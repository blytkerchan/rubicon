#include "primitivetype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */std::string PrimitiveType::getTypeName() const/* override*/
{
	switch (primitive_)
	{
	case boolean__ :
		return "bool";
	case date__ :
	case date_time__ :
	case time__ :
	case time_of_day__ :
	case duration__ :
		return "timeval";
	case embedded_pdv__ :
		return "Vlinder::Rubicon::EmbeddedPDV";
	case object_identifier__ :
	case oid_iri__ :
	case relative_oid_iri__ :
	case relative_oid__ :
		return "Vlinder::Rubicon::ObjectIdentifier";
	case octet_string__ :
		return "Vlinder::Rubicon::OctetString";
	case null__ :
		return "Vlinder::Rubicon::Null";
	case external__ :
		return "Vlinder::Rubicon::External";
	}
	throw logic_error("Unknown primitive type");
}
/*virtual */void PrimitiveType::generateConstructorImplementations(std::ostream &os) const/* override*/
{
	cout << "//TODO " << typeid(*this).name() << endl;
}
}}}






