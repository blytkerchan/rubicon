#include "typewithconstraint.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TypeWithConstraint::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void TypeWithConstraint::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
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
/*virtual */std::shared_ptr< StateMachine > TypeWithConstraint::getStateMachine() const/* override*/
{
    if (type_)
    {
        return type_->getStateMachine();
    }
    else
    {
        return named_type_.getStateMachine();
    }
}
}}}






