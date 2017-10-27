#ifndef rubicon_compiler_constrainedtype_hpp
#define rubicon_compiler_constrainedtype_hpp

#include "constraint.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ConstrainedType : TypeDescriptor
{
	ConstrainedType(std::shared_ptr< TypeDescriptor > const &type, Constraint const &constraint)
		: type_(type)
		, constraint_(constraint)
	{ /* no-op */ }
	
	std::shared_ptr< TypeDescriptor > type_;
	Constraint constraint_;
};
}}}

#endif



