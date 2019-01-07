#include "asn1/test-value.hpp"
#include <vector>
#include <rubicon/derencoder.hpp>

using namespace std;
using namespace Vlinder::Rubicon;
using namespace BooleanTest1;

int testTestValue()
{
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		ASN1::test_value.encode(encoder);
	}
	if (buffer.size() != 3) return 1;
	if (buffer[0] != 0x01) return 1;
	if (buffer[1] != 1) return 1;
	if (buffer[2] == 0) return 1;
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

