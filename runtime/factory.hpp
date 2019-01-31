#ifndef vlinder_rubicon_factory_hpp
#define vlinder_rubicon_factory_hpp

#include "types.hpp"
#include "derdecoder.hpp"
#include "details/any.hpp"

namespace Vlinder { namespace Rubicon {
namespace Details {
class Builder : DERDecoder
{
public :
        Builder() = default;
        ~Builder() = default;
        Builder(Builder const&) = delete;
        Builder& operator=(Builder const &) = delete;
        Builder(Builder &&) = default;
        Builder& operator=(Builder &&) = default;

        template < typename InputIterator >
        Integer buildInteger(InputIterator &first, InputIterator last)
        {
                state_ = decoding_integer__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< Integer >();
        }
        template < typename InputIterator >
        int buildEnumerated(InputIterator &first, InputIterator last)
        {
                state_ = decoding_enumerated__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< int >();
        }
        template < typename InputIterator >
        BitString buildBitString(InputIterator &first, InputIterator last)
        {
                state_ = decoding_bitstring__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< BitString >();
        }
        template < typename InputIterator >
        OctetString buildOctetString(InputIterator &first, InputIterator last)
        {
                state_ = decoding_octetstring__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< OctetString >();
        }
        template < typename InputIterator >
        Null buildNull(InputIterator &first, InputIterator last)
        {
                state_ = decoding_null__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< Null >();
        }
        template < typename InputIterator >
        Boolean buildBoolean(InputIterator &first, InputIterator last)
        {
                state_ = decoding_boolean__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< Boolean >();
        }
        template < typename InputIterator >
        Real buildReal(InputIterator &first, InputIterator last)
        {
                state_ = decoding_real__;
		if (!parse(first, last))
		{
			throw Vlinder::Rubicon::ParseError("Incomplete parse");
		}
		return get< Real >();
        }

        template < typename T >
        T get() const { return any_cast< T >(value_); }

protected :
	virtual void onEndOfContents() override;
	virtual void onInteger(Integer const &value) override;
	virtual void onEnumerated(int value) override;
	virtual void onBitString(bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last) override;
	virtual void onOctetString(bool final, unsigned char *first, unsigned char *last) override;
	virtual void onNull() override;
	virtual void onBeginSequence() override;
	virtual void onEndSequence() override;
	virtual void onBeginSet() override;
	virtual void onEndSet() override;
	virtual void onBoolean(bool val) override;
	virtual void onReal(double val) override;

private :
        enum State {
                  decoding_integer__
                , decoding_enumerated__
                , decoding_bitstring__
                , decoding_octetstring__
                , decoding_null__
                , decoding_boolean__
                , decoding_real__
                };

        Details::Any value_;
        State state_;
};
}        
template < typename InputIterator >
Integer decodeInteger(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildInteger(first, last);
}
template < typename InputIterator >
int decodeEnumerated(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildEnumerated(first, last);
}
template < typename InputIterator >
BitString decodeBitString(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildBitString(first, last);
}
template < typename InputIterator >
OctetString decodeOctetString(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildOctetString(first, last);
}
template < typename InputIterator >
Null decodeNull(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildNull(first, last);
}
template < typename InputIterator >
Boolean decodeBoolean(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildBoolean(first, last);
}
template < typename InputIterator >
Real decodeReal(InputIterator &first, InputIterator last)
{
        Details::Builder builder;
        return builder.buildReal(first, last);
}
}}

#endif
