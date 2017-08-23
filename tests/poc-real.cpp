#include "../details/integer.hpp"
#include "../exceptions/contract.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;
using namespace Vlinder::Rubicon;

static_assert(numeric_limits< double >::radix == 2, "radix of double must be 2");

enum struct Category {
	  normal__
	, positive_infinity__
	, negative_infinity__
	, not_a_number__
	, positive_zero__
	, negative_zero__
	};

double buildDouble(int sign, Details::Integer<> mantissa, unsigned int base, unsigned int scale_factor, int exponent)
{
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

void dissectDouble(double value, Category &category, int &sign, Details::Integer<> &mantissa, unsigned int &base, unsigned int &scale_factor, int &exponent)
{
	switch (fpclassify(value))
	{
	case FP_INFINITE :
		category = signbit(value) ? Category::negative_infinity__ : Category::positive_infinity__;
		return;
	case FP_NAN :
		category = Category::not_a_number__;
		return;
	case FP_ZERO :
		category = signbit(value) ? Category::negative_zero__ : Category::positive_zero__;
		return;
	default :
		category = Category::normal__;
	}

	sign = signbit(value) ? -1 : 1;
	value *= sign;
	double const mantissa_as_double(frexp(value, &exponent));
	double const mantissa_as_intermediate_for_integer(ldexp(mantissa_as_double, numeric_limits< double >::digits));
	exponent -= numeric_limits< double >::digits;
	static_assert(numeric_limits< double >::digits < numeric_limits< uint64_t >::digits, "double is expected to have a smaller mantissa than the bits in a 64-bit integer");
	static_assert(numeric_limits< double >::radix == numeric_limits< uint64_t >::radix, "radix for double and int should be the same");
	uint64_t mantissa_as_uint(mantissa_as_intermediate_for_integer);
	while ((mantissa_as_uint % 256) == 0)
	{
		exponent += 8;
		mantissa_as_uint /= 256;
	}
	while ((mantissa_as_uint % 16) == 0)
	{
		exponent += 4;
		mantissa_as_uint /= 16;
	}
	while ((mantissa_as_uint % 2) == 0)
	{
		++exponent;
		mantissa_as_uint /= 2;
	}
	mantissa = Details::Integer<>(mantissa_as_uint);
	base = 2;
	if ((exponent % 4) == 0)
	{
		base = 16;
		exponent /= 4;
	}
	else if ((exponent % 3) == 0)
	{
		base = 8;
		exponent /= 3;
	}
	else
	{ /* don't adjust the base */ }
	for (scale_factor = 3; scale_factor > 1; --scale_factor)
	{
		if ((exponent % scale_factor) == 0)
		{
			exponent /= scale_factor;
			break;
		}
		else
		{ /* not this one */ }
	}
}

int main()
{
	cout << "-4*2^(1*12) = " << buildDouble(-1, Details::Integer<>(4), 2, 1, 12) << endl;
	cout << "827 * 16^(2*13) = " << buildDouble(1, Details::Integer<>(827), 16, 2, 13) << endl;

	Category category;
	int sign;
	Details::Integer<> mantissa;
	unsigned int base;
	unsigned int scale_factor;
	int exponent;
	dissectDouble(buildDouble(-1, Details::Integer<>(4), 2, 1, 12), category, sign, mantissa, base, scale_factor, exponent);
	assert(category == Category::normal__);
	assert(sign == -1);
	assert(mantissa == Details::Integer<>(1));
	assert(base == 2);
	assert(scale_factor == 2);
	assert(exponent == 7);
}

