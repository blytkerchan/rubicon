#ifndef rubicon_compiler_realvalue_hpp
#define rubicon_compiler_realvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct RealValue : Value
{
	enum ValueType {
		  normal__
		, plus_infinity__
		, minus_infinity__
		, not_a_number__
		};

	RealValue(double value)
		: value_(value)
	{ /* no-op */ }
	RealValue(ValueType value_type)
		: value_type_(value_type)
	{ /* no-op */ }
	RealValue(std::shared_ptr< Value > value)
		: sequence_value_(value)
	{ /* no-op */ }

	double value_ = 0.0;
	ValueType value_type_ = normal__;
	std::shared_ptr< Value > sequence_value_;
};
}}}

#endif



