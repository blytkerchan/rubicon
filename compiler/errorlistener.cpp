#include "errorlistener.hpp"
#include "../tracing.hpp"
#include "Token.h"

using namespace std;
using namespace antlr4;
using namespace antlrcpp;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void ErrorListener::syntaxError(
	  Recognizer *recognizer
	, Token *offending_symbol
	, size_t line
	, size_t char_position_in_line
	, string const &msg
	, exception_ptr e
	)/* override*/
{
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: syntax error: ", input_filename_.c_str(), line, char_position_in_line)(msg.c_str())("\n");
	tracer__->trace(1, TRACE_INFO)("%s:%u:%u: offending symbol: ", input_filename_.c_str(), line, char_position_in_line)(offending_symbol->getText().c_str())("\n");
	on_error_callback_();
}

/*virtual */void ErrorListener::reportAmbiguity(
	  Parser *recognizer
	, dfa::DFA const &dfa
	, size_t start_index
	, size_t stop_index
	, bool exact
	, BitSet const &ambig_alts
	, atn::ATNConfigSet *configs
	)/* override*/
{}

/*virtual */void ErrorListener::reportAttemptingFullContext(
	  Parser *recognizer
	, dfa::DFA const &dfa
	, size_t start_index
	, size_t stop_index
	, BitSet const &conflicting_alts
	, atn::ATNConfigSet *configs
	)/* override*/
{}

/*virtual */void ErrorListener::reportContextSensitivity(
	  Parser *recognizer
	, dfa::DFA const &dfa
	, size_t start_index
	, size_t stop_index
	, size_t prediction
	, atn::ATNConfigSet *configs
	)/* override*/
{}
}}}



