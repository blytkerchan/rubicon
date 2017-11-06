grammar asn1;

file : module_definition ;

// 12.38 - reserved words
// these have to come first so they take precedence over identifiers and somesuch
ABSENT_RW				: 'ABSENT' ;
INTERSECTION_RW			: 'INTERSECTION' ;
SEQUENCE_RW				: 'SEQUENCE' ;
ENCODING_CONTROL_RW		: 'ENCODING-CONTROL' ;
SET_RW					: 'SET' ;
ALL_RW					: 'ALL' ;
END_RW					: 'END' ;
MAX_RW					: 'MAX' ;
SETTINGS_RW				: 'SETTINGS' ;
APPLICATION_RW			: 'APPLICATION' ;
ENUMERATED_RW			: 'ENUMERATED' ;
MIN_RW					: 'MIN' ;
AUTOMATIC_RW			: 'AUTOMATIC' ;
EXCEPT_RW				: 'EXCEPT' ;
MINUS_INFINITY_RW		: 'MINUS-INFINITY' ;
STRING_RW				: 'STRING' ;
BEGIN_RW				: 'BEGIN' ;
EXPLICIT_RW				: 'EXPLICIT' ;
NOT_A_NUMBER_RW			: 'NOT-A-NUMBER' ;
BIT_RW					: 'BIT' ;
EXPORTS_RW				: 'EXPORTS' ;
NULL_RW					: 'NULL' ;
EXTENSIBILITY_RW		: 'EXTENSIBILITY' ;
TAGS_RW					: 'TAGS' ;
BOOLEAN_RW				: 'BOOLEAN' ;
EXTERNAL_RW				: 'EXTERNAL' ;
OBJECT_RW				: 'OBJECT' ;
FALSE_RW				: 'FALSE' ;
TIME_RW					: 'TIME' ;
CHARACTER_RW			: 'CHARACTER' ;
FROM_RW					: 'FROM' ;
OCTET_RW				: 'OCTET' ;
TIME_OF_DAY_RW			: 'TIME-OF-DAY' ;
CHOICE_RW				: 'CHOICE' ;
OF_RW					: 'OF' ;
TRUE_RW					: 'TRUE' ;
OID_IRI_RW				: 'OID-IRI' ;
COMPONENT_RW			: 'COMPONENT' ;
UNION_RW				: 'UNION' ;
COMPONENTS_RW			: 'COMPONENTS' ;
PATTERN_RW				: 'PATTERN' ;
IDENTIFIER_RW			: 'IDENTIFIER' ;
PDV_RW					: 'PDV' ;
UNIVERSAL_RW			: 'UNIVERSAL' ;
CONTAINING_RW			: 'CONTAINING' ;
IMPLICIT_RW				: 'IMPLICIT' ;
PLUS_INFINITY_RW	  	: 'PLUS-INFINITY' ;
DATE_RW					: 'DATE' ;
IMPLIED_RW				: 'IMPLIED' ;
PRESENT_RW				: 'PRESENT' ;
DATE_TIME_RW			: 'DATE-TIME' ;
IMPORTS_RW				: 'IMPORTS' ;
DEFAULT_RW				: 'DEFAULT' ;
INCLUDES_RW				: 'INCLUDES' ;
PRIVATE_RW				: 'PRIVATE' ;
DEFINITIONS_RW			: 'DEFINITIONS' ;
REAL_RW					: 'REAL' ;
DURATION_RW				: 'DURATION' ;
INSTRUCTIONS_RW	   		: 'INSTRUCTIONS' ;
RELATIVE_OID_RW	   		: 'RELATIVE-OID' ;
WITH_RW					: 'WITH' ;
EMBEDDED_RW				: 'EMBEDDED' ;
INTEGER_RW				: 'INTEGER' ;
RELATIVE_OID_IRI_RW   	: 'RELATIVE-OID-IRI' ;
OPTIONAL_RW				: 'OPTIONAL' ;

