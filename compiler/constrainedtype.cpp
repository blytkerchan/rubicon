#include "constrainedtype.hpp"
#include "definedtyperesolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void ConstrainedType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
    type_->visit(visitor);
}
}}}






