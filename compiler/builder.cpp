#include "builder.hpp"
#include "../exceptions/contract.hpp"
#include "../generated/asn1Lexer.h"
#include "../generated/asn1Parser.h"
#include "errorlistener.hpp"
#include "listener.hpp"
#include "resolver.hpp"
#include <boost/filesystem.hpp>
#include "../tracing.hpp"

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

Builder& Builder::operator()(istream &is, bool produce_debug_output/* = false*/)
{
	// parse everything
	parse(is);
	if (!okay_) return *this;
	postParseSanityCheck();
	if (!okay_) return *this;
	scanDependencies();
	if (!okay_) return *this;
	if (produce_debug_output)
	{
		produceDebugOutput();
	}
	else
	{ /* Not asked to produce debug output */ }
	resolve();

	return *this;
}

string Builder::getModuleName() const
{
	return listener_->getModuleName();
}
vector< TypeAssignment > Builder::getTypeAssignments() const
{
	return listener_->getTypeAssignments();
}
vector< ValueAssignment > Builder::getValueAssignments() const
{
	return listener_->getValueAssignments();
}

void Builder::parse(istream &is)
{
	ANTLRInputStream input(is);
	input.name = input_filename_;
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
	map< string, unsigned int > types;
	for_each(type_assignments.begin(), type_assignments.end(), [&types](auto type){ types[type.getName()]++; });
    bool const duplicate_type_assignments(type_assignments.size() != types.size());
	okay_ &= !duplicate_type_assignments;
    if (duplicate_type_assignments)
    {
        auto where(find_if(types.begin(), types.end(), [](auto type) -> bool{ return type.second > 1; }));
        tracer__->trace(1, TRACE_ERROR, "Error: mutiple definition of %s\n", where->first.c_str());

        for_each(type_assignments.begin(), type_assignments.end(), [=](auto type_assignment){ tracer__->trace(1, TRACE_ERROR, "\tdefined here: %s:%u\n", type_assignment.getSourceLocation().filename_.c_str(), type_assignment.getSourceLocation().line_); });
    }
    else
    { /* all is well */ }
	
	auto value_assignments(listener_->getValueAssignments());
	map< string, unsigned int > values;
	for_each(value_assignments.begin(), value_assignments.end(), [&values](auto value){ values[value.getName()]++; });
	bool duplicate_value_assignments(value_assignments.size() != values.size());
	okay_ &= !duplicate_value_assignments;
    if (duplicate_value_assignments)
    {
        auto where(find_if(values.begin(), values.end(), [](auto value) -> bool{ return value.second > 1; }));
        tracer__->trace(1, TRACE_ERROR, "Error: mutiple definition of %s\n", where->first.c_str());

        for_each(value_assignments.begin(), value_assignments.end(), [=](auto value_assignment){ tracer__->trace(1, TRACE_ERROR, "\tdefined here: %s:%u\n", value_assignment.getSourceLocation().filename_.c_str(), value_assignment.getSourceLocation().line_); });
    }
    else
    { /* all is well */ }

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
		resolver(type_assignment, 1);
	}
	for (auto type_assignment : listener_->getTypeAssignments())
	{
		resolver(type_assignment, 2);
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

void Builder::produceDebugOutput() const
{
	tracer__->trace(1, TRACE_DEBUG, "Type assignments:\n");
	for (auto type_assignment : listener_->getTypeAssignments())
	{
		tracer__->trace(1, TRACE_DEBUG, "%s:%d: %s\n", type_assignment.getSourceLocation().filename_.c_str(), type_assignment.getSourceLocation().line_, type_assignment.getName().c_str());
	}
	for (auto value_assignment : listener_->getValueAssignments())
	{
		tracer__->trace(1, TRACE_DEBUG, "%s:%d: %s\n", value_assignment.getSourceLocation().filename_.c_str(), value_assignment.getSourceLocation().line_, value_assignment.getName().c_str());
	}
}

}}}

