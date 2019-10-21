
// Generated from asn1.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  asn1Lexer : public antlr4::Lexer {
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

  asn1Lexer(antlr4::CharStream *input);
  ~asn1Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

