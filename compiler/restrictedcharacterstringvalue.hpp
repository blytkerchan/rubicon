#ifndef rubicon_compiler_restrictedcharacterstringvalue_hpp
#define rubicon_compiler_restrictedcharacterstringvalue_hpp

#include "tuple.hpp"
#include "quadruple.hpp"
#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class RestrictedCharacterStringValue : public Value
{
public :
	explicit RestrictedCharacterStringValue(SourceLocation const &source_location)
		: Value(source_location)
	{ /* no-op */ }

	RestrictedCharacterStringValue(RestrictedCharacterStringValue &&value)
		: Value(std::move(value))
		, string_values_(std::move(value.string_values_))
		, values_(std::move(value.values_))
		, quadruple_values_(std::move(value.quadruple_values_))
		, tuple_values_(std::move(value.tuple_values_))
	{ /* no-op */ }
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::string const &value)
		: Value(source_location)
	{
		string_values_.push_back(std::make_pair(next_index_++, value));
	}
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::vector< std::string > const &values)
		: Value(source_location)
	{
		for (auto value : values)
		{
			string_values_.push_back(std::make_pair(next_index_++, value));
		}
	}
	RestrictedCharacterStringValue(SourceLocation const &source_location, std::shared_ptr< Value > const &value)
		: Value(source_location)
	{
		values_.push_back(std::make_pair(next_index_++, value));
	}

	void add(std::string const &value)
	{
		string_values_.push_back(std::make_pair(next_index_++, value));
	}

	void add(std::shared_ptr< Value > const &value)
	{
		values_.push_back(std::make_pair(next_index_++, value));
	}

	void add(Quadruple const &value)
	{
		quadruple_values_.push_back(std::make_pair(next_index_++, value));
	}

	void add(Tuple const &value)
	{
		tuple_values_.push_back(std::make_pair(next_index_++, value));
	}

	std::string getTypeName() const override { return "RestrictedCharacterString"; }

private :
	std::vector< std::pair< unsigned int, std::string > > string_values_;
	std::vector< std::pair< unsigned int, std::shared_ptr< Value > > > values_;
	std::vector< std::pair< unsigned int, Quadruple > > quadruple_values_;
	std::vector< std::pair< unsigned int, Tuple > > tuple_values_;
	unsigned int next_index_ = 0;
};
}}}

#endif



