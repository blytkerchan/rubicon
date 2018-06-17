#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

#include <set>
#include <string>
#include <iostream>
#include "resolver.hpp"
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeDescriptor
{
public :
	TypeDescriptor(SourceLocation const &source_location)
		: source_location_(source_location)
	{ /* no-op */ }
	virtual bool requireExplicitTag() const { return false; }
	virtual bool hasTypeName() const { return false; }
	virtual std::string getTypeName() const { return std::string(); }
	virtual std::set< std::string > getDependencies() const { return std::set< std::string >(); }
	virtual std::set< std::string > getStrongDependencies() const { return getDependencies(); }
	virtual std::set< std::string > getWeakDependencies() const { return std::set< std::string >(); }
	virtual void generateEncodeImplementation(std::ostream &os) const;
	virtual void generateEncodeImplementation(std::ostream &os, std::string const &instance_name) const;
	virtual void generateEventHandlers(std::ostream &os) const {};
	virtual void generateDataMembers(std::ostream &os) const;
	virtual bool hasOptionalMembers() const { return false; }
	virtual void generateHeaderGettersAndSetters(std::ostream &os) const {}
	virtual void generateMemberDeclarations(std::ostream &os) const {}
	virtual void generateCopyConstructorImplementation(std::ostream &os) const {}
	virtual void generateDestructorImplementation(std::ostream &os) const {}
	virtual void generateSwapparatorImplementation(std::ostream &os) const {}
	virtual void generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const {}

	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) = 0;

	SourceLocation getSourceLocation() const { return source_location_; }

private :
	SourceLocation source_location_;
};
}}}

#endif



