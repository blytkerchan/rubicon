#include "integertype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void IntegerType::generateEncodeImplementation(ostream &os) const/* override*/
{
        os << "\tder_encoder.encodeInteger(*this);\n";
}
}}}






