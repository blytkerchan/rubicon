#ifndef rubicon_compiler_embeddedpdvvalue_hpp
#define rubicon_compiler_embeddedpdvvalue_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class EmbeddedPDVValue : public Value
{
public :
	EmbeddedPDVValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value)
		: Value(source_location)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return "EmbeddedPDV"; }

private :
	std::shared_ptr< Value > value_;
};
}}}

#endif



