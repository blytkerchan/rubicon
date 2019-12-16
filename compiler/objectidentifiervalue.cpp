#include "objectidentifiervalue.hpp"
#include "sequencevalue.hpp"
#include "namedvalue.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
ObjectIdentifierValue::ObjectIdentifierValue(SequenceValue const &oid)
    : Value(oid.getSourceLocation())
{
    for (auto value : oid)
    {
        auto named_value(dynamic_pointer_cast< NamedValue >(value));
        if (named_value)
        {
            oid_.push_back(named_value->getName());
        }
        else
        { /* not a named value */
            throw logic_error("Not yet implemented");
        }
    }
}
}}}

