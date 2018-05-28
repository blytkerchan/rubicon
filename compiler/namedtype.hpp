#ifndef rubicon_compiler_namedtype_hpp
#define rubicon_compiler_namedtype_hpp

#include "typedescriptor.hpp"
#include <string>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct NamedType : TypeDescriptor
{
	NamedType() = default;
	NamedType(std::string const &name, std::shared_ptr< TypeDescriptor > const &type)
		: name_(name)
		, type_(type)
	{ /* no-op */ }

	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }

	std::string name_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



