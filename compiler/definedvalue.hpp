#ifndef rubicon_compiler_definedvalue_hpp
#define rubicon_compiler_definedvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct DefinedValue : Value
{
	DefinedValue(std::string const &name)
		: name_(name)
	{ /* no-op */ }

	std::string name_;
};
}}}

#endif



