#include "catch.hpp"
#include "runtime/derencoder.hpp"

using namespace std;
using namespace Vlinder::Rubicon;

TEST_CASE( "Encode a boolean (true)", "[derencoder]" ) {
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		encoder.encodeBoolean(true);
	}
	REQUIRE(!buffer.empty());
	REQUIRE(buffer.size() == 3);
	REQUIRE(buffer[0] == 0x01);
	REQUIRE(buffer[1] == 0x01);
	REQUIRE(buffer[2] != 0x00);
}

TEST_CASE( "Encode a boolean (false)", "[derencoder]" ) {
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		encoder.encodeBoolean(false);
	}
	REQUIRE(!buffer.empty());
	REQUIRE(buffer.size() == 3);
	REQUIRE(buffer[0] == 0x01);
	REQUIRE(buffer[1] == 0x01);
	REQUIRE(buffer[2] == 0x00);
}

