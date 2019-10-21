
// Generated from preproc.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "preprocParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by preprocParser.
 */
class  preprocListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(preprocParser::FileContext *ctx) = 0;
  virtual void exitFile(preprocParser::FileContext *ctx) = 0;

  virtual void enterText(preprocParser::TextContext *ctx) = 0;
  virtual void exitText(preprocParser::TextContext *ctx) = 0;

  virtual void enterC_style_comment(preprocParser::C_style_commentContext *ctx) = 0;
  virtual void exitC_style_comment(preprocParser::C_style_commentContext *ctx) = 0;

  virtual void enterAda_style_comment(preprocParser::Ada_style_commentContext *ctx) = 0;
  virtual void exitAda_style_comment(preprocParser::Ada_style_commentContext *ctx) = 0;

  virtual void enterQuoted_text(preprocParser::Quoted_textContext *ctx) = 0;
  virtual void exitQuoted_text(preprocParser::Quoted_textContext *ctx) = 0;

  virtual void enterNon_quoted_text(preprocParser::Non_quoted_textContext *ctx) = 0;
  virtual void exitNon_quoted_text(preprocParser::Non_quoted_textContext *ctx) = 0;


};

