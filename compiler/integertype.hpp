#ifndef rubicon_compiler_integertype_hpp
#define rubicon_compiler_integertype_hpp

#include <vector>
#include "enumeratedtype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct IntegerType : EnumeratedType
{
	using EnumeratedType::Values;

	IntegerType(Values const &values)
		: EnumeratedType(values, false)
	{ /* no-op */ }
};
}}}

#endif



