
// Generated from asn1.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "asn1Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by asn1Parser.
 */
class  asn1Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by asn1Parser.
   */
    virtual antlrcpp::Any visitFile(asn1Parser::FileContext *context) = 0;

    virtual antlrcpp::Any visitModule_definition(asn1Parser::Module_definitionContext *context) = 0;

    virtual antlrcpp::Any visitModule_identifier(asn1Parser::Module_identifierContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_identification(asn1Parser::Definitive_identificationContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_oid(asn1Parser::Definitive_oidContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_oid_and_iri(asn1Parser::Definitive_oid_and_iriContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_object_id_component_list(asn1Parser::Definitive_object_id_component_listContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_object_id_component(asn1Parser::Definitive_object_id_componentContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_number_form(asn1Parser::Definitive_number_formContext *context) = 0;

    virtual antlrcpp::Any visitDefinitive_name_and_number_form(asn1Parser::Definitive_name_and_number_formContext *context) = 0;

    virtual antlrcpp::Any visitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext *context) = 0;

    virtual antlrcpp::Any visitExplicit_tags(asn1Parser::Explicit_tagsContext *context) = 0;

    virtual antlrcpp::Any visitImplicit_tags(asn1Parser::Implicit_tagsContext *context) = 0;

    virtual antlrcpp::Any visitAutomatic_tags(asn1Parser::Automatic_tagsContext *context) = 0;

    virtual antlrcpp::Any visitExtension_default(asn1Parser::Extension_defaultContext *context) = 0;

    virtual antlrcpp::Any visitModule_body(asn1Parser::Module_bodyContext *context) = 0;

    virtual antlrcpp::Any visitExports(asn1Parser::ExportsContext *context) = 0;

    virtual antlrcpp::Any visitSymbols_exported(asn1Parser::Symbols_exportedContext *context) = 0;

    virtual antlrcpp::Any visitImports(asn1Parser::ImportsContext *context) = 0;

    virtual antlrcpp::Any visitSymbols_imported(asn1Parser::Symbols_importedContext *context) = 0;

    virtual antlrcpp::Any visitSymbols_from_module_list(asn1Parser::Symbols_from_module_listContext *context) = 0;

    virtual antlrcpp::Any visitSymbols_from_module(asn1Parser::Symbols_from_moduleContext *context) = 0;

    virtual antlrcpp::Any visitGlobal_module_reference(asn1Parser::Global_module_referenceContext *context) = 0;

    virtual antlrcpp::Any visitAssigned_identifier(asn1Parser::Assigned_identifierContext *context) = 0;

    virtual antlrcpp::Any visitSymbol_list(asn1Parser::Symbol_listContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(asn1Parser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitReference(asn1Parser::ReferenceContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_list(asn1Parser::Assignment_listContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(asn1Parser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitDefined_type(asn1Parser::Defined_typeContext *context) = 0;

    virtual antlrcpp::Any visitDefined_value(asn1Parser::Defined_valueContext *context) = 0;

    virtual antlrcpp::Any visitExternal_type_reference(asn1Parser::External_type_referenceContext *context) = 0;

    virtual antlrcpp::Any visitExternal_value_reference(asn1Parser::External_value_referenceContext *context) = 0;

    virtual antlrcpp::Any visitAbsolute_reference(asn1Parser::Absolute_referenceContext *context) = 0;

    virtual antlrcpp::Any visitItem_spec(asn1Parser::Item_specContext *context) = 0;

    virtual antlrcpp::Any visitComponent_id(asn1Parser::Component_idContext *context) = 0;

    virtual antlrcpp::Any visitType_assignment(asn1Parser::Type_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitValue_assignment(asn1Parser::Value_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitValue_set_type_assignment(asn1Parser::Value_set_type_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitValue_set(asn1Parser::Value_setContext *context) = 0;

    virtual antlrcpp::Any visitType(asn1Parser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitBuiltin_type(asn1Parser::Builtin_typeContext *context) = 0;

    virtual antlrcpp::Any visitReferenced_type(asn1Parser::Referenced_typeContext *context) = 0;

    virtual antlrcpp::Any visitNamed_type(asn1Parser::Named_typeContext *context) = 0;

    virtual antlrcpp::Any visitAny_type(asn1Parser::Any_typeContext *context) = 0;

    virtual antlrcpp::Any visitValue(asn1Parser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitBuiltin_value(asn1Parser::Builtin_valueContext *context) = 0;

    virtual antlrcpp::Any visitNamed_value(asn1Parser::Named_valueContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_value(asn1Parser::Boolean_valueContext *context) = 0;

    virtual antlrcpp::Any visitInteger_type(asn1Parser::Integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitNamed_number_list(asn1Parser::Named_number_listContext *context) = 0;

    virtual antlrcpp::Any visitNamed_number(asn1Parser::Named_numberContext *context) = 0;

    virtual antlrcpp::Any visitSigned_number(asn1Parser::Signed_numberContext *context) = 0;

    virtual antlrcpp::Any visitInteger_value(asn1Parser::Integer_valueContext *context) = 0;

    virtual antlrcpp::Any visitEnumerated_type(asn1Parser::Enumerated_typeContext *context) = 0;

    virtual antlrcpp::Any visitEnumerations(asn1Parser::EnumerationsContext *context) = 0;

    virtual antlrcpp::Any visitRoot_enumeration(asn1Parser::Root_enumerationContext *context) = 0;

    virtual antlrcpp::Any visitAdditional_enumeration(asn1Parser::Additional_enumerationContext *context) = 0;

    virtual antlrcpp::Any visitEnumeration(asn1Parser::EnumerationContext *context) = 0;

    virtual antlrcpp::Any visitEnumeration_item(asn1Parser::Enumeration_itemContext *context) = 0;

    virtual antlrcpp::Any visitEnumerated_value(asn1Parser::Enumerated_valueContext *context) = 0;

    virtual antlrcpp::Any visitReal_value(asn1Parser::Real_valueContext *context) = 0;

    virtual antlrcpp::Any visitBit_string_type(asn1Parser::Bit_string_typeContext *context) = 0;

    virtual antlrcpp::Any visitNamed_bit_list(asn1Parser::Named_bit_listContext *context) = 0;

    virtual antlrcpp::Any visitNamed_bit(asn1Parser::Named_bitContext *context) = 0;

    virtual antlrcpp::Any visitBit_string_value(asn1Parser::Bit_string_valueContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_list(asn1Parser::Identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitOctet_string_value(asn1Parser::Octet_string_valueContext *context) = 0;

    virtual antlrcpp::Any visitSequence_or_set_type(asn1Parser::Sequence_or_set_typeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_or_set_of_type(asn1Parser::Sequence_or_set_of_typeContext *context) = 0;

    virtual antlrcpp::Any visitExtension_and_exception(asn1Parser::Extension_and_exceptionContext *context) = 0;

    virtual antlrcpp::Any visitOptional_extension_marker(asn1Parser::Optional_extension_markerContext *context) = 0;

    virtual antlrcpp::Any visitComponent_type_lists(asn1Parser::Component_type_listsContext *context) = 0;

    virtual antlrcpp::Any visitExtension_end_marker(asn1Parser::Extension_end_markerContext *context) = 0;

    virtual antlrcpp::Any visitExtension_additions(asn1Parser::Extension_additionsContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_list(asn1Parser::Extension_addition_listContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition(asn1Parser::Extension_additionContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_group(asn1Parser::Extension_addition_groupContext *context) = 0;

    virtual antlrcpp::Any visitVersion_number(asn1Parser::Version_numberContext *context) = 0;

    virtual antlrcpp::Any visitComponent_type_list(asn1Parser::Component_type_listContext *context) = 0;

    virtual antlrcpp::Any visitComponent_type(asn1Parser::Component_typeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_value(asn1Parser::Sequence_valueContext *context) = 0;

    virtual antlrcpp::Any visitComponent_value_list(asn1Parser::Component_value_listContext *context) = 0;

    virtual antlrcpp::Any visitSequence_of_value(asn1Parser::Sequence_of_valueContext *context) = 0;

    virtual antlrcpp::Any visitValue_list(asn1Parser::Value_listContext *context) = 0;

    virtual antlrcpp::Any visitNamed_value_list(asn1Parser::Named_value_listContext *context) = 0;

    virtual antlrcpp::Any visitSet_value(asn1Parser::Set_valueContext *context) = 0;

    virtual antlrcpp::Any visitSet_of_value(asn1Parser::Set_of_valueContext *context) = 0;

    virtual antlrcpp::Any visitChoice_type(asn1Parser::Choice_typeContext *context) = 0;

    virtual antlrcpp::Any visitAlternative_type_lists(asn1Parser::Alternative_type_listsContext *context) = 0;

    virtual antlrcpp::Any visitRoot_alternative_type_list(asn1Parser::Root_alternative_type_listContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_alternatives(asn1Parser::Extension_addition_alternativesContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_alternatives_list(asn1Parser::Extension_addition_alternatives_listContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_alternative(asn1Parser::Extension_addition_alternativeContext *context) = 0;

    virtual antlrcpp::Any visitExtension_addition_alternatives_group(asn1Parser::Extension_addition_alternatives_groupContext *context) = 0;

    virtual antlrcpp::Any visitAlternative_type_list(asn1Parser::Alternative_type_listContext *context) = 0;

    virtual antlrcpp::Any visitChoice_value(asn1Parser::Choice_valueContext *context) = 0;

    virtual antlrcpp::Any visitSelection_type(asn1Parser::Selection_typeContext *context) = 0;

    virtual antlrcpp::Any visitPrefixed_type(asn1Parser::Prefixed_typeContext *context) = 0;

    virtual antlrcpp::Any visitTagged_type(asn1Parser::Tagged_typeContext *context) = 0;

    virtual antlrcpp::Any visitTag(asn1Parser::TagContext *context) = 0;

    virtual antlrcpp::Any visitClass_number(asn1Parser::Class_numberContext *context) = 0;

    virtual antlrcpp::Any visitCategory(asn1Parser::CategoryContext *context) = 0;

    virtual antlrcpp::Any visitEncoding_prefixed_type(asn1Parser::Encoding_prefixed_typeContext *context) = 0;

    virtual antlrcpp::Any visitEncoding_prefix(asn1Parser::Encoding_prefixContext *context) = 0;

    virtual antlrcpp::Any visitObject_identifier_value(asn1Parser::Object_identifier_valueContext *context) = 0;

    virtual antlrcpp::Any visitObj_id_components(asn1Parser::Obj_id_componentsContext *context) = 0;

    virtual antlrcpp::Any visitName_form(asn1Parser::Name_formContext *context) = 0;

    virtual antlrcpp::Any visitNumber_form(asn1Parser::Number_formContext *context) = 0;

    virtual antlrcpp::Any visitName_and_number_form(asn1Parser::Name_and_number_formContext *context) = 0;

    virtual antlrcpp::Any visitRelative_oid_value(asn1Parser::Relative_oid_valueContext *context) = 0;

    virtual antlrcpp::Any visitRelative_oid_components_list(asn1Parser::Relative_oid_components_listContext *context) = 0;

    virtual antlrcpp::Any visitRelative_oid_components(asn1Parser::Relative_oid_componentsContext *context) = 0;

    virtual antlrcpp::Any visitIri_value(asn1Parser::Iri_valueContext *context) = 0;

    virtual antlrcpp::Any visitArc_identifier(asn1Parser::Arc_identifierContext *context) = 0;

    virtual antlrcpp::Any visitRelative_iri_value(asn1Parser::Relative_iri_valueContext *context) = 0;

    virtual antlrcpp::Any visitEmbedded_pdv_value(asn1Parser::Embedded_pdv_valueContext *context) = 0;

    virtual antlrcpp::Any visitTime_value(asn1Parser::Time_valueContext *context) = 0;

    virtual antlrcpp::Any visitCharacter_string_type(asn1Parser::Character_string_typeContext *context) = 0;

    virtual antlrcpp::Any visitCharacter_string_value(asn1Parser::Character_string_valueContext *context) = 0;

    virtual antlrcpp::Any visitRestricted_character_string_type(asn1Parser::Restricted_character_string_typeContext *context) = 0;

    virtual antlrcpp::Any visitRestricted_character_string_value(asn1Parser::Restricted_character_string_valueContext *context) = 0;

    virtual antlrcpp::Any visitCharacter_string_list(asn1Parser::Character_string_listContext *context) = 0;

    virtual antlrcpp::Any visitChars_defn(asn1Parser::Chars_defnContext *context) = 0;

    virtual antlrcpp::Any visitQuadruple(asn1Parser::QuadrupleContext *context) = 0;

    virtual antlrcpp::Any visitGroup(asn1Parser::GroupContext *context) = 0;

    virtual antlrcpp::Any visitPlane(asn1Parser::PlaneContext *context) = 0;

    virtual antlrcpp::Any visitRow(asn1Parser::RowContext *context) = 0;

    virtual antlrcpp::Any visitCell(asn1Parser::CellContext *context) = 0;

    virtual antlrcpp::Any visitTuple(asn1Parser::TupleContext *context) = 0;

    virtual antlrcpp::Any visitTable_column(asn1Parser::Table_columnContext *context) = 0;

    virtual antlrcpp::Any visitTable_row(asn1Parser::Table_rowContext *context) = 0;

    virtual antlrcpp::Any visitUnrestricted_character_string_type(asn1Parser::Unrestricted_character_string_typeContext *context) = 0;

    virtual antlrcpp::Any visitUnrestricted_character_string_value(asn1Parser::Unrestricted_character_string_valueContext *context) = 0;

    virtual antlrcpp::Any visitUseful_type(asn1Parser::Useful_typeContext *context) = 0;

    virtual antlrcpp::Any visitConstrained_type(asn1Parser::Constrained_typeContext *context) = 0;

    virtual antlrcpp::Any visitType_with_constraint(asn1Parser::Type_with_constraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraint(asn1Parser::ConstraintContext *context) = 0;

    virtual antlrcpp::Any visitSize_constraint(asn1Parser::Size_constraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_spec(asn1Parser::Constraint_specContext *context) = 0;

    virtual antlrcpp::Any visitSubtype_constraint(asn1Parser::Subtype_constraintContext *context) = 0;

    virtual antlrcpp::Any visitElement_set_specs(asn1Parser::Element_set_specsContext *context) = 0;

    virtual antlrcpp::Any visitRoot_element_set_spec(asn1Parser::Root_element_set_specContext *context) = 0;

    virtual antlrcpp::Any visitAdditional_element_set_spec(asn1Parser::Additional_element_set_specContext *context) = 0;

    virtual antlrcpp::Any visitElement_set_spec(asn1Parser::Element_set_specContext *context) = 0;

    virtual antlrcpp::Any visitUnions(asn1Parser::UnionsContext *context) = 0;

    virtual antlrcpp::Any visitIntersections(asn1Parser::IntersectionsContext *context) = 0;

    virtual antlrcpp::Any visitIntersection_elements(asn1Parser::Intersection_elementsContext *context) = 0;

    virtual antlrcpp::Any visitElems(asn1Parser::ElemsContext *context) = 0;

    virtual antlrcpp::Any visitExclusions(asn1Parser::ExclusionsContext *context) = 0;

    virtual antlrcpp::Any visitUnion_mark(asn1Parser::Union_markContext *context) = 0;

    virtual antlrcpp::Any visitIntersection_mark(asn1Parser::Intersection_markContext *context) = 0;

    virtual antlrcpp::Any visitElements(asn1Parser::ElementsContext *context) = 0;

    virtual antlrcpp::Any visitSubtype_elements(asn1Parser::Subtype_elementsContext *context) = 0;

    virtual antlrcpp::Any visitSingle_value(asn1Parser::Single_valueContext *context) = 0;

    virtual antlrcpp::Any visitContained_subtype(asn1Parser::Contained_subtypeContext *context) = 0;

    virtual antlrcpp::Any visitIncludes(asn1Parser::IncludesContext *context) = 0;

    virtual antlrcpp::Any visitValue_range(asn1Parser::Value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitLower_endpoint(asn1Parser::Lower_endpointContext *context) = 0;

    virtual antlrcpp::Any visitUpper_endpoint(asn1Parser::Upper_endpointContext *context) = 0;

    virtual antlrcpp::Any visitLower_end_value(asn1Parser::Lower_end_valueContext *context) = 0;

    virtual antlrcpp::Any visitUpper_end_value(asn1Parser::Upper_end_valueContext *context) = 0;

    virtual antlrcpp::Any visitType_constraint(asn1Parser::Type_constraintContext *context) = 0;

    virtual antlrcpp::Any visitPermitted_alphabet(asn1Parser::Permitted_alphabetContext *context) = 0;

    virtual antlrcpp::Any visitInner_type_constraints(asn1Parser::Inner_type_constraintsContext *context) = 0;

    virtual antlrcpp::Any visitSingle_type_constraint(asn1Parser::Single_type_constraintContext *context) = 0;

    virtual antlrcpp::Any visitMultiple_type_constraints(asn1Parser::Multiple_type_constraintsContext *context) = 0;

    virtual antlrcpp::Any visitFull_specification(asn1Parser::Full_specificationContext *context) = 0;

    virtual antlrcpp::Any visitPartial_specification(asn1Parser::Partial_specificationContext *context) = 0;

    virtual antlrcpp::Any visitType_constraints(asn1Parser::Type_constraintsContext *context) = 0;

    virtual antlrcpp::Any visitNamed_constraint(asn1Parser::Named_constraintContext *context) = 0;

    virtual antlrcpp::Any visitComponent_constraint(asn1Parser::Component_constraintContext *context) = 0;

    virtual antlrcpp::Any visitValue_constraint(asn1Parser::Value_constraintContext *context) = 0;

    virtual antlrcpp::Any visitPresence_constraint(asn1Parser::Presence_constraintContext *context) = 0;

    virtual antlrcpp::Any visitPattern_constraint(asn1Parser::Pattern_constraintContext *context) = 0;

    virtual antlrcpp::Any visitProperty_settings(asn1Parser::Property_settingsContext *context) = 0;

    virtual antlrcpp::Any visitProperty_settings_list(asn1Parser::Property_settings_listContext *context) = 0;

    virtual antlrcpp::Any visitProperty_and_setting_pair(asn1Parser::Property_and_setting_pairContext *context) = 0;

    virtual antlrcpp::Any visitProperty_name(asn1Parser::Property_nameContext *context) = 0;

    virtual antlrcpp::Any visitSetting_name(asn1Parser::Setting_nameContext *context) = 0;

    virtual antlrcpp::Any visitDuration_range(asn1Parser::Duration_rangeContext *context) = 0;

    virtual antlrcpp::Any visitTime_point_range(asn1Parser::Time_point_rangeContext *context) = 0;

    virtual antlrcpp::Any visitRecurrence_range(asn1Parser::Recurrence_rangeContext *context) = 0;

    virtual antlrcpp::Any visitException_spec(asn1Parser::Exception_specContext *context) = 0;

    virtual antlrcpp::Any visitException_identification(asn1Parser::Exception_identificationContext *context) = 0;

    virtual antlrcpp::Any visitEncoding_control_sections(asn1Parser::Encoding_control_sectionsContext *context) = 0;

    virtual antlrcpp::Any visitEncoding_control_section(asn1Parser::Encoding_control_sectionContext *context) = 0;


};

