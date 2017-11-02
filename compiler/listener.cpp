#include "listener.hpp"
#include "bitstringtype.hpp"
#include "bitstringvalue.hpp"
#include "characterstringtype.hpp"
#include "choicetype.hpp"
#include "constrainedtype.hpp"
#include "definedtype.hpp"
#include "enumeratedtype.hpp"
#include "externaltypereference.hpp"
#include "generalizedtimetype.hpp"
#include "integertype.hpp"
#include "objectdescriptortype.hpp"
#include "primitivetype.hpp"
#include "selectiontype.hpp"
#include "sequenceorsetoftype.hpp"
#include "sequenceorsettype.hpp"
#include "taggedtype.hpp"
#include "typewithconstraint.hpp"
#include "unknowntype.hpp"
#include "utctimetype.hpp"
#include "../exceptions.hpp"
#include "../exceptions/contract.hpp"
#include "../tracing.hpp"
#include <algorithm>
#include <limits>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Listener::Listener(string const &namespace_prefix, string const &namespace_suffix)
	: namespace_prefix_(namespace_prefix)
	, namespace_suffix_(namespace_suffix)
{ /* no-op */ }

/*virtual */void Listener::exitModule_identifier(asn1Parser::Module_identifierContext *ctx)/* override*/
{
	pre_condition(ctx);
	pre_condition(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
	module_namespace_ = namespace_prefix_ + ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText() + namespace_suffix_;
	tracer__->trace(1, TRACE_INFO, "Will be using namespace name %s\n", module_namespace_.c_str());
	module_definitive_identification_ = ctx->definitive_identification();
}

/*virtual */void Listener::exitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->ENCODING_REFERENCE())
	{
		if (ctx->ENCODING_REFERENCE()->getText() != "TAG")
		{
			emitWarning(ctx->ENCODING_REFERENCE(), "encoding reference \"%s\" specified. We only implement DER (\"TAG\" encoding reference).", ctx->ENCODING_REFERENCE()->getText().c_str());
		}
		else
		{ /* nothing to warn about */ }
	}
	else
	{ /* definitely nothing to warn about */ }
}

