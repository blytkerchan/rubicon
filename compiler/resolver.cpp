#include "resolver.hpp"
#include "valueassignment.hpp"
#include "typeassignment.hpp"
#include "bitstringtype.hpp"
#include "choicetype.hpp"
#include "integertype.hpp"
#include "integervalue.hpp"
#include "listener.hpp"
#include "../exceptions.hpp"
#include "../tracing.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Resolver::Resolver(Listener *listener)
	: listener_(listener)
{ /* no-op */ }

Resolver const& Resolver::operator()(TypeAssignment &type_assignment)
{
	ScopedContext context(contexts_, resolve__);
	type_assignment.setTypeDescriptor(resolve(type_assignment.getTypeDescriptor()));
	return *this;
}
Resolver const& Resolver::operator()(ValueAssignment &value_assignment)
{
	ScopedContext context(contexts_, resolve__);
	value_assignment.setValue(resolve(value_assignment.getValue()));
	return *this;
}
shared_ptr< TypeDescriptor > Resolver::resolve(BitStringType &bit_string_type)
{
	// The behavior for resolving a bit string is the same if we're resolving or collapsing: in either case, we end
	// up with a bit string and we collapse the values in it down to their numeric equivalents. We therefore do not
	// clone in either case.
	
	// recursion detection
	if (find_if(contexts_.begin(), contexts_.end(), [&](auto context){ return context.ptr_ == &bit_string_type; }) != contexts_.end())
	{
		emitError(bit_string_type.getSourceLocation(), "Recursive BIT STRING definition detected");
		throw RecursiveDefinition("Recursive BIT STRING");
	}
	else
	{ /* all is well */ }
	ScopedContext context(contexts_, Context(contexts_.back().mode_, &bit_string_type));
	
	bool done(false);
	do
	{
		// this could be more efficient, by picking up where we left off, but the code would be more complex and this is mostly a one-shot deal
		auto which(
			  find_if(
				  bit_string_type.named_bits_.begin()
				, bit_string_type.named_bits_.end()
				, [](auto named_bit){ return named_bit.bit_ == numeric_limits< unsigned int >::max(); }
				)
			);
		if (which != bit_string_type.named_bits_.end())
		{
			auto value_assignments(listener_->getValueAssignments());
			auto name(which->name_);
			auto value_assignment(find_if(value_assignments.begin(), value_assignments.end(), [name](auto value_assignment){ return value_assignment.getName() == name; }));
			if (value_assignment != value_assignments.end())
			{
				// we now have a value assignment for the name, but we need to make sure it's an integer of some sort before we go
				// any further. Integers come in several shapes and sizes, so we should not expect the type here to directly be an
				// integer: it may well be a NamedType that is a NamedType that is .... an integer. If that is the case, however, 
				// resolving it should get us where we need to be.
				// Note that if the user had the bad taste of doing a recursive construct of some sort, we might crash.
				// something like
				//     MyBitString ::= BIT STRING (my-value)
				//     my-value MyBitString ::= my-value
				// would do that. We can take care of this (later) by doing a proper dependency analysis and bail out if there are
				// any circular dependencies.
				ScopedContext context(contexts_, collapse__);
				auto type(resolve(value_assignment->getType()));
				if (dynamic_pointer_cast< IntegerType >(type))
				{
					// now that we know that it's an integer, we have to resolve the value itself so we can get to a literal
					auto value(resolve(value_assignment->getValue()));
					auto integer_value(dynamic_pointer_cast< IntegerValue >(value));
					if (integer_value)
					{
						if (integer_value->getValue() < 0)
						{
							emitError(which->source_location_, "%s refers to a negative integer value", name.c_str());
							throw UndefinedReference("undefined reference");
						}
						else if (integer_value->getValue() >= numeric_limits< unsigned int >::max())
						{
							emitError(which->source_location_, "%s refers to an integer value that is too large", name.c_str());
							throw UndefinedReference("undefined reference");
						}
						else
						{
							which->bit_ = (decltype(which->bit_))integer_value->getValue();
						}
					}
					else
					{
						emitError(which->source_location_, "%s does not refer to an integer value", name.c_str());
						throw UndefinedReference("undefined reference");
					}
				}
				else
				{
					emitError(which->source_location_, "%s does not refer to an integer value", name.c_str());
					throw UndefinedReference("undefined reference");
				}
			}
			else
			{
				emitError(which->source_location_, "undefined reference to %s", name.c_str());
				throw UndefinedReference("undefined reference");
			}
		}
		else
		{
			done = true;
		}
	} while (!done);
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(CharacterStringType &character_string_type)
{
	// For character strings, the Listener does everything that needs to be done
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ChoiceType &choice_type)
{
	// The goal of resolution here is to ascertain that all the types in the choice type have a unique tag. For that to
	// be the case, they must be tagged either using their user-provided (textual) tag or using automatic tags.
	// This means we have a number of steps to go through:
	// 1. resolve all the types in the choice
	// 2. determine whether any of the types in the choice have a textual tag
	// 3. if not, determine whether automatic tagging is active
	// 3a. if automatic tagging is active and none of the types have a textual tag, re-tag everything
	// 4. ascertain that the tags of all the types in the choice are unique
	// Again, we have a potential problem with recursion here...
	// Note that the tag we assign here overrides the tag of the type we're choosing (X.690 clause 8.1.2.6) and that
	// the CHOICE itself does not emit a tag (X.690 clause 8.13).
	// In order for this to work, 
	for (auto alternative_type : choice_type.alternative_types_)
	{
		switch (alternative_type.which())
		{
		case 0 : // NamedType
		{
			ScopedContext context(contexts_, collapse__);
			auto resolved(resolve(get< NamedType >(alternative_type)));
			auto embedded_choice(dynamic_pointer_cast< ChoiceType >(resolved));

		}
		case 1 : // VersionedTypeList
		default :
			throw std::logic_error("Unexpected type in variant");
		}
	}
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ConstrainedType &constrained_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(DefinedType &defined_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(EnumeratedType &enumerated_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ExternalTypeReference &external_type_reference)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(GeneralizedTimeType &generalized_time_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(IntegerType &integer_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(NamedType &named_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ObjectDescriptorType &object_descriptor_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(PrimitiveType &primitive_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SelectionType &selection_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SequenceOrSetType &sequence_or_set_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SequenceOrSetOfType &sequence_or_set_of_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(TaggedType &tagged_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(TypeWithConstraint &type_with_constraint)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(UnknownType &unknown_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(UTCTimeType &utc_time_type)
{
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(shared_ptr< TypeDescriptor > const &type_descriptor)
{
	auto retval(type_descriptor->visit(*this));
	return retval ? retval : type_descriptor;
}
shared_ptr< Value > Resolver::resolve(shared_ptr< Value > const &value)
{
	return value;
	//return value.visit(*this);
}
/*static */void Resolver::emitError(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
}}}



