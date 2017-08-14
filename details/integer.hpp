#ifndef 
vlinder_rubicon_details_integer_hpp
#define 
vlinder_rubicon_details_integer_hpp

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
		while ((first != last) && (size_ != sizeof(value_))
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
	
	static_assert((max_bits_per_integer__ % 8) == 0);
	unsigned char value_[max_bits_per_integer__ / 8];
	bool signed_ = false;
	unsigned int size_ = 0;
	
private :
	template < typename I >
	void set(I i)
	{
		static_assert(sizeof(I) <= sizeof(value_));
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
};
}}}

#endif
