#ifndef vlinder_rubicon_bitstring_hpp
#define vlinder_rubicon_bitstring_hpp

#include <deque>

namespace Vlinder { namespace Rubicon {
class BitString
{
public :
    typedef std::deque< bool >::iterator iterator;
    typedef std::deque< bool >::const_iterator const_iterator;

	BitString() = default;
	virtual ~BitString() = default;
	BitString(BitString const &other) = default;
	BitString& operator=(BitString const &other) = default;
	BitString(BitString &&other) = default;
	BitString& operator=(BitString &&other) = default;
	BitString& swap(BitString &other);

    const_iterator begin() const { return value_.begin(); }
    const_iterator end() const { return value_.end(); }
    iterator begin() { return value_.begin(); }
    iterator end() { return value_.end(); }

    unsigned int size() const { return value_.size(); }
    bool empty() const { return value_.empty(); }

    bool operator[](unsigned int index) const;
    bool& operator[](unsigned int index);

private :
    std::deque< bool > value_;
};
}}

#endif
