#include "selectiontype.hpp"
#include <iostream>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void SelectionType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void SelectionType::generateCopyConstructorImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}

}}}






