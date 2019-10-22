#ifndef rubicon_compiler_externaltypereference_hpp
#define rubicon_compiler_externaltypereference_hpp

#include "typedescriptor.hpp"
#include <string>
#include <iostream>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ExternalTypeReference : public TypeDescriptor
{
public :
	ExternalTypeReference(SourceLocation const &source_location, std::string const &module_name, std::string const &symbol_name)
		: TypeDescriptor(source_location)
		, module_name_(module_name)
		, symbol_name_(symbol_name)
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::universal__, 8 }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual bool hasTypeName() const override { return true; }
	virtual std::string getTypeName() const override { return module_name_ + "." + symbol_name_; }

	virtual void generateEncodeImplementation(std::ostream &os) const override;

private :
	std::string module_name_;
	std::string symbol_name_;
};
}}}

#endif



