#ifndef rubicon_compiler_enumeratedtype_hpp
#define rubicon_compiler_enumeratedtype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "namednumber.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class EnumeratedType : public TypeDescriptor
{
public :
	typedef std::vector< NamedNumber > Values;

	EnumeratedType(SourceLocation const &source_location, Values const &values, bool extensible)
		: TypeDescriptor(source_location)
		, values_(values)
		, extensible_(extensible)
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::universal__, 10 }; }
	virtual std::vector< std::string > getPublicParents() const override { return std::vector< std::string >{ "Vlinder::Rubicon::Integer" }; }
	virtual std::string getTypeName() const override { return "Vlinder::Rubicon::Integer"; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

	virtual void generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const override;
	virtual void generatePublicStaticMembers(std::ostream &os) const override;
	virtual void generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const override;
	virtual void generateSwapparatorImplementation(std::ostream &os) const override;
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCompareImplementation(std::ostream &os) const override;

private :
	Values values_;
	bool extensible_;
};
}}}

#endif



