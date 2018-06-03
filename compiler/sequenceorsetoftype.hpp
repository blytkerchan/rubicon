#ifndef rubicon_compiler_sequenceorsetoftype_hpp
#define rubicon_compiler_sequenceorsetoftype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "namedtype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct SequenceOrSetOfType : TypeDescriptor
{
	SequenceOrSetOfType(bool is_set, std::shared_ptr< TypeDescriptor > const &type)
		: is_set_(is_set)
		, type_(type)
	{ /* no-op */ }
	SequenceOrSetOfType(bool is_set, std::shared_ptr< TypeDescriptor > &&type)
		: is_set_(is_set)
		, type_(std::move(type))
	{ /* no-op */ }
	SequenceOrSetOfType(bool is_set, NamedType const &type)
		: is_set_(is_set)
		, named_type_(type)
	{ /* no-op */ }
	SequenceOrSetOfType(bool is_set, NamedType &&type)
		: is_set_(is_set)
		, named_type_(std::move(type))
	{ /* no-op */ }

	virtual void generateEncodeImplementation(std::ostream &os) const override;

	bool is_set_ = false;
	std::shared_ptr< TypeDescriptor > type_;
	NamedType named_type_;
};
}}}

#endif



