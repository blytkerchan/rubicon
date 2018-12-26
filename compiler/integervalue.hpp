#ifndef rubicon_compiler_integervalue_hpp
#define rubicon_compiler_integervalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class IntegerValue : public Value
{
public :
	IntegerValue(SourceLocation const &source_location, long value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }

	IntegerValue(SourceLocation const &source_location, std::string const &identifier)
		: Value(source_location)
		, identifier_(identifier)
	{ /* no-op */ }

	std::string getTypeName() const override { return "Integer"; }
	std::string getIdentifier() const { return identifier_; }
	long getValue() const { return value_; }

	std::string generateInstance() const override { return std::to_string(value_); }

private :
	long value_;
	std::string identifier_;
};
}}}

#endif



