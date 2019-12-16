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

TEST_CASE( "Encode a BitString", "[derencoder]" ) {
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		unsigned char bits[] = {64, 33};
		encoder.encodeBitString(0, begin(bits), end(bits));
	}
	REQUIRE(!buffer.empty());
	REQUIRE(buffer.size() == 5);
	REQUIRE(buffer[0] == 0x03);
	REQUIRE(buffer[1] == 0x03);
	REQUIRE(buffer[2] == 0x00);
	REQUIRE(buffer[3] == 0x40);
	REQUIRE(buffer[4] == 0x21);
}

TEST_CASE( "Encode another BitString", "[derencoder]" ) {
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		unsigned char bits[] = {0x0A, 0x3B, 0x5F, 0x29, 0x1C, 0xD0};
		encoder.encodeBitString(4, begin(bits), end(bits));
	}
	REQUIRE(!buffer.empty());
	REQUIRE(buffer.size() == 9);
	REQUIRE(buffer[0] == 0x03);
	REQUIRE(buffer[1] == 0x07);
	REQUIRE(buffer[2] == 0x04);
	REQUIRE(buffer[3] == 0x0A);
	REQUIRE(buffer[4] == 0x3B);
	REQUIRE(buffer[5] == 0x5F);
	REQUIRE(buffer[6] == 0x29);
	REQUIRE(buffer[7] == 0x1C);
	REQUIRE(buffer[8] == 0xD0);
}
