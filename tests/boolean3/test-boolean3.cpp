#include "asn1/employed.hpp"
#include <vector>
#include <rubicon/derencoder.hpp>

using namespace std;
using namespace Vlinder::Rubicon;
using namespace BooleanTest3;

int testTestValue()
{
	ASN1::Employed test_value(false);
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		test_value.encode(encoder);
	}
	if (buffer.size() != 3) return 1;
	if (buffer[0] != 0x01) return 1;
	if (buffer[1] != 1) return 1;
	if (buffer[2] != 0) return 1;
	auto beg(buffer.begin());
	//auto decoded(ASN1::decodeT1(beg, buffer.end()));

	return 0;//decoded == val ? 0 : 1;
}

int main()
{
	return 0
		|| testTestValue()
		;
}