//////////////////////////////////////////////////
// lexical stuff (sections 11 and 12)
// X.680 section 11.1 table 2
fragment LATIN_CAPITAL_LETTER	: [A-Z] ;
fragment LATIN_SMALL_LETTER		: [a-z] ;
fragment DIGIT					: [0-9] ;
EXCLAMATION_MARK_TK				: '!' ;
fragment QUOTATION_MARK			: '"' ;
QUOTATION_MARK_TK				: '"' ;
fragment AMPERSAND				: '&' ;
fragment APOSTROPHE				: '\'' ;
fragment LEFT_PARENTHESIS		: '(' ;
LEFT_PARENTHESIS_TK				: '(' ;
fragment RIGHT_PARENTHESIS		: ')' ;
RIGHT_PARENTHESIS_TK			: ')' ;
ASTERISK_TK						: '*' ;
COMMA_TK						: ',' ;
fragment HYPHEN_MINUS			: '-' ;
fragment FULL_STOP				: '.' ;
FULL_STOP_TK					: '.' ;
SOLIDUS_TK						: '/' ;
COLON_TK						: ':' ;
SEMICOLON_TK					: ';' ;
LESS_THAN_SIGN_TK				: '<' ;
EQUALS_SIGN_TK					: '=' ;
fragment GREATER_THAN_SIGN		: '>' ;
COMMERCIAL_AT_TK				: '@' ;
LEFT_SQUARE_BRACKET_TK			: '[' ;
RIGHT_SQUARE_BRACKET_TK			: ']' ;
CIRCUMFLEX_ACCENT_TK			: '^' ;
fragment LOW_LINE				: '_' ;
fragment LEFT_CURLY_BRACKET		: '{' ;
LEFT_CURLY_BRACKET_TK			: '{' ;
VERTICAL_LINE_TK				: '|' ;
fragment RIGHT_CURLY_BRACKET	: '}' ;
RIGHT_CURLY_BRACKET_TK			: '}' ;
fragment NON_BREAKING_HYPHEN	: '\u2011' ;
// X.680 11.8
fragment HYPHEN					: ( HYPHEN_MINUS | NON_BREAKING_HYPHEN ) ;
HYPHEN_TK						: ( HYPHEN_MINUS | NON_BREAKING_HYPHEN ) ;
// 12.1.6
fragment HORIZONTAL_TABULATION	: '\t' ;
fragment LINE_FEED				: '\n' ;
fragment VERTICAL_TABULATION	: '\u000b' ;
fragment FORM_FEED				: '\u000c' ;
fragment CARRIAGE_RETURN		: '\r' ;
fragment SPACE					: ' ' ;
fragment NO_BREAK_SPACE			: '\u00a0' ;
fragment WHITE_SPACE
	: HORIZONTAL_TABULATION
	| LINE_FEED
	| VERTICAL_TABULATION
	| FORM_FEED
	| CARRIAGE_RETURN
	| SPACE
	| NO_BREAK_SPACE
	;
//NEW_LINE
//	: LINE_FEED
//	| VERTICAL_TABULATION
//	| FORM_FEED
//	| CARRIAGE_RETURN
//	;
WS : WHITE_SPACE+ -> channel(HIDDEN) ; // tell ANTLR to ignore white space

// 12.2 & 12.5
TYPE_REFERENCE_OR_MODULE_REFERENCE
	: LATIN_CAPITAL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;

// 12.3 & 12.4 (IDENTIFIER and VALUE_REFERENCE are gramatically the same
IDENTIFIER
	: LATIN_SMALL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;

// shared for 12.2 and 12.3
fragment TYPE_REFERENCE_OR_IDENTIFIER_CHUNK
	: (LATIN_CAPITAL_LETTER | LATIN_SMALL_LETTER | DIGIT)+
	;

TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT
	: ( HYPHEN TYPE_REFERENCE_OR_IDENTIFIER_CHUNK )+
	;

