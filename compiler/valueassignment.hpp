#ifndef vlinder_rubicon_compiler_valueassignment_hpp
#define vlinder_rubicon_compiler_valueassignment_hpp

#include "value.hpp"
#include <memory>
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeDescriptor;
class ValueAssignment
{
public :
	ValueAssignment(SourceLocation const &source_location, std::string const &name, std::shared_ptr< TypeDescriptor > const &type, std::shared_ptr< Value > const &value)
		: source_location_(source_location)
		, name_(name)
		, type_(type)
		, value_(value)
	{ /* no-op */ }

	SourceLocation getSourceLocation() const { return source_location_; }
	std::string getName() const { return name_; }
	std::set< std::string > getDependencies() const { return value_->getDependencies(); }
	void generateDeclaration(std::ostream &os) const;
	void setType(std::shared_ptr< TypeDescriptor > const &type) { type_ = type; }
	std::shared_ptr< TypeDescriptor > getType() { return type_; }
	void setValue(std::shared_ptr< Value > const &value) { value_ = value; }
	std::shared_ptr< Value > getValue() const { return value_; }

private :
	SourceLocation source_location_;
	std::string name_;
	std::shared_ptr< TypeDescriptor > type_;
	std::shared_ptr< Value > value_;
};
}}}

#endif
