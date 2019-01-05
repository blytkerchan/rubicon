#include "bitstring.hpp"
#include "derencoder.hpp"
#include "exceptions/contract.hpp"
#include <algorithm>

using namespace std;

namespace Vlinder { namespace Rubicon {
BitString::BitString(initializer_list< unsigned char > initializer_list, unsigned int trailing_bits)
{
	pre_condition(trailing_bits < 8);
	pre_condition((initializer_list.begin() != initializer_list.end()) || (trailing_bits == 0));
	for_each(
		  initializer_list.begin()
		, initializer_list.end()
		, [&](unsigned char uc) -> void {
				for (int i(0); i < 8; ++i)
				{
					value_.push_back((uc & 0x80) == 0x80);
					uc <<= 1;
				}
			}
		);
	value_.resize(value_.size() - trailing_bits);
}
int BitString::compare(BitString const &other) const
{
	auto my_curr(value_.begin());
	auto other_curr(other.value_.begin());
	auto const my_end(value_.end());
	auto const other_end(other.value_.end());

	while ((my_curr != my_end) && (other_curr != other_end))
	{
		int cmp(((int)(*other_curr++)) - ((int)(*my_curr++)));
		if (cmp) return cmp;
	}
	if (other_curr != other_end) return 1;
	if (my_curr != my_end) return -1;
	return 0;
}
void BitString::encode(DEREncoder &der_encoder) const
{
	unsigned char char_value(0);
	unsigned char bits_remaining(8);
	vector< unsigned char > bstring_value;
	for (bool bit : value_)
	{
		char_value <<= 1;
		char_value |= (bit ? 1 : 0);
		--bits_remaining;
		if (!bits_remaining)
		{
			bstring_value.push_back(char_value);
			char_value = 0;
			bits_remaining = 8;
		}
		else
		{ /* still remaining */ }
	}
	if (bits_remaining < 8)
	{
		char_value <<= bits_remaining;
		bstring_value.push_back(char_value);
	}
	else
	{ /* no-op */ }

	der_encoder.encodeBitString(bits_remaining % 8, bstring_value.begin(), bstring_value.end());
}

/*static */BitString BitString::build(std::vector< unsigned char > const &octets, unsigned int unused_bits)
{
	pre_condition(unused_bits < 8);
	pre_condition((octets.begin() != octets.end()) || (unused_bits == 0));
	BitString retval;
	for_each(
		  octets.begin()
		, octets.end()
		, [&](unsigned char uc) -> void {
				for (int i(0); i < 8; ++i)
				{
					retval.value_.push_back((uc & 0x80) == 0x80);
					uc <<= 1;
				}
			}
		);
	retval.value_.resize(retval.value_.size() - unused_bits);

	return retval;
}
bool operator==(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) == 0; }
bool operator!=(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) != 0; }
bool operator<(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) < 0; }
bool operator<=(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) <= 0; }
bool operator>(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) > 0; }
bool operator>=(BitString const &lhs, BitString const &rhs) { return lhs.compare(rhs) >= 0; }
}}

