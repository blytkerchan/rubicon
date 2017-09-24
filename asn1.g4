grammar asn1;

//////////////////////////////////////////////////
// lexical stuff (sections 11 and 12)
// X.680 section 11.1 table 2
LATIN_CAPITAL_LETTER	: [A-Z] ;
LATIN_SMALL_LETTER		: [a-z] ;
DIGIT					: [0-9] ;
EXCLAMATION_MARK		: '!' ;
QUOTATION_MARK			: '"' ;
AMPERSAND				: '&' ;
APOSTROPHE				: '\'' ;
LEFT_PARENTHESIS		: '(' ;
RIGHT_PARENTHESIS		: ')' ;
ASTERISK				: '*' ;
COMMA					: ',' ;
HYPHEN_MINUS			: '-' ;
FULL_STOP				: '.' ;
SOLIDUS					: '/' ;
COLON					: ':' ;
SEMICOLON				: ';' ;
LESS_THAN_SIGN			: '<' ;
EQUALS_SIGN				: '=' ;
GREATER_THAN_SIGN		: '>' ;
COMMERCIAL_AT			: '@' ;
LEFT_SQUARE_BRACKET		: '[' ;
RIGHT_SQUARE_BRACKET	: ']' ;
CIRCUMFLEX_ACCENT		: '^' ;
LOW_LINE				: '_' ;
LEFT_CURLY_BRACKET		: '{' ;
VERTICAL_LINE			: '|' ;
RIGHT_CURLY_BRACKET		: '}' ;
NON_BREAKING_HYPHEN		: '\u2011' ;
// X.680 11.8
HYPHEN			: ( HYPHEN_MINUS | NON_BREAKING_HYPHEN ) ;
// 12.1.6
HORIZONTAL_TABULATION	: '\t' ;
LINE_FEED				: '\n' ;
VERTICAL_TABULATION		: '\u000b' ;
FORM_FEED				: '\u000c' ;
CARRIAGE_RETURN			: '\r' ;
SPACE					: ' ' ;
NO_BREAK_SPACE			: '\u00a0' ;
WHITE_SPACE
	: HORIZONTAL_TABULATION
	| LINE_FEED
	| VERTICAL_TABULATION
	| FORM_FEED
	| CARRIAGE_RETURN
	| SPACE
	| NO_BREAK_SPACE
	;
NEW_LINE
	: LINE_FEED
	| VERTICAL_TABULATION
	| FORM_FEED
	| CARRIAGE_RETURN
	;
WS : WHITE_SPACE ; // tell ANTLR to ignore white space

// 12.2
TYPE_REFERENCE
	: LATIN_CAPITAL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;
	
// 12.3
IDENTIFIER
	: LATIN_SMALL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;
	
// 12.4
VALUE_REFERENCE
	: LATIN_SMALL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;

// 12.5
MODULE_REFERENCE
	: LATIN_CAPITAL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
	;

// shared for 12.2 and 12.3
TYPE_REFERENCE_OR_IDENTIFIER_CHUNK
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
PS_NAME : TYPE_REFERENCE ; // the grammer is identical

// 12.20 - 12.24
ASSIGNMENT				: '::=' ;
RANGE_SEPARATOR			: '..' ;
ELLIPSIS				: '...' ;
LEFT_VERSION_BRACKETS	: '[[' ;
RIGHT_VERSION_BRACKETS	: ']]' ;

// 12.26
INTEGER_UNICODE_LABEL
	: NUMBER
	;

// 12.27
NON_INTEGER_UNICODE_LABEL
	: ( LATIN_CAPITAL_LETTER | LATIN_SMALL_LETTER | DIGIT )+
	| ( LATIN_CAPITAL_LETTER | LATIN_SMALL_LETTER | DIGIT )+ WHITE_SPACE* LEFT_PARENTHESIS WHITE_SPACE* DIGIT+ WHITE_SPACE* RIGHT_PARENTHESIS
	;

// 12.38 - reserved words
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

