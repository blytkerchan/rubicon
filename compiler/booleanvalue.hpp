#ifndef rubicon_compiler_booleanvalue_hpp
#define rubicon_compiler_booleanvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BooleanValue : public Value
{
public :
	BooleanValue(bool value)
		: value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "BooleanString"; }

private :
	bool value_;
};
}}}

#endif



