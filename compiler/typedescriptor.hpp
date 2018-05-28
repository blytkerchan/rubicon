#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

#include <set>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TypeDescriptor
{
	virtual bool requireExplicitTag() const { return false; }
	virtual bool hasTypeName() const { return false; }
	virtual std::string getTypeName() const { return std::string(); }
	virtual std::set< std::string > getDependencies() const { return std::set< std::string >(); }
};
}}}

#endif



