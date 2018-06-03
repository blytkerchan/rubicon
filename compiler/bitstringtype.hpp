#ifndef rubicon_compiler_bitstringtype_hpp
#define rubicon_compiler_bitstringtype_hpp

#include "typedescriptor.hpp"
#include <vector>
#include <utility>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct BitStringType : TypeDescriptor
{
	typedef std::vector< std::pair< std::string, unsigned int > > NamedBits;

	BitStringType() = default;
	BitStringType(NamedBits const &named_bits)
		: named_bits_(named_bits)
	{ /* no-op */ }

	NamedBits named_bits_;
};
}}}

#endif



