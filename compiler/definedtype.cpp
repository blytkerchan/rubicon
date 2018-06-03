#include "definedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void DefinedType::generateEncodeImplementation(std::ostream &os, std::string const &member_name) const/* override*/
{
	os << "\t" << member_name << ".encode(der_encoder);\n";
}
}}}



