#ifndef vlinder_rubicon_derencoder_hpp
#define vlinder_rubicon_derencoder_hpp

namespace Vlinder { namespace Rubicon {
class DEREncoder
{
public :
	DEREncoder() = default;
	~DEREncoder() = default;
	DEREncoder(DEREncoder const&) = default;
	DEREncoder(DEREncoder &&) = default;
	DEREncoder& operator=(DEREncoder const&) = default;
	DEREncoder& operator=(DEREncoder &&) = default;
	
	template < typename OutputIterator >
	void encodeEndOfContents(OutputIterator &out)
	{
		// encode the type octet 
		*out++ = 0x00;
		encodeLength(out, 0);
	}
	
	template < typename OutputIterator >
	void encodeBoolean(OutputIterator &out, bool value)
	{
		*out++ = 0x01;
		encodeLength(out, 1);
		*out++ = value ? 0xFF : 0x00;
	}
	
	template < typename OutputIterator >
	void encodeInteger(OutputIterator &out, Details::Integer value)
	{
		*out++ = 0x02;
		value.compact();
		encodeLength(out, value.size());
		out = std::copy(value.begin(), value.end(), out);
	}
	
	template < typename OutputIterator >
	void encodeEnumerated(OutputIterator &out, int value)
	{
		*out++ = 0x0A;
		Details::Integer value_as_integer(value);
		value_as_integer.compact();
		encodeLength(out, value_as_integer.size());
		out = std::copy(value_as_integer.begin(), value_as_integer.end(), out);
	}
	
	template < typename OutputIterator, typename MultiPassInputIterator >
	void encodeBitString(
		  OutputIterator &out
		, unsigned int unused_bits
		, MultiPassInputIterator first
		, MultiPassInputIterator last
		)
	{
		pre_condition(unused_bits < 8);
		*out++ = 0x03;
		*out++ = unused_bits;
		encodeLength(out, std::distance(first, last);
		out = std::copy(first, last, out);
	}
	
	template < typename OutputIterator >
	void encodeReal(OutputIterator &out, double value)
	{
		*out++ = 0x09;
		// a few special values to handle first 
		switch (std::fpclassify(value))
		{
		case FP_INFINITE	:
			encodeLength(out, 1);
			*out++ = std::signbit(value) ? 0x41 : 0x40;
			return;
		case FP_NAN			:
			encodeLength(out, 1);
			*out++ = 0x42;
			return;
		case FP_ZERO		:
			if (std::signbit(value))
			{
				encodeLength(out, 1);
				*out++ = 0x43;
			}
			else 
			{
				encodeLength(out, 0);
			}
			return;
		default :
			// either normal or subnormal, we'll encode 
			break;
		}
		
		int exponent;
		double mantissa(frexp(value, &exponent));
		Details::Integer exponent_as_integer(exponent);
		// the first encoded value octet doesn't have a name in X.690, but it
		// *indicates* the way the value is encoded, so I decided to call it
		// the "indicator octet".
		unsigned char indicator_octet(0x80); // bit 8(7) to indicate binary encoding 
		indicator_octet |= std::signbit(value) ? 0x40 : 0x00;
		uint64_t mantissa_as_int(mantissa);
		unsigned int base(2);
		if ((mantissa_as_int % 4) == 0)
		{
			base *= 4;
			mantissa_as_int /= 4;
		}
		else 
		{ /* base 8 */ }
		if ((mantissa_as_int % 2) == 0)
		{
			assert(base == 8);
			base *= 2;
			mantissa_as_int /= 2;
		}
		else 
		{ /* base is final */ }
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
		mantissa_as_integer.compact();
		unsigned int const bytes_for_indicator(1);
		unsigned int const bytes_for_exponent_length(exponent_as_integer.size() > 3 ? 1 : 0);
		unsigned int const bytes_for_exponent_value(exponent_as_integer.size());
		unsigned int const bytes_for_mantissa_value(mantissa_as_integer.size());
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
		assert(mantissa_as_integer.size() != 0):
		out = std::copy(mantissa_as_integer.begin(), mantissa_as_integer.end(), out);
	}
	
	template < typename OutputIterator, typename MultiPassInputIterator >
	void encodeOctetString(
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
	
private :
	template < typename OutputIterator >
	void encodeLength(OutputIterator &out, uint64_t length)
	{
		if (length <= 127)
		{
			*out++ = length;
		}
		else 
		{
			Details::Integer integer_length(length);
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
};
}}

#endif
