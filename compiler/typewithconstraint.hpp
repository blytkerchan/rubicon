#ifndef rubicon_compiler_typewithconstraint_hpp
#define rubicon_compiler_typewithconstraint_hpp

#include "constraint.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TypeWithConstraint : TypeDescriptor
{
	TypeWithConstraint(bool is_set, Constraint const &constraint, std::shared_ptr< TypeDescriptor > const &type)
		: is_set_(is_set)
		, constraint_(constraint)
		, type_(type)
	{ /* no-op */ }

	TypeWithConstraint(bool is_set, Constraint const &constraint, NamedType const &type)
		: is_set_(is_set)
		, constraint_(constraint)
		, named_type_(type)
	{ /* no-op */ }

	bool is_set_;
	Constraint constraint_;
	std::shared_ptr< TypeDescriptor > type_;
	NamedType named_type_;
};
}}}

#endif



