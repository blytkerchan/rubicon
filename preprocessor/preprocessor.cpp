#include "preprocessor.hpp"
#include "antlr4-runtime.h"
#include "../generated/preprocLexer.h"
#include "../generated/preprocParser.h"
#include "listener.hpp"

using namespace std;
using namespace antlr4;

namespace Vlinder { namespace Rubicon { namespace Preprocessor {
Preprocessor::Preprocessor(std::string const &input_filename)
	: input_filename_(input_filename)
{ /* no-op */ }

Preprocessor& Preprocessor::operator()(ostream *out)
{
	ANTLRFileStream input(input_filename_);
	preprocLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	preprocParser parser(&tokens);
	auto the_tree(parser.file());
	tree::ParseTreeWalker walker;
	Listener listener(*out);
	walker.walk(&listener, the_tree);
	return *this;
}
/*explicit */Preprocessor::operator bool () const
{
	return okay_;
}
}}}

