#include "generated/preprocLexer.h"
#include "generated/preprocParser.h"
#include "preprocessor/listener.hpp"
#include "exceptions/contract.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <boost/program_options.hpp>
#include <antlr4-runtime/antlr4-runtime.h>

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
	else
	{ /* all is well */ }
	ostream *out(&cout);
	unique_ptr< ofstream > output_file;
	if (vm.count("output"))
	{
		output_file = move(make_unique< ofstream >(vm["output"].as< string >()));
		out = output_file.get();
	}
	else
	{ /* use stdout */ }

	ANTLRFileStream input(vm["input-file"].as< string >());
	preprocLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	preprocParser parser(&tokens);
	auto the_tree(parser.file());
	tree::ParseTreeWalker walker;
	Vlinder::Rubicon::Preprocessor::Listener listener(*out);
	walker.walk(&listener, the_tree);
}

