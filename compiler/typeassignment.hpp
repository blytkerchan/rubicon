#ifndef vlinder_rubicon_compiler_type_assignment_hpp
#define vlinder_rubicon_compiler_type_assignment_hpp

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include "typedescriptor.hpp"
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeAssignment
{
public :
	TypeAssignment(SourceLocation const &source_location, std::string const &name, std::shared_ptr< TypeDescriptor > const &type_descriptor)
		: source_location_(source_location)
		, name_(name)
		, type_descriptor_(type_descriptor)
	{ /* no-op */ }

	SourceLocation getSourceLocation() const { return source_location_; }
	std::string getName() const { return name_; }
	std::shared_ptr< TypeDescriptor > getType() const { return type_descriptor_; }
	void setType(std::shared_ptr< TypeDescriptor > const &type_descriptor) { type_descriptor_ = type_descriptor; }
	std::set< std::string > getDependencies() const { return type_descriptor_->getDependencies(); }
	std::set< std::string > getStrongDependencies() const { return type_descriptor_->getStrongDependencies(); }
	std::set< std::string > getWeakDependencies() const { return type_descriptor_->getWeakDependencies(); }
	std::vector< std::string > getPublicParents() const { return type_descriptor_->getPublicParents(); }
	std::vector< std::string > getProtectedParents() const { return type_descriptor_->getProtectedParents(); }
	std::vector< std::string > getPrivateParents() const { return type_descriptor_->getPrivateParents(); }
	bool hasOptionalMembers() const { return type_descriptor_->hasOptionalMembers(); }
	void generateAlternateConstructorDeclarations(std::ostream &os) const { type_descriptor_->generateAlternateConstructorDeclarations(os, name_); }
	void generateHeaderGettersAndSetters(std::ostream &os) const { type_descriptor_->generateHeaderGettersAndSetters(os); }
	void generateMemberDeclarations(std::ostream &os) const { type_descriptor_->generateMemberDeclarations(os); }
	void generateCopyConstructorImplementation(std::ostream &os) const;
	void generateAlternateConstructorImplementations(std::ostream &os) const;
	void generateDestructorImplementation(std::ostream &os) const;
	void generateAssignmentOperatorImplementation(std::ostream &os) const;
	void generateSwapparatorImplementation(std::ostream &os) const;
	void generateGetterAndSetterImplementations(std::ostream &ofs) const;

private :
	SourceLocation source_location_;
	std::string name_;
	std::shared_ptr< TypeDescriptor > type_descriptor_;
};
}}}

#endif
