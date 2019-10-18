#include "primitivetype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */Tag PrimitiveType::getTag() const/* override*/
{
	switch (primitive_)
	{
	case date__ :
		return { Tag::universal__, 31 };
	case date_time__ :
		return { Tag::universal__, 33 };
	case duration__ :
		return { Tag::universal__, 34 };
	case embedded_pdv__ :
		return { Tag::universal__, 11 };
	case external__ :
		return { Tag::universal__, 8 };
	case object_identifier__ :
		return { Tag::universal__, 6 };
	case octet_string__ :
		return { Tag::universal__, 4 };
	case oid_iri__ :
		return { Tag::universal__, 35 };
	case null__ :
		return { Tag::universal__, 5 };
	case relative_oid_iri__ :
		return { Tag::universal__, 36 };
	case relative_oid__ :
		return { Tag::universal__, 13 };
	case time__ :
		return { Tag::universal__, 14 };
	case time_of_day__ :
		return { Tag::universal__, 32 };
	default:
		throw std::logic_error("Unknown tag type");
	}
}
/*virtual */string PrimitiveType::getTypeName() const/* override*/
{
	switch (primitive_)
	{
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
/*virtual */void PrimitiveType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	cout << "//TODO " << typeid(*this).name() << endl;
}
}}}






