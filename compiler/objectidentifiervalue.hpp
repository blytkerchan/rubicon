#ifndef vlinder_rubicon_compiler_objectidentifiervalue_hpp
#define vlinder_rubicon_compiler_objectidentifiervalue_hpp

#include "value.hpp"
#include "objectidentifier.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
	struct ObjectIdentifierValue : Value
	{
		ObjectIdentifierValue(ObjectIdentifier const &oid)
			: oid_(oid)
		{ /* no-op */ }

		ObjectIdentifier oid_;
	};
}}}

#endif


