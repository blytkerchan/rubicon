#include "objectidentifier.hpp"
#include "derencoder.hpp"

namespace Vlinder { namespace Rubicon {
ObjectIdentifier::ObjectIdentifier(std::initializer_list< unsigned int > initializer_list)
    : value_(initializer_list)
{ /* no-op */ }

int ObjectIdentifier::compare(ObjectIdentifier const &other) const
{
    auto lhs_curr(begin());
    auto lhs_end(end());
    auto rhs_curr(other.begin());
    auto rhs_end(other.end());

    for ( ; (lhs_curr != lhs_end) && (rhs_curr != rhs_end); ++lhs_curr, ++rhs_curr )
    {
        int diff(*rhs_curr - *lhs_curr);
        if (diff) return diff;
    }
    if ((lhs_curr == lhs_end) && (rhs_curr != rhs_end)) return -1;
    if ((rhs_curr == rhs_end) && (lhs_curr != lhs_end)) return 1;
    return 0;
}

void ObjectIdentifier::encode(DEREncoder &der_encoder) const
{

}

/*static */ObjectIdentifier ObjectIdentifier::build(std::vector< unsigned int > const &arcs)
{
    ObjectIdentifier retval;
    retval.value_ = arcs;
    return retval;
}

bool operator==(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs) { return lhs.compare(rhs) == 0; }
bool operator!=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs) { return lhs.compare(rhs) != 0; }
bool operator<(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs)  { return lhs.compare(rhs) < 0; }
bool operator<=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs) { return lhs.compare(rhs) <= 0; }
bool operator>(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs)  { return lhs.compare(rhs) > 0; }
bool operator>=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs) { return lhs.compare(rhs) >= 0; }

}}

