#include "bitstringvalue.hpp"
#include <sstream>
#include <iterator>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */BitStringValue::BitStringValue(SourceLocation const &source_location)
	: Value(source_location)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, vector< unsigned char > const &bit_string, unsigned int trailing_bits)
	: Value(source_location)
	, bit_string_(bit_string)
	, trailing_bits_(trailing_bits)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, shared_ptr< Value > const &value)
	: Value(source_location)
	, value_(value)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, vector< string > &&identifiers)
	: Value(source_location)
	, identifiers_(move(identifiers))
{ /* no-op */ }

string BitStringValue::getTypeName() const/* override*/
{
	return "BitString";
}

string BitStringValue::generateInstance() const/* override*/
{
	stringstream ss;

	ss << "Vlinder::Rubicon::BitString({";
	if (!bit_string_.empty())
	{
		ostream_iterator< int > out_it(ss, ", ");
		copy(bit_string_.begin(), bit_string_.end(), out_it);
	}
	ss <<"}, " << trailing_bits_ << ")"; 

	return ss.str();
}

}}}



