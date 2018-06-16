#ifndef vlinder_rubicon_compiler_valueassignment_hpp
#define vlinder_rubicon_compiler_valueassignment_hpp

#include "value.hpp"
#include <memory>
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ValueAssignment
{
public :
	ValueAssignment(SourceLocation const &source_location, std::string const &name, std::shared_ptr< Value > const &value)
		: source_location_(source_location)
		, name_(name)
		, value_(value)
	{ /* no-op */ }

	SourceLocation getSourceLocation() const { return source_location_; }
	std::string getName() const { return name_; }
	std::set< std::string > getDependencies() const { return value_->getDependencies(); }
	void generateDeclaration(std::ostream &os) const;

private :
	SourceLocation source_location_;
	std::string name_;
	std::shared_ptr< Value > value_;
};
}}}

#endif
