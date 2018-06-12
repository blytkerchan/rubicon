#ifndef rubicon_compiler_objectdescriptortype_hpp
#define rubicon_compiler_objectdescriptortype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ObjectDescriptorType : TypeDescriptor
{
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



