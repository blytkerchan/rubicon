#ifndef rubicon_compiler_selectiontype_hpp
#define rubicon_compiler_selectiontype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct SelectionType : TypeDescriptor
{
	SelectionType(SourceLocation const &source_location, std::string const &selection, std::shared_ptr< TypeDescriptor > const type)
		: TypeDescriptor(source_location)
		, selection_(selection)
		, type_(type)
	{ /* no-op */ }

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }

	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

	std::string selection_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



