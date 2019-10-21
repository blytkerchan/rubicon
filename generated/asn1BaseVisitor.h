
// Generated from asn1.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "asn1Visitor.h"


/**
 * This class provides an empty implementation of asn1Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  asn1BaseVisitor : public asn1Visitor {
public:

  virtual antlrcpp::Any visitFile(asn1Parser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_definition(asn1Parser::Module_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_identifier(asn1Parser::Module_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_identification(asn1Parser::Definitive_identificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_oid(asn1Parser::Definitive_oidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_oid_and_iri(asn1Parser::Definitive_oid_and_iriContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_object_id_component_list(asn1Parser::Definitive_object_id_component_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_object_id_component(asn1Parser::Definitive_object_id_componentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_number_form(asn1Parser::Definitive_number_formContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitive_name_and_number_form(asn1Parser::Definitive_name_and_number_formContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplicit_tags(asn1Parser::Explicit_tagsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImplicit_tags(asn1Parser::Implicit_tagsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAutomatic_tags(asn1Parser::Automatic_tagsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_default(asn1Parser::Extension_defaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_body(asn1Parser::Module_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExports(asn1Parser::ExportsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbols_exported(asn1Parser::Symbols_exportedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImports(asn1Parser::ImportsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbols_imported(asn1Parser::Symbols_importedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbols_from_module_list(asn1Parser::Symbols_from_module_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbols_from_module(asn1Parser::Symbols_from_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobal_module_reference(asn1Parser::Global_module_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssigned_identifier(asn1Parser::Assigned_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbol_list(asn1Parser::Symbol_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbol(asn1Parser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReference(asn1Parser::ReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_list(asn1Parser::Assignment_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(asn1Parser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefined_type(asn1Parser::Defined_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefined_value(asn1Parser::Defined_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternal_type_reference(asn1Parser::External_type_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternal_value_reference(asn1Parser::External_value_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAbsolute_reference(asn1Parser::Absolute_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitItem_spec(asn1Parser::Item_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_id(asn1Parser::Component_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_assignment(asn1Parser::Type_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_assignment(asn1Parser::Value_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_set_type_assignment(asn1Parser::Value_set_type_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_set(asn1Parser::Value_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(asn1Parser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltin_type(asn1Parser::Builtin_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReferenced_type(asn1Parser::Referenced_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_type(asn1Parser::Named_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAny_type(asn1Parser::Any_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(asn1Parser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltin_value(asn1Parser::Builtin_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_value(asn1Parser::Named_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_value(asn1Parser::Boolean_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_type(asn1Parser::Integer_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_number_list(asn1Parser::Named_number_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_number(asn1Parser::Named_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigned_number(asn1Parser::Signed_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_value(asn1Parser::Integer_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerated_type(asn1Parser::Enumerated_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerations(asn1Parser::EnumerationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoot_enumeration(asn1Parser::Root_enumerationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditional_enumeration(asn1Parser::Additional_enumerationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumeration(asn1Parser::EnumerationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumeration_item(asn1Parser::Enumeration_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumerated_value(asn1Parser::Enumerated_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal_value(asn1Parser::Real_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_string_type(asn1Parser::Bit_string_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_bit_list(asn1Parser::Named_bit_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_bit(asn1Parser::Named_bitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_string_value(asn1Parser::Bit_string_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_list(asn1Parser::Identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOctet_string_value(asn1Parser::Octet_string_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_or_set_type(asn1Parser::Sequence_or_set_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_or_set_of_type(asn1Parser::Sequence_or_set_of_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_and_exception(asn1Parser::Extension_and_exceptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptional_extension_marker(asn1Parser::Optional_extension_markerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_type_lists(asn1Parser::Component_type_listsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_end_marker(asn1Parser::Extension_end_markerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_additions(asn1Parser::Extension_additionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_list(asn1Parser::Extension_addition_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition(asn1Parser::Extension_additionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_group(asn1Parser::Extension_addition_groupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion_number(asn1Parser::Version_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_type_list(asn1Parser::Component_type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_type(asn1Parser::Component_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_value(asn1Parser::Sequence_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_value_list(asn1Parser::Component_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_of_value(asn1Parser::Sequence_of_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_list(asn1Parser::Value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_value_list(asn1Parser::Named_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet_value(asn1Parser::Set_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet_of_value(asn1Parser::Set_of_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChoice_type(asn1Parser::Choice_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlternative_type_lists(asn1Parser::Alternative_type_listsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoot_alternative_type_list(asn1Parser::Root_alternative_type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_alternatives(asn1Parser::Extension_addition_alternativesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_alternatives_list(asn1Parser::Extension_addition_alternatives_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_alternative(asn1Parser::Extension_addition_alternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtension_addition_alternatives_group(asn1Parser::Extension_addition_alternatives_groupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlternative_type_list(asn1Parser::Alternative_type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChoice_value(asn1Parser::Choice_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelection_type(asn1Parser::Selection_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrefixed_type(asn1Parser::Prefixed_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTagged_type(asn1Parser::Tagged_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTag(asn1Parser::TagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_number(asn1Parser::Class_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCategory(asn1Parser::CategoryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_prefixed_type(asn1Parser::Encoding_prefixed_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_prefix(asn1Parser::Encoding_prefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject_identifier_value(asn1Parser::Object_identifier_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObj_id_components(asn1Parser::Obj_id_componentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_form(asn1Parser::Name_formContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_form(asn1Parser::Number_formContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_and_number_form(asn1Parser::Name_and_number_formContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelative_oid_value(asn1Parser::Relative_oid_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelative_oid_components_list(asn1Parser::Relative_oid_components_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelative_oid_components(asn1Parser::Relative_oid_componentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIri_value(asn1Parser::Iri_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArc_identifier(asn1Parser::Arc_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelative_iri_value(asn1Parser::Relative_iri_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmbedded_pdv_value(asn1Parser::Embedded_pdv_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime_value(asn1Parser::Time_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacter_string_type(asn1Parser::Character_string_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacter_string_value(asn1Parser::Character_string_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRestricted_character_string_type(asn1Parser::Restricted_character_string_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRestricted_character_string_value(asn1Parser::Restricted_character_string_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacter_string_list(asn1Parser::Character_string_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChars_defn(asn1Parser::Chars_defnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuadruple(asn1Parser::QuadrupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup(asn1Parser::GroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlane(asn1Parser::PlaneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRow(asn1Parser::RowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell(asn1Parser::CellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTuple(asn1Parser::TupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_column(asn1Parser::Table_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_row(asn1Parser::Table_rowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnrestricted_character_string_type(asn1Parser::Unrestricted_character_string_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnrestricted_character_string_value(asn1Parser::Unrestricted_character_string_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUseful_type(asn1Parser::Useful_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstrained_type(asn1Parser::Constrained_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_with_constraint(asn1Parser::Type_with_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint(asn1Parser::ConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSize_constraint(asn1Parser::Size_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_spec(asn1Parser::Constraint_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtype_constraint(asn1Parser::Subtype_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_set_specs(asn1Parser::Element_set_specsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRoot_element_set_spec(asn1Parser::Root_element_set_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditional_element_set_spec(asn1Parser::Additional_element_set_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement_set_spec(asn1Parser::Element_set_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnions(asn1Parser::UnionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntersections(asn1Parser::IntersectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntersection_elements(asn1Parser::Intersection_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElems(asn1Parser::ElemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExclusions(asn1Parser::ExclusionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnion_mark(asn1Parser::Union_markContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntersection_mark(asn1Parser::Intersection_markContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElements(asn1Parser::ElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubtype_elements(asn1Parser::Subtype_elementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingle_value(asn1Parser::Single_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContained_subtype(asn1Parser::Contained_subtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncludes(asn1Parser::IncludesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_range(asn1Parser::Value_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLower_endpoint(asn1Parser::Lower_endpointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpper_endpoint(asn1Parser::Upper_endpointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLower_end_value(asn1Parser::Lower_end_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpper_end_value(asn1Parser::Upper_end_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_constraint(asn1Parser::Type_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPermitted_alphabet(asn1Parser::Permitted_alphabetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInner_type_constraints(asn1Parser::Inner_type_constraintsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingle_type_constraint(asn1Parser::Single_type_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiple_type_constraints(asn1Parser::Multiple_type_constraintsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_specification(asn1Parser::Full_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartial_specification(asn1Parser::Partial_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_constraints(asn1Parser::Type_constraintsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_constraint(asn1Parser::Named_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComponent_constraint(asn1Parser::Component_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_constraint(asn1Parser::Value_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPresence_constraint(asn1Parser::Presence_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPattern_constraint(asn1Parser::Pattern_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_settings(asn1Parser::Property_settingsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_settings_list(asn1Parser::Property_settings_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_and_setting_pair(asn1Parser::Property_and_setting_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_name(asn1Parser::Property_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetting_name(asn1Parser::Setting_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDuration_range(asn1Parser::Duration_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime_point_range(asn1Parser::Time_point_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecurrence_range(asn1Parser::Recurrence_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitException_spec(asn1Parser::Exception_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitException_identification(asn1Parser::Exception_identificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_control_sections(asn1Parser::Encoding_control_sectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_control_section(asn1Parser::Encoding_control_sectionContext *ctx) override {
    return visitChildren(ctx);
  }


};