// 12.8
NUMBER
	: '0'
	| DIGIT+ // validation that it doesn't start with 0 will be done in code
	;

// 12.9
REAL_NUMBER
	: NUMBER FULL_STOP NUMBER ( 'e' | 'E' ) NUMBER
	| NUMBER FULL_STOP NUMBER
	| NUMBER ( 'e' | 'E' ) NUMBER
	| NUMBER
	;

// 12.10
BSTRING
	: APOSTROPHE ( '0' | '1' | WHITE_SPACE )* '\'B'
	;

// 12.12
HSTRING
	: APOSTROPHE ( '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' | 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | WHITE_SPACE )* '\'H'
	;

// 12.14
CSTRING
	: QUOTATION_MARK ( ( QUOTATION_MARK QUOTATION_MARK ) | . )*? QUOTATION_MARK
	;

// 12.16 is not implemented in the grammar: the interpreter will have to verify
//	   the validity of the string. Here, we just say that a SIMPLE_STRING is a string
SIMPLE_STRING : CSTRING ;

// 12.17
TSTRING
	: QUOTATION_MARK ( DIGIT | '+' | '-' | ':' | '.' | ',' | '/' | 'C' | 'D' | 'H' | 'M' | 'R' | 'P' | 'S' | 'T' | 'W' | 'Y' | 'Z' )* QUOTATION_MARK
	;

// 12.19
PS_NAME : TYPE_REFERENCE_OR_MODULE_REFERENCE ; // the grammer is identical

// 12.20 - 12.24
ASSIGNMENT				: '::=' ;
RANGE_SEPARATOR			: '..' ;
ELLIPSIS				: '...' ;
LEFT_VERSION_BRACKETS	: '[[' ;
RIGHT_VERSION_BRACKETS	: ']]' ;

// section 13
module_definition
	: module_identifier DEFINITIONS_RW encoding_reference_default? tag_default? extension_default? ASSIGNMENT BEGIN_RW module_body encoding_control_sections? END_RW
	;

module_identifier
	: TYPE_REFERENCE_OR_MODULE_REFERENCE definitive_identification?
	;

definitive_identification
	: definitive_oid
	| definitive_oid_and_iri
	;

definitive_oid
	: LEFT_CURLY_BRACKET_TK definitive_object_id_component_list RIGHT_CURLY_BRACKET_TK
	;

definitive_oid_and_iri
	: definitive_oid iri_value
	;

definitive_object_id_component_list
	: definitive_object_id_component+
	;

definitive_object_id_component
	: name_form
	| definitive_number_form
	| definitive_name_and_number_form
	;

definitive_number_form
	: NUMBER
	;

definitive_name_and_number_form
	: IDENTIFIER LEFT_PARENTHESIS_TK definitive_number_form RIGHT_PARENTHESIS_TK
	;

encoding_reference_default
	: ( ENCODING_REFERENCE COLON_TK )? INSTRUCTIONS_RW
	;

tag_default
	: EXPLICIT_RW TAGS_RW	# explicit_tags
	| IMPLICIT_RW TAGS_RW	# implicit_tags
	| AUTOMATIC_RW TAGS_RW	# automatic_tags
	;

extension_default
	: EXTENSIBILITY_RW IMPLIED_RW
	;

module_body
	: exports imports assignment_list?
	;

exports
	: (EXPORTS_RW symbols_exported SEMICOLON_TK | EXPORTS_RW ALL_RW SEMICOLON_TK)?
	;

symbols_exported
	: symbol_list?
	;

imports
	: (IMPORTS_RW symbols_imported SEMICOLON_TK)?
	;

symbols_imported
	: symbols_from_module_list?
	;

symbols_from_module_list
	: symbols_from_module+
	;

symbols_from_module
	: symbol_list FROM_RW global_module_reference
	;

