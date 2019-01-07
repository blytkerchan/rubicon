#include "booleantype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
BooleanType::BooleanType(SourceLocation const &source_location)
	: TypeDescriptor(source_location)
{ /* no-op */ }
/*virtual */std::string BooleanType::getTypeName() const/* override*/
{
	return "Vlinder::Rubicon::Boolean";
}
/*virtual */std::vector< std::string > BooleanType::getPublicParents() const/* override*/
{
	return std::vector< std::string >({ "Vlinder::Rubicon::Boolean" });
}
/*virtual */void BooleanType::generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const/* override*/
{}
/*virtual */void BooleanType::generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const/* override*/
{}
/*virtual */void BooleanType::generateEncodeImplementation(std::ostream &os) const/* override*/
{}
/*virtual */void BooleanType::generateHeaderGettersAndSetters(std::ostream &os) const/* override*/
{}
/*virtual */void BooleanType::generateSwapparatorImplementation(std::ostream &os) const/* override*/
{}
/*virtual */void BooleanType::generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const/* override*/
{}
/*virtual */void BooleanType::generateCompareImplementation(std::ostream &os) const/* override*/
{}
/*virtual */std::shared_ptr< TypeDescriptor > BooleanType::visit(Resolver &resolver)/* override*/
{
	return resolver.resolve(*this);
}
}}}


