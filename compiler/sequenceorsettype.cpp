#include "sequenceorsettype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */vector< string > SequenceOrSetType::getDependencies() const
{
	vector< string > retval;

	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			retval.push_back(named_component_type->named_type_.name_);
		}
		else
		{ /* not a named component */ }
	}

	return retval;
}
}}}