global_module_reference
	: TYPE_REFERENCE_OR_MODULE_REFERENCE assigned_identifier?
	;

assigned_identifier
	: object_identifier_value
	| defined_value
	;

symbol_list
	: symbol (COMMA_TK symbol)*
	;

symbol
	: reference
	;

reference
	: TYPE_REFERENCE_OR_MODULE_REFERENCE
	| IDENTIFIER
	;

assignment_list
	: assignment+
	;

assignment
	: type_assignment
	| value_assignment
	| value_set_type_assignment
	;

// section 14
defined_type
	: external_type_reference
	| TYPE_REFERENCE_OR_MODULE_REFERENCE
	;

defined_value
	: external_value_reference
	| IDENTIFIER
	;
external_type_reference
	: TYPE_REFERENCE_OR_MODULE_REFERENCE FULL_STOP_TK TYPE_REFERENCE_OR_MODULE_REFERENCE
	;

external_value_reference
	: TYPE_REFERENCE_OR_MODULE_REFERENCE FULL_STOP_TK IDENTIFIER
	;

// section 15
absolute_reference
	: COMMERCIAL_AT_TK module_identifier FULL_STOP_TK item_spec
	;

item_spec
	: TYPE_REFERENCE_OR_MODULE_REFERENCE
	| item_spec FULL_STOP_TK component_id
	;

component_id
	: IDENTIFIER
	| NUMBER
	| ASTERISK_TK
	;

// section 16
type_assignment
	: TYPE_REFERENCE_OR_MODULE_REFERENCE ASSIGNMENT type
	;
	
value_assignment
	: IDENTIFIER type ASSIGNMENT value
	;
	
value_set_type_assignment
	: TYPE_REFERENCE_OR_MODULE_REFERENCE type ASSIGNMENT value_set
	;
value_set
	: LEFT_CURLY_BRACKET_TK element_set_specs RIGHT_CURLY_BRACKET_TK
	;

// section 17
type
	: builtin_type
	| referenced_type
	| constrained_type
	;

builtin_type
	: bit_string_type 
	| BOOLEAN_RW
	| character_string_type
	| choice_type
	| DATE_RW
	| DATE_TIME_RW
	| DURATION_RW
	| EMBEDDED_RW PDV_RW
	| enumerated_type
	| EXTERNAL_RW
	| integer_type
	| OID_IRI_RW
	| NULL_RW
	| OBJECT_RW IDENTIFIER_RW
	| OCTET_RW STRING_RW
	| REAL_RW
	| RELATIVE_OID_IRI_RW
	| RELATIVE_OID_RW
	| sequence_or_set_type
	| sequence_or_set_of_type
	| prefixed_type
	| TIME_RW
	| TIME_OF_DAY_RW
	;
	
referenced_type
	: defined_type
	| useful_type
	| selection_type
	;

named_type
	: IDENTIFIER type
	;

value
	: builtin_value
	| defined_value
	;

builtin_value
	: bit_string_value
	| boolean_value
	| character_string_value
	| choice_value
	| embedded_pdv_value
	| enumerated_value
	| integer_value
	| iri_value
	| NULL_RW
	| object_identifier_value
	| octet_string_value
	| real_value
	| relative_iri_value
	| relative_oid_value
	| sequence_value
	| sequence_of_value
	| set_value
	| set_of_value
	| time_value
	;

named_value
	: IDENTIFIER value
	;

// sections 18 -
boolean_value
	: TRUE_RW
	| FALSE_RW
	;

integer_type
	: INTEGER_RW
	| INTEGER_RW LEFT_CURLY_BRACKET_TK named_number_list RIGHT_CURLY_BRACKET_TK
	;

named_number_list
	: named_number (COMMA_TK named_number)*
	;

