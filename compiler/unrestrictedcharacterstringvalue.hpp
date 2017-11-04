#ifndef rubicon_compiler_unrestrictedcharacterstringvalue_hpp
#define rubicon_compiler_unrestrictedcharacterstringvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct UnrestrictedCharacterStringValue : Value
{
	UnrestrictedCharacterStringValue(std::shared_ptr< Value > const &value)
		: value_(value)
	{ /* no-op */ }

	std::shared_ptr< Value > value_;
};
}}}

#endif



