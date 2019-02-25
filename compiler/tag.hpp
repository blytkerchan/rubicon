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
	Tag(Class a_class, unsigned int class_number)
		: class_(a_class)
		, class_number_(class_number)
	{ /* no-op */ }
	Tag(Class a_class, DefinedValue const &class_number)
		: class_(a_class)
		, class_number_(class_number)
	{ /* no-op */ }

	bool operator==(Tag const &other) const
	{
		return (class_ == other.class_) && (class_number_ == other.class_number_);
	}

	Class class_;
	boost::variant< unsigned int, DefinedValue > class_number_;
};
}}}

#endif


