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
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	if (contexts_.back().mode_ == collapse__) return shared_ptr< TypeDescriptor >();

	assert(contexts_.back().mode_ == resolve__);
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
	if (contexts_.back().mode_ == clone_if_choice__)
	{
		return make_shared(choice_type);
	}
	else
	{ /* not cloning */ }
	if (contexts_.back().mode_ == collapse__) return shared_ptr< TypeDescriptor >(); // definitely not a primitive

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
	// in order for this to work, we collapse other CHOICEs into this one.
	for (auto alternative_type : choice_type.alternative_types_)
	{
		switch (alternative_type.which())
		{
		case 0 : // NamedType
		{
			{ // clone any choices so we can re-tag them
				ScopedContext context(contexts_, clone_if_choice__);
				auto resolution_result(resolve(get< NamedType >(alternative_type)));
				assert(!resolution_result); // we don't expect the NamedType itself to clone, so resolve should return an empty shared_ptr
			}
			{ // do a general resolution pass so we apply constraints and somesuch
				resolve(get< NamedType >(alternative_type));
			}
		}
		case 1 : // VersionedTypeList
			// we don't do versioned type lists yet, so fall through to the logic error
		default :
			throw std::logic_error("Unexpected type in variant");
		}
	}
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ConstrainedType &constrained_type)
{
	switch (contexts_.back().mode_)
	{
	case clone_if_choice__ :
		// if the type being constrained is a CHOICE (which we find out by visiting it and seeing if the return
		// value is different from what we currently have as a pointer) we should transform the resulting
		// ChoiceType instance according to the constraint and return the transformed ChoiceType. If it is
		// anything else (i.e. the pointer hasn't changed) we return an empty shared_ptr
		//
		// the implementation is the same as when collapsing, so fall through
	case collapse__ :
		// if the type being constrained is a primitive (which we find out by visiting it and seeing if the return
		// value is different from what we currently have as a pointer) we should transform the resulting instance
		// according to the constraing and return the transformed type. If it is anything else (i.e. the pointer
		// hasn't changed) we return an empty shared_ptr.
		//
		// the implementation is the same as when we're cloning choices - and here it is:
	{
		auto resolution_result(resolve(constrained_type.getType()));
		if (resolution_result != constrained_type.getType())
		{
			emitWarning(constrained_type.getSourceLocation(), "don't know how to constrain types (yet) -- using unconstrained type in stead");
			return resolution_result;
		}
		else
		{
			return shared_ptr< TypeDescriptor >();
		}
	}
	case resolve__ :
		// when we're simply resolving, we should always transform the underlying resolved type according to
		// the constraint and return that. This is true regardless of where the type is w.r.t. the type
		// assignment (i.e. if it's a top-level type or part of some composite type) because we don't directly
		// generate code for constrained types, so they should no longer be in the AST when we get to generating
		// code. This implies that choices should resolve twice: once for the special treatment choices get, and
		// once for the general transformations.
		emitWarning(constrained_type.getSourceLocation(), "don't know how to constrain types (yet) -- using unconstrained type in stead");
		return resolve(constrained_type.getType());
	default :
		throw logic_error("Unexpected mode");
	}
}
shared_ptr< TypeDescriptor > Resolver::resolve(DefinedType &defined_type)
{
	// When cloning choices, we do not need to go any further than this, unless the underlying type is a CHOICE, in which case we will return a clone of the choice.
	// Regardless of what we're doing, we need to resolve the type name to make sure it exists.
	auto type_assignments(listener_->getTypeAssignments());
	auto which(find_if(type_assignments.begin(), type_assignments.end(), [=](auto type_assignment){ return type_assignment.getName() == defined_type.getTypeName(); }));
	if (which == type_assignments.end())
	{
		emitError(which->source_location_, "undefined reference to %s", defined_type.getTypeName().c_str());
		throw UndefinedReference("undefined reference");
	}
	else
	{ /* found it */ }
	switch (contexts_.back().mode_)
	{
	case clone_if_choice__ :
		// if we're cloning choices, and our defined type is a choice, we'll need to do two things:
		// 1. we need to make sure that our cloned choice is compatible with the named type (i.e. the generated class for the
		//    clone can be constructed from an instance of the generated class of the named type, and vice-versa)
		// 2. we need to make sure that the surrounding generated class returns instances of the generated (cloned) choice
		//    *as* instances of the top-level named class
		// i.e. the only difference between the clone and the top-level class should be the tags used when encoding or
		// decoding the instances.
		//
		// In order to accomplish this, we will tag the generated clone with the name of the class it was cloned from (the
		// "compatible class"). The surrounding choice type will need to generate the necessary code for those classes in its
		// implementation (and include a declaration for those classes in the private section of the class definition). We'll
		// also add a unique clone number so a choice could embed the same choice more than once if it needed to.
		//
		// We know that our defined type is a clone if the resolution results in a different pointer than the one we have.
		//TODO
		// 1. resolve the contained type
		// 2. if resolution != current pointer, we have a choice
		//    a. annotate with our type name
		//    b. annotate with our clone #
		//    c. bump the clone number
		//    d. return annotated clone
		// 3. otherwise, return empty shared_ptr
	case collapse__ :
		// if we're collapsing primitives, we only need to know whether the type we contain is a primitive (which we can ask it).
		// If so, we return it. Otherwise, we return an empty shared_ptr.
		//TODO
	case resolve__ :
		// If we're doing a "normal" resolution, we have nothing more to do - return an empty shared_ptr
		return shared_ptr< TypeDescriptor >();
	default :
		throw logic_error("Unexpected mode");
	}
}
//TODO
shared_ptr< TypeDescriptor > Resolver::resolve(EnumeratedType &enumerated_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ExternalTypeReference &external_type_reference)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(GeneralizedTimeType &generalized_time_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(IntegerType &integer_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(NamedType &named_type)
{
	// if resolving the underlying type does not return the same pointer as we had, that means it's been cloned. A named
	// type is never a top-level type, however, because that is not possible within the grammar of ASN.1 (X.680), so we
	// can safely replace what we had with the clone without cloning ourselves.
	// Note that if we are cloning (e.g. clone_if_choice__ is the current mode) this will clone.
	auto type(resolve(named_type.getType()));
	named_type.setType(type);
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(ObjectDescriptorType &object_descriptor_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(PrimitiveType &primitive_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SelectionType &selection_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SequenceOrSetType &sequence_or_set_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(SequenceOrSetOfType &sequence_or_set_of_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(TaggedType &tagged_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >(); //TODO check this- should go through the underlying type
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(TypeWithConstraint &type_with_constraint)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >(); //TODO check this- should go through the underlying type
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(UnknownType &unknown_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
	return shared_ptr< TypeDescriptor >();
}
shared_ptr< TypeDescriptor > Resolver::resolve(UTCTimeType &utc_time_type)
{
	if (contexts_.back().mode_ == clone_if_choice__) return shared_ptr< TypeDescriptor >();
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


