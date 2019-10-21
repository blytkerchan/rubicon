
// Generated from preproc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  preprocParser : public antlr4::Parser {
public:
  enum {
    BEGIN_C_STYLE_COMMENT = 1, END_C_STYLE_COMMENT = 2, ADA_STYLE_COMMENT_DELIM = 3, 
    NEWLINE = 4, QUOTE = 5, CHAR = 6
  };

  enum {
    RuleFile = 0, RuleText = 1, RuleC_style_comment = 2, RuleAda_style_comment = 3, 
    RuleQuoted_text = 4, RuleNon_quoted_text = 5
  };

  preprocParser(antlr4::TokenStream *input);
  ~preprocParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class TextContext;
  class C_style_commentContext;
  class Ada_style_commentContext;
  class Quoted_textContext;
  class Non_quoted_textContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TextContext *> text();
    TextContext* text(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    C_style_commentContext *c_style_comment();
    Ada_style_commentContext *ada_style_comment();
    Quoted_textContext *quoted_text();
    Non_quoted_textContext *non_quoted_text();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TextContext* text();

  class  C_style_commentContext : public antlr4::ParserRuleContext {
  public:
    C_style_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN_C_STYLE_COMMENT();
    std::vector<antlr4::tree::TerminalNode *> END_C_STYLE_COMMENT();
    antlr4::tree::TerminalNode* END_C_STYLE_COMMENT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ADA_STYLE_COMMENT_DELIM();
    antlr4::tree::TerminalNode* ADA_STYLE_COMMENT_DELIM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  C_style_commentContext* c_style_comment();

  class  Ada_style_commentContext : public antlr4::ParserRuleContext {
  public:
    Ada_style_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ADA_STYLE_COMMENT_DELIM();
    antlr4::tree::TerminalNode* ADA_STYLE_COMMENT_DELIM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ada_style_commentContext* ada_style_comment();

  class  Quoted_textContext : public antlr4::ParserRuleContext {
  public:
    Quoted_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CHAR();
    antlr4::tree::TerminalNode* CHAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Quoted_textContext* quoted_text();

  class  Non_quoted_textContext : public antlr4::ParserRuleContext {
  public:
    Non_quoted_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHAR();
    antlr4::tree::TerminalNode* CHAR(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Non_quoted_textContext* non_quoted_text();


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

