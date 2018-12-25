#include "preprocessor/preprocessor.hpp"
#include "compiler/builder.hpp"
#include "compiler/generator.hpp"
#include "exceptions/contract.hpp"
#include "tracing.hpp"
#include "tracing/stderrtracer.hpp"
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
namespace po = boost::program_options;
namespace pre = Vlinder::Rubicon::Preprocessor;
namespace cpl = Vlinder::Rubicon::Compiler;

int main(int argc, char const **argv)
{
	Vlinder::Tracing::StdErrTracer tracer;
	tracer__ = &tracer;
	tracer__->setMask(DEFAULT_TRACE_MASK | TRACE_INFO);
	po::options_description opts("options");
	opts.add_options()
		("help,h", "Display this help screen")
		("output,o", po::value< string >(), "output directory (defaults to namespace name, lowercased)")
		("namespace-prefix,n", po::value< string >(), "prefix to prepend to the namespace (defaults to none)")
		("namespace-suffix,s", po::value< string >(), "suffix to append to the namespace (defaults to \"::ASN1\")")
		("output-dependencies,g", "output dependencies in dot format")
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
	string const namespace_prefix(vm.count("namespace-prefix") == 0 ? string() : vm["namespace-prefix"].as< string >());
	string const namespace_suffix(vm.count("namespace-suffix") == 0 ? string("::ASN1") : vm["namespace-suffix"].as< string >());
	string const input_filename(vm["input-file"].as< string >());

	pre::Preprocessor preprocessor(input_filename);
	stringstream ss;
	if (preprocessor(&ss))
	{
		cpl::Builder builder(input_filename);
		cpl::Generator generator(vm.count("output") ? vm["output"].as< string >() : string(), namespace_prefix, namespace_suffix);
		return generator(builder(ss), vm.count("output-dependencies") != 0) ? 0 : 1;
	}
	else return 1;
}


