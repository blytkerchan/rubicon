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
                }
        }
}
