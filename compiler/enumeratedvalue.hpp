#ifndef rubicon_compiler_enumeratedvalue_hpp
#define rubicon_compiler_enumeratedvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class EnumeratedValue : public Value
{
public :
	EnumeratedValue(std::string const &identifier)
		: identifier_(identifier)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

private :
	std::string identifier_;
};
}}}

#endif



