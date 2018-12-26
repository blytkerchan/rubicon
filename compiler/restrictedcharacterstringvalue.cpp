#include "restrictedcharacterstringvalue.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */RestrictedCharacterStringValue::RestrictedCharacterStringValue(SourceLocation const &source_location)
	: Value(source_location)
{ /* no-op */ }

RestrictedCharacterStringValue::RestrictedCharacterStringValue(RestrictedCharacterStringValue &&value)
	: Value(move(value))
	, string_values_(move(value.string_values_))
	, values_(move(value.values_))
	, quadruple_values_(move(value.quadruple_values_))
	, tuple_values_(move(value.tuple_values_))
{ /* no-op */ }
RestrictedCharacterStringValue::RestrictedCharacterStringValue(SourceLocation const &source_location, string const &value)
	: Value(source_location)
{
	string_values_.push_back(make_pair(next_index_++, value));
}
RestrictedCharacterStringValue::RestrictedCharacterStringValue(SourceLocation const &source_location, vector< string > const &values)
	: Value(source_location)
{
	for (auto value : values)
	{
		string_values_.push_back(make_pair(next_index_++, value));
	}
}
RestrictedCharacterStringValue::RestrictedCharacterStringValue(SourceLocation const &source_location, shared_ptr< Value > const &value)
	: Value(source_location)
{
	values_.push_back(make_pair(next_index_++, value));
}

void RestrictedCharacterStringValue::add(string const &value)
{
	string_values_.push_back(make_pair(next_index_++, value));
}

void RestrictedCharacterStringValue::add(shared_ptr< Value > const &value)
{
	values_.push_back(make_pair(next_index_++, value));
}

void RestrictedCharacterStringValue::add(Quadruple const &value)
{
	quadruple_values_.push_back(make_pair(next_index_++, value));
}

void RestrictedCharacterStringValue::add(Tuple const &value)
{
	tuple_values_.push_back(make_pair(next_index_++, value));
}

string RestrictedCharacterStringValue::getTypeName() const/* override*/
{
	return "RestrictedCharacterString";
}

string RestrictedCharacterStringValue::generateInstance() const/* override*/
{
	return "/*TODO*/";
}

}}}


