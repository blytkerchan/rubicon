#include "taggedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void TaggedType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void TaggedType::generateCopyConstructorImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
}}}






