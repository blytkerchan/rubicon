#include "selectiontype.hpp"
#include "choicetype.hpp"
#include <iostream>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*TODO I don't remember enough about this code to know if the four following functions are implemented correctly
 *     Pretty sure they're not: type_ should be a ChoiceType (if it's not, validation should have failed before any of
 *     these are called) and the identifier we carry here (selection_) contains the name of the ChoiceType component 
 *     type (member) that is selected. The getTag function should return the tag for that type, the hasTypeName function
 *     should return whether that selected type has a name, etc. I should really implement getType(), then implement the
 *     others as a function of getType(). */
/*virtual */Tag SelectionType::getTag() const/* override*/
{
	return type_->getTag(); // probably wrong
}
/*virtual */bool SelectionType::hasTypeName() const/* override*/
{
	return type_->hasTypeName(); // probably wrong
}
/*virtual */shared_ptr< TypeDescriptor > SelectionType::getType() const
{
	assert(dynamic_pointer_cast< ChoiceType >(type_) == static_pointer_cast< ChoiceType >(type_));
	return type_; // probably wrong
}
/*virtual */string SelectionType::getTypeName() const/* override*/
{
	return type_->getTypeName(); // probably wrong
}
/*virtual */void SelectionType::generateEncodeImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void SelectionType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}

}}}






