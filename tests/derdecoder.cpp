#include "catch.hpp"
#include "runtime/factory.hpp"

using namespace std;
using namespace Vlinder::Rubicon;

SCENARIO( "decoding an incoming octet string", "[derdecoder]" ) {
        GIVEN( "an octet string { 01, 01, 01 }" ) {
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
}