/*virtual */void Listener::exitExplicit_tags(asn1Parser::Explicit_tagsContext *ctx)/* override*/
{
	tag_default_ = TagDefault::explicit_tags__;
}
/*virtual */void Listener::exitImplicit_tags(asn1Parser::Implicit_tagsContext *ctx)/* override*/
{
	tag_default_ = TagDefault::implicit_tags__;
}
/*virtual */void Listener::exitAutomatic_tags(asn1Parser::Automatic_tagsContext *ctx)/* overrid*/
{
	tag_default_ = TagDefault::automatic_tags__;
}
/*virtual */void Listener::exitExtension_default(asn1Parser::Extension_defaultContext *ctx)/* override*/
{
	pre_condition(ctx);
	module_types_extensibility_implied_ = (ctx->EXTENSIBILITY_RW() && ctx->IMPLIED_RW());
}
/*virtual */void Listener::exitEncoding_control_section(asn1Parser::Encoding_control_sectionContext *ctx)/* override*/
{
	pre_condition(ctx);
	pre_condition(ctx->ENCODING_REFERENCE());
	if (ctx->ENCODING_REFERENCE()->getText() != "TAG")
	{
		emitWarning(ctx->ENCODING_REFERENCE(), "encoding reference \"%s\" specified. We only implement DER (\"TAG\" encoding reference).", ctx->ENCODING_REFERENCE()->getText().c_str());
	}
	else
	{
		emitWarning(ctx->ENCODING_REFERENCE(), "encoding reference \"TAG\" specified. According to X.680-201508 this is not allowed in this context.");
	}
}
/*virtual */void Listener::exitExports(asn1Parser::ExportsContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->symbols_exported())
	{
		if (ctx->symbols_exported()->symbol_list())
		{
			auto symbols(ctx->symbols_exported()->symbol_list()->symbol());
			if (symbols.empty())
			{
				emitWarning(ctx, "EXPORTS clause without any symbols to export.");
			}
			transform(symbols.begin(), symbols.end(), back_inserter(symbols_to_export_), [](auto symbol) -> string { assert(symbol); return symbol->getText(); });
		}
		else
		{
			emitWarning(ctx, "EXPORTS clause without any symbols to export");
		}
	}
	else if (ctx->ALL_RW())
	{
		export_all_ = true;
	}
	else
	{ /* no exports clause */ }
	//TODO when done parsing, make sure all of these symbols are defined in this module.
	//     also generate a header file with the exported symbols
	//     also tag the classes for export (so they'll be visible from a DLL or DSO)
}
/*virtual */void Listener::exitImports(asn1Parser::ImportsContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->symbols_imported() && ctx->symbols_imported()->symbols_from_module_list())
	{
		auto symbols_from_modules(ctx->symbols_imported()->symbols_from_module_list()->symbols_from_module());
		for (auto symbols_from_module : symbols_from_modules)
		{
			// the module being referred to is known by two names: the
			// TYPE_REFERENCE_OR_MODULE_REFERENCE, which is the name that will be
			// used in this module, and the assigned_identifier, which is  optional
			// and presumed to be the TYPE_REFERENCE_OR_MODULE_REFERENCE if absent. If
			// it is not absent, it is either an OID or a defined_value. If it's an OID,
			// that OID will correspond to the OID of the module being imported, which
			// may have another name than what's given here. If it's a defined_value,
			// that will be the name we expect the module to have.
			// In any case, symbols from this module will be referred to by the
			// TYPE_REFERENCE_OR_MODULE_REFERENCE name in this module, not by whatever
			// other name it  may have.
			assert(symbols_from_module);
			assert(symbols_from_module->global_module_reference());
			assert(symbols_from_module->global_module_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE());
			ModuleNameMappings::LocalName local_name(symbols_from_module->global_module_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText());
			// Check that there are no two modules being imported from with the same name
			if (module_name_mappings_.exists(local_name))
			{
				emitWarning(symbols_from_module, "duplicate module name \"%s\"", local_name.c_str());
			}
			else
			{ /* OK, it's unique */ }
			if (symbols_from_module->global_module_reference()->assigned_identifier())
			{
				if (symbols_from_module->global_module_reference()->assigned_identifier()->object_identifier_value())
				{
					module_name_mappings_.insert(local_name, parseObjectIdentifier(symbols_from_module->global_module_reference()->assigned_identifier()->object_identifier_value()));
				}
				else
				{
					assert(symbols_from_module->global_module_reference()->assigned_identifier()->defined_value());
					module_name_mappings_.insert(local_name, parseDefinedValue(symbols_from_module->global_module_reference()->assigned_identifier()->defined_value()));
				}
			}
			else
			{
				module_name_mappings_.insert(local_name, ModuleNameMappings::AssignedIdentifier(local_name));
			}

			assert(symbols_from_module->symbol_list());
			auto symbols(symbols_from_module->symbol_list()->symbol());
			vector< string > symbol_names;
			transform(symbols.begin(), symbols.end(), back_inserter(symbol_names), [](auto symbol){ assert(symbol); return symbol->getText(); });
			imported_symbols_.insert(ImportedSymbols::value_type(local_name, symbol_names));
		}
	}
	else
	{ /* no imports clause */ }
}
/*virtual */void Listener::exitAssignment_list(asn1Parser::Assignment_listContext *ctx)/* override*/
{
	pre_condition(ctx);
	for (auto assignment : ctx->assignment())
	{
		assert(assignment);
		if (assignment->type_assignment())
		{
			auto type_assignment(parseTypeAssignment(assignment->type_assignment()));
			type_assignments_.push_back(type_assignment);
		}
		else if (assignment->value_assignment())
		{
		}
		else
		{
			assert(assignment->value_set_type_assignment());
		}
	}
}
ObjectIdentifier Listener::parseObjectIdentifier(asn1Parser::Object_identifier_valueContext *ctx)
{
	pre_condition(ctx);

	ObjectIdentifier retval;
	auto list(ctx->obj_id_components_list());
	if (list)
	{
		auto components(list->obj_id_components());
		if (components.empty())
		{
			emitWarning(ctx, "empty OID");
		}
		else
		{ /* nothing to warn about */ }
		for (auto component : components)
		{
			assert(component);
			if (component->name_form())
			{
				retval.push_back(component->name_form()->getText());
			}
			else if (component->number_form())
			{
				retval.push_back(parseNumber(component->number_form()->NUMBER()));
			}
			else if (component->name_and_number_form())
			{
				assert(component->name_and_number_form()->number_form());
				assert(component->name_and_number_form()->number_form()->NUMBER());
				assert(component->name_and_number_form()->IDENTIFIER() || component->name_and_number_form()->TYPE_REFERENCE_OR_MODULE_REFERENCE());
				string identifier(
					  component->name_and_number_form()->IDENTIFIER()
					? component->name_and_number_form()->IDENTIFIER()->getText()
					: component->name_and_number_form()->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText()
					);
				retval.push_back(make_pair(identifier, parseNumber(component->name_and_number_form()->number_form()->NUMBER())));
			}
			else
			{
				assert(component->defined_value());
				auto parsed_defined_value(parseDefinedValue(component->defined_value()));
				auto typed_parsed_defined_value(static_cast< DefinedValue const& >(*parsed_defined_value));
				retval.push_back(typed_parsed_defined_value);
			}
		}
	}
	else
	{
		emitWarning(ctx, "empty OID");
	}

	return retval;
}
unsigned int Listener::parseNumber(antlr4::tree::TerminalNode *node)
{
	pre_condition(node);
	string text(node->getText());
	assert(!text.empty());
	unsigned int retval(0);
	if ((text[0] == '0') && (text.size() != 1))
	{
		emitWarning(node, "leading zeroes will be ignored.");
	}
	for (auto c : text)
	{
		assert((c >= '0') && (c <= '9'));
		retval *= 10;
		retval += (c - '0');
	}

	return retval;
}

