#ifndef rubicon_compiler_namednumber_hpp
#define rubicon_compiler_namednumber_hpp

#include <string>
#include <boost/variant.hpp>
#include "definedvalue.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct NamedNumber
{
	NamedNumber(std::string const &name, long value)
		: name_(name)
		, value_(value)
	{ /* no-op */ }

	NamedNumber(std::string const &name, DefinedValue const &value)
		: name_(name)
		, value_(value)
	{ /* no-op */ }

	std::string name_;
	boost::variant< long, DefinedValue > value_;
};
}}}

#endif



