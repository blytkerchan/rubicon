#ifndef rubicon_compiler_generalizedtimetype_hpp
#define rubicon_compiler_generalizedtimetype_hpp

#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct GeneralizedTimeType : TypeDescriptor
{
	virtual void generateEncodeImplementation(std::ostream &os) const override;
};
}}}

#endif