named_number
	: IDENTIFIER LEFT_PARENTHESIS_TK signed_number RIGHT_PARENTHESIS_TK
	| IDENTIFIER LEFT_PARENTHESIS_TK defined_value RIGHT_PARENTHESIS_TK
	| TYPE_REFERENCE_OR_MODULE_REFERENCE LEFT_PARENTHESIS_TK signed_number RIGHT_PARENTHESIS_TK // in this context, we don't care if it starts with an uppercase letter (but the lexer does)
	| TYPE_REFERENCE_OR_MODULE_REFERENCE LEFT_PARENTHESIS_TK defined_value RIGHT_PARENTHESIS_TK
	;

signed_number
	: NUMBER
	| HYPHEN_TK NUMBER
	;

integer_value
	: signed_number
	| IDENTIFIER
	;

enumerated_type
	: ENUMERATED_RW LEFT_CURLY_BRACKET_TK enumerations RIGHT_CURLY_BRACKET_TK
	;

enumerations
	: root_enumeration
	| root_enumeration COMMA_TK ELLIPSIS exception_spec?
	| root_enumeration COMMA_TK ELLIPSIS exception_spec? COMMA_TK additional_enumeration
	;

root_enumeration
	: enumeration
	;

additional_enumeration
	: enumeration
	;

enumeration
	: enumeration_item (COMMA_TK enumeration_item)*
	;

enumeration_item
	: IDENTIFIER
	| named_number
	;

enumerated_value
	: IDENTIFIER
	;

real_value
	: numeric_real_value
	| special_real_value
	;

numeric_real_value
	: REAL_NUMBER
	| HYPHEN_TK REAL_NUMBER
	| sequence_value
	;

special_real_value
	: PLUS_INFINITY_RW
	| MINUS_INFINITY_RW
	| NOT_A_NUMBER_RW
	;

bit_string_type
	: BIT_RW STRING_RW
	| BIT_RW STRING_RW LEFT_CURLY_BRACKET_TK named_bit_list RIGHT_CURLY_BRACKET_TK
	;

named_bit_list
	: named_bit (COMMA_TK named_bit)*
	;

named_bit
	: IDENTIFIER LEFT_PARENTHESIS_TK NUMBER RIGHT_PARENTHESIS_TK
	| IDENTIFIER LEFT_PARENTHESIS_TK defined_value RIGHT_PARENTHESIS_TK
	;

bit_string_value
	: BSTRING
	| HSTRING
	| LEFT_CURLY_BRACKET_TK identifier_list RIGHT_CURLY_BRACKET_TK
	| LEFT_CURLY_BRACKET_TK RIGHT_CURLY_BRACKET_TK
	| CONTAINING_RW value
	;

identifier_list
	: IDENTIFIER (COMMA_TK IDENTIFIER)*
	;

octet_string_value
	: BSTRING
	| HSTRING
	| CONTAINING_RW value
	;

sequence_or_set_type
	: SEQUENCE_RW LEFT_CURLY_BRACKET_TK RIGHT_CURLY_BRACKET_TK
	| SEQUENCE_RW LEFT_CURLY_BRACKET_TK component_type_lists RIGHT_CURLY_BRACKET_TK
	;
sequence_or_set_of_type
	: SEQUENCE_RW OF_RW type
	| SEQUENCE_RW OF_RW named_type
	| SET_RW OF_RW type
	| SET_RW OF_RW named_type
	;
extension_and_exception
	: ELLIPSIS exception_spec?
	;
optional_extension_marker
	: COMMA_TK ELLIPSIS
	;
component_type_lists
	: component_type_list
	| component_type_list COMMA_TK extension_and_exception extension_additions? optional_extension_marker
	| component_type_list COMMA_TK extension_and_exception extension_additions? extension_end_marker COMMA_TK component_type_list
	| extension_and_exception extension_additions? extension_end_marker COMMA_TK component_type_list
	| extension_and_exception extension_additions? optional_extension_marker?
	;
extension_end_marker
	: COMMA_TK ELLIPSIS
	;
extension_additions
	: COMMA_TK extension_addition_list
	;
