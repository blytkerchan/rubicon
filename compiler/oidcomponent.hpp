#ifndef rubicon_compiler_oidcomponent_hpp
#define rubicon_compiler_oidcomponent_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct OIDComponent
{
	enum Variant_ {
		  number__
		, name_and_number__
		};

	OIDComponent()
	{ /* no-op */ }

	Variant_ variant_;
	unsigned int number_;
	std::string identifier_;
};
}}}

#endif



