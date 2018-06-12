#ifndef rubicon_compiler_typewithconstraint_hpp
#define rubicon_compiler_typewithconstraint_hpp

#include "typedescriptor.hpp"
#include "constraint.hpp"
#include "namedtype.hpp"
#include <string>
#include <iostream>
#include <memory>

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

	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }

	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

	bool is_set_;
	Constraint constraint_;
	std::shared_ptr< TypeDescriptor > type_;
	NamedType named_type_;
};
}}}

#endif



