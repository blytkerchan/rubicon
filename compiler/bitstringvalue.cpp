#include "bitstringvalue.hpp"
#include "bitstringtype.hpp"
#include "definedtype.hpp"
#include "directory.hpp"
#include "runtime/config.hpp"
#include "runtime/exceptions.hpp"
#include "tracing.hpp"
#include <sstream>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
BitStringValue::BitStringValue(SourceLocation const &source_location, Directory const &directory, shared_ptr< TypeDescriptor > const &type)
	: Value(source_location)
	, type_(type)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, Directory const &directory, shared_ptr< TypeDescriptor > const &type, vector< unsigned char > const &bit_string, unsigned int trailing_bits)
	: Value(source_location)
	, type_(type)
	, bit_string_(bit_string)
	, trailing_bits_(trailing_bits)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, Directory const &directory, shared_ptr< TypeDescriptor > const &type, shared_ptr< Value > const &value)
	: Value(source_location)
	, type_(type)
	, value_(value)
{ /* no-op */ }
BitStringValue::BitStringValue(SourceLocation const &source_location, Directory const &directory, shared_ptr< TypeDescriptor > const &type, vector< string > &&identifiers)
	: Value(source_location)
	, type_(type)
	, identifiers_(move(identifiers))
{
	if (!type)
	{
		tracer__->trace(true, TRACE_ERROR)("%s:%u:%u: no associated type for bit string\n", source_location.filename_.c_str(), source_location.line_, source_location.offset_);
		throw InvalidDefinition("No associated type");
	}
	else
	{ /* all is well */ }
	BitStringType::NamedBits named_bits;
	bool done(false);
	do
	{
		auto bit_string_type(dynamic_pointer_cast< BitStringType >(type_));
		auto defined_type(dynamic_pointer_cast< DefinedType >(type_));
		if (!bit_string_type && !defined_type)
		{
			tracer__->trace(true, TRACE_ERROR)("%s:%u:%u: associated type for bit string is neither a defined type nor a bit string type\n", source_location.filename_.c_str(), source_location.line_, source_location.offset_);
			throw InvalidDefinition("Wrong associated type");
		}
		else
		{ /* all is well so far */ }
		if (defined_type)
		{
			assert(!bit_string_type);
			type_ = directory.findType(defined_type->getTypeName());
		}
		else
		{
			assert(bit_string_type);
			// get list of named bits, so it survives outside the loop
			named_bits = bit_string_type->getNamedBits();
			done = true;
		}
	} while (!done);
	static_assert(RUBICON_MAX_BITS_PER_INTEGER < 65536);
	vector< unsigned short > indices;
	for (auto identifier : identifiers_)
	{
		auto which(
			find_if(
				  named_bits.begin()
				, named_bits.end()
				, [=](BitStringType::NamedBit named_bit){
						return named_bit.name_ == identifier;
					}
				)
			);
		if (which == named_bits.end())
		{
			tracer__->trace(true, TRACE_ERROR)("%s:%u:%u: bit named \"%s\" not found\n", source_location.filename_.c_str(), source_location.line_, source_location.offset_, identifier.c_str());
			throw InvalidDefinition("bit not found");
		}
		else
		{ /* all is well so far */ }
	}
}

string BitStringValue::getTypeName() const/* override*/
{
	return "BitString";
}

string BitStringValue::generateInstance() const/* override*/
{
	stringstream ss;

	if (!bit_string_.empty())
	{
		ss << "Vlinder::Rubicon::BitString({";
		bool first(true);
		for (auto bit : bit_string_)
		{
			if (!first) ss << ", ";
			ss << (int)bit;
			first = false;
		}
		ss <<"}, " << trailing_bits_ << ")"; 
	}
	else
	{
		/* If we get an identifier list, the identifiers must be
		 * associated with a bit string type, must all be associated 
		 * with the same one, must be associated with the one this 
		 * value is associated with (meaning our type must be that of 
		 * the named bit string type) and each indicate the index of 
		 * the bit that is set. All other bits are zero, and we 
		 * automatically have the same size constraint as the bit 
		 * string type we're associated with. */
		/* 22.19 The CONTAINING alternative can only be used if there 
		 * is a contents constraint on the bitstring type which 
		 * includes CONTAINING . The "Value" shall then be value 
		 * notation for a value of the "Type" in the 
		 * "ContentsConstraint" (see Rec. ITU-T X.682 | ISO/IEC 
		 * 8824-3, clause 11).
		 * NOTE – This value notation can never appear in a subtype 
		 * constraint because Rec. ITU-T X.682 | ISO/IEC 8824-3, 
		 * clause 11.3 forbids further constraints after a 
		 * "ContentsConstraint", and the above text forbids its use
		 * unless the governor has a "ContentsConstraint".
		 * 22.20 The CONTAINING alternative shall be used if there 
		 * is a contents constraint on the bitstring type which does
		 * not contain ENCODED BY. */
	}

	return ss.str();
}

}}}



