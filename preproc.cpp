#include "generated/preprocLexer.h"
#include "exceptions/contract.hpp"
#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include <antlr4-runtime/ANTLRFileStream.h>

using namespace antlr4;
using namespace std;
namespace po = boost::program_options;

/* Hello, world! */

int main(int argc, char const **argv)
{
	po::options_description opts("options");
	opts.add_options()
		("output,o", po::value< string >(), "output file (defaults to stdout)")
		;
	po::options_description hidden_options("Hidden options");
	hidden_options.add_options()
		("input-file", po::value< string >(), "input file")
		;
	po::options_description all_options("all options");
	all_options.add(opts);
	all_options.add(hidden_options);
	po::positional_options_description pos_opts;
	pos_opts.add("input-file", 1);
	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(all_options).positional(pos_opts).run(), vm);
	po::notify(vm);

	if (!vm.count("input-file"))
	{
		cerr << "Missing input file" << endl;
		cerr << "Usage: " << argv[0] << " [options] <input-file>" << endl;
		cerr << opts << endl;
		return 1;
	}

	ANTLRFileStream input(vm["input-file"].as< string >());
	preprocLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	tokens.fill();

	ostream *out(&cout);

	enum struct State {
		  initial__
		, expect_anything__ = initial__
		, wait_for_end_of_c_style_comment__
		, wait_for_end_of_ada_style_comment__
		, wait_for_end_of_quote__
		} state(State::initial__);
	for (auto token : tokens.getTokens())
	{
		switch (token->getType())
		{
		case preprocLexer::BEGIN_C_STYLE_COMMENT :
			if (State::expect_anything__ == state)
			{
				state = State::wait_for_end_of_c_style_comment__;
			}
			else if (State::wait_for_end_of_quote__ == state)
			{
				*out << token->getText();
			}
			else
			{
				invariant((State::wait_for_end_of_c_style_comment__ == state) || (State::wait_for_end_of_ada_style_comment__ == state));
			}
			break;
		case preprocLexer::END_C_STYLE_COMMENT :
			if (State::expect_anything__ == state)
			{
				cerr << vm["input-file"].as< string >() << "(" << token->getLine() << "): Unexpected end of C-style comment" << endl;
				return 1;
			}
			else if (State::wait_for_end_of_c_style_comment__ == state)
			{
				state = State::expect_anything__;
			}
			else if (State::wait_for_end_of_quote__ == state)
			{
				*out << token->getText();
			}
			else
			{
				invariant(State::wait_for_end_of_ada_style_comment__ == state);
			}
			break;
		case preprocLexer::ADA_STYLE_COMMENT_DELIM :
			if (State::expect_anything__ == state)
			{
				state = State::wait_for_end_of_ada_style_comment__;
			}
			else if (State::wait_for_end_of_ada_style_comment__ == state)
			{
				state = State::expect_anything__;
			}
			else if (State::wait_for_end_of_quote__ == state)
			{
				*out << token->getText();
			}
			else
			{
				invariant(State::wait_for_end_of_c_style_comment__ == state);
			}
		case preprocLexer::NEWLINE :
			switch (state)
			{
			case State::wait_for_end_of_ada_style_comment__ :
				state = State::expect_anything__;
			case State::expect_anything__ :
			case State::wait_for_end_of_quote__ :
				*out << token->getText();
				break;
			default :
				invariant((State::wait_for_end_of_c_style_comment__ == state) || (State::wait_for_end_of_ada_style_comment__ == state));
				break;
			}
			break;
		case preprocLexer::QUOTE :
			if (State::expect_anything__ == state)
			{
				state = State::wait_for_end_of_quote__;
				*out << token->getText();
			}
			else if (State::wait_for_end_of_quote__ == state)
			{
				state = State::expect_anything__;
				*out << token->getText();
			}
			else
			{
				invariant((State::wait_for_end_of_c_style_comment__ == state) || (State::wait_for_end_of_ada_style_comment__ == state));
			}
		case preprocLexer::CHAR :
			switch (state)
			{
			case State::expect_anything__ :
			case State::wait_for_end_of_quote__ :
				*out << token->getText();
				break;
			default :
				invariant((State::wait_for_end_of_c_style_comment__ == state) || (State::wait_for_end_of_ada_style_comment__ == state));
				break;
			}
		}
	}
}

