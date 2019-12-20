#include "sequenceorsetoftype.hpp"
#include "definedtyperesolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void SequenceOrSetOfType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void SequenceOrSetOfType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
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






