#include "catch.hpp"
#include "../runtime/bitstring.hpp"

using namespace Vlinder::Rubicon;

TEST_CASE("Default-constructed BitStrings are empry", "[bitstring]")
{
    BitString bit_string;

    REQUIRE(bit_string.empty());
    REQUIRE(bit_string.size() == 0);
    REQUIRE(bit_string.begin() == bit_string.end());
}