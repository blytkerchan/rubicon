#ifndef vlinder_rubicon_integer_hpp
#define vlinder_rubicon_integer_hpp

#include "config.hpp"
#include "exceptions.hpp"
#include "exceptions/contract.hpp"

namespace Vlinder { namespace Rubicon {
class Integer 
{
public :
	Integer() = default;
	~Integer() = default;
	Integer(Integer const&) = default;
	Integer(Integer&&) = default;
	
	explicit Integer(char value);
	explicit Integer(unsigned char value);
	explicit Integer(short value);
	explicit Integer(unsigned short value);
	explicit Integer(int value);
	explicit Integer(unsigned int value);
	explicit Integer(long value);
	explicit Integer(unsigned long value);
#ifdef RUBICON_HAVE_LONG_LONG
	explicit Integer(long long value);
	explicit Integer(unsigned long long value);
#endif
	template < typename InputIterator >
	Integer(bool is_signed, InputIterator first, InputIterator last)
		: signed_(is_signed)
		, size_(0)
	{
		while ((first != last) && (size_ != sizeof(value_)))
		{
			value_[size_++] = *first++;
		}
		if ((sizeof(value_) == size_) && (first != last)) throw EncodingError("Integer too large");
	}
	
	Integer& operator=(Integer const&) = default;
	Integer& operator=(Integer&&) = default;

	Integer& swap(Integer &other);
	
	unsigned int size() const noexcept { return size_; }
	unsigned char const* begin() const noexcept { return value_; }
	unsigned char const* end() const noexcept { return value_ + size_; }
	unsigned char const* cbegin() const noexcept { return value_; }
	unsigned char const* cend() const noexcept { return value_ + size_; }
	unsigned char* begin() noexcept { return value_; }
	unsigned char* end() noexcept { return value_ + size_; }

	void compact();

	int compare(Integer other) const;

	bool negative() const;
	
	bool operator!() const;
	explicit operator bool () const;

private :
	template < typename I >
	void set(I i)
	{
		static_assert(sizeof(I) <= sizeof(value_), "Integer too large");
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

	int compare_(Integer const &other) const
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
inline bool operator==(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) == 0; }
inline bool operator!=(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) != 0; }
inline bool operator<(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) < 0; }
inline bool operator<=(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) <= 0; }
inline bool operator>(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) > 0; }
inline bool operator>=(Integer const &lhs, Integer const &rhs) { return lhs.compare(rhs) >= 0; }

}}

#endif

