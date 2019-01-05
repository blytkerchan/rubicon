#include "typedescriptor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TypeDescriptor::generateEncodeImplementation(ostream &os) const
{
	os << typeid(*this).name() << " generateEncodeImplementation(os)"<< endl;
}
/*virtual */void TypeDescriptor::generateEncodeImplementation(ostream &os, string const &instance_name) const
{
	os << typeid(*this).name() << " generateEncodeImplementation(os, instance_name)"<< endl;
}
/*virtual */void TypeDescriptor::generateDataMembers(std::ostream &os) const
{
	os << typeid(*this).name() << " generateDataMembers(os)"<< endl;
}
void TypeDescriptor::setStateMachine(StateMachine const &state_machine)
{
	state_machine_ = make_shared< StateMachine >(state_machine);
}
}}}





