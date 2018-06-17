#ifndef rubicon_compiler_bitstringvalue_hpp
#define rubicon_compiler_bitstringvalue_hpp

#include "value.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BitStringValue : public Value
{
public :
	explicit BitStringValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }
	BitStringValue(SourceLocation const &source_location, std::vector< unsigned char > const &bit_string, unsigned int trailing_bits)
		: Value(source_location)
		, bit_string_(bit_string)
		, trailing_bits_(trailing_bits)
	{ /* no-op */ }
	BitStringValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }
	BitStringValue(SourceLocation const &source_location, std::vector< std::string > &&identifiers)
		: Value(source_location)
		, identifiers_(std::move(identifiers))
	{ /* no-op */ }

	std::string getTypeName() const override { return "BitString"; }

private :
	std::vector< unsigned char > bit_string_;
	unsigned int trailing_bits_ = 0;
	std::shared_ptr< Value > value_;
	std::vector< std::string > identifiers_;
};
}}}

#endif



