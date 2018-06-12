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

	virtual void generateEncodeImplementation(std::ostream &os, std::string const &instance_name) const override;
	virtual std::string getTypeName() const override { return "Vlinder::Rubicon::Integer"; }
};
}}}

#endif



