#ifndef rubicon_compiler_utctimetype_hpp
#define rubicon_compiler_utctimetype_hpp

#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class UTCTimeType : public TypeDescriptor
{
public :
	explicit UTCTimeType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	virtual Tag getTag() const override { return { Tag::universal__, 23 }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
};
}}}

#endif



