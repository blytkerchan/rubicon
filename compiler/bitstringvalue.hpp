#ifndef rubicon_compiler_bitstringvalue_hpp
#define rubicon_compiler_bitstringvalue_hpp

#include "value.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct BitStringValue : Value
{
	BitStringValue() = default;
	BitStringValue(std::vector< unsigned char > const &bit_string, unsigned int trailing_bits)
		: bit_string_(bit_string)
		, trailing_bits_(trailing_bits)
	{ /* no-op */ }
	BitStringValue(std::shared_ptr< Value > const &value)
		: value_(value)
	{ /* no-op */ }
	BitStringValue(std::vector< std::string > &&identifiers)
		: identifiers_(std::move(identifiers))
	{ /* no-op */ }

	std::vector< unsigned char > bit_string_;
	unsigned int trailing_bits_ = 0;
	std::shared_ptr< Value > value_;
	std::vector< std::string > identifiers_;
};
}}}

#endif



