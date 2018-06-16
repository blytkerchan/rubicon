#ifndef rubicon_compiler_definedvalue_hpp
#define rubicon_compiler_definedvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class DefinedValue : public Value
{
public :
	DefinedValue(std::string const &name)
		: name_(name)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

private :
	std::string name_;
};
}}}

#endif



