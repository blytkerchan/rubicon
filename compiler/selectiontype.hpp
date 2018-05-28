#ifndef rubicon_compiler_selectiontype_hpp
#define rubicon_compiler_selectiontype_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct SelectionType : TypeDescriptor
{
	SelectionType(std::string const &selection, std::shared_ptr< TypeDescriptor > const type)
		: selection_(selection)
		, type_(type)
	{ /* no-op */ }

	virtual bool hasTypeName() const override { return type_->hasTypeName(); }
	virtual std::string getTypeName() const override { return type_->getTypeName(); }

	std::string selection_;
	std::shared_ptr< TypeDescriptor > type_;
};
}}}

#endif



