#include "builder.hpp"
#include "../exceptions/contract.hpp"
#include "../generated/asn1Lexer.h"
#include "../generated/asn1Parser.h"
#include "errorlistener.hpp"
#include "listener.hpp"
#include "resolver.hpp"
#include <boost/filesystem.hpp>

using namespace antlr4;
using namespace std;
namespace bfs = boost::filesystem;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Builder::Builder(string const &input_filename)
	: input_filename_(input_filename)
{
}

Builder::~Builder()
{
	delete listener_;
}

Builder& Builder::operator()(istream &is)
{
	// parse everything
	parse(is);
	if (!okay_) return *this;
	postParseSanityCheck();
	if (!okay_) return *this;
	scanDependencies();

	return *this;
}

std::string Builder::getModuleName() const
{
	return listener_->getModuleName();
}
std::vector< TypeAssignment > Builder::getTypeAssignments() const
{
	return listener_->getTypeAssignments();
}
std::vector< ValueAssignment > Builder::getValueAssignments() const
{
	return listener_->getValueAssignments();
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
	listener_ = new Listener;
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
	transform(value_assignments.begin(), value_assignments.end(), inserter(values, values.end()), [](auto value){ return value.getName(); });
	okay_ &= value_assignments.size() == values.size();
	// check that everything that was exported actually exists
	for (auto symbol : listener_->getSymbolsToExport())
	{
		auto which_type(types.find(symbol));
		auto which_value(values.find(symbol));
		okay_ &= (which_type != types.end()) || (which_value != values.end());
	}
}

void Builder::resolve()
{
	Resolver resolver(listener_);
	for (auto type_assignment : listener_->getTypeAssignments())
	{
		resolver(type_assignment);
	}
	for (auto value_assignment : listener_->getValueAssignments())
	{
		resolver(value_assignment);
	}
}

void Builder::scanDependencies()
{
	type_dependencies_.clear();
	for (auto type_assignment : listener_->getTypeAssignments())
	{
		set< string > dependencies;
		auto const &deps(type_assignment.getDependencies());
		dependencies.insert(deps.begin(), deps.end());
		type_dependencies_.add(type_assignment.getName(), dependencies.begin(), dependencies.end());
	}
	value_dependencies_.clear();
	for (auto value_assignment : listener_->getValueAssignments())
	{
		set< string > dependencies;
		auto const &deps(value_assignment.getDependencies());
		dependencies.insert(deps.begin(), deps.end());
		value_dependencies_.add(value_assignment.getName(), dependencies.begin(), dependencies.end());
	}
}

}}}

