#include "namedtype.hpp"
#include "definedtyperesolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void NamedType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	cout << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void NamedType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
    type_->visit(visitor);
}
}}}






