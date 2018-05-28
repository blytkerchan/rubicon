#ifndef rubicon_compiler_choicetype_hpp
#define rubicon_compiler_choicetype_hpp

#include "typedescriptor.hpp"
#include "versionedtypelist.hpp"
#include <vector>
#include <utility>
#include <string>
#include <boost/variant.hpp>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ChoiceType : TypeDescriptor
{
	typedef std::vector< boost::variant< NamedType, VersionedTypeList > > AlternativeTypes;

	ChoiceType(AlternativeTypes const &alternative_types, bool extensible)
		: alternative_types_(alternative_types)
		, extensible_(extensible)
	{ /* no-op */ }
	virtual bool requireExplicitTag() const override { return true; }
	virtual std::set< std::string > getDependencies() const;

	AlternativeTypes alternative_types_;
	bool extensible_;
};
}}}

#endif



