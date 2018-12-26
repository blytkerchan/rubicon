#ifndef rubicon_compiler_choicevalue_hpp
#define rubicon_compiler_choicevalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ChoiceValue : public Value
{
public :
	ChoiceValue(SourceLocation const &source_location, std::string const &identifier, std::shared_ptr< Value > const &value)
		: Value(source_location)
		, identifier_(identifier)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	std::string identifier_;
	std::shared_ptr< Value > value_;
};
}}}

#endif



