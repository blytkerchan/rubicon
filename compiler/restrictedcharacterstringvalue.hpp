#ifndef rubicon_compiler_restrictedcharacterstringvalue_hpp
#define rubicon_compiler_restrictedcharacterstringvalue_hpp

#include "tuple.hpp"
#include "quadruple.hpp"
#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class RestrictedCharacterStringValue : public Value
{
public :
	explicit RestrictedCharacterStringValue(SourceLocation const &source_location);
	RestrictedCharacterStringValue(RestrictedCharacterStringValue &&value);
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::string const &value);
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::vector< std::string > const &values);
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value);

	void add(std::string const &value);
	void add(std::shared_ptr< Value > const &value);
	void add(Quadruple const &value);
	void add(Tuple const &value);

	std::string getTypeName() const override;

	std::string generateInstance() const override;

private :
	std::vector< std::pair< unsigned int, std::string > > string_values_;
	std::vector< std::pair< unsigned int, std::shared_ptr< Value > > > values_;
	std::vector< std::pair< unsigned int, Quadruple > > quadruple_values_;
	std::vector< std::pair< unsigned int, Tuple > > tuple_values_;
	unsigned int next_index_ = 0;
};
}}}

#endif



