#include "generator.hpp"
#include <iostream>
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
void Generator::outputTypes() const
{
	for (auto type_assignment : builder_->getTypeAssignments())
	{
		generateHeader(type_assignment);
		generateImplementation(type_assignment);
	}
}
void Generator::outputValues() const
{
	for (auto value_assignment : builder_->getValueAssignments())
	{
		generateHeader(value_assignment);
		generateImplementation(value_assignment);
	}
}
void Generator::generateHeader(TypeAssignment const &type_assignment) const
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".hpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);
	openIncludeGuard(ofs, type_assignment);
	generateHeaderIncludeDirectives(ofs, type_assignment);
	openNamespace(ofs);

	openClassDefinition(ofs, type_assignment);

	generatePublicDefinitionSection(ofs, type_assignment);
	generatePrivateDefinitionSection(ofs, type_assignment);

	closeClassDefinition(ofs, type_assignment);

	closeNamespace(ofs);
	closeIncludeGuard(ofs);
}
void Generator::generateHeader(ValueAssignment const &value_assignment) const
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(value_assignment.getName()) + ".hpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);
	openIncludeGuard(ofs, value_assignment);
	generateHeaderIncludeDirectives(ofs, value_assignment);
	openNamespace(ofs);
	generateDeclaration(ofs, value_assignment);
	closeNamespace(ofs);
	closeIncludeGuard(ofs);
}
void Generator::generateImplementation(TypeAssignment const &type_assignment) const
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".cpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);

	generateImplementationIncludeDirectives(ofs, type_assignment);

	openNamespace(ofs);

	generateCopyConstructorImplementation(ofs, type_assignment);
	generateDestructorImplementation(ofs, type_assignment);
	generateAssignmentOperatorImplementation(ofs, type_assignment);
	generateSwapparatorImplementation(ofs, type_assignment);
	generateGetterAndSetterImplementations(ofs, type_assignment);

	closeNamespace(ofs);
}
void Generator::generateImplementation(ValueAssignment const &value_assignment) const
{
	bfs::path const directory(getOutputDirectoryName());
	bfs::path const filename(directory / (alg::to_lower_copy(value_assignment.getName()) + ".cpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	generatePreamble(ofs);

//	generateImplementationIncludeDirectives(ofs, value_assignment);

//	openNamespace(ofs);

//	generateCopyConstructorImplementation(ofs, type_assignment);
//	generateDestructorImplementation(ofs, type_assignment);
//	generateAssignmentOperatorImplementation(ofs, type_assignment);
//	generateSwapparatorImplementation(ofs, type_assignment);
//	generateGetterAndSetterImplementations(ofs, type_assignment);

//	closeNamespace(ofs);
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
		"#include \"rubicon/derencoder.hpp\"\n"
		"#include \"rubicon/derdecoder.hpp\"\n"
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
	ofs << "\n";
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
	ofs
		<< "class " << type_assignment.getName() << "\n"
		<< "{\n"
		;
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
		"\t" << type_assignment.getName() << "(Vlinder::Rubicon::DERDecoder &der_decoder);\n"
		"\tvirtual ~" << type_assignment.getName() << "()" <<  (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "(" << type_assignment.getName() << " const &other)" << (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "& operator=(" << type_assignment.getName() << " const &other)" << (type_assignment.hasOptionalMembers() ? "" : " = default") << ";\n"
		"\t" << type_assignment.getName() << "(" << type_assignment.getName() << " &&other) = default;\n"
		"\t" << type_assignment.getName() << "& operator=(" << type_assignment.getName() << " &&other) = default;\n"
		"\t" << type_assignment.getName() << "& swap(" << type_assignment.getName() << " &other);\n"
		"\n"
		;
	type_assignment.generateHeaderGettersAndSetters(ofs);
	ofs << "\n";

	ofs <<
		"\tvoid encode(Vlinder::Rubicon::DEREncoder &der_encoder);\n"
		"\n"
		;
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
void Generator::generateDeclaration(std::ostream &os, ValueAssignment const &value_assignment) const
{
	value_assignment.generateDeclaration(os);
}

}}}


