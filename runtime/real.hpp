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
	
	unsigned int size() const noexcept { return size_; }
	unsigned char const* begin() const noexcept { return value_; }
	unsigned char const* end() const noexcept { return value_ + size_; }
	unsigned char const* cbegin() const noexcept { return value_; }
	unsigned char const* cend() const noexcept { return value_ + size_; }
	unsigned char* begin() noexcept { return value_; }
	unsigned char* end() noexcept { return value_ + size_; }

	void compact();

	int compare(Real other) const;

	bool negative() const;
	
private :
	template < typename I >
	void set(I i)
	{
		static_assert(sizeof(I) <= sizeof(value_), "Real too large");
		size_ = sizeof(I);
		for(
			  unsigned int index(0)
			; index < size_
			; ++index 
			)
		{
			value_[size_ - (index + 1)] = i & 0xFF;
			i >>= 8;
		}
	}

	int compare_(Real const &other) const
	{
		pre_condition(negative() == other.negative()); // otherwise we should never get here
		if (size() < other.size()) return negative() ? 1 : -1;
		if (size() > other.size()) return negative() ? -1 : 1;
		for (unsigned int index(0); index < size_; ++index)
		{
			if (value_[index] != other.value_[index]) return negative() ? (int)value_[index] - (int)other.value_[index] : (int)other.value_[index] - (int)value_[index];
		}

		return 0;
	}

	static_assert((RUBICON_MAX_BITS_PER_INTEGER % 8) == 0, "max bits per integer should be an integer multiple of 8");
	unsigned char value_[RUBICON_MAX_BITS_PER_INTEGER / 8];
	bool signed_ = false;
	unsigned int size_ = 0;
};
inline bool operator==(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) == 0; }
inline bool operator!=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) != 0; }
inline bool operator<(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) < 0; }
inline bool operator<=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) <= 0; }
inline bool operator>(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) > 0; }
inline bool operator>=(Real const &lhs, Real const &rhs) { return lhs.compare(rhs) >= 0; }

}}

#endif

