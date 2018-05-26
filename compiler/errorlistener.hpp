#ifndef rubicon_compiler_errorlistener_hpp
#define rubicon_compiler_errorlistener_hpp

#include <antlr4-runtime/BaseErrorListener.h>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ErrorListener : public antlr4::BaseErrorListener
{
public :
	ErrorListener(std::function< void() > const &on_error_callback, std::string const &input_filename)
		: on_error_callback_(on_error_callback)
		, input_filename_(input_filename)
	{ /* no-op */ }
	virtual void syntaxError(
		  antlr4::Recognizer *recognizer
		, antlr4::Token *offending_symbol
		, size_t line
		, size_t char_position_in_line
		, std::string const &msg
		, std::exception_ptr e
		) override;

	virtual void reportAmbiguity(
		  antlr4::Parser *recognizer
		, antlr4::dfa::DFA const &dfa
		, size_t start_index
		, size_t stop_index
		, bool exact
		, antlrcpp::BitSet const &ambig_alts
		, antlr4::atn::ATNConfigSet *configs
		) override;

	virtual void reportAttemptingFullContext(
		  antlr4::Parser *recognizer
		, antlr4::dfa::DFA const &dfa
		, size_t start_index
		, size_t stop_index
		, antlrcpp::BitSet const &conflicting_alts
		, antlr4::atn::ATNConfigSet *configs
		) override;

	virtual void reportContextSensitivity(
		  antlr4::Parser *recognizer
		, antlr4::dfa::DFA const &dfa
		, size_t start_index
		, size_t stop_index
		, size_t prediction
		, antlr4::atn::ATNConfigSet *configs
		) override;
private :
	std::function< void() > on_error_callback_;
	std::string input_filename_;
};
}}}

#endif