Listener::TypeAssignment Listener::parseTypeAssignment(asn1Parser::Type_assignmentContext *ctx)
{
	pre_condition(ctx);
	pre_condition(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
	pre_condition(ctx->type());
	string name(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText());
	auto type(parseType(ctx->type()));
	return TypeAssignment(name, type);
}

shared_ptr< TypeDescriptor > Listener::parseType(asn1Parser::TypeContext *ctx)
{
	pre_condition(ctx);
	return
		  ctx->builtin_type() ? parseBuiltinType(ctx->builtin_type())
		: ctx->referenced_type()
			? ctx->referenced_type()->defined_type()		? parseDefinedType(ctx->referenced_type()->defined_type())
			: ctx->referenced_type()->useful_type()			? parseUsefulType(ctx->referenced_type()->useful_type())
			: ctx->referenced_type()->selection_type()		? parseSelectionType(ctx->referenced_type()->selection_type())

		: ctx->constrained_type()	? parseContrainedType(ctx->constrained_type())
		: make_shared< UnknownType >()
		: make_shared< UnknownType >()
		;
}
shared_ptr< TypeDescriptor > Listener::parseBuiltinType(asn1Parser::Builtin_typeContext *ctx)
{
	return ctx->bit_string_type()			? parseBitStringType(ctx->bit_string_type())
		: ctx->BOOLEAN_RW()			? make_shared< PrimitiveType >(PrimitiveType::boolean__)
		: ctx->character_string_type()		? parseCharacterStringType(ctx->character_string_type())
		: ctx->choice_type()			? parseChoiceType(ctx->choice_type())
		: ctx->DATE_RW()			? make_shared< PrimitiveType >(PrimitiveType::date__)
		: ctx->DATE_TIME_RW()			? make_shared< PrimitiveType >(PrimitiveType::date_time__)
		: ctx->DURATION_RW()			? make_shared< PrimitiveType >(PrimitiveType::duration__)
		: (ctx->EMBEDDED_RW() && ctx->PDV_RW()) ? make_shared< PrimitiveType >(PrimitiveType::embedded_pdv__)
		: ctx->enumerated_type()		? parseEnumeratedType(ctx->enumerated_type())
		: ctx->EXTERNAL_RW()			? make_shared< PrimitiveType >(PrimitiveType::external__)
		: ctx->integer_type()			? parseIntegerType(ctx->integer_type())
		: ctx->OID_IRI_RW()			? make_shared< PrimitiveType >(PrimitiveType::oid_iri__)
		: ctx->NULL_RW()			? make_shared< PrimitiveType >(PrimitiveType::null__)
		: (ctx->OBJECT_RW() && ctx->IDENTIFIER_RW()) ? make_shared< PrimitiveType >(PrimitiveType::object_identifier__)
		: (ctx->OCTET_RW() && ctx->STRING_RW()) ? make_shared< PrimitiveType >(PrimitiveType::octet_string__)
		: ctx->RELATIVE_OID_IRI_RW()		? make_shared< PrimitiveType >(PrimitiveType::relative_oid_iri__)
		: ctx->RELATIVE_OID_RW()		? make_shared< PrimitiveType >(PrimitiveType::relative_oid__)
		: ctx->sequence_or_set_type()		? parseSequenceOrSetType(ctx->sequence_or_set_type())
		: ctx->sequence_or_set_of_type()	? parseSequenceOrSetOfType(ctx->sequence_or_set_of_type())
		: ctx->prefixed_type()			? parsePrefixedType(ctx->prefixed_type())
		: ctx->TIME_RW()			? make_shared< PrimitiveType >(PrimitiveType::time__)
		: ctx->TIME_OF_DAY_RW()			? make_shared< PrimitiveType >(PrimitiveType::time_of_day__)
		: shared_ptr< TypeDescriptor >(make_shared< UnknownType >()) // the explicit construction is a hint for the compiler to resolve the types in the tree of ternary operators
		;
}
shared_ptr< TypeDescriptor > Listener::parseBitStringType(asn1Parser::Bit_string_typeContext *ctx)
{
	pre_condition(ctx);
	BitStringType::NamedBits named_bits;
	if (ctx->named_bit_list())
	{
		for (auto named_bit : ctx->named_bit_list()->named_bit())
		{
			assert(named_bit);
			assert(named_bit->IDENTIFIER());
			auto name(named_bit->IDENTIFIER()->getText());
			if (named_bit->NUMBER())
			{
				unsigned int value(parseNumber(named_bit->NUMBER()));
				if (find_if(named_bits.begin(), named_bits.end(), [value](auto named_bit){ return named_bit.second == value; }) != named_bits.end())
				{
					emitError(ctx, "more than one name for bit %u", value);
					throw ParseError("more than one name for bit");
				}
				else
				{ /* all is well so far */ }
				named_bits.push_back(make_pair(name, value));
			}
			else
			{
				emitWarning(ctx, "using defined values for named bits is not supported. Bit name ignored.");
			}
		}
	}
	else
	{ /* no named bits */ }
	return make_shared< BitStringType >(named_bits);
}
std::shared_ptr< TypeDescriptor > Listener::parseCharacterStringType(asn1Parser::Character_string_typeContext *ctx)
{
	pre_condition(ctx);
	if (ctx->unrestricted_character_string_type())
	{
		return make_shared< CharacterStringType >();
	}
	else
	{
		assert(ctx->restricted_character_string_type());
		return make_shared< CharacterStringType >(ctx->restricted_character_string_type()->getText());
	}
}

std::shared_ptr< TypeDescriptor > Listener::parseChoiceType(asn1Parser::Choice_typeContext *ctx)
{
	pre_condition(ctx);
	pre_condition(ctx->alternative_type_lists());
	pre_condition(ctx->alternative_type_lists()->root_alternative_type_list());
	pre_condition(ctx->alternative_type_lists()->root_alternative_type_list()->alternative_type_list());
	vector< boost::variant< NamedType, VersionedTypeList > > alternative_type_list;
	for (auto named_type : ctx->alternative_type_lists()->root_alternative_type_list()->alternative_type_list()->named_type())
	{
		assert(named_type);
		alternative_type_list.push_back(parseNamedType(named_type));
	}
	bool extensible((ctx->alternative_type_lists()->extension_and_exception() != nullptr) || (ctx->alternative_type_lists()->optional_extension_marker() != nullptr));
	if (ctx->alternative_type_lists()->extension_addition_alternatives())
	{
		assert(ctx->alternative_type_lists()->extension_addition_alternatives()->extension_addition_alternatives_list());
		for (auto extension_addition_alternative : ctx->alternative_type_lists()->extension_addition_alternatives()->extension_addition_alternatives_list()->extension_addition_alternative())
		{
			assert(extension_addition_alternative);
			if (extension_addition_alternative->named_type())
			{
				alternative_type_list.push_back(parseNamedType(extension_addition_alternative->named_type()));
			}
			else
			{
				VersionedTypeList::second_type types;
				assert(extension_addition_alternative->extension_addition_alternatives_group());
				assert(extension_addition_alternative->extension_addition_alternatives_group()->alternative_type_list());
				for (auto named_type : extension_addition_alternative->extension_addition_alternatives_group()->alternative_type_list()->named_type())
				{
					assert(named_type);
					types.push_back(parseNamedType(named_type));
				}
				auto version(parseNumber(extension_addition_alternative->extension_addition_alternatives_group()->version_number()->NUMBER()));
				alternative_type_list.push_back(VersionedTypeList(version, types));
			}
		}
	}
	else
	{ /* no extension addition alternatives */ }

	return make_shared< ChoiceType >(alternative_type_list, extensible);
}
NamedType Listener::parseNamedType(asn1Parser::Named_typeContext *ctx)
{
	pre_condition(ctx);
	pre_condition(ctx->IDENTIFIER());
	pre_condition(ctx->type());
	string name(ctx->IDENTIFIER()->getText());
	auto type(parseType(ctx->type()));
	return NamedType(name, type);
}
std::shared_ptr< TypeDescriptor > Listener::parseEnumeratedType(asn1Parser::Enumerated_typeContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->enumerations());
	assert(ctx->enumerations()->root_enumeration());
	assert(ctx->enumerations()->root_enumeration()->enumeration());

	EnumeratedType::Values enumeration_values;
	bool extensible(ctx->enumerations()->ELLIPSIS() != nullptr);
	for (auto enumeration_item : ctx->enumerations()->root_enumeration()->enumeration()->enumeration_item())
	{
		assert(enumeration_item);
		if (enumeration_item->IDENTIFIER())
		{
			emitWarning(ctx, "using just identifiers for enumeration values is not supported in this implementation.");
		}
		else
		{
			assert(enumeration_item->named_number());
			enumeration_values.push_back(parseNamedNumber(enumeration_item->named_number()));
		}
	}
	if (ctx->enumerations()->additional_enumeration())
	{
		for (auto enumeration_item : ctx->enumerations()->additional_enumeration()->enumeration()->enumeration_item())
		{
			assert(enumeration_item);
			if (enumeration_item->IDENTIFIER())
			{
				emitWarning(ctx, "using just identifiers for enumeration values is not supported in this implementation.");
			}
			else
			{
				assert(enumeration_item->named_number());
				enumeration_values.push_back(parseNamedNumber(enumeration_item->named_number()));
			}
		}
	}
	if (ctx->enumerations()->exception_spec())
	{
		emitWarning(ctx, "exception specifications are not supported.");
	}
	else
	{ /* no exceptions */ }

	return make_shared< EnumeratedType >(enumeration_values, extensible);
}
NamedNumber Listener::parseNamedNumber(asn1Parser::Named_numberContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->IDENTIFIER() || ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
	string name(ctx->IDENTIFIER() ? ctx->IDENTIFIER()->getText() : ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText());
	if (ctx->signed_number())
	{
		auto value(parseSignedNumber(ctx->signed_number()));
		return NamedNumber(name, value);
	}
	else
	{
		assert(ctx->defined_value());
		auto value(parseDefinedValue(ctx->defined_value()));
		return NamedNumber(name, static_cast< DefinedValue const& >(*value));
	}
}
long Listener::parseSignedNumber(asn1Parser::Signed_numberContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->NUMBER());
	auto temp(parseNumber(ctx->NUMBER()));
	if (temp > (decltype(temp))numeric_limits< long >::max())
	{
		emitWarning(ctx, "value %u is greater than we support for a signed value.", temp);
	}
	else
	{ /* all is well so far */ }
	if (ctx->HYPHEN_TK())
	{
		//assert(numeric_limits< long >::max() <= -numeric_limits< long >::min());
		return -temp;
	}
	else
	{
		return temp;
	}
}
shared_ptr< TypeDescriptor > Listener::parseIntegerType(asn1Parser::Integer_typeContext *ctx)
{
	pre_condition(ctx);
	IntegerType::Values values;

	if (ctx->named_number_list())
	{
		for (auto named_number : ctx->named_number_list()->named_number())
		{
			assert(named_number);
			values.push_back(parseNamedNumber(named_number));
		}
	}
	else
	{ /* no named numbers */ }

	return make_shared< IntegerType >(values);
}
shared_ptr< TypeDescriptor > Listener::parseSequenceOrSetType(asn1Parser::Sequence_or_set_typeContext *ctx)
{
	pre_condition(ctx);
	assert((ctx->getStart()->getType() == asn1Parser::SEQUENCE_RW) || (ctx->getStart()->getType() == asn1Parser::SET_RW));
	bool is_set(ctx->getStart()->getType() == asn1Parser::SET_RW);
	assert(is_set || (ctx->getStart()->getType() == asn1Parser::SEQUENCE_RW));
	if (ctx->component_type_lists())
	{
		SequenceOrSetType::ComponentTypes component_types;
		bool root(ctx->component_type_lists()->getStart()->getType() != asn1Parser::ELLIPSIS);
		for (auto component_type_list : ctx->component_type_lists()->component_type_list())
		{
			assert(component_type_list);
			for (auto component_type : component_type_list->component_type())
			{
				assert(component_type);
				if (component_type->type())
				{
					assert(component_type->COMPONENTS_RW());
					assert(component_type->OF_RW());
					root = false;
					auto type(parseType(component_type->type()));
					component_types.push_back(make_shared< SequenceOrSetType::ComponentsOfType >(type));
				}
				else
				{
					assert(component_type->named_type());
					auto named_type(parseNamedType(component_type->named_type()));
					if (component_type->DEFAULT_RW())
					{
						component_types.push_back(make_shared< SequenceOrSetType::NamedComponentType >(root, named_type, parseValue(component_type->value())));
					}
					else
					{
						component_types.push_back(make_shared< SequenceOrSetType::NamedComponentType >(root, named_type, component_type->OPTIONAL_RW() != nullptr));
					}
				}
			}
			root = false;
		}
		return make_shared< SequenceOrSetType >(is_set, component_types);
	}
	else
	{
		return make_shared< SequenceOrSetType >();
	}
}
shared_ptr< TypeDescriptor > Listener::parseSequenceOrSetOfType(asn1Parser::Sequence_or_set_of_typeContext *ctx)
{
	pre_condition(ctx);
	assert((ctx->getStart()->getType() == asn1Parser::SEQUENCE_RW) || (ctx->getStart()->getType() == asn1Parser::SET_RW));
	bool is_set(ctx->getStart()->getType() == asn1Parser::SET_RW);
	if (ctx->type())
	{
		auto type(parseType(ctx->type()));
		return make_shared< SequenceOrSetOfType >(is_set, type);
	}
	else
	{
		assert(ctx->named_type());
		auto type(parseNamedType(ctx->named_type()));
		return make_shared< SequenceOrSetOfType >(is_set, type);
	}
}
shared_ptr< TypeDescriptor > Listener::parsePrefixedType(asn1Parser::Prefixed_typeContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->tagged_type() || ctx->encoding_prefixed_type());
	if (ctx->tagged_type())
	{
		assert(ctx->tagged_type()->tag());
		auto tag(parseTag(ctx->tagged_type()->tag()));
		// if the tag default is implicit or automatic, we revert to automatic tagging in that we tag explicitly only when required.
		bool explicit_tagging(ctx->tagged_type()->IMPLICIT_RW() ? false : ctx->tagged_type()->EXPLICIT_RW() ? true : tag_default_ == TagDefault::explicit_tags__);
		// We force implicit tagging when told to (but will (should?) warn later if this may cause ambiguity
		bool force_implicit_tagging(ctx->tagged_type()->IMPLICIT_RW() ? true : false);
		auto type(parseType(ctx->tagged_type()->type()));
		if (type->requireExplicitTag() && force_implicit_tagging)
		{
			emitWarning(ctx->tagged_type()->IMPLICIT_RW(), "Forcing implicit tagging, but type requires explicit tagging. This may cause interoperability issues.");
		}
		else
		{ /* ok */ }
		
		return make_shared< TaggedType >(tag, explicit_tagging, force_implicit_tagging, type);
	}
	else
	{
		assert(ctx->encoding_prefixed_type());
		assert(ctx->encoding_prefixed_type()->encoding_prefix());
		assert(ctx->encoding_prefixed_type()->type());
		emitWarning(ctx->encoding_prefixed_type()->encoding_prefix(), "encoding prefix ignored.");
		auto type(parseType(ctx->encoding_prefixed_type()->type()));
		return type;
	}
}

