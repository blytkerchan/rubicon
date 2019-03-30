#include "asn1/c.hpp"
#include "asn1/decoder.hpp"
#include "asn1/t1.hpp"
#include <vector>
#include <rubicon/derencoder.hpp>

using namespace std;
using namespace Vlinder::Rubicon;
using namespace BitStringTest4;

vector< unsigned char > encode()
{
	vector< unsigned char > buffer;
	DEREncoder encoder(buffer);
	ASN1::c.encode(encoder);
	return buffer;
}

int testT2()
{
	auto encoded(encode());
	if (encoded.size() != 4) return 1;
	if (encoded[0] != 3) return 1;
	if (encoded[1] != 2) return 1;
	if (encoded[2] != 6) return 1;
	if (encoded[3] != 0x40) return 1;
	auto beg(encoded.begin());
	auto decoded(ASN1::decodeT2(beg, encoded.end()));
	return decoded == ASN1::c ? 0 : 1;
}

int testT1()
{
	using ASN1::T1;
	T1 val(T1::a);
	vector< unsigned char > buffer;
	{
		DEREncoder encoder(buffer);
		val.encode(encoder);
	}
	if (buffer.size() != 3) return 1;
	if (buffer[0] != 0x02) return 1;
	if (buffer[1] != 1) return 1;
	if (buffer[2] != 2) return 1;
	auto beg(buffer.begin());
	auto decoded(ASN1::decodeT1(beg, buffer.end()));

	return decoded == val ? 0 : 1;
}

int main()
{
	return 0
		|| testT2()
		|| testT1()
		;
}

