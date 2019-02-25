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
	SequenceOrSetOfType(SourceLocation const &source_location, bool is_set, std::shared_ptr< TypeDescriptor > const &type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, type_(type)
		, named_type_(source_location)
	{ /* no-op */ }
	SequenceOrSetOfType(SourceLocation const &source_location, bool is_set, std::shared_ptr< TypeDescriptor > &&type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, type_(std::move(type))
		, named_type_(source_location)
	{ /* no-op */ }
	SequenceOrSetOfType(SourceLocation const &source_location, bool is_set, NamedType const &type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, named_type_(type)
	{ /* no-op */ }
	SequenceOrSetOfType(SourceLocation const &source_location, bool is_set, NamedType &&type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, named_type_(std::move(type))
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::universal__, is_set_ ? 17U : 16U }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

	bool is_set_ = false;
	std::shared_ptr< TypeDescriptor > type_;
	NamedType named_type_;
};
}}}

#endif