shared_ptr< TypeDescriptor > Listener::parseDefinedType(asn1Parser::Defined_typeContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->external_type_reference() || ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
	if (ctx->external_type_reference())
	{
		assert(ctx->external_type_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE().size() == 2);
		auto const module_name(ctx->external_type_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE(0)->getText());
		if (!module_name_mappings_.exists(module_name))
		{
			emitError(ctx->external_type_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE(0), "Unresolved reference to \"%s\"", ctx->external_type_reference()->getText().c_str());
			throw UnresolvedReference(ctx->external_type_reference()->getText());
		}
		else
		{
			assert(imported_symbols_.find(module_name) != imported_symbols_.end());
			auto imported_symbols(imported_symbols_.find(module_name)->second);
			auto const symbol_name(ctx->external_type_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE(1)->getText());
			if (find(imported_symbols.begin(), imported_symbols.end(), symbol_name) == imported_symbols.end())
			{
				emitError(ctx->external_type_reference()->TYPE_REFERENCE_OR_MODULE_REFERENCE(1), "Unresolved reference to \"%s\"", ctx->external_type_reference()->getText().c_str());
				throw UnresolvedReference(ctx->external_type_reference()->getText());
			}
			else
			{
				return make_shared< ExternalTypeReference >(module_name, symbol_name);
			}
		}
	}
	else
	{
		assert(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
		return make_shared< DefinedType >(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText());
	}
}
shared_ptr< TypeDescriptor > Listener::parseUsefulType(asn1Parser::Useful_typeContext *ctx)
{
	pre_condition(ctx);
	if (ctx->getText() == "GeneralizedTime")
	{
		return make_shared< GeneralizedTimeType >();
	}
	else if (ctx->getText() == "UTCTime")
	{
		return make_shared< UTCTimeType >();
	}
	else
	{
		assert(ctx->getText() == "ObjectDescriptor");
		return make_shared< ObjectDescriptorType >();
	}
}
shared_ptr< TypeDescriptor > Listener::parseSelectionType(asn1Parser::Selection_typeContext *ctx)
{
	pre_condition(ctx);
	auto selection(ctx->IDENTIFIER()->getText());
	auto type(parseType(ctx->type()));
	return make_shared< SelectionType >(selection, type);
}
shared_ptr< TypeDescriptor > Listener::parseContrainedType(asn1Parser::Constrained_typeContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->type_with_constraint()->constraint() && ctx->constraint());
	auto constraint(parseConstraint(ctx->type_with_constraint() ? ctx->type_with_constraint()->constraint() : ctx->constraint()));
	if (ctx->type_with_constraint())
	{
		assert(ctx->type_with_constraint()->SET_RW() || ctx->type_with_constraint()->SEQUENCE_RW());
		assert(ctx->type_with_constraint()->type() || ctx->type_with_constraint()->named_type());
		bool is_set(ctx->type_with_constraint()->SET_RW() ? true : false);
		auto retval(ctx->type_with_constraint()->type()
			? make_shared< TypeWithConstraint >(is_set, constraint, parseType(ctx->type_with_constraint()->type()))
			: make_shared< TypeWithConstraint >(is_set, constraint, parseNamedType(ctx->type_with_constraint()->named_type())))
			;
		return retval;
	}
	else
	{
		assert(ctx->builtin_type()) && parseReferencedType(ctx->referenced_type());
		auto type(ctx->builtin_type() ? parseBuiltinType(ctx->builtin_type()) : parseReferencedType(ctx->referenced_type()));
		return make_shared< ConstrainedType >(type, constraint);
	}
}

