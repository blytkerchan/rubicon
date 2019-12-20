#ifndef rubicon_compiler_integertype_hpp
#define rubicon_compiler_integertype_hpp

#include <vector>
#include "enumeratedtype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class IntegerType : public EnumeratedType
{
public :
	using EnumeratedType::Values;

	IntegerType(SourceLocation const &source_location, Values const &values)
		: EnumeratedType(source_location, values, false)
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::universal__, 2 }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
};
}}}

#endif



