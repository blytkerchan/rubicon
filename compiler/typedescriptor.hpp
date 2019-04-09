#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

#include <set>
#include <string>
#include <iostream>
#include "resolver.hpp"
#include "sourcelocation.hpp"
#include "tag.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct StateMachine;
class TypeDescriptor
{
public :
	TypeDescriptor(SourceLocation const &source_location)
		: source_location_(source_location)
	{ /* no-op */ }
	virtual bool requireExplicitTag() const { return false; }
	virtual Tag getTag() const = 0;
	virtual void setTag(Tag const &tag);
	virtual bool tagged() const { return true; };
	virtual bool hasTypeName() const { return false; }
	virtual std::string getTypeName() const { return std::string(); }
	virtual std::set< std::string > getDependencies() const { return std::set< std::string >(); }
	virtual std::set< std::string > getStrongDependencies() const { return getDependencies(); }
	virtual std::set< std::string > getWeakDependencies() const { return std::set< std::string >(); }
	virtual std::vector< std::string > getPublicParents() const { return std::vector< std::string >(); }
	virtual std::vector< std::string > getProtectedParents() const { return std::vector< std::string >(); }
	virtual std::vector< std::string > getPrivateParents() const { return std::vector< std::string >(); }
	virtual void generateAlternateConstructorDeclarations(std::ostream &os, std::string const &class_name) const {}
	virtual void generateAlternateConstructorImplementations(std::ostream &os, std::string const &class_name) const {}
	virtual void generateEncodeImplementation(std::ostream &os) const;
	virtual void generateEventHandlers(std::ostream &os) const {};
	virtual void generateDataMembers(std::ostream &os) const;
	virtual bool hasOptionalMembers() const { return false; }
	virtual void generateHeaderGettersAndSetters(std::ostream &os) const {}
	virtual void generateMemberDeclarations(std::ostream &os) const {}
	virtual void generateCopyConstructorImplementation(std::ostream &os) const {}
	virtual void generatePublicStaticMembers(std::ostream &os) const {}
	virtual void generateDestructorImplementation(std::ostream &os) const {}
	virtual void generateSwapparatorImplementation(std::ostream &os) const {}
	virtual void generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const {}
	virtual void generateCompareImplementation(std::ostream &os) const {}

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) = 0;

	SourceLocation getSourceLocation() const { return source_location_; }

	std::shared_ptr< StateMachine > getStateMachine() const { return state_machine_; }
	void setStateMachine(StateMachine const &state_machine);

private :
	SourceLocation source_location_;
	std::shared_ptr< StateMachine > state_machine_;
};
}}}

#endif



