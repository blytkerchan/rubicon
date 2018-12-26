#ifndef rubicon_compiler_namedvalue_hpp
#define rubicon_compiler_namedvalue_hpp

#include "value.hpp"
#include <string>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class NamedValue : public Value
{
public :
	explicit NamedValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }
	NamedValue(SourceLocation const &source_location, std::string const &name, std::shared_ptr< Value > const &value)
		: Value(source_location)
		, name_(name)
		, value_(value)
	{ /* no-op */ }

	std::string getTypeName() const override { return typeid(*this).name(); }

	std::string generateInstance() const override { return "/*TODO*/"; }

private :
	std::string name_;
	std::shared_ptr< Value > value_;
};
}}}

#endif



