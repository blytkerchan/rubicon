#ifndef rubicon_compiler_objectdescriptortype_hpp
#define rubicon_compiler_objectdescriptortype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ObjectDescriptorType : TypeDescriptor
{
	explicit ObjectDescriptorType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



