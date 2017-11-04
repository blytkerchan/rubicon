#ifndef rubicon_compiler_embeddedpdvvalue_hpp
#define rubicon_compiler_embeddedpdvvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct EmbeddedPDVValue : Value
{
	EmbeddedPDVValue(std::shared_ptr< Value > const &value)
		: value_(value)
	{ /* no-op */ }

	std::shared_ptr< Value > value_;
};
}}}

#endif



