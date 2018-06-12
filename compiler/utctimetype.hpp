#ifndef rubicon_compiler_utctimetype_hpp
#define rubicon_compiler_utctimetype_hpp

#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct UTCTimeType : TypeDescriptor
{
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



