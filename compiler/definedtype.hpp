#ifndef rubicon_compiler_definedtype_hpp
#define rubicon_compiler_definedtype_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct DefinedType : TypeDescriptor
{
	DefinedType(std::string const &type_name)
		: type_name_(type_name)
	{ /* no-op */ }

	virtual bool hasTypeName() const override { return true; }
	virtual std::string getTypeName() const override { return type_name_; }

	std::string type_name_;
};
}}}

#endif



