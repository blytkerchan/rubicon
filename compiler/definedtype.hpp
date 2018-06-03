#ifndef rubicon_compiler_definedtype_hpp
#define rubicon_compiler_definedtype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct DefinedType : TypeDescriptor
{
	DefinedType(std::string const &type_name)
		: type_name_(type_name)
	{ /* no-op */ }

	virtual bool hasTypeName() const override { return true; }
	virtual std::string getTypeName() const override { return type_name_; }

	virtual void generateEncodeImplementation(std::ostream &os, std::string const &member_name) const override;

	std::string type_name_;
};
}}}

#endif



