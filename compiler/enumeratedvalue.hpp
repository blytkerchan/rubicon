#ifndef rubicon_compiler_enumeratedvalue_hpp
#define rubicon_compiler_enumeratedvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class EnumeratedValue : public Value
{
public :
	EnumeratedValue(SourceLocation const &source_location, std::string const &identifier)
		: Value(source_location)
		, identifier_(identifier)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	std::string identifier_;
};
}}}

#endif



