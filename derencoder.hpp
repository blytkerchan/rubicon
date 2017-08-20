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
