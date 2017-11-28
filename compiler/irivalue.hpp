#ifndef rubicon_compiler_irivalue_hpp
#define rubicon_compiler_irivalue_hpp

#include "value.hpp"
#include "arcidentifier.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct IRIValue : Value
{
	IRIValue(bool relative = false)
		: relative_(relative)
	{ /* no-op */ }

	void add(ArcIdentifier const &arc_identifier)
	{
		arc_identifiers_.push_back(arc_identifier);
	}

	bool relative_;
	std::vector< ArcIdentifier > arc_identifiers_;
};
}}}

#endif



