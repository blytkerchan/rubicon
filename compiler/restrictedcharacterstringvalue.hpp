#ifndef rubicon_compiler_restrictedcharacterstringvalue_hpp
#define rubicon_compiler_restrictedcharacterstringvalue_hpp

#include "tuple.hpp"
#include "quadruple.hpp"
#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct RestrictedCharacterStringValue : Value
{
	RestrictedCharacterStringValue() = default;
	RestrictedCharacterStringValue(RestrictedCharacterStringValue &&value)
		: string_values_(std::move(value.string_values_))
		, values_(std::move(value.values_))
		, quadruple_values_(std::move(value.quadruple_values_))
		, tuple_values_(std::move(value.tuple_values_))
	{ /* no-op */ }
	RestrictedCharacterStringValue(std::string const &value)
	{
		string_values_.push_back(std::make_pair(next_index_++, value));
	}
	RestrictedCharacterStringValue(std::vector< std::string > const &values)
	{
		for(auto value : values)
		{
			string_values_.push_back(std::make_pair(next_index_++, value));
		}
	}
	RestrictedCharacterStringValue(std::shared_ptr< Value > const &value)
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

	std::vector< std::pair< unsigned int, std::string > > string_values_;
	std::vector< std::pair< unsigned int, std::shared_ptr< Value > > > values_;
	std::vector< std::pair< unsigned int, Quadruple > > quadruple_values_;
	std::vector< std::pair< unsigned int, Tuple > > tuple_values_;
	unsigned int next_index_ = 0;
};
}}}

#endif



