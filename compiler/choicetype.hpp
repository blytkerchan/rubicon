#ifndef rubicon_compiler_choicetype_hpp
#define rubicon_compiler_choicetype_hpp

#include "typedescriptor.hpp"
#include "versionedtypelist.hpp"
#include <vector>
#include <utility>
#include <string>
#include <boost/variant.hpp>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Resolver;
class ChoiceType : public TypeDescriptor
{
public :
	typedef std::vector< boost::variant< NamedType, VersionedTypeList > > AlternativeTypes;

	ChoiceType(SourceLocation const &source_location, AlternativeTypes const &alternative_types, bool extensible)
		: TypeDescriptor(source_location)
		, alternative_types_(alternative_types)
		, extensible_(extensible)
	{ /* no-op */ }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

	virtual bool requireExplicitTag() const override { return true; }
	virtual std::set< std::string > getDependencies() const;

	virtual void generateEncodeImplementation(std::ostream &os) const override;

private :
	AlternativeTypes alternative_types_;
	bool extensible_;

	friend class Resolver;
};
}}}

#endif



