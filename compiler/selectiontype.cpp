#include "selectiontype.hpp"
#include <iostream>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*TODO I don't remember enough about this code to know if the three following functions are implemented correctly*/
/*virtual */bool SelectionType::hasTypeName() const/* override*/
{
	return type_->hasTypeName();
}
/*virtual */std::shared_ptr< TypeDescriptor > SelectionType::getType() const
{
	return type_;
}
/*virtual */std::string SelectionType::getTypeName() const/* override*/
{
	return type_->getTypeName();
}
/*virtual */void SelectionType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void SelectionType::generateCopyConstructorImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}

}}}






