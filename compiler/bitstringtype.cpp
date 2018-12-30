#include "bitstringtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void BitStringType::generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const/* override*/
{
        os << "\t" << class_name << "(Vlinder::Rubicon::BitString const &bit_string);\n";
}
/*virtual */void BitStringType::generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const/* override*/
{
        os << class_name << "::" << class_name << "(Vlinder::Rubicon::BitString const &bit_string)\n"
                << "\t: Vlinder::Rubicon::BitString(bit_string)\n"
                << "{ /* no-op */ }\n"
                ;
}
}}}





