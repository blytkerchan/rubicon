#ifndef rubicon_compiler_sequencevalue_hpp
#define rubicon_compiler_sequencevalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class SequenceValue : public Value
{
public :
	SequenceValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }

	void add(std::shared_ptr< Value > const &value)
	{
		values_.push_back(value);
	}

	std::string getTypeName() const override { return typeid(*this).name(); }

private :
	std::vector< std::shared_ptr< Value > > values_;
};
}}}

#endif




