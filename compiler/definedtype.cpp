#include "definedtype.hpp"
#include "definedtyperesolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */Tag DefinedType::getTag() const/* override*/
{
    if (!tag_)
    {
        if (!referenced_type_)
        {
            throw std::logic_error("I should not have to answer this");
        }
        else
        {
            return referenced_type_->getTag();
        }
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
/*virtual */void DefinedType::visit(DefinedTypeResolutionVisitor& visitor)/* override*/
{
    visitor.visit(*this);
}
}}}



