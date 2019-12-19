#include "helpers.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
string toVariableName(string const &name, bool from_type_name/* = false*/)
{
	string retval;
	for (char c : name)
	{
		if (c == tolower(c))
		{
			retval.append(1, c);
		}
		else
		{
			if (!from_type_name) retval.append("_");
            from_type_name = false; // serves as "first" flag
			retval.append(1, tolower(c));
		}
	}

	return retval;
}
string toMemberName(string const &name, bool from_type_name/* = false*/)
{
	return toVariableName(name, from_type_name) + "_";
}
}}}

