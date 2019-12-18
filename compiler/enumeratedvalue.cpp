#include "enumeratedvalue.hpp"
#include "namedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
EnumeratedValue::EnumeratedValue(SourceLocation const &source_location, string const &identifier, std::shared_ptr< TypeDescriptor > const &type)
	: Value(source_location)
	, identifier_(identifier)
{
    auto named_type(dynamic_pointer_cast< NamedType >(type));
    if (named_type)
    {
        type_name_ = named_type->getTypeName();
    }
    else
    { /* no-op - not a named type */ }
}

/*virtual */string EnumeratedValue::getTypeName() const/* override*/
{
    return type_name_;
}
/*virtual */string EnumeratedValue::generateInstance() const/* override*/
{
    return type_name_ + "(" + type_name_ + "::" + identifier_ + ")";
}
}}}



