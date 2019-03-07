#include "valueassignment.hpp"
#include "typedescriptor.hpp"
#include <boost/algorithm/string/replace.hpp>

namespace alg = boost::algorithm;
using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
void ValueAssignment::generateDeclaration(ostream &os) const
{
    os << "extern " << type_->getTypeName() << " " << alg::replace_all_copy(name_, "-", "_") << ";\n";
}
void ValueAssignment::generateDefinition(ostream &os) const
{
    os << type_->getTypeName() << " " << alg::replace_all_copy(name_, "-", "_") << "(" << value_->generateInstance() << ");\n";
}
}}}

