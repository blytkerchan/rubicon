#ifndef rubicon_compiler_enumeratedtype_hpp
#define rubicon_compiler_enumeratedtype_hpp

#include <vector>
#include "namednumber.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class EnumeratedType : public TypeDescriptor
{
public :
	typedef std::vector< NamedNumber > Values;

	EnumeratedType(Values const &values, bool extensible)
		: values_(values)
		, extensible_(extensible)
	{ /* no-op */ }
private :
	Values values_;
	bool extensible_;
};
}}}

#endif



