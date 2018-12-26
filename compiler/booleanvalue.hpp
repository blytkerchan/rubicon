#ifndef rubicon_compiler_booleanvalue_hpp
#define rubicon_compiler_booleanvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BooleanValue : public Value
{
public :
	BooleanValue(SourceLocation const &source_location, bool value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "Boolean"; }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	bool value_;
};
}}}

#endif



