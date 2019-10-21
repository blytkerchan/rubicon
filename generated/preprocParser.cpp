
// Generated from preproc.g4 by ANTLR 4.7.2


#include "preprocListener.h"

#include "preprocParser.h"


using namespace antlrcpp;
using namespace antlr4;

preprocParser::preprocParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

preprocParser::~preprocParser() {
  delete _interpreter;
}

std::string preprocParser::getGrammarFileName() const {
  return "preproc.g4";
}

const std::vector<std::string>& preprocParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& preprocParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

preprocParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<preprocParser::TextContext *> preprocParser::FileContext::text() {
  return getRuleContexts<preprocParser::TextContext>();
}

preprocParser::TextContext* preprocParser::FileContext::text(size_t i) {
  return getRuleContext<preprocParser::TextContext>(i);
}


size_t preprocParser::FileContext::getRuleIndex() const {
  return preprocParser::RuleFile;
}

void preprocParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void preprocParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

preprocParser::FileContext* preprocParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, preprocParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << preprocParser::BEGIN_C_STYLE_COMMENT)
      | (1ULL << preprocParser::ADA_STYLE_COMMENT_DELIM)
      | (1ULL << preprocParser::NEWLINE)
      | (1ULL << preprocParser::QUOTE)
      | (1ULL << preprocParser::CHAR))) != 0)) {
      setState(12);
      text();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextContext ------------------------------------------------------------------

preprocParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

preprocParser::C_style_commentContext* preprocParser::TextContext::c_style_comment() {
  return getRuleContext<preprocParser::C_style_commentContext>(0);
}

preprocParser::Ada_style_commentContext* preprocParser::TextContext::ada_style_comment() {
  return getRuleContext<preprocParser::Ada_style_commentContext>(0);
}

preprocParser::Quoted_textContext* preprocParser::TextContext::quoted_text() {
  return getRuleContext<preprocParser::Quoted_textContext>(0);
}

preprocParser::Non_quoted_textContext* preprocParser::TextContext::non_quoted_text() {
  return getRuleContext<preprocParser::Non_quoted_textContext>(0);
}


size_t preprocParser::TextContext::getRuleIndex() const {
  return preprocParser::RuleText;
}

void preprocParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}

void preprocParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}

preprocParser::TextContext* preprocParser::text() {
  TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, getState());
  enterRule(_localctx, 2, preprocParser::RuleText);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(18);
      c_style_comment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(19);
      ada_style_comment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(20);
      quoted_text();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(21);
      non_quoted_text();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- C_style_commentContext ------------------------------------------------------------------

preprocParser::C_style_commentContext::C_style_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* preprocParser::C_style_commentContext::BEGIN_C_STYLE_COMMENT() {
  return getToken(preprocParser::BEGIN_C_STYLE_COMMENT, 0);
}

std::vector<tree::TerminalNode *> preprocParser::C_style_commentContext::END_C_STYLE_COMMENT() {
  return getTokens(preprocParser::END_C_STYLE_COMMENT);
}

tree::TerminalNode* preprocParser::C_style_commentContext::END_C_STYLE_COMMENT(size_t i) {
  return getToken(preprocParser::END_C_STYLE_COMMENT, i);
}

std::vector<tree::TerminalNode *> preprocParser::C_style_commentContext::ADA_STYLE_COMMENT_DELIM() {
  return getTokens(preprocParser::ADA_STYLE_COMMENT_DELIM);
}

tree::TerminalNode* preprocParser::C_style_commentContext::ADA_STYLE_COMMENT_DELIM(size_t i) {
  return getToken(preprocParser::ADA_STYLE_COMMENT_DELIM, i);
}

std::vector<tree::TerminalNode *> preprocParser::C_style_commentContext::NEWLINE() {
  return getTokens(preprocParser::NEWLINE);
}

tree::TerminalNode* preprocParser::C_style_commentContext::NEWLINE(size_t i) {
  return getToken(preprocParser::NEWLINE, i);
}


size_t preprocParser::C_style_commentContext::getRuleIndex() const {
  return preprocParser::RuleC_style_comment;
}

void preprocParser::C_style_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterC_style_comment(this);
}

void preprocParser::C_style_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitC_style_comment(this);
}

