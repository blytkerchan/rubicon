#ifndef vlinder_rubicon_derdecoder_hpp
#define vlinder_rubicon_derdecoder_hpp

#include "config.hpp"
#include "details/integer.hpp"
#include <algorithm>
#include <limits>

namespace Vlinder { namespace Rubicon {
class DERDecoder
{
public :
	DERDecoder() = default;
	virtual ~DERDecoder() = default;
	DERDecoder(DERDecoder const &) = default;
	DERDecoder(DERDecoder &&) = default;
	DERDecoder& operator=(DERDecoder const &) = default;
	DERDecoder& operator=(DERDecoder &&) = default;
	
	void reset();
	
	template < typename InputIterator >
	bool parse(InputIterator &first, InputIterator last)
	{
		while (1)
		{
			switch (state_)
			{
			case State::expect_type__ :
			{
				if (first == last) return false;
				parseType(*first++);
				state_ = State::expect_length__;
				// fall through
			}
			case State::expect_length__ :
			{
				bool complete(parseLength(first, last));
				if (!complete) return false;
				state_ = State::expect_value__;
				// fall through
			}
			case State::expect_value__ :
			{
				bool complete(parseValue(first, last));
				if (!complete) return false;
				state_ = State::expect_type__;
				parse_buffer_size_ = 0;
				length_ = 0;
				if ((0 != stack_depth_) && (0 == length_stack_[stack_depth_ - 1]))
				{
					switch (type_stack_[stack_depth_].tag_)
					{
					case 0x10 : // sequence
						onEndSequence();
						break;
					case 0x11 : // set
						onEndSet();
						break;
					default :
						throw std::logic_error("End of what?");
					}
					--stack_depth_;
				}
				break;
			}
			}
		}
	}
	
	virtual void onEndOfContents() = 0;
	virtual void onInteger(Details::Integer< RUBICON_MAX_BITS_PER_INTEGER > const &value) = 0;
	virtual void onEnumerated(int value) = 0;
	virtual void onBitString(bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last) = 0;
	virtual void onOctetString(bool final, unsigned char *first, unsigned char *last) = 0;
	virtual void onNull() = 0;
	virtual void onBeginSequence() = 0;
	virtual void onEndSequence() = 0;
	virtual void onBeginSet() = 0;
	virtual void onEndSet() = 0;
	virtual void onBoolean(bool val) = 0;
	virtual void onReal(double val) = 0;
	
private :
	enum struct State {
		  initial__
		, expect_type__ = initial__
		, expect_length__
		, expect_value__
		};
	enum struct TypeClass {
		  universal__
		, application__
		, context_specific__
		, private__
		};
	struct Type 
	{
		TypeClass type_class_;
		bool constructed_;
		uint8_t tag_;
	};
	
	void parseType(unsigned char tag);
	
	template < typename InputIterator >
	bool parseLength(InputIterator &first, InputIterator last)
	{
		if (first == last) return false;
		assert(parse_buffer_size_ < sizeof(parse_buffer_));
		// When we get here, we know we have at least one extra byte to parse
		// to get the length. We also know that whatever other bytes make up
		// the length are either waiting in the input or already in the length
		// buffer, so we add one byte the input into the length buffer and
		// try to parse the length buffer as a length. If the of the length
		// is greater than 64 bits, we bail out.
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
			if (0 == (parse_buffer_[0] & 0x80))
			{
				// we have the complete length 
				length_ = parse_buffer_[0];
				parse_buffer_size_ = 0;
				return true;
			}
			else if (0x80 == parse_buffer_[0])
			{
				throw EncodingError("Invalid DER: indeterminate size");
			}
			else if ((parse_buffer_[0] & 0x1F) > sizeof(parse_buffer_) - 1)
			{
				throw EncodingError("only 64 bits or less of size supported");
			}
			else 
			{
				if ((parse_buffer_size_ - 1) == (parse_buffer_[0] & 0x1F))
				{
					length_ = 0;
					for (
						  unsigned char *length_byte(parse_buffer_ + 1)
						; length_byte != (parse_buffer_ + parse_buffer_size_)
						; ++length_byte
						)
					{
						length_ *= 256;
						length_ += *length_byte;
					}
					parse_buffer_size_ = 0;
					if (0 != stack_depth_)
					{
						if (length_ > length_stack_[stack_depth_ - 1]) throw EncodingError("TLV larger than remaining space in construct");
						length_stack_[stack_depth_ - 1] -= length_;
					}
					return true;
				}
				else 
				{ /* don't have it all yet */ }
			}
		} while(first != last);
		
		return false;
	}
	
