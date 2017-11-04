#ifndef rubicon_compiler_enumeratedvalue_hpp
#define rubicon_compiler_enumeratedvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct EnumeratedValue : Value
{
	EnumeratedValue(std::string const &identifier)
		: identifier_(identifier)
	{ /* no-op */ }

	std::string identifier_;
};
}}}

#endif



