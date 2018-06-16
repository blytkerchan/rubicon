#ifndef rubicon_compiler_irivalue_hpp
#define rubicon_compiler_irivalue_hpp

#include "value.hpp"
#include "arcidentifier.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class IRIValue : public Value
{
public :
	IRIValue(bool relative = false)
		: relative_(relative)
	{ /* no-op */ }

	void add(ArcIdentifier const &arc_identifier)
	{
		arc_identifiers_.push_back(arc_identifier);
	}

	std::string getTypeName() const override { return "IRI"; }

private :
	bool relative_;
	std::vector< ArcIdentifier > arc_identifiers_;
};
}}}

#endif



