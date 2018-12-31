#include "derdecoder.hpp"
#include <cmath>
#include <stdexcept>

using namespace std;

namespace Vlinder { namespace Rubicon {
void DERDecoder::reset()
{
	state_ = State::expect_type__;
	parse_buffer_size_ = 0;
	length_ = 0;
	stack_depth_ = 0;
}

void DERDecoder::parseType(unsigned char tag)
{
	switch (tag & 0xC0)
	{
	case 0x00 :
		type_.type_class_ = TypeClass::universal__;
		break;
	case 0x40 :
		type_.type_class_ = TypeClass::application__;
		break;
	case 0x80 :
		type_.type_class_ = TypeClass::context_specific__;
		break;
	case 0xC0 :
		type_.type_class_ = TypeClass::private__;
		break;
	}
	type_.constructed_ = ((tag & 0x20) == 0x20);
	type_.tag_ = tag & 0x1F;
	if (0x1F == type_.tag_)
	{
		throw logic_error("multi-byte type tags are not yet implemented");
	}
	else 
	{ /* all is well */ }
}

void DERDecoder::push(Type const &type)
{
	static_assert((sizeof(type_stack_) / sizeof(type_stack_[0])) == (sizeof(length_stack_) / sizeof(length_stack_[0])), "Both stacks should be the same size");
	if (stack_depth_ == (sizeof(type_stack_) / sizeof(type_stack_[0]))) throw StackOverflow("Too many levels of structured data");
	length_stack_[stack_depth_] = length_;
	type_stack_[stack_depth_] = type;
	++stack_depth_;
}

/*static */double DERDecoder::buildDouble(
	  int sign
	, Details::Integer< RUBICON_MAX_BITS_PER_INTEGER > mantissa
	, unsigned int base
	, unsigned int scale_factor
	, int exponent
	)
{
	static_assert(numeric_limits< double >::radix == 2, "radix of double must be 2");
	double retval(0.0);

	pre_condition((base == 2) || (base == 8) || (base == 16));
	switch (base)
	{
	case 2 :
		base = 1;
		break;
	case 8:
		base = 3;
		break;
	case 16:
		base = 4;
		break;
	}
	for_each(
		  mantissa.begin()
		, mantissa.end()
		, [&retval](unsigned char octet){
			retval = ldexp(retval, 8) + octet;
		});
	pre_condition(scale_factor <= 3);
	pre_condition(		(exponent >= numeric_limits< decltype(exponent) >::min() / 12/*see below*/)
			&& 	(exponent <= numeric_limits< decltype(exponent) >::max() / 12/*maximum value for scale_factor * base*/)
			);
	retval = ldexp(retval, exponent * scale_factor * base) * sign;

	return retval;
}

}}



