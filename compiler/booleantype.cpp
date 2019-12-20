#include "booleantype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
BooleanType::BooleanType(SourceLocation const &source_location)
	: TypeDescriptor(source_location)
{ /* no-op */ }
/*virtual */string BooleanType::getTypeName() const/* override*/
{
	return "Vlinder::Rubicon::Boolean";
}
/*virtual */vector< string > BooleanType::getPublicParents() const/* override*/
{
	return vector< string >({ "Vlinder::Rubicon::Boolean" });
}
/*virtual */void BooleanType::generateAlternateConstructorDeclarations(ostream &os, string const &class_name) const/* override*/
{
	os << "\t" << class_name << "(Vlinder::Rubicon::Boolean const &other);\n";
}
/*virtual */void BooleanType::generateAlternateConstructorImplementations(ostream &os, string const &class_name) const/* override*/
{
	os
		<< class_name << "::" << class_name << "(Vlinder::Rubicon::Boolean const &other)\n"
		"\t: Vlinder::Rubicon::Boolean(other)\n"
		"{ /* no-op */ }\n"
		;
}
/*virtual */void BooleanType::generateHeaderGettersAndSetters(ostream &os) const/* override*/
{}
/*virtual */void BooleanType::generateSwapparatorImplementation(ostream &os) const/* override*/
{
	os << "\tVlinder::Rubicon::Boolean::swap(other);\n";
}
/*virtual */void BooleanType::generateGetterAndSetterImplementations(string const &type_name, ostream &ofs) const/* override*/
{}
/*virtual */void BooleanType::generateCompareImplementation(ostream &os) const/* override*/
{
	os << "\treturn Vlinder::Rubicon::Boolean::compare(other);\n";
}
/*virtual */shared_ptr< TypeDescriptor > BooleanType::visit(Resolver &resolver)/* override*/
{
	return resolver.resolve(*this);
}
}}}


