#ifndef vlinder_rubicon_compiler_modulenamemappings_hpp
#define vlinder_rubicon_compiler_modulenamemappings_hpp

#include <map>
#include <string>
#include <vector>
#include <boost/variant.hpp>
#include "objectidentifier.hpp"
#include "definedvalue.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ModuleNameMappings
{
public :
	typedef std::string LocalName;
	typedef boost::variant< ObjectIdentifier, DefinedValue > AssignedIdentifier;

	ModuleNameMappings() = default;
	~ModuleNameMappings() = default;
	ModuleNameMappings(ModuleNameMappings const &) = default;
	ModuleNameMappings(ModuleNameMappings &&) = default;
	ModuleNameMappings& operator=(ModuleNameMappings const &) = default;
	ModuleNameMappings& operator=(ModuleNameMappings &&) = default;

	void insert(LocalName const &local_name, AssignedIdentifier const &assigned_identifier);
	void insert(LocalName const &local_name, ObjectIdentifier const &assigned_identifier);
	void insert(LocalName const &local_name, DefinedValue const &assigned_identifier);

	bool exists(LocalName const &local_name) const;

private :
	typedef std::map< LocalName, AssignedIdentifier > Map;
	Map map_;
};

}}}

#endif

