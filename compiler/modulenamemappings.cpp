#include "modulenamemappings.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
void ModuleNameMappings::insert(LocalName const &local_name, AssignedIdentifier const &assigned_identifier)
{
	map_.insert(Map::value_type(local_name, assigned_identifier));
}

void ModuleNameMappings::insert(LocalName const &local_name, ObjectIdentifier const &assigned_identifier)
{
	insert(local_name, AssignedIdentifier(assigned_identifier));
}
void ModuleNameMappings::insert(LocalName const &local_name, shared_ptr< Value > const &assigned_identifier)
{
	insert(local_name, AssignedIdentifier(assigned_identifier));
}
bool ModuleNameMappings::exists(LocalName const &local_name) const
{
	auto where(map_.find(local_name));
	return where != map_.end();
}
}}}



