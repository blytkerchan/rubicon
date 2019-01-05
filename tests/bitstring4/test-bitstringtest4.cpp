#include "asn1/c.hpp"
#include "asn1/factory.hpp"
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

int main()
{
	auto encoded(encode());

	auto beg(encoded.begin());
	auto decoded(ASN1::decodeT2(beg, encoded.end()));
	return decoded == ASN1::c ? 0 : 1;
}

