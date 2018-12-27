#include "valueassignment.hpp"
#include "typedescriptor.hpp"
#include <boost/algorithm/string/replace.hpp>

namespace alg = boost::algorithm;

namespace Vlinder { namespace Rubicon { namespace Compiler {
void ValueAssignment::generateDeclaration(std::ostream &os) const
{
    os << "extern " << type_->getTypeName() << " " << alg::replace_all_copy(name_, "-", "_") << ";\n";
}
void ValueAssignment::generateDefinition(std::ostream &os) const
{
    os << type_->getTypeName() << " " << name_ << "(" << value_->generateInstance() << ");\n";
}
}}}

