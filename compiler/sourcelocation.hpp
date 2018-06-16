#ifndef vlinder_rubicon_compiler_sourcelocation_hpp
#define vlinder_rubicon_compiler_sourcelocation_hpp

#include "antlr4-runtime.h"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct SourceLocation
{
	SourceLocation(
		  std::string const &filename
		, unsigned int line
		, unsigned int offset
		)
		: filename_(filename)
		, line_(line)
		, offset_(offset)
	{ /* no-op */ }
	SourceLocation(antlr4::ParserRuleContext *ctx)
		: SourceLocation(ctx->getStart()->getTokenSource()->getSourceName(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine())
	{ /* no-op */ }

	std::string filename_;
	unsigned int line_;
	unsigned int offset_;
};
}}}

#endif

