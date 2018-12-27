#ifndef rubicon_compiler_bitstringvalue_hpp
#define rubicon_compiler_bitstringvalue_hpp

#include "value.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BitStringValue : public Value
{
public :
	explicit BitStringValue(SourceLocation const &source_location);
	BitStringValue(SourceLocation const &source_location, std::vector< unsigned char > const &bit_string, unsigned int trailing_bits);
	BitStringValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value);
	BitStringValue(SourceLocation const &source_location, std::vector< std::string > &&identifiers);

	std::string getTypeName() const override;

	std::string generateInstance() const override;

private :
	std::vector< unsigned char > bit_string_;
	unsigned int trailing_bits_ = 0;
	std::shared_ptr< Value > value_;
	std::vector< std::string > identifiers_;
};
}}}

#endif