preprocParser::C_style_commentContext* preprocParser::c_style_comment() {
  C_style_commentContext *_localctx = _tracker.createInstance<C_style_commentContext>(_ctx, getState());
  enterRule(_localctx, 4, preprocParser::RuleC_style_comment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case preprocParser::BEGIN_C_STYLE_COMMENT: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        match(preprocParser::BEGIN_C_STYLE_COMMENT);
        setState(28);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << preprocParser::BEGIN_C_STYLE_COMMENT)
          | (1ULL << preprocParser::ADA_STYLE_COMMENT_DELIM)
          | (1ULL << preprocParser::NEWLINE)
          | (1ULL << preprocParser::QUOTE)
          | (1ULL << preprocParser::CHAR))) != 0)) {
          setState(25);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == preprocParser::END_C_STYLE_COMMENT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(30);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(31);
        match(preprocParser::END_C_STYLE_COMMENT);
        break;
      }

      case preprocParser::ADA_STYLE_COMMENT_DELIM: {
        enterOuterAlt(_localctx, 2);
        setState(32);
        match(preprocParser::ADA_STYLE_COMMENT_DELIM);
        setState(36);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << preprocParser::BEGIN_C_STYLE_COMMENT)
          | (1ULL << preprocParser::END_C_STYLE_COMMENT)
          | (1ULL << preprocParser::QUOTE)
          | (1ULL << preprocParser::CHAR))) != 0)) {
          setState(33);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == preprocParser::ADA_STYLE_COMMENT_DELIM

          || _la == preprocParser::NEWLINE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(38);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(39);
        match(preprocParser::ADA_STYLE_COMMENT_DELIM);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ada_style_commentContext ------------------------------------------------------------------

preprocParser::Ada_style_commentContext::Ada_style_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> preprocParser::Ada_style_commentContext::ADA_STYLE_COMMENT_DELIM() {
  return getTokens(preprocParser::ADA_STYLE_COMMENT_DELIM);
}

tree::TerminalNode* preprocParser::Ada_style_commentContext::ADA_STYLE_COMMENT_DELIM(size_t i) {
  return getToken(preprocParser::ADA_STYLE_COMMENT_DELIM, i);
}

std::vector<tree::TerminalNode *> preprocParser::Ada_style_commentContext::NEWLINE() {
  return getTokens(preprocParser::NEWLINE);
}

tree::TerminalNode* preprocParser::Ada_style_commentContext::NEWLINE(size_t i) {
  return getToken(preprocParser::NEWLINE, i);
}


size_t preprocParser::Ada_style_commentContext::getRuleIndex() const {
  return preprocParser::RuleAda_style_comment;
}

void preprocParser::Ada_style_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAda_style_comment(this);
}

void preprocParser::Ada_style_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAda_style_comment(this);
}

