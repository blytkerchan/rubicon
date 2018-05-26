#include "dependencies.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
void Dependencies::add(string const &name, vector< string > const &dependencies)
{
	entries_.insert(Entry(name, dependencies));
}
}}}
namespace std {
	ostream& operator<<(ostream &os, Vlinder::Rubicon::Compiler::Dependencies const &dependencies)
	{
		os << string("digraph {\n");
		for (auto entry : dependencies)
		{
			for (auto dependency : entry.second)
			{
				os << entry.first << string(" -> ") << dependency << string("\n");
			}
		}
		os << string("}");
		return os;
	}
}



