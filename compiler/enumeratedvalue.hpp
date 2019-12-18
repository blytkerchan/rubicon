#ifndef rubicon_compiler_enumeratedvalue_hpp
#define rubicon_compiler_enumeratedvalue_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class TypeDescriptor;
class EnumeratedValue : public Value
{
public :
	EnumeratedValue(SourceLocation const &source_location, std::string const &identifier, std::shared_ptr< TypeDescriptor > const &type);

	virtual std::string getTypeName() const override;

	virtual std::string generateInstance() const override;

private :
	std::string identifier_;
    std::string type_name_;
};
}}}

#endif



