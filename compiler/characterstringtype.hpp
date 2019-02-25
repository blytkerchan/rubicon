#ifndef rubicon_compiler_characterstringtype_hpp
#define rubicon_compiler_characterstringtype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>
#include "tag.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class CharacterStringType : public TypeDescriptor
{
public :
	CharacterStringType(SourceLocation const &source_location, Tag const &tag)
		: TypeDescriptor(source_location)
		, tag_(tag)
	{ /* no-op */ }

	~CharacterStringType() = default;

	bool restricted() const { return (tag_.class_ != Tag::universal__) || (boost::get< unsigned int >(tag_.class_number_) != 27); }

	virtual Tag getTag() const override { return tag_; }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual std::string getTypeName() const override { return "CharacterString"; };
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

private :
	Tag tag_;
};
}}}

#endif



