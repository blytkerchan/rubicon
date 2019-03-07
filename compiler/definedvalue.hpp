#ifndef rubicon_compiler_definedvalue_hpp
#define rubicon_compiler_definedvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class DefinedValue : public Value
{
public :
	DefinedValue(SourceLocation const &source_location, std::string const &name)
		: Value(source_location)
		, name_(name)
	{ /* no-op */ }

	bool operator==(DefinedValue const &other) const
	{
		return name_ == other.name_;
	}

	std::string getTypeName() const override { return typeid(*this).name(); }
	std::string generateInstance() const override { return name_; /*TODO may need some formatting*/ }
	std::string getValueName() const { return name_; }

private :
	std::string name_;
};
}}}

#endif



