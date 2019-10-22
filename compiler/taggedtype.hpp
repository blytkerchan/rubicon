#ifndef rubicon_compiler_taggedtype_hpp
#define rubicon_compiler_taggedtype_hpp

#include "tag.hpp"
#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TaggedType : public TypeDescriptor
{
public :
	TaggedType(SourceLocation const &source_location, Tag const &tag, bool explicit_tagging, bool force_implicit_tagging, std::shared_ptr< TypeDescriptor > const &type)
		: TypeDescriptor(source_location)
		, tag_(tag)
		, explicit_tagging_(explicit_tagging)
		, force_implicit_tagging_(force_implicit_tagging)
		, type_(type)
	{ /* no-op */ }

	virtual Tag getTag() const override { return tag_; }
	virtual void setTag(Tag const &tag) override { tag_ = tag; };
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual std::string getTypeName() const override { return type_->getTypeName(); }
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

private :
	Tag tag_;
	bool explicit_tagging_;
	bool force_implicit_tagging_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



