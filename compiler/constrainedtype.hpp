#ifndef rubicon_compiler_constrainedtype_hpp
#define rubicon_compiler_constrainedtype_hpp

#include "typedescriptor.hpp"
#include "constraint.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ConstrainedType : public TypeDescriptor
{
public :
	ConstrainedType(SourceLocation const &source_location, std::shared_ptr< TypeDescriptor > const &type, Constraint const &constraint)
		: TypeDescriptor(source_location)
		, type_(type)
		, constraint_(constraint)
	{ /* no-op */ }

	virtual Tag getTag() const override { return type_->getTag(); }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;

	std::shared_ptr< TypeDescriptor > getType() const { return type_; }
	void setType(std::shared_ptr< TypeDescriptor > const &type) { type_ = type; }

    virtual void visit(DefinedTypeResolutionVisitor &visitor) override;

	virtual std::shared_ptr< StateMachine > getStateMachine() const override { return type_->getStateMachine(); }


private :
	std::shared_ptr< TypeDescriptor > type_;
	Constraint constraint_;
};
}}}

#endif



