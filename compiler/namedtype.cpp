#include "namedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void NamedType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	type_->generateEncodeImplementation(os);
}
/*virtual */void NamedType::generateEncodeImplementation(std::ostream &os, std::string const &member_name) const/* override*/
{
	type_->generateEncodeImplementation(os, member_name);
}
}}}





