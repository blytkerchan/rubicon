#ifndef rubicon_compiler_typedescriptor_hpp
#define rubicon_compiler_typedescriptor_hpp

#include <set>
#include <string>
#include <iostream>

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct TypeDescriptor
{
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
	virtual void generateConstructorImplementations(std::ostream &os) const {}
};
}}}

#endif



