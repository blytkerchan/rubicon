#ifndef rubicon_compiler_externaltypereference_hpp
#define rubicon_compiler_externaltypereference_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ExternalTypeReference : TypeDescriptor
{
	ExternalTypeReference(std::string const &module_name, std::string const &symbol_name)
		: module_name_(module_name)
		, symbol_name_(symbol_name)
	{ /* no-op */ }

	std::string module_name_;
	std::string symbol_name_;
};
}}}

#endif



