#include "bitstring.hpp"
#include "derencoder.hpp"
#include <algorithm>

using namespace std;

namespace Vlinder { namespace Rubicon {
BitString::BitString(initializer_list< unsigned char > initializer_list, unsigned int trailing_bits)
{
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
}}

