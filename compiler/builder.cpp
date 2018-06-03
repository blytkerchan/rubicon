#include "builder.hpp"
#include "../exceptions/contract.hpp"
#include "../generated/asn1Lexer.h"
#include "../generated/asn1Parser.h"
#include "dependencies.hpp"
#include "errorlistener.hpp"
#include "listener.hpp"
#include <antlr4-runtime/antlr4-runtime.h>
#include <fstream>
#include <set>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>

using namespace antlr4;
using namespace std;
namespace bfs = boost::filesystem;
namespace alg = boost::algorithm;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Builder::Builder(string const &output_directory_name, string const &input_filename, string const &namespace_prefix, string const &namespace_suffix)
	: input_filename_(input_filename)
	, namespace_prefix_(namespace_prefix)
	, namespace_suffix_(namespace_suffix)
	, output_directory_name_(output_directory_name)
{
}

Builder::~Builder()
{
	delete listener_;
}

Builder& Builder::operator()(istream &is, bool output_dependencies)
{
	// parse everything
	parse(is);
	if (!okay_) return *this;
	postParseSanityCheck();
	if (!okay_) return *this;
	if (output_dependencies)
	{
		outputDependencies();
	}
	else
	{ /* don't output dependencies */ }
	createOutputDirectory();
	outputTypes();

	return *this;
}

void Builder::parse(istream &is)
{
	ANTLRInputStream input(is);
	asn1Lexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	asn1Parser parser(&tokens);
	function< void() > on_error_callback([&](){ okay_ = false; });
	ErrorListener error_listener(on_error_callback, input_filename_);
	parser.removeErrorListeners();
	parser.addErrorListener(&error_listener);
	auto the_tree(parser.file());
	if (!okay_) return;
	tree::ParseTreeWalker walker;
	delete listener_;
	listener_ = nullptr;
	listener_ = new Listener(namespace_prefix_, namespace_suffix_);
	walker.walk(listener_, the_tree);
}
void Builder::postParseSanityCheck()
{
	invariant(listener_);
	// check for duplicate symbols
	auto type_assignments(listener_->getTypeAssignments());
	set< string > types;
	transform(type_assignments.begin(), type_assignments.end(), inserter(types, types.end()), [](auto type){ return type.getName(); });
	okay_ &= type_assignments.size() == types.size();
	auto value_assignments(listener_->getValueAssignments());
	set< string > values;
	transform(value_assignments.begin(), value_assignments.end(), inserter(values, values.end()), [](auto value){ return value.name_; });
	okay_ &= value_assignments.size() == values.size();
	// check that everything that was exported actually exists
	for (auto symbol : listener_->getSymbolsToExport())
	{
		auto which_type(types.find(symbol));
		auto which_value(values.find(symbol));
		okay_ &= (which_type != types.end()) || (which_value != values.end());
	}
}

void Builder::outputDependencies() const
{
	invariant(listener_);
	{
		Dependencies type_dependencies;
		for (auto type_assignment : listener_->getTypeAssignments())
		{
			set< string > dependencies;
			auto const &deps(type_assignment.getDependencies());
			dependencies.insert(deps.begin(), deps.end());
			type_dependencies.add(type_assignment.getName(), dependencies.begin(), dependencies.end());
		}
		string type_dependencies_filename = bfs::path(input_filename_).filename().string() + ".types.dot";
		ofstream type_dependencies_file(type_dependencies_filename, ofstream::trunc);
		type_dependencies_file << type_dependencies << endl;
	}
	{
		Dependencies value_dependencies;
		for (auto value_assignment : listener_->getValueAssignments())
		{
			set< string > dependencies;
			auto const &deps(value_assignment.getDependencies());
			dependencies.insert(deps.begin(), deps.end());
			value_dependencies.add(value_assignment.getName(), dependencies.begin(), dependencies.end());
		}
		string value_dependencies_filename = bfs::path(input_filename_).filename().string() + ".values.dot";
		ofstream value_dependencies_file(value_dependencies_filename, ofstream::trunc);
		value_dependencies_file << value_dependencies << endl;
	}
}
void Builder::createOutputDirectory()
{
	if (output_directory_name_.empty())
	{
		output_directory_name_ = alg::replace_all_copy(alg::to_lower_copy(listener_->getModuleNamespace()), "::", "/");
		cout << "Using output directory " << output_directory_name_ << endl;
	}
	else
	{ /* already have a directory name */ }
	bfs::create_directories(output_directory_name_);
}

void Builder::outputTypes()
{
	for (auto type_assignment : listener_->getTypeAssignments())
	{
		generateHeader(type_assignment);
		generateImplementation(type_assignment);
	}
}
void Builder::generateHeader(TypeAssignment const &type_assignment)
{
	bfs::path const directory(output_directory_name_);
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".hpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	// output the re-include guards
	string const guard(
		  string("generated_")
		+ alg::replace_all_copy(alg::to_lower_copy(listener_->getModuleNamespace()), "::", "_")
		+ "_"
		+ alg::to_lower_copy(type_assignment.getName())
		+ "_hpp"
		);
	ofs << "#ifndef " << guard << "\n";
	ofs << "#define " << guard << "\n\n";

	string const namespace_declaration(
		  string("namespace ")
		+ alg::replace_all_copy(alg::to_lower_copy(listener_->getModuleNamespace()), "::", " { namespace ")
		+ " {"
		);
	string const namespace_close(count(namespace_declaration.begin(), namespace_declaration.end(), '{'), '}');

	ofs << "/* GENERATED CODE, DO NOT EDIT */\n";
	ofs << namespace_declaration << "\n";
	type_assignment.generateHeader(ofs);
	ofs << namespace_close << "\n";

	ofs << "\n#endif\n";
}
void Builder::generateImplementation(TypeAssignment const &type_assignment)
{
	bfs::path const directory(output_directory_name_);
	bfs::path const filename(directory / (alg::to_lower_copy(type_assignment.getName()) + ".cpp"));
	ofstream ofs(filename.string(), ofstream::trunc);

	string const namespace_declaration(
		  string("namespace ")
		+ alg::replace_all_copy(alg::to_lower_copy(listener_->getModuleNamespace()), "::", " { namespace ")
		+ " {"
		);
	string const namespace_close(count(namespace_declaration.begin(), namespace_declaration.end(), '{'), '}');

	ofs << "/* GENERATED CODE, DO NOT EDIT */\n";
	ofs << "#include \"" << alg::to_lower_copy(type_assignment.getName()) << ".hpp" << "\"\n";
	ofs << "\n";
	ofs << namespace_declaration << "\n";
	type_assignment.generateImplementation(ofs);
	ofs << namespace_close << "\n";

}
}}}

