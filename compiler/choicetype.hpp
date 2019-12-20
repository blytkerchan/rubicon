#ifndef rubicon_compiler_choicetype_hpp
#define rubicon_compiler_choicetype_hpp

#include "typedescriptor.hpp"
#include "versionedtypelist.hpp"
#include <vector>
#include <utility>
#include <string>
#include <boost/variant.hpp>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Resolver;
class ChoiceType : public TypeDescriptor
{
public :
	typedef std::vector< boost::variant< NamedType, VersionedTypeList > > AlternativeTypes;

	ChoiceType(SourceLocation const &source_location, AlternativeTypes const &alternative_types, bool extensible)
		: TypeDescriptor(source_location)
		, alternative_types_(alternative_types)
		, extensible_(extensible)
	{ /* no-op */ }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }

	virtual Tag getTag() const override;
	virtual bool requireExplicitTag() const override { return true; }
	virtual std::set< std::string > getDependencies() const;

    virtual bool hasOptionalMembers() const { return true; } // all members in a choice are optional

    virtual void generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const override;
    virtual void generateHeaderGettersAndSetters(std::ostream &os) const override;
    virtual void generateMemberDeclarations(std::ostream &os) const override;
    virtual void generateCopyConstructorInitializers(std::ostream &os) const override;
    virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
    virtual void generateDestructorImplementation(std::ostream &os) const override;
    virtual void generateSwapparatorImplementation(std::ostream &os) const override;
    virtual void generateCompareImplementation(std::ostream &os) const override;
    virtual void generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const override;

	bool isClone() const { return is_clone_; }
	unsigned int getCloneID() const;
	std::string getCloneName() const;
	void setClone(unsigned int clone_id, std::string const &clone_name)
	{
		is_clone_ = true;
		clone_id_ = clone_id;
		clone_name_ = clone_name;
	}

    virtual void visit(DefinedTypeResolutionVisitor &visitor) override;

    AlternativeTypes getAlternativeTypes() const { return alternative_types_; }

private :
	AlternativeTypes alternative_types_;
	bool extensible_;
	bool is_clone_ = false;
	unsigned int clone_id_ = 0;
	std::string clone_name_;

	friend class Resolver;
};
}}}

#endif