// section 13
module_definition
	: module_identifier DEFINITIONS_RW encoding_reference_default? tag_default? extension_default? ASSIGNMENT BEGIN_RW module_body encoding_control_sections? END_RW
	;

module_identifier
	: MODULE_REFERENCE definitive_identification?
	;

definitive_identification
	: definitive_oid
	| definitive_oid_and_iri
	;

definitive_oid
	: LEFT_CURLY_BRACKET definitive_object_id_component_list RIGHT_CURLY_BRACKET
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
	: IDENTIFIER_RW LEFT_PARENTHESIS definitive_number_form RIGHT_PARENTHESIS
	;

encoding_reference_default
	: ( ( encoding_reference COLON )? INSTRUCTIONS_RW)
	;

tag_default
	: (EXPLICIT_RW TAGS_RW  | IMPLICIT_RW TAGS_RW  | AUTOMATIC_RW TAGS_RW)
	;
	
extension_default
	: (EXTENSIBILITY_RW IMPLIED_RW)
	;

module_body
	: (exports imports assignment_list)?
	;
	
exports
	: (EXPORTS_RW symbols_exported SEMICOLON | EXPORTS_RW ALL_RW SEMICOLON)?
	;
	
symbols_exported
	: symbol_list?
	;

imports
	: (IMPORTS_RW symbols_imported SEMICOLON)?
	;
	
symbols_imported
	: symbols_from_module_list?
	;

symbols_from_module_list
	: symbols_from_module
	| symbols_from_module_list symbols_from_module
	;

symbols_from_module
	: symbol_list FROM_RW global_module_reference
	;

global_module_reference
	: MODULE_REFERENCE assigned_identifier
	;

assigned_identifier
	: (object_identifier_value | defined_value)?
	;

symbol_list
	: symbol 
	| symbol_list COMMA symbol
	;

symbol
	: reference
	;

reference
	: TYPE_REFERENCE
	| VALUE_REFERENCE
	;

assignment_list
	: assignment
	| assignment_list assignment
	;

assignment
	: type_assignment
	| value_assignment
	| value_set_type_assignment
	;

// section 14
defined_type
	: external_type_reference
	| TYPE_REFERENCE
	;
	
defined_value
	: external_value_reference
	| VALUE_REFERENCE
	;

non_parameterized_type_name
	: external_type_reference
	| TYPE_REFERENCE 
	;
	
external_type_reference
	: MODULE_REFERENCE FULL_STOP TYPE_REFERENCE
	;

external_value_reference
	: MODULE_REFERENCE FULL_STOP VALUE_REFERENCE
	;

// section 15
absolute_reference
	: COMMERCIAL_AT module_identifier FULL_STOP item_spec
	;

item_spec
	: TYPE_REFERENCE
	| item_spec FULL_STOP component_id
	;

component_id
	: IDENTIFIER
	| NUMBER
	| ASTERISK
	;

// section 16
type_assignment
	: TYPE_REFERENCE ASSIGNMENT type
	;
	
value_assignment
	: VALUE_REFERENCE type ASSIGNMENT value
	;
	
value_set_type_assignment
	: TYPE_REFERENCE type ASSIGNMENT value_set
	;
value_set
	: LEFT_CURLY_BRACKET element_set_specs RIGHT_CURLY_BRACKET
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
	| date_type
	| date_time_type
	| duration_type
	| EMBEDDED_RW PDV_RW
	| enumerated_type
	| EXTERNAL_RW
	| integer_type
	| iri_type
	| null_type
	| object_identifier_type
	| octet_string_type
	| real_type
	| relative_iri_type
	| relative_oid_type
	| sequence_type
	| sequence_of_type
	| set_type
	| set_of_type
	| prefixed_type
	| time_type
	| time_of_day_type
	;
	
referenced_type
	: defined_type
	| useful_type
	| selection_type
//	| TypeFromObject	// not implemented
//	| ValueSetFromObjects // not implemented
	;

