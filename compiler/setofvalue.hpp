#ifndef rubicon_compiler_setofvalue_hpp
#define rubicon_compiler_setofvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class SetOfValue : public Value
{
public :
	SetOfValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }

	void add(std::shared_ptr< Value > const &value)
	{
		values_.push_back(value);
	}

	std::string getTypeName() const override { return typeid(*this).name(); }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	std::vector< std::shared_ptr< Value > > values_;
};
}}}

#endif




