#ifndef rubicon_compiler_unrestrictedcharacterstringvalue_hpp
#define rubicon_compiler_unrestrictedcharacterstringvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class UnrestrictedCharacterStringValue : public Value
{
public :
	UnrestrictedCharacterStringValue(std::shared_ptr< Value > const &value)
		: value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "UnrestrictedCharacterString"; }

private :
	std::shared_ptr< Value > value_;
};
}}}

#endif



