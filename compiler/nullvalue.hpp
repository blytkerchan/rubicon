#ifndef rubicon_compiler_nullvalue_hpp
#define rubicon_compiler_nullvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct NullValue : Value
{
	explicit NullValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }
	std::string getTypeName() const override { return "Null"; }
};
}}}

#endif



