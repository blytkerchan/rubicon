#include "boolean.hpp"
#include "derencoder.hpp"
#include "exceptions/contract.hpp"
#include <algorithm>

using namespace std;

namespace Vlinder { namespace Rubicon {
Boolean::Boolean(bool value/* = false*/)
	: value_(value)
{ /* no-op */ }
Boolean& Boolean::swap(Boolean &other)
{
	std::swap(value_, other.value_);
	return *this;
}
int Boolean::compare(Boolean const &other) const
{
	return (other.value_ ? 1 : 0) - (value_ ? 1 : 0);
}
void Boolean::encode(DEREncoder &der_encoder) const
{
	der_encoder.encodeBoolean(value_);
}

bool operator==(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) == 0; }
bool operator!=(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) != 0; }
bool operator<(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) < 0; }
bool operator<=(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) <= 0; }
bool operator>(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) > 0; }
bool operator>=(Boolean const &lhs, Boolean const &rhs) { return lhs.compare(rhs) >= 0; }
}}

