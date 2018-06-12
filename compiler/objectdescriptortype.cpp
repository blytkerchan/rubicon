#include "objectdescriptortype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void ObjectDescriptorType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
/*virtual */void ObjectDescriptorType::generateCopyConstructorImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO " << typeid(*this).name() << endl;
}
}}}






