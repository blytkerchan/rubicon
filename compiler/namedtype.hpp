#ifndef rubicon_compiler_namedtype_hpp
#define rubicon_compiler_namedtype_hpp

#include "typedescriptor.hpp"
#include <string>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class NamedType : public TypeDescriptor
{
public :
	explicit NamedType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	NamedType(SourceLocation const &source_location, std::string const &name, std::shared_ptr< TypeDescriptor > const &type)
		: TypeDescriptor(source_location)
		, name_(name)
		, type_(type)
	{ /* no-op */ }

	void setTag(Tag const &tag) { type_->setTag(tag); }
	virtual Tag getTag() const override { return type_->getTag(); }
	bool tagged() const override { return type_->tagged(); }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }
	std::string getName() const { return name_; }
	std::shared_ptr< TypeDescriptor > getType() const { return type_; }
	void setType(std::shared_ptr< TypeDescriptor > const &type) { type_ = type; }

	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
    
    virtual void visit(DefinedTypeResolutionVisitor &visitor) override;

private :
	std::string name_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



