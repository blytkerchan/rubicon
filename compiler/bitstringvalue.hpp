#ifndef rubicon_compiler_bitstringvalue_hpp
#define rubicon_compiler_bitstringvalue_hpp

#include "value.hpp"
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Directory;
class TypeDescriptor;
class BitStringValue : public Value
{
public :
	BitStringValue(SourceLocation const &source_location, Directory const &directory, std::shared_ptr< TypeDescriptor > const &type);
	BitStringValue(SourceLocation const &source_location, Directory const &directory, std::shared_ptr< TypeDescriptor > const &type, std::vector< unsigned char > const &bit_string, unsigned int trailing_bits);
	BitStringValue(SourceLocation const &source_location, Directory const &directory, std::shared_ptr< TypeDescriptor > const &type, std::shared_ptr< Value > const &value);
	BitStringValue(SourceLocation const &source_location, Directory const &directory, std::shared_ptr< TypeDescriptor > const &type, std::vector< std::string > const &identifiers);

	std::string getTypeName() const override;

	std::string generateInstance() const override;

private :
	std::shared_ptr< TypeDescriptor > type_;
	std::vector< unsigned char > bit_string_;
	unsigned int trailing_bits_ = 0;
	std::shared_ptr< Value > value_;
};
}}}

#endif



