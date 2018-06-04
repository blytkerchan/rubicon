#ifndef vlinder_rubicon_compiler_type_assignment_hpp
#define vlinder_rubicon_compiler_type_assignment_hpp

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include "typedescriptor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeAssignment
{
public :
	TypeAssignment(std::string const &name, std::shared_ptr< TypeDescriptor > const &type_descriptor)
		: name_(name)
		, type_descriptor_(type_descriptor)
	{ /* no-op */ }

	std::string getName() const { return name_; }
	std::set< std::string > getDependencies() const { return type_descriptor_->getDependencies(); }
	std::set< std::string > getStrongDependencies() const { return type_descriptor_->getStrongDependencies(); }
	std::set< std::string > getWeakDependencies() const { return type_descriptor_->getWeakDependencies(); }
	void generateHeader(std::ostream &os) const;
	void generateImplementation(std::ostream &os) const;

private :
	std::string name_;
	std::shared_ptr< TypeDescriptor > type_descriptor_;
};
}}}

#endif
