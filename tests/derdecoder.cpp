#include "catch.hpp"
#include "runtime/factory.hpp"

using namespace std;
using namespace Vlinder::Rubicon;

SCENARIO( "decoding an incoming octet string", "[derdecoder]" ) {
        GIVEN( "an octet string { 01, 01, 01 } (which encodes a boolean)" ) {
                vector< unsigned char > octets{ 0x01, 0x01, 0x01 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        auto try_boolean(decodeBoolean(iter, octets.end()));
			THEN( "it's a boolean" ) {
				REQUIRE(try_boolean);
			}
                }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_bit_string(decodeBitString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 02, 01, 00 } (which encodes a integer)" ) {
                vector< unsigned char > octets{ 0x02, 0x01, 0x00 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        auto try_integer(decodeInteger(iter, octets.end()));
                        THEN( "it's an integer" ) {
                                REQUIRE(!try_integer);
                        }
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_bit_string(decodeBitString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 02, 01, 01 } (which encodes a integer)" ) {
                vector< unsigned char > octets{ 0x02, 0x01, 0x01 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        auto try_integer(decodeInteger(iter, octets.end()));
                        THEN( "it's an integer" ) {
                                REQUIRE(try_integer);
                        }
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_bit_string(decodeBitString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 0A, 01, 00 } (which encodes an enumerated value)" ) {
                vector< unsigned char > octets{ 0x0A, 0x01, 0x00 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        THEN( "it's an enumerated value" ) {
                                REQUIRE(!try_enumerated);
                        }
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_bit_string(decodeBitString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 0A, 01, 01 } (which encodes an enumerated value)" ) {
                vector< unsigned char > octets{ 0x0A, 0x01, 0x01 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        THEN( "it's an enumerated value" ) {
                                REQUIRE(try_enumerated);
                        }
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_bit_string(decodeBitString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 03, 01, 00 } (which encodes an empty bit string)" ) {
                vector< unsigned char > octets{ 0x03, 0x01, 0x00 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        auto try_bit_string(decodeBitString(iter, octets.end()));
                        THEN( "it's a bit string" ) {
                                REQUIRE(try_bit_string.empty());
                        }
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 03, 02, 07, 80 } (which encodes a one-bit bit string)" ) {
                vector< unsigned char > octets{ 0x03, 0x02, 0x07, 0x80 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        auto try_bit_string(decodeBitString(iter, octets.end()));
                        THEN( "it's a bit string" ) {
                                REQUIRE(!try_bit_string.empty());
                                REQUIRE(try_bit_string.size() == 1);
                        }
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
        GIVEN( "an octet string { 03, 07, 04, 0A, 3B, 5F, 29, 1C, D0 } (which encodes a 44-bit bit string)" ) {
                vector< unsigned char > octets{ 0x03, 0x07, 0x04, 0x0A, 0x3B, 0x5F, 0x29, 0x1C, 0xD0 };
                WHEN( "we try to decode it as a boolean" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_boolean(decodeBoolean(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
	        }
                WHEN( "we try to decode it as an integer" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_integer(decodeInteger(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as an enumerated value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_enumerated(decodeEnumerated(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a bit string" ) {
                        auto iter(octets.begin());
                        auto try_bit_string(decodeBitString(iter, octets.end()));
                        THEN( "it's a bit string" ) {
                                REQUIRE(!try_bit_string.empty());
                                REQUIRE(try_bit_string.size() == 44);
                        }
                }
                WHEN( "we try to decode it as an octet string" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_octet_string(decodeOctetString(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a null value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_null(decodeNull(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
                WHEN( "we try to decode it as a real value" ) {
                        auto iter(octets.begin());
                        bool caught(false);
                        try
                        {
                                auto try_real(decodeReal(iter, octets.end()));
                        }
                        catch (ParseError const &e)
                        {
                                caught = true;
                        }
			THEN( "it fails" ) {
                                REQUIRE(caught);
			}
                }
        }
}
