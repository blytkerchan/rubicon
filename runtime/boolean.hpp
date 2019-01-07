#ifndef vlinder_rubicon_boolean_hpp
#define vlinder_rubicon_boolean_hpp

namespace Vlinder { namespace Rubicon {
class DEREncoder;
class Boolean
{
public :
	Boolean(bool value = false);
	virtual ~Boolean() = default;
	Boolean(Boolean const &other) = default;
	Boolean& operator=(Boolean const &other) = default;
	Boolean(Boolean &&other) = default;
	Boolean& operator=(Boolean &&other) = default;
	Boolean& operator=(bool value) { value_ = value; }
	Boolean& swap(Boolean &other);

	explicit operator bool () const { return value_; }
	bool operator!() const { return !value_; }

	int compare(Boolean const &other) const;

	void encode(DEREncoder &der_encoder) const;

	void set() { value_ = true; }
	void clear() { value_ = false; }
	void toggle() { value_ = !value_; }

private :
	bool value_;
};
bool operator==(Boolean const &lhs, Boolean const &rhs);
bool operator!=(Boolean const &lhs, Boolean const &rhs);
bool operator<(Boolean const &lhs, Boolean const &rhs);
bool operator<=(Boolean const &lhs, Boolean const &rhs);
bool operator>(Boolean const &lhs, Boolean const &rhs);
bool operator>=(Boolean const &lhs, Boolean const &rhs);
}}

#endif