shared_ptr< TypeDescriptor > Listener::parseReferencedType(asn1Parser::Referenced_typeContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->defined_type() || ctx->useful_type() || ctx->selection_type());
	return
		  ctx->defined_type() ? parseDefinedType(ctx->defined_type())
		: ctx->useful_type() ? parseUsefulType(ctx->useful_type())
		: parseSelectionType(ctx->selection_type())
		;
}

Constraint Listener::parseConstraint(asn1Parser::ConstraintContext *ctx)
{
	//TODO
	return Constraint();
}

Tag Listener::parseTag(asn1Parser::TagContext *ctx)
{
	pre_condition(ctx);
	if (ctx->ENCODING_REFERENCE())
	{
		if (ctx->ENCODING_REFERENCE()->getText() != "TAG")
		{
			emitWarning(ctx->ENCODING_REFERENCE(), "When used in \"Tag\", the \"encodingreference\" shall be TAG. (ignoring encoding reference)");
		}
		else
		{ /* all is well - nothing to see here */ }
	}
	else
	{ /* nothing to see here */ }
	Tag::Class the_class(Tag::Class::context_specific__);
	if (ctx->category())
	{
		assert(ctx->category()->UNIVERSAL_RW() || ctx->category()->APPLICATION_RW() || ctx->category()->PRIVATE_RW());
		the_class =
			ctx->category()->UNIVERSAL_RW()
			? Tag::Class::universal__
			: (ctx->category()->APPLICATION_RW()
				? Tag::Class::application__
				: Tag::Class::private__
				)
			;
		if (the_class == Tag::Class::universal__)
		{
			emitWarning(ctx->category(), "The \"Class\" shall not be UNIVERSAL except for types defined in X.680. This may cause errors interoperating with other encoders/decoders.");
		}
		else
		{ /* OK */ }
	}
	else
	{ /* assume context-specific */ }
	assert(ctx->class_number());
	assert(ctx->class_number()->NUMBER() || ctx->class_number()->defined_value());
	if (ctx->class_number()->NUMBER())
	{
		return Tag(the_class, parseNumber(ctx->class_number()->NUMBER()));
	}
	else
	{
		assert(ctx->class_number()->defined_value());
		return Tag(the_class, static_cast< DefinedValue const& >(*parseDefinedValue(ctx->class_number()->defined_value())));
	}
}

