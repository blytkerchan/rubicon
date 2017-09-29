#include "generated/asn1Lexer.h"
#include "generated/asn1Parser.h"
#include "compiler/listener.hpp"
#include "exceptions/contract.hpp"
#include "tracing.hpp"
#include "tracing/stderrtracer.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <boost/program_options.hpp>
#include <antlr4-runtime/antlr4-runtime.h>

using namespace antlr4;
using namespace std;
namespace po = boost::program_options;

int main(int argc, char const **argv)
{
	Vlinder::Tracing::StdErrTracer tracer;
	tracer__ = &tracer;
	tracer__->setMask(DEFAULT_TRACE_MASK);
	po::options_description opts("options");
	opts.add_options()
		("help,h", "Display this help screen")
		("output,o", po::value< string >(), "output file (defaults to stdout)")
		("namespace-prefix,n", po::value< string >(), "prefix to prepend to the namespace (defaults to none)")
		("namespace-suffix,s", po::value< string >(), "suffix to append to the namespace (defaults to \"::ASN1\")")
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

	if (vm.count("help"))
	{
		cout << "Usage: " << argv[0] << " [options] <input-file>" << endl;
		cout << opts << endl;
		return 0;
	}
	else
	{ /* no help */ }

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
	string const namespace_prefix(vm.count("namespace-prefix") == 0 ? string() : vm["namespace-prefix"].as< string >());
	string const namespace_suffix(vm.count("namespace-suffix") == 0 ? string("::ASN1") : vm["namespace-suffix"].as< string >());

	ANTLRFileStream input(vm["input-file"].as< string >());
	asn1Lexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	asn1Parser parser(&tokens);
	auto the_tree(parser.file());
	tree::ParseTreeWalker walker;
	Vlinder::Rubicon::Compiler::Listener listener(namespace_prefix, namespace_suffix);
	walker.walk(&listener, the_tree);
}


