#ifndef rubicon_compiler_taggedtype_hpp
#define rubicon_compiler_taggedtype_hpp

#include "tag.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TaggedType : TypeDescriptor
{
	TaggedType(Tag const &tag, bool explicit_tagging, bool force_implicit_tagging, std::shared_ptr< TypeDescriptor > const &type)
		: tag_(tag)
		, explicit_tagging_(explicit_tagging)
		, force_implicit_tagging_(force_implicit_tagging)
		, type_(type)
	{ /* no-op */ }

	Tag tag_;
	bool explicit_tagging_;
	bool force_implicit_tagging_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



