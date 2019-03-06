#ifndef vlinder_rubicon_compiler_tag_hpp
#define vlinder_rubicon_compiler_tag_hpp

#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "definedvalue.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct Tag
{
	enum Class {
		  universal__
		, application__
		, private__
		, context_specific__
		};

	Tag(Class a_class, unsigned int class_number);
	Tag(Class a_class, DefinedValue const &class_number);

	int compare(Tag const &other) const;

	Class class_;
	boost::variant< unsigned int, DefinedValue > class_number_;
};
bool operator==(Tag const &lhs, Tag const &rhs);
bool operator!=(Tag const &lhs, Tag const &rhs);
bool operator<(Tag const &lhs, Tag const &rhs);
bool operator<=(Tag const &lhs, Tag const &rhs);
bool operator>(Tag const &lhs, Tag const &rhs);
bool operator>=(Tag const &lhs, Tag const &rhs);
}}}

#endif


