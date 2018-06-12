#ifndef rubicon_compiler_unknowntype_hpp
#define rubicon_compiler_unknowntype_hpp

#include "typedescriptor.hpp"
#include <iostream>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct UnknownType : TypeDescriptor
{
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



