#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

#include <string>
#include <vector>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TypeDescriptor
{
	virtual bool requireExplicitTag() const { return false; }
	virtual std::vector< std::string > getDependencies() const { return std::vector< std::string >(); }
	virtual std::vector< std::string > getWeakDependencies() const { return std::vector< std::string >(); }
};
}}}

#endif



