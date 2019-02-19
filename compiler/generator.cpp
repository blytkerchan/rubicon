#include "generator.hpp"
#include <iostream>
#include <tuple>
#include "../exceptions/contract.hpp"
#include "builder.hpp"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>
#include "../version.hpp"

using namespace std;
namespace bfs = boost::filesystem;
namespace alg = boost::algorithm;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Generator::Generator(string const &output_directory_name, string const &namespace_prefix, string const &namespace_suffix)
	: output_directory_name_(output_directory_name)
	, namespace_prefix_(namespace_prefix)
	, namespace_suffix_(namespace_suffix)
{ /* no-op */ }
Generator::~Generator()
{ /* no-op */ }

Generator& Generator::operator()(Builder const &builder, bool output_dependencies)
{
	okay_ = (bool)builder;
	if (okay_)
	{
		builder_ = &builder;
		setNamespaceName();
		createOutputDirectory();
		if (output_dependencies)
		{
			outputDependencies();
		}
		else
		{ /* don't output dependencies */ }
		outputTypes();
		outputValues();
		generateFactory();
		generateCMakeLists();
	}
	else
	{ /* not OK */ }
	return *this;
}

void Generator::setNamespaceName()
{
	invariant(builder_);
	namespace_name_ = namespace_prefix_ + builder_->getModuleName() + namespace_suffix_;
}
void Generator::createOutputDirectory()
{
	if (output_directory_name_.empty())
	{
		string const namespace_name(getNamespaceName());
		output_directory_name_ = alg::replace_all_copy(alg::to_lower_copy(namespace_name), "::", "/");
		cout << "Using output directory " << output_directory_name_ << endl;
	}
	else
	{ /* already have a directory name */ }
	bfs::create_directories(output_directory_name_);
}
void Generator::outputDependencies() const
{
	invariant(builder_);
	{
		auto type_dependencies(builder_->getTypeDependencies());
		string type_dependencies_filename = (bfs::path(getOutputDirectoryName()) / "types.dot").string();
		ofstream type_dependencies_file(type_dependencies_filename, ofstream::trunc);
		type_dependencies_file << type_dependencies << endl;
	}
	{
		auto value_dependencies(builder_->getValueDependencies());
		string value_dependencies_filename = (bfs::path(getOutputDirectoryName()) / "values.dot").string();
		ofstream value_dependencies_file(value_dependencies_filename, ofstream::trunc);
		value_dependencies_file << value_dependencies << endl;
	}
}
void Generator::outputTypes()
{
	for (auto type_assignment : builder_->getTypeAssignments())
	{
		generateHeader(type_assignment);
		generateImplementation(type_assignment);
	}
}
void Generator::outputValues()
{
	for (auto value_assignment : builder_->getValueAssignments())
	{
		generateHeader(value_assignment);
		generateImplementation(value_assignment);
	}
}
void Generator::generateHeader(TypeAssignment const &type_assignment)
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".hpp"));
	generated_files_.push_back(filename);
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);
	openIncludeGuard(ofs, type_assignment);
	generateHeaderIncludeDirectives(ofs, type_assignment);
	generateHeaderForwardDeclarations(ofs, type_assignment);
	openNamespace(ofs);

	openClassDefinition(ofs, type_assignment);

	generatePublicDefinitionSection(ofs, type_assignment);
	generatePublicStaticMembers(ofs, type_assignment);
	generatePrivateDefinitionSection(ofs, type_assignment);

	closeClassDefinition(ofs, type_assignment);

	generateComparisonOperatorDeclarations(ofs, type_assignment);

	closeNamespace(ofs);
	closeIncludeGuard(ofs);
}
void Generator::generateHeader(ValueAssignment const &value_assignment)
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(value_assignment.getName()) + ".hpp"));
	generated_files_.push_back(filename);
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);
	openIncludeGuard(ofs, value_assignment);
	generateHeaderIncludeDirectives(ofs, value_assignment);
	openNamespace(ofs);
	generateDeclaration(ofs, value_assignment);
	closeNamespace(ofs);
	closeIncludeGuard(ofs);
}
void Generator::generateImplementation(TypeAssignment const &type_assignment)
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".cpp"));
	generated_files_.push_back(filename);
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);

	generateImplementationIncludeDirectives(ofs, type_assignment);
	generateImplementationUsingDirectives(ofs, type_assignment);

	openNamespace(ofs);

	generateCopyConstructorImplementation(ofs, type_assignment);
	generateAlternateConstructorImplementations(ofs, type_assignment);
	generateDestructorImplementation(ofs, type_assignment);
	generateAssignmentOperatorImplementation(ofs, type_assignment);
	generateSwapparatorImplementation(ofs, type_assignment);
	generateCompareImplementation(ofs, type_assignment);
	generateGetterAndSetterImplementations(ofs, type_assignment);
	generateEncodeImplementation(ofs, type_assignment);
	generateComparisonOperatorDefinitions(ofs, type_assignment);

	closeNamespace(ofs);
}
void Generator::generateImplementation(ValueAssignment const &value_assignment)
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(value_assignment.getName()) + ".cpp"));
	generated_files_.push_back(filename);
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);

	generateImplementationIncludeDirectives(ofs, value_assignment);
	generateImplementationUsingDirectives(ofs, value_assignment);

	openNamespace(ofs);

	generateDefinition(ofs, value_assignment);

	closeNamespace(ofs);
}
void Generator::generateFactory()
{
	generateFactoryHeader();
	generateFactoryImplementation();
}
void Generator::generateFactoryHeader()
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / "factory.hpp");
	generated_files_.push_back(filename);

	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);

	string const guard(
		string("generated_")
		+ alg::replace_all_copy(alg::to_lower_copy(getNamespaceName()), "::", "_")
		+ "_factory_hpp"
		);
	ofs << "#ifndef " << guard << "\n";
	ofs << "#define " << guard << "\n\n";

	ofs << "#include <deque>\n";
	ofs << "#include <vector>\n";
	ofs << "#include <rubicon/derdecoder.hpp>\n";
	ofs << "#include <rubicon/exceptions.hpp>\n";
	ofs << "#include <rubicon/details/any.hpp>\n";

	for (auto type_assignment : builder_->getTypeAssignments())
	{
		ofs << "#include \"" << alg::to_lower_copy(type_assignment.getName()) << ".hpp\"\n";
	}
	ofs << "\n";
	ofs << "namespace Vlinder { namespace Rubicon { class Integer; } }\n";

	openNamespace(ofs);

	ofs << "namespace Details {\n";
	for (auto type_assignment : builder_->getTypeAssignments())
	{
		generateBuilderDeclaration(ofs, type_assignment);
	}
	ofs << "}\n";
	for (auto type_assignment : builder_->getTypeAssignments())
	{
		ofs << "template < typename InputIterator >\n";
		ofs << type_assignment.getName() << " decode" << type_assignment.getName() << "(InputIterator &first, InputIterator last)\n";
		ofs << "{\n";
		ofs << "\tDetails::" << type_assignment.getName() << "Builder builder;\n";
		ofs << "\treturn builder(first, last);\n";
		ofs << "}\n";
	}
	closeNamespace(ofs);

	ofs << "\n#endif\n";
}
void Generator::generateFactoryImplementation()
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / "factory.cpp");
	generated_files_.push_back(filename);
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);
	ofs << "#include \"factory.hpp\"\n";
	ofs << "\n";

	ofs << "using namespace std;\n";
	ofs << "using namespace Vlinder::Rubicon;\n";
	ofs << "\n";
	
	openNamespace(ofs);
	ofs << "namespace Details {\n";
	for (auto type_assignment : builder_->getTypeAssignments())
	{
		generateBuilderImplementation(ofs, type_assignment);
	}
	ofs << "}\n";
	closeNamespace(ofs);
}
void Generator::generateBuilderDeclaration(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs
		<< "class " << type_assignment.getName() << "Builder : private Vlinder::Rubicon::DERDecoder\n"
		<< "{\n" 
		<< "public :\n"
		<< "\tvoid reset();\n"
		<< "\n"
		<< "\ttemplate < typename InputIterator >\n"
		<< "\t" << type_assignment.getName() << " operator()(InputIterator &first, InputIterator last)\n"
		<< "\t{\n"
		<< "\t\tif (!parse(first, last))\n"
		<< "\t\t{\n"
		<< "\t\t\tthrow Vlinder::Rubicon::ParseError(\"Incomplete parse\");\n"
		<< "\t\t}\n"
		<< "\t\treturn get();\n"
		<< "\t}\n"
		<< "\n"
		<< "protected:\n"
		<< "\tvirtual void onEndOfContents() override;\n"
		<< "\tvirtual void onInteger(Vlinder::Rubicon::Integer const &value) override;\n"
		<< "\tvirtual void onEnumerated(int value) override;\n"
		<< "\tvirtual void onBitString(bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last) override;\n"
		<< "\tvirtual void onOctetString(bool final, unsigned char *first, unsigned char *last) override;\n"
		<< "\tvirtual void onNull() override;\n"
		<< "\tvirtual void onBeginSequence() override;\n"
		<< "\tvirtual void onEndSequence() override;\n"
		<< "\tvirtual void onBeginSet() override;\n"
		<< "\tvirtual void onEndSet() override;\n"
		<< "\tvirtual void onBoolean(bool val) override;\n"
		<< "\tvirtual void onReal(double val) override;\n"
		<< "\n"
		<< "private :\n"
		<< "\tbool expect(unsigned int type_class, unsigned int tag) const;\n"
		<< "\tunsigned int next(unsigned int type_class, unsigned int tag) const;\n"
		<< "\t" << type_assignment.getName() << " get() const;\n"
		<< "\n"
		<< "\tunsigned int state_ = 0;\n"
		<< "\tstd::deque< Vlinder::Rubicon::Details::Any > constructed_;\n"
		<< "\tstd::vector< unsigned char > cache_;\n"
		<< "};\n"
		;
}
void Generator::generateBuilderImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	auto state_machine(type_assignment.getType()->getStateMachine());
	assert(state_machine);
	
	// reset
	ofs
		<< "void " << type_assignment.getName() << "Builder::reset()\n"
		<< "{\n"
		<< "\tstate_ = 0;\n"
		<< "\tconstructed_.clear();\n"
		<< "\tcache_.clear();\n"
		<< "\tDERDecoder::reset();\n"
		<< "}\n"
		<< "\n"
		;
	// end-of-contents
	ofs
		<< "/*virtual */void " << type_assignment.getName() << "Builder::onEndOfContents()/* override*/\n"
		<< "{\n"
		<< "\tthrow EncodingError(\"Invalid DER: end-of-contents found.\");\n"
		<< "}\n"
		<< "\n"
		;
	// each of the primitive types, and start/end of constructed types
	typedef tuple< string, string, string, int, int, string > EntryType;
	EntryType entries[] = {
		  {"onInteger", "Integer const &value", "Unexpected Integer", 0, 2, ""}
		, {"onEnumerated", "int value", "Unexpected Enumerated", 0, 10, ""}
		, {"onBitString", "bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last", "Unexpected BitString", 0, 3,
			"\tcache_.insert(cache_.end(), first, last);\n"
			"\tif (!final)\n"
			"\t{\n"
				"\t\tif (unused_bits != 0) throw ParseError(\"unused bits in partial bit string\");\n"
				"\t\treturn;\n"
			"\t}\n"
			"\telse\n"
			"\t{ /* this is final */ }\n"
			"\tif (unused_bits > 7) throw ParseError(\"too many unused bits in bit string\");\n"
			"\tBitString value(BitString::build(cache_, unused_bits));\n"
			"\tcache_.clear();\n"
			}
		, {"onOctetString", "bool final, unsigned char *first, unsigned char *last", "Unexpected OctetString", 0, 4, "\tvoid *value(nullptr);/*TODO*/\n"}
		, {"onNull", "", "Unexpected Null", 0, 5, "\tvoid *value(nullptr);\n"}
		, {"onBeginSequence", "", "Unexpected start-of-sequence", 0, 16, "\tvoid *value(nullptr);/*TODO*/\n"}
		, {"onEndSequence", "", "Unexpected end-of-sequence", 0, 0, "\tvoid *value(nullptr);/*TODO*/\n"}
		, {"onBeginSet", "", "Unexpected start-of-set", 0, 17, "\tvoid *value(nullptr);/*TODO*/\n"}
		, {"onEndSet", "", "Unexpected end-of-set", 0, 0, "\tvoid *value(nullptr);/*TODO*/\n"}
		, {"onBoolean", "bool value", "Unexpected boolean", 0, 1, ""}
		, {"onReal", "double value", "Unexpected real", 0, 9, ""}
		};
	for (auto entry : entries)
	{
		ofs
			<< "/*virtual */void " << type_assignment.getName() << "Builder::" << get< 0 >(entry) << "(" << get< 1 >(entry) << ")/* override*/\n"
			<< "{\n"
			<< "\tif (!expect(" << get< 3 >(entry) << ", " << get< 4 >(entry) << "))\n"
			<< "\t{\n"
			<< "\t\tthrow EncodingError(\"" << get< 2 >(entry) << "\");\n"
			<< "\t}\n"
			<< "\telse\n"
			<< "\t{ /* all is well */ }\n"
			<< get< 5 >(entry)
			<< "\tconstructed_.push_back(value);\n"
			<< "\tstate_ = next(" << get< 3 >(entry) << ", " << get< 4 >(entry) << ");\n"
			<< "\tdone_ = (state_ >= " << state_machine->state_count_ << ");\n"
			<< "}\n"
			<< "\n"
			;
	}
	// state machine management
	ofs
		<< "bool " << type_assignment.getName() << "Builder::expect(unsigned int type_class, unsigned int tag) const\n"
		<< "{\n"
		<< "\treturn false\n"
		;
	for (auto state : state_machine->states_)
	{
		ofs << "\t\t|| ((state_ == " << state.state_ << ") && (type_class == " << state.type_class_ << ") && (tag == " << state.tag_ << "))\n";
	}
	ofs
		<< "\t\t;\n"
		<< "}\n"
		<< "\n"
		<< "unsigned int " << type_assignment.getName() << "Builder::next(unsigned int type_class, unsigned int tag) const\n"
		<< "{\n"
		;
	for (auto state : state_machine->states_)
	{
		ofs << "\tif ((state_ == " << state.state_ << ") && (type_class == " << state.type_class_ << ") && (tag == " << state.tag_ << ")) return " << state.next_state_ << ";\n";
	}
	ofs
		<< "\treturn -1;\n"
		<< "}\n"
		<< "\n"
		;
	// get the results
	ofs
		<< type_assignment.getName() << " " << type_assignment.getName() << "Builder::get() const\n"
		<< "{\n"
		<< "\treturn Vlinder::Rubicon::Details::any_cast< " << type_assignment.getType()->getTypeName() << " >(constructed_.back());\n"
		<< "}\n"
		<< "\n"
		;
}
void Generator::generateCMakeLists() const
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / "CMakeLists.txt");
	ofstream ofs(filename.string(), ofstream::trunc);
	ofs <<
		"# Generated by Rubicon version " << DATECODE << "\n"
		"# This is the " << builder_->getModuleName() << " module\n"
		"# THIS IS GENERATED CODE - DO NOT MODIFY\n"
		;
	ofs
		<< "cmake_minimum_required(VERSION 3.10)\n"
		<< "project(" << builder_->getModuleName() << ")\n"
		<< "set(CMAKE_CXX_STANDARD 14)\n"
		<< "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
		<< "add_library(" << alg::to_lower_copy(builder_->getModuleName()) << "-asn1\n"
		;
	for_each(
		  generated_files_.begin()
		, generated_files_.end()
		, [&](auto generated_file){
				ofs << "\t" << generated_file.filename().string() << "\n";
			}
		);
	ofs << "\t)\n";
	ofs << "target_link_libraries(" << alg::to_lower_copy(builder_->getModuleName()) << "-asn1 rubicon)\n";
}
void Generator::generatePreamble(ostream &ofs) const
{
	ofs <<
		"/*\n"
		" * Generated by Rubicon version " << DATECODE << "\n"
		" * This is the " << builder_->getModuleName() << " module\n"
		" * THIS IS GENERATED CODE - DO NOT MODIFY\n"
		" */\n"
		;
}
void Generator::openIncludeGuard(ostream &ofs, TypeAssignment const &type_assignment) const
{
	string const guard(
		  string("generated_")
		+ alg::replace_all_copy(alg::to_lower_copy(getNamespaceName()), "::", "_")
		+ "_"
		+ alg::to_lower_copy(type_assignment.getName())
		+ "_hpp"
		);
	ofs << "#ifndef " << guard << "\n";
	ofs << "#define " << guard << "\n\n";
}
void Generator::openIncludeGuard(std::ostream &ofs, ValueAssignment const &value_assignment) const
{
	string const guard(
		  string("generated_")
		+ alg::replace_all_copy(alg::to_lower_copy(getNamespaceName()), "::", "_")
		+ "_"
		+ alg::replace_all_copy(alg::to_lower_copy(value_assignment.getName()), "-", "_")
		+ "_hpp"
		);
	ofs << "#ifndef " << guard << "\n";
	ofs << "#define " << guard << "\n\n";
}
void Generator::closeIncludeGuard(ostream &ofs) const
{
	ofs <<
		"\n"
		"#endif\n"
		;
}
void Generator::generateHeaderIncludeDirectives(ostream &ofs, TypeAssignment const &type_assignment) const
{
	for (auto dependency : type_assignment.getStrongDependencies())
	{
		ofs << "#include \"" << alg::replace_all_copy(alg::to_lower_copy(dependency), ".", "/") << ".hpp\"\n";
	}
	ofs <<
		"#include \"rubicon/types.hpp\"\n"
		;
	ofs << "\n";
}
void Generator::generateHeaderIncludeDirectives(std::ostream &ofs, ValueAssignment const &value_assignment) const
{
	for (auto dependency : value_assignment.getDependencies())
	{
		ofs << "#include \"" << alg::replace_all_copy(alg::to_lower_copy(dependency), ".", "/") << ".hpp\"\n";
	}
	ofs <<
		"#include \"rubicon/types.hpp\"\n"
		;
	ofs << "\n";
}
void Generator::generateHeaderForwardDeclarations(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs << "namespace Vlinder { namespace Rubicon { class DEREncoder; }}\n";
}
void Generator::generateImplementationIncludeDirectives(ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs << "#include \"" << alg::to_lower_copy(type_assignment.getName()) << ".hpp\"\n";
	for (auto dependency : type_assignment.getWeakDependencies())
	{
		ofs << "#include \"" << alg::replace_all_copy(alg::to_lower_copy(dependency), ".", "/") << ".hpp\"\n";
	}
	if (type_assignment.hasOptionalMembers())
	{
		ofs << "#include <memory>\n";
	}
	else
	{ /* no optional members, no need for unique_ptr */ }
	ofs << "#include <rubicon/derencoder.hpp>\n";
	ofs << "\n";
}
void Generator::generateImplementationUsingDirectives(ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs
		<< "using namespace std;\n"
		<< "using namespace Vlinder::Rubicon;\n"
		<< "\n"
		;
}
void Generator::generateImplementationIncludeDirectives(ostream &ofs, ValueAssignment const &value_assignment) const
{
	ofs << "#include \"" << alg::to_lower_copy(value_assignment.getName()) << ".hpp\"\n";
	ofs << "\n";
}
void Generator::generateImplementationUsingDirectives(ostream &ofs, ValueAssignment const &value_assignment) const
{
	ofs
		<< "using namespace std;\n"
		<< "using namespace Vlinder::Rubicon;\n"
		<< "\n"
		;
}
void Generator::openNamespace(ostream &ofs) const
{
	string const namespace_declaration(
		  string("namespace ")
		+ alg::replace_all_copy(getNamespaceName(), "::", " { namespace ")
		+ " {"
		);
	ofs << namespace_declaration << "\n";
}
void Generator::closeNamespace(ostream &ofs) const
{
	string const namespace_declaration(
		  string("namespace ")
		+ alg::replace_all_copy(getNamespaceName(), "::", " { namespace ")
		+ " {"
		);
	string const namespace_close(count(namespace_declaration.begin(), namespace_declaration.end(), '{'), '}');
	ofs << namespace_close << "\n";
}
void Generator::openClassDefinition(ostream &ofs, TypeAssignment const &type_assignment) const
{
	auto public_parents(type_assignment.getPublicParents());
	auto protected_parents(type_assignment.getProtectedParents());
	auto private_parents(type_assignment.getPrivateParents());
	ofs << "class " << type_assignment.getName() << "\n";
	bool first(true);
	for_each(public_parents.begin(), public_parents.end(), [&](auto public_parent){
				if (first) ofs << "\t: "; else ofs << "\t, ";
				ofs << "public " << public_parent << "\n";
				first = false;
			}
		);
	for_each(protected_parents.begin(), protected_parents.end(), [&](auto protected_parent){
				if (first) ofs << "\t: "; else ofs << "\t, ";
				ofs << "protected " << protected_parent;
				first = false;
			}
		);
	for_each(private_parents.begin(), private_parents.end(), [&](auto private_parent){
				if (first) ofs << "\t: "; else ofs << "\t, ";
				ofs << "private " << private_parent;
				first = false;
			}
		);
	ofs << "{\n";
}
void Generator::closeClassDefinition(ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs << "};\n";
}
void Generator::generatePublicDefinitionSection(ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs <<
		"public :\n"
		"\t" << type_assignment.getName() << "() = default;\n"
		;
	type_assignment.generateAlternateConstructorDeclarations(ofs);
	ofs << 	"\tvirtual ~" << type_assignment.getName() << "()" <<  (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "(" << type_assignment.getName() << " const &other)" << (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "& operator=(" << type_assignment.getName() << " const &other)" << (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "(" << type_assignment.getName() << " &&other) = default;\n"
		"\t" << type_assignment.getName() << "& operator=(" << type_assignment.getName() << " &&other) = default;\n"
		"\t" << type_assignment.getName() << "& swap(" << type_assignment.getName() << " &other);\n"
		"\n"
		"\tint compare(" << type_assignment.getName() << " const &other) const;\n"
		"\n"
		;
	ofs << "\n";
	type_assignment.generateHeaderGettersAndSetters(ofs);
	ofs << "\n";

	ofs <<
		"\tvoid encode(Vlinder::Rubicon::DEREncoder &der_encoder) const;\n"
		"\n"
		;
}
void Generator::generatePublicStaticMembers(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generatePublicStaticMembers(ofs);
}
void Generator::generateAlternateConstructorImplementations(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateAlternateConstructorImplementations(ofs);
}
void Generator::generatePrivateDefinitionSection(ostream &ofs, TypeAssignment const &type_assignment) const
{
	ofs <<
		"private :\n"
		;
	type_assignment.generateMemberDeclarations(ofs);
}
void Generator::generateCopyConstructorImplementation(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateCopyConstructorImplementation(ofs);
}
void Generator::generateDestructorImplementation(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateDestructorImplementation(ofs);
}
void Generator::generateAssignmentOperatorImplementation(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateAssignmentOperatorImplementation(ofs);
}
void Generator::generateSwapparatorImplementation(ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateSwapparatorImplementation(ofs);
}
void Generator::generateGetterAndSetterImplementations(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateGetterAndSetterImplementations(ofs);
}
void Generator::generateEncodeImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateEncodeImplementation(ofs);
}
void Generator::generateDeclaration(std::ostream &os, ValueAssignment const &value_assignment) const
{
	value_assignment.generateDeclaration(os);
}
void Generator::generateDefinition(std::ostream &os, ValueAssignment const &value_assignment) const
{
	value_assignment.generateDefinition(os);
}
void Generator::generateComparisonOperatorDeclarations(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	string operators[] = { "==", "!=", "<", "<=", ">", ">=" };
	for (auto op : operators)
	{
		ofs << "bool operator" << op << "(" << type_assignment.getName() << " const &lhs, " << type_assignment.getName() << " const &rhs);\n";
	}
}
void Generator::generateCompareImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	type_assignment.generateCompareImplementation(ofs);
}
void Generator::generateComparisonOperatorDefinitions(std::ostream &ofs, TypeAssignment const &type_assignment) const
{
	string operators[] = { "==", "!=", "<", "<=", ">", ">=" };
	for (auto op : operators)
	{
		ofs
			<< "bool operator" << op << "(" << type_assignment.getName() << " const &lhs, " << type_assignment.getName() << " const &rhs)\n"
			<< "{\n"
			<< "\treturn lhs.compare(rhs) " << op << " 0;\n"
			<< "}\n"
			;
	}
}
}}}


