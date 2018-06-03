#include "constrainedtype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void ConstrainedType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os <<
		"\tcheckConstraints()\n"
		"\t//TODO\n"
		;
}
}}}






