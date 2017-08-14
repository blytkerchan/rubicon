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
