#include "unknowntype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void UnknownType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void UnknownType::generateCopyConstructorImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}

}}}






