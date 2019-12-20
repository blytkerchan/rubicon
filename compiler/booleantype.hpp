#ifndef rubicon_compiler_booleantype_hpp
#define rubicon_compiler_booleantype_hpp

#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BooleanType : public TypeDescriptor
{
public :
	BooleanType(SourceLocation const &source_location);
	virtual Tag getTag() const override { return { Tag::universal__, 1 }; }
	virtual std::string getTypeName() const override;
	virtual std::vector< std::string > getPublicParents() const override;
	virtual void generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const override;
	virtual void generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const override;
	virtual void generateHeaderGettersAndSetters(std::ostream &os) const override;
	virtual void generateSwapparatorImplementation(std::ostream &os) const override;
	virtual void generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const override;
	virtual void generateCompareImplementation(std::ostream &os) const override;

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override;
};
}}}

#endif




