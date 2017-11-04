#ifndef rubicon_compiler_choicevalue_hpp
#define rubicon_compiler_choicevalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ChoiceValue : Value
{
	ChoiceValue(std::string const &identifier, std::shared_ptr< Value > const &value)
		: identifier_(identifier)
		, value_(value)
	{ /* no-op */ }

	std::string identifier_;
	std::shared_ptr< Value > value_;
};
}}}

#endif



