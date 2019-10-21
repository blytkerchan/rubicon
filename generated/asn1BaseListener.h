
// Generated from asn1.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "asn1Listener.h"


/**
 * This class provides an empty implementation of asn1Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  asn1BaseListener : public asn1Listener {
public:

  virtual void enterFile(asn1Parser::FileContext * /*ctx*/) override { }
  virtual void exitFile(asn1Parser::FileContext * /*ctx*/) override { }

  virtual void enterModule_definition(asn1Parser::Module_definitionContext * /*ctx*/) override { }
  virtual void exitModule_definition(asn1Parser::Module_definitionContext * /*ctx*/) override { }

  virtual void enterModule_identifier(asn1Parser::Module_identifierContext * /*ctx*/) override { }
  virtual void exitModule_identifier(asn1Parser::Module_identifierContext * /*ctx*/) override { }

  virtual void enterDefinitive_identification(asn1Parser::Definitive_identificationContext * /*ctx*/) override { }
  virtual void exitDefinitive_identification(asn1Parser::Definitive_identificationContext * /*ctx*/) override { }

  virtual void enterDefinitive_oid(asn1Parser::Definitive_oidContext * /*ctx*/) override { }
  virtual void exitDefinitive_oid(asn1Parser::Definitive_oidContext * /*ctx*/) override { }

  virtual void enterDefinitive_oid_and_iri(asn1Parser::Definitive_oid_and_iriContext * /*ctx*/) override { }
  virtual void exitDefinitive_oid_and_iri(asn1Parser::Definitive_oid_and_iriContext * /*ctx*/) override { }

  virtual void enterDefinitive_object_id_component_list(asn1Parser::Definitive_object_id_component_listContext * /*ctx*/) override { }
  virtual void exitDefinitive_object_id_component_list(asn1Parser::Definitive_object_id_component_listContext * /*ctx*/) override { }

  virtual void enterDefinitive_object_id_component(asn1Parser::Definitive_object_id_componentContext * /*ctx*/) override { }
  virtual void exitDefinitive_object_id_component(asn1Parser::Definitive_object_id_componentContext * /*ctx*/) override { }

  virtual void enterDefinitive_number_form(asn1Parser::Definitive_number_formContext * /*ctx*/) override { }
  virtual void exitDefinitive_number_form(asn1Parser::Definitive_number_formContext * /*ctx*/) override { }

  virtual void enterDefinitive_name_and_number_form(asn1Parser::Definitive_name_and_number_formContext * /*ctx*/) override { }
  virtual void exitDefinitive_name_and_number_form(asn1Parser::Definitive_name_and_number_formContext * /*ctx*/) override { }

  virtual void enterEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext * /*ctx*/) override { }
  virtual void exitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext * /*ctx*/) override { }

  virtual void enterExplicit_tags(asn1Parser::Explicit_tagsContext * /*ctx*/) override { }
  virtual void exitExplicit_tags(asn1Parser::Explicit_tagsContext * /*ctx*/) override { }

  virtual void enterImplicit_tags(asn1Parser::Implicit_tagsContext * /*ctx*/) override { }
  virtual void exitImplicit_tags(asn1Parser::Implicit_tagsContext * /*ctx*/) override { }

  virtual void enterAutomatic_tags(asn1Parser::Automatic_tagsContext * /*ctx*/) override { }
  virtual void exitAutomatic_tags(asn1Parser::Automatic_tagsContext * /*ctx*/) override { }

  virtual void enterExtension_default(asn1Parser::Extension_defaultContext * /*ctx*/) override { }
  virtual void exitExtension_default(asn1Parser::Extension_defaultContext * /*ctx*/) override { }

  virtual void enterModule_body(asn1Parser::Module_bodyContext * /*ctx*/) override { }
  virtual void exitModule_body(asn1Parser::Module_bodyContext * /*ctx*/) override { }

  virtual void enterExports(asn1Parser::ExportsContext * /*ctx*/) override { }
  virtual void exitExports(asn1Parser::ExportsContext * /*ctx*/) override { }

  virtual void enterSymbols_exported(asn1Parser::Symbols_exportedContext * /*ctx*/) override { }
  virtual void exitSymbols_exported(asn1Parser::Symbols_exportedContext * /*ctx*/) override { }

  virtual void enterImports(asn1Parser::ImportsContext * /*ctx*/) override { }
  virtual void exitImports(asn1Parser::ImportsContext * /*ctx*/) override { }

  virtual void enterSymbols_imported(asn1Parser::Symbols_importedContext * /*ctx*/) override { }
  virtual void exitSymbols_imported(asn1Parser::Symbols_importedContext * /*ctx*/) override { }

  virtual void enterSymbols_from_module_list(asn1Parser::Symbols_from_module_listContext * /*ctx*/) override { }
  virtual void exitSymbols_from_module_list(asn1Parser::Symbols_from_module_listContext * /*ctx*/) override { }

  virtual void enterSymbols_from_module(asn1Parser::Symbols_from_moduleContext * /*ctx*/) override { }
  virtual void exitSymbols_from_module(asn1Parser::Symbols_from_moduleContext * /*ctx*/) override { }

  virtual void enterGlobal_module_reference(asn1Parser::Global_module_referenceContext * /*ctx*/) override { }
  virtual void exitGlobal_module_reference(asn1Parser::Global_module_referenceContext * /*ctx*/) override { }

  virtual void enterAssigned_identifier(asn1Parser::Assigned_identifierContext * /*ctx*/) override { }
  virtual void exitAssigned_identifier(asn1Parser::Assigned_identifierContext * /*ctx*/) override { }

  virtual void enterSymbol_list(asn1Parser::Symbol_listContext * /*ctx*/) override { }
  virtual void exitSymbol_list(asn1Parser::Symbol_listContext * /*ctx*/) override { }

  virtual void enterSymbol(asn1Parser::SymbolContext * /*ctx*/) override { }
  virtual void exitSymbol(asn1Parser::SymbolContext * /*ctx*/) override { }

  virtual void enterReference(asn1Parser::ReferenceContext * /*ctx*/) override { }
  virtual void exitReference(asn1Parser::ReferenceContext * /*ctx*/) override { }

  virtual void enterAssignment_list(asn1Parser::Assignment_listContext * /*ctx*/) override { }
  virtual void exitAssignment_list(asn1Parser::Assignment_listContext * /*ctx*/) override { }

  virtual void enterAssignment(asn1Parser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(asn1Parser::AssignmentContext * /*ctx*/) override { }

  virtual void enterDefined_type(asn1Parser::Defined_typeContext * /*ctx*/) override { }
  virtual void exitDefined_type(asn1Parser::Defined_typeContext * /*ctx*/) override { }

  virtual void enterDefined_value(asn1Parser::Defined_valueContext * /*ctx*/) override { }
  virtual void exitDefined_value(asn1Parser::Defined_valueContext * /*ctx*/) override { }

  virtual void enterExternal_type_reference(asn1Parser::External_type_referenceContext * /*ctx*/) override { }
  virtual void exitExternal_type_reference(asn1Parser::External_type_referenceContext * /*ctx*/) override { }

  virtual void enterExternal_value_reference(asn1Parser::External_value_referenceContext * /*ctx*/) override { }
  virtual void exitExternal_value_reference(asn1Parser::External_value_referenceContext * /*ctx*/) override { }

  virtual void enterAbsolute_reference(asn1Parser::Absolute_referenceContext * /*ctx*/) override { }
  virtual void exitAbsolute_reference(asn1Parser::Absolute_referenceContext * /*ctx*/) override { }

  virtual void enterItem_spec(asn1Parser::Item_specContext * /*ctx*/) override { }
  virtual void exitItem_spec(asn1Parser::Item_specContext * /*ctx*/) override { }

  virtual void enterComponent_id(asn1Parser::Component_idContext * /*ctx*/) override { }
  virtual void exitComponent_id(asn1Parser::Component_idContext * /*ctx*/) override { }

  virtual void enterType_assignment(asn1Parser::Type_assignmentContext * /*ctx*/) override { }
  virtual void exitType_assignment(asn1Parser::Type_assignmentContext * /*ctx*/) override { }

  virtual void enterValue_assignment(asn1Parser::Value_assignmentContext * /*ctx*/) override { }
  virtual void exitValue_assignment(asn1Parser::Value_assignmentContext * /*ctx*/) override { }

  virtual void enterValue_set_type_assignment(asn1Parser::Value_set_type_assignmentContext * /*ctx*/) override { }
  virtual void exitValue_set_type_assignment(asn1Parser::Value_set_type_assignmentContext * /*ctx*/) override { }

  virtual void enterValue_set(asn1Parser::Value_setContext * /*ctx*/) override { }
  virtual void exitValue_set(asn1Parser::Value_setContext * /*ctx*/) override { }

  virtual void enterType(asn1Parser::TypeContext * /*ctx*/) override { }
  virtual void exitType(asn1Parser::TypeContext * /*ctx*/) override { }

  virtual void enterBuiltin_type(asn1Parser::Builtin_typeContext * /*ctx*/) override { }
  virtual void exitBuiltin_type(asn1Parser::Builtin_typeContext * /*ctx*/) override { }

  virtual void enterReferenced_type(asn1Parser::Referenced_typeContext * /*ctx*/) override { }
  virtual void exitReferenced_type(asn1Parser::Referenced_typeContext * /*ctx*/) override { }

  virtual void enterNamed_type(asn1Parser::Named_typeContext * /*ctx*/) override { }
  virtual void exitNamed_type(asn1Parser::Named_typeContext * /*ctx*/) override { }

  virtual void enterAny_type(asn1Parser::Any_typeContext * /*ctx*/) override { }
  virtual void exitAny_type(asn1Parser::Any_typeContext * /*ctx*/) override { }

  virtual void enterValue(asn1Parser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(asn1Parser::ValueContext * /*ctx*/) override { }

  virtual void enterBuiltin_value(asn1Parser::Builtin_valueContext * /*ctx*/) override { }
  virtual void exitBuiltin_value(asn1Parser::Builtin_valueContext * /*ctx*/) override { }

  virtual void enterNamed_value(asn1Parser::Named_valueContext * /*ctx*/) override { }
  virtual void exitNamed_value(asn1Parser::Named_valueContext * /*ctx*/) override { }

  virtual void enterBoolean_value(asn1Parser::Boolean_valueContext * /*ctx*/) override { }
  virtual void exitBoolean_value(asn1Parser::Boolean_valueContext * /*ctx*/) override { }

  virtual void enterInteger_type(asn1Parser::Integer_typeContext * /*ctx*/) override { }
  virtual void exitInteger_type(asn1Parser::Integer_typeContext * /*ctx*/) override { }

  virtual void enterNamed_number_list(asn1Parser::Named_number_listContext * /*ctx*/) override { }
  virtual void exitNamed_number_list(asn1Parser::Named_number_listContext * /*ctx*/) override { }

  virtual void enterNamed_number(asn1Parser::Named_numberContext * /*ctx*/) override { }
  virtual void exitNamed_number(asn1Parser::Named_numberContext * /*ctx*/) override { }

  virtual void enterSigned_number(asn1Parser::Signed_numberContext * /*ctx*/) override { }
  virtual void exitSigned_number(asn1Parser::Signed_numberContext * /*ctx*/) override { }

  virtual void enterInteger_value(asn1Parser::Integer_valueContext * /*ctx*/) override { }
  virtual void exitInteger_value(asn1Parser::Integer_valueContext * /*ctx*/) override { }

  virtual void enterEnumerated_type(asn1Parser::Enumerated_typeContext * /*ctx*/) override { }
  virtual void exitEnumerated_type(asn1Parser::Enumerated_typeContext * /*ctx*/) override { }

  virtual void enterEnumerations(asn1Parser::EnumerationsContext * /*ctx*/) override { }
  virtual void exitEnumerations(asn1Parser::EnumerationsContext * /*ctx*/) override { }

  virtual void enterRoot_enumeration(asn1Parser::Root_enumerationContext * /*ctx*/) override { }
  virtual void exitRoot_enumeration(asn1Parser::Root_enumerationContext * /*ctx*/) override { }

  virtual void enterAdditional_enumeration(asn1Parser::Additional_enumerationContext * /*ctx*/) override { }
  virtual void exitAdditional_enumeration(asn1Parser::Additional_enumerationContext * /*ctx*/) override { }

  virtual void enterEnumeration(asn1Parser::EnumerationContext * /*ctx*/) override { }
  virtual void exitEnumeration(asn1Parser::EnumerationContext * /*ctx*/) override { }

  virtual void enterEnumeration_item(asn1Parser::Enumeration_itemContext * /*ctx*/) override { }
  virtual void exitEnumeration_item(asn1Parser::Enumeration_itemContext * /*ctx*/) override { }

  virtual void enterEnumerated_value(asn1Parser::Enumerated_valueContext * /*ctx*/) override { }
  virtual void exitEnumerated_value(asn1Parser::Enumerated_valueContext * /*ctx*/) override { }

  virtual void enterReal_value(asn1Parser::Real_valueContext * /*ctx*/) override { }
  virtual void exitReal_value(asn1Parser::Real_valueContext * /*ctx*/) override { }

  virtual void enterBit_string_type(asn1Parser::Bit_string_typeContext * /*ctx*/) override { }
  virtual void exitBit_string_type(asn1Parser::Bit_string_typeContext * /*ctx*/) override { }

  virtual void enterNamed_bit_list(asn1Parser::Named_bit_listContext * /*ctx*/) override { }
  virtual void exitNamed_bit_list(asn1Parser::Named_bit_listContext * /*ctx*/) override { }

  virtual void enterNamed_bit(asn1Parser::Named_bitContext * /*ctx*/) override { }
  virtual void exitNamed_bit(asn1Parser::Named_bitContext * /*ctx*/) override { }

  virtual void enterBit_string_value(asn1Parser::Bit_string_valueContext * /*ctx*/) override { }
  virtual void exitBit_string_value(asn1Parser::Bit_string_valueContext * /*ctx*/) override { }

  virtual void enterIdentifier_list(asn1Parser::Identifier_listContext * /*ctx*/) override { }
  virtual void exitIdentifier_list(asn1Parser::Identifier_listContext * /*ctx*/) override { }

  virtual void enterOctet_string_value(asn1Parser::Octet_string_valueContext * /*ctx*/) override { }
  virtual void exitOctet_string_value(asn1Parser::Octet_string_valueContext * /*ctx*/) override { }

  virtual void enterSequence_or_set_type(asn1Parser::Sequence_or_set_typeContext * /*ctx*/) override { }
  virtual void exitSequence_or_set_type(asn1Parser::Sequence_or_set_typeContext * /*ctx*/) override { }

  virtual void enterSequence_or_set_of_type(asn1Parser::Sequence_or_set_of_typeContext * /*ctx*/) override { }
  virtual void exitSequence_or_set_of_type(asn1Parser::Sequence_or_set_of_typeContext * /*ctx*/) override { }

  virtual void enterExtension_and_exception(asn1Parser::Extension_and_exceptionContext * /*ctx*/) override { }
  virtual void exitExtension_and_exception(asn1Parser::Extension_and_exceptionContext * /*ctx*/) override { }

  virtual void enterOptional_extension_marker(asn1Parser::Optional_extension_markerContext * /*ctx*/) override { }
  virtual void exitOptional_extension_marker(asn1Parser::Optional_extension_markerContext * /*ctx*/) override { }

  virtual void enterComponent_type_lists(asn1Parser::Component_type_listsContext * /*ctx*/) override { }
  virtual void exitComponent_type_lists(asn1Parser::Component_type_listsContext * /*ctx*/) override { }

  virtual void enterExtension_end_marker(asn1Parser::Extension_end_markerContext * /*ctx*/) override { }
  virtual void exitExtension_end_marker(asn1Parser::Extension_end_markerContext * /*ctx*/) override { }

  virtual void enterExtension_additions(asn1Parser::Extension_additionsContext * /*ctx*/) override { }
  virtual void exitExtension_additions(asn1Parser::Extension_additionsContext * /*ctx*/) override { }

  virtual void enterExtension_addition_list(asn1Parser::Extension_addition_listContext * /*ctx*/) override { }
  virtual void exitExtension_addition_list(asn1Parser::Extension_addition_listContext * /*ctx*/) override { }

  virtual void enterExtension_addition(asn1Parser::Extension_additionContext * /*ctx*/) override { }
  virtual void exitExtension_addition(asn1Parser::Extension_additionContext * /*ctx*/) override { }

  virtual void enterExtension_addition_group(asn1Parser::Extension_addition_groupContext * /*ctx*/) override { }
  virtual void exitExtension_addition_group(asn1Parser::Extension_addition_groupContext * /*ctx*/) override { }

  virtual void enterVersion_number(asn1Parser::Version_numberContext * /*ctx*/) override { }
  virtual void exitVersion_number(asn1Parser::Version_numberContext * /*ctx*/) override { }

  virtual void enterComponent_type_list(asn1Parser::Component_type_listContext * /*ctx*/) override { }
  virtual void exitComponent_type_list(asn1Parser::Component_type_listContext * /*ctx*/) override { }

  virtual void enterComponent_type(asn1Parser::Component_typeContext * /*ctx*/) override { }
  virtual void exitComponent_type(asn1Parser::Component_typeContext * /*ctx*/) override { }

  virtual void enterSequence_value(asn1Parser::Sequence_valueContext * /*ctx*/) override { }
  virtual void exitSequence_value(asn1Parser::Sequence_valueContext * /*ctx*/) override { }

  virtual void enterComponent_value_list(asn1Parser::Component_value_listContext * /*ctx*/) override { }
  virtual void exitComponent_value_list(asn1Parser::Component_value_listContext * /*ctx*/) override { }

  virtual void enterSequence_of_value(asn1Parser::Sequence_of_valueContext * /*ctx*/) override { }
  virtual void exitSequence_of_value(asn1Parser::Sequence_of_valueContext * /*ctx*/) override { }

  virtual void enterValue_list(asn1Parser::Value_listContext * /*ctx*/) override { }
  virtual void exitValue_list(asn1Parser::Value_listContext * /*ctx*/) override { }

  virtual void enterNamed_value_list(asn1Parser::Named_value_listContext * /*ctx*/) override { }
  virtual void exitNamed_value_list(asn1Parser::Named_value_listContext * /*ctx*/) override { }

  virtual void enterSet_value(asn1Parser::Set_valueContext * /*ctx*/) override { }
  virtual void exitSet_value(asn1Parser::Set_valueContext * /*ctx*/) override { }

  virtual void enterSet_of_value(asn1Parser::Set_of_valueContext * /*ctx*/) override { }
  virtual void exitSet_of_value(asn1Parser::Set_of_valueContext * /*ctx*/) override { }

  virtual void enterChoice_type(asn1Parser::Choice_typeContext * /*ctx*/) override { }
  virtual void exitChoice_type(asn1Parser::Choice_typeContext * /*ctx*/) override { }

  virtual void enterAlternative_type_lists(asn1Parser::Alternative_type_listsContext * /*ctx*/) override { }
  virtual void exitAlternative_type_lists(asn1Parser::Alternative_type_listsContext * /*ctx*/) override { }

  virtual void enterRoot_alternative_type_list(asn1Parser::Root_alternative_type_listContext * /*ctx*/) override { }
  virtual void exitRoot_alternative_type_list(asn1Parser::Root_alternative_type_listContext * /*ctx*/) override { }

  virtual void enterExtension_addition_alternatives(asn1Parser::Extension_addition_alternativesContext * /*ctx*/) override { }
  virtual void exitExtension_addition_alternatives(asn1Parser::Extension_addition_alternativesContext * /*ctx*/) override { }

  virtual void enterExtension_addition_alternatives_list(asn1Parser::Extension_addition_alternatives_listContext * /*ctx*/) override { }
  virtual void exitExtension_addition_alternatives_list(asn1Parser::Extension_addition_alternatives_listContext * /*ctx*/) override { }

  virtual void enterExtension_addition_alternative(asn1Parser::Extension_addition_alternativeContext * /*ctx*/) override { }
  virtual void exitExtension_addition_alternative(asn1Parser::Extension_addition_alternativeContext * /*ctx*/) override { }

  virtual void enterExtension_addition_alternatives_group(asn1Parser::Extension_addition_alternatives_groupContext * /*ctx*/) override { }
  virtual void exitExtension_addition_alternatives_group(asn1Parser::Extension_addition_alternatives_groupContext * /*ctx*/) override { }

  virtual void enterAlternative_type_list(asn1Parser::Alternative_type_listContext * /*ctx*/) override { }
  virtual void exitAlternative_type_list(asn1Parser::Alternative_type_listContext * /*ctx*/) override { }

  virtual void enterChoice_value(asn1Parser::Choice_valueContext * /*ctx*/) override { }
  virtual void exitChoice_value(asn1Parser::Choice_valueContext * /*ctx*/) override { }

  virtual void enterSelection_type(asn1Parser::Selection_typeContext * /*ctx*/) override { }
  virtual void exitSelection_type(asn1Parser::Selection_typeContext * /*ctx*/) override { }

  virtual void enterPrefixed_type(asn1Parser::Prefixed_typeContext * /*ctx*/) override { }
  virtual void exitPrefixed_type(asn1Parser::Prefixed_typeContext * /*ctx*/) override { }

  virtual void enterTagged_type(asn1Parser::Tagged_typeContext * /*ctx*/) override { }
  virtual void exitTagged_type(asn1Parser::Tagged_typeContext * /*ctx*/) override { }

  virtual void enterTag(asn1Parser::TagContext * /*ctx*/) override { }
  virtual void exitTag(asn1Parser::TagContext * /*ctx*/) override { }

  virtual void enterClass_number(asn1Parser::Class_numberContext * /*ctx*/) override { }
  virtual void exitClass_number(asn1Parser::Class_numberContext * /*ctx*/) override { }

  virtual void enterCategory(asn1Parser::CategoryContext * /*ctx*/) override { }
  virtual void exitCategory(asn1Parser::CategoryContext * /*ctx*/) override { }

  virtual void enterEncoding_prefixed_type(asn1Parser::Encoding_prefixed_typeContext * /*ctx*/) override { }
  virtual void exitEncoding_prefixed_type(asn1Parser::Encoding_prefixed_typeContext * /*ctx*/) override { }

  virtual void enterEncoding_prefix(asn1Parser::Encoding_prefixContext * /*ctx*/) override { }
  virtual void exitEncoding_prefix(asn1Parser::Encoding_prefixContext * /*ctx*/) override { }

  virtual void enterObject_identifier_value(asn1Parser::Object_identifier_valueContext * /*ctx*/) override { }
  virtual void exitObject_identifier_value(asn1Parser::Object_identifier_valueContext * /*ctx*/) override { }

  virtual void enterObj_id_components(asn1Parser::Obj_id_componentsContext * /*ctx*/) override { }
  virtual void exitObj_id_components(asn1Parser::Obj_id_componentsContext * /*ctx*/) override { }

  virtual void enterName_form(asn1Parser::Name_formContext * /*ctx*/) override { }
  virtual void exitName_form(asn1Parser::Name_formContext * /*ctx*/) override { }

  virtual void enterNumber_form(asn1Parser::Number_formContext * /*ctx*/) override { }
  virtual void exitNumber_form(asn1Parser::Number_formContext * /*ctx*/) override { }

  virtual void enterName_and_number_form(asn1Parser::Name_and_number_formContext * /*ctx*/) override { }
  virtual void exitName_and_number_form(asn1Parser::Name_and_number_formContext * /*ctx*/) override { }

  virtual void enterRelative_oid_value(asn1Parser::Relative_oid_valueContext * /*ctx*/) override { }
  virtual void exitRelative_oid_value(asn1Parser::Relative_oid_valueContext * /*ctx*/) override { }

  virtual void enterRelative_oid_components_list(asn1Parser::Relative_oid_components_listContext * /*ctx*/) override { }
  virtual void exitRelative_oid_components_list(asn1Parser::Relative_oid_components_listContext * /*ctx*/) override { }

  virtual void enterRelative_oid_components(asn1Parser::Relative_oid_componentsContext * /*ctx*/) override { }
  virtual void exitRelative_oid_components(asn1Parser::Relative_oid_componentsContext * /*ctx*/) override { }

  virtual void enterIri_value(asn1Parser::Iri_valueContext * /*ctx*/) override { }
  virtual void exitIri_value(asn1Parser::Iri_valueContext * /*ctx*/) override { }

  virtual void enterArc_identifier(asn1Parser::Arc_identifierContext * /*ctx*/) override { }
  virtual void exitArc_identifier(asn1Parser::Arc_identifierContext * /*ctx*/) override { }

  virtual void enterRelative_iri_value(asn1Parser::Relative_iri_valueContext * /*ctx*/) override { }
  virtual void exitRelative_iri_value(asn1Parser::Relative_iri_valueContext * /*ctx*/) override { }

  virtual void enterEmbedded_pdv_value(asn1Parser::Embedded_pdv_valueContext * /*ctx*/) override { }
  virtual void exitEmbedded_pdv_value(asn1Parser::Embedded_pdv_valueContext * /*ctx*/) override { }

  virtual void enterTime_value(asn1Parser::Time_valueContext * /*ctx*/) override { }
  virtual void exitTime_value(asn1Parser::Time_valueContext * /*ctx*/) override { }

  virtual void enterCharacter_string_type(asn1Parser::Character_string_typeContext * /*ctx*/) override { }
  virtual void exitCharacter_string_type(asn1Parser::Character_string_typeContext * /*ctx*/) override { }

  virtual void enterCharacter_string_value(asn1Parser::Character_string_valueContext * /*ctx*/) override { }
  virtual void exitCharacter_string_value(asn1Parser::Character_string_valueContext * /*ctx*/) override { }

  virtual void enterRestricted_character_string_type(asn1Parser::Restricted_character_string_typeContext * /*ctx*/) override { }
  virtual void exitRestricted_character_string_type(asn1Parser::Restricted_character_string_typeContext * /*ctx*/) override { }

  virtual void enterRestricted_character_string_value(asn1Parser::Restricted_character_string_valueContext * /*ctx*/) override { }
  virtual void exitRestricted_character_string_value(asn1Parser::Restricted_character_string_valueContext * /*ctx*/) override { }

  virtual void enterCharacter_string_list(asn1Parser::Character_string_listContext * /*ctx*/) override { }
  virtual void exitCharacter_string_list(asn1Parser::Character_string_listContext * /*ctx*/) override { }

  virtual void enterChars_defn(asn1Parser::Chars_defnContext * /*ctx*/) override { }
  virtual void exitChars_defn(asn1Parser::Chars_defnContext * /*ctx*/) override { }

  virtual void enterQuadruple(asn1Parser::QuadrupleContext * /*ctx*/) override { }
  virtual void exitQuadruple(asn1Parser::QuadrupleContext * /*ctx*/) override { }

  virtual void enterGroup(asn1Parser::GroupContext * /*ctx*/) override { }
  virtual void exitGroup(asn1Parser::GroupContext * /*ctx*/) override { }

  virtual void enterPlane(asn1Parser::PlaneContext * /*ctx*/) override { }
  virtual void exitPlane(asn1Parser::PlaneContext * /*ctx*/) override { }

  virtual void enterRow(asn1Parser::RowContext * /*ctx*/) override { }
  virtual void exitRow(asn1Parser::RowContext * /*ctx*/) override { }

  virtual void enterCell(asn1Parser::CellContext * /*ctx*/) override { }
  virtual void exitCell(asn1Parser::CellContext * /*ctx*/) override { }

  virtual void enterTuple(asn1Parser::TupleContext * /*ctx*/) override { }
  virtual void exitTuple(asn1Parser::TupleContext * /*ctx*/) override { }

  virtual void enterTable_column(asn1Parser::Table_columnContext * /*ctx*/) override { }
  virtual void exitTable_column(asn1Parser::Table_columnContext * /*ctx*/) override { }

  virtual void enterTable_row(asn1Parser::Table_rowContext * /*ctx*/) override { }
  virtual void exitTable_row(asn1Parser::Table_rowContext * /*ctx*/) override { }

  virtual void enterUnrestricted_character_string_type(asn1Parser::Unrestricted_character_string_typeContext * /*ctx*/) override { }
  virtual void exitUnrestricted_character_string_type(asn1Parser::Unrestricted_character_string_typeContext * /*ctx*/) override { }

  virtual void enterUnrestricted_character_string_value(asn1Parser::Unrestricted_character_string_valueContext * /*ctx*/) override { }
  virtual void exitUnrestricted_character_string_value(asn1Parser::Unrestricted_character_string_valueContext * /*ctx*/) override { }

  virtual void enterUseful_type(asn1Parser::Useful_typeContext * /*ctx*/) override { }
  virtual void exitUseful_type(asn1Parser::Useful_typeContext * /*ctx*/) override { }

  virtual void enterConstrained_type(asn1Parser::Constrained_typeContext * /*ctx*/) override { }
  virtual void exitConstrained_type(asn1Parser::Constrained_typeContext * /*ctx*/) override { }

  virtual void enterType_with_constraint(asn1Parser::Type_with_constraintContext * /*ctx*/) override { }
  virtual void exitType_with_constraint(asn1Parser::Type_with_constraintContext * /*ctx*/) override { }

  virtual void enterConstraint(asn1Parser::ConstraintContext * /*ctx*/) override { }
  virtual void exitConstraint(asn1Parser::ConstraintContext * /*ctx*/) override { }

  virtual void enterSize_constraint(asn1Parser::Size_constraintContext * /*ctx*/) override { }
  virtual void exitSize_constraint(asn1Parser::Size_constraintContext * /*ctx*/) override { }

  virtual void enterConstraint_spec(asn1Parser::Constraint_specContext * /*ctx*/) override { }
  virtual void exitConstraint_spec(asn1Parser::Constraint_specContext * /*ctx*/) override { }

  virtual void enterSubtype_constraint(asn1Parser::Subtype_constraintContext * /*ctx*/) override { }
  virtual void exitSubtype_constraint(asn1Parser::Subtype_constraintContext * /*ctx*/) override { }

  virtual void enterElement_set_specs(asn1Parser::Element_set_specsContext * /*ctx*/) override { }
  virtual void exitElement_set_specs(asn1Parser::Element_set_specsContext * /*ctx*/) override { }

  virtual void enterRoot_element_set_spec(asn1Parser::Root_element_set_specContext * /*ctx*/) override { }
  virtual void exitRoot_element_set_spec(asn1Parser::Root_element_set_specContext * /*ctx*/) override { }

  virtual void enterAdditional_element_set_spec(asn1Parser::Additional_element_set_specContext * /*ctx*/) override { }
  virtual void exitAdditional_element_set_spec(asn1Parser::Additional_element_set_specContext * /*ctx*/) override { }

  virtual void enterElement_set_spec(asn1Parser::Element_set_specContext * /*ctx*/) override { }
  virtual void exitElement_set_spec(asn1Parser::Element_set_specContext * /*ctx*/) override { }

  virtual void enterUnions(asn1Parser::UnionsContext * /*ctx*/) override { }
  virtual void exitUnions(asn1Parser::UnionsContext * /*ctx*/) override { }

  virtual void enterIntersections(asn1Parser::IntersectionsContext * /*ctx*/) override { }
  virtual void exitIntersections(asn1Parser::IntersectionsContext * /*ctx*/) override { }

  virtual void enterIntersection_elements(asn1Parser::Intersection_elementsContext * /*ctx*/) override { }
  virtual void exitIntersection_elements(asn1Parser::Intersection_elementsContext * /*ctx*/) override { }

  virtual void enterElems(asn1Parser::ElemsContext * /*ctx*/) override { }
  virtual void exitElems(asn1Parser::ElemsContext * /*ctx*/) override { }

  virtual void enterExclusions(asn1Parser::ExclusionsContext * /*ctx*/) override { }
  virtual void exitExclusions(asn1Parser::ExclusionsContext * /*ctx*/) override { }

  virtual void enterUnion_mark(asn1Parser::Union_markContext * /*ctx*/) override { }
  virtual void exitUnion_mark(asn1Parser::Union_markContext * /*ctx*/) override { }

  virtual void enterIntersection_mark(asn1Parser::Intersection_markContext * /*ctx*/) override { }
  virtual void exitIntersection_mark(asn1Parser::Intersection_markContext * /*ctx*/) override { }

  virtual void enterElements(asn1Parser::ElementsContext * /*ctx*/) override { }
  virtual void exitElements(asn1Parser::ElementsContext * /*ctx*/) override { }

  virtual void enterSubtype_elements(asn1Parser::Subtype_elementsContext * /*ctx*/) override { }
  virtual void exitSubtype_elements(asn1Parser::Subtype_elementsContext * /*ctx*/) override { }

  virtual void enterSingle_value(asn1Parser::Single_valueContext * /*ctx*/) override { }
  virtual void exitSingle_value(asn1Parser::Single_valueContext * /*ctx*/) override { }

  virtual void enterContained_subtype(asn1Parser::Contained_subtypeContext * /*ctx*/) override { }
  virtual void exitContained_subtype(asn1Parser::Contained_subtypeContext * /*ctx*/) override { }

  virtual void enterIncludes(asn1Parser::IncludesContext * /*ctx*/) override { }
  virtual void exitIncludes(asn1Parser::IncludesContext * /*ctx*/) override { }

  virtual void enterValue_range(asn1Parser::Value_rangeContext * /*ctx*/) override { }
  virtual void exitValue_range(asn1Parser::Value_rangeContext * /*ctx*/) override { }

  virtual void enterLower_endpoint(asn1Parser::Lower_endpointContext * /*ctx*/) override { }
  virtual void exitLower_endpoint(asn1Parser::Lower_endpointContext * /*ctx*/) override { }

  virtual void enterUpper_endpoint(asn1Parser::Upper_endpointContext * /*ctx*/) override { }
  virtual void exitUpper_endpoint(asn1Parser::Upper_endpointContext * /*ctx*/) override { }

  virtual void enterLower_end_value(asn1Parser::Lower_end_valueContext * /*ctx*/) override { }
  virtual void exitLower_end_value(asn1Parser::Lower_end_valueContext * /*ctx*/) override { }

  virtual void enterUpper_end_value(asn1Parser::Upper_end_valueContext * /*ctx*/) override { }
  virtual void exitUpper_end_value(asn1Parser::Upper_end_valueContext * /*ctx*/) override { }

  virtual void enterType_constraint(asn1Parser::Type_constraintContext * /*ctx*/) override { }
  virtual void exitType_constraint(asn1Parser::Type_constraintContext * /*ctx*/) override { }

  virtual void enterPermitted_alphabet(asn1Parser::Permitted_alphabetContext * /*ctx*/) override { }
  virtual void exitPermitted_alphabet(asn1Parser::Permitted_alphabetContext * /*ctx*/) override { }

  virtual void enterInner_type_constraints(asn1Parser::Inner_type_constraintsContext * /*ctx*/) override { }
  virtual void exitInner_type_constraints(asn1Parser::Inner_type_constraintsContext * /*ctx*/) override { }

  virtual void enterSingle_type_constraint(asn1Parser::Single_type_constraintContext * /*ctx*/) override { }
  virtual void exitSingle_type_constraint(asn1Parser::Single_type_constraintContext * /*ctx*/) override { }

  virtual void enterMultiple_type_constraints(asn1Parser::Multiple_type_constraintsContext * /*ctx*/) override { }
  virtual void exitMultiple_type_constraints(asn1Parser::Multiple_type_constraintsContext * /*ctx*/) override { }

  virtual void enterFull_specification(asn1Parser::Full_specificationContext * /*ctx*/) override { }
  virtual void exitFull_specification(asn1Parser::Full_specificationContext * /*ctx*/) override { }

  virtual void enterPartial_specification(asn1Parser::Partial_specificationContext * /*ctx*/) override { }
  virtual void exitPartial_specification(asn1Parser::Partial_specificationContext * /*ctx*/) override { }

  virtual void enterType_constraints(asn1Parser::Type_constraintsContext * /*ctx*/) override { }
  virtual void exitType_constraints(asn1Parser::Type_constraintsContext * /*ctx*/) override { }

  virtual void enterNamed_constraint(asn1Parser::Named_constraintContext * /*ctx*/) override { }
  virtual void exitNamed_constraint(asn1Parser::Named_constraintContext * /*ctx*/) override { }

  virtual void enterComponent_constraint(asn1Parser::Component_constraintContext * /*ctx*/) override { }
  virtual void exitComponent_constraint(asn1Parser::Component_constraintContext * /*ctx*/) override { }

  virtual void enterValue_constraint(asn1Parser::Value_constraintContext * /*ctx*/) override { }
  virtual void exitValue_constraint(asn1Parser::Value_constraintContext * /*ctx*/) override { }

  virtual void enterPresence_constraint(asn1Parser::Presence_constraintContext * /*ctx*/) override { }
  virtual void exitPresence_constraint(asn1Parser::Presence_constraintContext * /*ctx*/) override { }

  virtual void enterPattern_constraint(asn1Parser::Pattern_constraintContext * /*ctx*/) override { }
  virtual void exitPattern_constraint(asn1Parser::Pattern_constraintContext * /*ctx*/) override { }

  virtual void enterProperty_settings(asn1Parser::Property_settingsContext * /*ctx*/) override { }
  virtual void exitProperty_settings(asn1Parser::Property_settingsContext * /*ctx*/) override { }

  virtual void enterProperty_settings_list(asn1Parser::Property_settings_listContext * /*ctx*/) override { }
  virtual void exitProperty_settings_list(asn1Parser::Property_settings_listContext * /*ctx*/) override { }

  virtual void enterProperty_and_setting_pair(asn1Parser::Property_and_setting_pairContext * /*ctx*/) override { }
  virtual void exitProperty_and_setting_pair(asn1Parser::Property_and_setting_pairContext * /*ctx*/) override { }

  virtual void enterProperty_name(asn1Parser::Property_nameContext * /*ctx*/) override { }
  virtual void exitProperty_name(asn1Parser::Property_nameContext * /*ctx*/) override { }

  virtual void enterSetting_name(asn1Parser::Setting_nameContext * /*ctx*/) override { }
  virtual void exitSetting_name(asn1Parser::Setting_nameContext * /*ctx*/) override { }

  virtual void enterDuration_range(asn1Parser::Duration_rangeContext * /*ctx*/) override { }
  virtual void exitDuration_range(asn1Parser::Duration_rangeContext * /*ctx*/) override { }

  virtual void enterTime_point_range(asn1Parser::Time_point_rangeContext * /*ctx*/) override { }
  virtual void exitTime_point_range(asn1Parser::Time_point_rangeContext * /*ctx*/) override { }

  virtual void enterRecurrence_range(asn1Parser::Recurrence_rangeContext * /*ctx*/) override { }
  virtual void exitRecurrence_range(asn1Parser::Recurrence_rangeContext * /*ctx*/) override { }

  virtual void enterException_spec(asn1Parser::Exception_specContext * /*ctx*/) override { }
  virtual void exitException_spec(asn1Parser::Exception_specContext * /*ctx*/) override { }

  virtual void enterException_identification(asn1Parser::Exception_identificationContext * /*ctx*/) override { }
  virtual void exitException_identification(asn1Parser::Exception_identificationContext * /*ctx*/) override { }

  virtual void enterEncoding_control_sections(asn1Parser::Encoding_control_sectionsContext * /*ctx*/) override { }
  virtual void exitEncoding_control_sections(asn1Parser::Encoding_control_sectionsContext * /*ctx*/) override { }

  virtual void enterEncoding_control_section(asn1Parser::Encoding_control_sectionContext * /*ctx*/) override { }
  virtual void exitEncoding_control_section(asn1Parser::Encoding_control_sectionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

