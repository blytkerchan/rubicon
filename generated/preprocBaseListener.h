
// Generated from preproc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "preprocListener.h"


/**
 * This class provides an empty implementation of preprocListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  preprocBaseListener : public preprocListener {
public:

  virtual void enterFile(preprocParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(preprocParser::FileContext * /*ctx*/) override { }

  virtual void enterText(preprocParser::TextContext * /*ctx*/) override { }
  virtual void exitText(preprocParser::TextContext * /*ctx*/) override { }

  virtual void enterC_style_comment(preprocParser::C_style_commentContext * /*ctx*/) override { }
  virtual void exitC_style_comment(preprocParser::C_style_commentContext * /*ctx*/) override { }

  virtual void enterAda_style_comment(preprocParser::Ada_style_commentContext * /*ctx*/) override { }
  virtual void exitAda_style_comment(preprocParser::Ada_style_commentContext * /*ctx*/) override { }

  virtual void enterQuoted_text(preprocParser::Quoted_textContext * /*ctx*/) override { }
  virtual void exitQuoted_text(preprocParser::Quoted_textContext * /*ctx*/) override { }

  virtual void enterNon_quoted_text(preprocParser::Non_quoted_textContext * /*ctx*/) override { }
  virtual void exitNon_quoted_text(preprocParser::Non_quoted_textContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

