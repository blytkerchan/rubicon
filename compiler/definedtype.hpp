#ifndef rubicon_compiler_definedtype_hpp
#define rubicon_compiler_definedtype_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct DefinedType : TypeDescriptor
{
	DefinedType(std::string const &type_name)
		: type_name_(type_name)
	{ /* no-op */ }

	std::string type_name_;
};
}}}

#endif



