#ifndef vlinder_rubicon_details_integer_hpp
#define vlinder_rubicon_details_integer_hpp

#include "../exceptions.hpp"
#include "../exceptions/contract.hpp"

namespace Vlinder { namespace Rubicon { namespace Details {
template < unsigned int max_bits_per_integer__ = 2048 >
struct Integer 
{
	Integer() = default;
	~Integer() = default;
	Integer(Integer const&) = default;
	Integer(Integer&&) = default;
	
	Integer(char value) : signed_(true), size_(0) { set(value); }
	Integer(unsigned char value) : signed_(false), size_(0) { set(value);}
	Integer(short value) : signed_(true), size_(0) { set(value);}
	Integer(unsigned short value) : signed_(false), size_(0) { set(value);}
	Integer(int value) : signed_(true), size_(0) { set(value);}
	Integer(unsigned int value) : signed_(false), size_(0) { set(value);}
	Integer(long value) : signed_(true), size_(0) { set(value);}
	Integer(unsigned long value) : signed_(false), size_(0) { set(value);}
#ifdef HAVE_LONG_LONG
	Integer(long long value) : signed_(true), size_(0) { set(value);}
	Integer(unsigned long long value) : signed_(false), size_(0) { set(value);}
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
	
	unsigned int size() const noexcept { return size_; }
	unsigned char const* begin() const noexcept { return value_; }
	unsigned char const* end() const noexcept { return value_ + size_; }
	unsigned char const* cbegin() const noexcept { return value_; }
	unsigned char const* cend() const noexcept { return value_ + size_; }
	unsigned char* begin() noexcept { return value_; }
	unsigned char* end() noexcept { return value_ + size_; }
	void compact()
	{
		while (size_ && (value_[0] == 0) && ((size_ == 1) || ((value_[1] & 0x80) == 0)))
		{
			std::copy_backward(value_ + 1, value_ + size_, value_);
			--size_;
		}
		if (signed_)
		{
			while ((size_ > 1) && (value_[0] == 0xFF) && ((value_[1] & 0x80) == 0x80))
			{
				std::copy_backward(value_ + 1, value_ + size_, value_);
				--size_;
			}
		}
		else 
		{ /* not a signed integer */ }
	}

	int compare(Integer other) const
	{
		if (negative() && !other.negative()) return -1;
		if (!negative() && other.negative()) return 1;
		Integer temp(*this);
		temp.compact();
		other.compact();
		return temp.compare_(other);
	}

	bool negative() const
	{
		return signed_ && ((value_[0] & 0x80) == 0x80);
	}

	static_assert((max_bits_per_integer__ % 8) == 0, "max bits per integer should be an integer multiple of 8");
	unsigned char value_[max_bits_per_integer__ / 8];
	bool signed_ = false;
	unsigned int size_ = 0;
	
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
};
template < unsigned int max_bits_per_integer__ > bool operator==(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) == 0; }
template < unsigned int max_bits_per_integer__ > bool operator!=(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) != 0; }
template < unsigned int max_bits_per_integer__ > bool operator<(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) < 0; }
template < unsigned int max_bits_per_integer__ > bool operator<=(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) <= 0; }
template < unsigned int max_bits_per_integer__ > bool operator>(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) > 0; }
template < unsigned int max_bits_per_integer__ > bool operator>=(Details::Integer< max_bits_per_integer__ > const &lhs, Details::Integer< max_bits_per_integer__ > const &rhs) { return lhs.compare(rhs) >= 0; }

}}}

#endif

