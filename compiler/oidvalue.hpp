#ifndef rubicon_compiler_oidvalue_hpp
#define rubicon_compiler_oidvalue_hpp

#include "value.hpp"
#include "oidcomponent.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct OIDValue : Value
{
	OIDValue(bool relative = false)
		: relative_(relative)
	{ /* no-op */ }

	void add(OIDComponent const &oid_component)
	{
		oid_components_.push_back(oid_component);
	}

	bool relative_;
	std::vector< OIDComponent > oid_components_;
};
}}}

#endif



