#ifndef vlinder_rubicon_compiler_objectidentifiervalue_hpp
#define vlinder_rubicon_compiler_objectidentifiervalue_hpp

#include "value.hpp"
#include "objectidentifier.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ObjectIdentifierValue : public Value
{
public :
	ObjectIdentifierValue(SourceLocation const &source_location, ObjectIdentifier const &oid)
		: Value(source_location)
		, oid_(oid)
	{ /* no-op */ }

	std::string getTypeName() const override { return "ObjectIdentifier"; }

private :
	ObjectIdentifier oid_;
};
}}}

#endif


