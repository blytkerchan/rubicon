#ifndef rubicon_compiler_typewithconstraint_hpp
#define rubicon_compiler_typewithconstraint_hpp

#include "typedescriptor.hpp"
#include "constraint.hpp"
#include "namedtype.hpp"
#include <string>
#include <iostream>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeWithConstraint : public TypeDescriptor
{
public :
	TypeWithConstraint(SourceLocation const &source_location, bool is_set, Constraint const &constraint, std::shared_ptr< TypeDescriptor > const &type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, constraint_(constraint)
		, type_(type)
		, named_type_(source_location)
	{ /* no-op */ }

	TypeWithConstraint(SourceLocation const &source_location, bool is_set, Constraint const &constraint, NamedType const &type)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, constraint_(constraint)
		, named_type_(type)
	{ /* no-op */ }

	virtual Tag getTag() const override { return type_->getTag(); }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }

	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

private :
	bool is_set_;
	Constraint constraint_;
	std::shared_ptr< TypeDescriptor > type_;
	NamedType named_type_;
};
}}}

#endif



