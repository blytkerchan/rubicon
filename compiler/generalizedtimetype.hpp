#ifndef rubicon_compiler_generalizedtimetype_hpp
#define rubicon_compiler_generalizedtimetype_hpp

#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct GeneralizedTimeType : TypeDescriptor
{
	explicit GeneralizedTimeType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	virtual Tag getTag() const override { return { Tag::universal__, 24 }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual std::string getTypeName() const override { return "Vlinder::Rubicon::GeneralizedTime"; }
};
}}}

#endif



