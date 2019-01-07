#ifndef rubicon_compiler_primitivetype_hpp
#define rubicon_compiler_primitivetype_hpp

#include "typedescriptor.hpp"
#include <iostream>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class PrimitiveType : public TypeDescriptor
{
public :
	enum Primitive {
		  date__
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
	PrimitiveType(SourceLocation const &source_location, Primitive primitive)
		: TypeDescriptor(source_location)
		, primitive_(primitive)
	{ /* no-op */ }

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	virtual std::string getTypeName() const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

private :
	Primitive primitive_;
};
}}}

#endif