	template < typename InputIterator >
	bool parseValue(InputIterator &first, InputIterator last)
	{
		switch (type_.type_class_)
		{
		case TypeClass::universal__ : return parseUniversalValue(first, last);
		case TypeClass::application__ : return parseApplicationValue(first, last);
		case TypeClass::context_specific__ : return parseContextSpecificValue(first, last);
		case TypeClass::private__ : return parsePrivateValue(first, last);
		}
		return false;
	}
	
	template < typename InputIterator >
	bool parseUniversalValue(InputIterator &first, InputIterator last)
	{
		assert(type_.type_class_ == TypeClass::universal__);
		if (type_.constructed_)
		{
			switch (type_. tag_)
			{
			case 0x03 : // bit string (may be primitive)
				return parseBitString(first, last);
			case 0x04 : // octet string (may be primitive)
				return parseOctetString(first, last);
			case 0x08 : // external
			case 0x0B : // embedded PDV
			case 0x0C : // UTF8 string (may be primitive)
			case 0x10 : // sequence
				onBeginSequence();
				push(type_);
				return true;
			case 0x11 : // set
				onBeginSet();
				push(type_);
				return true;
			case 0x12 : // numeric string (may be primitive)
			case 0x13 : // printable string (may be primitive)
			case 0x14 : // T61 string (may be primitive)
			case 0x15 : // Videotex string (may be primitive)
			case 0x16 : // IA5 string (may be primitive)
			case 0x17 : // UTC time (may be primitive)
			case 0x18 : // generalised time (may be primitive)
			case 0x19 : // graphic string (may be primitive)
			case 0x1A : // visible string (may be primitive)
			case 0x1B : // general string (may be primitive)
			case 0x1C : // universal string (may be primitive)
			case 0x1D : // character string (may be primitive)
			case 0x1E : // BMP string (may be primitive)
				break;
			}
		}
		else 
		{
			switch (type_.tag_)
			{
			case 0x00 : // end of input
				if (0 != length_) throw EncodingError("Non-zero length for end-of-input tag");
				onEndOfContents();
				return true;
			case 0x01 : // boolean
				if (length_ != 1) throw EncodingError("Wrong length for Boolean value");
				if (first == last) return false; // no input, but an error 
				unsigned char value(*first++);
				onBoolean(0 != value);
				return true;
			case 0x02 : // integer
				return parseInteger(first, last);
			case 0x0A : // enumerated
				return parseEnumerated(first, last);
			case 0x03 : // bit string (may be constructed)
				return parseBitString(first, last);
			case 0x09 : // real 
				return parseReal(first, last);
			case 0x04 : // octet string (may be constructed)
				return parseOctetString(first, last);
			case 0x05 : // null
				if (0 != length_) throw EncodingError("Non-zero length for null tag");
				onNull();
				break;
			case 0x06 : // object identifier 
			case 0x07 : // object descriptor 
			case 0x0C : // UTF8 string (may be constructed)
			case 0x0D : // relative OID
			case 0x12 : // numeric string (may be constructed)
			case 0x13 : // printable string (may be constructed)
			case 0x14 : // T61 string (may be constructed)
			case 0x15 : // Videotex string (may be constructed)
			case 0x16 : // IA5 string (may be constructed)
			case 0x17 : // UTC time (may be constructed)
			case 0x18 : // generalised time (may be constructed)
			case 0x19 : // graphic string (may be constructed)
			case 0x1A : // visible string (may be constructed)
			case 0x1B : // general string (may be constructed)
			case 0x1C : // universal string (may be constructed)
			case 0x1D : // character string (may be constructed)
			case 0x1E : // BMP string (may be constructed)
			default :
				throw EncodingError("unknown type");
			}
		}
	}
	
	template < typename InputIterator >
	bool parseApplicationValue(InputIterator &first, InputIterator last)
	{
	}
	
	template < typename InputIterator >
	bool parseContextSpecificValue(InputIterator &first, InputIterator last)
	{
	}
	
	template < typename InputIterator >
	bool parsePrivateValue(InputIterator &first, InputIterator last)
	{
	}
	
	template < typename InputIterator >
	bool parseInteger(InputIterator &first, InputIterator last)
	{
		if (0 == length_) throw EncodingError("zero-byte integer value");
		if (first == last) return false;
		if (length_ > sizeof(parse_buffer_)) throw EncodingError("integer too large"); // increase the max_bits_per_integer__ value if you want to parse bigger integers 
		// if we get here, we have at least one byte to consume from the input 
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
		} while ((first != last) && (parse_buffer_size_ != length_));
		if (parse_buffer_size_ == length_)
		{
			onInteger(Details::Integer< RUBICON_MAX_BITS_PER_INTEGER >(parse_buffer_, parse_buffer_ + parse_buffer_size_));
			parse_buffer_size_ = 0;
			return true;
		}
		else 
		{ /* not done yet */ }
		return false;
	}
	
