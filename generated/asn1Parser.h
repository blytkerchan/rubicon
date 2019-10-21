
// Generated from asn1.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  asn1Parser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, ABSENT_RW = 17, ALL_RW = 18, APPLICATION_RW = 19, 
    AUTOMATIC_RW = 20, BEGIN_RW = 21, BIT_RW = 22, BOOLEAN_RW = 23, CHARACTER_RW = 24, 
    CHOICE_RW = 25, COMPONENTS_RW = 26, COMPONENT_RW = 27, CONTAINING_RW = 28, 
    DATE_RW = 29, DATE_TIME_RW = 30, DEFAULT_RW = 31, DEFINITIONS_RW = 32, 
    DURATION_RW = 33, EMBEDDED_RW = 34, ENCODING_CONTROL_RW = 35, END_RW = 36, 
    ENUMERATED_RW = 37, EXCEPT_RW = 38, EXPLICIT_RW = 39, EXPORTS_RW = 40, 
    EXTENSIBILITY_RW = 41, EXTERNAL_RW = 42, FALSE_RW = 43, FROM_RW = 44, 
    IDENTIFIER_RW = 45, IMPLICIT_RW = 46, IMPLIED_RW = 47, IMPORTS_RW = 48, 
    INCLUDES_RW = 49, INSTRUCTIONS_RW = 50, INTEGER_RW = 51, INTERSECTION_RW = 52, 
    MAX_RW = 53, MINUS_INFINITY_RW = 54, MIN_RW = 55, NOT_A_NUMBER_RW = 56, 
    NULL_RW = 57, OBJECT_RW = 58, OCTET_RW = 59, OF_RW = 60, OID_IRI_RW = 61, 
    OPTIONAL_RW = 62, PATTERN_RW = 63, PDV_RW = 64, PLUS_INFINITY_RW = 65, 
    PRESENT_RW = 66, PRIVATE_RW = 67, REAL_RW = 68, RELATIVE_OID_IRI_RW = 69, 
    RELATIVE_OID_RW = 70, SEQUENCE_RW = 71, SETTINGS_RW = 72, SET_RW = 73, 
    SIZE_RW = 74, STRING_RW = 75, TAGS_RW = 76, TIME_OF_DAY_RW = 77, TIME_RW = 78, 
    TRUE_RW = 79, UNION_RW = 80, UNIVERSAL_RW = 81, WITH_RW = 82, ANY_RW = 83, 
    DEFINED_RW = 84, BY_RW = 85, EXCLAMATION_MARK_TK = 86, QUOTATION_MARK_TK = 87, 
    LEFT_PARENTHESIS_TK = 88, RIGHT_PARENTHESIS_TK = 89, ASTERISK_TK = 90, 
    COMMA_TK = 91, FULL_STOP_TK = 92, SOLIDUS_TK = 93, COLON_TK = 94, SEMICOLON_TK = 95, 
    LESS_THAN_SIGN_TK = 96, EQUALS_SIGN_TK = 97, COMMERCIAL_AT_TK = 98, 
    LEFT_SQUARE_BRACKET_TK = 99, RIGHT_SQUARE_BRACKET_TK = 100, CIRCUMFLEX_ACCENT_TK = 101, 
    LEFT_CURLY_BRACKET_TK = 102, VERTICAL_LINE_TK = 103, RIGHT_CURLY_BRACKET_TK = 104, 
    HYPHEN_TK = 105, WS = 106, TYPE_REFERENCE_OR_MODULE_REFERENCE = 107, 
    IDENTIFIER = 108, TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT = 109, 
    NUMBER = 110, REAL_NUMBER = 111, BSTRING = 112, HSTRING = 113, CSTRING = 114, 
    SIMPLE_STRING = 115, TSTRING = 116, PS_NAME = 117, ASSIGNMENT = 118, 
    RANGE_SEPARATOR = 119, ELLIPSIS = 120, LEFT_VERSION_BRACKETS = 121, 
    RIGHT_VERSION_BRACKETS = 122, ENCODING_REFERENCE = 123
  };

  enum {
    RuleFile = 0, RuleModule_definition = 1, RuleModule_identifier = 2, 
    RuleDefinitive_identification = 3, RuleDefinitive_oid = 4, RuleDefinitive_oid_and_iri = 5, 
    RuleDefinitive_object_id_component_list = 6, RuleDefinitive_object_id_component = 7, 
    RuleDefinitive_number_form = 8, RuleDefinitive_name_and_number_form = 9, 
    RuleEncoding_reference_default = 10, RuleTag_default = 11, RuleExtension_default = 12, 
    RuleModule_body = 13, RuleExports = 14, RuleSymbols_exported = 15, RuleImports = 16, 
    RuleSymbols_imported = 17, RuleSymbols_from_module_list = 18, RuleSymbols_from_module = 19, 
    RuleGlobal_module_reference = 20, RuleAssigned_identifier = 21, RuleSymbol_list = 22, 
    RuleSymbol = 23, RuleReference = 24, RuleAssignment_list = 25, RuleAssignment = 26, 
    RuleDefined_type = 27, RuleDefined_value = 28, RuleExternal_type_reference = 29, 
    RuleExternal_value_reference = 30, RuleAbsolute_reference = 31, RuleItem_spec = 32, 
    RuleComponent_id = 33, RuleType_assignment = 34, RuleValue_assignment = 35, 
    RuleValue_set_type_assignment = 36, RuleValue_set = 37, RuleType = 38, 
    RuleBuiltin_type = 39, RuleReferenced_type = 40, RuleNamed_type = 41, 
    RuleAny_type = 42, RuleValue = 43, RuleBuiltin_value = 44, RuleNamed_value = 45, 
    RuleBoolean_value = 46, RuleInteger_type = 47, RuleNamed_number_list = 48, 
    RuleNamed_number = 49, RuleSigned_number = 50, RuleInteger_value = 51, 
    RuleEnumerated_type = 52, RuleEnumerations = 53, RuleRoot_enumeration = 54, 
    RuleAdditional_enumeration = 55, RuleEnumeration = 56, RuleEnumeration_item = 57, 
    RuleEnumerated_value = 58, RuleReal_value = 59, RuleBit_string_type = 60, 
    RuleNamed_bit_list = 61, RuleNamed_bit = 62, RuleBit_string_value = 63, 
    RuleIdentifier_list = 64, RuleOctet_string_value = 65, RuleSequence_or_set_type = 66, 
    RuleSequence_or_set_of_type = 67, RuleExtension_and_exception = 68, 
    RuleOptional_extension_marker = 69, RuleComponent_type_lists = 70, RuleExtension_end_marker = 71, 
    RuleExtension_additions = 72, RuleExtension_addition_list = 73, RuleExtension_addition = 74, 
    RuleExtension_addition_group = 75, RuleVersion_number = 76, RuleComponent_type_list = 77, 
    RuleComponent_type = 78, RuleSequence_value = 79, RuleComponent_value_list = 80, 
    RuleSequence_of_value = 81, RuleValue_list = 82, RuleNamed_value_list = 83, 
    RuleSet_value = 84, RuleSet_of_value = 85, RuleChoice_type = 86, RuleAlternative_type_lists = 87, 
    RuleRoot_alternative_type_list = 88, RuleExtension_addition_alternatives = 89, 
    RuleExtension_addition_alternatives_list = 90, RuleExtension_addition_alternative = 91, 
    RuleExtension_addition_alternatives_group = 92, RuleAlternative_type_list = 93, 
    RuleChoice_value = 94, RuleSelection_type = 95, RulePrefixed_type = 96, 
    RuleTagged_type = 97, RuleTag = 98, RuleClass_number = 99, RuleCategory = 100, 
    RuleEncoding_prefixed_type = 101, RuleEncoding_prefix = 102, RuleObject_identifier_value = 103, 
    RuleObj_id_components = 104, RuleName_form = 105, RuleNumber_form = 106, 
    RuleName_and_number_form = 107, RuleRelative_oid_value = 108, RuleRelative_oid_components_list = 109, 
    RuleRelative_oid_components = 110, RuleIri_value = 111, RuleArc_identifier = 112, 
    RuleRelative_iri_value = 113, RuleEmbedded_pdv_value = 114, RuleTime_value = 115, 
    RuleCharacter_string_type = 116, RuleCharacter_string_value = 117, RuleRestricted_character_string_type = 118, 
    RuleRestricted_character_string_value = 119, RuleCharacter_string_list = 120, 
    RuleChars_defn = 121, RuleQuadruple = 122, RuleGroup = 123, RulePlane = 124, 
    RuleRow = 125, RuleCell = 126, RuleTuple = 127, RuleTable_column = 128, 
    RuleTable_row = 129, RuleUnrestricted_character_string_type = 130, RuleUnrestricted_character_string_value = 131, 
    RuleUseful_type = 132, RuleConstrained_type = 133, RuleType_with_constraint = 134, 
    RuleConstraint = 135, RuleSize_constraint = 136, RuleConstraint_spec = 137, 
    RuleSubtype_constraint = 138, RuleElement_set_specs = 139, RuleRoot_element_set_spec = 140, 
    RuleAdditional_element_set_spec = 141, RuleElement_set_spec = 142, RuleUnions = 143, 
    RuleIntersections = 144, RuleIntersection_elements = 145, RuleElems = 146, 
    RuleExclusions = 147, RuleUnion_mark = 148, RuleIntersection_mark = 149, 
    RuleElements = 150, RuleSubtype_elements = 151, RuleSingle_value = 152, 
    RuleContained_subtype = 153, RuleIncludes = 154, RuleValue_range = 155, 
    RuleLower_endpoint = 156, RuleUpper_endpoint = 157, RuleLower_end_value = 158, 
    RuleUpper_end_value = 159, RuleType_constraint = 160, RulePermitted_alphabet = 161, 
    RuleInner_type_constraints = 162, RuleSingle_type_constraint = 163, 
    RuleMultiple_type_constraints = 164, RuleFull_specification = 165, RulePartial_specification = 166, 
    RuleType_constraints = 167, RuleNamed_constraint = 168, RuleComponent_constraint = 169, 
    RuleValue_constraint = 170, RulePresence_constraint = 171, RulePattern_constraint = 172, 
    RuleProperty_settings = 173, RuleProperty_settings_list = 174, RuleProperty_and_setting_pair = 175, 
    RuleProperty_name = 176, RuleSetting_name = 177, RuleDuration_range = 178, 
    RuleTime_point_range = 179, RuleRecurrence_range = 180, RuleException_spec = 181, 
    RuleException_identification = 182, RuleEncoding_control_sections = 183, 
    RuleEncoding_control_section = 184
  };

  asn1Parser(antlr4::TokenStream *input);
  ~asn1Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class Module_definitionContext;
  class Module_identifierContext;
  class Definitive_identificationContext;
  class Definitive_oidContext;
  class Definitive_oid_and_iriContext;
  class Definitive_object_id_component_listContext;
  class Definitive_object_id_componentContext;
  class Definitive_number_formContext;
  class Definitive_name_and_number_formContext;
  class Encoding_reference_defaultContext;
  class Tag_defaultContext;
  class Extension_defaultContext;
  class Module_bodyContext;
  class ExportsContext;
  class Symbols_exportedContext;
  class ImportsContext;
  class Symbols_importedContext;
  class Symbols_from_module_listContext;
  class Symbols_from_moduleContext;
  class Global_module_referenceContext;
  class Assigned_identifierContext;
  class Symbol_listContext;
  class SymbolContext;
  class ReferenceContext;
  class Assignment_listContext;
  class AssignmentContext;
  class Defined_typeContext;
  class Defined_valueContext;
  class External_type_referenceContext;
  class External_value_referenceContext;
  class Absolute_referenceContext;
  class Item_specContext;
  class Component_idContext;
  class Type_assignmentContext;
  class Value_assignmentContext;
  class Value_set_type_assignmentContext;
  class Value_setContext;
  class TypeContext;
  class Builtin_typeContext;
  class Referenced_typeContext;
  class Named_typeContext;
  class Any_typeContext;
  class ValueContext;
  class Builtin_valueContext;
  class Named_valueContext;
  class Boolean_valueContext;
  class Integer_typeContext;
  class Named_number_listContext;
  class Named_numberContext;
  class Signed_numberContext;
  class Integer_valueContext;
  class Enumerated_typeContext;
  class EnumerationsContext;
  class Root_enumerationContext;
  class Additional_enumerationContext;
  class EnumerationContext;
  class Enumeration_itemContext;
  class Enumerated_valueContext;
  class Real_valueContext;
  class Bit_string_typeContext;
  class Named_bit_listContext;
  class Named_bitContext;
  class Bit_string_valueContext;
  class Identifier_listContext;
  class Octet_string_valueContext;
  class Sequence_or_set_typeContext;
  class Sequence_or_set_of_typeContext;
  class Extension_and_exceptionContext;
  class Optional_extension_markerContext;
  class Component_type_listsContext;
  class Extension_end_markerContext;
  class Extension_additionsContext;
  class Extension_addition_listContext;
  class Extension_additionContext;
  class Extension_addition_groupContext;
  class Version_numberContext;
  class Component_type_listContext;
  class Component_typeContext;
  class Sequence_valueContext;
  class Component_value_listContext;
  class Sequence_of_valueContext;
  class Value_listContext;
  class Named_value_listContext;
  class Set_valueContext;
  class Set_of_valueContext;
  class Choice_typeContext;
  class Alternative_type_listsContext;
  class Root_alternative_type_listContext;
  class Extension_addition_alternativesContext;
  class Extension_addition_alternatives_listContext;
  class Extension_addition_alternativeContext;
  class Extension_addition_alternatives_groupContext;
  class Alternative_type_listContext;
  class Choice_valueContext;
  class Selection_typeContext;
  class Prefixed_typeContext;
  class Tagged_typeContext;
  class TagContext;
  class Class_numberContext;
  class CategoryContext;
  class Encoding_prefixed_typeContext;
  class Encoding_prefixContext;
  class Object_identifier_valueContext;
  class Obj_id_componentsContext;
  class Name_formContext;
  class Number_formContext;
  class Name_and_number_formContext;
  class Relative_oid_valueContext;
  class Relative_oid_components_listContext;
  class Relative_oid_componentsContext;
  class Iri_valueContext;
  class Arc_identifierContext;
  class Relative_iri_valueContext;
  class Embedded_pdv_valueContext;
  class Time_valueContext;
  class Character_string_typeContext;
  class Character_string_valueContext;
  class Restricted_character_string_typeContext;
  class Restricted_character_string_valueContext;
  class Character_string_listContext;
  class Chars_defnContext;
  class QuadrupleContext;
  class GroupContext;
  class PlaneContext;
  class RowContext;
  class CellContext;
  class TupleContext;
  class Table_columnContext;
  class Table_rowContext;
  class Unrestricted_character_string_typeContext;
  class Unrestricted_character_string_valueContext;
  class Useful_typeContext;
  class Constrained_typeContext;
  class Type_with_constraintContext;
  class ConstraintContext;
  class Size_constraintContext;
  class Constraint_specContext;
  class Subtype_constraintContext;
  class Element_set_specsContext;
  class Root_element_set_specContext;
  class Additional_element_set_specContext;
  class Element_set_specContext;
  class UnionsContext;
  class IntersectionsContext;
  class Intersection_elementsContext;
  class ElemsContext;
  class ExclusionsContext;
  class Union_markContext;
  class Intersection_markContext;
  class ElementsContext;
  class Subtype_elementsContext;
  class Single_valueContext;
  class Contained_subtypeContext;
  class IncludesContext;
  class Value_rangeContext;
  class Lower_endpointContext;
  class Upper_endpointContext;
  class Lower_end_valueContext;
  class Upper_end_valueContext;
  class Type_constraintContext;
  class Permitted_alphabetContext;
  class Inner_type_constraintsContext;
  class Single_type_constraintContext;
  class Multiple_type_constraintsContext;
  class Full_specificationContext;
  class Partial_specificationContext;
  class Type_constraintsContext;
  class Named_constraintContext;
  class Component_constraintContext;
  class Value_constraintContext;
  class Presence_constraintContext;
  class Pattern_constraintContext;
  class Property_settingsContext;
  class Property_settings_listContext;
  class Property_and_setting_pairContext;
  class Property_nameContext;
  class Setting_nameContext;
  class Duration_rangeContext;
  class Time_point_rangeContext;
  class Recurrence_rangeContext;
  class Exception_specContext;
  class Exception_identificationContext;
  class Encoding_control_sectionsContext;
  class Encoding_control_sectionContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_definitionContext *module_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  Module_definitionContext : public antlr4::ParserRuleContext {
  public:
    Module_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_identifierContext *module_identifier();
    antlr4::tree::TerminalNode *DEFINITIONS_RW();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    antlr4::tree::TerminalNode *BEGIN_RW();
    Module_bodyContext *module_body();
    antlr4::tree::TerminalNode *END_RW();
    Encoding_reference_defaultContext *encoding_reference_default();
    Tag_defaultContext *tag_default();
    Extension_defaultContext *extension_default();
    Encoding_control_sectionsContext *encoding_control_sections();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_definitionContext* module_definition();

  class  Module_identifierContext : public antlr4::ParserRuleContext {
  public:
    Module_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    Definitive_identificationContext *definitive_identification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_identifierContext* module_identifier();

  class  Definitive_identificationContext : public antlr4::ParserRuleContext {
  public:
    Definitive_identificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Definitive_oidContext *definitive_oid();
    Definitive_oid_and_iriContext *definitive_oid_and_iri();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_identificationContext* definitive_identification();

  class  Definitive_oidContext : public antlr4::ParserRuleContext {
  public:
    Definitive_oidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Definitive_object_id_component_listContext *definitive_object_id_component_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_oidContext* definitive_oid();

  class  Definitive_oid_and_iriContext : public antlr4::ParserRuleContext {
  public:
    Definitive_oid_and_iriContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Definitive_oidContext *definitive_oid();
    Iri_valueContext *iri_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_oid_and_iriContext* definitive_oid_and_iri();

  class  Definitive_object_id_component_listContext : public antlr4::ParserRuleContext {
  public:
    Definitive_object_id_component_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Definitive_object_id_componentContext *> definitive_object_id_component();
    Definitive_object_id_componentContext* definitive_object_id_component(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_object_id_component_listContext* definitive_object_id_component_list();

  class  Definitive_object_id_componentContext : public antlr4::ParserRuleContext {
  public:
    Definitive_object_id_componentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Name_formContext *name_form();
    Definitive_number_formContext *definitive_number_form();
    Definitive_name_and_number_formContext *definitive_name_and_number_form();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_object_id_componentContext* definitive_object_id_component();

  class  Definitive_number_formContext : public antlr4::ParserRuleContext {
  public:
    Definitive_number_formContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_number_formContext* definitive_number_form();

  class  Definitive_name_and_number_formContext : public antlr4::ParserRuleContext {
  public:
    Definitive_name_and_number_formContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    Definitive_number_formContext *definitive_number_form();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definitive_name_and_number_formContext* definitive_name_and_number_form();

  class  Encoding_reference_defaultContext : public antlr4::ParserRuleContext {
  public:
    Encoding_reference_defaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSTRUCTIONS_RW();
    antlr4::tree::TerminalNode *ENCODING_REFERENCE();
    antlr4::tree::TerminalNode *COLON_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Encoding_reference_defaultContext* encoding_reference_default();

  class  Tag_defaultContext : public antlr4::ParserRuleContext {
  public:
    Tag_defaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Tag_defaultContext() = default;
    void copyFrom(Tag_defaultContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Automatic_tagsContext : public Tag_defaultContext {
  public:
    Automatic_tagsContext(Tag_defaultContext *ctx);

    antlr4::tree::TerminalNode *AUTOMATIC_RW();
    antlr4::tree::TerminalNode *TAGS_RW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Implicit_tagsContext : public Tag_defaultContext {
  public:
    Implicit_tagsContext(Tag_defaultContext *ctx);

    antlr4::tree::TerminalNode *IMPLICIT_RW();
    antlr4::tree::TerminalNode *TAGS_RW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Explicit_tagsContext : public Tag_defaultContext {
  public:
    Explicit_tagsContext(Tag_defaultContext *ctx);

    antlr4::tree::TerminalNode *EXPLICIT_RW();
    antlr4::tree::TerminalNode *TAGS_RW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Tag_defaultContext* tag_default();

  class  Extension_defaultContext : public antlr4::ParserRuleContext {
  public:
    Extension_defaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTENSIBILITY_RW();
    antlr4::tree::TerminalNode *IMPLIED_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_defaultContext* extension_default();

  class  Module_bodyContext : public antlr4::ParserRuleContext {
  public:
    Module_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExportsContext *exports();
    ImportsContext *imports();
    Assignment_listContext *assignment_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_bodyContext* module_body();

  class  ExportsContext : public antlr4::ParserRuleContext {
  public:
    ExportsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPORTS_RW();
    Symbols_exportedContext *symbols_exported();
    antlr4::tree::TerminalNode *SEMICOLON_TK();
    antlr4::tree::TerminalNode *ALL_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExportsContext* exports();

  class  Symbols_exportedContext : public antlr4::ParserRuleContext {
  public:
    Symbols_exportedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Symbol_listContext *symbol_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Symbols_exportedContext* symbols_exported();

  class  ImportsContext : public antlr4::ParserRuleContext {
  public:
    ImportsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORTS_RW();
    Symbols_importedContext *symbols_imported();
    antlr4::tree::TerminalNode *SEMICOLON_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportsContext* imports();

  class  Symbols_importedContext : public antlr4::ParserRuleContext {
  public:
    Symbols_importedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Symbols_from_module_listContext *symbols_from_module_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Symbols_importedContext* symbols_imported();

  class  Symbols_from_module_listContext : public antlr4::ParserRuleContext {
  public:
    Symbols_from_module_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Symbols_from_moduleContext *> symbols_from_module();
    Symbols_from_moduleContext* symbols_from_module(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Symbols_from_module_listContext* symbols_from_module_list();

  class  Symbols_from_moduleContext : public antlr4::ParserRuleContext {
  public:
    Symbols_from_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Symbol_listContext *symbol_list();
    antlr4::tree::TerminalNode *FROM_RW();
    Global_module_referenceContext *global_module_reference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Symbols_from_moduleContext* symbols_from_module();

  class  Global_module_referenceContext : public antlr4::ParserRuleContext {
  public:
    Global_module_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    Assigned_identifierContext *assigned_identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_module_referenceContext* global_module_reference();

  class  Assigned_identifierContext : public antlr4::ParserRuleContext {
  public:
    Assigned_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_identifier_valueContext *object_identifier_value();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assigned_identifierContext* assigned_identifier();

  class  Symbol_listContext : public antlr4::ParserRuleContext {
  public:
    Symbol_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SymbolContext *> symbol();
    SymbolContext* symbol(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Symbol_listContext* symbol_list();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReferenceContext *reference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  ReferenceContext : public antlr4::ParserRuleContext {
  public:
    ReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReferenceContext* reference();

  class  Assignment_listContext : public antlr4::ParserRuleContext {
  public:
    Assignment_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_listContext* assignment_list();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_assignmentContext *type_assignment();
    Value_assignmentContext *value_assignment();
    Value_set_type_assignmentContext *value_set_type_assignment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Defined_typeContext : public antlr4::ParserRuleContext {
  public:
    Defined_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    External_type_referenceContext *external_type_reference();
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Defined_typeContext* defined_type();

  class  Defined_valueContext : public antlr4::ParserRuleContext {
  public:
    Defined_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    External_value_referenceContext *external_value_reference();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Defined_valueContext* defined_value();

  class  External_type_referenceContext : public antlr4::ParserRuleContext {
  public:
    External_type_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TYPE_REFERENCE_OR_MODULE_REFERENCE();
    antlr4::tree::TerminalNode* TYPE_REFERENCE_OR_MODULE_REFERENCE(size_t i);
    antlr4::tree::TerminalNode *FULL_STOP_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  External_type_referenceContext* external_type_reference();

  class  External_value_referenceContext : public antlr4::ParserRuleContext {
  public:
    External_value_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    antlr4::tree::TerminalNode *FULL_STOP_TK();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  External_value_referenceContext* external_value_reference();

  class  Absolute_referenceContext : public antlr4::ParserRuleContext {
  public:
    Absolute_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMERCIAL_AT_TK();
    Module_identifierContext *module_identifier();
    antlr4::tree::TerminalNode *FULL_STOP_TK();
    Item_specContext *item_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Absolute_referenceContext* absolute_reference();

  class  Item_specContext : public antlr4::ParserRuleContext {
  public:
    Item_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    Item_specContext *item_spec();
    antlr4::tree::TerminalNode *FULL_STOP_TK();
    Component_idContext *component_id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Item_specContext* item_spec();
  Item_specContext* item_spec(int precedence);
  class  Component_idContext : public antlr4::ParserRuleContext {
  public:
    Component_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *ASTERISK_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_idContext* component_id();

  class  Type_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Type_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_assignmentContext* type_assignment();

  class  Value_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Value_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeContext *type();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_assignmentContext* value_assignment();

  class  Value_set_type_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Value_set_type_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();
    TypeContext *type();
    antlr4::tree::TerminalNode *ASSIGNMENT();
    Value_setContext *value_set();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_set_type_assignmentContext* value_set_type_assignment();

  class  Value_setContext : public antlr4::ParserRuleContext {
  public:
    Value_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Element_set_specsContext *element_set_specs();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_setContext* value_set();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Builtin_typeContext *builtin_type();
    Referenced_typeContext *referenced_type();
    Constrained_typeContext *constrained_type();
    Any_typeContext *any_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  Builtin_typeContext : public antlr4::ParserRuleContext {
  public:
    Builtin_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bit_string_typeContext *bit_string_type();
    antlr4::tree::TerminalNode *BOOLEAN_RW();
    Character_string_typeContext *character_string_type();
    Choice_typeContext *choice_type();
    antlr4::tree::TerminalNode *DATE_RW();
    antlr4::tree::TerminalNode *DATE_TIME_RW();
    antlr4::tree::TerminalNode *DURATION_RW();
    antlr4::tree::TerminalNode *EMBEDDED_RW();
    antlr4::tree::TerminalNode *PDV_RW();
    Enumerated_typeContext *enumerated_type();
    antlr4::tree::TerminalNode *EXTERNAL_RW();
    Integer_typeContext *integer_type();
    antlr4::tree::TerminalNode *OID_IRI_RW();
    antlr4::tree::TerminalNode *NULL_RW();
    antlr4::tree::TerminalNode *OBJECT_RW();
    antlr4::tree::TerminalNode *IDENTIFIER_RW();
    antlr4::tree::TerminalNode *OCTET_RW();
    antlr4::tree::TerminalNode *STRING_RW();
    antlr4::tree::TerminalNode *REAL_RW();
    antlr4::tree::TerminalNode *RELATIVE_OID_IRI_RW();
    antlr4::tree::TerminalNode *RELATIVE_OID_RW();
    Sequence_or_set_typeContext *sequence_or_set_type();
    Sequence_or_set_of_typeContext *sequence_or_set_of_type();
    Prefixed_typeContext *prefixed_type();
    antlr4::tree::TerminalNode *TIME_RW();
    antlr4::tree::TerminalNode *TIME_OF_DAY_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Builtin_typeContext* builtin_type();

  class  Referenced_typeContext : public antlr4::ParserRuleContext {
  public:
    Referenced_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defined_typeContext *defined_type();
    Useful_typeContext *useful_type();
    Selection_typeContext *selection_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Referenced_typeContext* referenced_type();

  class  Named_typeContext : public antlr4::ParserRuleContext {
  public:
    Named_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_typeContext* named_type();

  class  Any_typeContext : public antlr4::ParserRuleContext {
  public:
    Any_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY_RW();
    antlr4::tree::TerminalNode *DEFINED_RW();
    antlr4::tree::TerminalNode *BY_RW();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Any_typeContext* any_type();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Builtin_valueContext *builtin_value();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();

  class  Builtin_valueContext : public antlr4::ParserRuleContext {
  public:
    Builtin_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bit_string_valueContext *bit_string_value();
    Boolean_valueContext *boolean_value();
    Character_string_valueContext *character_string_value();
    Choice_valueContext *choice_value();
    Embedded_pdv_valueContext *embedded_pdv_value();
    Enumerated_valueContext *enumerated_value();
    Integer_valueContext *integer_value();
    Iri_valueContext *iri_value();
    antlr4::tree::TerminalNode *NULL_RW();
    Object_identifier_valueContext *object_identifier_value();
    Octet_string_valueContext *octet_string_value();
    Real_valueContext *real_value();
    Relative_iri_valueContext *relative_iri_value();
    Relative_oid_valueContext *relative_oid_value();
    Sequence_valueContext *sequence_value();
    Sequence_of_valueContext *sequence_of_value();
    Set_valueContext *set_value();
    Set_of_valueContext *set_of_value();
    Time_valueContext *time_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Builtin_valueContext* builtin_value();

  class  Named_valueContext : public antlr4::ParserRuleContext {
  public:
    Named_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_valueContext* named_value();

  class  Boolean_valueContext : public antlr4::ParserRuleContext {
  public:
    Boolean_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE_RW();
    antlr4::tree::TerminalNode *FALSE_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_valueContext* boolean_value();

  class  Integer_typeContext : public antlr4::ParserRuleContext {
  public:
    Integer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_RW();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Named_number_listContext *named_number_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_typeContext* integer_type();

  class  Named_number_listContext : public antlr4::ParserRuleContext {
  public:
    Named_number_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_numberContext *> named_number();
    Named_numberContext* named_number(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_number_listContext* named_number_list();

  class  Named_numberContext : public antlr4::ParserRuleContext {
  public:
    Named_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    Signed_numberContext *signed_number();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();
    Defined_valueContext *defined_value();
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_numberContext* named_number();

  class  Signed_numberContext : public antlr4::ParserRuleContext {
  public:
    Signed_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *HYPHEN_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Signed_numberContext* signed_number();

  class  Integer_valueContext : public antlr4::ParserRuleContext {
  public:
    Integer_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signed_numberContext *signed_number();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_valueContext* integer_value();

  class  Enumerated_typeContext : public antlr4::ParserRuleContext {
  public:
    Enumerated_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUMERATED_RW();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    EnumerationsContext *enumerations();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enumerated_typeContext* enumerated_type();

  class  EnumerationsContext : public antlr4::ParserRuleContext {
  public:
    EnumerationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Root_enumerationContext *root_enumeration();
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);
    antlr4::tree::TerminalNode *ELLIPSIS();
    Exception_specContext *exception_spec();
    Additional_enumerationContext *additional_enumeration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumerationsContext* enumerations();

  class  Root_enumerationContext : public antlr4::ParserRuleContext {
  public:
    Root_enumerationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnumerationContext *enumeration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Root_enumerationContext* root_enumeration();

  class  Additional_enumerationContext : public antlr4::ParserRuleContext {
  public:
    Additional_enumerationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnumerationContext *enumeration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Additional_enumerationContext* additional_enumeration();

  class  EnumerationContext : public antlr4::ParserRuleContext {
  public:
    EnumerationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Enumeration_itemContext *> enumeration_item();
    Enumeration_itemContext* enumeration_item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumerationContext* enumeration();

  class  Enumeration_itemContext : public antlr4::ParserRuleContext {
  public:
    Enumeration_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Named_numberContext *named_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enumeration_itemContext* enumeration_item();

  class  Enumerated_valueContext : public antlr4::ParserRuleContext {
  public:
    Enumerated_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enumerated_valueContext* enumerated_value();

  class  Real_valueContext : public antlr4::ParserRuleContext {
  public:
    Real_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL_NUMBER();
    antlr4::tree::TerminalNode *HYPHEN_TK();
    Sequence_valueContext *sequence_value();
    antlr4::tree::TerminalNode *PLUS_INFINITY_RW();
    antlr4::tree::TerminalNode *MINUS_INFINITY_RW();
    antlr4::tree::TerminalNode *NOT_A_NUMBER_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Real_valueContext* real_value();

  class  Bit_string_typeContext : public antlr4::ParserRuleContext {
  public:
    Bit_string_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_RW();
    antlr4::tree::TerminalNode *STRING_RW();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Named_bit_listContext *named_bit_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bit_string_typeContext* bit_string_type();

  class  Named_bit_listContext : public antlr4::ParserRuleContext {
  public:
    Named_bit_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_bitContext *> named_bit();
    Named_bitContext* named_bit(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_bit_listContext* named_bit_list();

  class  Named_bitContext : public antlr4::ParserRuleContext {
  public:
    Named_bitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_bitContext* named_bit();

  class  Bit_string_valueContext : public antlr4::ParserRuleContext {
  public:
    Bit_string_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BSTRING();
    antlr4::tree::TerminalNode *HSTRING();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Identifier_listContext *identifier_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *CONTAINING_RW();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bit_string_valueContext* bit_string_value();

  class  Identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_listContext* identifier_list();

  class  Octet_string_valueContext : public antlr4::ParserRuleContext {
  public:
    Octet_string_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BSTRING();
    antlr4::tree::TerminalNode *HSTRING();
    antlr4::tree::TerminalNode *CONTAINING_RW();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Octet_string_valueContext* octet_string_value();

  class  Sequence_or_set_typeContext : public antlr4::ParserRuleContext {
  public:
    Sequence_or_set_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEQUENCE_RW();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    Component_type_listsContext *component_type_lists();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_or_set_typeContext* sequence_or_set_type();

  class  Sequence_or_set_of_typeContext : public antlr4::ParserRuleContext {
  public:
    Sequence_or_set_of_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEQUENCE_RW();
    antlr4::tree::TerminalNode *OF_RW();
    TypeContext *type();
    Named_typeContext *named_type();
    antlr4::tree::TerminalNode *SET_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_or_set_of_typeContext* sequence_or_set_of_type();

  class  Extension_and_exceptionContext : public antlr4::ParserRuleContext {
  public:
    Extension_and_exceptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELLIPSIS();
    Exception_specContext *exception_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_and_exceptionContext* extension_and_exception();

  class  Optional_extension_markerContext : public antlr4::ParserRuleContext {
  public:
    Optional_extension_markerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA_TK();
    antlr4::tree::TerminalNode *ELLIPSIS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_extension_markerContext* optional_extension_marker();

  class  Component_type_listsContext : public antlr4::ParserRuleContext {
  public:
    Component_type_listsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Component_type_listContext *> component_type_list();
    Component_type_listContext* component_type_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);
    Extension_and_exceptionContext *extension_and_exception();
    Optional_extension_markerContext *optional_extension_marker();
    Extension_additionsContext *extension_additions();
    Extension_end_markerContext *extension_end_marker();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_type_listsContext* component_type_lists();

  class  Extension_end_markerContext : public antlr4::ParserRuleContext {
  public:
    Extension_end_markerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA_TK();
    antlr4::tree::TerminalNode *ELLIPSIS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_end_markerContext* extension_end_marker();

  class  Extension_additionsContext : public antlr4::ParserRuleContext {
  public:
    Extension_additionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA_TK();
    Extension_addition_listContext *extension_addition_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_additionsContext* extension_additions();

  class  Extension_addition_listContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Extension_additionContext *> extension_addition();
    Extension_additionContext* extension_addition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_listContext* extension_addition_list();

  class  Extension_additionContext : public antlr4::ParserRuleContext {
  public:
    Extension_additionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Component_typeContext *component_type();
    Extension_addition_groupContext *extension_addition_group();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_additionContext* extension_addition();

  class  Extension_addition_groupContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_groupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_VERSION_BRACKETS();
    Component_type_listContext *component_type_list();
    antlr4::tree::TerminalNode *RIGHT_VERSION_BRACKETS();
    Version_numberContext *version_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_groupContext* extension_addition_group();

  class  Version_numberContext : public antlr4::ParserRuleContext {
  public:
    Version_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *COLON_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Version_numberContext* version_number();

  class  Component_type_listContext : public antlr4::ParserRuleContext {
  public:
    Component_type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Component_typeContext *> component_type();
    Component_typeContext* component_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_type_listContext* component_type_list();

  class  Component_typeContext : public antlr4::ParserRuleContext {
  public:
    Component_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Named_typeContext *named_type();
    antlr4::tree::TerminalNode *OPTIONAL_RW();
    antlr4::tree::TerminalNode *DEFAULT_RW();
    ValueContext *value();
    antlr4::tree::TerminalNode *COMPONENTS_RW();
    antlr4::tree::TerminalNode *OF_RW();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_typeContext* component_type();

  class  Sequence_valueContext : public antlr4::ParserRuleContext {
  public:
    Sequence_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    Component_value_listContext *component_value_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_valueContext* sequence_value();

  class  Component_value_listContext : public antlr4::ParserRuleContext {
  public:
    Component_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_valueContext *> named_value();
    Named_valueContext* named_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_value_listContext* component_value_list();

  class  Sequence_of_valueContext : public antlr4::ParserRuleContext {
  public:
    Sequence_of_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Value_listContext *value_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    Named_value_listContext *named_value_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_of_valueContext* sequence_of_value();

  class  Value_listContext : public antlr4::ParserRuleContext {
  public:
    Value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ValueContext *> value();
    ValueContext* value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_listContext* value_list();

  class  Named_value_listContext : public antlr4::ParserRuleContext {
  public:
    Named_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_valueContext *> named_value();
    Named_valueContext* named_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_value_listContext* named_value_list();

  class  Set_valueContext : public antlr4::ParserRuleContext {
  public:
    Set_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    Component_value_listContext *component_value_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_valueContext* set_value();

  class  Set_of_valueContext : public antlr4::ParserRuleContext {
  public:
    Set_of_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Value_listContext *value_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    Named_value_listContext *named_value_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_of_valueContext* set_of_value();

  class  Choice_typeContext : public antlr4::ParserRuleContext {
  public:
    Choice_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHOICE_RW();
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Alternative_type_listsContext *alternative_type_lists();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Choice_typeContext* choice_type();

  class  Alternative_type_listsContext : public antlr4::ParserRuleContext {
  public:
    Alternative_type_listsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Root_alternative_type_listContext *root_alternative_type_list();
    antlr4::tree::TerminalNode *COMMA_TK();
    Extension_and_exceptionContext *extension_and_exception();
    Optional_extension_markerContext *optional_extension_marker();
    Extension_addition_alternativesContext *extension_addition_alternatives();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alternative_type_listsContext* alternative_type_lists();

  class  Root_alternative_type_listContext : public antlr4::ParserRuleContext {
  public:
    Root_alternative_type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Alternative_type_listContext *alternative_type_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Root_alternative_type_listContext* root_alternative_type_list();

  class  Extension_addition_alternativesContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_alternativesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA_TK();
    Extension_addition_alternatives_listContext *extension_addition_alternatives_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_alternativesContext* extension_addition_alternatives();

  class  Extension_addition_alternatives_listContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_alternatives_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Extension_addition_alternativeContext *> extension_addition_alternative();
    Extension_addition_alternativeContext* extension_addition_alternative(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_alternatives_listContext* extension_addition_alternatives_list();

  class  Extension_addition_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Extension_addition_alternatives_groupContext *extension_addition_alternatives_group();
    Named_typeContext *named_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_alternativeContext* extension_addition_alternative();

  class  Extension_addition_alternatives_groupContext : public antlr4::ParserRuleContext {
  public:
    Extension_addition_alternatives_groupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_VERSION_BRACKETS();
    Version_numberContext *version_number();
    Alternative_type_listContext *alternative_type_list();
    antlr4::tree::TerminalNode *RIGHT_VERSION_BRACKETS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extension_addition_alternatives_groupContext* extension_addition_alternatives_group();

  class  Alternative_type_listContext : public antlr4::ParserRuleContext {
  public:
    Alternative_type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Named_typeContext *> named_type();
    Named_typeContext* named_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alternative_type_listContext* alternative_type_list();

  class  Choice_valueContext : public antlr4::ParserRuleContext {
  public:
    Choice_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON_TK();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Choice_valueContext* choice_value();

  class  Selection_typeContext : public antlr4::ParserRuleContext {
  public:
    Selection_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LESS_THAN_SIGN_TK();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Selection_typeContext* selection_type();

  class  Prefixed_typeContext : public antlr4::ParserRuleContext {
  public:
    Prefixed_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tagged_typeContext *tagged_type();
    Encoding_prefixed_typeContext *encoding_prefixed_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Prefixed_typeContext* prefixed_type();

  class  Tagged_typeContext : public antlr4::ParserRuleContext {
  public:
    Tagged_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagContext *tag();
    TypeContext *type();
    antlr4::tree::TerminalNode *IMPLICIT_RW();
    antlr4::tree::TerminalNode *EXPLICIT_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tagged_typeContext* tagged_type();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET_TK();
    Class_numberContext *class_number();
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET_TK();
    antlr4::tree::TerminalNode *ENCODING_REFERENCE();
    antlr4::tree::TerminalNode *COLON_TK();
    CategoryContext *category();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagContext* tag();

  class  Class_numberContext : public antlr4::ParserRuleContext {
  public:
    Class_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_numberContext* class_number();

  class  CategoryContext : public antlr4::ParserRuleContext {
  public:
    CategoryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNIVERSAL_RW();
    antlr4::tree::TerminalNode *APPLICATION_RW();
    antlr4::tree::TerminalNode *PRIVATE_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CategoryContext* category();

  class  Encoding_prefixed_typeContext : public antlr4::ParserRuleContext {
  public:
    Encoding_prefixed_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Encoding_prefixContext *encoding_prefix();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Encoding_prefixed_typeContext* encoding_prefixed_type();

  class  Encoding_prefixContext : public antlr4::ParserRuleContext {
  public:
    Encoding_prefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET_TK();
    std::vector<antlr4::tree::TerminalNode *> ENCODING_REFERENCE();
    antlr4::tree::TerminalNode* ENCODING_REFERENCE(size_t i);
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET_TK();
    antlr4::tree::TerminalNode *COLON_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Encoding_prefixContext* encoding_prefix();

  class  Object_identifier_valueContext : public antlr4::ParserRuleContext {
  public:
    Object_identifier_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    std::vector<Obj_id_componentsContext *> obj_id_components();
    Obj_id_componentsContext* obj_id_components(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Object_identifier_valueContext* object_identifier_value();

  class  Obj_id_componentsContext : public antlr4::ParserRuleContext {
  public:
    Obj_id_componentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Name_formContext *name_form();
    Number_formContext *number_form();
    Name_and_number_formContext *name_and_number_form();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Obj_id_componentsContext* obj_id_components();

  class  Name_formContext : public antlr4::ParserRuleContext {
  public:
    Name_formContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Name_formContext* name_form();

  class  Number_formContext : public antlr4::ParserRuleContext {
  public:
    Number_formContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_formContext* number_form();

  class  Name_and_number_formContext : public antlr4::ParserRuleContext {
  public:
    Name_and_number_formContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    Number_formContext *number_form();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Name_and_number_formContext* name_and_number_form();

  class  Relative_oid_valueContext : public antlr4::ParserRuleContext {
  public:
    Relative_oid_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Relative_oid_components_listContext *relative_oid_components_list();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relative_oid_valueContext* relative_oid_value();

  class  Relative_oid_components_listContext : public antlr4::ParserRuleContext {
  public:
    Relative_oid_components_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Relative_oid_componentsContext *> relative_oid_components();
    Relative_oid_componentsContext* relative_oid_components(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relative_oid_components_listContext* relative_oid_components_list();

  class  Relative_oid_componentsContext : public antlr4::ParserRuleContext {
  public:
    Relative_oid_componentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Number_formContext *number_form();
    Name_and_number_formContext *name_and_number_form();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relative_oid_componentsContext* relative_oid_components();

  class  Iri_valueContext : public antlr4::ParserRuleContext {
  public:
    Iri_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUOTATION_MARK_TK();
    antlr4::tree::TerminalNode* QUOTATION_MARK_TK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SOLIDUS_TK();
    antlr4::tree::TerminalNode* SOLIDUS_TK(size_t i);
    std::vector<Arc_identifierContext *> arc_identifier();
    Arc_identifierContext* arc_identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Iri_valueContext* iri_value();

  class  Arc_identifierContext : public antlr4::ParserRuleContext {
  public:
    Arc_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();
    antlr4::tree::TerminalNode *TYPE_REFERENCE_OR_MODULE_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arc_identifierContext* arc_identifier();

  class  Relative_iri_valueContext : public antlr4::ParserRuleContext {
  public:
    Relative_iri_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUOTATION_MARK_TK();
    antlr4::tree::TerminalNode* QUOTATION_MARK_TK(size_t i);
    std::vector<Arc_identifierContext *> arc_identifier();
    Arc_identifierContext* arc_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SOLIDUS_TK();
    antlr4::tree::TerminalNode* SOLIDUS_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relative_iri_valueContext* relative_iri_value();

  class  Embedded_pdv_valueContext : public antlr4::ParserRuleContext {
  public:
    Embedded_pdv_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_valueContext *sequence_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Embedded_pdv_valueContext* embedded_pdv_value();

  class  Time_valueContext : public antlr4::ParserRuleContext {
  public:
    Time_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TSTRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Time_valueContext* time_value();

  class  Character_string_typeContext : public antlr4::ParserRuleContext {
  public:
    Character_string_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Restricted_character_string_typeContext *restricted_character_string_type();
    Unrestricted_character_string_typeContext *unrestricted_character_string_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Character_string_typeContext* character_string_type();

  class  Character_string_valueContext : public antlr4::ParserRuleContext {
  public:
    Character_string_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Restricted_character_string_valueContext *restricted_character_string_value();
    Unrestricted_character_string_valueContext *unrestricted_character_string_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Character_string_valueContext* character_string_value();

  class  Restricted_character_string_typeContext : public antlr4::ParserRuleContext {
  public:
    Restricted_character_string_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Restricted_character_string_typeContext* restricted_character_string_type();

  class  Restricted_character_string_valueContext : public antlr4::ParserRuleContext {
  public:
    Restricted_character_string_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CSTRING();
    Character_string_listContext *character_string_list();
    QuadrupleContext *quadruple();
    TupleContext *tuple();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Restricted_character_string_valueContext* restricted_character_string_value();

  class  Character_string_listContext : public antlr4::ParserRuleContext {
  public:
    Character_string_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    std::vector<Chars_defnContext *> chars_defn();
    Chars_defnContext* chars_defn(size_t i);
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Character_string_listContext* character_string_list();

  class  Chars_defnContext : public antlr4::ParserRuleContext {
  public:
    Chars_defnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CSTRING();
    QuadrupleContext *quadruple();
    TupleContext *tuple();
    Defined_valueContext *defined_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chars_defnContext* chars_defn();

  class  QuadrupleContext : public antlr4::ParserRuleContext {
  public:
    QuadrupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    GroupContext *group();
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);
    PlaneContext *plane();
    RowContext *row();
    CellContext *cell();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuadrupleContext* quadruple();

  class  GroupContext : public antlr4::ParserRuleContext {
  public:
    GroupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupContext* group();

  class  PlaneContext : public antlr4::ParserRuleContext {
  public:
    PlaneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PlaneContext* plane();

  class  RowContext : public antlr4::ParserRuleContext {
  public:
    RowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RowContext* row();

  class  CellContext : public antlr4::ParserRuleContext {
  public:
    CellContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CellContext* cell();

  class  TupleContext : public antlr4::ParserRuleContext {
  public:
    TupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Table_columnContext *table_column();
    antlr4::tree::TerminalNode *COMMA_TK();
    Table_rowContext *table_row();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleContext* tuple();

  class  Table_columnContext : public antlr4::ParserRuleContext {
  public:
    Table_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_columnContext* table_column();

  class  Table_rowContext : public antlr4::ParserRuleContext {
  public:
    Table_rowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_rowContext* table_row();

  class  Unrestricted_character_string_typeContext : public antlr4::ParserRuleContext {
  public:
    Unrestricted_character_string_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER_RW();
    antlr4::tree::TerminalNode *STRING_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unrestricted_character_string_typeContext* unrestricted_character_string_type();

  class  Unrestricted_character_string_valueContext : public antlr4::ParserRuleContext {
  public:
    Unrestricted_character_string_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_valueContext *sequence_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unrestricted_character_string_valueContext* unrestricted_character_string_value();

  class  Useful_typeContext : public antlr4::ParserRuleContext {
  public:
    Useful_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Useful_typeContext* useful_type();

  class  Constrained_typeContext : public antlr4::ParserRuleContext {
  public:
    Constrained_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstraintContext *constraint();
    Builtin_typeContext *builtin_type();
    Referenced_typeContext *referenced_type();
    Type_with_constraintContext *type_with_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constrained_typeContext* constrained_type();

  class  Type_with_constraintContext : public antlr4::ParserRuleContext {
  public:
    Type_with_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET_RW();
    ConstraintContext *constraint();
    antlr4::tree::TerminalNode *OF_RW();
    TypeContext *type();
    Size_constraintContext *size_constraint();
    antlr4::tree::TerminalNode *SEQUENCE_RW();
    Named_typeContext *named_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_with_constraintContext* type_with_constraint();

  class  ConstraintContext : public antlr4::ParserRuleContext {
  public:
    ConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    Constraint_specContext *constraint_spec();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();
    Exception_specContext *exception_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstraintContext* constraint();

  class  Size_constraintContext : public antlr4::ParserRuleContext {
  public:
    Size_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIZE_RW();
    ConstraintContext *constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Size_constraintContext* size_constraint();

  class  Constraint_specContext : public antlr4::ParserRuleContext {
  public:
    Constraint_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subtype_constraintContext *subtype_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_specContext* constraint_spec();

  class  Subtype_constraintContext : public antlr4::ParserRuleContext {
  public:
    Subtype_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_set_specsContext *element_set_specs();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Subtype_constraintContext* subtype_constraint();

  class  Element_set_specsContext : public antlr4::ParserRuleContext {
  public:
    Element_set_specsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Root_element_set_specContext *root_element_set_spec();
    std::vector<antlr4::tree::TerminalNode *> COMMA_TK();
    antlr4::tree::TerminalNode* COMMA_TK(size_t i);
    antlr4::tree::TerminalNode *ELLIPSIS();
    Additional_element_set_specContext *additional_element_set_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_set_specsContext* element_set_specs();

  class  Root_element_set_specContext : public antlr4::ParserRuleContext {
  public:
    Root_element_set_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_set_specContext *element_set_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Root_element_set_specContext* root_element_set_spec();

  class  Additional_element_set_specContext : public antlr4::ParserRuleContext {
  public:
    Additional_element_set_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_set_specContext *element_set_spec();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Additional_element_set_specContext* additional_element_set_spec();

  class  Element_set_specContext : public antlr4::ParserRuleContext {
  public:
    Element_set_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnionsContext *unions();
    antlr4::tree::TerminalNode *ALL_RW();
    ExclusionsContext *exclusions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Element_set_specContext* element_set_spec();

  class  UnionsContext : public antlr4::ParserRuleContext {
  public:
    UnionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntersectionsContext *intersections();
    UnionsContext *unions();
    Union_markContext *union_mark();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnionsContext* unions();
  UnionsContext* unions(int precedence);
  class  IntersectionsContext : public antlr4::ParserRuleContext {
  public:
    IntersectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Intersection_elementsContext *> intersection_elements();
    Intersection_elementsContext* intersection_elements(size_t i);
    Intersection_markContext *intersection_mark();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntersectionsContext* intersections();

  class  Intersection_elementsContext : public antlr4::ParserRuleContext {
  public:
    Intersection_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementsContext *elements();
    ElemsContext *elems();
    ExclusionsContext *exclusions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Intersection_elementsContext* intersection_elements();

  class  ElemsContext : public antlr4::ParserRuleContext {
  public:
    ElemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementsContext *elements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElemsContext* elems();

  class  ExclusionsContext : public antlr4::ParserRuleContext {
  public:
    ExclusionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCEPT_RW();
    ElementsContext *elements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExclusionsContext* exclusions();

  class  Union_markContext : public antlr4::ParserRuleContext {
  public:
    Union_markContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERTICAL_LINE_TK();
    antlr4::tree::TerminalNode *UNION_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Union_markContext* union_mark();

  class  Intersection_markContext : public antlr4::ParserRuleContext {
  public:
    Intersection_markContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CIRCUMFLEX_ACCENT_TK();
    antlr4::tree::TerminalNode *INTERSECTION_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Intersection_markContext* intersection_mark();

  class  ElementsContext : public antlr4::ParserRuleContext {
  public:
    ElementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subtype_elementsContext *subtype_elements();
    antlr4::tree::TerminalNode *LEFT_PARENTHESIS_TK();
    Element_set_specContext *element_set_spec();
    antlr4::tree::TerminalNode *RIGHT_PARENTHESIS_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementsContext* elements();

  class  Subtype_elementsContext : public antlr4::ParserRuleContext {
  public:
    Subtype_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Single_valueContext *single_value();
    Contained_subtypeContext *contained_subtype();
    Value_rangeContext *value_range();
    Permitted_alphabetContext *permitted_alphabet();
    Size_constraintContext *size_constraint();
    Type_constraintContext *type_constraint();
    Inner_type_constraintsContext *inner_type_constraints();
    Pattern_constraintContext *pattern_constraint();
    Property_settingsContext *property_settings();
    Duration_rangeContext *duration_range();
    Time_point_rangeContext *time_point_range();
    Recurrence_rangeContext *recurrence_range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Subtype_elementsContext* subtype_elements();

  class  Single_valueContext : public antlr4::ParserRuleContext {
  public:
    Single_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Single_valueContext* single_value();

  class  Contained_subtypeContext : public antlr4::ParserRuleContext {
  public:
    Contained_subtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IncludesContext *includes();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Contained_subtypeContext* contained_subtype();

  class  IncludesContext : public antlr4::ParserRuleContext {
  public:
    IncludesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDES_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludesContext* includes();

  class  Value_rangeContext : public antlr4::ParserRuleContext {
  public:
    Value_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lower_endpointContext *lower_endpoint();
    antlr4::tree::TerminalNode *RANGE_SEPARATOR();
    Upper_endpointContext *upper_endpoint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_rangeContext* value_range();

  class  Lower_endpointContext : public antlr4::ParserRuleContext {
  public:
    Lower_endpointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lower_end_valueContext *lower_end_value();
    antlr4::tree::TerminalNode *LESS_THAN_SIGN_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Lower_endpointContext* lower_endpoint();

  class  Upper_endpointContext : public antlr4::ParserRuleContext {
  public:
    Upper_endpointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Upper_end_valueContext *upper_end_value();
    antlr4::tree::TerminalNode *LESS_THAN_SIGN_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Upper_endpointContext* upper_endpoint();

  class  Lower_end_valueContext : public antlr4::ParserRuleContext {
  public:
    Lower_end_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    antlr4::tree::TerminalNode *MIN_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Lower_end_valueContext* lower_end_value();

  class  Upper_end_valueContext : public antlr4::ParserRuleContext {
  public:
    Upper_end_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    antlr4::tree::TerminalNode *MAX_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Upper_end_valueContext* upper_end_value();

  class  Type_constraintContext : public antlr4::ParserRuleContext {
  public:
    Type_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_constraintContext* type_constraint();

  class  Permitted_alphabetContext : public antlr4::ParserRuleContext {
  public:
    Permitted_alphabetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM_RW();
    ConstraintContext *constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Permitted_alphabetContext* permitted_alphabet();

  class  Inner_type_constraintsContext : public antlr4::ParserRuleContext {
  public:
    Inner_type_constraintsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH_RW();
    antlr4::tree::TerminalNode *COMPONENT_RW();
    Single_type_constraintContext *single_type_constraint();
    antlr4::tree::TerminalNode *COMPONENTS_RW();
    Multiple_type_constraintsContext *multiple_type_constraints();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inner_type_constraintsContext* inner_type_constraints();

  class  Single_type_constraintContext : public antlr4::ParserRuleContext {
  public:
    Single_type_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstraintContext *constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Single_type_constraintContext* single_type_constraint();

  class  Multiple_type_constraintsContext : public antlr4::ParserRuleContext {
  public:
    Multiple_type_constraintsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Full_specificationContext *full_specification();
    Partial_specificationContext *partial_specification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiple_type_constraintsContext* multiple_type_constraints();

  class  Full_specificationContext : public antlr4::ParserRuleContext {
  public:
    Full_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    Type_constraintsContext *type_constraints();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Full_specificationContext* full_specification();

  class  Partial_specificationContext : public antlr4::ParserRuleContext {
  public:
    Partial_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY_BRACKET_TK();
    antlr4::tree::TerminalNode *ELLIPSIS();
    antlr4::tree::TerminalNode *COMMA_TK();
    Type_constraintsContext *type_constraints();
    antlr4::tree::TerminalNode *RIGHT_CURLY_BRACKET_TK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Partial_specificationContext* partial_specification();

  class  Type_constraintsContext : public antlr4::ParserRuleContext {
  public:
    Type_constraintsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Named_constraintContext *named_constraint();
    antlr4::tree::TerminalNode *COMMA_TK();
    Type_constraintsContext *type_constraints();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_constraintsContext* type_constraints();

  class  Named_constraintContext : public antlr4::ParserRuleContext {
  public:
    Named_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Component_constraintContext *component_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_constraintContext* named_constraint();

  class  Component_constraintContext : public antlr4::ParserRuleContext {
  public:
    Component_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_constraintContext *value_constraint();
    Presence_constraintContext *presence_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Component_constraintContext* component_constraint();

  class  Value_constraintContext : public antlr4::ParserRuleContext {
  public:
    Value_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstraintContext *constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_constraintContext* value_constraint();

  class  Presence_constraintContext : public antlr4::ParserRuleContext {
  public:
    Presence_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRESENT_RW();
    antlr4::tree::TerminalNode *ABSENT_RW();
    antlr4::tree::TerminalNode *OPTIONAL_RW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Presence_constraintContext* presence_constraint();

  class  Pattern_constraintContext : public antlr4::ParserRuleContext {
  public:
    Pattern_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATTERN_RW();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pattern_constraintContext* pattern_constraint();

  class  Property_settingsContext : public antlr4::ParserRuleContext {
  public:
    Property_settingsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SETTINGS_RW();
    antlr4::tree::TerminalNode *SIMPLE_STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_settingsContext* property_settings();

  class  Property_settings_listContext : public antlr4::ParserRuleContext {
  public:
    Property_settings_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_and_setting_pairContext *property_and_setting_pair();
    Property_settings_listContext *property_settings_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_settings_listContext* property_settings_list();
  Property_settings_listContext* property_settings_list(int precedence);
  class  Property_and_setting_pairContext : public antlr4::ParserRuleContext {
  public:
    Property_and_setting_pairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_nameContext *property_name();
    antlr4::tree::TerminalNode *EQUALS_SIGN_TK();
    Setting_nameContext *setting_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_and_setting_pairContext* property_and_setting_pair();

  class  Property_nameContext : public antlr4::ParserRuleContext {
  public:
    Property_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PS_NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_nameContext* property_name();

  class  Setting_nameContext : public antlr4::ParserRuleContext {
  public:
    Setting_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PS_NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Setting_nameContext* setting_name();

  class  Duration_rangeContext : public antlr4::ParserRuleContext {
  public:
    Duration_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_rangeContext *value_range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Duration_rangeContext* duration_range();

  class  Time_point_rangeContext : public antlr4::ParserRuleContext {
  public:
    Time_point_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_rangeContext *value_range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Time_point_rangeContext* time_point_range();

  class  Recurrence_rangeContext : public antlr4::ParserRuleContext {
  public:
    Recurrence_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_rangeContext *value_range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Recurrence_rangeContext* recurrence_range();

  class  Exception_specContext : public antlr4::ParserRuleContext {
  public:
    Exception_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXCLAMATION_MARK_TK();
    Exception_identificationContext *exception_identification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Exception_specContext* exception_spec();

  class  Exception_identificationContext : public antlr4::ParserRuleContext {
  public:
    Exception_identificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signed_numberContext *signed_number();
    Defined_valueContext *defined_value();
    TypeContext *type();
    antlr4::tree::TerminalNode *COLON_TK();
    ValueContext *value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Exception_identificationContext* exception_identification();

  class  Encoding_control_sectionsContext : public antlr4::ParserRuleContext {
  public:
    Encoding_control_sectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Encoding_control_sectionContext *> encoding_control_section();
    Encoding_control_sectionContext* encoding_control_section(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Encoding_control_sectionsContext* encoding_control_sections();

  class  Encoding_control_sectionContext : public antlr4::ParserRuleContext {
  public:
    Encoding_control_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENCODING_CONTROL_RW();
    antlr4::tree::TerminalNode *ENCODING_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Encoding_control_sectionContext* encoding_control_section();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool item_specSempred(Item_specContext *_localctx, size_t predicateIndex);
  bool unionsSempred(UnionsContext *_localctx, size_t predicateIndex);
  bool property_settings_listSempred(Property_settings_listContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

