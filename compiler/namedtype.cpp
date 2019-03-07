#include "namedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void NamedType::generateEncodeImplementation(ostream &os) const/* override*/
{
	type_->generateEncodeImplementation(os);
}
/*virtual */void NamedType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	cout << "//TODO " << typeid(*this).name() << endl;
}
}}}






