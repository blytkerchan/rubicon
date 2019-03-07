#ifndef rubicon_compiler_value_hpp
#define rubicon_compiler_value_hpp

#include <set>
#include <string>
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Value
{
public :
	Value(SourceLocation const &source_location)
		: source_location_(source_location)
	{ /* no-op */ }
	virtual void addDependency(std::string const &dependency)
	{
		dependencies_.insert(dependency);
	}
	virtual std::set< std::string > getDependencies() const { return dependencies_; }
	virtual std::string getTypeName() const = 0;

	virtual std::string generateInstance() const = 0;
	SourceLocation getSourceLocation() const { return source_location_; }

	SourceLocation source_location_;

private:
	std::set< std::string > dependencies_;
};
}}}

#endif



