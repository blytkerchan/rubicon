#ifndef vlinder_rubicon_bitstring_hpp
#define vlinder_rubicon_bitstring_hpp

#include <initializer_list>
#include <vector>

namespace Vlinder { namespace Rubicon {
class BitString
{
public :
	typedef std::vector< bool >::iterator iterator;
	typedef std::vector< bool >::const_iterator const_iterator;
	typedef std::vector< bool >::size_type size_type;
	typedef std::vector< bool >::reference reference;
	typedef std::vector< bool >::const_reference const_reference;

	BitString() = default;
	BitString(size_type size, bool value = false) : value_(size, value) { /* no-op */ }
	BitString(std::initializer_list< unsigned char > initializer_list, unsigned int trailing_bits);
	virtual ~BitString() = default;
	BitString(BitString const &other) = default;
	BitString& operator=(BitString const &other) = default;
	BitString(BitString &&other) = default;
	BitString& operator=(BitString &&other) = default;
	BitString& swap(BitString &other) { value_.swap(other.value_); return *this; }

	const_iterator begin() const { return value_.begin(); }
	const_iterator end() const { return value_.end(); }
	iterator begin() { return value_.begin(); }
	iterator end() { return value_.end(); }

	void resize(size_type new_size) { value_.resize(new_size); }
	void reserve(size_type new_size) { value_.reserve(new_size); }
	size_type size() const { return value_.size(); }
	size_type capacity() const { return value_.capacity(); }
	bool empty() const { return value_.empty(); }

	const_reference operator[](size_type index) const { return value_[index]; }
	reference operator[](size_type index) { return value_[index]; }

	void setBit(size_type index) { value_[index] = true; }
	void clearBit(size_type index) { value_[index] = false; }
	void toggleBit(size_type index) { value_[index] = !value_[index]; }

private :
	std::vector< bool > value_;
};
}}

#endif