shared_ptr< Value > Listener::parseValue(asn1Parser::ValueContext *ctx)
{
	pre_condition(ctx);
	assert(ctx->builtin_value() || ctx->defined_value());
	return ctx->builtin_value()
		? parseBuiltinValue(ctx->builtin_value())
		: parseDefinedValue(ctx->defined_value())
		;
}

shared_ptr< Value > Listener::parseBuiltinValue(asn1Parser::Builtin_valueContext *ctx)
{
	return
		  ctx->bit_string_value()		? parseBitStringValue(ctx->bit_string_value())
		: ctx->boolean_value()			? parseBooleanValue(ctx->boolean_value())
		: ctx->character_string_value()		? parseCharacterStringValue(ctx->character_string_value())
		: ctx->choice_value()			? parseChoiceValue(ctx->choice_value())
		: ctx->embedded_pdv_value()		? parseEmbeddedPDVValue(ctx->embedded_pdv_value())
		: ctx->enumerated_value()		? parseEnumeratedValue(ctx->enumerated_value())
		: ctx->integer_value()			? parseIntegerValue(ctx->integer_value())
		: ctx->iri_value()			? parseIRIValue(ctx->iri_value())
		: ctx->null_value()			? parseNullValue(ctx->null_value())
		: ctx->object_identifier_value()	? parseObjectIdentifierValue(ctx->object_identifier_value())
		: ctx->octet_string_value()		? parseOctetStringValue(ctx->octet_string_value())
		: ctx->real_value()			? parseRealValue(ctx->real_value())
		: ctx->relative_iri_value()		? parseRelativeIRIValue(ctx->relative_iri_value())
		: ctx->relative_oid_value()		? parseRelativeOIDValue(ctx->relative_oid_value())
		: ctx->sequence_value()			? parseSequenceValue(ctx->sequence_value())
		: ctx->sequence_of_value()		? parseSequenceOfValue(ctx->sequence_of_value())
		: ctx->set_value()			? parseSetValue(ctx->set_value())
		: ctx->set_of_value()			? parseSetOfValue(ctx->set_of_value())
							: parseTimeValue(ctx->time_value())
		;
}
shared_ptr< Value > Listener::parseDefinedValue(asn1Parser::Defined_valueContext *ctx)
{
	pre_condition(ctx);
	string text(ctx->getText());
	text.erase(
		  remove_if(
			  text.begin()
			, text.end()
			, [](unsigned char c) { 
				return false
					|| (c == '\t') 
					|| (c == ' ')
					|| (c == '\n')
					|| (c == '\r')
					|| (c == 0x0b)
					|| (c == 0x0c)
					|| (c == 0xa0)	//TODO if input is UTF-8, this is not codepoint \u00a0 -- or rather, this is not how that would be encooded.
					;
				}
			)
		, text.end()
		);
	return make_shared< DefinedValue >(text);
}
shared_ptr< Value > Listener::parseBitStringValue(asn1Parser::Bit_string_valueContext *ctx)
{
	pre_condition(ctx);
	if (ctx->BSTRING())
	{
		assert(ctx->BSTRING()->getSymbol());
		auto bstring_text(ctx->BSTRING()->getSymbol()->getText());
		unsigned char char_value(0);
		unsigned char bits_remaining(8);
		vector< unsigned char > bstring_value;
		for (auto bstring_char : bstring_text)
		{
			char_value <<= 1;
			switch (bstring_char)
			{
			case '1' :
				char_value |= 1;
				--bits_remaining;
				break;
			case '0' :
				--bits_remaining;
				break;
			default :
				// no-op
				break;
			}
			if (!bits_remaining)
			{
				bstring_value.push_back(char_value);
				char_value = 0;
				bits_remaining = 8;
			}
			else
			{ /* still remaining */ }
		}
		if (bits_remaining < 8)
		{
			char_value <<= bits_remaining;
			bstring_value.push_back(char_value);
			return make_shared< BitStringValue >(bstring_value, bits_remaining);
		}
		else
		{
			return make_shared< BitStringValue >(bstring_value, 0);
		}
	}
	else if (ctx->HSTRING())
	{
		assert(ctx->HSTRING()->getSymbol());
		auto hstring_text(ctx->HSTRING()->getSymbol()->getText());
		unsigned char char_value(0);
		unsigned char bits_remaining(8);
		vector< unsigned char > bstring_value;
		for (auto hstring_char : hstring_text)
		{
			char_value <<= 4;
			switch (hstring_char)
			{
			case '0' : char_value |= 0x0; bits_remaining -= 4; break;
			case '1' : char_value |= 0x1; bits_remaining -= 4; break;
			case '2' : char_value |= 0x2; bits_remaining -= 4; break;
			case '3' : char_value |= 0x3; bits_remaining -= 4; break;
			case '4' : char_value |= 0x4; bits_remaining -= 4; break;
			case '5' : char_value |= 0x5; bits_remaining -= 4; break;
			case '6' : char_value |= 0x6; bits_remaining -= 4; break;
			case '7' : char_value |= 0x7; bits_remaining -= 4; break;
			case '8' : char_value |= 0x8; bits_remaining -= 4; break;
			case '9' : char_value |= 0x9; bits_remaining -= 4; break;
			case 'a' : char_value |= 0xA; bits_remaining -= 4; break;
			case 'A' : char_value |= 0xA; bits_remaining -= 4; break;
			case 'b' : char_value |= 0xB; bits_remaining -= 4; break;
			case 'B' : char_value |= 0xB; bits_remaining -= 4; break;
			case 'c' : char_value |= 0xC; bits_remaining -= 4; break;
			case 'C' : char_value |= 0xC; bits_remaining -= 4; break;
			case 'd' : char_value |= 0xD; bits_remaining -= 4; break;
			case 'D' : char_value |= 0xD; bits_remaining -= 4; break;
			case 'e' : char_value |= 0xE; bits_remaining -= 4; break;
			case 'E' : char_value |= 0xE; bits_remaining -= 4; break;
			case 'f' : char_value |= 0xF; bits_remaining -= 4; break;
			case 'F' : char_value |= 0xF; bits_remaining -= 4; break;
			}
			
			if (!bits_remaining)
			{
				bstring_value.push_back(char_value);
				char_value = 0;
				bits_remaining = 8;
			}
			else
			{ /* still remaining */ }
		}
		if (bits_remaining < 8)
		{
			assert(bits_remaining == 4);
			char_value <<= bits_remaining;
			bstring_value.push_back(char_value);
			return make_shared< BitStringValue >(bstring_value, bits_remaining);
		}
		else
		{
			return make_shared< BitStringValue >(bstring_value, 0);
		}
	}
	else if (ctx->CONTAINING_RW())
	{
		return make_shared< BitStringValue >(parseValue(ctx->value()));
	}
	else if (ctx->identifier_list())
	{
		vector< string > identifiers;
		auto identifier_list(ctx->identifier_list()->IDENTIFIER());
		transform(identifier_list.begin(), identifier_list.end(), back_inserter(identifiers), [](auto identifier){ return identifier->getText(); });
		return make_shared< BitStringValue >(move(identifiers));
	}
	else
	{
		return make_shared< BitStringValue >();
	}
}

