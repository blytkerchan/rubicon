#include "constrainedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void ConstrainedType::generateEncodeImplementation(ostream &os) const/* override*/
{
	os <<
		"\tcheckConstraints()\n"
		"\t//TODO\n"
		;
}
}}}






