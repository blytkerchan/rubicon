#ifndef rubicon_compiler_integervalue_hpp
#define rubicon_compiler_integervalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct IntegerValue : Value
{
	IntegerValue(long value)
		: value_(value)
	{ /* no-op */ }

	IntegerValue(std::string const &identifier)
		: identifier_(identifier)
	{ /* no-op */ }

	long value_;
	std::string identifier_;
};
}}}

#endif



