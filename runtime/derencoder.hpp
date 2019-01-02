#ifndef vlinder_rubicon_derencoder_hpp
#define vlinder_rubicon_derencoder_hpp

#include "config.hpp"
#include "details/buffer.hpp"
#include "integer.hpp"
#include <cmath>
#include <limits>
#include <memory>

namespace Vlinder { namespace Rubicon {
class DEREncoder
{
	enum struct DoubleValueCategory {
		  normal__
		, positive_infinity__
		, negative_infinity__
		, not_a_number__
		, positive_zero__
		, negative_zero__
		};
public :
	DEREncoder() = default;
	template < typename Buffer >
	DEREncoder(Buffer &buffer)
		: buffer_(std::make_shared< Details::Buffer_< Buffer > >(buffer))
	{ /* no-op */ }
	~DEREncoder() = default;
	DEREncoder(DEREncoder const&) = default;
	DEREncoder(DEREncoder &&) = default;
	DEREncoder& operator=(DEREncoder const&) = default;
	DEREncoder& operator=(DEREncoder &&) = default;

	void encodeBoolean(bool value)
	{
		auto iter(std::back_inserter(*buffer_));
		encodeBoolean_(iter, value);
	}
	template < typename MultiPassInputIterator >
	void encodeBitString(
		  unsigned int unused_bits
		, MultiPassInputIterator first
		, MultiPassInputIterator last
		)
	{
		auto iter(std::back_inserter(*buffer_));
		encodeBitString_(iter, unused_bits, first, last);
	}

private :
	template < typename OutputIterator >
	static void encodeEndOfContents(OutputIterator &out)
	{
		// encode the type octet 
		*out++ = 0x00;
		encodeLength(out, 0);
	}
	
	template < typename OutputIterator >
	static void encodeBoolean_(OutputIterator &out, bool value)
	{
		*out++ = 0x01;
		encodeLength(out, 1);
		*out++ = value ? 0xFF : 0x00;
	}
	
	template < typename OutputIterator >
	static void encodeInteger(OutputIterator &out, Integer value)
	{
		*out++ = 0x02;
		value.compact();
		encodeLength(out, value.size());
		out = std::copy(value.begin(), value.end(), out);
	}
	
	template < typename OutputIterator >
	static void encodeEnumerated(OutputIterator &out, int value)
	{
		*out++ = 0x0A;
		Integer value_as_integer(value);
		value_as_integer.compact();
		encodeLength(out, value_as_integer.size());
		out = std::copy(value_as_integer.begin(), value_as_integer.end(), out);
	}
	
	template < typename OutputIterator, typename MultiPassInputIterator >
	static void encodeBitString_(
		  OutputIterator &out
		, unsigned int unused_bits
		, MultiPassInputIterator first
		, MultiPassInputIterator last
		)
	{
		pre_condition(unused_bits < 8);
		*out++ = 0x03;
		encodeLength(out, std::distance(first, last) + 1);
		*out++ = unused_bits;
		out = std::copy(first, last, out);
	}
	
	template < typename OutputIterator >
	static void encodeReal(OutputIterator &out, double value)
	{
		DoubleValueCategory category;
		int sign;
		Integer mantissa;
		unsigned int base;
		unsigned int scale_factor;
		int exponent;
		dissectDouble(value, category, sign, mantissa, base, scale_factor, exponent);
	
		*out++ = 0x09;
		// a few special values to handle first 
		switch (category)
		{
		case DoubleValueCategory::positive_infinity__ :
			encodeLength(out, 1);
			*out++ = 0x40;
			break;
		case DoubleValueCategory::negative_infinity__ :
			encodeLength(out, 1);
			*out++ = 0x41;
			return;
		case DoubleValueCategory::not_a_number__ :
			encodeLength(out, 1);
			*out++ = 0x42;
			return;
		case DoubleValueCategory::negative_zero__ :
			encodeLength(out, 1);
			*out++ = 0x43;
			return;
		case DoubleValueCategory::positive_zero__ :
			encodeLength(out, 0);
			return;
		default :
			// either normal or subnormal, we'll encode 
			break;
		}
		
		Integer exponent_as_integer(exponent);
		// the first encoded value octet doesn't have a name in X.690, but it
		// *indicates* the way the value is encoded, so I decided to call it
		// the "indicator octet".
		unsigned char indicator_octet(0x80); // bit 8(7) to indicate binary encoding 
		indicator_octet |= (sign == -1) ? 0x40 : 0x00;
		switch (base)
		{
		case 2 :
			// indicator octet is OK for now 
			break;
		case 8 :
			indicator_octet |= 0x10;
			break;
		case 16 :
			indicator_octet |= 0x20;
			break;
		default :
			throw std::logic_error("unreachable code");
		}
		exponent_as_integer.compact();
		assert(exponent_as_integer.size() <= 255);
		switch (exponent_as_integer.size())
		{
		case 0 :
			// fall through: if the exponent is zero, were still need an octet
			// to encode it
		case 1 :
			// indicator octet already OK 
			break;
		case 2 :
			indicator_octet |= 0x01;
			break;
		case 3 :
			indicator_octet |= 0x02;
			break;
		default :
			indicator_octet |= 0x03;
		}
		mantissa.compact();
		unsigned int const bytes_for_indicator(1);
		unsigned int const bytes_for_exponent_length(exponent_as_integer.size() > 3 ? 1 : 0);
		unsigned int const bytes_for_exponent_value(exponent_as_integer.size());
		unsigned int const bytes_for_mantissa_value(mantissa.size());
		encodeLength(out, bytes_for_indicator + bytes_for_exponent_length + bytes_for_exponent_value + bytes_for_mantissa_value);
		*out++ = indicator_octet;
		if (exponent_as_integer.size() > 3)
		{
			*out++ = exponent_as_integer.size();
		}
		else 
		{ /* already encoded */ }
		if (exponent_as_integer.size() == 0)
		{
			*out++ = 0;
		}
		else 
		{
			out = std::copy(exponent_as_integer.begin(), exponent_as_integer.end(), out);
		}
		assert(mantissa.size() != 0);
		out = std::copy(mantissa.begin(), mantissa.end(), out);
	}
	
