#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TypeDescriptor
{
	virtual bool requireExplicitTag() const { return false; }
};
}}}

#endif



