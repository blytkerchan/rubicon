#include "bitstring.hpp"
#include "derencoder.hpp"

namespace Vlinder { namespace Rubicon {
BitString& BitString::swap(BitString &other)
{
    value_.swap(other.value_);
    return *this;
}

bool BitString::operator[](unsigned int index) const
{
    return value_[index];
}
bool& BitString::operator[](unsigned int index)
{
    return value_[index];
}
}}

