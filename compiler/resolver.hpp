#ifndef vlinder_rubicon_compiler_resolver_hpp
#define vlinder_rubicon_compiler_resolver_hpp

#include <memory>
#include <deque>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class BitStringType;
class CharacterStringType;
class ChoiceType;
class ConstrainedType;
class DefinedType;
class EnumeratedType;
class ExternalTypeReference;
class GeneralizedTimeType;
class IntegerType;
class Listener;
class NamedType;
class ObjectDescriptorType;
class PrimitiveType;
class SelectionType;
class SequenceOrSetType;
class SequenceOrSetOfType;
class TaggedType;
class TypeAssignment;
class TypeDescriptor;
class TypeWithConstraint;
class UnknownType;
class UTCTimeType;
class Value;
class ValueAssignment;
struct SourceLocation;
class Resolver
{
public :
	Resolver(Listener *listener);
	
	Resolver const& operator()(TypeAssignment &type_assignment);
	Resolver const& operator()(ValueAssignment &value_assignment);

	std::shared_ptr< TypeDescriptor > resolve(BitStringType &bit_string_type);
	std::shared_ptr< TypeDescriptor > resolve(CharacterStringType &character_string_type);
	std::shared_ptr< TypeDescriptor > resolve(ChoiceType &choice_type);
	std::shared_ptr< TypeDescriptor > resolve(ConstrainedType &constrained_type);
	std::shared_ptr< TypeDescriptor > resolve(DefinedType &defined_type);
	std::shared_ptr< TypeDescriptor > resolve(EnumeratedType &enumerated_type);
	std::shared_ptr< TypeDescriptor > resolve(ExternalTypeReference &external_type_reference);
	std::shared_ptr< TypeDescriptor > resolve(GeneralizedTimeType &generalized_time_type);
	std::shared_ptr< TypeDescriptor > resolve(IntegerType &integer_type);
	std::shared_ptr< TypeDescriptor > resolve(NamedType &named_type);
	std::shared_ptr< TypeDescriptor > resolve(ObjectDescriptorType &object_descriptor_type);
	std::shared_ptr< TypeDescriptor > resolve(PrimitiveType &primitive_type);
	std::shared_ptr< TypeDescriptor > resolve(SelectionType &selection_type);
	std::shared_ptr< TypeDescriptor > resolve(SequenceOrSetType &sequence_or_set_type);
	std::shared_ptr< TypeDescriptor > resolve(SequenceOrSetOfType &sequence_or_set_of_type);
	std::shared_ptr< TypeDescriptor > resolve(TaggedType &tagged_type);
	std::shared_ptr< TypeDescriptor > resolve(TypeWithConstraint &type_with_constraint);
	std::shared_ptr< TypeDescriptor > resolve(UnknownType &unknown_type);
	std::shared_ptr< TypeDescriptor > resolve(UTCTimeType &utc_time_type);

private :
	enum Mode {
		  resolve__		// make sure all the names resolve, and we have everything we need to generate code
		, collapse__		// collapse to the leaf primitive (has no effect on non-primitive types)
		, clone_if_choice__	// clone if the type is a CHOICE, so we can tag it
		, get_selected_type__
		};
	struct Context
	{
		Context(Mode mode, void *ptr = nullptr)
			: mode_(mode)
			, ptr_(ptr)
		{}

		Mode mode_;
		void *ptr_ = nullptr;
	};
	typedef std::deque< Context > Contexts;
	struct ScopedContext : Context
	{
		ScopedContext(Contexts &contexts, Context const &context)
			: Context(context)
			, contexts_(contexts)
		{
			contexts_.push_back(context);
		}
		~ScopedContext()
		{
			contexts_.pop_back();
		}

		Contexts &contexts_;
	};
	std::shared_ptr< TypeDescriptor > resolve(std::shared_ptr< TypeDescriptor > const &type_descriptor);
	std::shared_ptr< Value > resolve(std::shared_ptr< Value > const &value);

	static void emitWarning(SourceLocation const &source_location, char const *fmt, ...);
	static void emitError(SourceLocation const &source_location, char const *fmt, ...);

	Listener *listener_;
	Contexts contexts_;
	unsigned int next_clone_id_ = 0;
};
}}}

#endif

