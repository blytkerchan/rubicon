#ifndef rubicon_compiler_unrestrictedcharacterstringvalue_hpp
#define rubicon_compiler_unrestrictedcharacterstringvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class UnrestrictedCharacterStringValue : public Value
{
public :
	UnrestrictedCharacterStringValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "UnrestrictedCharacterString"; }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	std::shared_ptr< Value > value_;
};
}}}

#endif



