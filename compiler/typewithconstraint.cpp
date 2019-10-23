#include "typewithconstraint.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TypeWithConstraint::generateEncodeImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void TypeWithConstraint::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
void TypeWithConstraint::visit(DefinedTypeResolutionVisitor &visitor)
{
    if (type_)
    {
        type_->visit(visitor);
    }
    else
    {
        named_type_.visit(visitor);
    }
}
}}}






