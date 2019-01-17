#include "real.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

namespace Vlinder { namespace Rubicon {
Real::Real(double value)
	: value_(value)
{}
	
Real& Real::swap(Real &other)
{
	std::swap(value_, other.value_);
	return *this;
}
	
int Real::compare(Real const &other) const
{
	if (&other == this)
	{
		return isnan(value_) ? -1 : 0;
	}
	else if (isnan(value_) || isnan(other.value_))
	{
		throw std::logic_error("NaN is unordered");
	}
	else if (isinf(value_) && (value_ < 0)) // lhs is negative infinity
	{
		return (isinf(other.value_) && (other.value_ < 0)) ? 0 : -1;
	}
	else if (isinf(value_)) // lhs is positive infinity
	{
		return (isinf(other.value_) && (other.value_ > 0)) ? 0 : 1;
	}
	else
	{
		double cmp(other.value_ - value_);
		return cmp < 0 ? -1 : cmp > 0 ? 1 : 0;
	}
}
}}



