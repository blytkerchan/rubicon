#ifndef rubicon_compiler_objectdescriptortype_hpp
#define rubicon_compiler_objectdescriptortype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ObjectDescriptorType : public TypeDescriptor
{
public :
	explicit ObjectDescriptorType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	virtual Tag getTag() const override { return { Tag::universal__, 7 }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