extension_addition_list
	: extension_addition (COMMA_TK extension_addition)*
	;
extension_addition
	: component_type
	| extension_addition_group
	;
extension_addition_group
	: LEFT_VERSION_BRACKETS version_number? component_type_list RIGHT_VERSION_BRACKETS
	;
version_number
	: NUMBER COLON_TK
	;
component_type_list
	: component_type (COMMA_TK component_type)*
	;
component_type
	: named_type
	| named_type OPTIONAL_RW
	| named_type DEFAULT_RW value
	| COMPONENTS_RW OF_RW type
	;

sequence_value
	: LEFT_CURLY_BRACKET_TK component_value_list? RIGHT_CURLY_BRACKET_TK
	;

component_value_list
	: named_value (COMMA_TK named_value)*
	;

sequence_of_value
	: LEFT_CURLY_BRACKET_TK value_list RIGHT_CURLY_BRACKET_TK
	| LEFT_CURLY_BRACKET_TK named_value_list RIGHT_CURLY_BRACKET_TK
	| LEFT_CURLY_BRACKET_TK RIGHT_CURLY_BRACKET_TK
	;
value_list
	: value
	| value_list COMMA_TK value
	;
named_value_list
	: named_value
	| named_value_list COMMA_TK named_value
	;
set_value
	: LEFT_CURLY_BRACKET_TK component_value_list? RIGHT_CURLY_BRACKET_TK
	;
set_of_value
	: LEFT_CURLY_BRACKET_TK value_list RIGHT_CURLY_BRACKET_TK
	| LEFT_CURLY_BRACKET_TK named_value_list RIGHT_CURLY_BRACKET_TK
	| LEFT_CURLY_BRACKET_TK RIGHT_CURLY_BRACKET_TK
	;
choice_type
	: CHOICE_RW LEFT_CURLY_BRACKET_TK alternative_type_lists RIGHT_CURLY_BRACKET_TK
	;
alternative_type_lists
	: root_alternative_type_list
	| root_alternative_type_list COMMA_TK extension_and_exception extension_addition_alternatives? optional_extension_marker
	;
root_alternative_type_list
	: alternative_type_list
	;
extension_addition_alternatives
	: COMMA_TK extension_addition_alternatives_list
	;
extension_addition_alternatives_list
	: extension_addition_alternative (COMMA_TK extension_addition_alternative)*
	;
extension_addition_alternative
	: extension_addition_alternatives_group
	| named_type
	;
extension_addition_alternatives_group
	: LEFT_VERSION_BRACKETS version_number alternative_type_list RIGHT_VERSION_BRACKETS
	;
alternative_type_list
	: named_type (COMMA_TK named_type)*
	;
choice_value
	: IDENTIFIER COLON_TK value
	;
selection_type
	: IDENTIFIER LESS_THAN_SIGN_TK type
	;
prefixed_type
	: tagged_type
	| encoding_prefixed_type
	;
tagged_type
	: tag type
	| tag IMPLICIT_RW type
	| tag EXPLICIT_RW type
	;
tag
	: LEFT_SQUARE_BRACKET_TK ( ENCODING_REFERENCE COLON_TK )? category? class_number RIGHT_SQUARE_BRACKET_TK
	;
ENCODING_REFERENCE
	: LATIN_CAPITAL_LETTER+
	;
class_number
	: NUMBER
	| defined_value
	;
category
	: UNIVERSAL_RW
	| APPLICATION_RW
	| PRIVATE_RW
	;
encoding_prefixed_type
	: encoding_prefix type
	;
encoding_prefix
	: LEFT_SQUARE_BRACKET_TK ( ENCODING_REFERENCE COLON_TK )? ENCODING_REFERENCE RIGHT_SQUARE_BRACKET_TK
	;
object_identifier_value
	: LEFT_CURLY_BRACKET_TK obj_id_components+ RIGHT_CURLY_BRACKET_TK
	;
