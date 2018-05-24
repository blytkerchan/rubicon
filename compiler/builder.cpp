#include "builder.hpp"
#include "listener.hpp"
#include "../generated/asn1Lexer.h"
#include "../generated/asn1Parser.h"
#include <antlr4-runtime/antlr4-runtime.h>
#include <set>

using namespace antlr4;
using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Builder::Builder(std::ostream *out, std::string const &input_filename, string const &namespace_prefix, string const &namespace_suffix)
	: out_(out)
	, input_filename_(input_filename)
	, namespace_prefix_(namespace_prefix)
	, namespace_suffix_(namespace_suffix)
{
	pre_condition(out);
}

Builder& Builder::operator()()
{
	// parse everything
	ANTLRFileStream input(input_filename_);
	asn1Lexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	asn1Parser parser(&tokens);
	auto the_tree(parser.file());
	tree::ParseTreeWalker walker;
	Listener listener(namespace_prefix_, namespace_suffix_);
	walker.walk(&listener, the_tree);
	// post-parse checks
	// check for duplicate symbols
	auto type_assignments(listener.getTypeAssignments());
	set< string > types;
	transform(type_assignments.begin(), type_assignments.end(), inserter(types, types.end()), [](auto type){ return type.name_; });
	okay_ &= type_assignments.size() == types.size();
	auto value_assignments(listener.getValueAssignments());
	set< string > values;
	transform(value_assignments.begin(), value_assignments.end(), inserter(values, values.end()), [](auto value){ return value.name_; });
	okay_ &= value_assignments.size() == values.size();
	// check that everything that was exported actually exists
	for (auto symbol : listener.getSymbolsToExport())
	{
		auto which_type(types.find(symbol));
		auto which_value(values.find(symbol));
		okay_ &= (which_type != types.end()) || (which_value != values.end());
	}

	return *this;
}

}}}

