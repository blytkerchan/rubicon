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
		  OutputIterator out 
		, MultiPassInputIterator first 
		, MultiPassInputIterator last 
		)
	{
		// encode the type octet
		*out++ = 0x04;
		encodeLength(out, std::distance(first, last));
		std::copy(first, last, out);
	}
	
private :

};
}}

#endif
