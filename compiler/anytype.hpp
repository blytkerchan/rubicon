#ifndef rubicon_compiler_anytype_hpp
#define rubicon_compiler_anytype_hpp

#include "typedescriptor.hpp"
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Resolver;
class AnyType : public TypeDescriptor
{
public :
	explicit AnyType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }

	AnyType(SourceLocation const &source_location, std::string const &defined_by_identifier)
		: TypeDescriptor(source_location)
        , defined_by_identifier_(defined_by_identifier)
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::internal__, 0 }; }

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

private :
    std::string defined_by_identifier_;

	friend class Resolver;
};
}}}

#endif



