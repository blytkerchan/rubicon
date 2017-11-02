#ifndef rubicon_compiler_booleanvalue_hpp
#define rubicon_compiler_booleanvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct BooleanValue : Value
{
	BooleanValue(bool value)
		: value_(value)
	{ /* no-op */ }

	bool value_;
};
}}}

#endif



