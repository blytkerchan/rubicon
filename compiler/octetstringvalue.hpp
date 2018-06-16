#ifndef rubicon_compiler_octetstringvalue_hpp
#define rubicon_compiler_octetstringvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class OctetStringValue : public Value
{
public :
	OctetStringValue() = default;
	OctetStringValue(std::vector< unsigned char > const &bit_string, unsigned int trailing_bits)
		: bit_string_(bit_string)
		, trailing_bits_(trailing_bits)
	{ /* no-op */ }
	OctetStringValue(std::shared_ptr< Value > const &value)
		: value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "OctetString"; }

private :
	std::vector< unsigned char > bit_string_;
	unsigned int trailing_bits_ = 0;
	std::shared_ptr< Value > value_;
};
}}}

#endif



