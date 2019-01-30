#include "integer.hpp"
#include "exceptions.hpp"
#include "exceptions/contract.hpp"
#include <algorithm>

using namespace std;

namespace Vlinder { namespace Rubicon { 
Integer::Integer(char value) : signed_(true), size_(0) { set(value); }
Integer::Integer(unsigned char value) : signed_(false), size_(0) { set(value);}
Integer::Integer(short value) : signed_(true), size_(0) { set(value);}
Integer::Integer(unsigned short value) : signed_(false), size_(0) { set(value);}
Integer::Integer(int value) : signed_(true), size_(0) { set(value);}
Integer::Integer(unsigned int value) : signed_(false), size_(0) { set(value);}
Integer::Integer(long value) : signed_(true), size_(0) { set(value);}
Integer::Integer(unsigned long value) : signed_(false), size_(0) { set(value);}
#ifdef RUBICON_HAVE_LONG_LONG
Integer::Integer(long long value) : signed_(true), size_(0) { set(value);}
Integer::Integer(unsigned long long value) : signed_(false), size_(0) { set(value);}
#endif

Integer& Integer::swap(Integer &other)
{
	swap_ranges(std::begin(value_), std::end(value_), std::begin(other.value_));
	std::swap(signed_, other.signed_);
	std::swap(size_, other.size_);

	return *this;
}


void Integer::compact()
{
	while (size_ && (value_[0] == 0) && ((size_ == 1) || ((value_[1] & 0x80) == 0)))
	{
		copy_backward(value_ + 1, value_ + size_, value_ + (size_ - 1));
		--size_;
	}
	if (signed_)
	{
		while ((size_ > 1) && (value_[0] == 0xFF) && ((value_[1] & 0x80) == 0x80))
		{
			copy_backward(value_ + 1, value_ + size_, value_ + (size_ - 1));
			--size_;
		}
	}
	else 
	{ /* not a signed integer */ }
}

int Integer::compare(Integer other) const
{
	if (negative() && !other.negative()) return -1;
	if (!negative() && other.negative()) return 1;
	Integer temp(*this);
	temp.compact();
	other.compact();
	return temp.compare_(other);
}

bool Integer::negative() const
{
	return signed_ && ((value_[0] & 0x80) == 0x80);
}

bool Integer::operator!() const
{
	bool retval(true);
	for_each(value_, value_ + size_, [&retval](auto v){ if (v) retval = false; });
	return retval;
}
/*explicit */Integer::operator bool () const
{
	return !!*this;
}

}}

