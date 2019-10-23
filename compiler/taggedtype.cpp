#include "taggedtype.hpp"
#include "definedtyperesolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TaggedType::generateEncodeImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void TaggedType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void TaggedType::visit(DefinedTypeResolutionVisitor& visitor)/* override*/
{
    type_->visit(visitor);
}
}}}






