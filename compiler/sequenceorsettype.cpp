#include "sequenceorsettype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */set< string > SequenceOrSetType::getDependencies() const
{
	set< string > retval;

	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			if (named_component_type->hasTypeName())
			{
				retval.insert(retval.end(), named_component_type->getTypeName());
			}
			else
			{ /* this type has no name */ }
			//auto deps(named_component_type->getDependencies());
			//retval.insert(deps.begin(), deps.end());
		}
		else
		{ /* not a named component */ }
	}

	return retval;
}
}}}





