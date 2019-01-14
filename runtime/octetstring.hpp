#ifndef vlinder_rubicon_octetstring_hpp
#define vlinder_rubicon_octetstring_hpp

#include <initializer_list>
#include <vector>

namespace Vlinder { namespace Rubicon {
class DEREncoder;
class OctetString
{
public :
	typedef std::vector< unsigned char >::iterator iterator;
	typedef std::vector< unsigned char >::const_iterator const_iterator;
	typedef std::vector< unsigned char >::size_type size_type;
	typedef std::vector< unsigned char >::reference reference;
	typedef std::vector< unsigned char >::const_reference const_reference;

	OctetString() = default;
	OctetString(size_type size, bool value = false) : value_(size, value) { /* no-op */ }
	OctetString(std::initializer_list< unsigned char > initializer_list);
	template < typename I >
	OctetString(I first, I last)
		: value_(first, last)
	{ /* no-op */ }
	virtual ~OctetString() = default;
	OctetString(OctetString const &other) = default;
	OctetString& operator=(OctetString const &other) = default;
	OctetString(OctetString &&other) = default;
	OctetString& operator=(OctetString &&other) = default;
	OctetString& swap(OctetString &other) { value_.swap(other.value_); return *this; }

	int compare(OctetString const &other) const;

	void encode(DEREncoder &der_encoder) const;

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

	static OctetString build(std::vector< unsigned char > const &octets);

private :
	std::vector < unsigned char > value_;
};
bool operator==(OctetString const &lhs, OctetString const &rhs);
bool operator!=(OctetString const &lhs, OctetString const &rhs);
bool operator<(OctetString const &lhs, OctetString const &rhs);
bool operator<=(OctetString const &lhs, OctetString const &rhs);
bool operator>(OctetString const &lhs, OctetString const &rhs);
bool operator>=(OctetString const &lhs, OctetString const &rhs);

}}

#endif