obj_id_components
	: name_form
	| number_form
	| name_and_number_form
	| defined_value
	;
name_form
	: IDENTIFIER
	;
number_form
	: NUMBER
	| defined_value
	;
name_and_number_form
	: IDENTIFIER LEFT_PARENTHESIS_TK number_form RIGHT_PARENTHESIS_TK
	| TYPE_REFERENCE_OR_MODULE_REFERENCE LEFT_PARENTHESIS_TK number_form RIGHT_PARENTHESIS_TK // in this context, we don't care if it starts with an uppercase
	;
relative_oid_value
	: LEFT_CURLY_BRACKET_TK relative_oid_components_list RIGHT_CURLY_BRACKET_TK
	;
relative_oid_components_list
	: relative_oid_components+
	;
relative_oid_components
	: number_form
	| name_and_number_form
	| defined_value
	;
iri_value
	: QUOTATION_MARK_TK (SOLIDUS_TK arc_identifier)+ QUOTATION_MARK_TK
	;
arc_identifier
	: NUMBER
	| IDENTIFIER LEFT_PARENTHESIS_TK NUMBER RIGHT_PARENTHESIS_TK
	| TYPE_REFERENCE_OR_MODULE_REFERENCE LEFT_PARENTHESIS_TK NUMBER RIGHT_PARENTHESIS_TK
	;
relative_iri_value
	: QUOTATION_MARK_TK first_relative_arc_identifier (SOLIDUS_TK arc_identifier)+ QUOTATION_MARK_TK
	;
first_relative_arc_identifier
	: arc_identifier
	;
embedded_pdv_value
	: sequence_value
	;
time_value
	: TSTRING
	;
character_string_type
	: restricted_character_string_type
	| unrestricted_character_string_type
	;
character_string_value
	: restricted_character_string_value
	| unrestricted_character_string_value
	;
restricted_character_string_type
	: 'BMPString'
	| 'GeneralString'
	| 'GraphicString'
	| 'IA5String'
	| 'ISO646String'
	| 'NumericString'
	| 'PrintableString'
	| 'TeletexString'
	| 'T61String'
	| 'UniversalString'
	| 'UTF8String'
	| 'VideotexString'
	| 'VisibleString'
	;
restricted_character_string_value
	: CSTRING
	| character_string_list
	| quadruple
	| tuple
	;
character_string_list
	: LEFT_CURLY_BRACKET_TK chars_defn (COMMA_TK chars_defn)* RIGHT_CURLY_BRACKET_TK
	;
chars_defn
	: CSTRING
	| quadruple
	| tuple
	| defined_value
	;
quadruple
	: LEFT_CURLY_BRACKET_TK group COMMA_TK plane COMMA_TK row COMMA_TK cell RIGHT_CURLY_BRACKET_TK
	;
group
	: NUMBER
	;
plane
	: NUMBER
	;
row
	: NUMBER
	;
cell
	: NUMBER
	;
tuple
	: LEFT_CURLY_BRACKET_TK table_column COMMA_TK table_row RIGHT_CURLY_BRACKET_TK
	;
table_column
	: NUMBER
	;
table_row
	: NUMBER
	;
unrestricted_character_string_type
	: CHARACTER_RW STRING_RW
	;
unrestricted_character_string_value
	: sequence_value
	;
useful_type
	: 'GeneralizedTime'
	| 'UTCTime'
	| 'ObjectDescriptor'
	;
constrained_type
	: ( builtin_type | referenced_type ) constraint
	| type_with_constraint
	;

type_with_constraint
	: SET_RW constraint OF_RW type
	| SEQUENCE_RW constraint OF_RW type
	| SET_RW constraint OF_RW named_type
	| SEQUENCE_RW constraint OF_RW named_type
	;
constraint
	: LEFT_PARENTHESIS_TK constraint_spec exception_spec? RIGHT_PARENTHESIS_TK
	;
