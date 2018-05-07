#ifndef rubicon_compiler_sequenceofvalue_hpp
#define rubicon_compiler_sequenceofvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct SequenceOfValue : Value
{
	SequenceOfValue()
	{ /* no-op */ }

	void add(std::shared_ptr< Value > const &value)
	{
		values_.push_back(value);
	}

	std::vector< std::shared_ptr< Value > > values_;
};
}}}

#endif




