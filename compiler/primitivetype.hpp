#ifndef rubicon_compiler_primitivetype_hpp
#define rubicon_compiler_primitivetype_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class PrimitiveType : public TypeDescriptor
{
public :
	enum Primitive {
		  boolean__
		, date__
		, date_time__
		, duration__
		, embedded_pdv__
		, external__
		, object_identifier__
		, octet_string__
		, oid_iri__
		, null__
		, relative_oid_iri__
		, relative_oid__
		, time__
		, time_of_day__
		};
	PrimitiveType(Primitive primitive)
		: primitive_(primitive)
	{ /* no-op */ }

private :
	Primitive primitive_;
};
}}}

#endif