constraint_spec
	: subtype_constraint
	;
subtype_constraint
	: element_set_specs
	;
element_set_specs
	: root_element_set_spec
	| root_element_set_spec COMMA_TK ELLIPSIS
	| root_element_set_spec COMMA_TK ELLIPSIS COMMA_TK additional_element_set_spec
	;
root_element_set_spec
	: element_set_spec
	;
additional_element_set_spec
	: element_set_spec
	;
element_set_spec
	: unions
	| ALL_RW exclusions
	;
unions
	: intersections
	| unions union_mark intersections
	;
intersections
	: intersection_elements
	| intersection_elements intersection_mark intersection_elements
	;
intersection_elements
	: elements
	| elems exclusions
	;
elems
	: elements
	;
exclusions
	: EXCEPT_RW elements
	;
union_mark
	: VERTICAL_LINE_TK
	| UNION_RW
	;
intersection_mark
	: CIRCUMFLEX_ACCENT_TK
	| INTERSECTION_RW
	;
elements
	: subtype_elements
	| LEFT_PARENTHESIS_TK element_set_spec RIGHT_PARENTHESIS_TK
	;
subtype_elements
	: single_value
	| contained_subtype
	| value_range
	| permitted_alphabet
	| type_constraint
	| inner_type_constraints
	| pattern_constraint
	| property_settings
	| duration_range
	| time_point_range
	| recurrence_range
	;
single_value
	: value
	;
contained_subtype
	: includes? type
	;
includes
	: INCLUDES_RW
	;
value_range
	: lower_endpoint RANGE_SEPARATOR upper_endpoint
	;
lower_endpoint
	: lower_end_value
	| lower_end_value LESS_THAN_SIGN_TK
	;
upper_endpoint
	: upper_end_value
	| LESS_THAN_SIGN_TK upper_end_value
	;
lower_end_value
	: value
	| MIN_RW
	;
upper_end_value
	: value
	| MAX_RW
	;
type_constraint
	: type
	;
permitted_alphabet
	: FROM_RW constraint
	;
inner_type_constraints
	: WITH_RW COMPONENT_RW single_type_constraint
	| WITH_RW COMPONENTS_RW multiple_type_constraints
	;
single_type_constraint
	: constraint
	;
multiple_type_constraints
	: full_specification
	| partial_specification
	;
full_specification
	: LEFT_CURLY_BRACKET_TK type_constraints RIGHT_CURLY_BRACKET_TK
	;
partial_specification
	: LEFT_CURLY_BRACKET_TK ELLIPSIS COMMA_TK type_constraints RIGHT_CURLY_BRACKET_TK
	;
type_constraints
	: named_constraint
	| named_constraint COMMA_TK type_constraints
	;
named_constraint
	: IDENTIFIER component_constraint?
	;

component_constraint
	: value_constraint presence_constraint
	| presence_constraint
	| value_constraint
	;
value_constraint
	: constraint
	;
presence_constraint
	: PRESENT_RW
	| ABSENT_RW
	| OPTIONAL_RW
	;
pattern_constraint
	: PATTERN_RW value
	;
property_settings
	: SETTINGS_RW SIMPLE_STRING
	;
property_settings_list
	: property_and_setting_pair
	| property_settings_list property_and_setting_pair
	;
property_and_setting_pair
	: property_name EQUALS_SIGN_TK setting_name
	;
property_name
	: PS_NAME
	;
setting_name
	: PS_NAME
	;
duration_range
	: value_range
	;
time_point_range
	: value_range
	;
recurrence_range
	: value_range
	;
exception_spec
	: EXCLAMATION_MARK_TK exception_identification
	;
exception_identification
	: signed_number
	| defined_value
	| type COLON_TK value
	;
encoding_control_sections
	: encoding_control_section+
	;
encoding_control_section
	: ENCODING_CONTROL_RW ENCODING_REFERENCE
	;

