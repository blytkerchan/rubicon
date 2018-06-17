#ifndef rubicon_compiler_realvalue_hpp
#define rubicon_compiler_realvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class RealValue : public Value
{
public :
	enum ValueType {
		  normal__
		, plus_infinity__
		, minus_infinity__
		, not_a_number__
		};

	RealValue(SourceLocation const &source_location, double value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }
	RealValue(SourceLocation const &source_location, ValueType value_type)
		: Value(source_location)
		, value_type_(value_type)
	{ /* no-op */ }
	RealValue(SourceLocation const &source_location, std::shared_ptr< Value > value)
		: Value(source_location)
		, sequence_value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "Real"; }

private :
	double value_ = 0.0;
	ValueType value_type_ = normal__;
	std::shared_ptr< Value > sequence_value_;
};
}}}

#endif



