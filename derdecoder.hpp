namespace Vlinder { namespace Rubicon {
template < unsigned int max_bits_per_integer__ = 2048 >
class DERDecoder
{
public :
	DERDecoder() = default;
	virtual ~DERDecoder = default;
	DERDecoder(DERDecoder const &) = default;
	DERDecoder(DERDecoder &&) = default;
	DERDecoder& operator=DERDecoder(DERDecoder const &) = default;
	DERDecoder& operator=DERDecoder(DERDecoder &&) = default;

	template < typename InputIterator >
	bool parse(InputIterator &first, InputIterator last)
	{
		while (first != last)
		{
			switch (state_)
			{
			case State::expect_type__ :
			{
				parseType(*first++);
				state_ = State::expect_length__;
				break;
			}
			case State::expect_length__ :
			{
				bool complete(parseLength(first, last));
				if (!complete) return false;
				state_ = State::expect_value__;
				break;
			}
			case State::expect_value__ :
			{
				bool complete(parseValue(first, last));
				if (!complete) return false;
				state_ = State::expect_type__;
				break;
			}
			}
		}
	}
	
	virtual void onEndOfInput() noexcept = 0;
	// Callee will receive between one and N bytes where
	// N depends on the maximum number of bits in an integer,
	// in network byte order.
	virtual void onInteger(unsigned char *first, unsigned char *last) noexcept = 0;
	virtual void onEnumerated(int value) noexcept = 0;
	virtual void onBitString(bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last) noexcept = 0;
	
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
	
	void parseType(unsigned char tag)
	{
		switch (tag & 0xC0)
		{
		case 0x00 :
			type_.type_class_ = TypeClass::universal__;
			break;
		case 0x40 :
			type.type_class_ = TypeClass::application__;
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
			throw NotYetImplemented("multi-byte type tags are not yet implemented");
		}
		else 
		{ /* all is well */ }
	}
	
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
				throw IndeterminateSize("Invalid DER");
			}
			else if ((parse_buffer_[0] & 0x1F) > sizeof(parse_buffer_) - 1)
			{
				throw SizeTooLarge("only 64 bits or less of size supported");
			}
			else 
			{
				if ((parse_buffer_size_ - 1) == (parse_buffer_[0] & 0x1F))
				{
					length_ = 0;
					for (
						  unsigned char *length_byte(parse_buffer_ + 1)
						; length_byte != (parse_buffer + parse_buffer_size_)
						; ++length_byte
						)
					{
						length_ *= 256;
						length_ += *length_byte;
					}
					parse_buffer_size_ = 0;
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
			case 0x08 : // external
			case 0x0B : // embedded PDV
			case 0x0C : // UTF8 string (may be primitive)
			case 0x10 : // sequence 
			case 0x11 : // set
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
			}
		}
		else 
		{
			switch (type_.tag_)
			{
			case 0x00 : // end of input
				if (0 != length_) throw EncodingError("Non-zero length for end-of-input tag");
				onEndOfInput();
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
				return parseBitString(first, last;
			case 0x04 : // octet string (may be constructed)
			case 0x05 : // null 
			case 0x06 : // object identifier 
			case 0x07 : // object descriptor 
			case 0x09 : // real 
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
		if (length_ > sizeof(parse_buffer_)) throw EncodingError("integer too large"); // increase the max_bits_per_integer__ value if you want to parse bigger integers 
		// if we get here, we have at least one byte to consume from the input 
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
		} while ((first != last) && (parse_buffer_size_ != length_));
		if (parser_buffer_size_ == length_)
		{
			// we don't know what the large integer representation is here, so we
			// just pass the beginning and end pointer of the parsed integer here.
			onInteger(parse_buffer_, parse_buffer_ + parse_buffer_size_);
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
		// if we get here we know we have at least one more byte to consume
		do 
		{
			parse_buffer_[parse_buffer_size_++] = *first++;
		} while ((first != last) && (parse_buffer_size_ != length_));
		if (parser_buffer_size_ == length_)
		{
			int value(parse_buffer_[0] & 0x80 ? ~0 : 0;
			for (
				  unsigned char *value_byte(parse_buffer_ + 1)
				; value_byte != (parse_buffer + parse_buffer_size_)
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
		assert(first != last);
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
		unsigned int const unused_bits(final ? parse_buffer_[0]);
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
	
	State state_ = initial__;
	Type type_;
	uint64_t length_;
	unsigned char parse_buffer_[max_bits_per_integer__ / 8];
	static_assert(max_bits_per_integer__ >= 64);
	static_assert(max_bits_per_integer__ >= (sizeof(int) * 8));
	uint64_t parse_buffer_size_ = 0;
};
}}
