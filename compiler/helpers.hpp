#ifndef rubicon_compiler_helpers_hpp
#define rubicon_compiler_helpers_hpp

#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
std::string toVariableName(std::string const &name, bool from_type_name = false);
std::string toMemberName(std::string const &name, bool from_type_name = false);
}}}

#endif


