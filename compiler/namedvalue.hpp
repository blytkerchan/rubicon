#ifndef rubicon_compiler_namedvalue_hpp
#define rubicon_compiler_namedvalue_hpp

#include "value.hpp"
#include <string>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class NamedValue : public Value
{
public :
	NamedValue() = default;
	NamedValue(std::string const &name, std::shared_ptr< Value > const &value)
		: name_(name)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

private :
	std::string name_;
	std::shared_ptr< Value > value_;
};
}}}

#endif