named_type
	: IDENTIFIER type
	;

value
	: builtin_value
	| referenced_value
//	| ObjectClassFieldValue // not implemented
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
	| null_value
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
// 17.10 not implemented
referenced_value
	: defined_value
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
	| INTEGER_RW LEFT_CURLY_BRACKET named_number_list RIGHT_CURLY_BRACKET
	;

named_number_list
	: named_number
	| named_number_list COMMA named_number
	;

named_number
	: IDENTIFIER LEFT_PARENTHESIS signed_number RIGHT_PARENTHESIS
	| IDENTIFIER LEFT_PARENTHESIS defined_value RIGHT_PARENTHESIS
	;

signed_number
	: NUMBER
	| HYPHEN NUMBER
	;

integer_value
	: signed_number
	| IDENTIFIER
	;

enumerated_type
	: ENUMERATED_RW LEFT_CURLY_BRACKET enumerations RIGHT_CURLY_BRACKET
	;

enumerations
	: root_enumeration
	| root_enumeration COMMA ELLIPSIS exception_spec?
	| root_enumeration COMMA ELLIPSIS exception_spec? COMMA additional_enumeration
	;

root_enumeration
	: enumeration
	;

additional_enumeration
	: enumeration
	;

enumeration
	: enumeration_item
	| enumeration_item COMMA enumeration
	;

enumeration_item
	: IDENTIFIER
	| named_number
	;

enumerated_value
	: IDENTIFIER
	;

real_type
	: REAL_RW
	;

real_value
	: numeric_real_value
	| special_real_value
	;

numeric_real_value
	: REAL_NUMBER
	| HYPHEN REAL_NUMBER
	| sequence_value
	;

special_real_value
	: PLUS_INFINITY_RW
	| MINUS_INFINITY_RW
	| NOT_A_NUMBER_RW
	;

bit_string_type
	: BIT_RW STRING_RW
	| BIT_RW STRING_RW LEFT_CURLY_BRACKET named_bit_list RIGHT_CURLY_BRACKET
	;

named_bit_list
	: named_bit
	| named_bit_list COMMA named_bit
	;

named_bit
	: IDENTIFIER LEFT_PARENTHESIS NUMBER RIGHT_PARENTHESIS
	| IDENTIFIER LEFT_PARENTHESIS defined_value RIGHT_PARENTHESIS
	;

bit_string_value
	: BSTRING
	| HSTRING
	| LEFT_CURLY_BRACKET identifier_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	| CONTAINING_RW value
	;

identifier_list
	: IDENTIFIER
	| identifier_list COMMA IDENTIFIER
	;

octet_string_type
	: OCTET_RW STRING_RW
	;

octet_string_value
	: BSTRING
	| HSTRING
	| CONTAINING_RW value
	;

null_type
	: NULL_RW
	;

null_value
	: NULL_RW
	;

sequence_type
	: SEQUENCE_RW LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	| SEQUENCE_RW LEFT_CURLY_BRACKET extension_and_exception optional_extension_marker? RIGHT_CURLY_BRACKET
	| SEQUENCE_RW LEFT_CURLY_BRACKET component_type_lists RIGHT_CURLY_BRACKET
	;
sequence_of_type
	: SEQUENCE_RW OF_RW type
	| SEQUENCE_RW OF_RW named_type
	;
extension_and_exception
	: ELLIPSIS
	| ELLIPSIS exception_spec?
	;
optional_extension_marker
	: COMMA ELLIPSIS
	;
component_type_lists
	: root_component_type_list
	| root_component_type_list COMMA extension_and_exception extension_additions? optional_extension_marker
	| root_component_type_list COMMA extension_and_exception extension_additions? extension_end_marker COMMA root_component_type_list
	| extension_and_exception extension_additions? extension_end_marker COMMA root_component_type_list
	| extension_and_exception extension_additions? optional_extension_marker
	;
root_component_type_list
	: component_type_list
	;
extension_end_marker
	: COMMA ELLIPSIS
	;
