#include "definedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */Tag DefinedType::getTag() const/* override*/
{
    if (!tag_)
    {
        throw std::logic_error("I should not have to answer this");
    }
    else
    {
        return *tag_;
    }
}
/*virtual */void DefinedType::setTag(Tag const &tag)/* override*/
{
    tag_ = make_unique< Tag >(tag);
}
/*virtual */bool DefinedType::tagged() const/* override*/
{
    return !!tag_;
}
/*virtual */void DefinedType::generateEncodeImplementation(ostream &os) const/* override*/ {}
}}}



