#ifndef rubicon_compiler_value_hpp
#define rubicon_compiler_value_hpp

#include <set>
#include <string>
#include "sourcelocation.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct Value
{
	Value(SourceLocation const &source_location)
		: source_location_(source_location)
	{ /* no-op */ }
	virtual std::set< std::string > getDependencies() const { return std::set< std::string >(); }
	virtual std::string getTypeName() const = 0;

	SourceLocation source_location_;
};
}}}

#endif



