#include "tag.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
Tag::Tag(Class a_class, unsigned int class_number)
	: class_(a_class)
	, class_number_(class_number)
{ /* no-op */ }
Tag::Tag(Class a_class, DefinedValue const &class_number)
	: class_(a_class)
	, class_number_(class_number)
{ /* no-op */ }

int Tag::compare(Tag const &other) const
{
	if (class_ < other.class_)
	{
		return -1;
	}
	else if (other.class_ < class_)
	{
		return 1;
	}
	else
	{
		assert(class_ == other.class_);
		return (boost::get< unsigned int >(class_number_) < boost::get< unsigned int >(other.class_number_))
			? -1 
			: (boost::get< unsigned int >(other.class_number_) < boost::get< unsigned int >(class_number_))
			? 1 
			: 0
			;
	}
}
bool operator==(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) == 0; }
bool operator!=(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) != 0; }
bool operator<(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) < 0; }
bool operator<=(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) <= 0; }
bool operator>(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) > 0; }
bool operator>=(Tag const &lhs, Tag const &rhs) { return lhs.compare(rhs) >= 0; }
}}}