extension_additions
	: COMMA extension_addition_list
	;
extension_addition_list
	: extension_addition
	| extension_addition_list COMMA extension_addition
	;
extension_addition
	: component_type
	| extension_addition_group
	;
extension_addition_group
	: LEFT_VERSION_BRACKETS version_number? component_type_list RIGHT_VERSION_BRACKETS
	;
version_number
	: NUMBER COLON
	;
component_type_list
	: component_type
	| component_type_list COMMA component_type
	;
component_type
	: named_type
	| named_type OPTIONAL_RW
	| named_type DEFAULT_RW value
	| COMPONENTS_RW OF_RW type
	;

sequence_value
	: LEFT_CURLY_BRACKET component_value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	;

component_value_list
	: named_value
	| component_value_list COMMA named_value
	;

sequence_of_value
	: LEFT_CURLY_BRACKET value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET named_value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	;
value_list
	: value
	| value_list COMMA value
	;
named_value_list
	: named_value
	| named_value_list COMMA named_value
	;

set_type
	: SET_RW LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET 
	| SET_RW LEFT_CURLY_BRACKET extension_and_exception optional_extension_marker RIGHT_CURLY_BRACKET
	| SET_RW LEFT_CURLY_BRACKET component_type_lists RIGHT_CURLY_BRACKET 
	;
set_value
	: LEFT_CURLY_BRACKET component_value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	;
set_of_type
	: SET_RW OF_RW type
	| SET_RW OF_RW named_type
	;
set_of_value
	: LEFT_CURLY_BRACKET value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET named_value_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET
	;
choice_type
	: CHOICE_RW LEFT_CURLY_BRACKET alternative_type_lists RIGHT_CURLY_BRACKET
	;
alternative_type_lists
	: root_alternative_type_list
	| root_alternative_type_list COMMA extension_and_exception extension_addition_alternatives? optional_extension_marker
	;
root_alternative_type_list
	: alternative_type_list
	;
extension_addition_alternatives
	: COMMA extension_addition_alternatives_list
	;
extension_addition_alternatives_list
	: extension_addition_alternative
	| extension_addition_alternatives_list COMMA extension_addition_alternative
	;
extension_addition_alternative
	: extension_addition_alternatives_group
	| named_type
	;
extension_addition_alternatives_group
	: LEFT_VERSION_BRACKETS version_number alternative_type_list RIGHT_VERSION_BRACKETS
	;
alternative_type_list
	: named_type
	| alternative_type_list COMMA named_type
	;
choice_value
	: IDENTIFIER COLON value
	;
selection_type
	: IDENTIFIER LESS_THAN_SIGN type
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
	: LEFT_SQUARE_BRACKET ( encoding_reference COLON )? category? class_number RIGHT_SQUARE_BRACKET
	;
encoding_reference
	: LATIN_SMALL_LETTER TYPE_REFERENCE_OR_IDENTIFIER_CHUNK? TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT?
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
	: LEFT_SQUARE_BRACKET ( encoding_reference COLON )? encoding_reference RIGHT_SQUARE_BRACKET
	;
object_identifier_type
	: OBJECT_RW IDENTIFIER_RW
	;
object_identifier_value
	: LEFT_CURLY_BRACKET obj_id_components_list RIGHT_CURLY_BRACKET
	| LEFT_CURLY_BRACKET defined_value obj_id_components_list RIGHT_CURLY_BRACKET
	;
obj_id_components_list
	: obj_id_components
	| obj_id_components obj_id_components_list
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
	: IDENTIFIER LEFT_PARENTHESIS number_form RIGHT_PARENTHESIS
	;
relative_oid_type
	: RELATIVE_OID_RW
	;
relative_oid_value
	: LEFT_CURLY_BRACKET relative_oid_components_list RIGHT_CURLY_BRACKET
	;
relative_oid_components_list
	: relative_oid_components
	| relative_oid_components relative_oid_components_list
	;
