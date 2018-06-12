#include "typeassignment.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
void TypeAssignment::generateCopyConstructorImplementation(std::ostream &os) const
{
	if (hasOptionalMembers())
	{
		os << getName() << "::" << getName() << "(" << getName() << " const &other)\n{\n";
		type_descriptor_->generateCopyConstructorImplementation(os);
		os << "}\n";
	}
	else
	{ /* no optional members - default copy constructor */ }
}
}}}