preprocParser::Ada_style_commentContext* preprocParser::ada_style_comment() {
  Ada_style_commentContext *_localctx = _tracker.createInstance<Ada_style_commentContext>(_ctx, getState());
  enterRule(_localctx, 6, preprocParser::RuleAda_style_comment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(preprocParser::ADA_STYLE_COMMENT_DELIM);
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << preprocParser::BEGIN_C_STYLE_COMMENT)
      | (1ULL << preprocParser::END_C_STYLE_COMMENT)
      | (1ULL << preprocParser::QUOTE)
      | (1ULL << preprocParser::CHAR))) != 0)) {
      setState(43);
      _la = _input->LA(1);
      if (_la == 0 || _la == Token::EOF || (_la == preprocParser::ADA_STYLE_COMMENT_DELIM

      || _la == preprocParser::NEWLINE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    match(preprocParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Quoted_textContext ------------------------------------------------------------------

preprocParser::Quoted_textContext::Quoted_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> preprocParser::Quoted_textContext::QUOTE() {
  return getTokens(preprocParser::QUOTE);
}

tree::TerminalNode* preprocParser::Quoted_textContext::QUOTE(size_t i) {
  return getToken(preprocParser::QUOTE, i);
}

std::vector<tree::TerminalNode *> preprocParser::Quoted_textContext::CHAR() {
  return getTokens(preprocParser::CHAR);
}

tree::TerminalNode* preprocParser::Quoted_textContext::CHAR(size_t i) {
  return getToken(preprocParser::CHAR, i);
}


size_t preprocParser::Quoted_textContext::getRuleIndex() const {
  return preprocParser::RuleQuoted_text;
}

void preprocParser::Quoted_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuoted_text(this);
}

void preprocParser::Quoted_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuoted_text(this);
}

preprocParser::Quoted_textContext* preprocParser::quoted_text() {
  Quoted_textContext *_localctx = _tracker.createInstance<Quoted_textContext>(_ctx, getState());
  enterRule(_localctx, 8, preprocParser::RuleQuoted_text);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(preprocParser::QUOTE);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(52);
        match(preprocParser::CHAR); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(58);
    match(preprocParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_quoted_textContext ------------------------------------------------------------------

preprocParser::Non_quoted_textContext::Non_quoted_textContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> preprocParser::Non_quoted_textContext::CHAR() {
  return getTokens(preprocParser::CHAR);
}

tree::TerminalNode* preprocParser::Non_quoted_textContext::CHAR(size_t i) {
  return getToken(preprocParser::CHAR, i);
}

tree::TerminalNode* preprocParser::Non_quoted_textContext::NEWLINE() {
  return getToken(preprocParser::NEWLINE, 0);
}


size_t preprocParser::Non_quoted_textContext::getRuleIndex() const {
  return preprocParser::RuleNon_quoted_text;
}

void preprocParser::Non_quoted_textContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNon_quoted_text(this);
}

void preprocParser::Non_quoted_textContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<preprocListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNon_quoted_text(this);
}

preprocParser::Non_quoted_textContext* preprocParser::non_quoted_text() {
  Non_quoted_textContext *_localctx = _tracker.createInstance<Non_quoted_textContext>(_ctx, getState());
  enterRule(_localctx, 10, preprocParser::RuleNon_quoted_text);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case preprocParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(61); 
        _errHandler->sync(this);
        alt = 1 + 1;
        do {
          switch (alt) {
            case 1 + 1: {
                  setState(60);
                  match(preprocParser::CHAR);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(63); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
        } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case preprocParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(preprocParser::NEWLINE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> preprocParser::_decisionToDFA;
atn::PredictionContextCache preprocParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN preprocParser::_atn;
std::vector<uint16_t> preprocParser::_serializedATN;

std::vector<std::string> preprocParser::_ruleNames = {
  "file", "text", "c_style_comment", "ada_style_comment", "quoted_text", 
  "non_quoted_text"
};

std::vector<std::string> preprocParser::_literalNames = {
  "", "'/*'", "'*/'", "'--'", "", "'\"'"
};

std::vector<std::string> preprocParser::_symbolicNames = {
  "", "BEGIN_C_STYLE_COMMENT", "END_C_STYLE_COMMENT", "ADA_STYLE_COMMENT_DELIM", 
  "NEWLINE", "QUOTE", "CHAR"
};

dfa::Vocabulary preprocParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> preprocParser::_tokenNames;

preprocParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8, 0x47, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x7, 0x2, 0x10, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x13, 0xb, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x1d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x20, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x25, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x28, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2b, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x2f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x32, 0xb, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x38, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x3b, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x6, 0x7, 0x40, 
    0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x41, 0x3, 0x7, 0x5, 0x7, 0x45, 0xa, 0x7, 
    0x3, 0x7, 0x4, 0x39, 0x41, 0x2, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 
    0x4, 0x3, 0x2, 0x4, 0x4, 0x3, 0x2, 0x5, 0x6, 0x2, 0x4b, 0x2, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x35, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10, 0x5, 0x4, 0x3, 0x2, 0xf, 0xe, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0x13, 0x3, 0x2, 0x2, 0x2, 0x11, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 0x2, 0x12, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x14, 0x19, 0x5, 0x6, 0x4, 0x2, 
    0x15, 0x19, 0x5, 0x8, 0x5, 0x2, 0x16, 0x19, 0x5, 0xa, 0x6, 0x2, 0x17, 
    0x19, 0x5, 0xc, 0x7, 0x2, 0x18, 0x14, 0x3, 0x2, 0x2, 0x2, 0x18, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1e, 0x7, 0x3, 
    0x2, 0x2, 0x1b, 0x1d, 0xa, 0x2, 0x2, 0x2, 0x1c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x21, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x22, 0x26, 
    0x7, 0x5, 0x2, 0x2, 0x23, 0x25, 0xa, 0x3, 0x2, 0x2, 0x24, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x7, 0x5, 0x2, 0x2, 
    0x2a, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x22, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x30, 0x7, 0x5, 0x2, 0x2, 0x2d, 0x2f, 
    0xa, 0x3, 0x2, 0x2, 0x2e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x33, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x34, 0x7, 0x6, 0x2, 0x2, 0x34, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x39, 0x7, 0x7, 0x2, 0x2, 0x36, 0x38, 0x7, 0x8, 0x2, 0x2, 0x37, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x7, 
    0x2, 0x2, 0x3d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x8, 0x2, 
    0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x45, 0x7, 0x6, 0x2, 0x2, 0x44, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xb, 0x11, 0x18, 0x1e, 0x26, 0x2a, 0x30, 0x39, 0x41, 
    0x44, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

preprocParser::Initializer preprocParser::_init;
