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

	virtual Tag getTag() const override { return { Tag::universal__, 3 }; }
	virtual std::vector< std::string > getPublicParents() const override { return std::vector< std::string >{ "Vlinder::Rubicon::BitString" }; }

	virtual std::string getTypeName() const override { return "Vlinder::Rubicon::BitString"; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

	NamedBits getNamedBits() const { return named_bits_; }

	virtual void generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const override;
	virtual void generatePublicStaticMembers(std::ostream &os) const override;
	virtual void generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const override;
	virtual void generateSwapparatorImplementation(std::ostream &os) const override;
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateCompareImplementation(std::ostream &os) const override;

private :
	NamedBits named_bits_;

	friend class Resolver;
};
}}}

#endif



