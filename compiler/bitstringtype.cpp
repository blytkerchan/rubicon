#include "bitstringtype.hpp"
#include <boost/algorithm/string/replace.hpp>

using namespace std;
namespace alg = boost::algorithm;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void BitStringType::generateAlternateConstructorDeclarations(ostream &os, string const &class_name) const/* override*/
{
        os << "\t" << class_name << "(Vlinder::Rubicon::BitString const &bit_string);\n";
}
/*virtual */void BitStringType::generatePublicStaticMembers(ostream &os) const/* override*/
{
        for_each(
                  named_bits_.begin()
                , named_bits_.end()
                , [&](NamedBit const &named_bit){
                                os << "\tstatic unsigned int " << alg::replace_all_copy(named_bit.name_, "-", "_") << " = " << named_bit.bit_ << ";\n";
                        }
                );
}
/*virtual */void BitStringType::generateAlternateConstructorImplementations(ostream &os, string const &class_name) const/* override*/
{
        os << class_name << "::" << class_name << "(Vlinder::Rubicon::BitString const &bit_string)\n"
                << "\t: Vlinder::Rubicon::BitString(bit_string)\n"
                << "{ /* no-op */ }\n"
                ;
}
}}}





