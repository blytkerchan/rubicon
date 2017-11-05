#ifndef rubicon_compiler_arcidentifier_hpp
#define rubicon_compiler_arcidentifier_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct ArcIdentifier
{
	ArcIdentifier(std::string const &name, unsigned long id)
		: name_(name)
		, id_(id)
	{ /* no-op */ }
	ArcIdentifier(unsigned long id)
		: id_(id)
	{ /* no-op */ }

	std::string name_;
	unsigned long id_;
};
}}}

#endif



