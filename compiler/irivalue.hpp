#ifndef rubicon_compiler_irivalue_hpp
#define rubicon_compiler_irivalue_hpp

#include "value.hpp"
#include "arcidentifier.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct IRIValue : Value
{
	IRIValue()
	{ /* no-op */ }

	void add(ArcIdentifier const &arc_identifier)
	{
		arc_identifiers_.push_back(arc_identifier);
	}

	std::vector< ArcIdentifier > arc_identifiers_;
};
}}}

#endif



