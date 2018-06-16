#ifndef rubicon_compiler_integervalue_hpp
#define rubicon_compiler_integervalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class IntegerValue : public Value
{
public :
	IntegerValue(long value)
		: value_(value)
	{ /* no-op */ }

	IntegerValue(std::string const &identifier)
		: identifier_(identifier)
	{ /* no-op */ }

	std::string getTypeName() const override { return "Integer"; }

private :
	long value_;
	std::string identifier_;
};
}}}

#endif



