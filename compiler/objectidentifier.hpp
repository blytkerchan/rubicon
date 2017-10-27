#ifndef vlinder_rubicon_compiler_objectidentifier_hpp
#define vlinder_rubicon_compiler_objectidentifier_hpp

#include <string>
#include <vector>
#include <boost/variant.hpp>

namespace Vlinder { namespace Rubicon { namespace Compiler {
	typedef boost::variant< std::string, unsigned int, std::pair< std::string, unsigned int > > ObjectIdentifierComponent;
	typedef std::vector< ObjectIdentifierComponent > ObjectIdentifier;
}}}

#endif


