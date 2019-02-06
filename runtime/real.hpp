#ifndef vlinder_rubicon_real_hpp
#define vlinder_rubicon_real_hpp

#include "config.hpp"
#include "exceptions.hpp"
#include "exceptions/contract.hpp"

namespace Vlinder { namespace Rubicon {
class Real
{
public :
	Real() = default;
	~Real() = default;
	Real(Real const&) = default;
	Real(Real&&) = default;
	
	Real(double value);
	
	Real& operator=(Real const&) = default;
	Real& operator=(Real&&) = default;

	Real& swap(Real &other);
	
	int compare(Real const &other) const;
	
	explicit operator double () const { return value_; }
private :
	double value_;
};
inline bool operator==(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) == 0; }
inline bool operator!=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) != 0; }
inline bool operator<(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) < 0; }
inline bool operator<=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) <= 0; }
inline bool operator>(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) > 0; }
inline bool operator>=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) >= 0; }

}}

#endif

