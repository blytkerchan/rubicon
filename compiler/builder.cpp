#include "builder.hpp"
#include "listener.hpp"
#include "errorlistener.hpp"
#include "../generated/asn1Lexer.h"
#include "../generated/asn1Parser.h"
#include <antlr4-runtime/antlr4-runtime.h>
#include <set>
#include "../exceptions/contract.hpp"

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
	transform(type_assignments.begin(), type_assignments.end(), inserter(types, types.end()), [](auto type){ return type.name_; });
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

}
}}}

