#ifndef rubicon_compiler_bitstringtype_hpp
#define rubicon_compiler_bitstringtype_hpp

#include "typedescriptor.hpp"
#include <vector>
#include <utility>
#include <string>
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Resolver;
class BitStringType : public TypeDescriptor
{
public :
	struct NamedBit
	{
		NamedBit(
			  SourceLocation source_location
			, std::string name
			, unsigned int bit
			)
			: source_location_(source_location)
			, name_(name)
			, bit_(bit)
		{ /* no-op */ }
		SourceLocation source_location_;
		std::string name_;
		unsigned int bit_;
	};
	typedef std::vector< NamedBit > NamedBits;

	explicit BitStringType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	BitStringType(SourceLocation const &source_location, NamedBits const &named_bits)
		: TypeDescriptor(source_location)
		, named_bits_(named_bits)
	{ /* no-op */ }

	virtual std::string getTypeName() const override { return "Vlinder::Rubicon::BitString"; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

	NamedBits getNamedBits() const { return named_bits_; }

private :
	NamedBits named_bits_;

	friend class Resolver;
};
}}}

#endif



