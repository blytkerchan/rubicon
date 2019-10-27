#ifndef vlinder_rubicon_objectidentifier_hpp
#define vlinder_rubicon_objectidentifier_hpp

#include "exceptions/contract.hpp"
#include <initializer_list>
#include <vector>

namespace Vlinder { namespace Rubicon {
class DEREncoder;
/* 3.8.54 object identifier type: A simple type whose values are a sequence of primary integer values that identify a 
 *                                series of arcs leading from the root to a node of the International Object Identifier
 *                                tree, as specified by the Rec. ITU-T X.660 | ISO/IEC 9834 series.
 * NOTE 1 – The rules of Rec. ITU-T X.660 | ISO/IEC 9834-1 permit a wide range of authorities to independently associate 
 *          a primary integer value with an arc of the tree.
 * NOTE 2 – In the value notation for the object identifier type (and in XML encodings of that type) it is possible to 
 *          include secondary identifiers for arcs.
 */
class ObjectIdentifier
{
public :
	typedef std::vector< unsigned int >::iterator iterator;
	typedef std::vector< unsigned int >::const_iterator const_iterator;
	typedef std::vector< unsigned int >::size_type size_type;
	typedef std::vector< unsigned int >::reference reference;
	typedef std::vector< unsigned int >::const_reference const_reference;

	ObjectIdentifier() = default;
	ObjectIdentifier(std::initializer_list< unsigned int > initializer_list);
	template < typename I >
	ObjectIdentifier(I first, I last)
        : value_(first, last)
    { /* no-op */ }
	virtual ~ObjectIdentifier() = default;
	ObjectIdentifier(ObjectIdentifier const &other) = default;
	ObjectIdentifier& operator=(ObjectIdentifier const &other) = default;
	ObjectIdentifier(ObjectIdentifier &&other) = default;
	ObjectIdentifier& operator=(ObjectIdentifier &&other) = default;
	ObjectIdentifier& swap(ObjectIdentifier &other) { value_.swap(other.value_); return *this; }

	int compare(ObjectIdentifier const &other) const;

	void encode(DEREncoder &der_encoder) const;

	const_iterator begin() const { return value_.begin(); }
	const_iterator end() const { return value_.end(); }
	iterator begin() { return value_.begin(); }
	iterator end() { return value_.end(); }

	size_type size() const { return value_.size(); }
	bool empty() const { return value_.empty(); }

	const_reference operator[](size_type index) const { return value_[index]; }
	reference operator[](size_type index) { return value_[index]; }

	static ObjectIdentifier build(std::vector< unsigned int > const &arcs);

private :
	std::vector< unsigned int > value_;
};
bool operator==(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);
bool operator!=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);
bool operator<(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);
bool operator<=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);
bool operator>(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);
bool operator>=(ObjectIdentifier const &lhs, ObjectIdentifier const &rhs);

}}

#endif
