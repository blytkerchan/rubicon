#include "factory.hpp"
#include "exceptions.hpp"
#include <vector>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Details {
/*virtual */void Builder::onEndOfContents()/* override*/
{
        throw std::logic_error("Not supported for this builder");
}
/*virtual */void Builder::onInteger(Integer const &value)/* override*/
{
        if (state_ != decoding_integer__)
        {
                throw ParseError("Unexpected Integer");
        }
        else
        {
                value_ = value;
		done_ = true;
        }
}
/*virtual */void Builder::onEnumerated(int value)/* override*/
{
        if (state_ != decoding_enumerated__)
        {
                throw ParseError("Unexpected Enumerated");
        }
        else
        {
                value_ = value;
		done_ = true;
        }
}
/*virtual */void Builder::onBitString(bool final, unsigned int unused_bits, unsigned char *first, unsigned char *last)/* override*/
{
        if (state_ != decoding_bitstring__)
        {
                throw ParseError("Unexpected BitString");
        }
        else
        {
                vector< unsigned char > buffer(value_.empty() ? vector< unsigned char >() : Details::any_cast< vector< unsigned char > >(value_));
                buffer.insert(buffer.end(), first, last);
                if (final)
                {
                        value_ = BitString(buffer.begin(), buffer.end(), unused_bits);
			done_ = true;
                }
                else
                {
                        value_ = buffer;
                }
        }
}
/*virtual */void Builder::onOctetString(bool final, unsigned char *first, unsigned char *last)/* override*/
{
        if (state_ != decoding_octetstring__)
        {
                throw ParseError("Unexpected OctetString");
        }
        else
        {
                vector< unsigned char > buffer(value_.empty() ? vector< unsigned char >() : Details::any_cast< vector< unsigned char > >(value_));
                buffer.insert(buffer.end(), first, last);
                if (final)
                {
                        value_ = OctetString(buffer.begin(), buffer.end());
			done_ = true;
                }
                else
                {
                        value_ = buffer;
                }
        }
}
/*virtual */void Builder::onNull()/* override*/
{
        if (state_ != decoding_null__)
        {
                throw ParseError("Unexpected Null");
        }
        else
        {
		value_ = Null();
		done_ = true;
	}
}
/*virtual */void Builder::onBeginSequence()/* override*/
{
	throw ParseError("Unexpected start of sequence");
}
/*virtual */void Builder::onEndSequence()/* override*/
{
	throw ParseError("Unexpected end of sequence");
}
/*virtual */void Builder::onBeginSet()/* override*/
{
	throw ParseError("Unexpected start of set");
}
/*virtual */void Builder::onEndSet()/* override*/
{
	throw ParseError("Unexpected end of set");
}
/*virtual */void Builder::onBoolean(bool val)/* override*/
{
        if (state_ != decoding_boolean__)
        {
                throw ParseError("Unexpected boolean");
        }
        else
        {
		value_ = Boolean(val);
		done_ = true;
	}
}
/*virtual */void Builder::onReal(double val)/* override*/
{
        if (state_ != decoding_real__)
        {
                throw ParseError("Unexpected boolean");
        }
        else
        {
		value_ = Real(val);
		done_ = true;
	}
}
}}}

