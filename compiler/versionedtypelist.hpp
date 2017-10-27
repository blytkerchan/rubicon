#ifndef rubicon_compiler_versionedtypelist_hpp
#define rubicon_compiler_versionedtypelist_hpp

#include "namedtype.hpp"
#include <utility>
#include <vector>

namespace Vlinder { namespace Rubicon { namespace Compiler {
	typedef std::pair< unsigned int, std::vector< NamedType > > VersionedTypeList;
}}}

#endif