relative_oid_components
	: number_form
	| name_and_number_form
	| defined_value
	;
iri_type
	: OID_IRI_RW
	;
iri_value
	: QUOTATION_MARK first_arc_identifier subsequent_arc_identifier? QUOTATION_MARK
	;
first_arc_identifier
	: SOLIDUS arc_identifier
	;
subsequent_arc_identifier
	: SOLIDUS arc_identifier subsequent_arc_identifier
	;
arc_identifier
	: INTEGER_UNICODE_LABEL
	| NON_INTEGER_UNICODE_LABEL
	;
relative_iri_type
	: RELATIVE_OID_IRI_RW
	;
relative_iri_value
	: QUOTATION_MARK first_relative_arc_identifier subsequent_arc_identifier? QUOTATION_MARK
	;
first_relative_arc_identifier
	: arc_identifier
	;
embedded_pdv_value
	: sequence_value
	;
time_type
	: TIME_RW
	;
time_value
	: TSTRING
	;
date_type
	: DATE_RW
	;
time_of_day_type
	: TIME_OF_DAY_RW
	;
date_time_type
	: DATE_TIME_RW
	;
duration_type
	: DURATION_RW
	;
character_string_type
//	: restricted_character_string_type
	: unrestricted_character_string_type
	;
character_string_value
	: restricted_character_string_value
	| unrestricted_character_string_value
	;
//restricted_character_string_type
//	: BMPString 
//	| GeneralString
//	| GraphicString
//	| IA5String
//	| ISO646String
//	| NumericString
//	| PrintableString
//	| TeletexString
//	| T61String
//	| UniversalString
//	| UTF8String
//	| VideotexString
//	| VisibleString
//	;
restricted_character_string_value
	: CSTRING
	| character_string_list
	| quadruple
	| tuple
	;
character_string_list
	: LEFT_CURLY_BRACKET char_syms RIGHT_CURLY_BRACKET
	;
char_syms
	: chars_defn
	| char_syms COMMA chars_defn
	;
chars_defn
	: CSTRING
	| quadruple
	| tuple
	| defined_value
	;
quadruple
	: LEFT_CURLY_BRACKET group COMMA plane COMMA row COMMA cell RIGHT_CURLY_BRACKET
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
	: LEFT_CURLY_BRACKET table_column COMMA table_row RIGHT_CURLY_BRACKET
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
	: TYPE_REFERENCE
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
	: LEFT_PARENTHESIS constraint_spec exception_spec? RIGHT_PARENTHESIS
	;
constraint_spec
	: subtype_constraint
	;
subtype_constraint
	: element_set_specs
	;
element_set_specs
	: root_element_set_spec
	| root_element_set_spec COMMA ELLIPSIS
	| root_element_set_spec COMMA ELLIPSIS COMMA additional_element_set_spec
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
	: VERTICAL_LINE
	| UNION_RW
	;
intersection_mark
	: CIRCUMFLEX_ACCENT
	| INTERSECTION_RW
	;
elements
	: subtype_elements
	| LEFT_PARENTHESIS element_set_spec RIGHT_PARENTHESIS
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
	| lower_end_value LESS_THAN_SIGN
	;
upper_endpoint
	: upper_end_value
	| LESS_THAN_SIGN upper_end_value
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
	: LEFT_CURLY_BRACKET type_constraints RIGHT_CURLY_BRACKET
	;
partial_specification
	: LEFT_CURLY_BRACKET ELLIPSIS COMMA type_constraints RIGHT_CURLY_BRACKET
	;
type_constraints
	: named_constraint
	| named_constraint COMMA type_constraints
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
	: property_name EQUALS_SIGN setting_name
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
	: EXCLAMATION_MARK exception_identification
	;
exception_identification
	: signed_number
	| defined_value
	| type COLON value
	;
encoding_control_sections
	: encoding_control_section encoding_control_sections
	;
encoding_control_section
	: ENCODING_CONTROL_RW encoding_reference
	;
