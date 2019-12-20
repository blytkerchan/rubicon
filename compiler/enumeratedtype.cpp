#include "enumeratedtype.hpp"
#include <boost/algorithm/string/replace.hpp>

using namespace std;
namespace alg = boost::algorithm;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void EnumeratedType::generateAlternateConstructorDeclarations(ostream &os, string const &class_name) const/* override*/
{
        os << "\t" << class_name << "(Vlinder::Rubicon::Integer const &value);\n";
        os << "\texplicit " << class_name << "(unsigned int value);\n";
}
/*virtual */void EnumeratedType::generatePublicStaticMembers(ostream &os) const/* override*/
{
        for_each(
                  values_.begin()
                , values_.end()
                , [&](NamedNumber const &named_number){
                                os << "\tstatic unsigned int const " << alg::replace_all_copy(named_number.name_, "-", "_") << " = " << boost::get< long >(named_number.value_) << ";\n";
                        }
                );
}
/*virtual */void EnumeratedType::generateAlternateConstructorImplementations(ostream &os, string const &class_name) const/* override*/
{
        os << class_name << "::" << class_name << "(Vlinder::Rubicon::Integer const &value)\n"
                << "\t: Vlinder::Rubicon::Integer(value)\n"
                << "{ /* no-op */ }\n"
                ;
        os << "/*explicit */" << class_name << "::" << class_name << "(unsigned int value)\n"
                << "\t: Vlinder::Rubicon::Integer(value)\n"
                << "{ /* no-op */ }\n"
                ;
}
/*virtual */void EnumeratedType::generateSwapparatorImplementation(ostream &os) const/* override*/
{
        os << "\tVlinder::Rubicon::Integer::swap(other);\n";
}
/*virtual */void EnumeratedType::generateCompareImplementation(ostream &os) const/* override*/
{
	os << "\treturn Vlinder::Rubicon::Integer::compare(other);\n";
}
}}}






