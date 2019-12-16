#ifndef rubicon_compiler_sequencevalue_hpp
#define rubicon_compiler_sequencevalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class SequenceValue : public Value
{
public :
    typedef std::vector< std::shared_ptr< Value > > Values_;
    typedef Values_::const_iterator const_iterator;

	SequenceValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }

	void add(std::shared_ptr< Value > const &value)
	{
		values_.push_back(value);
	}

	std::string getTypeName() const override { return typeid(*this).name(); }

	std::string generateInstance() const override { return "/*TODO*/"; }

    const_iterator begin() const { return values_.begin(); }
    const_iterator end() const { return values_.end(); }

private :
	Values_ values_;
};
}}}

#endif




