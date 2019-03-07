#include "typedescriptor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TypeDescriptor::setTag(Tag const &tag)
{
	assert(!"This should not be called");
}
/*virtual */void TypeDescriptor::generateEncodeImplementation(ostream &os) const
{
	os << typeid(*this).name() << " generateEncodeImplementation(os)"<< endl;
}
/*virtual */void TypeDescriptor::generateDataMembers(ostream &os) const
{
	os << typeid(*this).name() << " generateDataMembers(os)"<< endl;
}
void TypeDescriptor::setStateMachine(StateMachine const &state_machine)
{
	state_machine_ = make_shared< StateMachine >(state_machine);
}
}}}





