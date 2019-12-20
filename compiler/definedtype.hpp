#ifndef rubicon_compiler_definedtype_hpp
#define rubicon_compiler_definedtype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class DefinedType : public TypeDescriptor
{
public :
	DefinedType(SourceLocation const &source_location, std::string const &type_name)
		: TypeDescriptor(source_location)
		, type_name_(type_name)
	{ /* no-op */ }
	
	virtual Tag getTag() const override;
	virtual void setTag(Tag const &tag) override;
	virtual bool tagged() const override;
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual bool hasTypeName() const override { return true; }
	virtual std::string getTypeName() const override { return type_name_; }

    void setReferencedType(std::shared_ptr< TypeDescriptor > const &referenced_type) { referenced_type_ = referenced_type; }
    std::shared_ptr< TypeDescriptor > getReferencedType() const { return referenced_type_; }

    virtual void visit(DefinedTypeResolutionVisitor &visitor) override;

	virtual std::shared_ptr< StateMachine > getStateMachine() const override { return referenced_type_->getStateMachine(); }

private :
	std::unique_ptr< Tag > tag_;
	std::string type_name_;
    std::shared_ptr< TypeDescriptor > referenced_type_;
};
}}}

#endif