	template < typename InputIterator >
	bool parseEnumerated(InputIterator &first, InputIterator last)
	{
		// enumerated values are parsers as int values and may not be larger than
		// sizeof(int). They are signed (because nothing I've seen in X.690
		// indicates they aren't) so we do sign extension.
		if (length_ > sizeof(int)) throw EncodingError("enumerated value too large");
		if (0 == length_) throw EncodingError("empty enumerated value");
		if (first == last) return false;
		// if we get here we know we have at least one more byte to consume
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
		} while ((first != last) && (parse_buffer_size_ != length_));
		if (parse_buffer_size_ == length_)
		{
			int value(parse_buffer_[0] & 0x80 ? ~0 : 0);
			for (
				  unsigned char *value_byte(parse_buffer_ + 1)
				; value_byte != (parse_buffer_ + parse_buffer_size_)
				; ++value_byte
				)
			{
				value <<= 8;
				value |= *value_byte;
			}
			onEnumerated(value);
			parse_buffer_size_ = 0;
			return true;
		}
		else 
		{ /* not done yet */ }
		return false;
	}
	
	template < typename InputIterator >
	bool parseBitString(InputIterator &first, InputIterator last)
	{
		if (0 == length_) throw EncodingError("zero-length bit string");
		// If we get here, we are either constructing or consuming the string.
		// The parse_buffer_size_ member contains the number of bytes we've read
		// from the input. The first byte contains the number of bits that are not
		// used in the final byte. We only pass this to onBitString if we're
		// passing the final byte as well. 
		if (first != last) return false;
		uint64_t parse_buffer_size(parse_buffer_size_);
		auto avail(sizeof(parse_buffer_) - 1/* for the leading octet, which were need to preserve */);
		do 
		{
			if (0 == parse_buffer_size_)
			{
				parse_buffer_[parse_buffer_size_++] = *first++;
				parse_buffer_size = parse_buffer_size_;
			}
			else if (avail && (parse_buffer_size_ < length_))
			{
				parse_buffer_[parse_buffer_size_++ - parse_buffer_size + 1] = *first++;
				--avail;
			}
			else break;
		} while (first != last);
		if (parse_buffer_[0]/*unused bits the last byte*/ > 7) throw EncodingError("Too many unused bits in the final byte");
		bool const empty_bit_string((length_ == 1) && (parse_buffer_size_ == 1));
		bool const content_bytes_in_buffer(parse_buffer_size_ > parse_buffer_size);
		uint64_t const available_bytes(parse_buffer_size_ - parse_buffer_size);
		bool const final(length_ == parse_buffer_size_);
		unsigned int const unused_bits(final ? parse_buffer_[0] : 0);
		auto const beg(parse_buffer_ + 1);
		auto const end(parse_buffer_ + (parse_buffer_size_ - parse_buffer_size) + 1);
		assert(((parse_buffer_size_ - parse_buffer_size) + 1) <= sizeof(parse_buffer_));
		if (empty_bit_string || content_bytes_in_buffer)
		{
			if (empty_bit_string)
			{
				assert(0 == available_bytes);
				assert(final);
				if (parse_buffer_[0] != 0) throw EncodingError("unused bits in an empty bit string");
			}
			else 
			{ /* not an empty bit string */ }
			onBitString(
				  final
				, unused_bits
				, beg
				, end
				);
		}
		else
		{ /* nothing to report yet */ }
		
		if (final) parse_buffer_size_ = 0;
		return final;
	}
	
	template < typename InputIterator >
	bool parseReal(InputIterator &first, InputIterator last)
	{
		if (0 == length_)
		{
			onReal(0);
			return true;
		}
		else if (length_ > sizeof(parse_buffer_))
		{
			throw DecodingError("parse buffer too small for real value");
		}
		else 
		{ /* we have content octets to parse */ }
		if (first == last) return false;
		// When we get here, we know the value being encoded is not non-negative
		// zero. We don't support base-10 encoding (because I don't have a copy
		// of ISO 6093 and really — who would do such a thing?) so we bail out
		// if we see that that's what's in the input.
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
			switch (parse_buffer_[0] & 0xC0)
			{
			case 0x00 : throw DecodingError("base-10 (decimal) encoding of real values is not supported!");
			case 0x40 :
				if (length_ != 1) throw EncodingError("more than one octet for a ``special'' real value");
				switch (parse_buffer_[0])
				{
				case 0x40 : onReal(std::numeric_limits< double >::infinity()); return true;
				case 0x41 : onReal(-std::numeric_limits< double >::infinity()); return true;
				case 0x42 : onReal(std::numeric_limits< double >::quiet_NaN()); return true;
				case 0x43 : onReal(-0); return true;
				default : throw EncodingError("reserved special real value");
				}
				throw std::logic_error("unreachable code");
			default :
				// binary encoding
				break;
			}
		} while ((first != last) && (parse_buffer_size_ < length_));
		// when we get here, were either have the entire real value in the parse buffer (parse_buffer_size_ == length_) or we've run out of input data. 
		if (parse_buffer_size_ == length_)
		{
			int sign((parse_buffer_[0] & 0x40) == 0x40 ? -1 : 1);
			unsigned int base;
			switch (parse_buffer_[0] & 0x30)
			{
			case 0x00 :
				base = 2;
				break;
			case 0x10 :
				base = 8;
				break;
			case 0x20 :
				base = 16;
				break;
			default :
				throw EncodingError("reserved value for real base");
			}
			unsigned int const scale_factor((parse_buffer_[0] & 0x0C) >> 2);
			if (length_ < 2) throw EncodingError("Impossibly small real encoding");
			unsigned int const bytes_in_exponent(
				  ((parse_buffer_[0] & 0x03) == 3) ? parse_buffer_[1]
				: (parse_buffer_[0] & 0x03) + 1
				);
			unsigned char const *beg(parse_buffer_ + (((parse_buffer_[0] & 0x03) == 3) ? 2 : 1));
			unsigned char const *end(parse_buffer_ + parse_buffer_size_);
			int exponent(0);
			if ((bytes_in_exponent > sizeof(exponent)) || (std::distance(beg, end) < bytes_in_exponent)) throw EncodingError("exponent length error");
			end = beg + bytes_in_exponent;
			if ((bytes_in_exponent != 0) && ((*beg & 0x80) == 0x80)) exponent = ~0;
			for ( ; beg != end; ++beg)
			{
				exponent <<= 8;
				exponent |= *beg;
			}
			end = parse_buffer_ + parse_buffer_size_;
			
			double value(buildDouble(sign, Details::Integer< RUBICON_MAX_BITS_PER_INTEGER >(beg, end), base, scale_factor, exponent));
			onReal(value);
			length_ = 0;
			parse_buffer_size_ = 0;
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	template < typename InputIterator >
	bool parseOctetString(InputIterator &first, InputIterator last)
	{
		// like bit strings, we don't necessarily expect to have the entire octet
		// string available when we're called, so we indicate whether this is the
		// final chunk when calling onOctetString. Having the limitation of using
		// input iterator (which by definition can only be read from once) means
		// we read in chunks no bigger than our parse buffer. 
		while (first != last)
		{
			uint64_t initial_parse_buffer_size(parse_buffer_size_);
			uint64_t working_length(std::min(length_ - initial_parse_buffer_size, sizeof(parse_buffer_)));
			// there is no combination of std::copy and std::copy_n that works for
			// this particular situation, where I want to copy up to n elements
			// from a range, so I'll have to write an actual copying loop by hand :(
			for (uint64_t i(0); (first != last) && (i < working_length); )
			{
				parse_buffer_[i++] = *first++;
				++parse_buffer_size_;
			}
			onOctetString(
				  parse_buffer_size_ == length_
				, parse_buffer_
				, parse_buffer_ + working_length
				);
		}
		bool const done(parse_buffer_size_ == length_);
		if (done)
		{
			parse_buffer_size_ = 0;
			length_ = 0;
		}
		else 
		{ /* not done yet */ }
		return done;
	}

	void push(Type const &type);

	static double buildDouble(
		  int sign
		, Details::Integer< RUBICON_MAX_BITS_PER_INTEGER > mantissa
		, unsigned int base
		, unsigned int scale_factor
		, int exponent
		);
	
	State state_ = State::initial__;
	Type type_;
	uint64_t length_;
	unsigned char parse_buffer_[RUBICON_MAX_BITS_PER_INTEGER / 8];
	static_assert(RUBICON_MAX_BITS_PER_INTEGER >= 64);
	static_assert(RUBICON_MAX_BITS_PER_INTEGER >= (sizeof(int) * 8));
	uint64_t parse_buffer_size_ = 0;
	uint64_t length_stack_[RUBICON_STACK_SIZE];
	Type type_stack_[RUBICON_STACK_SIZE];
	uint64_t stack_depth_ = 0;
};
}}

#endif


