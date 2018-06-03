#ifndef rubicon_compiler_constrainedtype_hpp
#define rubicon_compiler_constrainedtype_hpp

#include "typedescriptor.hpp"
#include "constraint.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ConstrainedType : TypeDescriptor
{
	ConstrainedType(std::shared_ptr< TypeDescriptor > const &type, Constraint const &constraint)
		: type_(type)
		, constraint_(constraint)
	{ /* no-op */ }

	virtual void generateEncodeImplementation(std::ostream &os) const override;

	std::shared_ptr< TypeDescriptor > type_;
	Constraint constraint_;
};
}}}

#endif