shared_ptr< Value > Listener::parseBooleanValue(asn1Parser::Boolean_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseCharacterStringValue(asn1Parser::Character_string_valueContext *ctx)		{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseChoiceValue(asn1Parser::Choice_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseEmbeddedPDVValue(asn1Parser::Embedded_pdv_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseEnumeratedValue(asn1Parser::Enumerated_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseIntegerValue(asn1Parser::Integer_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseIRIValue(asn1Parser::Iri_valueContext *ctx)					{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseNullValue(asn1Parser::Null_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseObjectIdentifierValue(asn1Parser::Object_identifier_valueContext *ctx)	{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseOctetStringValue(asn1Parser::Octet_string_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseRealValue(asn1Parser::Real_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseRelativeIRIValue(asn1Parser::Relative_iri_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseRelativeOIDValue(asn1Parser::Relative_oid_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseSequenceValue(asn1Parser::Sequence_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseSequenceOfValue(asn1Parser::Sequence_of_valueContext *ctx)			{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseSetValue(asn1Parser::Set_valueContext *ctx)					{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseSetOfValue(asn1Parser::Set_of_valueContext *ctx)				{ return shared_ptr< Value >(); }
shared_ptr< Value > Listener::parseTimeValue(asn1Parser::Time_valueContext *ctx)				{ return shared_ptr< Value >(); }

/*static */void Listener::emitWarning(antlr4::ParserRuleContext *ctx, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_WARN)("%s:%u:%u: warning: ", ctx->getStart()->getTokenSource()->getSourceName().c_str(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine())(fmt, ap)("\n");
	va_end(ap);
}
/*static */void Listener::emitWarning(antlr4::tree::TerminalNode *node, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_WARN)("%s:%u:%u: warning: ", node->getSymbol()->getTokenSource()->getSourceName().c_str(), node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine())(fmt, ap)("\n");
	va_end(ap);
}
/*static */void Listener::emitError(antlr4::ParserRuleContext *ctx, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", ctx->getStart()->getTokenSource()->getSourceName().c_str(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine())(fmt, ap)("\n");
	va_end(ap);
}
/*static */void Listener::emitError(antlr4::tree::TerminalNode *node, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", node->getSymbol()->getTokenSource()->getSourceName().c_str(), node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine())(fmt, ap)("\n");
	va_end(ap);
}

}}}




