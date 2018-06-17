#ifndef rubicon_compiler_constrainedtype_hpp
#define rubicon_compiler_constrainedtype_hpp

#include "typedescriptor.hpp"
#include "constraint.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ConstrainedType : TypeDescriptor
{
	ConstrainedType(SourceLocation const &source_location, std::shared_ptr< TypeDescriptor > const &type, Constraint const &constraint)
		: TypeDescriptor(source_location)
		, type_(type)
		, constraint_(constraint)
	{ /* no-op */ }

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;

	std::shared_ptr< TypeDescriptor > type_;
	Constraint constraint_;
};
}}}

#endif