	template < typename OutputIterator, typename MultiPassInputIterator >
	static void encodeOctetString(
		  OutputIterator &out 
		, MultiPassInputIterator first 
		, MultiPassInputIterator last 
		)
	{
		// encode the type octet
		*out++ = 0x04;
		encodeLength(out, std::distance(first, last));
		out = std::copy(first, last, out);
	}

	template < typename OutputIterator, typename MultiPassInputIterator >
	static void encodeSequence(
		  OutputIterator &out
		, MultiPassInputIterator first
		, MultiPassInputIterator last
		)
	{
		*out++ = 0x30;
		encodeLength(out, std::distance(first, last));
		out = std::copy(first, last, out);
	}
	
	template < typename OutputIterator, typename MultiPassInputIterator >
	static void encodeSet(
		  OutputIterator &out
		, MultiPassInputIterator first
		, MultiPassInputIterator last
		)
	{
		*out++ = 0x31;
		encodeLength(out, std::distance(first, last));
		out = std::copy(first, last, out);
	}

private :
	template < typename OutputIterator >
	static void encodeLength(OutputIterator &out, uint64_t length)
	{
		if (length <= 127)
		{
			*out++ = length;
		}
		else 
		{
			Integer integer_length(length);
			integer_length.compact();
			assert(integer_length.size() > 1);
			assert(integer_length.size() <= sizeof(length));
			assert(integer_length.size() < 127);
			unsigned char integer_length_size(integer_length.size());
			integer_length_size |= 0x80;
			*out++ = integer_length_size;
			out = std::copy(integer_length.begin(), integer_length.end(), out);
		}
	}
	
	static void dissectDouble(
		  double value
		, DoubleValueCategory &category
		, int &sign
		, Integer &mantissa
		, unsigned int &base
		, unsigned int &scale_factor
		, int &exponent
		)
	{
		switch (std::fpclassify(value))
		{
		case FP_INFINITE :
			category = std::signbit(value) ? DoubleValueCategory::negative_infinity__ : DoubleValueCategory::positive_infinity__;
			return;
		case FP_NAN :
			category = DoubleValueCategory::not_a_number__;
			return;
		case FP_ZERO :
			category = std::signbit(value) ? DoubleValueCategory::negative_zero__ : DoubleValueCategory::positive_zero__;
			return;
		default :
			category = DoubleValueCategory::normal__;
		}
	
		sign = std::signbit(value) ? -1 : 1;
		value *= sign;
		double const mantissa_as_double(std::frexp(value, &exponent));
		double const mantissa_as_intermediate_for_integer(ldexp(mantissa_as_double, std::numeric_limits< double >::digits));
		exponent -= std::numeric_limits< double >::digits;
		static_assert(std::numeric_limits< double >::digits < std::numeric_limits< uint64_t >::digits, "double is expected to have a smaller mantissa than the bits in a 64-bit integer");
		static_assert(std::numeric_limits< double >::radix == std::numeric_limits< uint64_t >::radix, "radix for double and int should be the same");
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
		mantissa = Integer(mantissa_as_uint);
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
private :
	std::shared_ptr< Details::Buffer > buffer_;
};
}}

#endif
