#ifndef rubicon_compiler_value_hpp
#define rubicon_compiler_value_hpp

#include <set>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct Value
{
	virtual std::set< std::string > getDependencies() const { return std::set< std::string >(); }
};
}}}

#endif



