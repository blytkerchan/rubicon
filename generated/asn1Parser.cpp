
// Generated from asn1.g4 by ANTLR 4.7.2


#include "asn1Listener.h"
#include "asn1Visitor.h"

#include "asn1Parser.h"


using namespace antlrcpp;
using namespace antlr4;

asn1Parser::asn1Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

asn1Parser::~asn1Parser() {
  delete _interpreter;
}

std::string asn1Parser::getGrammarFileName() const {
  return "asn1.g4";
}

const std::vector<std::string>& asn1Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& asn1Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

asn1Parser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Module_definitionContext* asn1Parser::FileContext::module_definition() {
  return getRuleContext<asn1Parser::Module_definitionContext>(0);
}


size_t asn1Parser::FileContext::getRuleIndex() const {
  return asn1Parser::RuleFile;
}

void asn1Parser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void asn1Parser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any asn1Parser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::FileContext* asn1Parser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, asn1Parser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    module_definition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_definitionContext ------------------------------------------------------------------

asn1Parser::Module_definitionContext::Module_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Module_identifierContext* asn1Parser::Module_definitionContext::module_identifier() {
  return getRuleContext<asn1Parser::Module_identifierContext>(0);
}

tree::TerminalNode* asn1Parser::Module_definitionContext::DEFINITIONS_RW() {
  return getToken(asn1Parser::DEFINITIONS_RW, 0);
}

tree::TerminalNode* asn1Parser::Module_definitionContext::ASSIGNMENT() {
  return getToken(asn1Parser::ASSIGNMENT, 0);
}

tree::TerminalNode* asn1Parser::Module_definitionContext::BEGIN_RW() {
  return getToken(asn1Parser::BEGIN_RW, 0);
}

asn1Parser::Module_bodyContext* asn1Parser::Module_definitionContext::module_body() {
  return getRuleContext<asn1Parser::Module_bodyContext>(0);
}

tree::TerminalNode* asn1Parser::Module_definitionContext::END_RW() {
  return getToken(asn1Parser::END_RW, 0);
}

asn1Parser::Encoding_reference_defaultContext* asn1Parser::Module_definitionContext::encoding_reference_default() {
  return getRuleContext<asn1Parser::Encoding_reference_defaultContext>(0);
}

asn1Parser::Tag_defaultContext* asn1Parser::Module_definitionContext::tag_default() {
  return getRuleContext<asn1Parser::Tag_defaultContext>(0);
}

asn1Parser::Extension_defaultContext* asn1Parser::Module_definitionContext::extension_default() {
  return getRuleContext<asn1Parser::Extension_defaultContext>(0);
}

asn1Parser::Encoding_control_sectionsContext* asn1Parser::Module_definitionContext::encoding_control_sections() {
  return getRuleContext<asn1Parser::Encoding_control_sectionsContext>(0);
}


size_t asn1Parser::Module_definitionContext::getRuleIndex() const {
  return asn1Parser::RuleModule_definition;
}

void asn1Parser::Module_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_definition(this);
}

void asn1Parser::Module_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_definition(this);
}


antlrcpp::Any asn1Parser::Module_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitModule_definition(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Module_definitionContext* asn1Parser::module_definition() {
  Module_definitionContext *_localctx = _tracker.createInstance<Module_definitionContext>(_ctx, getState());
  enterRule(_localctx, 2, asn1Parser::RuleModule_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    module_identifier();
    setState(373);
    match(asn1Parser::DEFINITIONS_RW);
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::INSTRUCTIONS_RW || _la == asn1Parser::ENCODING_REFERENCE) {
      setState(374);
      encoding_reference_default();
    }
    setState(378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << asn1Parser::AUTOMATIC_RW)
      | (1ULL << asn1Parser::EXPLICIT_RW)
      | (1ULL << asn1Parser::IMPLICIT_RW))) != 0)) {
      setState(377);
      tag_default();
    }
    setState(381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::EXTENSIBILITY_RW) {
      setState(380);
      extension_default();
    }
    setState(383);
    match(asn1Parser::ASSIGNMENT);
    setState(384);
    match(asn1Parser::BEGIN_RW);
    setState(385);
    module_body();
    setState(387);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::ENCODING_CONTROL_RW) {
      setState(386);
      encoding_control_sections();
    }
    setState(389);
    match(asn1Parser::END_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_identifierContext ------------------------------------------------------------------

asn1Parser::Module_identifierContext::Module_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Module_identifierContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

asn1Parser::Definitive_identificationContext* asn1Parser::Module_identifierContext::definitive_identification() {
  return getRuleContext<asn1Parser::Definitive_identificationContext>(0);
}


size_t asn1Parser::Module_identifierContext::getRuleIndex() const {
  return asn1Parser::RuleModule_identifier;
}

void asn1Parser::Module_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_identifier(this);
}

void asn1Parser::Module_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_identifier(this);
}


antlrcpp::Any asn1Parser::Module_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitModule_identifier(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Module_identifierContext* asn1Parser::module_identifier() {
  Module_identifierContext *_localctx = _tracker.createInstance<Module_identifierContext>(_ctx, getState());
  enterRule(_localctx, 4, asn1Parser::RuleModule_identifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::LEFT_CURLY_BRACKET_TK) {
      setState(392);
      definitive_identification();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definitive_identificationContext ------------------------------------------------------------------

asn1Parser::Definitive_identificationContext::Definitive_identificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Definitive_oidContext* asn1Parser::Definitive_identificationContext::definitive_oid() {
  return getRuleContext<asn1Parser::Definitive_oidContext>(0);
}

asn1Parser::Definitive_oid_and_iriContext* asn1Parser::Definitive_identificationContext::definitive_oid_and_iri() {
  return getRuleContext<asn1Parser::Definitive_oid_and_iriContext>(0);
}


size_t asn1Parser::Definitive_identificationContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_identification;
}

void asn1Parser::Definitive_identificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_identification(this);
}

void asn1Parser::Definitive_identificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_identification(this);
}


antlrcpp::Any asn1Parser::Definitive_identificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_identification(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_identificationContext* asn1Parser::definitive_identification() {
  Definitive_identificationContext *_localctx = _tracker.createInstance<Definitive_identificationContext>(_ctx, getState());
  enterRule(_localctx, 6, asn1Parser::RuleDefinitive_identification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(397);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(395);
      definitive_oid();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(396);
      definitive_oid_and_iri();
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

//----------------- Definitive_oidContext ------------------------------------------------------------------

asn1Parser::Definitive_oidContext::Definitive_oidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Definitive_oidContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Definitive_object_id_component_listContext* asn1Parser::Definitive_oidContext::definitive_object_id_component_list() {
  return getRuleContext<asn1Parser::Definitive_object_id_component_listContext>(0);
}

tree::TerminalNode* asn1Parser::Definitive_oidContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Definitive_oidContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_oid;
}

void asn1Parser::Definitive_oidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_oid(this);
}

void asn1Parser::Definitive_oidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_oid(this);
}


antlrcpp::Any asn1Parser::Definitive_oidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_oid(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_oidContext* asn1Parser::definitive_oid() {
  Definitive_oidContext *_localctx = _tracker.createInstance<Definitive_oidContext>(_ctx, getState());
  enterRule(_localctx, 8, asn1Parser::RuleDefinitive_oid);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(400);
    definitive_object_id_component_list();
    setState(401);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definitive_oid_and_iriContext ------------------------------------------------------------------

asn1Parser::Definitive_oid_and_iriContext::Definitive_oid_and_iriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Definitive_oidContext* asn1Parser::Definitive_oid_and_iriContext::definitive_oid() {
  return getRuleContext<asn1Parser::Definitive_oidContext>(0);
}

asn1Parser::Iri_valueContext* asn1Parser::Definitive_oid_and_iriContext::iri_value() {
  return getRuleContext<asn1Parser::Iri_valueContext>(0);
}


size_t asn1Parser::Definitive_oid_and_iriContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_oid_and_iri;
}

void asn1Parser::Definitive_oid_and_iriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_oid_and_iri(this);
}

void asn1Parser::Definitive_oid_and_iriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_oid_and_iri(this);
}


antlrcpp::Any asn1Parser::Definitive_oid_and_iriContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_oid_and_iri(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_oid_and_iriContext* asn1Parser::definitive_oid_and_iri() {
  Definitive_oid_and_iriContext *_localctx = _tracker.createInstance<Definitive_oid_and_iriContext>(_ctx, getState());
  enterRule(_localctx, 10, asn1Parser::RuleDefinitive_oid_and_iri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    definitive_oid();
    setState(404);
    iri_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definitive_object_id_component_listContext ------------------------------------------------------------------

asn1Parser::Definitive_object_id_component_listContext::Definitive_object_id_component_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Definitive_object_id_componentContext *> asn1Parser::Definitive_object_id_component_listContext::definitive_object_id_component() {
  return getRuleContexts<asn1Parser::Definitive_object_id_componentContext>();
}

asn1Parser::Definitive_object_id_componentContext* asn1Parser::Definitive_object_id_component_listContext::definitive_object_id_component(size_t i) {
  return getRuleContext<asn1Parser::Definitive_object_id_componentContext>(i);
}


size_t asn1Parser::Definitive_object_id_component_listContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_object_id_component_list;
}

void asn1Parser::Definitive_object_id_component_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_object_id_component_list(this);
}

void asn1Parser::Definitive_object_id_component_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_object_id_component_list(this);
}


antlrcpp::Any asn1Parser::Definitive_object_id_component_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_object_id_component_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_object_id_component_listContext* asn1Parser::definitive_object_id_component_list() {
  Definitive_object_id_component_listContext *_localctx = _tracker.createInstance<Definitive_object_id_component_listContext>(_ctx, getState());
  enterRule(_localctx, 12, asn1Parser::RuleDefinitive_object_id_component_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(406);
      definitive_object_id_component();
      setState(409); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::IDENTIFIER

    || _la == asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definitive_object_id_componentContext ------------------------------------------------------------------

asn1Parser::Definitive_object_id_componentContext::Definitive_object_id_componentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Name_formContext* asn1Parser::Definitive_object_id_componentContext::name_form() {
  return getRuleContext<asn1Parser::Name_formContext>(0);
}

asn1Parser::Definitive_number_formContext* asn1Parser::Definitive_object_id_componentContext::definitive_number_form() {
  return getRuleContext<asn1Parser::Definitive_number_formContext>(0);
}

asn1Parser::Definitive_name_and_number_formContext* asn1Parser::Definitive_object_id_componentContext::definitive_name_and_number_form() {
  return getRuleContext<asn1Parser::Definitive_name_and_number_formContext>(0);
}


size_t asn1Parser::Definitive_object_id_componentContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_object_id_component;
}

void asn1Parser::Definitive_object_id_componentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_object_id_component(this);
}

void asn1Parser::Definitive_object_id_componentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_object_id_component(this);
}


antlrcpp::Any asn1Parser::Definitive_object_id_componentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_object_id_component(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_object_id_componentContext* asn1Parser::definitive_object_id_component() {
  Definitive_object_id_componentContext *_localctx = _tracker.createInstance<Definitive_object_id_componentContext>(_ctx, getState());
  enterRule(_localctx, 14, asn1Parser::RuleDefinitive_object_id_component);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(414);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      name_form();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(412);
      definitive_number_form();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(413);
      definitive_name_and_number_form();
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

//----------------- Definitive_number_formContext ------------------------------------------------------------------

asn1Parser::Definitive_number_formContext::Definitive_number_formContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Definitive_number_formContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::Definitive_number_formContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_number_form;
}

void asn1Parser::Definitive_number_formContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_number_form(this);
}

void asn1Parser::Definitive_number_formContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_number_form(this);
}


antlrcpp::Any asn1Parser::Definitive_number_formContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_number_form(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_number_formContext* asn1Parser::definitive_number_form() {
  Definitive_number_formContext *_localctx = _tracker.createInstance<Definitive_number_formContext>(_ctx, getState());
  enterRule(_localctx, 16, asn1Parser::RuleDefinitive_number_form);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Definitive_name_and_number_formContext ------------------------------------------------------------------

asn1Parser::Definitive_name_and_number_formContext::Definitive_name_and_number_formContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Definitive_name_and_number_formContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Definitive_name_and_number_formContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

asn1Parser::Definitive_number_formContext* asn1Parser::Definitive_name_and_number_formContext::definitive_number_form() {
  return getRuleContext<asn1Parser::Definitive_number_formContext>(0);
}

tree::TerminalNode* asn1Parser::Definitive_name_and_number_formContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}


size_t asn1Parser::Definitive_name_and_number_formContext::getRuleIndex() const {
  return asn1Parser::RuleDefinitive_name_and_number_form;
}

void asn1Parser::Definitive_name_and_number_formContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitive_name_and_number_form(this);
}

void asn1Parser::Definitive_name_and_number_formContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitive_name_and_number_form(this);
}


antlrcpp::Any asn1Parser::Definitive_name_and_number_formContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefinitive_name_and_number_form(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Definitive_name_and_number_formContext* asn1Parser::definitive_name_and_number_form() {
  Definitive_name_and_number_formContext *_localctx = _tracker.createInstance<Definitive_name_and_number_formContext>(_ctx, getState());
  enterRule(_localctx, 18, asn1Parser::RuleDefinitive_name_and_number_form);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(asn1Parser::IDENTIFIER);
    setState(419);
    match(asn1Parser::LEFT_PARENTHESIS_TK);
    setState(420);
    definitive_number_form();
    setState(421);
    match(asn1Parser::RIGHT_PARENTHESIS_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Encoding_reference_defaultContext ------------------------------------------------------------------

asn1Parser::Encoding_reference_defaultContext::Encoding_reference_defaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Encoding_reference_defaultContext::INSTRUCTIONS_RW() {
  return getToken(asn1Parser::INSTRUCTIONS_RW, 0);
}

tree::TerminalNode* asn1Parser::Encoding_reference_defaultContext::ENCODING_REFERENCE() {
  return getToken(asn1Parser::ENCODING_REFERENCE, 0);
}

tree::TerminalNode* asn1Parser::Encoding_reference_defaultContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}


size_t asn1Parser::Encoding_reference_defaultContext::getRuleIndex() const {
  return asn1Parser::RuleEncoding_reference_default;
}

void asn1Parser::Encoding_reference_defaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEncoding_reference_default(this);
}

void asn1Parser::Encoding_reference_defaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEncoding_reference_default(this);
}


antlrcpp::Any asn1Parser::Encoding_reference_defaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEncoding_reference_default(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Encoding_reference_defaultContext* asn1Parser::encoding_reference_default() {
  Encoding_reference_defaultContext *_localctx = _tracker.createInstance<Encoding_reference_defaultContext>(_ctx, getState());
  enterRule(_localctx, 20, asn1Parser::RuleEncoding_reference_default);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::ENCODING_REFERENCE) {
      setState(423);
      match(asn1Parser::ENCODING_REFERENCE);
      setState(424);
      match(asn1Parser::COLON_TK);
    }
    setState(427);
    match(asn1Parser::INSTRUCTIONS_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tag_defaultContext ------------------------------------------------------------------

asn1Parser::Tag_defaultContext::Tag_defaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t asn1Parser::Tag_defaultContext::getRuleIndex() const {
  return asn1Parser::RuleTag_default;
}

void asn1Parser::Tag_defaultContext::copyFrom(Tag_defaultContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Automatic_tagsContext ------------------------------------------------------------------

tree::TerminalNode* asn1Parser::Automatic_tagsContext::AUTOMATIC_RW() {
  return getToken(asn1Parser::AUTOMATIC_RW, 0);
}

tree::TerminalNode* asn1Parser::Automatic_tagsContext::TAGS_RW() {
  return getToken(asn1Parser::TAGS_RW, 0);
}

asn1Parser::Automatic_tagsContext::Automatic_tagsContext(Tag_defaultContext *ctx) { copyFrom(ctx); }

void asn1Parser::Automatic_tagsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAutomatic_tags(this);
}
void asn1Parser::Automatic_tagsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAutomatic_tags(this);
}

antlrcpp::Any asn1Parser::Automatic_tagsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAutomatic_tags(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Implicit_tagsContext ------------------------------------------------------------------

tree::TerminalNode* asn1Parser::Implicit_tagsContext::IMPLICIT_RW() {
  return getToken(asn1Parser::IMPLICIT_RW, 0);
}

tree::TerminalNode* asn1Parser::Implicit_tagsContext::TAGS_RW() {
  return getToken(asn1Parser::TAGS_RW, 0);
}

asn1Parser::Implicit_tagsContext::Implicit_tagsContext(Tag_defaultContext *ctx) { copyFrom(ctx); }

void asn1Parser::Implicit_tagsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImplicit_tags(this);
}
void asn1Parser::Implicit_tagsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImplicit_tags(this);
}

antlrcpp::Any asn1Parser::Implicit_tagsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitImplicit_tags(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Explicit_tagsContext ------------------------------------------------------------------

tree::TerminalNode* asn1Parser::Explicit_tagsContext::EXPLICIT_RW() {
  return getToken(asn1Parser::EXPLICIT_RW, 0);
}

tree::TerminalNode* asn1Parser::Explicit_tagsContext::TAGS_RW() {
  return getToken(asn1Parser::TAGS_RW, 0);
}

asn1Parser::Explicit_tagsContext::Explicit_tagsContext(Tag_defaultContext *ctx) { copyFrom(ctx); }

void asn1Parser::Explicit_tagsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicit_tags(this);
}
void asn1Parser::Explicit_tagsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicit_tags(this);
}

antlrcpp::Any asn1Parser::Explicit_tagsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExplicit_tags(this);
  else
    return visitor->visitChildren(this);
}
asn1Parser::Tag_defaultContext* asn1Parser::tag_default() {
  Tag_defaultContext *_localctx = _tracker.createInstance<Tag_defaultContext>(_ctx, getState());
  enterRule(_localctx, 22, asn1Parser::RuleTag_default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::EXPLICIT_RW: {
        _localctx = dynamic_cast<Tag_defaultContext *>(_tracker.createInstance<asn1Parser::Explicit_tagsContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(429);
        match(asn1Parser::EXPLICIT_RW);
        setState(430);
        match(asn1Parser::TAGS_RW);
        break;
      }

      case asn1Parser::IMPLICIT_RW: {
        _localctx = dynamic_cast<Tag_defaultContext *>(_tracker.createInstance<asn1Parser::Implicit_tagsContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(431);
        match(asn1Parser::IMPLICIT_RW);
        setState(432);
        match(asn1Parser::TAGS_RW);
        break;
      }

      case asn1Parser::AUTOMATIC_RW: {
        _localctx = dynamic_cast<Tag_defaultContext *>(_tracker.createInstance<asn1Parser::Automatic_tagsContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(433);
        match(asn1Parser::AUTOMATIC_RW);
        setState(434);
        match(asn1Parser::TAGS_RW);
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

//----------------- Extension_defaultContext ------------------------------------------------------------------

asn1Parser::Extension_defaultContext::Extension_defaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_defaultContext::EXTENSIBILITY_RW() {
  return getToken(asn1Parser::EXTENSIBILITY_RW, 0);
}

tree::TerminalNode* asn1Parser::Extension_defaultContext::IMPLIED_RW() {
  return getToken(asn1Parser::IMPLIED_RW, 0);
}


size_t asn1Parser::Extension_defaultContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_default;
}

void asn1Parser::Extension_defaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_default(this);
}

void asn1Parser::Extension_defaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_default(this);
}


antlrcpp::Any asn1Parser::Extension_defaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_default(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_defaultContext* asn1Parser::extension_default() {
  Extension_defaultContext *_localctx = _tracker.createInstance<Extension_defaultContext>(_ctx, getState());
  enterRule(_localctx, 24, asn1Parser::RuleExtension_default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(asn1Parser::EXTENSIBILITY_RW);
    setState(438);
    match(asn1Parser::IMPLIED_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_bodyContext ------------------------------------------------------------------

asn1Parser::Module_bodyContext::Module_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ExportsContext* asn1Parser::Module_bodyContext::exports() {
  return getRuleContext<asn1Parser::ExportsContext>(0);
}

asn1Parser::ImportsContext* asn1Parser::Module_bodyContext::imports() {
  return getRuleContext<asn1Parser::ImportsContext>(0);
}

asn1Parser::Assignment_listContext* asn1Parser::Module_bodyContext::assignment_list() {
  return getRuleContext<asn1Parser::Assignment_listContext>(0);
}


size_t asn1Parser::Module_bodyContext::getRuleIndex() const {
  return asn1Parser::RuleModule_body;
}

void asn1Parser::Module_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_body(this);
}

void asn1Parser::Module_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_body(this);
}


antlrcpp::Any asn1Parser::Module_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitModule_body(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Module_bodyContext* asn1Parser::module_body() {
  Module_bodyContext *_localctx = _tracker.createInstance<Module_bodyContext>(_ctx, getState());
  enterRule(_localctx, 26, asn1Parser::RuleModule_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    exports();
    setState(441);
    imports();
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER) {
      setState(442);
      assignment_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExportsContext ------------------------------------------------------------------

asn1Parser::ExportsContext::ExportsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::ExportsContext::EXPORTS_RW() {
  return getToken(asn1Parser::EXPORTS_RW, 0);
}

asn1Parser::Symbols_exportedContext* asn1Parser::ExportsContext::symbols_exported() {
  return getRuleContext<asn1Parser::Symbols_exportedContext>(0);
}

tree::TerminalNode* asn1Parser::ExportsContext::SEMICOLON_TK() {
  return getToken(asn1Parser::SEMICOLON_TK, 0);
}

tree::TerminalNode* asn1Parser::ExportsContext::ALL_RW() {
  return getToken(asn1Parser::ALL_RW, 0);
}


size_t asn1Parser::ExportsContext::getRuleIndex() const {
  return asn1Parser::RuleExports;
}

void asn1Parser::ExportsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExports(this);
}

void asn1Parser::ExportsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExports(this);
}


antlrcpp::Any asn1Parser::ExportsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExports(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ExportsContext* asn1Parser::exports() {
  ExportsContext *_localctx = _tracker.createInstance<ExportsContext>(_ctx, getState());
  enterRule(_localctx, 28, asn1Parser::RuleExports);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(445);
      match(asn1Parser::EXPORTS_RW);
      setState(446);
      symbols_exported();
      setState(447);
      match(asn1Parser::SEMICOLON_TK);
      break;
    }

    case 2: {
      setState(449);
      match(asn1Parser::EXPORTS_RW);
      setState(450);
      match(asn1Parser::ALL_RW);
      setState(451);
      match(asn1Parser::SEMICOLON_TK);
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

//----------------- Symbols_exportedContext ------------------------------------------------------------------

asn1Parser::Symbols_exportedContext::Symbols_exportedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Symbol_listContext* asn1Parser::Symbols_exportedContext::symbol_list() {
  return getRuleContext<asn1Parser::Symbol_listContext>(0);
}


size_t asn1Parser::Symbols_exportedContext::getRuleIndex() const {
  return asn1Parser::RuleSymbols_exported;
}

void asn1Parser::Symbols_exportedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbols_exported(this);
}

void asn1Parser::Symbols_exportedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbols_exported(this);
}


antlrcpp::Any asn1Parser::Symbols_exportedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbols_exported(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Symbols_exportedContext* asn1Parser::symbols_exported() {
  Symbols_exportedContext *_localctx = _tracker.createInstance<Symbols_exportedContext>(_ctx, getState());
  enterRule(_localctx, 30, asn1Parser::RuleSymbols_exported);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER) {
      setState(454);
      symbol_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportsContext ------------------------------------------------------------------

asn1Parser::ImportsContext::ImportsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::ImportsContext::IMPORTS_RW() {
  return getToken(asn1Parser::IMPORTS_RW, 0);
}

asn1Parser::Symbols_importedContext* asn1Parser::ImportsContext::symbols_imported() {
  return getRuleContext<asn1Parser::Symbols_importedContext>(0);
}

tree::TerminalNode* asn1Parser::ImportsContext::SEMICOLON_TK() {
  return getToken(asn1Parser::SEMICOLON_TK, 0);
}


size_t asn1Parser::ImportsContext::getRuleIndex() const {
  return asn1Parser::RuleImports;
}

void asn1Parser::ImportsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImports(this);
}

void asn1Parser::ImportsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImports(this);
}


antlrcpp::Any asn1Parser::ImportsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitImports(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ImportsContext* asn1Parser::imports() {
  ImportsContext *_localctx = _tracker.createInstance<ImportsContext>(_ctx, getState());
  enterRule(_localctx, 32, asn1Parser::RuleImports);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::IMPORTS_RW) {
      setState(457);
      match(asn1Parser::IMPORTS_RW);
      setState(458);
      symbols_imported();
      setState(459);
      match(asn1Parser::SEMICOLON_TK);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Symbols_importedContext ------------------------------------------------------------------

asn1Parser::Symbols_importedContext::Symbols_importedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Symbols_from_module_listContext* asn1Parser::Symbols_importedContext::symbols_from_module_list() {
  return getRuleContext<asn1Parser::Symbols_from_module_listContext>(0);
}


size_t asn1Parser::Symbols_importedContext::getRuleIndex() const {
  return asn1Parser::RuleSymbols_imported;
}

void asn1Parser::Symbols_importedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbols_imported(this);
}

void asn1Parser::Symbols_importedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbols_imported(this);
}


antlrcpp::Any asn1Parser::Symbols_importedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbols_imported(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Symbols_importedContext* asn1Parser::symbols_imported() {
  Symbols_importedContext *_localctx = _tracker.createInstance<Symbols_importedContext>(_ctx, getState());
  enterRule(_localctx, 34, asn1Parser::RuleSymbols_imported);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(464);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER) {
      setState(463);
      symbols_from_module_list();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Symbols_from_module_listContext ------------------------------------------------------------------

asn1Parser::Symbols_from_module_listContext::Symbols_from_module_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Symbols_from_moduleContext *> asn1Parser::Symbols_from_module_listContext::symbols_from_module() {
  return getRuleContexts<asn1Parser::Symbols_from_moduleContext>();
}

asn1Parser::Symbols_from_moduleContext* asn1Parser::Symbols_from_module_listContext::symbols_from_module(size_t i) {
  return getRuleContext<asn1Parser::Symbols_from_moduleContext>(i);
}


size_t asn1Parser::Symbols_from_module_listContext::getRuleIndex() const {
  return asn1Parser::RuleSymbols_from_module_list;
}

void asn1Parser::Symbols_from_module_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbols_from_module_list(this);
}

void asn1Parser::Symbols_from_module_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbols_from_module_list(this);
}


antlrcpp::Any asn1Parser::Symbols_from_module_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbols_from_module_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Symbols_from_module_listContext* asn1Parser::symbols_from_module_list() {
  Symbols_from_module_listContext *_localctx = _tracker.createInstance<Symbols_from_module_listContext>(_ctx, getState());
  enterRule(_localctx, 36, asn1Parser::RuleSymbols_from_module_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(466);
      symbols_from_module();
      setState(469); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Symbols_from_moduleContext ------------------------------------------------------------------

asn1Parser::Symbols_from_moduleContext::Symbols_from_moduleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Symbol_listContext* asn1Parser::Symbols_from_moduleContext::symbol_list() {
  return getRuleContext<asn1Parser::Symbol_listContext>(0);
}

tree::TerminalNode* asn1Parser::Symbols_from_moduleContext::FROM_RW() {
  return getToken(asn1Parser::FROM_RW, 0);
}

asn1Parser::Global_module_referenceContext* asn1Parser::Symbols_from_moduleContext::global_module_reference() {
  return getRuleContext<asn1Parser::Global_module_referenceContext>(0);
}


size_t asn1Parser::Symbols_from_moduleContext::getRuleIndex() const {
  return asn1Parser::RuleSymbols_from_module;
}

void asn1Parser::Symbols_from_moduleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbols_from_module(this);
}

void asn1Parser::Symbols_from_moduleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbols_from_module(this);
}


antlrcpp::Any asn1Parser::Symbols_from_moduleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbols_from_module(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Symbols_from_moduleContext* asn1Parser::symbols_from_module() {
  Symbols_from_moduleContext *_localctx = _tracker.createInstance<Symbols_from_moduleContext>(_ctx, getState());
  enterRule(_localctx, 38, asn1Parser::RuleSymbols_from_module);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    symbol_list();
    setState(472);
    match(asn1Parser::FROM_RW);
    setState(473);
    global_module_reference();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_module_referenceContext ------------------------------------------------------------------

asn1Parser::Global_module_referenceContext::Global_module_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Global_module_referenceContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

asn1Parser::Assigned_identifierContext* asn1Parser::Global_module_referenceContext::assigned_identifier() {
  return getRuleContext<asn1Parser::Assigned_identifierContext>(0);
}


size_t asn1Parser::Global_module_referenceContext::getRuleIndex() const {
  return asn1Parser::RuleGlobal_module_reference;
}

void asn1Parser::Global_module_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal_module_reference(this);
}

void asn1Parser::Global_module_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal_module_reference(this);
}


antlrcpp::Any asn1Parser::Global_module_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitGlobal_module_reference(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Global_module_referenceContext* asn1Parser::global_module_reference() {
  Global_module_referenceContext *_localctx = _tracker.createInstance<Global_module_referenceContext>(_ctx, getState());
  enterRule(_localctx, 40, asn1Parser::RuleGlobal_module_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(477);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(476);
      assigned_identifier();
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

//----------------- Assigned_identifierContext ------------------------------------------------------------------

asn1Parser::Assigned_identifierContext::Assigned_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Object_identifier_valueContext* asn1Parser::Assigned_identifierContext::object_identifier_value() {
  return getRuleContext<asn1Parser::Object_identifier_valueContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::Assigned_identifierContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Assigned_identifierContext::getRuleIndex() const {
  return asn1Parser::RuleAssigned_identifier;
}

void asn1Parser::Assigned_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssigned_identifier(this);
}

void asn1Parser::Assigned_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssigned_identifier(this);
}


antlrcpp::Any asn1Parser::Assigned_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAssigned_identifier(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Assigned_identifierContext* asn1Parser::assigned_identifier() {
  Assigned_identifierContext *_localctx = _tracker.createInstance<Assigned_identifierContext>(_ctx, getState());
  enterRule(_localctx, 42, asn1Parser::RuleAssigned_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(481);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::LEFT_CURLY_BRACKET_TK: {
        enterOuterAlt(_localctx, 1);
        setState(479);
        object_identifier_value();
        break;
      }

      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(480);
        defined_value();
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

//----------------- Symbol_listContext ------------------------------------------------------------------

asn1Parser::Symbol_listContext::Symbol_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::SymbolContext *> asn1Parser::Symbol_listContext::symbol() {
  return getRuleContexts<asn1Parser::SymbolContext>();
}

asn1Parser::SymbolContext* asn1Parser::Symbol_listContext::symbol(size_t i) {
  return getRuleContext<asn1Parser::SymbolContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Symbol_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Symbol_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Symbol_listContext::getRuleIndex() const {
  return asn1Parser::RuleSymbol_list;
}

void asn1Parser::Symbol_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbol_list(this);
}

void asn1Parser::Symbol_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbol_list(this);
}


antlrcpp::Any asn1Parser::Symbol_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbol_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Symbol_listContext* asn1Parser::symbol_list() {
  Symbol_listContext *_localctx = _tracker.createInstance<Symbol_listContext>(_ctx, getState());
  enterRule(_localctx, 44, asn1Parser::RuleSymbol_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    symbol();
    setState(488);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(484);
      match(asn1Parser::COMMA_TK);
      setState(485);
      symbol();
      setState(490);
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

//----------------- SymbolContext ------------------------------------------------------------------

asn1Parser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ReferenceContext* asn1Parser::SymbolContext::reference() {
  return getRuleContext<asn1Parser::ReferenceContext>(0);
}


size_t asn1Parser::SymbolContext::getRuleIndex() const {
  return asn1Parser::RuleSymbol;
}

void asn1Parser::SymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbol(this);
}

void asn1Parser::SymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbol(this);
}


antlrcpp::Any asn1Parser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::SymbolContext* asn1Parser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 46, asn1Parser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    reference();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReferenceContext ------------------------------------------------------------------

asn1Parser::ReferenceContext::ReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::ReferenceContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

tree::TerminalNode* asn1Parser::ReferenceContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::ReferenceContext::getRuleIndex() const {
  return asn1Parser::RuleReference;
}

void asn1Parser::ReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReference(this);
}

void asn1Parser::ReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReference(this);
}


antlrcpp::Any asn1Parser::ReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitReference(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ReferenceContext* asn1Parser::reference() {
  ReferenceContext *_localctx = _tracker.createInstance<ReferenceContext>(_ctx, getState());
  enterRule(_localctx, 48, asn1Parser::RuleReference);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    _la = _input->LA(1);
    if (!(_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_listContext ------------------------------------------------------------------

asn1Parser::Assignment_listContext::Assignment_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::AssignmentContext *> asn1Parser::Assignment_listContext::assignment() {
  return getRuleContexts<asn1Parser::AssignmentContext>();
}

asn1Parser::AssignmentContext* asn1Parser::Assignment_listContext::assignment(size_t i) {
  return getRuleContext<asn1Parser::AssignmentContext>(i);
}


size_t asn1Parser::Assignment_listContext::getRuleIndex() const {
  return asn1Parser::RuleAssignment_list;
}

void asn1Parser::Assignment_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_list(this);
}

void asn1Parser::Assignment_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_list(this);
}


antlrcpp::Any asn1Parser::Assignment_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAssignment_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Assignment_listContext* asn1Parser::assignment_list() {
  Assignment_listContext *_localctx = _tracker.createInstance<Assignment_listContext>(_ctx, getState());
  enterRule(_localctx, 50, asn1Parser::RuleAssignment_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(495);
      assignment();
      setState(498); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE

    || _la == asn1Parser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

asn1Parser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Type_assignmentContext* asn1Parser::AssignmentContext::type_assignment() {
  return getRuleContext<asn1Parser::Type_assignmentContext>(0);
}

asn1Parser::Value_assignmentContext* asn1Parser::AssignmentContext::value_assignment() {
  return getRuleContext<asn1Parser::Value_assignmentContext>(0);
}

asn1Parser::Value_set_type_assignmentContext* asn1Parser::AssignmentContext::value_set_type_assignment() {
  return getRuleContext<asn1Parser::Value_set_type_assignmentContext>(0);
}


size_t asn1Parser::AssignmentContext::getRuleIndex() const {
  return asn1Parser::RuleAssignment;
}

void asn1Parser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void asn1Parser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any asn1Parser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::AssignmentContext* asn1Parser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 52, asn1Parser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(500);
      type_assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(501);
      value_assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(502);
      value_set_type_assignment();
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

//----------------- Defined_typeContext ------------------------------------------------------------------

asn1Parser::Defined_typeContext::Defined_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::External_type_referenceContext* asn1Parser::Defined_typeContext::external_type_reference() {
  return getRuleContext<asn1Parser::External_type_referenceContext>(0);
}

tree::TerminalNode* asn1Parser::Defined_typeContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}


size_t asn1Parser::Defined_typeContext::getRuleIndex() const {
  return asn1Parser::RuleDefined_type;
}

void asn1Parser::Defined_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefined_type(this);
}

void asn1Parser::Defined_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefined_type(this);
}


antlrcpp::Any asn1Parser::Defined_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefined_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Defined_typeContext* asn1Parser::defined_type() {
  Defined_typeContext *_localctx = _tracker.createInstance<Defined_typeContext>(_ctx, getState());
  enterRule(_localctx, 54, asn1Parser::RuleDefined_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(507);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(505);
      external_type_reference();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(506);
      match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
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

//----------------- Defined_valueContext ------------------------------------------------------------------

asn1Parser::Defined_valueContext::Defined_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::External_value_referenceContext* asn1Parser::Defined_valueContext::external_value_reference() {
  return getRuleContext<asn1Parser::External_value_referenceContext>(0);
}

tree::TerminalNode* asn1Parser::Defined_valueContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::Defined_valueContext::getRuleIndex() const {
  return asn1Parser::RuleDefined_value;
}

void asn1Parser::Defined_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefined_value(this);
}

void asn1Parser::Defined_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefined_value(this);
}


antlrcpp::Any asn1Parser::Defined_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDefined_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Defined_valueContext* asn1Parser::defined_value() {
  Defined_valueContext *_localctx = _tracker.createInstance<Defined_valueContext>(_ctx, getState());
  enterRule(_localctx, 56, asn1Parser::RuleDefined_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE: {
        enterOuterAlt(_localctx, 1);
        setState(509);
        external_value_reference();
        break;
      }

      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(510);
        match(asn1Parser::IDENTIFIER);
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

//----------------- External_type_referenceContext ------------------------------------------------------------------

asn1Parser::External_type_referenceContext::External_type_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> asn1Parser::External_type_referenceContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getTokens(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
}

tree::TerminalNode* asn1Parser::External_type_referenceContext::TYPE_REFERENCE_OR_MODULE_REFERENCE(size_t i) {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, i);
}

tree::TerminalNode* asn1Parser::External_type_referenceContext::FULL_STOP_TK() {
  return getToken(asn1Parser::FULL_STOP_TK, 0);
}


size_t asn1Parser::External_type_referenceContext::getRuleIndex() const {
  return asn1Parser::RuleExternal_type_reference;
}

void asn1Parser::External_type_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_type_reference(this);
}

void asn1Parser::External_type_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_type_reference(this);
}


antlrcpp::Any asn1Parser::External_type_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExternal_type_reference(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::External_type_referenceContext* asn1Parser::external_type_reference() {
  External_type_referenceContext *_localctx = _tracker.createInstance<External_type_referenceContext>(_ctx, getState());
  enterRule(_localctx, 58, asn1Parser::RuleExternal_type_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(514);
    match(asn1Parser::FULL_STOP_TK);
    setState(515);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- External_value_referenceContext ------------------------------------------------------------------

asn1Parser::External_value_referenceContext::External_value_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::External_value_referenceContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

tree::TerminalNode* asn1Parser::External_value_referenceContext::FULL_STOP_TK() {
  return getToken(asn1Parser::FULL_STOP_TK, 0);
}

tree::TerminalNode* asn1Parser::External_value_referenceContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::External_value_referenceContext::getRuleIndex() const {
  return asn1Parser::RuleExternal_value_reference;
}

void asn1Parser::External_value_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_value_reference(this);
}

void asn1Parser::External_value_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_value_reference(this);
}


antlrcpp::Any asn1Parser::External_value_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExternal_value_reference(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::External_value_referenceContext* asn1Parser::external_value_reference() {
  External_value_referenceContext *_localctx = _tracker.createInstance<External_value_referenceContext>(_ctx, getState());
  enterRule(_localctx, 60, asn1Parser::RuleExternal_value_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(518);
    match(asn1Parser::FULL_STOP_TK);
    setState(519);
    match(asn1Parser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Absolute_referenceContext ------------------------------------------------------------------

asn1Parser::Absolute_referenceContext::Absolute_referenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Absolute_referenceContext::COMMERCIAL_AT_TK() {
  return getToken(asn1Parser::COMMERCIAL_AT_TK, 0);
}

asn1Parser::Module_identifierContext* asn1Parser::Absolute_referenceContext::module_identifier() {
  return getRuleContext<asn1Parser::Module_identifierContext>(0);
}

tree::TerminalNode* asn1Parser::Absolute_referenceContext::FULL_STOP_TK() {
  return getToken(asn1Parser::FULL_STOP_TK, 0);
}

asn1Parser::Item_specContext* asn1Parser::Absolute_referenceContext::item_spec() {
  return getRuleContext<asn1Parser::Item_specContext>(0);
}


size_t asn1Parser::Absolute_referenceContext::getRuleIndex() const {
  return asn1Parser::RuleAbsolute_reference;
}

void asn1Parser::Absolute_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbsolute_reference(this);
}

void asn1Parser::Absolute_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbsolute_reference(this);
}


antlrcpp::Any asn1Parser::Absolute_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAbsolute_reference(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Absolute_referenceContext* asn1Parser::absolute_reference() {
  Absolute_referenceContext *_localctx = _tracker.createInstance<Absolute_referenceContext>(_ctx, getState());
  enterRule(_localctx, 62, asn1Parser::RuleAbsolute_reference);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(521);
    match(asn1Parser::COMMERCIAL_AT_TK);
    setState(522);
    module_identifier();
    setState(523);
    match(asn1Parser::FULL_STOP_TK);
    setState(524);
    item_spec(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Item_specContext ------------------------------------------------------------------

asn1Parser::Item_specContext::Item_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Item_specContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

asn1Parser::Item_specContext* asn1Parser::Item_specContext::item_spec() {
  return getRuleContext<asn1Parser::Item_specContext>(0);
}

tree::TerminalNode* asn1Parser::Item_specContext::FULL_STOP_TK() {
  return getToken(asn1Parser::FULL_STOP_TK, 0);
}

asn1Parser::Component_idContext* asn1Parser::Item_specContext::component_id() {
  return getRuleContext<asn1Parser::Component_idContext>(0);
}


size_t asn1Parser::Item_specContext::getRuleIndex() const {
  return asn1Parser::RuleItem_spec;
}

void asn1Parser::Item_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItem_spec(this);
}

void asn1Parser::Item_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItem_spec(this);
}


antlrcpp::Any asn1Parser::Item_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitItem_spec(this);
  else
    return visitor->visitChildren(this);
}


asn1Parser::Item_specContext* asn1Parser::item_spec() {
   return item_spec(0);
}

asn1Parser::Item_specContext* asn1Parser::item_spec(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  asn1Parser::Item_specContext *_localctx = _tracker.createInstance<Item_specContext>(_ctx, parentState);
  asn1Parser::Item_specContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, asn1Parser::RuleItem_spec, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(527);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    _ctx->stop = _input->LT(-1);
    setState(534);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Item_specContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleItem_spec);
        setState(529);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(530);
        match(asn1Parser::FULL_STOP_TK);
        setState(531);
        component_id(); 
      }
      setState(536);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Component_idContext ------------------------------------------------------------------

asn1Parser::Component_idContext::Component_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Component_idContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Component_idContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Component_idContext::ASTERISK_TK() {
  return getToken(asn1Parser::ASTERISK_TK, 0);
}


size_t asn1Parser::Component_idContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_id;
}

void asn1Parser::Component_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_id(this);
}

void asn1Parser::Component_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_id(this);
}


antlrcpp::Any asn1Parser::Component_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_id(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_idContext* asn1Parser::component_id() {
  Component_idContext *_localctx = _tracker.createInstance<Component_idContext>(_ctx, getState());
  enterRule(_localctx, 66, asn1Parser::RuleComponent_id);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(537);
    _la = _input->LA(1);
    if (!(((((_la - 90) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 90)) & ((1ULL << (asn1Parser::ASTERISK_TK - 90))
      | (1ULL << (asn1Parser::IDENTIFIER - 90))
      | (1ULL << (asn1Parser::NUMBER - 90)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_assignmentContext ------------------------------------------------------------------

asn1Parser::Type_assignmentContext::Type_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Type_assignmentContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

tree::TerminalNode* asn1Parser::Type_assignmentContext::ASSIGNMENT() {
  return getToken(asn1Parser::ASSIGNMENT, 0);
}

asn1Parser::TypeContext* asn1Parser::Type_assignmentContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Type_assignmentContext::getRuleIndex() const {
  return asn1Parser::RuleType_assignment;
}

void asn1Parser::Type_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_assignment(this);
}

void asn1Parser::Type_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_assignment(this);
}


antlrcpp::Any asn1Parser::Type_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitType_assignment(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Type_assignmentContext* asn1Parser::type_assignment() {
  Type_assignmentContext *_localctx = _tracker.createInstance<Type_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 68, asn1Parser::RuleType_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(539);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(540);
    match(asn1Parser::ASSIGNMENT);
    setState(541);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_assignmentContext ------------------------------------------------------------------

asn1Parser::Value_assignmentContext::Value_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Value_assignmentContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

asn1Parser::TypeContext* asn1Parser::Value_assignmentContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

tree::TerminalNode* asn1Parser::Value_assignmentContext::ASSIGNMENT() {
  return getToken(asn1Parser::ASSIGNMENT, 0);
}

asn1Parser::ValueContext* asn1Parser::Value_assignmentContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Value_assignmentContext::getRuleIndex() const {
  return asn1Parser::RuleValue_assignment;
}

void asn1Parser::Value_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_assignment(this);
}

void asn1Parser::Value_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_assignment(this);
}


antlrcpp::Any asn1Parser::Value_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_assignment(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_assignmentContext* asn1Parser::value_assignment() {
  Value_assignmentContext *_localctx = _tracker.createInstance<Value_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 70, asn1Parser::RuleValue_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
    match(asn1Parser::IDENTIFIER);
    setState(544);
    type();
    setState(545);
    match(asn1Parser::ASSIGNMENT);
    setState(546);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_set_type_assignmentContext ------------------------------------------------------------------

asn1Parser::Value_set_type_assignmentContext::Value_set_type_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Value_set_type_assignmentContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}

asn1Parser::TypeContext* asn1Parser::Value_set_type_assignmentContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

tree::TerminalNode* asn1Parser::Value_set_type_assignmentContext::ASSIGNMENT() {
  return getToken(asn1Parser::ASSIGNMENT, 0);
}

asn1Parser::Value_setContext* asn1Parser::Value_set_type_assignmentContext::value_set() {
  return getRuleContext<asn1Parser::Value_setContext>(0);
}


size_t asn1Parser::Value_set_type_assignmentContext::getRuleIndex() const {
  return asn1Parser::RuleValue_set_type_assignment;
}

void asn1Parser::Value_set_type_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_set_type_assignment(this);
}

void asn1Parser::Value_set_type_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_set_type_assignment(this);
}


antlrcpp::Any asn1Parser::Value_set_type_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_set_type_assignment(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_set_type_assignmentContext* asn1Parser::value_set_type_assignment() {
  Value_set_type_assignmentContext *_localctx = _tracker.createInstance<Value_set_type_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 72, asn1Parser::RuleValue_set_type_assignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(548);
    match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
    setState(549);
    type();
    setState(550);
    match(asn1Parser::ASSIGNMENT);
    setState(551);
    value_set();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_setContext ------------------------------------------------------------------

asn1Parser::Value_setContext::Value_setContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Value_setContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Element_set_specsContext* asn1Parser::Value_setContext::element_set_specs() {
  return getRuleContext<asn1Parser::Element_set_specsContext>(0);
}

tree::TerminalNode* asn1Parser::Value_setContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Value_setContext::getRuleIndex() const {
  return asn1Parser::RuleValue_set;
}

void asn1Parser::Value_setContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_set(this);
}

void asn1Parser::Value_setContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_set(this);
}


antlrcpp::Any asn1Parser::Value_setContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_set(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_setContext* asn1Parser::value_set() {
  Value_setContext *_localctx = _tracker.createInstance<Value_setContext>(_ctx, getState());
  enterRule(_localctx, 74, asn1Parser::RuleValue_set);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(554);
    element_set_specs();
    setState(555);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

asn1Parser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Builtin_typeContext* asn1Parser::TypeContext::builtin_type() {
  return getRuleContext<asn1Parser::Builtin_typeContext>(0);
}

asn1Parser::Referenced_typeContext* asn1Parser::TypeContext::referenced_type() {
  return getRuleContext<asn1Parser::Referenced_typeContext>(0);
}

asn1Parser::Constrained_typeContext* asn1Parser::TypeContext::constrained_type() {
  return getRuleContext<asn1Parser::Constrained_typeContext>(0);
}

asn1Parser::Any_typeContext* asn1Parser::TypeContext::any_type() {
  return getRuleContext<asn1Parser::Any_typeContext>(0);
}


size_t asn1Parser::TypeContext::getRuleIndex() const {
  return asn1Parser::RuleType;
}

void asn1Parser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void asn1Parser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any asn1Parser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::TypeContext* asn1Parser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 76, asn1Parser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(561);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(557);
      builtin_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(558);
      referenced_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(559);
      constrained_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(560);
      any_type();
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

//----------------- Builtin_typeContext ------------------------------------------------------------------

asn1Parser::Builtin_typeContext::Builtin_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Bit_string_typeContext* asn1Parser::Builtin_typeContext::bit_string_type() {
  return getRuleContext<asn1Parser::Bit_string_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::BOOLEAN_RW() {
  return getToken(asn1Parser::BOOLEAN_RW, 0);
}

asn1Parser::Character_string_typeContext* asn1Parser::Builtin_typeContext::character_string_type() {
  return getRuleContext<asn1Parser::Character_string_typeContext>(0);
}

asn1Parser::Choice_typeContext* asn1Parser::Builtin_typeContext::choice_type() {
  return getRuleContext<asn1Parser::Choice_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::DATE_RW() {
  return getToken(asn1Parser::DATE_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::DATE_TIME_RW() {
  return getToken(asn1Parser::DATE_TIME_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::DURATION_RW() {
  return getToken(asn1Parser::DURATION_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::EMBEDDED_RW() {
  return getToken(asn1Parser::EMBEDDED_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::PDV_RW() {
  return getToken(asn1Parser::PDV_RW, 0);
}

asn1Parser::Enumerated_typeContext* asn1Parser::Builtin_typeContext::enumerated_type() {
  return getRuleContext<asn1Parser::Enumerated_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::EXTERNAL_RW() {
  return getToken(asn1Parser::EXTERNAL_RW, 0);
}

asn1Parser::Integer_typeContext* asn1Parser::Builtin_typeContext::integer_type() {
  return getRuleContext<asn1Parser::Integer_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::OID_IRI_RW() {
  return getToken(asn1Parser::OID_IRI_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::NULL_RW() {
  return getToken(asn1Parser::NULL_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::OBJECT_RW() {
  return getToken(asn1Parser::OBJECT_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::IDENTIFIER_RW() {
  return getToken(asn1Parser::IDENTIFIER_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::OCTET_RW() {
  return getToken(asn1Parser::OCTET_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::STRING_RW() {
  return getToken(asn1Parser::STRING_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::REAL_RW() {
  return getToken(asn1Parser::REAL_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::RELATIVE_OID_IRI_RW() {
  return getToken(asn1Parser::RELATIVE_OID_IRI_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::RELATIVE_OID_RW() {
  return getToken(asn1Parser::RELATIVE_OID_RW, 0);
}

asn1Parser::Sequence_or_set_typeContext* asn1Parser::Builtin_typeContext::sequence_or_set_type() {
  return getRuleContext<asn1Parser::Sequence_or_set_typeContext>(0);
}

asn1Parser::Sequence_or_set_of_typeContext* asn1Parser::Builtin_typeContext::sequence_or_set_of_type() {
  return getRuleContext<asn1Parser::Sequence_or_set_of_typeContext>(0);
}

asn1Parser::Prefixed_typeContext* asn1Parser::Builtin_typeContext::prefixed_type() {
  return getRuleContext<asn1Parser::Prefixed_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::TIME_RW() {
  return getToken(asn1Parser::TIME_RW, 0);
}

tree::TerminalNode* asn1Parser::Builtin_typeContext::TIME_OF_DAY_RW() {
  return getToken(asn1Parser::TIME_OF_DAY_RW, 0);
}


size_t asn1Parser::Builtin_typeContext::getRuleIndex() const {
  return asn1Parser::RuleBuiltin_type;
}

void asn1Parser::Builtin_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltin_type(this);
}

void asn1Parser::Builtin_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltin_type(this);
}


antlrcpp::Any asn1Parser::Builtin_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitBuiltin_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Builtin_typeContext* asn1Parser::builtin_type() {
  Builtin_typeContext *_localctx = _tracker.createInstance<Builtin_typeContext>(_ctx, getState());
  enterRule(_localctx, 78, asn1Parser::RuleBuiltin_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(589);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(563);
      bit_string_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(564);
      match(asn1Parser::BOOLEAN_RW);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(565);
      character_string_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(566);
      choice_type();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(567);
      match(asn1Parser::DATE_RW);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(568);
      match(asn1Parser::DATE_TIME_RW);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(569);
      match(asn1Parser::DURATION_RW);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(570);
      match(asn1Parser::EMBEDDED_RW);
      setState(571);
      match(asn1Parser::PDV_RW);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(572);
      enumerated_type();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(573);
      match(asn1Parser::EXTERNAL_RW);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(574);
      integer_type();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(575);
      match(asn1Parser::OID_IRI_RW);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(576);
      match(asn1Parser::NULL_RW);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(577);
      match(asn1Parser::OBJECT_RW);
      setState(578);
      match(asn1Parser::IDENTIFIER_RW);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(579);
      match(asn1Parser::OCTET_RW);
      setState(580);
      match(asn1Parser::STRING_RW);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(581);
      match(asn1Parser::REAL_RW);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(582);
      match(asn1Parser::RELATIVE_OID_IRI_RW);
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(583);
      match(asn1Parser::RELATIVE_OID_RW);
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(584);
      sequence_or_set_type();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(585);
      sequence_or_set_of_type();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(586);
      prefixed_type();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(587);
      match(asn1Parser::TIME_RW);
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(588);
      match(asn1Parser::TIME_OF_DAY_RW);
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

//----------------- Referenced_typeContext ------------------------------------------------------------------

asn1Parser::Referenced_typeContext::Referenced_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Defined_typeContext* asn1Parser::Referenced_typeContext::defined_type() {
  return getRuleContext<asn1Parser::Defined_typeContext>(0);
}

asn1Parser::Useful_typeContext* asn1Parser::Referenced_typeContext::useful_type() {
  return getRuleContext<asn1Parser::Useful_typeContext>(0);
}

asn1Parser::Selection_typeContext* asn1Parser::Referenced_typeContext::selection_type() {
  return getRuleContext<asn1Parser::Selection_typeContext>(0);
}


size_t asn1Parser::Referenced_typeContext::getRuleIndex() const {
  return asn1Parser::RuleReferenced_type;
}

void asn1Parser::Referenced_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReferenced_type(this);
}

void asn1Parser::Referenced_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReferenced_type(this);
}


antlrcpp::Any asn1Parser::Referenced_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitReferenced_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Referenced_typeContext* asn1Parser::referenced_type() {
  Referenced_typeContext *_localctx = _tracker.createInstance<Referenced_typeContext>(_ctx, getState());
  enterRule(_localctx, 80, asn1Parser::RuleReferenced_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(594);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE: {
        enterOuterAlt(_localctx, 1);
        setState(591);
        defined_type();
        break;
      }

      case asn1Parser::T__13:
      case asn1Parser::T__14:
      case asn1Parser::T__15: {
        enterOuterAlt(_localctx, 2);
        setState(592);
        useful_type();
        break;
      }

      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(593);
        selection_type();
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

//----------------- Named_typeContext ------------------------------------------------------------------

asn1Parser::Named_typeContext::Named_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Named_typeContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

asn1Parser::TypeContext* asn1Parser::Named_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Named_typeContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_type;
}

void asn1Parser::Named_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_type(this);
}

void asn1Parser::Named_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_type(this);
}


antlrcpp::Any asn1Parser::Named_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_typeContext* asn1Parser::named_type() {
  Named_typeContext *_localctx = _tracker.createInstance<Named_typeContext>(_ctx, getState());
  enterRule(_localctx, 82, asn1Parser::RuleNamed_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(596);
    match(asn1Parser::IDENTIFIER);
    setState(597);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_typeContext ------------------------------------------------------------------

asn1Parser::Any_typeContext::Any_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Any_typeContext::ANY_RW() {
  return getToken(asn1Parser::ANY_RW, 0);
}

tree::TerminalNode* asn1Parser::Any_typeContext::DEFINED_RW() {
  return getToken(asn1Parser::DEFINED_RW, 0);
}

tree::TerminalNode* asn1Parser::Any_typeContext::BY_RW() {
  return getToken(asn1Parser::BY_RW, 0);
}

tree::TerminalNode* asn1Parser::Any_typeContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::Any_typeContext::getRuleIndex() const {
  return asn1Parser::RuleAny_type;
}

void asn1Parser::Any_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_type(this);
}

void asn1Parser::Any_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_type(this);
}


antlrcpp::Any asn1Parser::Any_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAny_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Any_typeContext* asn1Parser::any_type() {
  Any_typeContext *_localctx = _tracker.createInstance<Any_typeContext>(_ctx, getState());
  enterRule(_localctx, 84, asn1Parser::RuleAny_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(599);
      match(asn1Parser::ANY_RW);
      setState(600);
      match(asn1Parser::DEFINED_RW);
      setState(601);
      match(asn1Parser::BY_RW);
      setState(602);
      match(asn1Parser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(603);
      match(asn1Parser::ANY_RW);
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

//----------------- ValueContext ------------------------------------------------------------------

asn1Parser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Builtin_valueContext* asn1Parser::ValueContext::builtin_value() {
  return getRuleContext<asn1Parser::Builtin_valueContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::ValueContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::ValueContext::getRuleIndex() const {
  return asn1Parser::RuleValue;
}

void asn1Parser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void asn1Parser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


antlrcpp::Any asn1Parser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ValueContext* asn1Parser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 86, asn1Parser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(608);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(606);
      builtin_value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(607);
      defined_value();
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

//----------------- Builtin_valueContext ------------------------------------------------------------------

asn1Parser::Builtin_valueContext::Builtin_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Bit_string_valueContext* asn1Parser::Builtin_valueContext::bit_string_value() {
  return getRuleContext<asn1Parser::Bit_string_valueContext>(0);
}

asn1Parser::Boolean_valueContext* asn1Parser::Builtin_valueContext::boolean_value() {
  return getRuleContext<asn1Parser::Boolean_valueContext>(0);
}

asn1Parser::Character_string_valueContext* asn1Parser::Builtin_valueContext::character_string_value() {
  return getRuleContext<asn1Parser::Character_string_valueContext>(0);
}

asn1Parser::Choice_valueContext* asn1Parser::Builtin_valueContext::choice_value() {
  return getRuleContext<asn1Parser::Choice_valueContext>(0);
}

asn1Parser::Embedded_pdv_valueContext* asn1Parser::Builtin_valueContext::embedded_pdv_value() {
  return getRuleContext<asn1Parser::Embedded_pdv_valueContext>(0);
}

asn1Parser::Enumerated_valueContext* asn1Parser::Builtin_valueContext::enumerated_value() {
  return getRuleContext<asn1Parser::Enumerated_valueContext>(0);
}

asn1Parser::Integer_valueContext* asn1Parser::Builtin_valueContext::integer_value() {
  return getRuleContext<asn1Parser::Integer_valueContext>(0);
}

asn1Parser::Iri_valueContext* asn1Parser::Builtin_valueContext::iri_value() {
  return getRuleContext<asn1Parser::Iri_valueContext>(0);
}

tree::TerminalNode* asn1Parser::Builtin_valueContext::NULL_RW() {
  return getToken(asn1Parser::NULL_RW, 0);
}

asn1Parser::Object_identifier_valueContext* asn1Parser::Builtin_valueContext::object_identifier_value() {
  return getRuleContext<asn1Parser::Object_identifier_valueContext>(0);
}

asn1Parser::Octet_string_valueContext* asn1Parser::Builtin_valueContext::octet_string_value() {
  return getRuleContext<asn1Parser::Octet_string_valueContext>(0);
}

asn1Parser::Real_valueContext* asn1Parser::Builtin_valueContext::real_value() {
  return getRuleContext<asn1Parser::Real_valueContext>(0);
}

asn1Parser::Relative_iri_valueContext* asn1Parser::Builtin_valueContext::relative_iri_value() {
  return getRuleContext<asn1Parser::Relative_iri_valueContext>(0);
}

asn1Parser::Relative_oid_valueContext* asn1Parser::Builtin_valueContext::relative_oid_value() {
  return getRuleContext<asn1Parser::Relative_oid_valueContext>(0);
}

asn1Parser::Sequence_valueContext* asn1Parser::Builtin_valueContext::sequence_value() {
  return getRuleContext<asn1Parser::Sequence_valueContext>(0);
}

asn1Parser::Sequence_of_valueContext* asn1Parser::Builtin_valueContext::sequence_of_value() {
  return getRuleContext<asn1Parser::Sequence_of_valueContext>(0);
}

asn1Parser::Set_valueContext* asn1Parser::Builtin_valueContext::set_value() {
  return getRuleContext<asn1Parser::Set_valueContext>(0);
}

asn1Parser::Set_of_valueContext* asn1Parser::Builtin_valueContext::set_of_value() {
  return getRuleContext<asn1Parser::Set_of_valueContext>(0);
}

asn1Parser::Time_valueContext* asn1Parser::Builtin_valueContext::time_value() {
  return getRuleContext<asn1Parser::Time_valueContext>(0);
}


size_t asn1Parser::Builtin_valueContext::getRuleIndex() const {
  return asn1Parser::RuleBuiltin_value;
}

void asn1Parser::Builtin_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltin_value(this);
}

void asn1Parser::Builtin_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltin_value(this);
}


antlrcpp::Any asn1Parser::Builtin_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitBuiltin_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Builtin_valueContext* asn1Parser::builtin_value() {
  Builtin_valueContext *_localctx = _tracker.createInstance<Builtin_valueContext>(_ctx, getState());
  enterRule(_localctx, 88, asn1Parser::RuleBuiltin_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(610);
      bit_string_value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(611);
      boolean_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(612);
      character_string_value();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(613);
      choice_value();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(614);
      embedded_pdv_value();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(615);
      enumerated_value();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(616);
      integer_value();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(617);
      iri_value();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(618);
      match(asn1Parser::NULL_RW);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(619);
      object_identifier_value();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(620);
      octet_string_value();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(621);
      real_value();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(622);
      relative_iri_value();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(623);
      relative_oid_value();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(624);
      sequence_value();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(625);
      sequence_of_value();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(626);
      set_value();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(627);
      set_of_value();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(628);
      time_value();
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

//----------------- Named_valueContext ------------------------------------------------------------------

asn1Parser::Named_valueContext::Named_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Named_valueContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

asn1Parser::ValueContext* asn1Parser::Named_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Named_valueContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_value;
}

void asn1Parser::Named_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_value(this);
}

void asn1Parser::Named_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_value(this);
}


antlrcpp::Any asn1Parser::Named_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_valueContext* asn1Parser::named_value() {
  Named_valueContext *_localctx = _tracker.createInstance<Named_valueContext>(_ctx, getState());
  enterRule(_localctx, 90, asn1Parser::RuleNamed_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    match(asn1Parser::IDENTIFIER);
    setState(632);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_valueContext ------------------------------------------------------------------

asn1Parser::Boolean_valueContext::Boolean_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Boolean_valueContext::TRUE_RW() {
  return getToken(asn1Parser::TRUE_RW, 0);
}

tree::TerminalNode* asn1Parser::Boolean_valueContext::FALSE_RW() {
  return getToken(asn1Parser::FALSE_RW, 0);
}


size_t asn1Parser::Boolean_valueContext::getRuleIndex() const {
  return asn1Parser::RuleBoolean_value;
}

void asn1Parser::Boolean_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean_value(this);
}

void asn1Parser::Boolean_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean_value(this);
}


antlrcpp::Any asn1Parser::Boolean_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitBoolean_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Boolean_valueContext* asn1Parser::boolean_value() {
  Boolean_valueContext *_localctx = _tracker.createInstance<Boolean_valueContext>(_ctx, getState());
  enterRule(_localctx, 92, asn1Parser::RuleBoolean_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    _la = _input->LA(1);
    if (!(_la == asn1Parser::FALSE_RW

    || _la == asn1Parser::TRUE_RW)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_typeContext ------------------------------------------------------------------

asn1Parser::Integer_typeContext::Integer_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Integer_typeContext::INTEGER_RW() {
  return getToken(asn1Parser::INTEGER_RW, 0);
}

tree::TerminalNode* asn1Parser::Integer_typeContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Named_number_listContext* asn1Parser::Integer_typeContext::named_number_list() {
  return getRuleContext<asn1Parser::Named_number_listContext>(0);
}

tree::TerminalNode* asn1Parser::Integer_typeContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Integer_typeContext::getRuleIndex() const {
  return asn1Parser::RuleInteger_type;
}

void asn1Parser::Integer_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_type(this);
}

void asn1Parser::Integer_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_type(this);
}


antlrcpp::Any asn1Parser::Integer_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitInteger_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Integer_typeContext* asn1Parser::integer_type() {
  Integer_typeContext *_localctx = _tracker.createInstance<Integer_typeContext>(_ctx, getState());
  enterRule(_localctx, 94, asn1Parser::RuleInteger_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(642);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(636);
      match(asn1Parser::INTEGER_RW);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(637);
      match(asn1Parser::INTEGER_RW);
      setState(638);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(639);
      named_number_list();
      setState(640);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
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

//----------------- Named_number_listContext ------------------------------------------------------------------

asn1Parser::Named_number_listContext::Named_number_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Named_numberContext *> asn1Parser::Named_number_listContext::named_number() {
  return getRuleContexts<asn1Parser::Named_numberContext>();
}

asn1Parser::Named_numberContext* asn1Parser::Named_number_listContext::named_number(size_t i) {
  return getRuleContext<asn1Parser::Named_numberContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Named_number_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Named_number_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Named_number_listContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_number_list;
}

void asn1Parser::Named_number_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_number_list(this);
}

void asn1Parser::Named_number_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_number_list(this);
}


antlrcpp::Any asn1Parser::Named_number_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_number_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_number_listContext* asn1Parser::named_number_list() {
  Named_number_listContext *_localctx = _tracker.createInstance<Named_number_listContext>(_ctx, getState());
  enterRule(_localctx, 96, asn1Parser::RuleNamed_number_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    named_number();
    setState(649);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(645);
      match(asn1Parser::COMMA_TK);
      setState(646);
      named_number();
      setState(651);
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

//----------------- Named_numberContext ------------------------------------------------------------------

asn1Parser::Named_numberContext::Named_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Named_numberContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Named_numberContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

asn1Parser::Signed_numberContext* asn1Parser::Named_numberContext::signed_number() {
  return getRuleContext<asn1Parser::Signed_numberContext>(0);
}

tree::TerminalNode* asn1Parser::Named_numberContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}

asn1Parser::Defined_valueContext* asn1Parser::Named_numberContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}

tree::TerminalNode* asn1Parser::Named_numberContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}


size_t asn1Parser::Named_numberContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_number;
}

void asn1Parser::Named_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_number(this);
}

void asn1Parser::Named_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_number(this);
}


antlrcpp::Any asn1Parser::Named_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_number(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_numberContext* asn1Parser::named_number() {
  Named_numberContext *_localctx = _tracker.createInstance<Named_numberContext>(_ctx, getState());
  enterRule(_localctx, 98, asn1Parser::RuleNamed_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(672);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(652);
      match(asn1Parser::IDENTIFIER);
      setState(653);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(654);
      signed_number();
      setState(655);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(657);
      match(asn1Parser::IDENTIFIER);
      setState(658);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(659);
      defined_value();
      setState(660);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(662);
      match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
      setState(663);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(664);
      signed_number();
      setState(665);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(667);
      match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
      setState(668);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(669);
      defined_value();
      setState(670);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
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

//----------------- Signed_numberContext ------------------------------------------------------------------

asn1Parser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Signed_numberContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Signed_numberContext::HYPHEN_TK() {
  return getToken(asn1Parser::HYPHEN_TK, 0);
}


size_t asn1Parser::Signed_numberContext::getRuleIndex() const {
  return asn1Parser::RuleSigned_number;
}

void asn1Parser::Signed_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigned_number(this);
}

void asn1Parser::Signed_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigned_number(this);
}


antlrcpp::Any asn1Parser::Signed_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSigned_number(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Signed_numberContext* asn1Parser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 100, asn1Parser::RuleSigned_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(677);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(674);
        match(asn1Parser::NUMBER);
        break;
      }

      case asn1Parser::HYPHEN_TK: {
        enterOuterAlt(_localctx, 2);
        setState(675);
        match(asn1Parser::HYPHEN_TK);
        setState(676);
        match(asn1Parser::NUMBER);
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

//----------------- Integer_valueContext ------------------------------------------------------------------

asn1Parser::Integer_valueContext::Integer_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Signed_numberContext* asn1Parser::Integer_valueContext::signed_number() {
  return getRuleContext<asn1Parser::Signed_numberContext>(0);
}

tree::TerminalNode* asn1Parser::Integer_valueContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::Integer_valueContext::getRuleIndex() const {
  return asn1Parser::RuleInteger_value;
}

void asn1Parser::Integer_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_value(this);
}

void asn1Parser::Integer_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_value(this);
}


antlrcpp::Any asn1Parser::Integer_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitInteger_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Integer_valueContext* asn1Parser::integer_value() {
  Integer_valueContext *_localctx = _tracker.createInstance<Integer_valueContext>(_ctx, getState());
  enterRule(_localctx, 102, asn1Parser::RuleInteger_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(681);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(679);
        signed_number();
        break;
      }

      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(680);
        match(asn1Parser::IDENTIFIER);
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

//----------------- Enumerated_typeContext ------------------------------------------------------------------

asn1Parser::Enumerated_typeContext::Enumerated_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Enumerated_typeContext::ENUMERATED_RW() {
  return getToken(asn1Parser::ENUMERATED_RW, 0);
}

tree::TerminalNode* asn1Parser::Enumerated_typeContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::EnumerationsContext* asn1Parser::Enumerated_typeContext::enumerations() {
  return getRuleContext<asn1Parser::EnumerationsContext>(0);
}

tree::TerminalNode* asn1Parser::Enumerated_typeContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Enumerated_typeContext::getRuleIndex() const {
  return asn1Parser::RuleEnumerated_type;
}

void asn1Parser::Enumerated_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerated_type(this);
}

void asn1Parser::Enumerated_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerated_type(this);
}


antlrcpp::Any asn1Parser::Enumerated_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEnumerated_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Enumerated_typeContext* asn1Parser::enumerated_type() {
  Enumerated_typeContext *_localctx = _tracker.createInstance<Enumerated_typeContext>(_ctx, getState());
  enterRule(_localctx, 104, asn1Parser::RuleEnumerated_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(683);
    match(asn1Parser::ENUMERATED_RW);
    setState(684);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(685);
    enumerations();
    setState(686);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationsContext ------------------------------------------------------------------

asn1Parser::EnumerationsContext::EnumerationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Root_enumerationContext* asn1Parser::EnumerationsContext::root_enumeration() {
  return getRuleContext<asn1Parser::Root_enumerationContext>(0);
}

std::vector<tree::TerminalNode *> asn1Parser::EnumerationsContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::EnumerationsContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}

tree::TerminalNode* asn1Parser::EnumerationsContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}

asn1Parser::Exception_specContext* asn1Parser::EnumerationsContext::exception_spec() {
  return getRuleContext<asn1Parser::Exception_specContext>(0);
}

asn1Parser::Additional_enumerationContext* asn1Parser::EnumerationsContext::additional_enumeration() {
  return getRuleContext<asn1Parser::Additional_enumerationContext>(0);
}


size_t asn1Parser::EnumerationsContext::getRuleIndex() const {
  return asn1Parser::RuleEnumerations;
}

void asn1Parser::EnumerationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerations(this);
}

void asn1Parser::EnumerationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerations(this);
}


antlrcpp::Any asn1Parser::EnumerationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEnumerations(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::EnumerationsContext* asn1Parser::enumerations() {
  EnumerationsContext *_localctx = _tracker.createInstance<EnumerationsContext>(_ctx, getState());
  enterRule(_localctx, 106, asn1Parser::RuleEnumerations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(704);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(688);
      root_enumeration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(689);
      root_enumeration();
      setState(690);
      match(asn1Parser::COMMA_TK);
      setState(691);
      match(asn1Parser::ELLIPSIS);
      setState(693);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == asn1Parser::EXCLAMATION_MARK_TK) {
        setState(692);
        exception_spec();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(695);
      root_enumeration();
      setState(696);
      match(asn1Parser::COMMA_TK);
      setState(697);
      match(asn1Parser::ELLIPSIS);
      setState(699);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == asn1Parser::EXCLAMATION_MARK_TK) {
        setState(698);
        exception_spec();
      }
      setState(701);
      match(asn1Parser::COMMA_TK);
      setState(702);
      additional_enumeration();
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

//----------------- Root_enumerationContext ------------------------------------------------------------------

asn1Parser::Root_enumerationContext::Root_enumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::EnumerationContext* asn1Parser::Root_enumerationContext::enumeration() {
  return getRuleContext<asn1Parser::EnumerationContext>(0);
}


size_t asn1Parser::Root_enumerationContext::getRuleIndex() const {
  return asn1Parser::RuleRoot_enumeration;
}

void asn1Parser::Root_enumerationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot_enumeration(this);
}

void asn1Parser::Root_enumerationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot_enumeration(this);
}


antlrcpp::Any asn1Parser::Root_enumerationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRoot_enumeration(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Root_enumerationContext* asn1Parser::root_enumeration() {
  Root_enumerationContext *_localctx = _tracker.createInstance<Root_enumerationContext>(_ctx, getState());
  enterRule(_localctx, 108, asn1Parser::RuleRoot_enumeration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    enumeration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Additional_enumerationContext ------------------------------------------------------------------

asn1Parser::Additional_enumerationContext::Additional_enumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::EnumerationContext* asn1Parser::Additional_enumerationContext::enumeration() {
  return getRuleContext<asn1Parser::EnumerationContext>(0);
}


size_t asn1Parser::Additional_enumerationContext::getRuleIndex() const {
  return asn1Parser::RuleAdditional_enumeration;
}

void asn1Parser::Additional_enumerationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditional_enumeration(this);
}

void asn1Parser::Additional_enumerationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditional_enumeration(this);
}


antlrcpp::Any asn1Parser::Additional_enumerationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAdditional_enumeration(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Additional_enumerationContext* asn1Parser::additional_enumeration() {
  Additional_enumerationContext *_localctx = _tracker.createInstance<Additional_enumerationContext>(_ctx, getState());
  enterRule(_localctx, 110, asn1Parser::RuleAdditional_enumeration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(708);
    enumeration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationContext ------------------------------------------------------------------

asn1Parser::EnumerationContext::EnumerationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Enumeration_itemContext *> asn1Parser::EnumerationContext::enumeration_item() {
  return getRuleContexts<asn1Parser::Enumeration_itemContext>();
}

asn1Parser::Enumeration_itemContext* asn1Parser::EnumerationContext::enumeration_item(size_t i) {
  return getRuleContext<asn1Parser::Enumeration_itemContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::EnumerationContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::EnumerationContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::EnumerationContext::getRuleIndex() const {
  return asn1Parser::RuleEnumeration;
}

void asn1Parser::EnumerationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeration(this);
}

void asn1Parser::EnumerationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeration(this);
}


antlrcpp::Any asn1Parser::EnumerationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEnumeration(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::EnumerationContext* asn1Parser::enumeration() {
  EnumerationContext *_localctx = _tracker.createInstance<EnumerationContext>(_ctx, getState());
  enterRule(_localctx, 112, asn1Parser::RuleEnumeration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(710);
    enumeration_item();
    setState(715);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(711);
        match(asn1Parser::COMMA_TK);
        setState(712);
        enumeration_item(); 
      }
      setState(717);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enumeration_itemContext ------------------------------------------------------------------

asn1Parser::Enumeration_itemContext::Enumeration_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Enumeration_itemContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

asn1Parser::Named_numberContext* asn1Parser::Enumeration_itemContext::named_number() {
  return getRuleContext<asn1Parser::Named_numberContext>(0);
}


size_t asn1Parser::Enumeration_itemContext::getRuleIndex() const {
  return asn1Parser::RuleEnumeration_item;
}

void asn1Parser::Enumeration_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumeration_item(this);
}

void asn1Parser::Enumeration_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumeration_item(this);
}


antlrcpp::Any asn1Parser::Enumeration_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEnumeration_item(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Enumeration_itemContext* asn1Parser::enumeration_item() {
  Enumeration_itemContext *_localctx = _tracker.createInstance<Enumeration_itemContext>(_ctx, getState());
  enterRule(_localctx, 114, asn1Parser::RuleEnumeration_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(720);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(718);
      match(asn1Parser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(719);
      named_number();
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

//----------------- Enumerated_valueContext ------------------------------------------------------------------

asn1Parser::Enumerated_valueContext::Enumerated_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Enumerated_valueContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::Enumerated_valueContext::getRuleIndex() const {
  return asn1Parser::RuleEnumerated_value;
}

void asn1Parser::Enumerated_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumerated_value(this);
}

void asn1Parser::Enumerated_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumerated_value(this);
}


antlrcpp::Any asn1Parser::Enumerated_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEnumerated_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Enumerated_valueContext* asn1Parser::enumerated_value() {
  Enumerated_valueContext *_localctx = _tracker.createInstance<Enumerated_valueContext>(_ctx, getState());
  enterRule(_localctx, 116, asn1Parser::RuleEnumerated_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    match(asn1Parser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Real_valueContext ------------------------------------------------------------------

asn1Parser::Real_valueContext::Real_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Real_valueContext::REAL_NUMBER() {
  return getToken(asn1Parser::REAL_NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Real_valueContext::HYPHEN_TK() {
  return getToken(asn1Parser::HYPHEN_TK, 0);
}

asn1Parser::Sequence_valueContext* asn1Parser::Real_valueContext::sequence_value() {
  return getRuleContext<asn1Parser::Sequence_valueContext>(0);
}

tree::TerminalNode* asn1Parser::Real_valueContext::PLUS_INFINITY_RW() {
  return getToken(asn1Parser::PLUS_INFINITY_RW, 0);
}

tree::TerminalNode* asn1Parser::Real_valueContext::MINUS_INFINITY_RW() {
  return getToken(asn1Parser::MINUS_INFINITY_RW, 0);
}

tree::TerminalNode* asn1Parser::Real_valueContext::NOT_A_NUMBER_RW() {
  return getToken(asn1Parser::NOT_A_NUMBER_RW, 0);
}


size_t asn1Parser::Real_valueContext::getRuleIndex() const {
  return asn1Parser::RuleReal_value;
}

void asn1Parser::Real_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_value(this);
}

void asn1Parser::Real_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_value(this);
}


antlrcpp::Any asn1Parser::Real_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitReal_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Real_valueContext* asn1Parser::real_value() {
  Real_valueContext *_localctx = _tracker.createInstance<Real_valueContext>(_ctx, getState());
  enterRule(_localctx, 118, asn1Parser::RuleReal_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(731);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::REAL_NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(724);
        match(asn1Parser::REAL_NUMBER);
        break;
      }

      case asn1Parser::HYPHEN_TK: {
        enterOuterAlt(_localctx, 2);
        setState(725);
        match(asn1Parser::HYPHEN_TK);
        setState(726);
        match(asn1Parser::REAL_NUMBER);
        break;
      }

      case asn1Parser::LEFT_CURLY_BRACKET_TK: {
        enterOuterAlt(_localctx, 3);
        setState(727);
        sequence_value();
        break;
      }

      case asn1Parser::PLUS_INFINITY_RW: {
        enterOuterAlt(_localctx, 4);
        setState(728);
        match(asn1Parser::PLUS_INFINITY_RW);
        break;
      }

      case asn1Parser::MINUS_INFINITY_RW: {
        enterOuterAlt(_localctx, 5);
        setState(729);
        match(asn1Parser::MINUS_INFINITY_RW);
        break;
      }

      case asn1Parser::NOT_A_NUMBER_RW: {
        enterOuterAlt(_localctx, 6);
        setState(730);
        match(asn1Parser::NOT_A_NUMBER_RW);
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

//----------------- Bit_string_typeContext ------------------------------------------------------------------

asn1Parser::Bit_string_typeContext::Bit_string_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Bit_string_typeContext::BIT_RW() {
  return getToken(asn1Parser::BIT_RW, 0);
}

tree::TerminalNode* asn1Parser::Bit_string_typeContext::STRING_RW() {
  return getToken(asn1Parser::STRING_RW, 0);
}

tree::TerminalNode* asn1Parser::Bit_string_typeContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Named_bit_listContext* asn1Parser::Bit_string_typeContext::named_bit_list() {
  return getRuleContext<asn1Parser::Named_bit_listContext>(0);
}

tree::TerminalNode* asn1Parser::Bit_string_typeContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Bit_string_typeContext::getRuleIndex() const {
  return asn1Parser::RuleBit_string_type;
}

void asn1Parser::Bit_string_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBit_string_type(this);
}

void asn1Parser::Bit_string_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBit_string_type(this);
}


antlrcpp::Any asn1Parser::Bit_string_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitBit_string_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Bit_string_typeContext* asn1Parser::bit_string_type() {
  Bit_string_typeContext *_localctx = _tracker.createInstance<Bit_string_typeContext>(_ctx, getState());
  enterRule(_localctx, 120, asn1Parser::RuleBit_string_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(741);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(733);
      match(asn1Parser::BIT_RW);
      setState(734);
      match(asn1Parser::STRING_RW);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(735);
      match(asn1Parser::BIT_RW);
      setState(736);
      match(asn1Parser::STRING_RW);
      setState(737);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(738);
      named_bit_list();
      setState(739);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
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

//----------------- Named_bit_listContext ------------------------------------------------------------------

asn1Parser::Named_bit_listContext::Named_bit_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Named_bitContext *> asn1Parser::Named_bit_listContext::named_bit() {
  return getRuleContexts<asn1Parser::Named_bitContext>();
}

asn1Parser::Named_bitContext* asn1Parser::Named_bit_listContext::named_bit(size_t i) {
  return getRuleContext<asn1Parser::Named_bitContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Named_bit_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Named_bit_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Named_bit_listContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_bit_list;
}

void asn1Parser::Named_bit_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_bit_list(this);
}

void asn1Parser::Named_bit_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_bit_list(this);
}


antlrcpp::Any asn1Parser::Named_bit_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_bit_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_bit_listContext* asn1Parser::named_bit_list() {
  Named_bit_listContext *_localctx = _tracker.createInstance<Named_bit_listContext>(_ctx, getState());
  enterRule(_localctx, 122, asn1Parser::RuleNamed_bit_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(743);
    named_bit();
    setState(748);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(744);
      match(asn1Parser::COMMA_TK);
      setState(745);
      named_bit();
      setState(750);
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

//----------------- Named_bitContext ------------------------------------------------------------------

asn1Parser::Named_bitContext::Named_bitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Named_bitContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Named_bitContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

tree::TerminalNode* asn1Parser::Named_bitContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Named_bitContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}

asn1Parser::Defined_valueContext* asn1Parser::Named_bitContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Named_bitContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_bit;
}

void asn1Parser::Named_bitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_bit(this);
}

void asn1Parser::Named_bitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_bit(this);
}


antlrcpp::Any asn1Parser::Named_bitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_bit(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_bitContext* asn1Parser::named_bit() {
  Named_bitContext *_localctx = _tracker.createInstance<Named_bitContext>(_ctx, getState());
  enterRule(_localctx, 124, asn1Parser::RuleNamed_bit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(760);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(751);
      match(asn1Parser::IDENTIFIER);
      setState(752);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(753);
      match(asn1Parser::NUMBER);
      setState(754);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(755);
      match(asn1Parser::IDENTIFIER);
      setState(756);
      match(asn1Parser::LEFT_PARENTHESIS_TK);
      setState(757);
      defined_value();
      setState(758);
      match(asn1Parser::RIGHT_PARENTHESIS_TK);
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

//----------------- Bit_string_valueContext ------------------------------------------------------------------

asn1Parser::Bit_string_valueContext::Bit_string_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Bit_string_valueContext::BSTRING() {
  return getToken(asn1Parser::BSTRING, 0);
}

tree::TerminalNode* asn1Parser::Bit_string_valueContext::HSTRING() {
  return getToken(asn1Parser::HSTRING, 0);
}

tree::TerminalNode* asn1Parser::Bit_string_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Identifier_listContext* asn1Parser::Bit_string_valueContext::identifier_list() {
  return getRuleContext<asn1Parser::Identifier_listContext>(0);
}

tree::TerminalNode* asn1Parser::Bit_string_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Bit_string_valueContext::CONTAINING_RW() {
  return getToken(asn1Parser::CONTAINING_RW, 0);
}

asn1Parser::ValueContext* asn1Parser::Bit_string_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Bit_string_valueContext::getRuleIndex() const {
  return asn1Parser::RuleBit_string_value;
}

void asn1Parser::Bit_string_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBit_string_value(this);
}

void asn1Parser::Bit_string_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBit_string_value(this);
}


antlrcpp::Any asn1Parser::Bit_string_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitBit_string_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Bit_string_valueContext* asn1Parser::bit_string_value() {
  Bit_string_valueContext *_localctx = _tracker.createInstance<Bit_string_valueContext>(_ctx, getState());
  enterRule(_localctx, 126, asn1Parser::RuleBit_string_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(772);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(762);
      match(asn1Parser::BSTRING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(763);
      match(asn1Parser::HSTRING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(764);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(765);
      identifier_list();
      setState(766);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(768);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(769);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(770);
      match(asn1Parser::CONTAINING_RW);
      setState(771);
      value();
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

//----------------- Identifier_listContext ------------------------------------------------------------------

asn1Parser::Identifier_listContext::Identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> asn1Parser::Identifier_listContext::IDENTIFIER() {
  return getTokens(asn1Parser::IDENTIFIER);
}

tree::TerminalNode* asn1Parser::Identifier_listContext::IDENTIFIER(size_t i) {
  return getToken(asn1Parser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> asn1Parser::Identifier_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Identifier_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Identifier_listContext::getRuleIndex() const {
  return asn1Parser::RuleIdentifier_list;
}

void asn1Parser::Identifier_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier_list(this);
}

void asn1Parser::Identifier_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier_list(this);
}


antlrcpp::Any asn1Parser::Identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIdentifier_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Identifier_listContext* asn1Parser::identifier_list() {
  Identifier_listContext *_localctx = _tracker.createInstance<Identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 128, asn1Parser::RuleIdentifier_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(774);
    match(asn1Parser::IDENTIFIER);
    setState(779);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(775);
      match(asn1Parser::COMMA_TK);
      setState(776);
      match(asn1Parser::IDENTIFIER);
      setState(781);
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

//----------------- Octet_string_valueContext ------------------------------------------------------------------

asn1Parser::Octet_string_valueContext::Octet_string_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Octet_string_valueContext::BSTRING() {
  return getToken(asn1Parser::BSTRING, 0);
}

tree::TerminalNode* asn1Parser::Octet_string_valueContext::HSTRING() {
  return getToken(asn1Parser::HSTRING, 0);
}

tree::TerminalNode* asn1Parser::Octet_string_valueContext::CONTAINING_RW() {
  return getToken(asn1Parser::CONTAINING_RW, 0);
}

asn1Parser::ValueContext* asn1Parser::Octet_string_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Octet_string_valueContext::getRuleIndex() const {
  return asn1Parser::RuleOctet_string_value;
}

void asn1Parser::Octet_string_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOctet_string_value(this);
}

void asn1Parser::Octet_string_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOctet_string_value(this);
}


antlrcpp::Any asn1Parser::Octet_string_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitOctet_string_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Octet_string_valueContext* asn1Parser::octet_string_value() {
  Octet_string_valueContext *_localctx = _tracker.createInstance<Octet_string_valueContext>(_ctx, getState());
  enterRule(_localctx, 130, asn1Parser::RuleOctet_string_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(786);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::BSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(782);
        match(asn1Parser::BSTRING);
        break;
      }

      case asn1Parser::HSTRING: {
        enterOuterAlt(_localctx, 2);
        setState(783);
        match(asn1Parser::HSTRING);
        break;
      }

      case asn1Parser::CONTAINING_RW: {
        enterOuterAlt(_localctx, 3);
        setState(784);
        match(asn1Parser::CONTAINING_RW);
        setState(785);
        value();
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

//----------------- Sequence_or_set_typeContext ------------------------------------------------------------------

asn1Parser::Sequence_or_set_typeContext::Sequence_or_set_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Sequence_or_set_typeContext::SEQUENCE_RW() {
  return getToken(asn1Parser::SEQUENCE_RW, 0);
}

tree::TerminalNode* asn1Parser::Sequence_or_set_typeContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Sequence_or_set_typeContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Component_type_listsContext* asn1Parser::Sequence_or_set_typeContext::component_type_lists() {
  return getRuleContext<asn1Parser::Component_type_listsContext>(0);
}


size_t asn1Parser::Sequence_or_set_typeContext::getRuleIndex() const {
  return asn1Parser::RuleSequence_or_set_type;
}

void asn1Parser::Sequence_or_set_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence_or_set_type(this);
}

void asn1Parser::Sequence_or_set_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence_or_set_type(this);
}


antlrcpp::Any asn1Parser::Sequence_or_set_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSequence_or_set_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Sequence_or_set_typeContext* asn1Parser::sequence_or_set_type() {
  Sequence_or_set_typeContext *_localctx = _tracker.createInstance<Sequence_or_set_typeContext>(_ctx, getState());
  enterRule(_localctx, 132, asn1Parser::RuleSequence_or_set_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(796);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(788);
      match(asn1Parser::SEQUENCE_RW);
      setState(789);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(790);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(791);
      match(asn1Parser::SEQUENCE_RW);
      setState(792);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(793);
      component_type_lists();
      setState(794);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
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

//----------------- Sequence_or_set_of_typeContext ------------------------------------------------------------------

asn1Parser::Sequence_or_set_of_typeContext::Sequence_or_set_of_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Sequence_or_set_of_typeContext::SEQUENCE_RW() {
  return getToken(asn1Parser::SEQUENCE_RW, 0);
}

tree::TerminalNode* asn1Parser::Sequence_or_set_of_typeContext::OF_RW() {
  return getToken(asn1Parser::OF_RW, 0);
}

asn1Parser::TypeContext* asn1Parser::Sequence_or_set_of_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

asn1Parser::Named_typeContext* asn1Parser::Sequence_or_set_of_typeContext::named_type() {
  return getRuleContext<asn1Parser::Named_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Sequence_or_set_of_typeContext::SET_RW() {
  return getToken(asn1Parser::SET_RW, 0);
}


size_t asn1Parser::Sequence_or_set_of_typeContext::getRuleIndex() const {
  return asn1Parser::RuleSequence_or_set_of_type;
}

void asn1Parser::Sequence_or_set_of_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence_or_set_of_type(this);
}

void asn1Parser::Sequence_or_set_of_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence_or_set_of_type(this);
}


antlrcpp::Any asn1Parser::Sequence_or_set_of_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSequence_or_set_of_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Sequence_or_set_of_typeContext* asn1Parser::sequence_or_set_of_type() {
  Sequence_or_set_of_typeContext *_localctx = _tracker.createInstance<Sequence_or_set_of_typeContext>(_ctx, getState());
  enterRule(_localctx, 134, asn1Parser::RuleSequence_or_set_of_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(810);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(798);
      match(asn1Parser::SEQUENCE_RW);
      setState(799);
      match(asn1Parser::OF_RW);
      setState(800);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(801);
      match(asn1Parser::SEQUENCE_RW);
      setState(802);
      match(asn1Parser::OF_RW);
      setState(803);
      named_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(804);
      match(asn1Parser::SET_RW);
      setState(805);
      match(asn1Parser::OF_RW);
      setState(806);
      type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(807);
      match(asn1Parser::SET_RW);
      setState(808);
      match(asn1Parser::OF_RW);
      setState(809);
      named_type();
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

//----------------- Extension_and_exceptionContext ------------------------------------------------------------------

asn1Parser::Extension_and_exceptionContext::Extension_and_exceptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_and_exceptionContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}

asn1Parser::Exception_specContext* asn1Parser::Extension_and_exceptionContext::exception_spec() {
  return getRuleContext<asn1Parser::Exception_specContext>(0);
}


size_t asn1Parser::Extension_and_exceptionContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_and_exception;
}

void asn1Parser::Extension_and_exceptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_and_exception(this);
}

void asn1Parser::Extension_and_exceptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_and_exception(this);
}


antlrcpp::Any asn1Parser::Extension_and_exceptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_and_exception(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_and_exceptionContext* asn1Parser::extension_and_exception() {
  Extension_and_exceptionContext *_localctx = _tracker.createInstance<Extension_and_exceptionContext>(_ctx, getState());
  enterRule(_localctx, 136, asn1Parser::RuleExtension_and_exception);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(812);
    match(asn1Parser::ELLIPSIS);
    setState(814);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::EXCLAMATION_MARK_TK) {
      setState(813);
      exception_spec();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_extension_markerContext ------------------------------------------------------------------

asn1Parser::Optional_extension_markerContext::Optional_extension_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Optional_extension_markerContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

tree::TerminalNode* asn1Parser::Optional_extension_markerContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}


size_t asn1Parser::Optional_extension_markerContext::getRuleIndex() const {
  return asn1Parser::RuleOptional_extension_marker;
}

void asn1Parser::Optional_extension_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOptional_extension_marker(this);
}

void asn1Parser::Optional_extension_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOptional_extension_marker(this);
}


antlrcpp::Any asn1Parser::Optional_extension_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitOptional_extension_marker(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Optional_extension_markerContext* asn1Parser::optional_extension_marker() {
  Optional_extension_markerContext *_localctx = _tracker.createInstance<Optional_extension_markerContext>(_ctx, getState());
  enterRule(_localctx, 138, asn1Parser::RuleOptional_extension_marker);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(816);
    match(asn1Parser::COMMA_TK);
    setState(817);
    match(asn1Parser::ELLIPSIS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_type_listsContext ------------------------------------------------------------------

asn1Parser::Component_type_listsContext::Component_type_listsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Component_type_listContext *> asn1Parser::Component_type_listsContext::component_type_list() {
  return getRuleContexts<asn1Parser::Component_type_listContext>();
}

asn1Parser::Component_type_listContext* asn1Parser::Component_type_listsContext::component_type_list(size_t i) {
  return getRuleContext<asn1Parser::Component_type_listContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Component_type_listsContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Component_type_listsContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}

asn1Parser::Extension_and_exceptionContext* asn1Parser::Component_type_listsContext::extension_and_exception() {
  return getRuleContext<asn1Parser::Extension_and_exceptionContext>(0);
}

asn1Parser::Optional_extension_markerContext* asn1Parser::Component_type_listsContext::optional_extension_marker() {
  return getRuleContext<asn1Parser::Optional_extension_markerContext>(0);
}

asn1Parser::Extension_additionsContext* asn1Parser::Component_type_listsContext::extension_additions() {
  return getRuleContext<asn1Parser::Extension_additionsContext>(0);
}

asn1Parser::Extension_end_markerContext* asn1Parser::Component_type_listsContext::extension_end_marker() {
  return getRuleContext<asn1Parser::Extension_end_markerContext>(0);
}


size_t asn1Parser::Component_type_listsContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_type_lists;
}

void asn1Parser::Component_type_listsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_type_lists(this);
}

void asn1Parser::Component_type_listsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_type_lists(this);
}


antlrcpp::Any asn1Parser::Component_type_listsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_type_lists(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_type_listsContext* asn1Parser::component_type_lists() {
  Component_type_listsContext *_localctx = _tracker.createInstance<Component_type_listsContext>(_ctx, getState());
  enterRule(_localctx, 140, asn1Parser::RuleComponent_type_lists);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(853);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(819);
      component_type_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(820);
      component_type_list();
      setState(821);
      match(asn1Parser::COMMA_TK);
      setState(822);
      extension_and_exception();
      setState(824);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
      case 1: {
        setState(823);
        extension_additions();
        break;
      }

      }
      setState(826);
      optional_extension_marker();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(828);
      component_type_list();
      setState(829);
      match(asn1Parser::COMMA_TK);
      setState(830);
      extension_and_exception();
      setState(832);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
      case 1: {
        setState(831);
        extension_additions();
        break;
      }

      }
      setState(834);
      extension_end_marker();
      setState(835);
      match(asn1Parser::COMMA_TK);
      setState(836);
      component_type_list();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(838);
      extension_and_exception();
      setState(840);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
      case 1: {
        setState(839);
        extension_additions();
        break;
      }

      }
      setState(842);
      extension_end_marker();
      setState(843);
      match(asn1Parser::COMMA_TK);
      setState(844);
      component_type_list();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(846);
      extension_and_exception();
      setState(848);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
      case 1: {
        setState(847);
        extension_additions();
        break;
      }

      }
      setState(851);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == asn1Parser::COMMA_TK) {
        setState(850);
        optional_extension_marker();
      }
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

//----------------- Extension_end_markerContext ------------------------------------------------------------------

asn1Parser::Extension_end_markerContext::Extension_end_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_end_markerContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

tree::TerminalNode* asn1Parser::Extension_end_markerContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}


size_t asn1Parser::Extension_end_markerContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_end_marker;
}

void asn1Parser::Extension_end_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_end_marker(this);
}

void asn1Parser::Extension_end_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_end_marker(this);
}


antlrcpp::Any asn1Parser::Extension_end_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_end_marker(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_end_markerContext* asn1Parser::extension_end_marker() {
  Extension_end_markerContext *_localctx = _tracker.createInstance<Extension_end_markerContext>(_ctx, getState());
  enterRule(_localctx, 142, asn1Parser::RuleExtension_end_marker);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(855);
    match(asn1Parser::COMMA_TK);
    setState(856);
    match(asn1Parser::ELLIPSIS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_additionsContext ------------------------------------------------------------------

asn1Parser::Extension_additionsContext::Extension_additionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_additionsContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Extension_addition_listContext* asn1Parser::Extension_additionsContext::extension_addition_list() {
  return getRuleContext<asn1Parser::Extension_addition_listContext>(0);
}


size_t asn1Parser::Extension_additionsContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_additions;
}

void asn1Parser::Extension_additionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_additions(this);
}

void asn1Parser::Extension_additionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_additions(this);
}


antlrcpp::Any asn1Parser::Extension_additionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_additions(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_additionsContext* asn1Parser::extension_additions() {
  Extension_additionsContext *_localctx = _tracker.createInstance<Extension_additionsContext>(_ctx, getState());
  enterRule(_localctx, 144, asn1Parser::RuleExtension_additions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(858);
    match(asn1Parser::COMMA_TK);
    setState(859);
    extension_addition_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_addition_listContext ------------------------------------------------------------------

asn1Parser::Extension_addition_listContext::Extension_addition_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Extension_additionContext *> asn1Parser::Extension_addition_listContext::extension_addition() {
  return getRuleContexts<asn1Parser::Extension_additionContext>();
}

asn1Parser::Extension_additionContext* asn1Parser::Extension_addition_listContext::extension_addition(size_t i) {
  return getRuleContext<asn1Parser::Extension_additionContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Extension_addition_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Extension_addition_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Extension_addition_listContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_list;
}

void asn1Parser::Extension_addition_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_list(this);
}

void asn1Parser::Extension_addition_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_list(this);
}


antlrcpp::Any asn1Parser::Extension_addition_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_listContext* asn1Parser::extension_addition_list() {
  Extension_addition_listContext *_localctx = _tracker.createInstance<Extension_addition_listContext>(_ctx, getState());
  enterRule(_localctx, 146, asn1Parser::RuleExtension_addition_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(861);
    extension_addition();
    setState(866);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(862);
        match(asn1Parser::COMMA_TK);
        setState(863);
        extension_addition(); 
      }
      setState(868);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_additionContext ------------------------------------------------------------------

asn1Parser::Extension_additionContext::Extension_additionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Component_typeContext* asn1Parser::Extension_additionContext::component_type() {
  return getRuleContext<asn1Parser::Component_typeContext>(0);
}

asn1Parser::Extension_addition_groupContext* asn1Parser::Extension_additionContext::extension_addition_group() {
  return getRuleContext<asn1Parser::Extension_addition_groupContext>(0);
}


size_t asn1Parser::Extension_additionContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition;
}

void asn1Parser::Extension_additionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition(this);
}

void asn1Parser::Extension_additionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition(this);
}


antlrcpp::Any asn1Parser::Extension_additionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_additionContext* asn1Parser::extension_addition() {
  Extension_additionContext *_localctx = _tracker.createInstance<Extension_additionContext>(_ctx, getState());
  enterRule(_localctx, 148, asn1Parser::RuleExtension_addition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(871);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::COMPONENTS_RW:
      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(869);
        component_type();
        break;
      }

      case asn1Parser::LEFT_VERSION_BRACKETS: {
        enterOuterAlt(_localctx, 2);
        setState(870);
        extension_addition_group();
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

//----------------- Extension_addition_groupContext ------------------------------------------------------------------

asn1Parser::Extension_addition_groupContext::Extension_addition_groupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_addition_groupContext::LEFT_VERSION_BRACKETS() {
  return getToken(asn1Parser::LEFT_VERSION_BRACKETS, 0);
}

asn1Parser::Component_type_listContext* asn1Parser::Extension_addition_groupContext::component_type_list() {
  return getRuleContext<asn1Parser::Component_type_listContext>(0);
}

tree::TerminalNode* asn1Parser::Extension_addition_groupContext::RIGHT_VERSION_BRACKETS() {
  return getToken(asn1Parser::RIGHT_VERSION_BRACKETS, 0);
}

asn1Parser::Version_numberContext* asn1Parser::Extension_addition_groupContext::version_number() {
  return getRuleContext<asn1Parser::Version_numberContext>(0);
}


size_t asn1Parser::Extension_addition_groupContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_group;
}

void asn1Parser::Extension_addition_groupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_group(this);
}

void asn1Parser::Extension_addition_groupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_group(this);
}


antlrcpp::Any asn1Parser::Extension_addition_groupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_group(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_groupContext* asn1Parser::extension_addition_group() {
  Extension_addition_groupContext *_localctx = _tracker.createInstance<Extension_addition_groupContext>(_ctx, getState());
  enterRule(_localctx, 150, asn1Parser::RuleExtension_addition_group);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(873);
    match(asn1Parser::LEFT_VERSION_BRACKETS);
    setState(875);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::NUMBER) {
      setState(874);
      version_number();
    }
    setState(877);
    component_type_list();
    setState(878);
    match(asn1Parser::RIGHT_VERSION_BRACKETS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Version_numberContext ------------------------------------------------------------------

asn1Parser::Version_numberContext::Version_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Version_numberContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Version_numberContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}


size_t asn1Parser::Version_numberContext::getRuleIndex() const {
  return asn1Parser::RuleVersion_number;
}

void asn1Parser::Version_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion_number(this);
}

void asn1Parser::Version_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion_number(this);
}


antlrcpp::Any asn1Parser::Version_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitVersion_number(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Version_numberContext* asn1Parser::version_number() {
  Version_numberContext *_localctx = _tracker.createInstance<Version_numberContext>(_ctx, getState());
  enterRule(_localctx, 152, asn1Parser::RuleVersion_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(880);
    match(asn1Parser::NUMBER);
    setState(881);
    match(asn1Parser::COLON_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_type_listContext ------------------------------------------------------------------

asn1Parser::Component_type_listContext::Component_type_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Component_typeContext *> asn1Parser::Component_type_listContext::component_type() {
  return getRuleContexts<asn1Parser::Component_typeContext>();
}

asn1Parser::Component_typeContext* asn1Parser::Component_type_listContext::component_type(size_t i) {
  return getRuleContext<asn1Parser::Component_typeContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Component_type_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Component_type_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Component_type_listContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_type_list;
}

void asn1Parser::Component_type_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_type_list(this);
}

void asn1Parser::Component_type_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_type_list(this);
}


antlrcpp::Any asn1Parser::Component_type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_type_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_type_listContext* asn1Parser::component_type_list() {
  Component_type_listContext *_localctx = _tracker.createInstance<Component_type_listContext>(_ctx, getState());
  enterRule(_localctx, 154, asn1Parser::RuleComponent_type_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(883);
    component_type();
    setState(888);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(884);
        match(asn1Parser::COMMA_TK);
        setState(885);
        component_type(); 
      }
      setState(890);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_typeContext ------------------------------------------------------------------

asn1Parser::Component_typeContext::Component_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Named_typeContext* asn1Parser::Component_typeContext::named_type() {
  return getRuleContext<asn1Parser::Named_typeContext>(0);
}

tree::TerminalNode* asn1Parser::Component_typeContext::OPTIONAL_RW() {
  return getToken(asn1Parser::OPTIONAL_RW, 0);
}

tree::TerminalNode* asn1Parser::Component_typeContext::DEFAULT_RW() {
  return getToken(asn1Parser::DEFAULT_RW, 0);
}

asn1Parser::ValueContext* asn1Parser::Component_typeContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}

tree::TerminalNode* asn1Parser::Component_typeContext::COMPONENTS_RW() {
  return getToken(asn1Parser::COMPONENTS_RW, 0);
}

tree::TerminalNode* asn1Parser::Component_typeContext::OF_RW() {
  return getToken(asn1Parser::OF_RW, 0);
}

asn1Parser::TypeContext* asn1Parser::Component_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Component_typeContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_type;
}

void asn1Parser::Component_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_type(this);
}

void asn1Parser::Component_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_type(this);
}


antlrcpp::Any asn1Parser::Component_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_typeContext* asn1Parser::component_type() {
  Component_typeContext *_localctx = _tracker.createInstance<Component_typeContext>(_ctx, getState());
  enterRule(_localctx, 156, asn1Parser::RuleComponent_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(902);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(891);
      named_type();
      setState(892);
      match(asn1Parser::OPTIONAL_RW);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(894);
      named_type();
      setState(895);
      match(asn1Parser::DEFAULT_RW);
      setState(896);
      value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(898);
      named_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(899);
      match(asn1Parser::COMPONENTS_RW);
      setState(900);
      match(asn1Parser::OF_RW);
      setState(901);
      type();
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

//----------------- Sequence_valueContext ------------------------------------------------------------------

asn1Parser::Sequence_valueContext::Sequence_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Sequence_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Sequence_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Component_value_listContext* asn1Parser::Sequence_valueContext::component_value_list() {
  return getRuleContext<asn1Parser::Component_value_listContext>(0);
}


size_t asn1Parser::Sequence_valueContext::getRuleIndex() const {
  return asn1Parser::RuleSequence_value;
}

void asn1Parser::Sequence_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence_value(this);
}

void asn1Parser::Sequence_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence_value(this);
}


antlrcpp::Any asn1Parser::Sequence_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSequence_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Sequence_valueContext* asn1Parser::sequence_value() {
  Sequence_valueContext *_localctx = _tracker.createInstance<Sequence_valueContext>(_ctx, getState());
  enterRule(_localctx, 158, asn1Parser::RuleSequence_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(904);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(906);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::IDENTIFIER) {
      setState(905);
      component_value_list();
    }
    setState(908);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_value_listContext ------------------------------------------------------------------

asn1Parser::Component_value_listContext::Component_value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Named_valueContext *> asn1Parser::Component_value_listContext::named_value() {
  return getRuleContexts<asn1Parser::Named_valueContext>();
}

asn1Parser::Named_valueContext* asn1Parser::Component_value_listContext::named_value(size_t i) {
  return getRuleContext<asn1Parser::Named_valueContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Component_value_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Component_value_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Component_value_listContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_value_list;
}

void asn1Parser::Component_value_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_value_list(this);
}

void asn1Parser::Component_value_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_value_list(this);
}


antlrcpp::Any asn1Parser::Component_value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_value_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_value_listContext* asn1Parser::component_value_list() {
  Component_value_listContext *_localctx = _tracker.createInstance<Component_value_listContext>(_ctx, getState());
  enterRule(_localctx, 160, asn1Parser::RuleComponent_value_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(910);
    named_value();
    setState(915);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(911);
      match(asn1Parser::COMMA_TK);
      setState(912);
      named_value();
      setState(917);
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

//----------------- Sequence_of_valueContext ------------------------------------------------------------------

asn1Parser::Sequence_of_valueContext::Sequence_of_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Sequence_of_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Value_listContext* asn1Parser::Sequence_of_valueContext::value_list() {
  return getRuleContext<asn1Parser::Value_listContext>(0);
}

tree::TerminalNode* asn1Parser::Sequence_of_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Named_value_listContext* asn1Parser::Sequence_of_valueContext::named_value_list() {
  return getRuleContext<asn1Parser::Named_value_listContext>(0);
}


size_t asn1Parser::Sequence_of_valueContext::getRuleIndex() const {
  return asn1Parser::RuleSequence_of_value;
}

void asn1Parser::Sequence_of_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequence_of_value(this);
}

void asn1Parser::Sequence_of_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequence_of_value(this);
}


antlrcpp::Any asn1Parser::Sequence_of_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSequence_of_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Sequence_of_valueContext* asn1Parser::sequence_of_value() {
  Sequence_of_valueContext *_localctx = _tracker.createInstance<Sequence_of_valueContext>(_ctx, getState());
  enterRule(_localctx, 162, asn1Parser::RuleSequence_of_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(928);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(918);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(919);
      value_list();
      setState(920);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(922);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(923);
      named_value_list();
      setState(924);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(926);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(927);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
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

//----------------- Value_listContext ------------------------------------------------------------------

asn1Parser::Value_listContext::Value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::ValueContext *> asn1Parser::Value_listContext::value() {
  return getRuleContexts<asn1Parser::ValueContext>();
}

asn1Parser::ValueContext* asn1Parser::Value_listContext::value(size_t i) {
  return getRuleContext<asn1Parser::ValueContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Value_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Value_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Value_listContext::getRuleIndex() const {
  return asn1Parser::RuleValue_list;
}

void asn1Parser::Value_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_list(this);
}

void asn1Parser::Value_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_list(this);
}


antlrcpp::Any asn1Parser::Value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_listContext* asn1Parser::value_list() {
  Value_listContext *_localctx = _tracker.createInstance<Value_listContext>(_ctx, getState());
  enterRule(_localctx, 164, asn1Parser::RuleValue_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(930);
    value();
    setState(935);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(931);
      match(asn1Parser::COMMA_TK);
      setState(932);
      value();
      setState(937);
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

//----------------- Named_value_listContext ------------------------------------------------------------------

asn1Parser::Named_value_listContext::Named_value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Named_valueContext *> asn1Parser::Named_value_listContext::named_value() {
  return getRuleContexts<asn1Parser::Named_valueContext>();
}

asn1Parser::Named_valueContext* asn1Parser::Named_value_listContext::named_value(size_t i) {
  return getRuleContext<asn1Parser::Named_valueContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Named_value_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Named_value_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Named_value_listContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_value_list;
}

void asn1Parser::Named_value_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_value_list(this);
}

void asn1Parser::Named_value_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_value_list(this);
}


antlrcpp::Any asn1Parser::Named_value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_value_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_value_listContext* asn1Parser::named_value_list() {
  Named_value_listContext *_localctx = _tracker.createInstance<Named_value_listContext>(_ctx, getState());
  enterRule(_localctx, 166, asn1Parser::RuleNamed_value_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(938);
    named_value();
    setState(943);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(939);
      match(asn1Parser::COMMA_TK);
      setState(940);
      named_value();
      setState(945);
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

//----------------- Set_valueContext ------------------------------------------------------------------

asn1Parser::Set_valueContext::Set_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Set_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Set_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Component_value_listContext* asn1Parser::Set_valueContext::component_value_list() {
  return getRuleContext<asn1Parser::Component_value_listContext>(0);
}


size_t asn1Parser::Set_valueContext::getRuleIndex() const {
  return asn1Parser::RuleSet_value;
}

void asn1Parser::Set_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_value(this);
}

void asn1Parser::Set_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_value(this);
}


antlrcpp::Any asn1Parser::Set_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSet_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Set_valueContext* asn1Parser::set_value() {
  Set_valueContext *_localctx = _tracker.createInstance<Set_valueContext>(_ctx, getState());
  enterRule(_localctx, 168, asn1Parser::RuleSet_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(946);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(948);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::IDENTIFIER) {
      setState(947);
      component_value_list();
    }
    setState(950);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_of_valueContext ------------------------------------------------------------------

asn1Parser::Set_of_valueContext::Set_of_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Set_of_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Value_listContext* asn1Parser::Set_of_valueContext::value_list() {
  return getRuleContext<asn1Parser::Value_listContext>(0);
}

tree::TerminalNode* asn1Parser::Set_of_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Named_value_listContext* asn1Parser::Set_of_valueContext::named_value_list() {
  return getRuleContext<asn1Parser::Named_value_listContext>(0);
}


size_t asn1Parser::Set_of_valueContext::getRuleIndex() const {
  return asn1Parser::RuleSet_of_value;
}

void asn1Parser::Set_of_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_of_value(this);
}

void asn1Parser::Set_of_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_of_value(this);
}


antlrcpp::Any asn1Parser::Set_of_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSet_of_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Set_of_valueContext* asn1Parser::set_of_value() {
  Set_of_valueContext *_localctx = _tracker.createInstance<Set_of_valueContext>(_ctx, getState());
  enterRule(_localctx, 170, asn1Parser::RuleSet_of_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(962);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(952);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(953);
      value_list();
      setState(954);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(956);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(957);
      named_value_list();
      setState(958);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(960);
      match(asn1Parser::LEFT_CURLY_BRACKET_TK);
      setState(961);
      match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
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

//----------------- Choice_typeContext ------------------------------------------------------------------

asn1Parser::Choice_typeContext::Choice_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Choice_typeContext::CHOICE_RW() {
  return getToken(asn1Parser::CHOICE_RW, 0);
}

tree::TerminalNode* asn1Parser::Choice_typeContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Alternative_type_listsContext* asn1Parser::Choice_typeContext::alternative_type_lists() {
  return getRuleContext<asn1Parser::Alternative_type_listsContext>(0);
}

tree::TerminalNode* asn1Parser::Choice_typeContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Choice_typeContext::getRuleIndex() const {
  return asn1Parser::RuleChoice_type;
}

void asn1Parser::Choice_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChoice_type(this);
}

void asn1Parser::Choice_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChoice_type(this);
}


antlrcpp::Any asn1Parser::Choice_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitChoice_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Choice_typeContext* asn1Parser::choice_type() {
  Choice_typeContext *_localctx = _tracker.createInstance<Choice_typeContext>(_ctx, getState());
  enterRule(_localctx, 172, asn1Parser::RuleChoice_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(964);
    match(asn1Parser::CHOICE_RW);
    setState(965);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(966);
    alternative_type_lists();
    setState(967);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alternative_type_listsContext ------------------------------------------------------------------

asn1Parser::Alternative_type_listsContext::Alternative_type_listsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Root_alternative_type_listContext* asn1Parser::Alternative_type_listsContext::root_alternative_type_list() {
  return getRuleContext<asn1Parser::Root_alternative_type_listContext>(0);
}

tree::TerminalNode* asn1Parser::Alternative_type_listsContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Extension_and_exceptionContext* asn1Parser::Alternative_type_listsContext::extension_and_exception() {
  return getRuleContext<asn1Parser::Extension_and_exceptionContext>(0);
}

asn1Parser::Optional_extension_markerContext* asn1Parser::Alternative_type_listsContext::optional_extension_marker() {
  return getRuleContext<asn1Parser::Optional_extension_markerContext>(0);
}

asn1Parser::Extension_addition_alternativesContext* asn1Parser::Alternative_type_listsContext::extension_addition_alternatives() {
  return getRuleContext<asn1Parser::Extension_addition_alternativesContext>(0);
}


size_t asn1Parser::Alternative_type_listsContext::getRuleIndex() const {
  return asn1Parser::RuleAlternative_type_lists;
}

void asn1Parser::Alternative_type_listsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlternative_type_lists(this);
}

void asn1Parser::Alternative_type_listsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlternative_type_lists(this);
}


antlrcpp::Any asn1Parser::Alternative_type_listsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAlternative_type_lists(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Alternative_type_listsContext* asn1Parser::alternative_type_lists() {
  Alternative_type_listsContext *_localctx = _tracker.createInstance<Alternative_type_listsContext>(_ctx, getState());
  enterRule(_localctx, 174, asn1Parser::RuleAlternative_type_lists);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(978);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(969);
      root_alternative_type_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(970);
      root_alternative_type_list();
      setState(971);
      match(asn1Parser::COMMA_TK);
      setState(972);
      extension_and_exception();
      setState(974);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
      case 1: {
        setState(973);
        extension_addition_alternatives();
        break;
      }

      }
      setState(976);
      optional_extension_marker();
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

//----------------- Root_alternative_type_listContext ------------------------------------------------------------------

asn1Parser::Root_alternative_type_listContext::Root_alternative_type_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Alternative_type_listContext* asn1Parser::Root_alternative_type_listContext::alternative_type_list() {
  return getRuleContext<asn1Parser::Alternative_type_listContext>(0);
}


size_t asn1Parser::Root_alternative_type_listContext::getRuleIndex() const {
  return asn1Parser::RuleRoot_alternative_type_list;
}

void asn1Parser::Root_alternative_type_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot_alternative_type_list(this);
}

void asn1Parser::Root_alternative_type_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot_alternative_type_list(this);
}


antlrcpp::Any asn1Parser::Root_alternative_type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRoot_alternative_type_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Root_alternative_type_listContext* asn1Parser::root_alternative_type_list() {
  Root_alternative_type_listContext *_localctx = _tracker.createInstance<Root_alternative_type_listContext>(_ctx, getState());
  enterRule(_localctx, 176, asn1Parser::RuleRoot_alternative_type_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(980);
    alternative_type_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_addition_alternativesContext ------------------------------------------------------------------

asn1Parser::Extension_addition_alternativesContext::Extension_addition_alternativesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_addition_alternativesContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Extension_addition_alternatives_listContext* asn1Parser::Extension_addition_alternativesContext::extension_addition_alternatives_list() {
  return getRuleContext<asn1Parser::Extension_addition_alternatives_listContext>(0);
}


size_t asn1Parser::Extension_addition_alternativesContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_alternatives;
}

void asn1Parser::Extension_addition_alternativesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_alternatives(this);
}

void asn1Parser::Extension_addition_alternativesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_alternatives(this);
}


antlrcpp::Any asn1Parser::Extension_addition_alternativesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_alternatives(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_alternativesContext* asn1Parser::extension_addition_alternatives() {
  Extension_addition_alternativesContext *_localctx = _tracker.createInstance<Extension_addition_alternativesContext>(_ctx, getState());
  enterRule(_localctx, 178, asn1Parser::RuleExtension_addition_alternatives);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(982);
    match(asn1Parser::COMMA_TK);
    setState(983);
    extension_addition_alternatives_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_addition_alternatives_listContext ------------------------------------------------------------------

asn1Parser::Extension_addition_alternatives_listContext::Extension_addition_alternatives_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Extension_addition_alternativeContext *> asn1Parser::Extension_addition_alternatives_listContext::extension_addition_alternative() {
  return getRuleContexts<asn1Parser::Extension_addition_alternativeContext>();
}

asn1Parser::Extension_addition_alternativeContext* asn1Parser::Extension_addition_alternatives_listContext::extension_addition_alternative(size_t i) {
  return getRuleContext<asn1Parser::Extension_addition_alternativeContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Extension_addition_alternatives_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Extension_addition_alternatives_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Extension_addition_alternatives_listContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_alternatives_list;
}

void asn1Parser::Extension_addition_alternatives_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_alternatives_list(this);
}

void asn1Parser::Extension_addition_alternatives_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_alternatives_list(this);
}


antlrcpp::Any asn1Parser::Extension_addition_alternatives_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_alternatives_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_alternatives_listContext* asn1Parser::extension_addition_alternatives_list() {
  Extension_addition_alternatives_listContext *_localctx = _tracker.createInstance<Extension_addition_alternatives_listContext>(_ctx, getState());
  enterRule(_localctx, 180, asn1Parser::RuleExtension_addition_alternatives_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(985);
    extension_addition_alternative();
    setState(990);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(986);
        match(asn1Parser::COMMA_TK);
        setState(987);
        extension_addition_alternative(); 
      }
      setState(992);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Extension_addition_alternativeContext ------------------------------------------------------------------

asn1Parser::Extension_addition_alternativeContext::Extension_addition_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Extension_addition_alternatives_groupContext* asn1Parser::Extension_addition_alternativeContext::extension_addition_alternatives_group() {
  return getRuleContext<asn1Parser::Extension_addition_alternatives_groupContext>(0);
}

asn1Parser::Named_typeContext* asn1Parser::Extension_addition_alternativeContext::named_type() {
  return getRuleContext<asn1Parser::Named_typeContext>(0);
}


size_t asn1Parser::Extension_addition_alternativeContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_alternative;
}

void asn1Parser::Extension_addition_alternativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_alternative(this);
}

void asn1Parser::Extension_addition_alternativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_alternative(this);
}


antlrcpp::Any asn1Parser::Extension_addition_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_alternative(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_alternativeContext* asn1Parser::extension_addition_alternative() {
  Extension_addition_alternativeContext *_localctx = _tracker.createInstance<Extension_addition_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 182, asn1Parser::RuleExtension_addition_alternative);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(995);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::LEFT_VERSION_BRACKETS: {
        enterOuterAlt(_localctx, 1);
        setState(993);
        extension_addition_alternatives_group();
        break;
      }

      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(994);
        named_type();
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

//----------------- Extension_addition_alternatives_groupContext ------------------------------------------------------------------

asn1Parser::Extension_addition_alternatives_groupContext::Extension_addition_alternatives_groupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Extension_addition_alternatives_groupContext::LEFT_VERSION_BRACKETS() {
  return getToken(asn1Parser::LEFT_VERSION_BRACKETS, 0);
}

asn1Parser::Version_numberContext* asn1Parser::Extension_addition_alternatives_groupContext::version_number() {
  return getRuleContext<asn1Parser::Version_numberContext>(0);
}

asn1Parser::Alternative_type_listContext* asn1Parser::Extension_addition_alternatives_groupContext::alternative_type_list() {
  return getRuleContext<asn1Parser::Alternative_type_listContext>(0);
}

tree::TerminalNode* asn1Parser::Extension_addition_alternatives_groupContext::RIGHT_VERSION_BRACKETS() {
  return getToken(asn1Parser::RIGHT_VERSION_BRACKETS, 0);
}


size_t asn1Parser::Extension_addition_alternatives_groupContext::getRuleIndex() const {
  return asn1Parser::RuleExtension_addition_alternatives_group;
}

void asn1Parser::Extension_addition_alternatives_groupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtension_addition_alternatives_group(this);
}

void asn1Parser::Extension_addition_alternatives_groupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtension_addition_alternatives_group(this);
}


antlrcpp::Any asn1Parser::Extension_addition_alternatives_groupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExtension_addition_alternatives_group(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Extension_addition_alternatives_groupContext* asn1Parser::extension_addition_alternatives_group() {
  Extension_addition_alternatives_groupContext *_localctx = _tracker.createInstance<Extension_addition_alternatives_groupContext>(_ctx, getState());
  enterRule(_localctx, 184, asn1Parser::RuleExtension_addition_alternatives_group);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(997);
    match(asn1Parser::LEFT_VERSION_BRACKETS);
    setState(998);
    version_number();
    setState(999);
    alternative_type_list();
    setState(1000);
    match(asn1Parser::RIGHT_VERSION_BRACKETS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alternative_type_listContext ------------------------------------------------------------------

asn1Parser::Alternative_type_listContext::Alternative_type_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Named_typeContext *> asn1Parser::Alternative_type_listContext::named_type() {
  return getRuleContexts<asn1Parser::Named_typeContext>();
}

asn1Parser::Named_typeContext* asn1Parser::Alternative_type_listContext::named_type(size_t i) {
  return getRuleContext<asn1Parser::Named_typeContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Alternative_type_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Alternative_type_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Alternative_type_listContext::getRuleIndex() const {
  return asn1Parser::RuleAlternative_type_list;
}

void asn1Parser::Alternative_type_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlternative_type_list(this);
}

void asn1Parser::Alternative_type_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlternative_type_list(this);
}


antlrcpp::Any asn1Parser::Alternative_type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAlternative_type_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Alternative_type_listContext* asn1Parser::alternative_type_list() {
  Alternative_type_listContext *_localctx = _tracker.createInstance<Alternative_type_listContext>(_ctx, getState());
  enterRule(_localctx, 186, asn1Parser::RuleAlternative_type_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1002);
    named_type();
    setState(1007);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1003);
        match(asn1Parser::COMMA_TK);
        setState(1004);
        named_type(); 
      }
      setState(1009);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Choice_valueContext ------------------------------------------------------------------

asn1Parser::Choice_valueContext::Choice_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Choice_valueContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Choice_valueContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}

asn1Parser::ValueContext* asn1Parser::Choice_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Choice_valueContext::getRuleIndex() const {
  return asn1Parser::RuleChoice_value;
}

void asn1Parser::Choice_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChoice_value(this);
}

void asn1Parser::Choice_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChoice_value(this);
}


antlrcpp::Any asn1Parser::Choice_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitChoice_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Choice_valueContext* asn1Parser::choice_value() {
  Choice_valueContext *_localctx = _tracker.createInstance<Choice_valueContext>(_ctx, getState());
  enterRule(_localctx, 188, asn1Parser::RuleChoice_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1010);
    match(asn1Parser::IDENTIFIER);
    setState(1011);
    match(asn1Parser::COLON_TK);
    setState(1012);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selection_typeContext ------------------------------------------------------------------

asn1Parser::Selection_typeContext::Selection_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Selection_typeContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Selection_typeContext::LESS_THAN_SIGN_TK() {
  return getToken(asn1Parser::LESS_THAN_SIGN_TK, 0);
}

asn1Parser::TypeContext* asn1Parser::Selection_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Selection_typeContext::getRuleIndex() const {
  return asn1Parser::RuleSelection_type;
}

void asn1Parser::Selection_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelection_type(this);
}

void asn1Parser::Selection_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelection_type(this);
}


antlrcpp::Any asn1Parser::Selection_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSelection_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Selection_typeContext* asn1Parser::selection_type() {
  Selection_typeContext *_localctx = _tracker.createInstance<Selection_typeContext>(_ctx, getState());
  enterRule(_localctx, 190, asn1Parser::RuleSelection_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1014);
    match(asn1Parser::IDENTIFIER);
    setState(1015);
    match(asn1Parser::LESS_THAN_SIGN_TK);
    setState(1016);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Prefixed_typeContext ------------------------------------------------------------------

asn1Parser::Prefixed_typeContext::Prefixed_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Tagged_typeContext* asn1Parser::Prefixed_typeContext::tagged_type() {
  return getRuleContext<asn1Parser::Tagged_typeContext>(0);
}

asn1Parser::Encoding_prefixed_typeContext* asn1Parser::Prefixed_typeContext::encoding_prefixed_type() {
  return getRuleContext<asn1Parser::Encoding_prefixed_typeContext>(0);
}


size_t asn1Parser::Prefixed_typeContext::getRuleIndex() const {
  return asn1Parser::RulePrefixed_type;
}

void asn1Parser::Prefixed_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefixed_type(this);
}

void asn1Parser::Prefixed_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefixed_type(this);
}


antlrcpp::Any asn1Parser::Prefixed_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPrefixed_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Prefixed_typeContext* asn1Parser::prefixed_type() {
  Prefixed_typeContext *_localctx = _tracker.createInstance<Prefixed_typeContext>(_ctx, getState());
  enterRule(_localctx, 192, asn1Parser::RulePrefixed_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1020);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1018);
      tagged_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1019);
      encoding_prefixed_type();
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

//----------------- Tagged_typeContext ------------------------------------------------------------------

asn1Parser::Tagged_typeContext::Tagged_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::TagContext* asn1Parser::Tagged_typeContext::tag() {
  return getRuleContext<asn1Parser::TagContext>(0);
}

asn1Parser::TypeContext* asn1Parser::Tagged_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

tree::TerminalNode* asn1Parser::Tagged_typeContext::IMPLICIT_RW() {
  return getToken(asn1Parser::IMPLICIT_RW, 0);
}

tree::TerminalNode* asn1Parser::Tagged_typeContext::EXPLICIT_RW() {
  return getToken(asn1Parser::EXPLICIT_RW, 0);
}


size_t asn1Parser::Tagged_typeContext::getRuleIndex() const {
  return asn1Parser::RuleTagged_type;
}

void asn1Parser::Tagged_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTagged_type(this);
}

void asn1Parser::Tagged_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTagged_type(this);
}


antlrcpp::Any asn1Parser::Tagged_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTagged_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Tagged_typeContext* asn1Parser::tagged_type() {
  Tagged_typeContext *_localctx = _tracker.createInstance<Tagged_typeContext>(_ctx, getState());
  enterRule(_localctx, 194, asn1Parser::RuleTagged_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1033);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1022);
      tag();
      setState(1023);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1025);
      tag();
      setState(1026);
      match(asn1Parser::IMPLICIT_RW);
      setState(1027);
      type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1029);
      tag();
      setState(1030);
      match(asn1Parser::EXPLICIT_RW);
      setState(1031);
      type();
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

//----------------- TagContext ------------------------------------------------------------------

asn1Parser::TagContext::TagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::TagContext::LEFT_SQUARE_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_SQUARE_BRACKET_TK, 0);
}

asn1Parser::Class_numberContext* asn1Parser::TagContext::class_number() {
  return getRuleContext<asn1Parser::Class_numberContext>(0);
}

tree::TerminalNode* asn1Parser::TagContext::RIGHT_SQUARE_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_SQUARE_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::TagContext::ENCODING_REFERENCE() {
  return getToken(asn1Parser::ENCODING_REFERENCE, 0);
}

tree::TerminalNode* asn1Parser::TagContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}

asn1Parser::CategoryContext* asn1Parser::TagContext::category() {
  return getRuleContext<asn1Parser::CategoryContext>(0);
}


size_t asn1Parser::TagContext::getRuleIndex() const {
  return asn1Parser::RuleTag;
}

void asn1Parser::TagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTag(this);
}

void asn1Parser::TagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTag(this);
}


antlrcpp::Any asn1Parser::TagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTag(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::TagContext* asn1Parser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 196, asn1Parser::RuleTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1035);
    match(asn1Parser::LEFT_SQUARE_BRACKET_TK);
    setState(1038);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::ENCODING_REFERENCE) {
      setState(1036);
      match(asn1Parser::ENCODING_REFERENCE);
      setState(1037);
      match(asn1Parser::COLON_TK);
    }
    setState(1041);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 19) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 19)) & ((1ULL << (asn1Parser::APPLICATION_RW - 19))
      | (1ULL << (asn1Parser::PRIVATE_RW - 19))
      | (1ULL << (asn1Parser::UNIVERSAL_RW - 19)))) != 0)) {
      setState(1040);
      category();
    }
    setState(1043);
    class_number();
    setState(1044);
    match(asn1Parser::RIGHT_SQUARE_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_numberContext ------------------------------------------------------------------

asn1Parser::Class_numberContext::Class_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Class_numberContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

asn1Parser::Defined_valueContext* asn1Parser::Class_numberContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Class_numberContext::getRuleIndex() const {
  return asn1Parser::RuleClass_number;
}

void asn1Parser::Class_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_number(this);
}

void asn1Parser::Class_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_number(this);
}


antlrcpp::Any asn1Parser::Class_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitClass_number(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Class_numberContext* asn1Parser::class_number() {
  Class_numberContext *_localctx = _tracker.createInstance<Class_numberContext>(_ctx, getState());
  enterRule(_localctx, 198, asn1Parser::RuleClass_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1048);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(1046);
        match(asn1Parser::NUMBER);
        break;
      }

      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1047);
        defined_value();
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

//----------------- CategoryContext ------------------------------------------------------------------

asn1Parser::CategoryContext::CategoryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::CategoryContext::UNIVERSAL_RW() {
  return getToken(asn1Parser::UNIVERSAL_RW, 0);
}

tree::TerminalNode* asn1Parser::CategoryContext::APPLICATION_RW() {
  return getToken(asn1Parser::APPLICATION_RW, 0);
}

tree::TerminalNode* asn1Parser::CategoryContext::PRIVATE_RW() {
  return getToken(asn1Parser::PRIVATE_RW, 0);
}


size_t asn1Parser::CategoryContext::getRuleIndex() const {
  return asn1Parser::RuleCategory;
}

void asn1Parser::CategoryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCategory(this);
}

void asn1Parser::CategoryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCategory(this);
}


antlrcpp::Any asn1Parser::CategoryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitCategory(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::CategoryContext* asn1Parser::category() {
  CategoryContext *_localctx = _tracker.createInstance<CategoryContext>(_ctx, getState());
  enterRule(_localctx, 200, asn1Parser::RuleCategory);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1050);
    _la = _input->LA(1);
    if (!(((((_la - 19) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 19)) & ((1ULL << (asn1Parser::APPLICATION_RW - 19))
      | (1ULL << (asn1Parser::PRIVATE_RW - 19))
      | (1ULL << (asn1Parser::UNIVERSAL_RW - 19)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Encoding_prefixed_typeContext ------------------------------------------------------------------

asn1Parser::Encoding_prefixed_typeContext::Encoding_prefixed_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Encoding_prefixContext* asn1Parser::Encoding_prefixed_typeContext::encoding_prefix() {
  return getRuleContext<asn1Parser::Encoding_prefixContext>(0);
}

asn1Parser::TypeContext* asn1Parser::Encoding_prefixed_typeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Encoding_prefixed_typeContext::getRuleIndex() const {
  return asn1Parser::RuleEncoding_prefixed_type;
}

void asn1Parser::Encoding_prefixed_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEncoding_prefixed_type(this);
}

void asn1Parser::Encoding_prefixed_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEncoding_prefixed_type(this);
}


antlrcpp::Any asn1Parser::Encoding_prefixed_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEncoding_prefixed_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Encoding_prefixed_typeContext* asn1Parser::encoding_prefixed_type() {
  Encoding_prefixed_typeContext *_localctx = _tracker.createInstance<Encoding_prefixed_typeContext>(_ctx, getState());
  enterRule(_localctx, 202, asn1Parser::RuleEncoding_prefixed_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1052);
    encoding_prefix();
    setState(1053);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Encoding_prefixContext ------------------------------------------------------------------

asn1Parser::Encoding_prefixContext::Encoding_prefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Encoding_prefixContext::LEFT_SQUARE_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_SQUARE_BRACKET_TK, 0);
}

std::vector<tree::TerminalNode *> asn1Parser::Encoding_prefixContext::ENCODING_REFERENCE() {
  return getTokens(asn1Parser::ENCODING_REFERENCE);
}

tree::TerminalNode* asn1Parser::Encoding_prefixContext::ENCODING_REFERENCE(size_t i) {
  return getToken(asn1Parser::ENCODING_REFERENCE, i);
}

tree::TerminalNode* asn1Parser::Encoding_prefixContext::RIGHT_SQUARE_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_SQUARE_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Encoding_prefixContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}


size_t asn1Parser::Encoding_prefixContext::getRuleIndex() const {
  return asn1Parser::RuleEncoding_prefix;
}

void asn1Parser::Encoding_prefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEncoding_prefix(this);
}

void asn1Parser::Encoding_prefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEncoding_prefix(this);
}


antlrcpp::Any asn1Parser::Encoding_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEncoding_prefix(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Encoding_prefixContext* asn1Parser::encoding_prefix() {
  Encoding_prefixContext *_localctx = _tracker.createInstance<Encoding_prefixContext>(_ctx, getState());
  enterRule(_localctx, 204, asn1Parser::RuleEncoding_prefix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1055);
    match(asn1Parser::LEFT_SQUARE_BRACKET_TK);
    setState(1058);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      setState(1056);
      match(asn1Parser::ENCODING_REFERENCE);
      setState(1057);
      match(asn1Parser::COLON_TK);
      break;
    }

    }
    setState(1060);
    match(asn1Parser::ENCODING_REFERENCE);
    setState(1061);
    match(asn1Parser::RIGHT_SQUARE_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_identifier_valueContext ------------------------------------------------------------------

asn1Parser::Object_identifier_valueContext::Object_identifier_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Object_identifier_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Object_identifier_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

std::vector<asn1Parser::Obj_id_componentsContext *> asn1Parser::Object_identifier_valueContext::obj_id_components() {
  return getRuleContexts<asn1Parser::Obj_id_componentsContext>();
}

asn1Parser::Obj_id_componentsContext* asn1Parser::Object_identifier_valueContext::obj_id_components(size_t i) {
  return getRuleContext<asn1Parser::Obj_id_componentsContext>(i);
}


size_t asn1Parser::Object_identifier_valueContext::getRuleIndex() const {
  return asn1Parser::RuleObject_identifier_value;
}

void asn1Parser::Object_identifier_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject_identifier_value(this);
}

void asn1Parser::Object_identifier_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject_identifier_value(this);
}


antlrcpp::Any asn1Parser::Object_identifier_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitObject_identifier_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Object_identifier_valueContext* asn1Parser::object_identifier_value() {
  Object_identifier_valueContext *_localctx = _tracker.createInstance<Object_identifier_valueContext>(_ctx, getState());
  enterRule(_localctx, 206, asn1Parser::RuleObject_identifier_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1063);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1065); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1064);
      obj_id_components();
      setState(1067); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & ((1ULL << (asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE - 107))
      | (1ULL << (asn1Parser::IDENTIFIER - 107))
      | (1ULL << (asn1Parser::NUMBER - 107)))) != 0));
    setState(1069);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Obj_id_componentsContext ------------------------------------------------------------------

asn1Parser::Obj_id_componentsContext::Obj_id_componentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Name_formContext* asn1Parser::Obj_id_componentsContext::name_form() {
  return getRuleContext<asn1Parser::Name_formContext>(0);
}

asn1Parser::Number_formContext* asn1Parser::Obj_id_componentsContext::number_form() {
  return getRuleContext<asn1Parser::Number_formContext>(0);
}

asn1Parser::Name_and_number_formContext* asn1Parser::Obj_id_componentsContext::name_and_number_form() {
  return getRuleContext<asn1Parser::Name_and_number_formContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::Obj_id_componentsContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Obj_id_componentsContext::getRuleIndex() const {
  return asn1Parser::RuleObj_id_components;
}

void asn1Parser::Obj_id_componentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObj_id_components(this);
}

void asn1Parser::Obj_id_componentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObj_id_components(this);
}


antlrcpp::Any asn1Parser::Obj_id_componentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitObj_id_components(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Obj_id_componentsContext* asn1Parser::obj_id_components() {
  Obj_id_componentsContext *_localctx = _tracker.createInstance<Obj_id_componentsContext>(_ctx, getState());
  enterRule(_localctx, 208, asn1Parser::RuleObj_id_components);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1075);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1071);
      name_form();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1072);
      number_form();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1073);
      name_and_number_form();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1074);
      defined_value();
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

//----------------- Name_formContext ------------------------------------------------------------------

asn1Parser::Name_formContext::Name_formContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Name_formContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}


size_t asn1Parser::Name_formContext::getRuleIndex() const {
  return asn1Parser::RuleName_form;
}

void asn1Parser::Name_formContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_form(this);
}

void asn1Parser::Name_formContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_form(this);
}


antlrcpp::Any asn1Parser::Name_formContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitName_form(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Name_formContext* asn1Parser::name_form() {
  Name_formContext *_localctx = _tracker.createInstance<Name_formContext>(_ctx, getState());
  enterRule(_localctx, 210, asn1Parser::RuleName_form);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1077);
    match(asn1Parser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_formContext ------------------------------------------------------------------

asn1Parser::Number_formContext::Number_formContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Number_formContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

asn1Parser::Defined_valueContext* asn1Parser::Number_formContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Number_formContext::getRuleIndex() const {
  return asn1Parser::RuleNumber_form;
}

void asn1Parser::Number_formContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber_form(this);
}

void asn1Parser::Number_formContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber_form(this);
}


antlrcpp::Any asn1Parser::Number_formContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNumber_form(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Number_formContext* asn1Parser::number_form() {
  Number_formContext *_localctx = _tracker.createInstance<Number_formContext>(_ctx, getState());
  enterRule(_localctx, 212, asn1Parser::RuleNumber_form);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1081);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(1079);
        match(asn1Parser::NUMBER);
        break;
      }

      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1080);
        defined_value();
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

//----------------- Name_and_number_formContext ------------------------------------------------------------------

asn1Parser::Name_and_number_formContext::Name_and_number_formContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Name_and_number_formContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Name_and_number_formContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

asn1Parser::Number_formContext* asn1Parser::Name_and_number_formContext::number_form() {
  return getRuleContext<asn1Parser::Number_formContext>(0);
}

tree::TerminalNode* asn1Parser::Name_and_number_formContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}

tree::TerminalNode* asn1Parser::Name_and_number_formContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}


size_t asn1Parser::Name_and_number_formContext::getRuleIndex() const {
  return asn1Parser::RuleName_and_number_form;
}

void asn1Parser::Name_and_number_formContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_and_number_form(this);
}

void asn1Parser::Name_and_number_formContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_and_number_form(this);
}


antlrcpp::Any asn1Parser::Name_and_number_formContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitName_and_number_form(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Name_and_number_formContext* asn1Parser::name_and_number_form() {
  Name_and_number_formContext *_localctx = _tracker.createInstance<Name_and_number_formContext>(_ctx, getState());
  enterRule(_localctx, 214, asn1Parser::RuleName_and_number_form);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1093);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1083);
        match(asn1Parser::IDENTIFIER);
        setState(1084);
        match(asn1Parser::LEFT_PARENTHESIS_TK);
        setState(1085);
        number_form();
        setState(1086);
        match(asn1Parser::RIGHT_PARENTHESIS_TK);
        break;
      }

      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE: {
        enterOuterAlt(_localctx, 2);
        setState(1088);
        match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
        setState(1089);
        match(asn1Parser::LEFT_PARENTHESIS_TK);
        setState(1090);
        number_form();
        setState(1091);
        match(asn1Parser::RIGHT_PARENTHESIS_TK);
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

//----------------- Relative_oid_valueContext ------------------------------------------------------------------

asn1Parser::Relative_oid_valueContext::Relative_oid_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Relative_oid_valueContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Relative_oid_components_listContext* asn1Parser::Relative_oid_valueContext::relative_oid_components_list() {
  return getRuleContext<asn1Parser::Relative_oid_components_listContext>(0);
}

tree::TerminalNode* asn1Parser::Relative_oid_valueContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Relative_oid_valueContext::getRuleIndex() const {
  return asn1Parser::RuleRelative_oid_value;
}

void asn1Parser::Relative_oid_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelative_oid_value(this);
}

void asn1Parser::Relative_oid_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelative_oid_value(this);
}


antlrcpp::Any asn1Parser::Relative_oid_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRelative_oid_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Relative_oid_valueContext* asn1Parser::relative_oid_value() {
  Relative_oid_valueContext *_localctx = _tracker.createInstance<Relative_oid_valueContext>(_ctx, getState());
  enterRule(_localctx, 216, asn1Parser::RuleRelative_oid_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1095);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1096);
    relative_oid_components_list();
    setState(1097);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relative_oid_components_listContext ------------------------------------------------------------------

asn1Parser::Relative_oid_components_listContext::Relative_oid_components_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Relative_oid_componentsContext *> asn1Parser::Relative_oid_components_listContext::relative_oid_components() {
  return getRuleContexts<asn1Parser::Relative_oid_componentsContext>();
}

asn1Parser::Relative_oid_componentsContext* asn1Parser::Relative_oid_components_listContext::relative_oid_components(size_t i) {
  return getRuleContext<asn1Parser::Relative_oid_componentsContext>(i);
}


size_t asn1Parser::Relative_oid_components_listContext::getRuleIndex() const {
  return asn1Parser::RuleRelative_oid_components_list;
}

void asn1Parser::Relative_oid_components_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelative_oid_components_list(this);
}

void asn1Parser::Relative_oid_components_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelative_oid_components_list(this);
}


antlrcpp::Any asn1Parser::Relative_oid_components_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRelative_oid_components_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Relative_oid_components_listContext* asn1Parser::relative_oid_components_list() {
  Relative_oid_components_listContext *_localctx = _tracker.createInstance<Relative_oid_components_listContext>(_ctx, getState());
  enterRule(_localctx, 218, asn1Parser::RuleRelative_oid_components_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1100); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1099);
      relative_oid_components();
      setState(1102); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & ((1ULL << (asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE - 107))
      | (1ULL << (asn1Parser::IDENTIFIER - 107))
      | (1ULL << (asn1Parser::NUMBER - 107)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relative_oid_componentsContext ------------------------------------------------------------------

asn1Parser::Relative_oid_componentsContext::Relative_oid_componentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Number_formContext* asn1Parser::Relative_oid_componentsContext::number_form() {
  return getRuleContext<asn1Parser::Number_formContext>(0);
}

asn1Parser::Name_and_number_formContext* asn1Parser::Relative_oid_componentsContext::name_and_number_form() {
  return getRuleContext<asn1Parser::Name_and_number_formContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::Relative_oid_componentsContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Relative_oid_componentsContext::getRuleIndex() const {
  return asn1Parser::RuleRelative_oid_components;
}

void asn1Parser::Relative_oid_componentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelative_oid_components(this);
}

void asn1Parser::Relative_oid_componentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelative_oid_components(this);
}


antlrcpp::Any asn1Parser::Relative_oid_componentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRelative_oid_components(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Relative_oid_componentsContext* asn1Parser::relative_oid_components() {
  Relative_oid_componentsContext *_localctx = _tracker.createInstance<Relative_oid_componentsContext>(_ctx, getState());
  enterRule(_localctx, 220, asn1Parser::RuleRelative_oid_components);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1104);
      number_form();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1105);
      name_and_number_form();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1106);
      defined_value();
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

//----------------- Iri_valueContext ------------------------------------------------------------------

asn1Parser::Iri_valueContext::Iri_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> asn1Parser::Iri_valueContext::QUOTATION_MARK_TK() {
  return getTokens(asn1Parser::QUOTATION_MARK_TK);
}

tree::TerminalNode* asn1Parser::Iri_valueContext::QUOTATION_MARK_TK(size_t i) {
  return getToken(asn1Parser::QUOTATION_MARK_TK, i);
}

std::vector<tree::TerminalNode *> asn1Parser::Iri_valueContext::SOLIDUS_TK() {
  return getTokens(asn1Parser::SOLIDUS_TK);
}

tree::TerminalNode* asn1Parser::Iri_valueContext::SOLIDUS_TK(size_t i) {
  return getToken(asn1Parser::SOLIDUS_TK, i);
}

std::vector<asn1Parser::Arc_identifierContext *> asn1Parser::Iri_valueContext::arc_identifier() {
  return getRuleContexts<asn1Parser::Arc_identifierContext>();
}

asn1Parser::Arc_identifierContext* asn1Parser::Iri_valueContext::arc_identifier(size_t i) {
  return getRuleContext<asn1Parser::Arc_identifierContext>(i);
}


size_t asn1Parser::Iri_valueContext::getRuleIndex() const {
  return asn1Parser::RuleIri_value;
}

void asn1Parser::Iri_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIri_value(this);
}

void asn1Parser::Iri_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIri_value(this);
}


antlrcpp::Any asn1Parser::Iri_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIri_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Iri_valueContext* asn1Parser::iri_value() {
  Iri_valueContext *_localctx = _tracker.createInstance<Iri_valueContext>(_ctx, getState());
  enterRule(_localctx, 222, asn1Parser::RuleIri_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1109);
    match(asn1Parser::QUOTATION_MARK_TK);
    setState(1112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1110);
      match(asn1Parser::SOLIDUS_TK);
      setState(1111);
      arc_identifier();
      setState(1114); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::SOLIDUS_TK);
    setState(1116);
    match(asn1Parser::QUOTATION_MARK_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arc_identifierContext ------------------------------------------------------------------

asn1Parser::Arc_identifierContext::Arc_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Arc_identifierContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}

tree::TerminalNode* asn1Parser::Arc_identifierContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

tree::TerminalNode* asn1Parser::Arc_identifierContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

tree::TerminalNode* asn1Parser::Arc_identifierContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}

tree::TerminalNode* asn1Parser::Arc_identifierContext::TYPE_REFERENCE_OR_MODULE_REFERENCE() {
  return getToken(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE, 0);
}


size_t asn1Parser::Arc_identifierContext::getRuleIndex() const {
  return asn1Parser::RuleArc_identifier;
}

void asn1Parser::Arc_identifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArc_identifier(this);
}

void asn1Parser::Arc_identifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArc_identifier(this);
}


antlrcpp::Any asn1Parser::Arc_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitArc_identifier(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Arc_identifierContext* asn1Parser::arc_identifier() {
  Arc_identifierContext *_localctx = _tracker.createInstance<Arc_identifierContext>(_ctx, getState());
  enterRule(_localctx, 224, asn1Parser::RuleArc_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(1118);
        match(asn1Parser::NUMBER);
        break;
      }

      case asn1Parser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(1119);
        match(asn1Parser::IDENTIFIER);
        setState(1120);
        match(asn1Parser::LEFT_PARENTHESIS_TK);
        setState(1121);
        match(asn1Parser::NUMBER);
        setState(1122);
        match(asn1Parser::RIGHT_PARENTHESIS_TK);
        break;
      }

      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE: {
        enterOuterAlt(_localctx, 3);
        setState(1123);
        match(asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE);
        setState(1124);
        match(asn1Parser::LEFT_PARENTHESIS_TK);
        setState(1125);
        match(asn1Parser::NUMBER);
        setState(1126);
        match(asn1Parser::RIGHT_PARENTHESIS_TK);
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

//----------------- Relative_iri_valueContext ------------------------------------------------------------------

asn1Parser::Relative_iri_valueContext::Relative_iri_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> asn1Parser::Relative_iri_valueContext::QUOTATION_MARK_TK() {
  return getTokens(asn1Parser::QUOTATION_MARK_TK);
}

tree::TerminalNode* asn1Parser::Relative_iri_valueContext::QUOTATION_MARK_TK(size_t i) {
  return getToken(asn1Parser::QUOTATION_MARK_TK, i);
}

std::vector<asn1Parser::Arc_identifierContext *> asn1Parser::Relative_iri_valueContext::arc_identifier() {
  return getRuleContexts<asn1Parser::Arc_identifierContext>();
}

asn1Parser::Arc_identifierContext* asn1Parser::Relative_iri_valueContext::arc_identifier(size_t i) {
  return getRuleContext<asn1Parser::Arc_identifierContext>(i);
}

std::vector<tree::TerminalNode *> asn1Parser::Relative_iri_valueContext::SOLIDUS_TK() {
  return getTokens(asn1Parser::SOLIDUS_TK);
}

tree::TerminalNode* asn1Parser::Relative_iri_valueContext::SOLIDUS_TK(size_t i) {
  return getToken(asn1Parser::SOLIDUS_TK, i);
}


size_t asn1Parser::Relative_iri_valueContext::getRuleIndex() const {
  return asn1Parser::RuleRelative_iri_value;
}

void asn1Parser::Relative_iri_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelative_iri_value(this);
}

void asn1Parser::Relative_iri_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelative_iri_value(this);
}


antlrcpp::Any asn1Parser::Relative_iri_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRelative_iri_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Relative_iri_valueContext* asn1Parser::relative_iri_value() {
  Relative_iri_valueContext *_localctx = _tracker.createInstance<Relative_iri_valueContext>(_ctx, getState());
  enterRule(_localctx, 226, asn1Parser::RuleRelative_iri_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1129);
    match(asn1Parser::QUOTATION_MARK_TK);
    setState(1130);
    arc_identifier();
    setState(1133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1131);
      match(asn1Parser::SOLIDUS_TK);
      setState(1132);
      arc_identifier();
      setState(1135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::SOLIDUS_TK);
    setState(1137);
    match(asn1Parser::QUOTATION_MARK_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Embedded_pdv_valueContext ------------------------------------------------------------------

asn1Parser::Embedded_pdv_valueContext::Embedded_pdv_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Sequence_valueContext* asn1Parser::Embedded_pdv_valueContext::sequence_value() {
  return getRuleContext<asn1Parser::Sequence_valueContext>(0);
}


size_t asn1Parser::Embedded_pdv_valueContext::getRuleIndex() const {
  return asn1Parser::RuleEmbedded_pdv_value;
}

void asn1Parser::Embedded_pdv_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmbedded_pdv_value(this);
}

void asn1Parser::Embedded_pdv_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmbedded_pdv_value(this);
}


antlrcpp::Any asn1Parser::Embedded_pdv_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEmbedded_pdv_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Embedded_pdv_valueContext* asn1Parser::embedded_pdv_value() {
  Embedded_pdv_valueContext *_localctx = _tracker.createInstance<Embedded_pdv_valueContext>(_ctx, getState());
  enterRule(_localctx, 228, asn1Parser::RuleEmbedded_pdv_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1139);
    sequence_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Time_valueContext ------------------------------------------------------------------

asn1Parser::Time_valueContext::Time_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Time_valueContext::TSTRING() {
  return getToken(asn1Parser::TSTRING, 0);
}


size_t asn1Parser::Time_valueContext::getRuleIndex() const {
  return asn1Parser::RuleTime_value;
}

void asn1Parser::Time_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime_value(this);
}

void asn1Parser::Time_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime_value(this);
}


antlrcpp::Any asn1Parser::Time_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTime_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Time_valueContext* asn1Parser::time_value() {
  Time_valueContext *_localctx = _tracker.createInstance<Time_valueContext>(_ctx, getState());
  enterRule(_localctx, 230, asn1Parser::RuleTime_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1141);
    match(asn1Parser::TSTRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Character_string_typeContext ------------------------------------------------------------------

asn1Parser::Character_string_typeContext::Character_string_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Restricted_character_string_typeContext* asn1Parser::Character_string_typeContext::restricted_character_string_type() {
  return getRuleContext<asn1Parser::Restricted_character_string_typeContext>(0);
}

asn1Parser::Unrestricted_character_string_typeContext* asn1Parser::Character_string_typeContext::unrestricted_character_string_type() {
  return getRuleContext<asn1Parser::Unrestricted_character_string_typeContext>(0);
}


size_t asn1Parser::Character_string_typeContext::getRuleIndex() const {
  return asn1Parser::RuleCharacter_string_type;
}

void asn1Parser::Character_string_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharacter_string_type(this);
}

void asn1Parser::Character_string_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharacter_string_type(this);
}


antlrcpp::Any asn1Parser::Character_string_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitCharacter_string_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Character_string_typeContext* asn1Parser::character_string_type() {
  Character_string_typeContext *_localctx = _tracker.createInstance<Character_string_typeContext>(_ctx, getState());
  enterRule(_localctx, 232, asn1Parser::RuleCharacter_string_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::T__0:
      case asn1Parser::T__1:
      case asn1Parser::T__2:
      case asn1Parser::T__3:
      case asn1Parser::T__4:
      case asn1Parser::T__5:
      case asn1Parser::T__6:
      case asn1Parser::T__7:
      case asn1Parser::T__8:
      case asn1Parser::T__9:
      case asn1Parser::T__10:
      case asn1Parser::T__11:
      case asn1Parser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(1143);
        restricted_character_string_type();
        break;
      }

      case asn1Parser::CHARACTER_RW: {
        enterOuterAlt(_localctx, 2);
        setState(1144);
        unrestricted_character_string_type();
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

//----------------- Character_string_valueContext ------------------------------------------------------------------

asn1Parser::Character_string_valueContext::Character_string_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Restricted_character_string_valueContext* asn1Parser::Character_string_valueContext::restricted_character_string_value() {
  return getRuleContext<asn1Parser::Restricted_character_string_valueContext>(0);
}

asn1Parser::Unrestricted_character_string_valueContext* asn1Parser::Character_string_valueContext::unrestricted_character_string_value() {
  return getRuleContext<asn1Parser::Unrestricted_character_string_valueContext>(0);
}


size_t asn1Parser::Character_string_valueContext::getRuleIndex() const {
  return asn1Parser::RuleCharacter_string_value;
}

void asn1Parser::Character_string_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharacter_string_value(this);
}

void asn1Parser::Character_string_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharacter_string_value(this);
}


antlrcpp::Any asn1Parser::Character_string_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitCharacter_string_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Character_string_valueContext* asn1Parser::character_string_value() {
  Character_string_valueContext *_localctx = _tracker.createInstance<Character_string_valueContext>(_ctx, getState());
  enterRule(_localctx, 234, asn1Parser::RuleCharacter_string_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1147);
      restricted_character_string_value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1148);
      unrestricted_character_string_value();
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

//----------------- Restricted_character_string_typeContext ------------------------------------------------------------------

asn1Parser::Restricted_character_string_typeContext::Restricted_character_string_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t asn1Parser::Restricted_character_string_typeContext::getRuleIndex() const {
  return asn1Parser::RuleRestricted_character_string_type;
}

void asn1Parser::Restricted_character_string_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRestricted_character_string_type(this);
}

void asn1Parser::Restricted_character_string_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRestricted_character_string_type(this);
}


antlrcpp::Any asn1Parser::Restricted_character_string_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRestricted_character_string_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Restricted_character_string_typeContext* asn1Parser::restricted_character_string_type() {
  Restricted_character_string_typeContext *_localctx = _tracker.createInstance<Restricted_character_string_typeContext>(_ctx, getState());
  enterRule(_localctx, 236, asn1Parser::RuleRestricted_character_string_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1151);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << asn1Parser::T__0)
      | (1ULL << asn1Parser::T__1)
      | (1ULL << asn1Parser::T__2)
      | (1ULL << asn1Parser::T__3)
      | (1ULL << asn1Parser::T__4)
      | (1ULL << asn1Parser::T__5)
      | (1ULL << asn1Parser::T__6)
      | (1ULL << asn1Parser::T__7)
      | (1ULL << asn1Parser::T__8)
      | (1ULL << asn1Parser::T__9)
      | (1ULL << asn1Parser::T__10)
      | (1ULL << asn1Parser::T__11)
      | (1ULL << asn1Parser::T__12))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Restricted_character_string_valueContext ------------------------------------------------------------------

asn1Parser::Restricted_character_string_valueContext::Restricted_character_string_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Restricted_character_string_valueContext::CSTRING() {
  return getToken(asn1Parser::CSTRING, 0);
}

asn1Parser::Character_string_listContext* asn1Parser::Restricted_character_string_valueContext::character_string_list() {
  return getRuleContext<asn1Parser::Character_string_listContext>(0);
}

asn1Parser::QuadrupleContext* asn1Parser::Restricted_character_string_valueContext::quadruple() {
  return getRuleContext<asn1Parser::QuadrupleContext>(0);
}

asn1Parser::TupleContext* asn1Parser::Restricted_character_string_valueContext::tuple() {
  return getRuleContext<asn1Parser::TupleContext>(0);
}


size_t asn1Parser::Restricted_character_string_valueContext::getRuleIndex() const {
  return asn1Parser::RuleRestricted_character_string_value;
}

void asn1Parser::Restricted_character_string_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRestricted_character_string_value(this);
}

void asn1Parser::Restricted_character_string_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRestricted_character_string_value(this);
}


antlrcpp::Any asn1Parser::Restricted_character_string_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRestricted_character_string_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Restricted_character_string_valueContext* asn1Parser::restricted_character_string_value() {
  Restricted_character_string_valueContext *_localctx = _tracker.createInstance<Restricted_character_string_valueContext>(_ctx, getState());
  enterRule(_localctx, 238, asn1Parser::RuleRestricted_character_string_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1153);
      match(asn1Parser::CSTRING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1154);
      character_string_list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1155);
      quadruple();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1156);
      tuple();
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

//----------------- Character_string_listContext ------------------------------------------------------------------

asn1Parser::Character_string_listContext::Character_string_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Character_string_listContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

std::vector<asn1Parser::Chars_defnContext *> asn1Parser::Character_string_listContext::chars_defn() {
  return getRuleContexts<asn1Parser::Chars_defnContext>();
}

asn1Parser::Chars_defnContext* asn1Parser::Character_string_listContext::chars_defn(size_t i) {
  return getRuleContext<asn1Parser::Chars_defnContext>(i);
}

tree::TerminalNode* asn1Parser::Character_string_listContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}

std::vector<tree::TerminalNode *> asn1Parser::Character_string_listContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Character_string_listContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}


size_t asn1Parser::Character_string_listContext::getRuleIndex() const {
  return asn1Parser::RuleCharacter_string_list;
}

void asn1Parser::Character_string_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharacter_string_list(this);
}

void asn1Parser::Character_string_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharacter_string_list(this);
}


antlrcpp::Any asn1Parser::Character_string_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitCharacter_string_list(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Character_string_listContext* asn1Parser::character_string_list() {
  Character_string_listContext *_localctx = _tracker.createInstance<Character_string_listContext>(_ctx, getState());
  enterRule(_localctx, 240, asn1Parser::RuleCharacter_string_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1159);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1160);
    chars_defn();
    setState(1165);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == asn1Parser::COMMA_TK) {
      setState(1161);
      match(asn1Parser::COMMA_TK);
      setState(1162);
      chars_defn();
      setState(1167);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1168);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chars_defnContext ------------------------------------------------------------------

asn1Parser::Chars_defnContext::Chars_defnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Chars_defnContext::CSTRING() {
  return getToken(asn1Parser::CSTRING, 0);
}

asn1Parser::QuadrupleContext* asn1Parser::Chars_defnContext::quadruple() {
  return getRuleContext<asn1Parser::QuadrupleContext>(0);
}

asn1Parser::TupleContext* asn1Parser::Chars_defnContext::tuple() {
  return getRuleContext<asn1Parser::TupleContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::Chars_defnContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}


size_t asn1Parser::Chars_defnContext::getRuleIndex() const {
  return asn1Parser::RuleChars_defn;
}

void asn1Parser::Chars_defnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChars_defn(this);
}

void asn1Parser::Chars_defnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChars_defn(this);
}


antlrcpp::Any asn1Parser::Chars_defnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitChars_defn(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Chars_defnContext* asn1Parser::chars_defn() {
  Chars_defnContext *_localctx = _tracker.createInstance<Chars_defnContext>(_ctx, getState());
  enterRule(_localctx, 242, asn1Parser::RuleChars_defn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1170);
      match(asn1Parser::CSTRING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1171);
      quadruple();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1172);
      tuple();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1173);
      defined_value();
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

//----------------- QuadrupleContext ------------------------------------------------------------------

asn1Parser::QuadrupleContext::QuadrupleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::QuadrupleContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::GroupContext* asn1Parser::QuadrupleContext::group() {
  return getRuleContext<asn1Parser::GroupContext>(0);
}

std::vector<tree::TerminalNode *> asn1Parser::QuadrupleContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::QuadrupleContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}

asn1Parser::PlaneContext* asn1Parser::QuadrupleContext::plane() {
  return getRuleContext<asn1Parser::PlaneContext>(0);
}

asn1Parser::RowContext* asn1Parser::QuadrupleContext::row() {
  return getRuleContext<asn1Parser::RowContext>(0);
}

asn1Parser::CellContext* asn1Parser::QuadrupleContext::cell() {
  return getRuleContext<asn1Parser::CellContext>(0);
}

tree::TerminalNode* asn1Parser::QuadrupleContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::QuadrupleContext::getRuleIndex() const {
  return asn1Parser::RuleQuadruple;
}

void asn1Parser::QuadrupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuadruple(this);
}

void asn1Parser::QuadrupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuadruple(this);
}


antlrcpp::Any asn1Parser::QuadrupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitQuadruple(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::QuadrupleContext* asn1Parser::quadruple() {
  QuadrupleContext *_localctx = _tracker.createInstance<QuadrupleContext>(_ctx, getState());
  enterRule(_localctx, 244, asn1Parser::RuleQuadruple);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1176);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1177);
    group();
    setState(1178);
    match(asn1Parser::COMMA_TK);
    setState(1179);
    plane();
    setState(1180);
    match(asn1Parser::COMMA_TK);
    setState(1181);
    row();
    setState(1182);
    match(asn1Parser::COMMA_TK);
    setState(1183);
    cell();
    setState(1184);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupContext ------------------------------------------------------------------

asn1Parser::GroupContext::GroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::GroupContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::GroupContext::getRuleIndex() const {
  return asn1Parser::RuleGroup;
}

void asn1Parser::GroupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup(this);
}

void asn1Parser::GroupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup(this);
}


antlrcpp::Any asn1Parser::GroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitGroup(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::GroupContext* asn1Parser::group() {
  GroupContext *_localctx = _tracker.createInstance<GroupContext>(_ctx, getState());
  enterRule(_localctx, 246, asn1Parser::RuleGroup);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1186);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlaneContext ------------------------------------------------------------------

asn1Parser::PlaneContext::PlaneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::PlaneContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::PlaneContext::getRuleIndex() const {
  return asn1Parser::RulePlane;
}

void asn1Parser::PlaneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlane(this);
}

void asn1Parser::PlaneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlane(this);
}


antlrcpp::Any asn1Parser::PlaneContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPlane(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::PlaneContext* asn1Parser::plane() {
  PlaneContext *_localctx = _tracker.createInstance<PlaneContext>(_ctx, getState());
  enterRule(_localctx, 248, asn1Parser::RulePlane);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1188);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RowContext ------------------------------------------------------------------

asn1Parser::RowContext::RowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::RowContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::RowContext::getRuleIndex() const {
  return asn1Parser::RuleRow;
}

void asn1Parser::RowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRow(this);
}

void asn1Parser::RowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRow(this);
}


antlrcpp::Any asn1Parser::RowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRow(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::RowContext* asn1Parser::row() {
  RowContext *_localctx = _tracker.createInstance<RowContext>(_ctx, getState());
  enterRule(_localctx, 250, asn1Parser::RuleRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1190);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CellContext ------------------------------------------------------------------

asn1Parser::CellContext::CellContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::CellContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::CellContext::getRuleIndex() const {
  return asn1Parser::RuleCell;
}

void asn1Parser::CellContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCell(this);
}

void asn1Parser::CellContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCell(this);
}


antlrcpp::Any asn1Parser::CellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitCell(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::CellContext* asn1Parser::cell() {
  CellContext *_localctx = _tracker.createInstance<CellContext>(_ctx, getState());
  enterRule(_localctx, 252, asn1Parser::RuleCell);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1192);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TupleContext ------------------------------------------------------------------

asn1Parser::TupleContext::TupleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::TupleContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Table_columnContext* asn1Parser::TupleContext::table_column() {
  return getRuleContext<asn1Parser::Table_columnContext>(0);
}

tree::TerminalNode* asn1Parser::TupleContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Table_rowContext* asn1Parser::TupleContext::table_row() {
  return getRuleContext<asn1Parser::Table_rowContext>(0);
}

tree::TerminalNode* asn1Parser::TupleContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::TupleContext::getRuleIndex() const {
  return asn1Parser::RuleTuple;
}

void asn1Parser::TupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTuple(this);
}

void asn1Parser::TupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTuple(this);
}


antlrcpp::Any asn1Parser::TupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTuple(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::TupleContext* asn1Parser::tuple() {
  TupleContext *_localctx = _tracker.createInstance<TupleContext>(_ctx, getState());
  enterRule(_localctx, 254, asn1Parser::RuleTuple);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1194);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1195);
    table_column();
    setState(1196);
    match(asn1Parser::COMMA_TK);
    setState(1197);
    table_row();
    setState(1198);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_columnContext ------------------------------------------------------------------

asn1Parser::Table_columnContext::Table_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Table_columnContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::Table_columnContext::getRuleIndex() const {
  return asn1Parser::RuleTable_column;
}

void asn1Parser::Table_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_column(this);
}

void asn1Parser::Table_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_column(this);
}


antlrcpp::Any asn1Parser::Table_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTable_column(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Table_columnContext* asn1Parser::table_column() {
  Table_columnContext *_localctx = _tracker.createInstance<Table_columnContext>(_ctx, getState());
  enterRule(_localctx, 256, asn1Parser::RuleTable_column);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1200);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_rowContext ------------------------------------------------------------------

asn1Parser::Table_rowContext::Table_rowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Table_rowContext::NUMBER() {
  return getToken(asn1Parser::NUMBER, 0);
}


size_t asn1Parser::Table_rowContext::getRuleIndex() const {
  return asn1Parser::RuleTable_row;
}

void asn1Parser::Table_rowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_row(this);
}

void asn1Parser::Table_rowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_row(this);
}


antlrcpp::Any asn1Parser::Table_rowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTable_row(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Table_rowContext* asn1Parser::table_row() {
  Table_rowContext *_localctx = _tracker.createInstance<Table_rowContext>(_ctx, getState());
  enterRule(_localctx, 258, asn1Parser::RuleTable_row);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1202);
    match(asn1Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unrestricted_character_string_typeContext ------------------------------------------------------------------

asn1Parser::Unrestricted_character_string_typeContext::Unrestricted_character_string_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Unrestricted_character_string_typeContext::CHARACTER_RW() {
  return getToken(asn1Parser::CHARACTER_RW, 0);
}

tree::TerminalNode* asn1Parser::Unrestricted_character_string_typeContext::STRING_RW() {
  return getToken(asn1Parser::STRING_RW, 0);
}


size_t asn1Parser::Unrestricted_character_string_typeContext::getRuleIndex() const {
  return asn1Parser::RuleUnrestricted_character_string_type;
}

void asn1Parser::Unrestricted_character_string_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnrestricted_character_string_type(this);
}

void asn1Parser::Unrestricted_character_string_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnrestricted_character_string_type(this);
}


antlrcpp::Any asn1Parser::Unrestricted_character_string_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUnrestricted_character_string_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Unrestricted_character_string_typeContext* asn1Parser::unrestricted_character_string_type() {
  Unrestricted_character_string_typeContext *_localctx = _tracker.createInstance<Unrestricted_character_string_typeContext>(_ctx, getState());
  enterRule(_localctx, 260, asn1Parser::RuleUnrestricted_character_string_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1204);
    match(asn1Parser::CHARACTER_RW);
    setState(1205);
    match(asn1Parser::STRING_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unrestricted_character_string_valueContext ------------------------------------------------------------------

asn1Parser::Unrestricted_character_string_valueContext::Unrestricted_character_string_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Sequence_valueContext* asn1Parser::Unrestricted_character_string_valueContext::sequence_value() {
  return getRuleContext<asn1Parser::Sequence_valueContext>(0);
}


size_t asn1Parser::Unrestricted_character_string_valueContext::getRuleIndex() const {
  return asn1Parser::RuleUnrestricted_character_string_value;
}

void asn1Parser::Unrestricted_character_string_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnrestricted_character_string_value(this);
}

void asn1Parser::Unrestricted_character_string_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnrestricted_character_string_value(this);
}


antlrcpp::Any asn1Parser::Unrestricted_character_string_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUnrestricted_character_string_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Unrestricted_character_string_valueContext* asn1Parser::unrestricted_character_string_value() {
  Unrestricted_character_string_valueContext *_localctx = _tracker.createInstance<Unrestricted_character_string_valueContext>(_ctx, getState());
  enterRule(_localctx, 262, asn1Parser::RuleUnrestricted_character_string_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1207);
    sequence_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Useful_typeContext ------------------------------------------------------------------

asn1Parser::Useful_typeContext::Useful_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t asn1Parser::Useful_typeContext::getRuleIndex() const {
  return asn1Parser::RuleUseful_type;
}

void asn1Parser::Useful_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUseful_type(this);
}

void asn1Parser::Useful_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUseful_type(this);
}


antlrcpp::Any asn1Parser::Useful_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUseful_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Useful_typeContext* asn1Parser::useful_type() {
  Useful_typeContext *_localctx = _tracker.createInstance<Useful_typeContext>(_ctx, getState());
  enterRule(_localctx, 264, asn1Parser::RuleUseful_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1209);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << asn1Parser::T__13)
      | (1ULL << asn1Parser::T__14)
      | (1ULL << asn1Parser::T__15))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constrained_typeContext ------------------------------------------------------------------

asn1Parser::Constrained_typeContext::Constrained_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ConstraintContext* asn1Parser::Constrained_typeContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}

asn1Parser::Builtin_typeContext* asn1Parser::Constrained_typeContext::builtin_type() {
  return getRuleContext<asn1Parser::Builtin_typeContext>(0);
}

asn1Parser::Referenced_typeContext* asn1Parser::Constrained_typeContext::referenced_type() {
  return getRuleContext<asn1Parser::Referenced_typeContext>(0);
}

asn1Parser::Type_with_constraintContext* asn1Parser::Constrained_typeContext::type_with_constraint() {
  return getRuleContext<asn1Parser::Type_with_constraintContext>(0);
}


size_t asn1Parser::Constrained_typeContext::getRuleIndex() const {
  return asn1Parser::RuleConstrained_type;
}

void asn1Parser::Constrained_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstrained_type(this);
}

void asn1Parser::Constrained_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstrained_type(this);
}


antlrcpp::Any asn1Parser::Constrained_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitConstrained_type(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Constrained_typeContext* asn1Parser::constrained_type() {
  Constrained_typeContext *_localctx = _tracker.createInstance<Constrained_typeContext>(_ctx, getState());
  enterRule(_localctx, 266, asn1Parser::RuleConstrained_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1213);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case asn1Parser::T__0:
        case asn1Parser::T__1:
        case asn1Parser::T__2:
        case asn1Parser::T__3:
        case asn1Parser::T__4:
        case asn1Parser::T__5:
        case asn1Parser::T__6:
        case asn1Parser::T__7:
        case asn1Parser::T__8:
        case asn1Parser::T__9:
        case asn1Parser::T__10:
        case asn1Parser::T__11:
        case asn1Parser::T__12:
        case asn1Parser::BIT_RW:
        case asn1Parser::BOOLEAN_RW:
        case asn1Parser::CHARACTER_RW:
        case asn1Parser::CHOICE_RW:
        case asn1Parser::DATE_RW:
        case asn1Parser::DATE_TIME_RW:
        case asn1Parser::DURATION_RW:
        case asn1Parser::EMBEDDED_RW:
        case asn1Parser::ENUMERATED_RW:
        case asn1Parser::EXTERNAL_RW:
        case asn1Parser::INTEGER_RW:
        case asn1Parser::NULL_RW:
        case asn1Parser::OBJECT_RW:
        case asn1Parser::OCTET_RW:
        case asn1Parser::OID_IRI_RW:
        case asn1Parser::REAL_RW:
        case asn1Parser::RELATIVE_OID_IRI_RW:
        case asn1Parser::RELATIVE_OID_RW:
        case asn1Parser::SEQUENCE_RW:
        case asn1Parser::SET_RW:
        case asn1Parser::TIME_OF_DAY_RW:
        case asn1Parser::TIME_RW:
        case asn1Parser::LEFT_SQUARE_BRACKET_TK: {
          setState(1211);
          builtin_type();
          break;
        }

        case asn1Parser::T__13:
        case asn1Parser::T__14:
        case asn1Parser::T__15:
        case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
        case asn1Parser::IDENTIFIER: {
          setState(1212);
          referenced_type();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1215);
      constraint();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1217);
      type_with_constraint();
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

//----------------- Type_with_constraintContext ------------------------------------------------------------------

asn1Parser::Type_with_constraintContext::Type_with_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Type_with_constraintContext::SET_RW() {
  return getToken(asn1Parser::SET_RW, 0);
}

asn1Parser::ConstraintContext* asn1Parser::Type_with_constraintContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}

tree::TerminalNode* asn1Parser::Type_with_constraintContext::OF_RW() {
  return getToken(asn1Parser::OF_RW, 0);
}

asn1Parser::TypeContext* asn1Parser::Type_with_constraintContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

asn1Parser::Size_constraintContext* asn1Parser::Type_with_constraintContext::size_constraint() {
  return getRuleContext<asn1Parser::Size_constraintContext>(0);
}

tree::TerminalNode* asn1Parser::Type_with_constraintContext::SEQUENCE_RW() {
  return getToken(asn1Parser::SEQUENCE_RW, 0);
}

asn1Parser::Named_typeContext* asn1Parser::Type_with_constraintContext::named_type() {
  return getRuleContext<asn1Parser::Named_typeContext>(0);
}


size_t asn1Parser::Type_with_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleType_with_constraint;
}

void asn1Parser::Type_with_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_with_constraint(this);
}

void asn1Parser::Type_with_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_with_constraint(this);
}


antlrcpp::Any asn1Parser::Type_with_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitType_with_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Type_with_constraintContext* asn1Parser::type_with_constraint() {
  Type_with_constraintContext *_localctx = _tracker.createInstance<Type_with_constraintContext>(_ctx, getState());
  enterRule(_localctx, 268, asn1Parser::RuleType_with_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1220);
      match(asn1Parser::SET_RW);
      setState(1221);
      constraint();
      setState(1222);
      match(asn1Parser::OF_RW);
      setState(1223);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1225);
      match(asn1Parser::SET_RW);
      setState(1226);
      size_constraint();
      setState(1227);
      match(asn1Parser::OF_RW);
      setState(1228);
      type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1230);
      match(asn1Parser::SEQUENCE_RW);
      setState(1231);
      constraint();
      setState(1232);
      match(asn1Parser::OF_RW);
      setState(1233);
      type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1235);
      match(asn1Parser::SEQUENCE_RW);
      setState(1236);
      size_constraint();
      setState(1237);
      match(asn1Parser::OF_RW);
      setState(1238);
      type();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1240);
      match(asn1Parser::SET_RW);
      setState(1241);
      constraint();
      setState(1242);
      match(asn1Parser::OF_RW);
      setState(1243);
      named_type();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1245);
      match(asn1Parser::SET_RW);
      setState(1246);
      size_constraint();
      setState(1247);
      match(asn1Parser::OF_RW);
      setState(1248);
      named_type();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1250);
      match(asn1Parser::SEQUENCE_RW);
      setState(1251);
      constraint();
      setState(1252);
      match(asn1Parser::OF_RW);
      setState(1253);
      named_type();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1255);
      match(asn1Parser::SEQUENCE_RW);
      setState(1256);
      size_constraint();
      setState(1257);
      match(asn1Parser::OF_RW);
      setState(1258);
      named_type();
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

//----------------- ConstraintContext ------------------------------------------------------------------

asn1Parser::ConstraintContext::ConstraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::ConstraintContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

asn1Parser::Constraint_specContext* asn1Parser::ConstraintContext::constraint_spec() {
  return getRuleContext<asn1Parser::Constraint_specContext>(0);
}

tree::TerminalNode* asn1Parser::ConstraintContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}

asn1Parser::Exception_specContext* asn1Parser::ConstraintContext::exception_spec() {
  return getRuleContext<asn1Parser::Exception_specContext>(0);
}


size_t asn1Parser::ConstraintContext::getRuleIndex() const {
  return asn1Parser::RuleConstraint;
}

void asn1Parser::ConstraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraint(this);
}

void asn1Parser::ConstraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraint(this);
}


antlrcpp::Any asn1Parser::ConstraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitConstraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ConstraintContext* asn1Parser::constraint() {
  ConstraintContext *_localctx = _tracker.createInstance<ConstraintContext>(_ctx, getState());
  enterRule(_localctx, 270, asn1Parser::RuleConstraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1262);
    match(asn1Parser::LEFT_PARENTHESIS_TK);
    setState(1263);
    constraint_spec();
    setState(1265);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::EXCLAMATION_MARK_TK) {
      setState(1264);
      exception_spec();
    }
    setState(1267);
    match(asn1Parser::RIGHT_PARENTHESIS_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Size_constraintContext ------------------------------------------------------------------

asn1Parser::Size_constraintContext::Size_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Size_constraintContext::SIZE_RW() {
  return getToken(asn1Parser::SIZE_RW, 0);
}

asn1Parser::ConstraintContext* asn1Parser::Size_constraintContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}


size_t asn1Parser::Size_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleSize_constraint;
}

void asn1Parser::Size_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSize_constraint(this);
}

void asn1Parser::Size_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSize_constraint(this);
}


antlrcpp::Any asn1Parser::Size_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSize_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Size_constraintContext* asn1Parser::size_constraint() {
  Size_constraintContext *_localctx = _tracker.createInstance<Size_constraintContext>(_ctx, getState());
  enterRule(_localctx, 272, asn1Parser::RuleSize_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1269);
    match(asn1Parser::SIZE_RW);
    setState(1270);
    constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constraint_specContext ------------------------------------------------------------------

asn1Parser::Constraint_specContext::Constraint_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Subtype_constraintContext* asn1Parser::Constraint_specContext::subtype_constraint() {
  return getRuleContext<asn1Parser::Subtype_constraintContext>(0);
}


size_t asn1Parser::Constraint_specContext::getRuleIndex() const {
  return asn1Parser::RuleConstraint_spec;
}

void asn1Parser::Constraint_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstraint_spec(this);
}

void asn1Parser::Constraint_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstraint_spec(this);
}


antlrcpp::Any asn1Parser::Constraint_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitConstraint_spec(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Constraint_specContext* asn1Parser::constraint_spec() {
  Constraint_specContext *_localctx = _tracker.createInstance<Constraint_specContext>(_ctx, getState());
  enterRule(_localctx, 274, asn1Parser::RuleConstraint_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1272);
    subtype_constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subtype_constraintContext ------------------------------------------------------------------

asn1Parser::Subtype_constraintContext::Subtype_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Element_set_specsContext* asn1Parser::Subtype_constraintContext::element_set_specs() {
  return getRuleContext<asn1Parser::Element_set_specsContext>(0);
}


size_t asn1Parser::Subtype_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleSubtype_constraint;
}

void asn1Parser::Subtype_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtype_constraint(this);
}

void asn1Parser::Subtype_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtype_constraint(this);
}


antlrcpp::Any asn1Parser::Subtype_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSubtype_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Subtype_constraintContext* asn1Parser::subtype_constraint() {
  Subtype_constraintContext *_localctx = _tracker.createInstance<Subtype_constraintContext>(_ctx, getState());
  enterRule(_localctx, 276, asn1Parser::RuleSubtype_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1274);
    element_set_specs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_set_specsContext ------------------------------------------------------------------

asn1Parser::Element_set_specsContext::Element_set_specsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Root_element_set_specContext* asn1Parser::Element_set_specsContext::root_element_set_spec() {
  return getRuleContext<asn1Parser::Root_element_set_specContext>(0);
}

std::vector<tree::TerminalNode *> asn1Parser::Element_set_specsContext::COMMA_TK() {
  return getTokens(asn1Parser::COMMA_TK);
}

tree::TerminalNode* asn1Parser::Element_set_specsContext::COMMA_TK(size_t i) {
  return getToken(asn1Parser::COMMA_TK, i);
}

tree::TerminalNode* asn1Parser::Element_set_specsContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}

asn1Parser::Additional_element_set_specContext* asn1Parser::Element_set_specsContext::additional_element_set_spec() {
  return getRuleContext<asn1Parser::Additional_element_set_specContext>(0);
}


size_t asn1Parser::Element_set_specsContext::getRuleIndex() const {
  return asn1Parser::RuleElement_set_specs;
}

void asn1Parser::Element_set_specsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_set_specs(this);
}

void asn1Parser::Element_set_specsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_set_specs(this);
}


antlrcpp::Any asn1Parser::Element_set_specsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitElement_set_specs(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Element_set_specsContext* asn1Parser::element_set_specs() {
  Element_set_specsContext *_localctx = _tracker.createInstance<Element_set_specsContext>(_ctx, getState());
  enterRule(_localctx, 278, asn1Parser::RuleElement_set_specs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1276);
      root_element_set_spec();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1277);
      root_element_set_spec();
      setState(1278);
      match(asn1Parser::COMMA_TK);
      setState(1279);
      match(asn1Parser::ELLIPSIS);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1281);
      root_element_set_spec();
      setState(1282);
      match(asn1Parser::COMMA_TK);
      setState(1283);
      match(asn1Parser::ELLIPSIS);
      setState(1284);
      match(asn1Parser::COMMA_TK);
      setState(1285);
      additional_element_set_spec();
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

//----------------- Root_element_set_specContext ------------------------------------------------------------------

asn1Parser::Root_element_set_specContext::Root_element_set_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Element_set_specContext* asn1Parser::Root_element_set_specContext::element_set_spec() {
  return getRuleContext<asn1Parser::Element_set_specContext>(0);
}


size_t asn1Parser::Root_element_set_specContext::getRuleIndex() const {
  return asn1Parser::RuleRoot_element_set_spec;
}

void asn1Parser::Root_element_set_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot_element_set_spec(this);
}

void asn1Parser::Root_element_set_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot_element_set_spec(this);
}


antlrcpp::Any asn1Parser::Root_element_set_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRoot_element_set_spec(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Root_element_set_specContext* asn1Parser::root_element_set_spec() {
  Root_element_set_specContext *_localctx = _tracker.createInstance<Root_element_set_specContext>(_ctx, getState());
  enterRule(_localctx, 280, asn1Parser::RuleRoot_element_set_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1289);
    element_set_spec();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Additional_element_set_specContext ------------------------------------------------------------------

asn1Parser::Additional_element_set_specContext::Additional_element_set_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Element_set_specContext* asn1Parser::Additional_element_set_specContext::element_set_spec() {
  return getRuleContext<asn1Parser::Element_set_specContext>(0);
}


size_t asn1Parser::Additional_element_set_specContext::getRuleIndex() const {
  return asn1Parser::RuleAdditional_element_set_spec;
}

void asn1Parser::Additional_element_set_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditional_element_set_spec(this);
}

void asn1Parser::Additional_element_set_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditional_element_set_spec(this);
}


antlrcpp::Any asn1Parser::Additional_element_set_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitAdditional_element_set_spec(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Additional_element_set_specContext* asn1Parser::additional_element_set_spec() {
  Additional_element_set_specContext *_localctx = _tracker.createInstance<Additional_element_set_specContext>(_ctx, getState());
  enterRule(_localctx, 282, asn1Parser::RuleAdditional_element_set_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1291);
    element_set_spec();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_set_specContext ------------------------------------------------------------------

asn1Parser::Element_set_specContext::Element_set_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::UnionsContext* asn1Parser::Element_set_specContext::unions() {
  return getRuleContext<asn1Parser::UnionsContext>(0);
}

tree::TerminalNode* asn1Parser::Element_set_specContext::ALL_RW() {
  return getToken(asn1Parser::ALL_RW, 0);
}

asn1Parser::ExclusionsContext* asn1Parser::Element_set_specContext::exclusions() {
  return getRuleContext<asn1Parser::ExclusionsContext>(0);
}


size_t asn1Parser::Element_set_specContext::getRuleIndex() const {
  return asn1Parser::RuleElement_set_spec;
}

void asn1Parser::Element_set_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement_set_spec(this);
}

void asn1Parser::Element_set_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement_set_spec(this);
}


antlrcpp::Any asn1Parser::Element_set_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitElement_set_spec(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Element_set_specContext* asn1Parser::element_set_spec() {
  Element_set_specContext *_localctx = _tracker.createInstance<Element_set_specContext>(_ctx, getState());
  enterRule(_localctx, 284, asn1Parser::RuleElement_set_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1296);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::T__0:
      case asn1Parser::T__1:
      case asn1Parser::T__2:
      case asn1Parser::T__3:
      case asn1Parser::T__4:
      case asn1Parser::T__5:
      case asn1Parser::T__6:
      case asn1Parser::T__7:
      case asn1Parser::T__8:
      case asn1Parser::T__9:
      case asn1Parser::T__10:
      case asn1Parser::T__11:
      case asn1Parser::T__12:
      case asn1Parser::T__13:
      case asn1Parser::T__14:
      case asn1Parser::T__15:
      case asn1Parser::BIT_RW:
      case asn1Parser::BOOLEAN_RW:
      case asn1Parser::CHARACTER_RW:
      case asn1Parser::CHOICE_RW:
      case asn1Parser::CONTAINING_RW:
      case asn1Parser::DATE_RW:
      case asn1Parser::DATE_TIME_RW:
      case asn1Parser::DURATION_RW:
      case asn1Parser::EMBEDDED_RW:
      case asn1Parser::ENUMERATED_RW:
      case asn1Parser::EXTERNAL_RW:
      case asn1Parser::FALSE_RW:
      case asn1Parser::FROM_RW:
      case asn1Parser::INCLUDES_RW:
      case asn1Parser::INTEGER_RW:
      case asn1Parser::MINUS_INFINITY_RW:
      case asn1Parser::MIN_RW:
      case asn1Parser::NOT_A_NUMBER_RW:
      case asn1Parser::NULL_RW:
      case asn1Parser::OBJECT_RW:
      case asn1Parser::OCTET_RW:
      case asn1Parser::OID_IRI_RW:
      case asn1Parser::PATTERN_RW:
      case asn1Parser::PLUS_INFINITY_RW:
      case asn1Parser::REAL_RW:
      case asn1Parser::RELATIVE_OID_IRI_RW:
      case asn1Parser::RELATIVE_OID_RW:
      case asn1Parser::SEQUENCE_RW:
      case asn1Parser::SETTINGS_RW:
      case asn1Parser::SET_RW:
      case asn1Parser::SIZE_RW:
      case asn1Parser::TIME_OF_DAY_RW:
      case asn1Parser::TIME_RW:
      case asn1Parser::TRUE_RW:
      case asn1Parser::WITH_RW:
      case asn1Parser::ANY_RW:
      case asn1Parser::QUOTATION_MARK_TK:
      case asn1Parser::LEFT_PARENTHESIS_TK:
      case asn1Parser::LEFT_SQUARE_BRACKET_TK:
      case asn1Parser::LEFT_CURLY_BRACKET_TK:
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER:
      case asn1Parser::NUMBER:
      case asn1Parser::REAL_NUMBER:
      case asn1Parser::BSTRING:
      case asn1Parser::HSTRING:
      case asn1Parser::CSTRING:
      case asn1Parser::TSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(1293);
        unions(0);
        break;
      }

      case asn1Parser::ALL_RW: {
        enterOuterAlt(_localctx, 2);
        setState(1294);
        match(asn1Parser::ALL_RW);
        setState(1295);
        exclusions();
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

//----------------- UnionsContext ------------------------------------------------------------------

asn1Parser::UnionsContext::UnionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::IntersectionsContext* asn1Parser::UnionsContext::intersections() {
  return getRuleContext<asn1Parser::IntersectionsContext>(0);
}

asn1Parser::UnionsContext* asn1Parser::UnionsContext::unions() {
  return getRuleContext<asn1Parser::UnionsContext>(0);
}

asn1Parser::Union_markContext* asn1Parser::UnionsContext::union_mark() {
  return getRuleContext<asn1Parser::Union_markContext>(0);
}


size_t asn1Parser::UnionsContext::getRuleIndex() const {
  return asn1Parser::RuleUnions;
}

void asn1Parser::UnionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnions(this);
}

void asn1Parser::UnionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnions(this);
}


antlrcpp::Any asn1Parser::UnionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUnions(this);
  else
    return visitor->visitChildren(this);
}


asn1Parser::UnionsContext* asn1Parser::unions() {
   return unions(0);
}

asn1Parser::UnionsContext* asn1Parser::unions(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  asn1Parser::UnionsContext *_localctx = _tracker.createInstance<UnionsContext>(_ctx, parentState);
  asn1Parser::UnionsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 286;
  enterRecursionRule(_localctx, 286, asn1Parser::RuleUnions, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1299);
    intersections();
    _ctx->stop = _input->LT(-1);
    setState(1307);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<UnionsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleUnions);
        setState(1301);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1302);
        union_mark();
        setState(1303);
        intersections(); 
      }
      setState(1309);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IntersectionsContext ------------------------------------------------------------------

asn1Parser::IntersectionsContext::IntersectionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Intersection_elementsContext *> asn1Parser::IntersectionsContext::intersection_elements() {
  return getRuleContexts<asn1Parser::Intersection_elementsContext>();
}

asn1Parser::Intersection_elementsContext* asn1Parser::IntersectionsContext::intersection_elements(size_t i) {
  return getRuleContext<asn1Parser::Intersection_elementsContext>(i);
}

asn1Parser::Intersection_markContext* asn1Parser::IntersectionsContext::intersection_mark() {
  return getRuleContext<asn1Parser::Intersection_markContext>(0);
}


size_t asn1Parser::IntersectionsContext::getRuleIndex() const {
  return asn1Parser::RuleIntersections;
}

void asn1Parser::IntersectionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntersections(this);
}

void asn1Parser::IntersectionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntersections(this);
}


antlrcpp::Any asn1Parser::IntersectionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIntersections(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::IntersectionsContext* asn1Parser::intersections() {
  IntersectionsContext *_localctx = _tracker.createInstance<IntersectionsContext>(_ctx, getState());
  enterRule(_localctx, 288, asn1Parser::RuleIntersections);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1310);
      intersection_elements();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1311);
      intersection_elements();
      setState(1312);
      intersection_mark();
      setState(1313);
      intersection_elements();
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

//----------------- Intersection_elementsContext ------------------------------------------------------------------

asn1Parser::Intersection_elementsContext::Intersection_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ElementsContext* asn1Parser::Intersection_elementsContext::elements() {
  return getRuleContext<asn1Parser::ElementsContext>(0);
}

asn1Parser::ElemsContext* asn1Parser::Intersection_elementsContext::elems() {
  return getRuleContext<asn1Parser::ElemsContext>(0);
}

asn1Parser::ExclusionsContext* asn1Parser::Intersection_elementsContext::exclusions() {
  return getRuleContext<asn1Parser::ExclusionsContext>(0);
}


size_t asn1Parser::Intersection_elementsContext::getRuleIndex() const {
  return asn1Parser::RuleIntersection_elements;
}

void asn1Parser::Intersection_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntersection_elements(this);
}

void asn1Parser::Intersection_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntersection_elements(this);
}


antlrcpp::Any asn1Parser::Intersection_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIntersection_elements(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Intersection_elementsContext* asn1Parser::intersection_elements() {
  Intersection_elementsContext *_localctx = _tracker.createInstance<Intersection_elementsContext>(_ctx, getState());
  enterRule(_localctx, 290, asn1Parser::RuleIntersection_elements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1321);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1317);
      elements();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1318);
      elems();
      setState(1319);
      exclusions();
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

//----------------- ElemsContext ------------------------------------------------------------------

asn1Parser::ElemsContext::ElemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ElementsContext* asn1Parser::ElemsContext::elements() {
  return getRuleContext<asn1Parser::ElementsContext>(0);
}


size_t asn1Parser::ElemsContext::getRuleIndex() const {
  return asn1Parser::RuleElems;
}

void asn1Parser::ElemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElems(this);
}

void asn1Parser::ElemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElems(this);
}


antlrcpp::Any asn1Parser::ElemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitElems(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ElemsContext* asn1Parser::elems() {
  ElemsContext *_localctx = _tracker.createInstance<ElemsContext>(_ctx, getState());
  enterRule(_localctx, 292, asn1Parser::RuleElems);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1323);
    elements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExclusionsContext ------------------------------------------------------------------

asn1Parser::ExclusionsContext::ExclusionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::ExclusionsContext::EXCEPT_RW() {
  return getToken(asn1Parser::EXCEPT_RW, 0);
}

asn1Parser::ElementsContext* asn1Parser::ExclusionsContext::elements() {
  return getRuleContext<asn1Parser::ElementsContext>(0);
}


size_t asn1Parser::ExclusionsContext::getRuleIndex() const {
  return asn1Parser::RuleExclusions;
}

void asn1Parser::ExclusionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusions(this);
}

void asn1Parser::ExclusionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusions(this);
}


antlrcpp::Any asn1Parser::ExclusionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitExclusions(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ExclusionsContext* asn1Parser::exclusions() {
  ExclusionsContext *_localctx = _tracker.createInstance<ExclusionsContext>(_ctx, getState());
  enterRule(_localctx, 294, asn1Parser::RuleExclusions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1325);
    match(asn1Parser::EXCEPT_RW);
    setState(1326);
    elements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Union_markContext ------------------------------------------------------------------

asn1Parser::Union_markContext::Union_markContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Union_markContext::VERTICAL_LINE_TK() {
  return getToken(asn1Parser::VERTICAL_LINE_TK, 0);
}

tree::TerminalNode* asn1Parser::Union_markContext::UNION_RW() {
  return getToken(asn1Parser::UNION_RW, 0);
}


size_t asn1Parser::Union_markContext::getRuleIndex() const {
  return asn1Parser::RuleUnion_mark;
}

void asn1Parser::Union_markContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnion_mark(this);
}

void asn1Parser::Union_markContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnion_mark(this);
}


antlrcpp::Any asn1Parser::Union_markContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUnion_mark(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Union_markContext* asn1Parser::union_mark() {
  Union_markContext *_localctx = _tracker.createInstance<Union_markContext>(_ctx, getState());
  enterRule(_localctx, 296, asn1Parser::RuleUnion_mark);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1328);
    _la = _input->LA(1);
    if (!(_la == asn1Parser::UNION_RW

    || _la == asn1Parser::VERTICAL_LINE_TK)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Intersection_markContext ------------------------------------------------------------------

asn1Parser::Intersection_markContext::Intersection_markContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Intersection_markContext::CIRCUMFLEX_ACCENT_TK() {
  return getToken(asn1Parser::CIRCUMFLEX_ACCENT_TK, 0);
}

tree::TerminalNode* asn1Parser::Intersection_markContext::INTERSECTION_RW() {
  return getToken(asn1Parser::INTERSECTION_RW, 0);
}


size_t asn1Parser::Intersection_markContext::getRuleIndex() const {
  return asn1Parser::RuleIntersection_mark;
}

void asn1Parser::Intersection_markContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntersection_mark(this);
}

void asn1Parser::Intersection_markContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntersection_mark(this);
}


antlrcpp::Any asn1Parser::Intersection_markContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIntersection_mark(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Intersection_markContext* asn1Parser::intersection_mark() {
  Intersection_markContext *_localctx = _tracker.createInstance<Intersection_markContext>(_ctx, getState());
  enterRule(_localctx, 298, asn1Parser::RuleIntersection_mark);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1330);
    _la = _input->LA(1);
    if (!(_la == asn1Parser::INTERSECTION_RW

    || _la == asn1Parser::CIRCUMFLEX_ACCENT_TK)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementsContext ------------------------------------------------------------------

asn1Parser::ElementsContext::ElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Subtype_elementsContext* asn1Parser::ElementsContext::subtype_elements() {
  return getRuleContext<asn1Parser::Subtype_elementsContext>(0);
}

tree::TerminalNode* asn1Parser::ElementsContext::LEFT_PARENTHESIS_TK() {
  return getToken(asn1Parser::LEFT_PARENTHESIS_TK, 0);
}

asn1Parser::Element_set_specContext* asn1Parser::ElementsContext::element_set_spec() {
  return getRuleContext<asn1Parser::Element_set_specContext>(0);
}

tree::TerminalNode* asn1Parser::ElementsContext::RIGHT_PARENTHESIS_TK() {
  return getToken(asn1Parser::RIGHT_PARENTHESIS_TK, 0);
}


size_t asn1Parser::ElementsContext::getRuleIndex() const {
  return asn1Parser::RuleElements;
}

void asn1Parser::ElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElements(this);
}

void asn1Parser::ElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElements(this);
}


antlrcpp::Any asn1Parser::ElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitElements(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::ElementsContext* asn1Parser::elements() {
  ElementsContext *_localctx = _tracker.createInstance<ElementsContext>(_ctx, getState());
  enterRule(_localctx, 300, asn1Parser::RuleElements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1337);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::T__0:
      case asn1Parser::T__1:
      case asn1Parser::T__2:
      case asn1Parser::T__3:
      case asn1Parser::T__4:
      case asn1Parser::T__5:
      case asn1Parser::T__6:
      case asn1Parser::T__7:
      case asn1Parser::T__8:
      case asn1Parser::T__9:
      case asn1Parser::T__10:
      case asn1Parser::T__11:
      case asn1Parser::T__12:
      case asn1Parser::T__13:
      case asn1Parser::T__14:
      case asn1Parser::T__15:
      case asn1Parser::BIT_RW:
      case asn1Parser::BOOLEAN_RW:
      case asn1Parser::CHARACTER_RW:
      case asn1Parser::CHOICE_RW:
      case asn1Parser::CONTAINING_RW:
      case asn1Parser::DATE_RW:
      case asn1Parser::DATE_TIME_RW:
      case asn1Parser::DURATION_RW:
      case asn1Parser::EMBEDDED_RW:
      case asn1Parser::ENUMERATED_RW:
      case asn1Parser::EXTERNAL_RW:
      case asn1Parser::FALSE_RW:
      case asn1Parser::FROM_RW:
      case asn1Parser::INCLUDES_RW:
      case asn1Parser::INTEGER_RW:
      case asn1Parser::MINUS_INFINITY_RW:
      case asn1Parser::MIN_RW:
      case asn1Parser::NOT_A_NUMBER_RW:
      case asn1Parser::NULL_RW:
      case asn1Parser::OBJECT_RW:
      case asn1Parser::OCTET_RW:
      case asn1Parser::OID_IRI_RW:
      case asn1Parser::PATTERN_RW:
      case asn1Parser::PLUS_INFINITY_RW:
      case asn1Parser::REAL_RW:
      case asn1Parser::RELATIVE_OID_IRI_RW:
      case asn1Parser::RELATIVE_OID_RW:
      case asn1Parser::SEQUENCE_RW:
      case asn1Parser::SETTINGS_RW:
      case asn1Parser::SET_RW:
      case asn1Parser::SIZE_RW:
      case asn1Parser::TIME_OF_DAY_RW:
      case asn1Parser::TIME_RW:
      case asn1Parser::TRUE_RW:
      case asn1Parser::WITH_RW:
      case asn1Parser::ANY_RW:
      case asn1Parser::QUOTATION_MARK_TK:
      case asn1Parser::LEFT_SQUARE_BRACKET_TK:
      case asn1Parser::LEFT_CURLY_BRACKET_TK:
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER:
      case asn1Parser::NUMBER:
      case asn1Parser::REAL_NUMBER:
      case asn1Parser::BSTRING:
      case asn1Parser::HSTRING:
      case asn1Parser::CSTRING:
      case asn1Parser::TSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(1332);
        subtype_elements();
        break;
      }

      case asn1Parser::LEFT_PARENTHESIS_TK: {
        enterOuterAlt(_localctx, 2);
        setState(1333);
        match(asn1Parser::LEFT_PARENTHESIS_TK);
        setState(1334);
        element_set_spec();
        setState(1335);
        match(asn1Parser::RIGHT_PARENTHESIS_TK);
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

//----------------- Subtype_elementsContext ------------------------------------------------------------------

asn1Parser::Subtype_elementsContext::Subtype_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Single_valueContext* asn1Parser::Subtype_elementsContext::single_value() {
  return getRuleContext<asn1Parser::Single_valueContext>(0);
}

asn1Parser::Contained_subtypeContext* asn1Parser::Subtype_elementsContext::contained_subtype() {
  return getRuleContext<asn1Parser::Contained_subtypeContext>(0);
}

asn1Parser::Value_rangeContext* asn1Parser::Subtype_elementsContext::value_range() {
  return getRuleContext<asn1Parser::Value_rangeContext>(0);
}

asn1Parser::Permitted_alphabetContext* asn1Parser::Subtype_elementsContext::permitted_alphabet() {
  return getRuleContext<asn1Parser::Permitted_alphabetContext>(0);
}

asn1Parser::Size_constraintContext* asn1Parser::Subtype_elementsContext::size_constraint() {
  return getRuleContext<asn1Parser::Size_constraintContext>(0);
}

asn1Parser::Type_constraintContext* asn1Parser::Subtype_elementsContext::type_constraint() {
  return getRuleContext<asn1Parser::Type_constraintContext>(0);
}

asn1Parser::Inner_type_constraintsContext* asn1Parser::Subtype_elementsContext::inner_type_constraints() {
  return getRuleContext<asn1Parser::Inner_type_constraintsContext>(0);
}

asn1Parser::Pattern_constraintContext* asn1Parser::Subtype_elementsContext::pattern_constraint() {
  return getRuleContext<asn1Parser::Pattern_constraintContext>(0);
}

asn1Parser::Property_settingsContext* asn1Parser::Subtype_elementsContext::property_settings() {
  return getRuleContext<asn1Parser::Property_settingsContext>(0);
}

asn1Parser::Duration_rangeContext* asn1Parser::Subtype_elementsContext::duration_range() {
  return getRuleContext<asn1Parser::Duration_rangeContext>(0);
}

asn1Parser::Time_point_rangeContext* asn1Parser::Subtype_elementsContext::time_point_range() {
  return getRuleContext<asn1Parser::Time_point_rangeContext>(0);
}

asn1Parser::Recurrence_rangeContext* asn1Parser::Subtype_elementsContext::recurrence_range() {
  return getRuleContext<asn1Parser::Recurrence_rangeContext>(0);
}


size_t asn1Parser::Subtype_elementsContext::getRuleIndex() const {
  return asn1Parser::RuleSubtype_elements;
}

void asn1Parser::Subtype_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtype_elements(this);
}

void asn1Parser::Subtype_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtype_elements(this);
}


antlrcpp::Any asn1Parser::Subtype_elementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSubtype_elements(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Subtype_elementsContext* asn1Parser::subtype_elements() {
  Subtype_elementsContext *_localctx = _tracker.createInstance<Subtype_elementsContext>(_ctx, getState());
  enterRule(_localctx, 302, asn1Parser::RuleSubtype_elements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1339);
      single_value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1340);
      contained_subtype();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1341);
      value_range();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1342);
      permitted_alphabet();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1343);
      size_constraint();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1344);
      type_constraint();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1345);
      inner_type_constraints();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1346);
      pattern_constraint();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1347);
      property_settings();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1348);
      duration_range();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1349);
      time_point_range();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(1350);
      recurrence_range();
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

//----------------- Single_valueContext ------------------------------------------------------------------

asn1Parser::Single_valueContext::Single_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ValueContext* asn1Parser::Single_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Single_valueContext::getRuleIndex() const {
  return asn1Parser::RuleSingle_value;
}

void asn1Parser::Single_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_value(this);
}

void asn1Parser::Single_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_value(this);
}


antlrcpp::Any asn1Parser::Single_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSingle_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Single_valueContext* asn1Parser::single_value() {
  Single_valueContext *_localctx = _tracker.createInstance<Single_valueContext>(_ctx, getState());
  enterRule(_localctx, 304, asn1Parser::RuleSingle_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1353);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Contained_subtypeContext ------------------------------------------------------------------

asn1Parser::Contained_subtypeContext::Contained_subtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::TypeContext* asn1Parser::Contained_subtypeContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

asn1Parser::IncludesContext* asn1Parser::Contained_subtypeContext::includes() {
  return getRuleContext<asn1Parser::IncludesContext>(0);
}


size_t asn1Parser::Contained_subtypeContext::getRuleIndex() const {
  return asn1Parser::RuleContained_subtype;
}

void asn1Parser::Contained_subtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContained_subtype(this);
}

void asn1Parser::Contained_subtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContained_subtype(this);
}


antlrcpp::Any asn1Parser::Contained_subtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitContained_subtype(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Contained_subtypeContext* asn1Parser::contained_subtype() {
  Contained_subtypeContext *_localctx = _tracker.createInstance<Contained_subtypeContext>(_ctx, getState());
  enterRule(_localctx, 306, asn1Parser::RuleContained_subtype);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1356);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::INCLUDES_RW) {
      setState(1355);
      includes();
    }
    setState(1358);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludesContext ------------------------------------------------------------------

asn1Parser::IncludesContext::IncludesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::IncludesContext::INCLUDES_RW() {
  return getToken(asn1Parser::INCLUDES_RW, 0);
}


size_t asn1Parser::IncludesContext::getRuleIndex() const {
  return asn1Parser::RuleIncludes;
}

void asn1Parser::IncludesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncludes(this);
}

void asn1Parser::IncludesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncludes(this);
}


antlrcpp::Any asn1Parser::IncludesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitIncludes(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::IncludesContext* asn1Parser::includes() {
  IncludesContext *_localctx = _tracker.createInstance<IncludesContext>(_ctx, getState());
  enterRule(_localctx, 308, asn1Parser::RuleIncludes);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1360);
    match(asn1Parser::INCLUDES_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_rangeContext ------------------------------------------------------------------

asn1Parser::Value_rangeContext::Value_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Lower_endpointContext* asn1Parser::Value_rangeContext::lower_endpoint() {
  return getRuleContext<asn1Parser::Lower_endpointContext>(0);
}

tree::TerminalNode* asn1Parser::Value_rangeContext::RANGE_SEPARATOR() {
  return getToken(asn1Parser::RANGE_SEPARATOR, 0);
}

asn1Parser::Upper_endpointContext* asn1Parser::Value_rangeContext::upper_endpoint() {
  return getRuleContext<asn1Parser::Upper_endpointContext>(0);
}


size_t asn1Parser::Value_rangeContext::getRuleIndex() const {
  return asn1Parser::RuleValue_range;
}

void asn1Parser::Value_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_range(this);
}

void asn1Parser::Value_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_range(this);
}


antlrcpp::Any asn1Parser::Value_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_range(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_rangeContext* asn1Parser::value_range() {
  Value_rangeContext *_localctx = _tracker.createInstance<Value_rangeContext>(_ctx, getState());
  enterRule(_localctx, 310, asn1Parser::RuleValue_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1362);
    lower_endpoint();
    setState(1363);
    match(asn1Parser::RANGE_SEPARATOR);
    setState(1364);
    upper_endpoint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lower_endpointContext ------------------------------------------------------------------

asn1Parser::Lower_endpointContext::Lower_endpointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Lower_end_valueContext* asn1Parser::Lower_endpointContext::lower_end_value() {
  return getRuleContext<asn1Parser::Lower_end_valueContext>(0);
}

tree::TerminalNode* asn1Parser::Lower_endpointContext::LESS_THAN_SIGN_TK() {
  return getToken(asn1Parser::LESS_THAN_SIGN_TK, 0);
}


size_t asn1Parser::Lower_endpointContext::getRuleIndex() const {
  return asn1Parser::RuleLower_endpoint;
}

void asn1Parser::Lower_endpointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_endpoint(this);
}

void asn1Parser::Lower_endpointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_endpoint(this);
}


antlrcpp::Any asn1Parser::Lower_endpointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitLower_endpoint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Lower_endpointContext* asn1Parser::lower_endpoint() {
  Lower_endpointContext *_localctx = _tracker.createInstance<Lower_endpointContext>(_ctx, getState());
  enterRule(_localctx, 312, asn1Parser::RuleLower_endpoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1370);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1366);
      lower_end_value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1367);
      lower_end_value();
      setState(1368);
      match(asn1Parser::LESS_THAN_SIGN_TK);
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

//----------------- Upper_endpointContext ------------------------------------------------------------------

asn1Parser::Upper_endpointContext::Upper_endpointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Upper_end_valueContext* asn1Parser::Upper_endpointContext::upper_end_value() {
  return getRuleContext<asn1Parser::Upper_end_valueContext>(0);
}

tree::TerminalNode* asn1Parser::Upper_endpointContext::LESS_THAN_SIGN_TK() {
  return getToken(asn1Parser::LESS_THAN_SIGN_TK, 0);
}


size_t asn1Parser::Upper_endpointContext::getRuleIndex() const {
  return asn1Parser::RuleUpper_endpoint;
}

void asn1Parser::Upper_endpointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_endpoint(this);
}

void asn1Parser::Upper_endpointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_endpoint(this);
}


antlrcpp::Any asn1Parser::Upper_endpointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUpper_endpoint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Upper_endpointContext* asn1Parser::upper_endpoint() {
  Upper_endpointContext *_localctx = _tracker.createInstance<Upper_endpointContext>(_ctx, getState());
  enterRule(_localctx, 314, asn1Parser::RuleUpper_endpoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1375);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::CONTAINING_RW:
      case asn1Parser::FALSE_RW:
      case asn1Parser::MAX_RW:
      case asn1Parser::MINUS_INFINITY_RW:
      case asn1Parser::NOT_A_NUMBER_RW:
      case asn1Parser::NULL_RW:
      case asn1Parser::PLUS_INFINITY_RW:
      case asn1Parser::TRUE_RW:
      case asn1Parser::QUOTATION_MARK_TK:
      case asn1Parser::LEFT_CURLY_BRACKET_TK:
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER:
      case asn1Parser::NUMBER:
      case asn1Parser::REAL_NUMBER:
      case asn1Parser::BSTRING:
      case asn1Parser::HSTRING:
      case asn1Parser::CSTRING:
      case asn1Parser::TSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(1372);
        upper_end_value();
        break;
      }

      case asn1Parser::LESS_THAN_SIGN_TK: {
        enterOuterAlt(_localctx, 2);
        setState(1373);
        match(asn1Parser::LESS_THAN_SIGN_TK);
        setState(1374);
        upper_end_value();
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

//----------------- Lower_end_valueContext ------------------------------------------------------------------

asn1Parser::Lower_end_valueContext::Lower_end_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ValueContext* asn1Parser::Lower_end_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}

tree::TerminalNode* asn1Parser::Lower_end_valueContext::MIN_RW() {
  return getToken(asn1Parser::MIN_RW, 0);
}


size_t asn1Parser::Lower_end_valueContext::getRuleIndex() const {
  return asn1Parser::RuleLower_end_value;
}

void asn1Parser::Lower_end_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_end_value(this);
}

void asn1Parser::Lower_end_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_end_value(this);
}


antlrcpp::Any asn1Parser::Lower_end_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitLower_end_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Lower_end_valueContext* asn1Parser::lower_end_value() {
  Lower_end_valueContext *_localctx = _tracker.createInstance<Lower_end_valueContext>(_ctx, getState());
  enterRule(_localctx, 316, asn1Parser::RuleLower_end_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1379);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::CONTAINING_RW:
      case asn1Parser::FALSE_RW:
      case asn1Parser::MINUS_INFINITY_RW:
      case asn1Parser::NOT_A_NUMBER_RW:
      case asn1Parser::NULL_RW:
      case asn1Parser::PLUS_INFINITY_RW:
      case asn1Parser::TRUE_RW:
      case asn1Parser::QUOTATION_MARK_TK:
      case asn1Parser::LEFT_CURLY_BRACKET_TK:
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER:
      case asn1Parser::NUMBER:
      case asn1Parser::REAL_NUMBER:
      case asn1Parser::BSTRING:
      case asn1Parser::HSTRING:
      case asn1Parser::CSTRING:
      case asn1Parser::TSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(1377);
        value();
        break;
      }

      case asn1Parser::MIN_RW: {
        enterOuterAlt(_localctx, 2);
        setState(1378);
        match(asn1Parser::MIN_RW);
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

//----------------- Upper_end_valueContext ------------------------------------------------------------------

asn1Parser::Upper_end_valueContext::Upper_end_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ValueContext* asn1Parser::Upper_end_valueContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}

tree::TerminalNode* asn1Parser::Upper_end_valueContext::MAX_RW() {
  return getToken(asn1Parser::MAX_RW, 0);
}


size_t asn1Parser::Upper_end_valueContext::getRuleIndex() const {
  return asn1Parser::RuleUpper_end_value;
}

void asn1Parser::Upper_end_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_end_value(this);
}

void asn1Parser::Upper_end_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_end_value(this);
}


antlrcpp::Any asn1Parser::Upper_end_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitUpper_end_value(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Upper_end_valueContext* asn1Parser::upper_end_value() {
  Upper_end_valueContext *_localctx = _tracker.createInstance<Upper_end_valueContext>(_ctx, getState());
  enterRule(_localctx, 318, asn1Parser::RuleUpper_end_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case asn1Parser::CONTAINING_RW:
      case asn1Parser::FALSE_RW:
      case asn1Parser::MINUS_INFINITY_RW:
      case asn1Parser::NOT_A_NUMBER_RW:
      case asn1Parser::NULL_RW:
      case asn1Parser::PLUS_INFINITY_RW:
      case asn1Parser::TRUE_RW:
      case asn1Parser::QUOTATION_MARK_TK:
      case asn1Parser::LEFT_CURLY_BRACKET_TK:
      case asn1Parser::HYPHEN_TK:
      case asn1Parser::TYPE_REFERENCE_OR_MODULE_REFERENCE:
      case asn1Parser::IDENTIFIER:
      case asn1Parser::NUMBER:
      case asn1Parser::REAL_NUMBER:
      case asn1Parser::BSTRING:
      case asn1Parser::HSTRING:
      case asn1Parser::CSTRING:
      case asn1Parser::TSTRING: {
        enterOuterAlt(_localctx, 1);
        setState(1381);
        value();
        break;
      }

      case asn1Parser::MAX_RW: {
        enterOuterAlt(_localctx, 2);
        setState(1382);
        match(asn1Parser::MAX_RW);
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

//----------------- Type_constraintContext ------------------------------------------------------------------

asn1Parser::Type_constraintContext::Type_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::TypeContext* asn1Parser::Type_constraintContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}


size_t asn1Parser::Type_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleType_constraint;
}

void asn1Parser::Type_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_constraint(this);
}

void asn1Parser::Type_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_constraint(this);
}


antlrcpp::Any asn1Parser::Type_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitType_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Type_constraintContext* asn1Parser::type_constraint() {
  Type_constraintContext *_localctx = _tracker.createInstance<Type_constraintContext>(_ctx, getState());
  enterRule(_localctx, 320, asn1Parser::RuleType_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1385);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Permitted_alphabetContext ------------------------------------------------------------------

asn1Parser::Permitted_alphabetContext::Permitted_alphabetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Permitted_alphabetContext::FROM_RW() {
  return getToken(asn1Parser::FROM_RW, 0);
}

asn1Parser::ConstraintContext* asn1Parser::Permitted_alphabetContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}


size_t asn1Parser::Permitted_alphabetContext::getRuleIndex() const {
  return asn1Parser::RulePermitted_alphabet;
}

void asn1Parser::Permitted_alphabetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPermitted_alphabet(this);
}

void asn1Parser::Permitted_alphabetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPermitted_alphabet(this);
}


antlrcpp::Any asn1Parser::Permitted_alphabetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPermitted_alphabet(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Permitted_alphabetContext* asn1Parser::permitted_alphabet() {
  Permitted_alphabetContext *_localctx = _tracker.createInstance<Permitted_alphabetContext>(_ctx, getState());
  enterRule(_localctx, 322, asn1Parser::RulePermitted_alphabet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1387);
    match(asn1Parser::FROM_RW);
    setState(1388);
    constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Inner_type_constraintsContext ------------------------------------------------------------------

asn1Parser::Inner_type_constraintsContext::Inner_type_constraintsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Inner_type_constraintsContext::WITH_RW() {
  return getToken(asn1Parser::WITH_RW, 0);
}

tree::TerminalNode* asn1Parser::Inner_type_constraintsContext::COMPONENT_RW() {
  return getToken(asn1Parser::COMPONENT_RW, 0);
}

asn1Parser::Single_type_constraintContext* asn1Parser::Inner_type_constraintsContext::single_type_constraint() {
  return getRuleContext<asn1Parser::Single_type_constraintContext>(0);
}

tree::TerminalNode* asn1Parser::Inner_type_constraintsContext::COMPONENTS_RW() {
  return getToken(asn1Parser::COMPONENTS_RW, 0);
}

asn1Parser::Multiple_type_constraintsContext* asn1Parser::Inner_type_constraintsContext::multiple_type_constraints() {
  return getRuleContext<asn1Parser::Multiple_type_constraintsContext>(0);
}


size_t asn1Parser::Inner_type_constraintsContext::getRuleIndex() const {
  return asn1Parser::RuleInner_type_constraints;
}

void asn1Parser::Inner_type_constraintsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInner_type_constraints(this);
}

void asn1Parser::Inner_type_constraintsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInner_type_constraints(this);
}


antlrcpp::Any asn1Parser::Inner_type_constraintsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitInner_type_constraints(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Inner_type_constraintsContext* asn1Parser::inner_type_constraints() {
  Inner_type_constraintsContext *_localctx = _tracker.createInstance<Inner_type_constraintsContext>(_ctx, getState());
  enterRule(_localctx, 324, asn1Parser::RuleInner_type_constraints);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1390);
      match(asn1Parser::WITH_RW);
      setState(1391);
      match(asn1Parser::COMPONENT_RW);
      setState(1392);
      single_type_constraint();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1393);
      match(asn1Parser::WITH_RW);
      setState(1394);
      match(asn1Parser::COMPONENTS_RW);
      setState(1395);
      multiple_type_constraints();
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

//----------------- Single_type_constraintContext ------------------------------------------------------------------

asn1Parser::Single_type_constraintContext::Single_type_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ConstraintContext* asn1Parser::Single_type_constraintContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}


size_t asn1Parser::Single_type_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleSingle_type_constraint;
}

void asn1Parser::Single_type_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_type_constraint(this);
}

void asn1Parser::Single_type_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_type_constraint(this);
}


antlrcpp::Any asn1Parser::Single_type_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSingle_type_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Single_type_constraintContext* asn1Parser::single_type_constraint() {
  Single_type_constraintContext *_localctx = _tracker.createInstance<Single_type_constraintContext>(_ctx, getState());
  enterRule(_localctx, 326, asn1Parser::RuleSingle_type_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1398);
    constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiple_type_constraintsContext ------------------------------------------------------------------

asn1Parser::Multiple_type_constraintsContext::Multiple_type_constraintsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Full_specificationContext* asn1Parser::Multiple_type_constraintsContext::full_specification() {
  return getRuleContext<asn1Parser::Full_specificationContext>(0);
}

asn1Parser::Partial_specificationContext* asn1Parser::Multiple_type_constraintsContext::partial_specification() {
  return getRuleContext<asn1Parser::Partial_specificationContext>(0);
}


size_t asn1Parser::Multiple_type_constraintsContext::getRuleIndex() const {
  return asn1Parser::RuleMultiple_type_constraints;
}

void asn1Parser::Multiple_type_constraintsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiple_type_constraints(this);
}

void asn1Parser::Multiple_type_constraintsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiple_type_constraints(this);
}


antlrcpp::Any asn1Parser::Multiple_type_constraintsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitMultiple_type_constraints(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Multiple_type_constraintsContext* asn1Parser::multiple_type_constraints() {
  Multiple_type_constraintsContext *_localctx = _tracker.createInstance<Multiple_type_constraintsContext>(_ctx, getState());
  enterRule(_localctx, 328, asn1Parser::RuleMultiple_type_constraints);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1400);
      full_specification();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1401);
      partial_specification();
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

//----------------- Full_specificationContext ------------------------------------------------------------------

asn1Parser::Full_specificationContext::Full_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Full_specificationContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

asn1Parser::Type_constraintsContext* asn1Parser::Full_specificationContext::type_constraints() {
  return getRuleContext<asn1Parser::Type_constraintsContext>(0);
}

tree::TerminalNode* asn1Parser::Full_specificationContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Full_specificationContext::getRuleIndex() const {
  return asn1Parser::RuleFull_specification;
}

void asn1Parser::Full_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFull_specification(this);
}

void asn1Parser::Full_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFull_specification(this);
}


antlrcpp::Any asn1Parser::Full_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitFull_specification(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Full_specificationContext* asn1Parser::full_specification() {
  Full_specificationContext *_localctx = _tracker.createInstance<Full_specificationContext>(_ctx, getState());
  enterRule(_localctx, 330, asn1Parser::RuleFull_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1404);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1405);
    type_constraints();
    setState(1406);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Partial_specificationContext ------------------------------------------------------------------

asn1Parser::Partial_specificationContext::Partial_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Partial_specificationContext::LEFT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::LEFT_CURLY_BRACKET_TK, 0);
}

tree::TerminalNode* asn1Parser::Partial_specificationContext::ELLIPSIS() {
  return getToken(asn1Parser::ELLIPSIS, 0);
}

tree::TerminalNode* asn1Parser::Partial_specificationContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Type_constraintsContext* asn1Parser::Partial_specificationContext::type_constraints() {
  return getRuleContext<asn1Parser::Type_constraintsContext>(0);
}

tree::TerminalNode* asn1Parser::Partial_specificationContext::RIGHT_CURLY_BRACKET_TK() {
  return getToken(asn1Parser::RIGHT_CURLY_BRACKET_TK, 0);
}


size_t asn1Parser::Partial_specificationContext::getRuleIndex() const {
  return asn1Parser::RulePartial_specification;
}

void asn1Parser::Partial_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPartial_specification(this);
}

void asn1Parser::Partial_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPartial_specification(this);
}


antlrcpp::Any asn1Parser::Partial_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPartial_specification(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Partial_specificationContext* asn1Parser::partial_specification() {
  Partial_specificationContext *_localctx = _tracker.createInstance<Partial_specificationContext>(_ctx, getState());
  enterRule(_localctx, 332, asn1Parser::RulePartial_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1408);
    match(asn1Parser::LEFT_CURLY_BRACKET_TK);
    setState(1409);
    match(asn1Parser::ELLIPSIS);
    setState(1410);
    match(asn1Parser::COMMA_TK);
    setState(1411);
    type_constraints();
    setState(1412);
    match(asn1Parser::RIGHT_CURLY_BRACKET_TK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_constraintsContext ------------------------------------------------------------------

asn1Parser::Type_constraintsContext::Type_constraintsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Named_constraintContext* asn1Parser::Type_constraintsContext::named_constraint() {
  return getRuleContext<asn1Parser::Named_constraintContext>(0);
}

tree::TerminalNode* asn1Parser::Type_constraintsContext::COMMA_TK() {
  return getToken(asn1Parser::COMMA_TK, 0);
}

asn1Parser::Type_constraintsContext* asn1Parser::Type_constraintsContext::type_constraints() {
  return getRuleContext<asn1Parser::Type_constraintsContext>(0);
}


size_t asn1Parser::Type_constraintsContext::getRuleIndex() const {
  return asn1Parser::RuleType_constraints;
}

void asn1Parser::Type_constraintsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_constraints(this);
}

void asn1Parser::Type_constraintsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_constraints(this);
}


antlrcpp::Any asn1Parser::Type_constraintsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitType_constraints(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Type_constraintsContext* asn1Parser::type_constraints() {
  Type_constraintsContext *_localctx = _tracker.createInstance<Type_constraintsContext>(_ctx, getState());
  enterRule(_localctx, 334, asn1Parser::RuleType_constraints);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1419);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1414);
      named_constraint();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1415);
      named_constraint();
      setState(1416);
      match(asn1Parser::COMMA_TK);
      setState(1417);
      type_constraints();
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

//----------------- Named_constraintContext ------------------------------------------------------------------

asn1Parser::Named_constraintContext::Named_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Named_constraintContext::IDENTIFIER() {
  return getToken(asn1Parser::IDENTIFIER, 0);
}

asn1Parser::Component_constraintContext* asn1Parser::Named_constraintContext::component_constraint() {
  return getRuleContext<asn1Parser::Component_constraintContext>(0);
}


size_t asn1Parser::Named_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleNamed_constraint;
}

void asn1Parser::Named_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamed_constraint(this);
}

void asn1Parser::Named_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamed_constraint(this);
}


antlrcpp::Any asn1Parser::Named_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitNamed_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Named_constraintContext* asn1Parser::named_constraint() {
  Named_constraintContext *_localctx = _tracker.createInstance<Named_constraintContext>(_ctx, getState());
  enterRule(_localctx, 336, asn1Parser::RuleNamed_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1421);
    match(asn1Parser::IDENTIFIER);
    setState(1423);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == asn1Parser::ABSENT_RW

    || _la == asn1Parser::OPTIONAL_RW || _la == asn1Parser::PRESENT_RW

    || _la == asn1Parser::LEFT_PARENTHESIS_TK) {
      setState(1422);
      component_constraint();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_constraintContext ------------------------------------------------------------------

asn1Parser::Component_constraintContext::Component_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Value_constraintContext* asn1Parser::Component_constraintContext::value_constraint() {
  return getRuleContext<asn1Parser::Value_constraintContext>(0);
}

asn1Parser::Presence_constraintContext* asn1Parser::Component_constraintContext::presence_constraint() {
  return getRuleContext<asn1Parser::Presence_constraintContext>(0);
}


size_t asn1Parser::Component_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleComponent_constraint;
}

void asn1Parser::Component_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_constraint(this);
}

void asn1Parser::Component_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_constraint(this);
}


antlrcpp::Any asn1Parser::Component_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitComponent_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Component_constraintContext* asn1Parser::component_constraint() {
  Component_constraintContext *_localctx = _tracker.createInstance<Component_constraintContext>(_ctx, getState());
  enterRule(_localctx, 338, asn1Parser::RuleComponent_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1430);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1425);
      value_constraint();
      setState(1426);
      presence_constraint();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1428);
      presence_constraint();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1429);
      value_constraint();
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

//----------------- Value_constraintContext ------------------------------------------------------------------

asn1Parser::Value_constraintContext::Value_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::ConstraintContext* asn1Parser::Value_constraintContext::constraint() {
  return getRuleContext<asn1Parser::ConstraintContext>(0);
}


size_t asn1Parser::Value_constraintContext::getRuleIndex() const {
  return asn1Parser::RuleValue_constraint;
}

void asn1Parser::Value_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_constraint(this);
}

void asn1Parser::Value_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_constraint(this);
}


antlrcpp::Any asn1Parser::Value_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitValue_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Value_constraintContext* asn1Parser::value_constraint() {
  Value_constraintContext *_localctx = _tracker.createInstance<Value_constraintContext>(_ctx, getState());
  enterRule(_localctx, 340, asn1Parser::RuleValue_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1432);
    constraint();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Presence_constraintContext ------------------------------------------------------------------

asn1Parser::Presence_constraintContext::Presence_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Presence_constraintContext::PRESENT_RW() {
  return getToken(asn1Parser::PRESENT_RW, 0);
}

tree::TerminalNode* asn1Parser::Presence_constraintContext::ABSENT_RW() {
  return getToken(asn1Parser::ABSENT_RW, 0);
}

tree::TerminalNode* asn1Parser::Presence_constraintContext::OPTIONAL_RW() {
  return getToken(asn1Parser::OPTIONAL_RW, 0);
}


size_t asn1Parser::Presence_constraintContext::getRuleIndex() const {
  return asn1Parser::RulePresence_constraint;
}

void asn1Parser::Presence_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPresence_constraint(this);
}

void asn1Parser::Presence_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPresence_constraint(this);
}


antlrcpp::Any asn1Parser::Presence_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPresence_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Presence_constraintContext* asn1Parser::presence_constraint() {
  Presence_constraintContext *_localctx = _tracker.createInstance<Presence_constraintContext>(_ctx, getState());
  enterRule(_localctx, 342, asn1Parser::RulePresence_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1434);
    _la = _input->LA(1);
    if (!(((((_la - 17) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 17)) & ((1ULL << (asn1Parser::ABSENT_RW - 17))
      | (1ULL << (asn1Parser::OPTIONAL_RW - 17))
      | (1ULL << (asn1Parser::PRESENT_RW - 17)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pattern_constraintContext ------------------------------------------------------------------

asn1Parser::Pattern_constraintContext::Pattern_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Pattern_constraintContext::PATTERN_RW() {
  return getToken(asn1Parser::PATTERN_RW, 0);
}

asn1Parser::ValueContext* asn1Parser::Pattern_constraintContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Pattern_constraintContext::getRuleIndex() const {
  return asn1Parser::RulePattern_constraint;
}

void asn1Parser::Pattern_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPattern_constraint(this);
}

void asn1Parser::Pattern_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPattern_constraint(this);
}


antlrcpp::Any asn1Parser::Pattern_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitPattern_constraint(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Pattern_constraintContext* asn1Parser::pattern_constraint() {
  Pattern_constraintContext *_localctx = _tracker.createInstance<Pattern_constraintContext>(_ctx, getState());
  enterRule(_localctx, 344, asn1Parser::RulePattern_constraint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1436);
    match(asn1Parser::PATTERN_RW);
    setState(1437);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_settingsContext ------------------------------------------------------------------

asn1Parser::Property_settingsContext::Property_settingsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Property_settingsContext::SETTINGS_RW() {
  return getToken(asn1Parser::SETTINGS_RW, 0);
}

tree::TerminalNode* asn1Parser::Property_settingsContext::SIMPLE_STRING() {
  return getToken(asn1Parser::SIMPLE_STRING, 0);
}


size_t asn1Parser::Property_settingsContext::getRuleIndex() const {
  return asn1Parser::RuleProperty_settings;
}

void asn1Parser::Property_settingsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_settings(this);
}

void asn1Parser::Property_settingsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_settings(this);
}


antlrcpp::Any asn1Parser::Property_settingsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitProperty_settings(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Property_settingsContext* asn1Parser::property_settings() {
  Property_settingsContext *_localctx = _tracker.createInstance<Property_settingsContext>(_ctx, getState());
  enterRule(_localctx, 346, asn1Parser::RuleProperty_settings);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1439);
    match(asn1Parser::SETTINGS_RW);
    setState(1440);
    match(asn1Parser::SIMPLE_STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_settings_listContext ------------------------------------------------------------------

asn1Parser::Property_settings_listContext::Property_settings_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Property_and_setting_pairContext* asn1Parser::Property_settings_listContext::property_and_setting_pair() {
  return getRuleContext<asn1Parser::Property_and_setting_pairContext>(0);
}

asn1Parser::Property_settings_listContext* asn1Parser::Property_settings_listContext::property_settings_list() {
  return getRuleContext<asn1Parser::Property_settings_listContext>(0);
}


size_t asn1Parser::Property_settings_listContext::getRuleIndex() const {
  return asn1Parser::RuleProperty_settings_list;
}

void asn1Parser::Property_settings_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_settings_list(this);
}

void asn1Parser::Property_settings_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_settings_list(this);
}


antlrcpp::Any asn1Parser::Property_settings_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitProperty_settings_list(this);
  else
    return visitor->visitChildren(this);
}


asn1Parser::Property_settings_listContext* asn1Parser::property_settings_list() {
   return property_settings_list(0);
}

asn1Parser::Property_settings_listContext* asn1Parser::property_settings_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  asn1Parser::Property_settings_listContext *_localctx = _tracker.createInstance<Property_settings_listContext>(_ctx, parentState);
  asn1Parser::Property_settings_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 348;
  enterRecursionRule(_localctx, 348, asn1Parser::RuleProperty_settings_list, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1443);
    property_and_setting_pair();
    _ctx->stop = _input->LT(-1);
    setState(1449);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Property_settings_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProperty_settings_list);
        setState(1445);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1446);
        property_and_setting_pair(); 
      }
      setState(1451);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Property_and_setting_pairContext ------------------------------------------------------------------

asn1Parser::Property_and_setting_pairContext::Property_and_setting_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Property_nameContext* asn1Parser::Property_and_setting_pairContext::property_name() {
  return getRuleContext<asn1Parser::Property_nameContext>(0);
}

tree::TerminalNode* asn1Parser::Property_and_setting_pairContext::EQUALS_SIGN_TK() {
  return getToken(asn1Parser::EQUALS_SIGN_TK, 0);
}

asn1Parser::Setting_nameContext* asn1Parser::Property_and_setting_pairContext::setting_name() {
  return getRuleContext<asn1Parser::Setting_nameContext>(0);
}


size_t asn1Parser::Property_and_setting_pairContext::getRuleIndex() const {
  return asn1Parser::RuleProperty_and_setting_pair;
}

void asn1Parser::Property_and_setting_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_and_setting_pair(this);
}

void asn1Parser::Property_and_setting_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_and_setting_pair(this);
}


antlrcpp::Any asn1Parser::Property_and_setting_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitProperty_and_setting_pair(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Property_and_setting_pairContext* asn1Parser::property_and_setting_pair() {
  Property_and_setting_pairContext *_localctx = _tracker.createInstance<Property_and_setting_pairContext>(_ctx, getState());
  enterRule(_localctx, 350, asn1Parser::RuleProperty_and_setting_pair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1452);
    property_name();
    setState(1453);
    match(asn1Parser::EQUALS_SIGN_TK);
    setState(1454);
    setting_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_nameContext ------------------------------------------------------------------

asn1Parser::Property_nameContext::Property_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Property_nameContext::PS_NAME() {
  return getToken(asn1Parser::PS_NAME, 0);
}


size_t asn1Parser::Property_nameContext::getRuleIndex() const {
  return asn1Parser::RuleProperty_name;
}

void asn1Parser::Property_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_name(this);
}

void asn1Parser::Property_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_name(this);
}


antlrcpp::Any asn1Parser::Property_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitProperty_name(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Property_nameContext* asn1Parser::property_name() {
  Property_nameContext *_localctx = _tracker.createInstance<Property_nameContext>(_ctx, getState());
  enterRule(_localctx, 352, asn1Parser::RuleProperty_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1456);
    match(asn1Parser::PS_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Setting_nameContext ------------------------------------------------------------------

asn1Parser::Setting_nameContext::Setting_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Setting_nameContext::PS_NAME() {
  return getToken(asn1Parser::PS_NAME, 0);
}


size_t asn1Parser::Setting_nameContext::getRuleIndex() const {
  return asn1Parser::RuleSetting_name;
}

void asn1Parser::Setting_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetting_name(this);
}

void asn1Parser::Setting_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetting_name(this);
}


antlrcpp::Any asn1Parser::Setting_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitSetting_name(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Setting_nameContext* asn1Parser::setting_name() {
  Setting_nameContext *_localctx = _tracker.createInstance<Setting_nameContext>(_ctx, getState());
  enterRule(_localctx, 354, asn1Parser::RuleSetting_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1458);
    match(asn1Parser::PS_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Duration_rangeContext ------------------------------------------------------------------

asn1Parser::Duration_rangeContext::Duration_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Value_rangeContext* asn1Parser::Duration_rangeContext::value_range() {
  return getRuleContext<asn1Parser::Value_rangeContext>(0);
}


size_t asn1Parser::Duration_rangeContext::getRuleIndex() const {
  return asn1Parser::RuleDuration_range;
}

void asn1Parser::Duration_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDuration_range(this);
}

void asn1Parser::Duration_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDuration_range(this);
}


antlrcpp::Any asn1Parser::Duration_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitDuration_range(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Duration_rangeContext* asn1Parser::duration_range() {
  Duration_rangeContext *_localctx = _tracker.createInstance<Duration_rangeContext>(_ctx, getState());
  enterRule(_localctx, 356, asn1Parser::RuleDuration_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1460);
    value_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Time_point_rangeContext ------------------------------------------------------------------

asn1Parser::Time_point_rangeContext::Time_point_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Value_rangeContext* asn1Parser::Time_point_rangeContext::value_range() {
  return getRuleContext<asn1Parser::Value_rangeContext>(0);
}


size_t asn1Parser::Time_point_rangeContext::getRuleIndex() const {
  return asn1Parser::RuleTime_point_range;
}

void asn1Parser::Time_point_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime_point_range(this);
}

void asn1Parser::Time_point_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime_point_range(this);
}


antlrcpp::Any asn1Parser::Time_point_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitTime_point_range(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Time_point_rangeContext* asn1Parser::time_point_range() {
  Time_point_rangeContext *_localctx = _tracker.createInstance<Time_point_rangeContext>(_ctx, getState());
  enterRule(_localctx, 358, asn1Parser::RuleTime_point_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1462);
    value_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Recurrence_rangeContext ------------------------------------------------------------------

asn1Parser::Recurrence_rangeContext::Recurrence_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Value_rangeContext* asn1Parser::Recurrence_rangeContext::value_range() {
  return getRuleContext<asn1Parser::Value_rangeContext>(0);
}


size_t asn1Parser::Recurrence_rangeContext::getRuleIndex() const {
  return asn1Parser::RuleRecurrence_range;
}

void asn1Parser::Recurrence_rangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecurrence_range(this);
}

void asn1Parser::Recurrence_rangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecurrence_range(this);
}


antlrcpp::Any asn1Parser::Recurrence_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitRecurrence_range(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Recurrence_rangeContext* asn1Parser::recurrence_range() {
  Recurrence_rangeContext *_localctx = _tracker.createInstance<Recurrence_rangeContext>(_ctx, getState());
  enterRule(_localctx, 360, asn1Parser::RuleRecurrence_range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1464);
    value_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exception_specContext ------------------------------------------------------------------

asn1Parser::Exception_specContext::Exception_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Exception_specContext::EXCLAMATION_MARK_TK() {
  return getToken(asn1Parser::EXCLAMATION_MARK_TK, 0);
}

asn1Parser::Exception_identificationContext* asn1Parser::Exception_specContext::exception_identification() {
  return getRuleContext<asn1Parser::Exception_identificationContext>(0);
}


size_t asn1Parser::Exception_specContext::getRuleIndex() const {
  return asn1Parser::RuleException_spec;
}

void asn1Parser::Exception_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterException_spec(this);
}

void asn1Parser::Exception_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitException_spec(this);
}


antlrcpp::Any asn1Parser::Exception_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitException_spec(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Exception_specContext* asn1Parser::exception_spec() {
  Exception_specContext *_localctx = _tracker.createInstance<Exception_specContext>(_ctx, getState());
  enterRule(_localctx, 362, asn1Parser::RuleException_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1466);
    match(asn1Parser::EXCLAMATION_MARK_TK);
    setState(1467);
    exception_identification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Exception_identificationContext ------------------------------------------------------------------

asn1Parser::Exception_identificationContext::Exception_identificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

asn1Parser::Signed_numberContext* asn1Parser::Exception_identificationContext::signed_number() {
  return getRuleContext<asn1Parser::Signed_numberContext>(0);
}

asn1Parser::Defined_valueContext* asn1Parser::Exception_identificationContext::defined_value() {
  return getRuleContext<asn1Parser::Defined_valueContext>(0);
}

asn1Parser::TypeContext* asn1Parser::Exception_identificationContext::type() {
  return getRuleContext<asn1Parser::TypeContext>(0);
}

tree::TerminalNode* asn1Parser::Exception_identificationContext::COLON_TK() {
  return getToken(asn1Parser::COLON_TK, 0);
}

asn1Parser::ValueContext* asn1Parser::Exception_identificationContext::value() {
  return getRuleContext<asn1Parser::ValueContext>(0);
}


size_t asn1Parser::Exception_identificationContext::getRuleIndex() const {
  return asn1Parser::RuleException_identification;
}

void asn1Parser::Exception_identificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterException_identification(this);
}

void asn1Parser::Exception_identificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitException_identification(this);
}


antlrcpp::Any asn1Parser::Exception_identificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitException_identification(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Exception_identificationContext* asn1Parser::exception_identification() {
  Exception_identificationContext *_localctx = _tracker.createInstance<Exception_identificationContext>(_ctx, getState());
  enterRule(_localctx, 364, asn1Parser::RuleException_identification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1475);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1469);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1470);
      defined_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1471);
      type();
      setState(1472);
      match(asn1Parser::COLON_TK);
      setState(1473);
      value();
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

//----------------- Encoding_control_sectionsContext ------------------------------------------------------------------

asn1Parser::Encoding_control_sectionsContext::Encoding_control_sectionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<asn1Parser::Encoding_control_sectionContext *> asn1Parser::Encoding_control_sectionsContext::encoding_control_section() {
  return getRuleContexts<asn1Parser::Encoding_control_sectionContext>();
}

asn1Parser::Encoding_control_sectionContext* asn1Parser::Encoding_control_sectionsContext::encoding_control_section(size_t i) {
  return getRuleContext<asn1Parser::Encoding_control_sectionContext>(i);
}


size_t asn1Parser::Encoding_control_sectionsContext::getRuleIndex() const {
  return asn1Parser::RuleEncoding_control_sections;
}

void asn1Parser::Encoding_control_sectionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEncoding_control_sections(this);
}

void asn1Parser::Encoding_control_sectionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEncoding_control_sections(this);
}


antlrcpp::Any asn1Parser::Encoding_control_sectionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEncoding_control_sections(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Encoding_control_sectionsContext* asn1Parser::encoding_control_sections() {
  Encoding_control_sectionsContext *_localctx = _tracker.createInstance<Encoding_control_sectionsContext>(_ctx, getState());
  enterRule(_localctx, 366, asn1Parser::RuleEncoding_control_sections);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1478); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1477);
      encoding_control_section();
      setState(1480); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == asn1Parser::ENCODING_CONTROL_RW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Encoding_control_sectionContext ------------------------------------------------------------------

asn1Parser::Encoding_control_sectionContext::Encoding_control_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* asn1Parser::Encoding_control_sectionContext::ENCODING_CONTROL_RW() {
  return getToken(asn1Parser::ENCODING_CONTROL_RW, 0);
}

tree::TerminalNode* asn1Parser::Encoding_control_sectionContext::ENCODING_REFERENCE() {
  return getToken(asn1Parser::ENCODING_REFERENCE, 0);
}


size_t asn1Parser::Encoding_control_sectionContext::getRuleIndex() const {
  return asn1Parser::RuleEncoding_control_section;
}

void asn1Parser::Encoding_control_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEncoding_control_section(this);
}

void asn1Parser::Encoding_control_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<asn1Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEncoding_control_section(this);
}


antlrcpp::Any asn1Parser::Encoding_control_sectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<asn1Visitor*>(visitor))
    return parserVisitor->visitEncoding_control_section(this);
  else
    return visitor->visitChildren(this);
}

asn1Parser::Encoding_control_sectionContext* asn1Parser::encoding_control_section() {
  Encoding_control_sectionContext *_localctx = _tracker.createInstance<Encoding_control_sectionContext>(_ctx, getState());
  enterRule(_localctx, 368, asn1Parser::RuleEncoding_control_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1482);
    match(asn1Parser::ENCODING_CONTROL_RW);
    setState(1483);
    match(asn1Parser::ENCODING_REFERENCE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool asn1Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 32: return item_specSempred(dynamic_cast<Item_specContext *>(context), predicateIndex);
    case 143: return unionsSempred(dynamic_cast<UnionsContext *>(context), predicateIndex);
    case 174: return property_settings_listSempred(dynamic_cast<Property_settings_listContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool asn1Parser::item_specSempred(Item_specContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool asn1Parser::unionsSempred(UnionsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool asn1Parser::property_settings_listSempred(Property_settings_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> asn1Parser::_decisionToDFA;
atn::PredictionContextCache asn1Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN asn1Parser::_atn;
std::vector<uint16_t> asn1Parser::_serializedATN;

std::vector<std::string> asn1Parser::_ruleNames = {
  "file", "module_definition", "module_identifier", "definitive_identification", 
  "definitive_oid", "definitive_oid_and_iri", "definitive_object_id_component_list", 
  "definitive_object_id_component", "definitive_number_form", "definitive_name_and_number_form", 
  "encoding_reference_default", "tag_default", "extension_default", "module_body", 
  "exports", "symbols_exported", "imports", "symbols_imported", "symbols_from_module_list", 
  "symbols_from_module", "global_module_reference", "assigned_identifier", 
  "symbol_list", "symbol", "reference", "assignment_list", "assignment", 
  "defined_type", "defined_value", "external_type_reference", "external_value_reference", 
  "absolute_reference", "item_spec", "component_id", "type_assignment", 
  "value_assignment", "value_set_type_assignment", "value_set", "type", 
  "builtin_type", "referenced_type", "named_type", "any_type", "value", 
  "builtin_value", "named_value", "boolean_value", "integer_type", "named_number_list", 
  "named_number", "signed_number", "integer_value", "enumerated_type", "enumerations", 
  "root_enumeration", "additional_enumeration", "enumeration", "enumeration_item", 
  "enumerated_value", "real_value", "bit_string_type", "named_bit_list", 
  "named_bit", "bit_string_value", "identifier_list", "octet_string_value", 
  "sequence_or_set_type", "sequence_or_set_of_type", "extension_and_exception", 
  "optional_extension_marker", "component_type_lists", "extension_end_marker", 
  "extension_additions", "extension_addition_list", "extension_addition", 
  "extension_addition_group", "version_number", "component_type_list", "component_type", 
  "sequence_value", "component_value_list", "sequence_of_value", "value_list", 
  "named_value_list", "set_value", "set_of_value", "choice_type", "alternative_type_lists", 
  "root_alternative_type_list", "extension_addition_alternatives", "extension_addition_alternatives_list", 
  "extension_addition_alternative", "extension_addition_alternatives_group", 
  "alternative_type_list", "choice_value", "selection_type", "prefixed_type", 
  "tagged_type", "tag", "class_number", "category", "encoding_prefixed_type", 
  "encoding_prefix", "object_identifier_value", "obj_id_components", "name_form", 
  "number_form", "name_and_number_form", "relative_oid_value", "relative_oid_components_list", 
  "relative_oid_components", "iri_value", "arc_identifier", "relative_iri_value", 
  "embedded_pdv_value", "time_value", "character_string_type", "character_string_value", 
  "restricted_character_string_type", "restricted_character_string_value", 
  "character_string_list", "chars_defn", "quadruple", "group", "plane", 
  "row", "cell", "tuple", "table_column", "table_row", "unrestricted_character_string_type", 
  "unrestricted_character_string_value", "useful_type", "constrained_type", 
  "type_with_constraint", "constraint", "size_constraint", "constraint_spec", 
  "subtype_constraint", "element_set_specs", "root_element_set_spec", "additional_element_set_spec", 
  "element_set_spec", "unions", "intersections", "intersection_elements", 
  "elems", "exclusions", "union_mark", "intersection_mark", "elements", 
  "subtype_elements", "single_value", "contained_subtype", "includes", "value_range", 
  "lower_endpoint", "upper_endpoint", "lower_end_value", "upper_end_value", 
  "type_constraint", "permitted_alphabet", "inner_type_constraints", "single_type_constraint", 
  "multiple_type_constraints", "full_specification", "partial_specification", 
  "type_constraints", "named_constraint", "component_constraint", "value_constraint", 
  "presence_constraint", "pattern_constraint", "property_settings", "property_settings_list", 
  "property_and_setting_pair", "property_name", "setting_name", "duration_range", 
  "time_point_range", "recurrence_range", "exception_spec", "exception_identification", 
  "encoding_control_sections", "encoding_control_section"
};

std::vector<std::string> asn1Parser::_literalNames = {
  "", "'BMPString'", "'GeneralString'", "'GraphicString'", "'IA5String'", 
  "'ISO646String'", "'NumericString'", "'PrintableString'", "'TeletexString'", 
  "'T61String'", "'UniversalString'", "'UTF8String'", "'VideotexString'", 
  "'VisibleString'", "'GeneralizedTime'", "'UTCTime'", "'ObjectDescriptor'", 
  "'ABSENT'", "'ALL'", "'APPLICATION'", "'AUTOMATIC'", "'BEGIN'", "'BIT'", 
  "'BOOLEAN'", "'CHARACTER'", "'CHOICE'", "'COMPONENTS'", "'COMPONENT'", 
  "'CONTAINING'", "'DATE'", "'DATE-TIME'", "'DEFAULT'", "'DEFINITIONS'", 
  "'DURATION'", "'EMBEDDED'", "'ENCODING-CONTROL'", "'END'", "'ENUMERATED'", 
  "'EXCEPT'", "'EXPLICIT'", "'EXPORTS'", "'EXTENSIBILITY'", "'EXTERNAL'", 
  "'FALSE'", "'FROM'", "'IDENTIFIER'", "'IMPLICIT'", "'IMPLIED'", "'IMPORTS'", 
  "'INCLUDES'", "'INSTRUCTIONS'", "'INTEGER'", "'INTERSECTION'", "'MAX'", 
  "'MINUS-INFINITY'", "'MIN'", "'NOT-A-NUMBER'", "'NULL'", "'OBJECT'", "'OCTET'", 
  "'OF'", "'OID-IRI'", "'OPTIONAL'", "'PATTERN'", "'PDV'", "'PLUS-INFINITY'", 
  "'PRESENT'", "'PRIVATE'", "'REAL'", "'RELATIVE-OID-IRI'", "'RELATIVE-OID'", 
  "'SEQUENCE'", "'SETTINGS'", "'SET'", "'SIZE'", "'STRING'", "'TAGS'", "'TIME-OF-DAY'", 
  "'TIME'", "'TRUE'", "'UNION'", "'UNIVERSAL'", "'WITH'", "'ANY'", "'DEFINED'", 
  "'BY'", "'!'", "'\"'", "'('", "')'", "'*'", "','", "'.'", "'/'", "':'", 
  "';'", "'<'", "'='", "'@'", "'['", "']'", "'^'", "'{'", "'|'", "'}'", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "'::='", "'..'", "'...'", 
  "'[['", "']]'"
};

std::vector<std::string> asn1Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ABSENT_RW", 
  "ALL_RW", "APPLICATION_RW", "AUTOMATIC_RW", "BEGIN_RW", "BIT_RW", "BOOLEAN_RW", 
  "CHARACTER_RW", "CHOICE_RW", "COMPONENTS_RW", "COMPONENT_RW", "CONTAINING_RW", 
  "DATE_RW", "DATE_TIME_RW", "DEFAULT_RW", "DEFINITIONS_RW", "DURATION_RW", 
  "EMBEDDED_RW", "ENCODING_CONTROL_RW", "END_RW", "ENUMERATED_RW", "EXCEPT_RW", 
  "EXPLICIT_RW", "EXPORTS_RW", "EXTENSIBILITY_RW", "EXTERNAL_RW", "FALSE_RW", 
  "FROM_RW", "IDENTIFIER_RW", "IMPLICIT_RW", "IMPLIED_RW", "IMPORTS_RW", 
  "INCLUDES_RW", "INSTRUCTIONS_RW", "INTEGER_RW", "INTERSECTION_RW", "MAX_RW", 
  "MINUS_INFINITY_RW", "MIN_RW", "NOT_A_NUMBER_RW", "NULL_RW", "OBJECT_RW", 
  "OCTET_RW", "OF_RW", "OID_IRI_RW", "OPTIONAL_RW", "PATTERN_RW", "PDV_RW", 
  "PLUS_INFINITY_RW", "PRESENT_RW", "PRIVATE_RW", "REAL_RW", "RELATIVE_OID_IRI_RW", 
  "RELATIVE_OID_RW", "SEQUENCE_RW", "SETTINGS_RW", "SET_RW", "SIZE_RW", 
  "STRING_RW", "TAGS_RW", "TIME_OF_DAY_RW", "TIME_RW", "TRUE_RW", "UNION_RW", 
  "UNIVERSAL_RW", "WITH_RW", "ANY_RW", "DEFINED_RW", "BY_RW", "EXCLAMATION_MARK_TK", 
  "QUOTATION_MARK_TK", "LEFT_PARENTHESIS_TK", "RIGHT_PARENTHESIS_TK", "ASTERISK_TK", 
  "COMMA_TK", "FULL_STOP_TK", "SOLIDUS_TK", "COLON_TK", "SEMICOLON_TK", 
  "LESS_THAN_SIGN_TK", "EQUALS_SIGN_TK", "COMMERCIAL_AT_TK", "LEFT_SQUARE_BRACKET_TK", 
  "RIGHT_SQUARE_BRACKET_TK", "CIRCUMFLEX_ACCENT_TK", "LEFT_CURLY_BRACKET_TK", 
  "VERTICAL_LINE_TK", "RIGHT_CURLY_BRACKET_TK", "HYPHEN_TK", "WS", "TYPE_REFERENCE_OR_MODULE_REFERENCE", 
  "IDENTIFIER", "TYPE_REFERENCE_OR_IDENTIFIER_HYPHENATED_LIST_OPT", "NUMBER", 
  "REAL_NUMBER", "BSTRING", "HSTRING", "CSTRING", "SIMPLE_STRING", "TSTRING", 
  "PS_NAME", "ASSIGNMENT", "RANGE_SEPARATOR", "ELLIPSIS", "LEFT_VERSION_BRACKETS", 
  "RIGHT_VERSION_BRACKETS", "ENCODING_REFERENCE"
};

dfa::Vocabulary asn1Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> asn1Parser::_tokenNames;

asn1Parser::Initializer::Initializer() {
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
    0x3, 0x7d, 0x5d0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 
    0x9, 0x70, 0x4, 0x71, 0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 
    0x73, 0x4, 0x74, 0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 
    0x4, 0x77, 0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 
    0x7a, 0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
    0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 0x9, 
    0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 0x9, 0x83, 
    0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 0x9, 0x86, 0x4, 
    0x87, 0x9, 0x87, 0x4, 0x88, 0x9, 0x88, 0x4, 0x89, 0x9, 0x89, 0x4, 0x8a, 
    0x9, 0x8a, 0x4, 0x8b, 0x9, 0x8b, 0x4, 0x8c, 0x9, 0x8c, 0x4, 0x8d, 0x9, 
    0x8d, 0x4, 0x8e, 0x9, 0x8e, 0x4, 0x8f, 0x9, 0x8f, 0x4, 0x90, 0x9, 0x90, 
    0x4, 0x91, 0x9, 0x91, 0x4, 0x92, 0x9, 0x92, 0x4, 0x93, 0x9, 0x93, 0x4, 
    0x94, 0x9, 0x94, 0x4, 0x95, 0x9, 0x95, 0x4, 0x96, 0x9, 0x96, 0x4, 0x97, 
    0x9, 0x97, 0x4, 0x98, 0x9, 0x98, 0x4, 0x99, 0x9, 0x99, 0x4, 0x9a, 0x9, 
    0x9a, 0x4, 0x9b, 0x9, 0x9b, 0x4, 0x9c, 0x9, 0x9c, 0x4, 0x9d, 0x9, 0x9d, 
    0x4, 0x9e, 0x9, 0x9e, 0x4, 0x9f, 0x9, 0x9f, 0x4, 0xa0, 0x9, 0xa0, 0x4, 
    0xa1, 0x9, 0xa1, 0x4, 0xa2, 0x9, 0xa2, 0x4, 0xa3, 0x9, 0xa3, 0x4, 0xa4, 
    0x9, 0xa4, 0x4, 0xa5, 0x9, 0xa5, 0x4, 0xa6, 0x9, 0xa6, 0x4, 0xa7, 0x9, 
    0xa7, 0x4, 0xa8, 0x9, 0xa8, 0x4, 0xa9, 0x9, 0xa9, 0x4, 0xaa, 0x9, 0xaa, 
    0x4, 0xab, 0x9, 0xab, 0x4, 0xac, 0x9, 0xac, 0x4, 0xad, 0x9, 0xad, 0x4, 
    0xae, 0x9, 0xae, 0x4, 0xaf, 0x9, 0xaf, 0x4, 0xb0, 0x9, 0xb0, 0x4, 0xb1, 
    0x9, 0xb1, 0x4, 0xb2, 0x9, 0xb2, 0x4, 0xb3, 0x9, 0xb3, 0x4, 0xb4, 0x9, 
    0xb4, 0x4, 0xb5, 0x9, 0xb5, 0x4, 0xb6, 0x9, 0xb6, 0x4, 0xb7, 0x9, 0xb7, 
    0x4, 0xb8, 0x9, 0xb8, 0x4, 0xb9, 0x9, 0xb9, 0x4, 0xba, 0x9, 0xba, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x17a, 0xa, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x17d, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x180, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x186, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x18c, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x190, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x6, 0x8, 0x19a, 0xa, 
    0x8, 0xd, 0x8, 0xe, 0x8, 0x19b, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x1a1, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x1ac, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0x1b6, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x1be, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1c7, 
    0xa, 0x10, 0x3, 0x11, 0x5, 0x11, 0x1ca, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1d0, 0xa, 0x12, 0x3, 0x13, 0x5, 0x13, 
    0x1d3, 0xa, 0x13, 0x3, 0x14, 0x6, 0x14, 0x1d6, 0xa, 0x14, 0xd, 0x14, 
    0xe, 0x14, 0x1d7, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x1e0, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
    0x1e4, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x1e9, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x1ec, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x6, 0x1b, 0x1f3, 0xa, 0x1b, 0xd, 0x1b, 
    0xe, 0x1b, 0x1f4, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1fa, 
    0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1fe, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x5, 0x1e, 0x202, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x217, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x21a, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x5, 0x28, 0x234, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x250, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x255, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x5, 0x2c, 0x25f, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x263, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x278, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x5, 0x31, 0x285, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x7, 0x32, 0x28a, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x28d, 
    0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x5, 0x33, 0x2a3, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x2a8, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 
    0x2ac, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x2b8, 
    0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x2be, 
    0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x2c3, 0xa, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x7, 0x3a, 0x2cc, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x2cf, 0xb, 
    0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x2d3, 0xa, 0x3b, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x2de, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 
    0x3e, 0x2e8, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 
    0x2ed, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x2f0, 0xb, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
    0x40, 0x3, 0x40, 0x5, 0x40, 0x2fb, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x5, 0x41, 0x307, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x7, 0x42, 0x30c, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x30f, 
    0xb, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x315, 
    0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
    0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x31f, 0xa, 0x44, 0x3, 0x45, 
    0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x32d, 
    0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x331, 0xa, 0x46, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x5, 0x48, 0x33b, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x343, 0xa, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x34b, 
    0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x5, 0x48, 0x353, 0xa, 0x48, 0x3, 0x48, 0x5, 0x48, 0x356, 0xa, 
    0x48, 0x5, 0x48, 0x358, 0xa, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 
    0x4b, 0x363, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x366, 0xb, 0x4b, 0x3, 
    0x4c, 0x3, 0x4c, 0x5, 0x4c, 0x36a, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 
    0x5, 0x4d, 0x36e, 0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x379, 
    0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x37c, 0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
    0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x389, 0xa, 0x50, 0x3, 0x51, 
    0x3, 0x51, 0x5, 0x51, 0x38d, 0xa, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
    0x3, 0x52, 0x3, 0x52, 0x7, 0x52, 0x394, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 
    0x397, 0xb, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 0x3a3, 
    0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x3a8, 0xa, 0x54, 
    0xc, 0x54, 0xe, 0x54, 0x3ab, 0xb, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
    0x7, 0x55, 0x3b0, 0xa, 0x55, 0xc, 0x55, 0xe, 0x55, 0x3b3, 0xb, 0x55, 
    0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x3b7, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
    0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x5, 0x57, 0x3c5, 0xa, 0x57, 
    0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x3d1, 0xa, 0x59, 
    0x3, 0x59, 0x3, 0x59, 0x5, 0x59, 0x3d5, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 
    0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x7, 
    0x5c, 0x3df, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 0x3e2, 0xb, 0x5c, 0x3, 
    0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3e6, 0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x7, 
    0x5f, 0x3f0, 0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 0x3f3, 0xb, 0x5f, 0x3, 
    0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 
    0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x5, 0x62, 0x3ff, 0xa, 0x62, 0x3, 0x63, 
    0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 
    0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 0x40c, 0xa, 0x63, 
    0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x411, 0xa, 0x64, 0x3, 0x64, 
    0x5, 0x64, 0x414, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 
    0x3, 0x65, 0x5, 0x65, 0x41b, 0xa, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 
    0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 0x425, 
    0xa, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x6, 
    0x69, 0x42c, 0xa, 0x69, 0xd, 0x69, 0xe, 0x69, 0x42d, 0x3, 0x69, 0x3, 
    0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x436, 
    0xa, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x5, 0x6c, 0x43c, 
    0xa, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 
    0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x448, 
    0xa, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6f, 0x6, 
    0x6f, 0x44f, 0xa, 0x6f, 0xd, 0x6f, 0xe, 0x6f, 0x450, 0x3, 0x70, 0x3, 
    0x70, 0x3, 0x70, 0x5, 0x70, 0x456, 0xa, 0x70, 0x3, 0x71, 0x3, 0x71, 
    0x3, 0x71, 0x6, 0x71, 0x45b, 0xa, 0x71, 0xd, 0x71, 0xe, 0x71, 0x45c, 
    0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 
    0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x5, 0x72, 0x46a, 
    0xa, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x6, 0x73, 0x470, 
    0xa, 0x73, 0xd, 0x73, 0xe, 0x73, 0x471, 0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 
    0x3, 0x74, 0x3, 0x75, 0x3, 0x75, 0x3, 0x76, 0x3, 0x76, 0x5, 0x76, 0x47c, 
    0xa, 0x76, 0x3, 0x77, 0x3, 0x77, 0x5, 0x77, 0x480, 0xa, 0x77, 0x3, 0x78, 
    0x3, 0x78, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x5, 0x79, 0x488, 
    0xa, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x7, 0x7a, 0x48e, 
    0xa, 0x7a, 0xc, 0x7a, 0xe, 0x7a, 0x491, 0xb, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 
    0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x5, 0x7b, 0x499, 0xa, 0x7b, 
    0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 
    0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7e, 
    0x3, 0x7e, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x80, 0x3, 0x80, 0x3, 0x81, 0x3, 
    0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x81, 0x3, 0x82, 0x3, 0x82, 
    0x3, 0x83, 0x3, 0x83, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x85, 0x3, 
    0x85, 0x3, 0x86, 0x3, 0x86, 0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x4c0, 
    0xa, 0x87, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x4c5, 0xa, 0x87, 
    0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 
    0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
    0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 
    0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
    0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 
    0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 0x3, 0x88, 
    0x3, 0x88, 0x5, 0x88, 0x4ef, 0xa, 0x88, 0x3, 0x89, 0x3, 0x89, 0x3, 0x89, 
    0x5, 0x89, 0x4f4, 0xa, 0x89, 0x3, 0x89, 0x3, 0x89, 0x3, 0x8a, 0x3, 0x8a, 
    0x3, 0x8a, 0x3, 0x8b, 0x3, 0x8b, 0x3, 0x8c, 0x3, 0x8c, 0x3, 0x8d, 0x3, 
    0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 
    0x3, 0x8d, 0x3, 0x8d, 0x3, 0x8d, 0x5, 0x8d, 0x50a, 0xa, 0x8d, 0x3, 0x8e, 
    0x3, 0x8e, 0x3, 0x8f, 0x3, 0x8f, 0x3, 0x90, 0x3, 0x90, 0x3, 0x90, 0x5, 
    0x90, 0x513, 0xa, 0x90, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 
    0x3, 0x91, 0x3, 0x91, 0x3, 0x91, 0x7, 0x91, 0x51c, 0xa, 0x91, 0xc, 0x91, 
    0xe, 0x91, 0x51f, 0xb, 0x91, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 0x3, 0x92, 
    0x3, 0x92, 0x5, 0x92, 0x526, 0xa, 0x92, 0x3, 0x93, 0x3, 0x93, 0x3, 0x93, 
    0x3, 0x93, 0x5, 0x93, 0x52c, 0xa, 0x93, 0x3, 0x94, 0x3, 0x94, 0x3, 0x95, 
    0x3, 0x95, 0x3, 0x95, 0x3, 0x96, 0x3, 0x96, 0x3, 0x97, 0x3, 0x97, 0x3, 
    0x98, 0x3, 0x98, 0x3, 0x98, 0x3, 0x98, 0x3, 0x98, 0x5, 0x98, 0x53c, 
    0xa, 0x98, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 
    0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 0x3, 0x99, 
    0x5, 0x99, 0x54a, 0xa, 0x99, 0x3, 0x9a, 0x3, 0x9a, 0x3, 0x9b, 0x5, 0x9b, 
    0x54f, 0xa, 0x9b, 0x3, 0x9b, 0x3, 0x9b, 0x3, 0x9c, 0x3, 0x9c, 0x3, 0x9d, 
    0x3, 0x9d, 0x3, 0x9d, 0x3, 0x9d, 0x3, 0x9e, 0x3, 0x9e, 0x3, 0x9e, 0x3, 
    0x9e, 0x5, 0x9e, 0x55d, 0xa, 0x9e, 0x3, 0x9f, 0x3, 0x9f, 0x3, 0x9f, 
    0x5, 0x9f, 0x562, 0xa, 0x9f, 0x3, 0xa0, 0x3, 0xa0, 0x5, 0xa0, 0x566, 
    0xa, 0xa0, 0x3, 0xa1, 0x3, 0xa1, 0x5, 0xa1, 0x56a, 0xa, 0xa1, 0x3, 0xa2, 
    0x3, 0xa2, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa3, 0x3, 0xa4, 0x3, 0xa4, 0x3, 
    0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x3, 0xa4, 0x5, 0xa4, 0x577, 0xa, 0xa4, 
    0x3, 0xa5, 0x3, 0xa5, 0x3, 0xa6, 0x3, 0xa6, 0x5, 0xa6, 0x57d, 0xa, 0xa6, 
    0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa7, 0x3, 0xa8, 0x3, 0xa8, 0x3, 
    0xa8, 0x3, 0xa8, 0x3, 0xa8, 0x3, 0xa8, 0x3, 0xa9, 0x3, 0xa9, 0x3, 0xa9, 
    0x3, 0xa9, 0x3, 0xa9, 0x5, 0xa9, 0x58e, 0xa, 0xa9, 0x3, 0xaa, 0x3, 0xaa, 
    0x5, 0xaa, 0x592, 0xa, 0xaa, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 0x3, 0xab, 
    0x3, 0xab, 0x5, 0xab, 0x599, 0xa, 0xab, 0x3, 0xac, 0x3, 0xac, 0x3, 0xad, 
    0x3, 0xad, 0x3, 0xae, 0x3, 0xae, 0x3, 0xae, 0x3, 0xaf, 0x3, 0xaf, 0x3, 
    0xaf, 0x3, 0xb0, 0x3, 0xb0, 0x3, 0xb0, 0x3, 0xb0, 0x3, 0xb0, 0x7, 0xb0, 
    0x5aa, 0xa, 0xb0, 0xc, 0xb0, 0xe, 0xb0, 0x5ad, 0xb, 0xb0, 0x3, 0xb1, 
    0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb1, 0x3, 0xb2, 0x3, 0xb2, 0x3, 0xb3, 0x3, 
    0xb3, 0x3, 0xb4, 0x3, 0xb4, 0x3, 0xb5, 0x3, 0xb5, 0x3, 0xb6, 0x3, 0xb6, 
    0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb7, 0x3, 0xb8, 0x3, 0xb8, 0x3, 0xb8, 0x3, 
    0xb8, 0x3, 0xb8, 0x3, 0xb8, 0x5, 0xb8, 0x5c6, 0xa, 0xb8, 0x3, 0xb9, 
    0x6, 0xb9, 0x5c9, 0xa, 0xb9, 0xd, 0xb9, 0xe, 0xb9, 0x5ca, 0x3, 0xba, 
    0x3, 0xba, 0x3, 0xba, 0x3, 0xba, 0x2, 0x5, 0x42, 0x120, 0x15e, 0xbb, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
    0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
    0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 
    0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 
    0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 
    0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 
    0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 
    0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 0x108, 
    0x10a, 0x10c, 0x10e, 0x110, 0x112, 0x114, 0x116, 0x118, 0x11a, 0x11c, 
    0x11e, 0x120, 0x122, 0x124, 0x126, 0x128, 0x12a, 0x12c, 0x12e, 0x130, 
    0x132, 0x134, 0x136, 0x138, 0x13a, 0x13c, 0x13e, 0x140, 0x142, 0x144, 
    0x146, 0x148, 0x14a, 0x14c, 0x14e, 0x150, 0x152, 0x154, 0x156, 0x158, 
    0x15a, 0x15c, 0x15e, 0x160, 0x162, 0x164, 0x166, 0x168, 0x16a, 0x16c, 
    0x16e, 0x170, 0x172, 0x2, 0xb, 0x3, 0x2, 0x6d, 0x6e, 0x5, 0x2, 0x5c, 
    0x5c, 0x6e, 0x6e, 0x70, 0x70, 0x4, 0x2, 0x2d, 0x2d, 0x51, 0x51, 0x5, 
    0x2, 0x15, 0x15, 0x45, 0x45, 0x53, 0x53, 0x3, 0x2, 0x3, 0xf, 0x3, 0x2, 
    0x10, 0x12, 0x4, 0x2, 0x52, 0x52, 0x69, 0x69, 0x4, 0x2, 0x36, 0x36, 
    0x67, 0x67, 0x5, 0x2, 0x13, 0x13, 0x40, 0x40, 0x44, 0x44, 0x2, 0x5e8, 
    0x2, 0x174, 0x3, 0x2, 0x2, 0x2, 0x4, 0x176, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x189, 0x3, 0x2, 0x2, 0x2, 0x8, 0x18f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x191, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x195, 0x3, 0x2, 0x2, 0x2, 0xe, 0x199, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x12, 0x1a2, 0x3, 0x2, 
    0x2, 0x2, 0x14, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b7, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1d2, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1d9, 0x3, 
    0x2, 0x2, 0x2, 0x2a, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1ed, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x201, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x203, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x207, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x210, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x46, 0x21d, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x221, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x233, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x254, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x256, 0x3, 0x2, 0x2, 0x2, 0x56, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x58, 0x262, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x277, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x279, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x60, 0x284, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x286, 0x3, 0x2, 0x2, 0x2, 0x64, 0x2a2, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2ab, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x2c4, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x72, 0x2c8, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x76, 0x2d4, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x2e7, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x2fa, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x306, 0x3, 0x2, 0x2, 0x2, 0x82, 0x308, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x314, 0x3, 0x2, 0x2, 0x2, 0x86, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0x32c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x332, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x357, 0x3, 0x2, 0x2, 0x2, 0x90, 0x359, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x35f, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x369, 0x3, 0x2, 0x2, 0x2, 0x98, 0x36b, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x372, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x375, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x388, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x38a, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0x390, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x3a4, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x3b4, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0xae, 0x3c6, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x3d6, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x3db, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0xba, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0xbc, 
    0x3ec, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3f8, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x40b, 0x3, 
    0x2, 0x2, 0x2, 0xc6, 0x40d, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x41a, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0x41c, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x41e, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0x421, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x429, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0x435, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x437, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0x43b, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x447, 0x3, 0x2, 0x2, 0x2, 0xda, 0x449, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0x44e, 0x3, 0x2, 0x2, 0x2, 0xde, 0x455, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0x457, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x469, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0x46b, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x475, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0x477, 0x3, 0x2, 0x2, 0x2, 0xea, 0x47b, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0x47f, 0x3, 0x2, 0x2, 0x2, 0xee, 0x481, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0x487, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x489, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x498, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0x49a, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x4a4, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x4a8, 0x3, 0x2, 
    0x2, 0x2, 0xfe, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x100, 0x4ac, 0x3, 0x2, 0x2, 
    0x2, 0x102, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x104, 0x4b4, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x108, 0x4b9, 0x3, 0x2, 0x2, 
    0x2, 0x10a, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x4c4, 0x3, 0x2, 0x2, 
    0x2, 0x10e, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x110, 0x4f0, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x114, 0x4fa, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x118, 0x509, 0x3, 0x2, 0x2, 
    0x2, 0x11a, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x50d, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x512, 0x3, 0x2, 0x2, 0x2, 0x120, 0x514, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x525, 0x3, 0x2, 0x2, 0x2, 0x124, 0x52b, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x128, 0x52f, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x532, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x534, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x549, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x54e, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x552, 0x3, 0x2, 0x2, 0x2, 0x138, 0x554, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x561, 0x3, 0x2, 0x2, 
    0x2, 0x13e, 0x565, 0x3, 0x2, 0x2, 0x2, 0x140, 0x569, 0x3, 0x2, 0x2, 
    0x2, 0x142, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x144, 0x56d, 0x3, 0x2, 0x2, 
    0x2, 0x146, 0x576, 0x3, 0x2, 0x2, 0x2, 0x148, 0x578, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x57e, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x582, 0x3, 0x2, 0x2, 0x2, 0x150, 0x58d, 0x3, 0x2, 0x2, 
    0x2, 0x152, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x154, 0x598, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x59a, 0x3, 0x2, 0x2, 0x2, 0x158, 0x59c, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x5a1, 0x3, 0x2, 0x2, 
    0x2, 0x15e, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x160, 0x5ae, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x164, 0x5b4, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x168, 0x5b8, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x5ba, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x5bc, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x5c5, 0x3, 0x2, 0x2, 0x2, 0x170, 0x5c8, 0x3, 0x2, 0x2, 
    0x2, 0x172, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x5, 0x4, 0x3, 
    0x2, 0x175, 0x3, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x5, 0x6, 0x4, 0x2, 
    0x177, 0x179, 0x7, 0x22, 0x2, 0x2, 0x178, 0x17a, 0x5, 0x16, 0xc, 0x2, 
    0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 0x5, 0x18, 0xd, 0x2, 
    0x17c, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 
    0x17d, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x180, 0x5, 0x1a, 0xe, 0x2, 
    0x17f, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x7, 0x78, 0x2, 0x2, 
    0x182, 0x183, 0x7, 0x17, 0x2, 0x2, 0x183, 0x185, 0x5, 0x1c, 0xf, 0x2, 
    0x184, 0x186, 0x5, 0x170, 0xb9, 0x2, 0x185, 0x184, 0x3, 0x2, 0x2, 0x2, 
    0x185, 0x186, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x187, 0x188, 0x7, 0x26, 0x2, 0x2, 0x188, 0x5, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x18b, 0x7, 0x6d, 0x2, 0x2, 0x18a, 0x18c, 0x5, 0x8, 0x5, 0x2, 0x18b, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x5, 0xa, 0x6, 0x2, 0x18e, 0x190, 
    0x5, 0xc, 0x7, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x190, 0x9, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 
    0x68, 0x2, 0x2, 0x192, 0x193, 0x5, 0xe, 0x8, 0x2, 0x193, 0x194, 0x7, 
    0x6a, 0x2, 0x2, 0x194, 0xb, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 0xa, 
    0x6, 0x2, 0x196, 0x197, 0x5, 0xe0, 0x71, 0x2, 0x197, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x19a, 0x5, 0x10, 0x9, 0x2, 0x199, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x1a1, 0x5, 0xd4, 0x6b, 0x2, 0x19e, 0x1a1, 0x5, 0x12, 0xa, 
    0x2, 0x19f, 0x1a1, 0x5, 0x14, 0xb, 0x2, 0x1a0, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x11, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x70, 0x2, 
    0x2, 0x1a3, 0x13, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x6e, 0x2, 
    0x2, 0x1a5, 0x1a6, 0x7, 0x5a, 0x2, 0x2, 0x1a6, 0x1a7, 0x5, 0x12, 0xa, 
    0x2, 0x1a7, 0x1a8, 0x7, 0x5b, 0x2, 0x2, 0x1a8, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x1aa, 0x7, 0x7d, 0x2, 0x2, 0x1aa, 0x1ac, 0x7, 0x60, 0x2, 
    0x2, 0x1ab, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x34, 0x2, 
    0x2, 0x1ae, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x29, 0x2, 
    0x2, 0x1b0, 0x1b6, 0x7, 0x4e, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x30, 0x2, 
    0x2, 0x1b2, 0x1b6, 0x7, 0x4e, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0x16, 0x2, 
    0x2, 0x1b4, 0x1b6, 0x7, 0x4e, 0x2, 0x2, 0x1b5, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x2b, 0x2, 
    0x2, 0x1b8, 0x1b9, 0x7, 0x31, 0x2, 0x2, 0x1b9, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1ba, 0x1bb, 0x5, 0x1e, 0x10, 0x2, 0x1bb, 0x1bd, 0x5, 0x22, 0x12, 
    0x2, 0x1bc, 0x1be, 0x5, 0x34, 0x1b, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1bf, 0x1c0, 0x7, 0x2a, 0x2, 0x2, 0x1c0, 0x1c1, 0x5, 0x20, 0x11, 0x2, 
    0x1c1, 0x1c2, 0x7, 0x61, 0x2, 0x2, 0x1c2, 0x1c7, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c4, 0x7, 0x2a, 0x2, 0x2, 0x1c4, 0x1c5, 0x7, 0x14, 0x2, 0x2, 
    0x1c5, 0x1c7, 0x7, 0x61, 0x2, 0x2, 0x1c6, 0x1bf, 0x3, 0x2, 0x2, 0x2, 
    0x1c6, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 
    0x1c7, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ca, 0x5, 0x2e, 0x18, 0x2, 
    0x1c9, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 
    0x1ca, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x7, 0x32, 0x2, 0x2, 
    0x1cc, 0x1cd, 0x5, 0x24, 0x13, 0x2, 0x1cd, 0x1ce, 0x7, 0x61, 0x2, 0x2, 
    0x1ce, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cb, 0x3, 0x2, 0x2, 0x2, 
    0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
    0x1d3, 0x5, 0x26, 0x14, 0x2, 0x1d2, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
    0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d6, 
    0x5, 0x28, 0x15, 0x2, 0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 
    0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 
    0x3, 0x2, 0x2, 0x2, 0x1d8, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x5, 
    0x2e, 0x18, 0x2, 0x1da, 0x1db, 0x7, 0x2e, 0x2, 0x2, 0x1db, 0x1dc, 0x5, 
    0x2a, 0x16, 0x2, 0x1dc, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1df, 0x7, 
    0x6d, 0x2, 0x2, 0x1de, 0x1e0, 0x5, 0x2c, 0x17, 0x2, 0x1df, 0x1de, 0x3, 
    0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x1e1, 0x1e4, 0x5, 0xd0, 0x69, 0x2, 0x1e2, 0x1e4, 0x5, 0x3a, 
    0x1e, 0x2, 0x1e3, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e2, 0x3, 0x2, 
    0x2, 0x2, 0x1e4, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1ea, 0x5, 0x30, 
    0x19, 0x2, 0x1e6, 0x1e7, 0x7, 0x5d, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x30, 
    0x19, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x3, 0x2, 
    0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 
    0x2, 0x2, 0x1eb, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 0x2, 
    0x2, 0x1ed, 0x1ee, 0x5, 0x32, 0x1a, 0x2, 0x1ee, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f0, 0x9, 0x2, 0x2, 0x2, 0x1f0, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x1f1, 0x1f3, 0x5, 0x36, 0x1c, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f3, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
    0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1f6, 
    0x1fa, 0x5, 0x46, 0x24, 0x2, 0x1f7, 0x1fa, 0x5, 0x48, 0x25, 0x2, 0x1f8, 
    0x1fa, 0x5, 0x4a, 0x26, 0x2, 0x1f9, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
    0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 0x5, 0x3c, 0x1f, 0x2, 0x1fc, 
    0x1fe, 0x7, 0x6d, 0x2, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fd, 
    0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 
    0x5, 0x3e, 0x20, 0x2, 0x200, 0x202, 0x7, 0x6e, 0x2, 0x2, 0x201, 0x1ff, 
    0x3, 0x2, 0x2, 0x2, 0x201, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x204, 0x7, 0x6d, 0x2, 0x2, 0x204, 0x205, 0x7, 
    0x5e, 0x2, 0x2, 0x205, 0x206, 0x7, 0x6d, 0x2, 0x2, 0x206, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x6d, 0x2, 0x2, 0x208, 0x209, 0x7, 
    0x5e, 0x2, 0x2, 0x209, 0x20a, 0x7, 0x6e, 0x2, 0x2, 0x20a, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x20c, 0x7, 0x64, 0x2, 0x2, 0x20c, 0x20d, 0x5, 
    0x6, 0x4, 0x2, 0x20d, 0x20e, 0x7, 0x5e, 0x2, 0x2, 0x20e, 0x20f, 0x5, 
    0x42, 0x22, 0x2, 0x20f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x8, 
    0x22, 0x1, 0x2, 0x211, 0x212, 0x7, 0x6d, 0x2, 0x2, 0x212, 0x218, 0x3, 
    0x2, 0x2, 0x2, 0x213, 0x214, 0xc, 0x3, 0x2, 0x2, 0x214, 0x215, 0x7, 
    0x5e, 0x2, 0x2, 0x215, 0x217, 0x5, 0x44, 0x23, 0x2, 0x216, 0x213, 0x3, 
    0x2, 0x2, 0x2, 0x217, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x218, 0x216, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x21a, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x9, 0x3, 
    0x2, 0x2, 0x21c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x6d, 
    0x2, 0x2, 0x21e, 0x21f, 0x7, 0x78, 0x2, 0x2, 0x21f, 0x220, 0x5, 0x4e, 
    0x28, 0x2, 0x220, 0x47, 0x3, 0x2, 0x2, 0x2, 0x221, 0x222, 0x7, 0x6e, 
    0x2, 0x2, 0x222, 0x223, 0x5, 0x4e, 0x28, 0x2, 0x223, 0x224, 0x7, 0x78, 
    0x2, 0x2, 0x224, 0x225, 0x5, 0x58, 0x2d, 0x2, 0x225, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x226, 0x227, 0x7, 0x6d, 0x2, 0x2, 0x227, 0x228, 0x5, 0x4e, 
    0x28, 0x2, 0x228, 0x229, 0x7, 0x78, 0x2, 0x2, 0x229, 0x22a, 0x5, 0x4c, 
    0x27, 0x2, 0x22a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x7, 0x68, 
    0x2, 0x2, 0x22c, 0x22d, 0x5, 0x118, 0x8d, 0x2, 0x22d, 0x22e, 0x7, 0x6a, 
    0x2, 0x2, 0x22e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x234, 0x5, 0x50, 
    0x29, 0x2, 0x230, 0x234, 0x5, 0x52, 0x2a, 0x2, 0x231, 0x234, 0x5, 0x10c, 
    0x87, 0x2, 0x232, 0x234, 0x5, 0x56, 0x2c, 0x2, 0x233, 0x22f, 0x3, 0x2, 
    0x2, 0x2, 0x233, 0x230, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 0x3, 0x2, 
    0x2, 0x2, 0x233, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x235, 0x250, 0x5, 0x7a, 0x3e, 0x2, 0x236, 0x250, 0x7, 0x19, 0x2, 
    0x2, 0x237, 0x250, 0x5, 0xea, 0x76, 0x2, 0x238, 0x250, 0x5, 0xae, 0x58, 
    0x2, 0x239, 0x250, 0x7, 0x1f, 0x2, 0x2, 0x23a, 0x250, 0x7, 0x20, 0x2, 
    0x2, 0x23b, 0x250, 0x7, 0x23, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x24, 0x2, 
    0x2, 0x23d, 0x250, 0x7, 0x42, 0x2, 0x2, 0x23e, 0x250, 0x5, 0x6a, 0x36, 
    0x2, 0x23f, 0x250, 0x7, 0x2c, 0x2, 0x2, 0x240, 0x250, 0x5, 0x60, 0x31, 
    0x2, 0x241, 0x250, 0x7, 0x3f, 0x2, 0x2, 0x242, 0x250, 0x7, 0x3b, 0x2, 
    0x2, 0x243, 0x244, 0x7, 0x3c, 0x2, 0x2, 0x244, 0x250, 0x7, 0x2f, 0x2, 
    0x2, 0x245, 0x246, 0x7, 0x3d, 0x2, 0x2, 0x246, 0x250, 0x7, 0x4d, 0x2, 
    0x2, 0x247, 0x250, 0x7, 0x46, 0x2, 0x2, 0x248, 0x250, 0x7, 0x47, 0x2, 
    0x2, 0x249, 0x250, 0x7, 0x48, 0x2, 0x2, 0x24a, 0x250, 0x5, 0x86, 0x44, 
    0x2, 0x24b, 0x250, 0x5, 0x88, 0x45, 0x2, 0x24c, 0x250, 0x5, 0xc2, 0x62, 
    0x2, 0x24d, 0x250, 0x7, 0x50, 0x2, 0x2, 0x24e, 0x250, 0x7, 0x4f, 0x2, 
    0x2, 0x24f, 0x235, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x236, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x237, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x238, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x239, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23a, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23c, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23f, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x240, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x241, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x242, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x245, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x247, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x249, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x250, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x255, 0x5, 0x38, 0x1d, 0x2, 0x252, 0x255, 0x5, 0x10a, 0x86, 
    0x2, 0x253, 0x255, 0x5, 0xc0, 0x61, 0x2, 0x254, 0x251, 0x3, 0x2, 0x2, 
    0x2, 0x254, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x253, 0x3, 0x2, 0x2, 
    0x2, 0x255, 0x53, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x7, 0x6e, 0x2, 
    0x2, 0x257, 0x258, 0x5, 0x4e, 0x28, 0x2, 0x258, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x259, 0x25a, 0x7, 0x55, 0x2, 0x2, 0x25a, 0x25b, 0x7, 0x56, 0x2, 
    0x2, 0x25b, 0x25c, 0x7, 0x57, 0x2, 0x2, 0x25c, 0x25f, 0x7, 0x6e, 0x2, 
    0x2, 0x25d, 0x25f, 0x7, 0x55, 0x2, 0x2, 0x25e, 0x259, 0x3, 0x2, 0x2, 
    0x2, 0x25e, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x260, 0x263, 0x5, 0x5a, 0x2e, 0x2, 0x261, 0x263, 0x5, 0x3a, 0x1e, 0x2, 
    0x262, 0x260, 0x3, 0x2, 0x2, 0x2, 0x262, 0x261, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x59, 0x3, 0x2, 0x2, 0x2, 0x264, 0x278, 0x5, 0x80, 0x41, 0x2, 
    0x265, 0x278, 0x5, 0x5e, 0x30, 0x2, 0x266, 0x278, 0x5, 0xec, 0x77, 0x2, 
    0x267, 0x278, 0x5, 0xbe, 0x60, 0x2, 0x268, 0x278, 0x5, 0xe6, 0x74, 0x2, 
    0x269, 0x278, 0x5, 0x76, 0x3c, 0x2, 0x26a, 0x278, 0x5, 0x68, 0x35, 0x2, 
    0x26b, 0x278, 0x5, 0xe0, 0x71, 0x2, 0x26c, 0x278, 0x7, 0x3b, 0x2, 0x2, 
    0x26d, 0x278, 0x5, 0xd0, 0x69, 0x2, 0x26e, 0x278, 0x5, 0x84, 0x43, 0x2, 
    0x26f, 0x278, 0x5, 0x78, 0x3d, 0x2, 0x270, 0x278, 0x5, 0xe4, 0x73, 0x2, 
    0x271, 0x278, 0x5, 0xda, 0x6e, 0x2, 0x272, 0x278, 0x5, 0xa0, 0x51, 0x2, 
    0x273, 0x278, 0x5, 0xa4, 0x53, 0x2, 0x274, 0x278, 0x5, 0xaa, 0x56, 0x2, 
    0x275, 0x278, 0x5, 0xac, 0x57, 0x2, 0x276, 0x278, 0x5, 0xe8, 0x75, 0x2, 
    0x277, 0x264, 0x3, 0x2, 0x2, 0x2, 0x277, 0x265, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x266, 0x3, 0x2, 0x2, 0x2, 0x277, 0x267, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x268, 0x3, 0x2, 0x2, 0x2, 0x277, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x277, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x277, 0x26d, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x277, 0x26f, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x270, 0x3, 0x2, 0x2, 0x2, 0x277, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x272, 0x3, 0x2, 0x2, 0x2, 0x277, 0x273, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x274, 0x3, 0x2, 0x2, 0x2, 0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x276, 0x3, 0x2, 0x2, 0x2, 0x278, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x279, 
    0x27a, 0x7, 0x6e, 0x2, 0x2, 0x27a, 0x27b, 0x5, 0x58, 0x2d, 0x2, 0x27b, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x9, 0x4, 0x2, 0x2, 0x27d, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x27e, 0x285, 0x7, 0x35, 0x2, 0x2, 0x27f, 0x280, 
    0x7, 0x35, 0x2, 0x2, 0x280, 0x281, 0x7, 0x68, 0x2, 0x2, 0x281, 0x282, 
    0x5, 0x62, 0x32, 0x2, 0x282, 0x283, 0x7, 0x6a, 0x2, 0x2, 0x283, 0x285, 
    0x3, 0x2, 0x2, 0x2, 0x284, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x284, 0x27f, 
    0x3, 0x2, 0x2, 0x2, 0x285, 0x61, 0x3, 0x2, 0x2, 0x2, 0x286, 0x28b, 0x5, 
    0x64, 0x33, 0x2, 0x287, 0x288, 0x7, 0x5d, 0x2, 0x2, 0x288, 0x28a, 0x5, 
    0x64, 0x33, 0x2, 0x289, 0x287, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28d, 0x3, 
    0x2, 0x2, 0x2, 0x28b, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 
    0x2, 0x2, 0x2, 0x28c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28b, 0x3, 0x2, 
    0x2, 0x2, 0x28e, 0x28f, 0x7, 0x6e, 0x2, 0x2, 0x28f, 0x290, 0x7, 0x5a, 
    0x2, 0x2, 0x290, 0x291, 0x5, 0x66, 0x34, 0x2, 0x291, 0x292, 0x7, 0x5b, 
    0x2, 0x2, 0x292, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x7, 0x6e, 
    0x2, 0x2, 0x294, 0x295, 0x7, 0x5a, 0x2, 0x2, 0x295, 0x296, 0x5, 0x3a, 
    0x1e, 0x2, 0x296, 0x297, 0x7, 0x5b, 0x2, 0x2, 0x297, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x298, 0x299, 0x7, 0x6d, 0x2, 0x2, 0x299, 0x29a, 0x7, 0x5a, 
    0x2, 0x2, 0x29a, 0x29b, 0x5, 0x66, 0x34, 0x2, 0x29b, 0x29c, 0x7, 0x5b, 
    0x2, 0x2, 0x29c, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x6d, 
    0x2, 0x2, 0x29e, 0x29f, 0x7, 0x5a, 0x2, 0x2, 0x29f, 0x2a0, 0x5, 0x3a, 
    0x1e, 0x2, 0x2a0, 0x2a1, 0x7, 0x5b, 0x2, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x293, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x298, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x29d, 0x3, 0x2, 
    0x2, 0x2, 0x2a3, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a8, 0x7, 0x70, 
    0x2, 0x2, 0x2a5, 0x2a6, 0x7, 0x6b, 0x2, 0x2, 0x2a6, 0x2a8, 0x7, 0x70, 
    0x2, 0x2, 0x2a7, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a5, 0x3, 0x2, 
    0x2, 0x2, 0x2a8, 0x67, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2ac, 0x5, 0x66, 
    0x34, 0x2, 0x2aa, 0x2ac, 0x7, 0x6e, 0x2, 0x2, 0x2ab, 0x2a9, 0x3, 0x2, 
    0x2, 0x2, 0x2ab, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x2ad, 0x2ae, 0x7, 0x27, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0x68, 0x2, 
    0x2, 0x2af, 0x2b0, 0x5, 0x6c, 0x37, 0x2, 0x2b0, 0x2b1, 0x7, 0x6a, 0x2, 
    0x2, 0x2b1, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2c3, 0x5, 0x6e, 0x38, 
    0x2, 0x2b3, 0x2b4, 0x5, 0x6e, 0x38, 0x2, 0x2b4, 0x2b5, 0x7, 0x5d, 0x2, 
    0x2, 0x2b5, 0x2b7, 0x7, 0x7a, 0x2, 0x2, 0x2b6, 0x2b8, 0x5, 0x16c, 0xb7, 
    0x2, 0x2b7, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 
    0x2, 0x2b8, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x5, 0x6e, 0x38, 
    0x2, 0x2ba, 0x2bb, 0x7, 0x5d, 0x2, 0x2, 0x2bb, 0x2bd, 0x7, 0x7a, 0x2, 
    0x2, 0x2bc, 0x2be, 0x5, 0x16c, 0xb7, 0x2, 0x2bd, 0x2bc, 0x3, 0x2, 0x2, 
    0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 0x2, 
    0x2, 0x2bf, 0x2c0, 0x7, 0x5d, 0x2, 0x2, 0x2c0, 0x2c1, 0x5, 0x70, 0x39, 
    0x2, 0x2c1, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2b2, 0x3, 0x2, 0x2, 
    0x2, 0x2c2, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2b9, 0x3, 0x2, 0x2, 
    0x2, 0x2c3, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 0x5, 0x72, 0x3a, 
    0x2, 0x2c5, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 0x5, 0x72, 0x3a, 
    0x2, 0x2c7, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cd, 0x5, 0x74, 0x3b, 
    0x2, 0x2c9, 0x2ca, 0x7, 0x5d, 0x2, 0x2, 0x2ca, 0x2cc, 0x5, 0x74, 0x3b, 
    0x2, 0x2cb, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cf, 0x3, 0x2, 0x2, 
    0x2, 0x2cd, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x3, 0x2, 0x2, 
    0x2, 0x2ce, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2cd, 0x3, 0x2, 0x2, 0x2, 
    0x2d0, 0x2d3, 0x7, 0x6e, 0x2, 0x2, 0x2d1, 0x2d3, 0x5, 0x64, 0x33, 0x2, 
    0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d1, 0x3, 0x2, 0x2, 0x2, 
    0x2d3, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0x7, 0x6e, 0x2, 0x2, 
    0x2d5, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2de, 0x7, 0x71, 0x2, 0x2, 
    0x2d7, 0x2d8, 0x7, 0x6b, 0x2, 0x2, 0x2d8, 0x2de, 0x7, 0x71, 0x2, 0x2, 
    0x2d9, 0x2de, 0x5, 0xa0, 0x51, 0x2, 0x2da, 0x2de, 0x7, 0x43, 0x2, 0x2, 
    0x2db, 0x2de, 0x7, 0x38, 0x2, 0x2, 0x2dc, 0x2de, 0x7, 0x3a, 0x2, 0x2, 
    0x2dd, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2d7, 0x3, 0x2, 0x2, 0x2, 
    0x2dd, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2da, 0x3, 0x2, 0x2, 0x2, 
    0x2dd, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2dc, 0x3, 0x2, 0x2, 0x2, 
    0x2de, 0x79, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x18, 0x2, 0x2, 
    0x2e0, 0x2e8, 0x7, 0x4d, 0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x18, 0x2, 0x2, 
    0x2e2, 0x2e3, 0x7, 0x4d, 0x2, 0x2, 0x2e3, 0x2e4, 0x7, 0x68, 0x2, 0x2, 
    0x2e4, 0x2e5, 0x5, 0x7c, 0x3f, 0x2, 0x2e5, 0x2e6, 0x7, 0x6a, 0x2, 0x2, 
    0x2e6, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2df, 0x3, 0x2, 0x2, 0x2, 
    0x2e7, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x2e9, 
    0x2ee, 0x5, 0x7e, 0x40, 0x2, 0x2ea, 0x2eb, 0x7, 0x5d, 0x2, 0x2, 0x2eb, 
    0x2ed, 0x5, 0x7e, 0x40, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ed, 
    0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ee, 
    0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ee, 
    0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x6e, 0x2, 0x2, 0x2f2, 0x2f3, 
    0x7, 0x5a, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 0x70, 0x2, 0x2, 0x2f4, 0x2fb, 
    0x7, 0x5b, 0x2, 0x2, 0x2f5, 0x2f6, 0x7, 0x6e, 0x2, 0x2, 0x2f6, 0x2f7, 
    0x7, 0x5a, 0x2, 0x2, 0x2f7, 0x2f8, 0x5, 0x3a, 0x1e, 0x2, 0x2f8, 0x2f9, 
    0x7, 0x5b, 0x2, 0x2, 0x2f9, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2f1, 
    0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x2fc, 0x307, 0x7, 0x72, 0x2, 0x2, 0x2fd, 0x307, 0x7, 
    0x73, 0x2, 0x2, 0x2fe, 0x2ff, 0x7, 0x68, 0x2, 0x2, 0x2ff, 0x300, 0x5, 
    0x82, 0x42, 0x2, 0x300, 0x301, 0x7, 0x6a, 0x2, 0x2, 0x301, 0x307, 0x3, 
    0x2, 0x2, 0x2, 0x302, 0x303, 0x7, 0x68, 0x2, 0x2, 0x303, 0x307, 0x7, 
    0x6a, 0x2, 0x2, 0x304, 0x305, 0x7, 0x1e, 0x2, 0x2, 0x305, 0x307, 0x5, 
    0x58, 0x2d, 0x2, 0x306, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x306, 0x2fd, 0x3, 
    0x2, 0x2, 0x2, 0x306, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x306, 0x302, 0x3, 
    0x2, 0x2, 0x2, 0x306, 0x304, 0x3, 0x2, 0x2, 0x2, 0x307, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x308, 0x30d, 0x7, 0x6e, 0x2, 0x2, 0x309, 0x30a, 0x7, 0x5d, 
    0x2, 0x2, 0x30a, 0x30c, 0x7, 0x6e, 0x2, 0x2, 0x30b, 0x309, 0x3, 0x2, 
    0x2, 0x2, 0x30c, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30b, 0x3, 0x2, 
    0x2, 0x2, 0x30d, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x30f, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x310, 0x315, 0x7, 0x72, 0x2, 
    0x2, 0x311, 0x315, 0x7, 0x73, 0x2, 0x2, 0x312, 0x313, 0x7, 0x1e, 0x2, 
    0x2, 0x313, 0x315, 0x5, 0x58, 0x2d, 0x2, 0x314, 0x310, 0x3, 0x2, 0x2, 
    0x2, 0x314, 0x311, 0x3, 0x2, 0x2, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 
    0x2, 0x315, 0x85, 0x3, 0x2, 0x2, 0x2, 0x316, 0x317, 0x7, 0x49, 0x2, 
    0x2, 0x317, 0x318, 0x7, 0x68, 0x2, 0x2, 0x318, 0x31f, 0x7, 0x6a, 0x2, 
    0x2, 0x319, 0x31a, 0x7, 0x49, 0x2, 0x2, 0x31a, 0x31b, 0x7, 0x68, 0x2, 
    0x2, 0x31b, 0x31c, 0x5, 0x8e, 0x48, 0x2, 0x31c, 0x31d, 0x7, 0x6a, 0x2, 
    0x2, 0x31d, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x316, 0x3, 0x2, 0x2, 
    0x2, 0x31e, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x320, 0x321, 0x7, 0x49, 0x2, 0x2, 0x321, 0x322, 0x7, 0x3e, 0x2, 0x2, 
    0x322, 0x32d, 0x5, 0x4e, 0x28, 0x2, 0x323, 0x324, 0x7, 0x49, 0x2, 0x2, 
    0x324, 0x325, 0x7, 0x3e, 0x2, 0x2, 0x325, 0x32d, 0x5, 0x54, 0x2b, 0x2, 
    0x326, 0x327, 0x7, 0x4b, 0x2, 0x2, 0x327, 0x328, 0x7, 0x3e, 0x2, 0x2, 
    0x328, 0x32d, 0x5, 0x4e, 0x28, 0x2, 0x329, 0x32a, 0x7, 0x4b, 0x2, 0x2, 
    0x32a, 0x32b, 0x7, 0x3e, 0x2, 0x2, 0x32b, 0x32d, 0x5, 0x54, 0x2b, 0x2, 
    0x32c, 0x320, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x323, 0x3, 0x2, 0x2, 0x2, 
    0x32c, 0x326, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x329, 0x3, 0x2, 0x2, 0x2, 
    0x32d, 0x89, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x330, 0x7, 0x7a, 0x2, 0x2, 
    0x32f, 0x331, 0x5, 0x16c, 0xb7, 0x2, 0x330, 0x32f, 0x3, 0x2, 0x2, 0x2, 
    0x330, 0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x332, 
    0x333, 0x7, 0x5d, 0x2, 0x2, 0x333, 0x334, 0x7, 0x7a, 0x2, 0x2, 0x334, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x335, 0x358, 0x5, 0x9c, 0x4f, 0x2, 0x336, 
    0x337, 0x5, 0x9c, 0x4f, 0x2, 0x337, 0x338, 0x7, 0x5d, 0x2, 0x2, 0x338, 
    0x33a, 0x5, 0x8a, 0x46, 0x2, 0x339, 0x33b, 0x5, 0x92, 0x4a, 0x2, 0x33a, 
    0x339, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33b, 
    0x33c, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x5, 0x8c, 0x47, 0x2, 0x33d, 
    0x358, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x5, 0x9c, 0x4f, 0x2, 0x33f, 
    0x340, 0x7, 0x5d, 0x2, 0x2, 0x340, 0x342, 0x5, 0x8a, 0x46, 0x2, 0x341, 
    0x343, 0x5, 0x92, 0x4a, 0x2, 0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x342, 
    0x343, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 
    0x345, 0x5, 0x90, 0x49, 0x2, 0x345, 0x346, 0x7, 0x5d, 0x2, 0x2, 0x346, 
    0x347, 0x5, 0x9c, 0x4f, 0x2, 0x347, 0x358, 0x3, 0x2, 0x2, 0x2, 0x348, 
    0x34a, 0x5, 0x8a, 0x46, 0x2, 0x349, 0x34b, 0x5, 0x92, 0x4a, 0x2, 0x34a, 
    0x349, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34b, 
    0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x5, 0x90, 0x49, 0x2, 0x34d, 
    0x34e, 0x7, 0x5d, 0x2, 0x2, 0x34e, 0x34f, 0x5, 0x9c, 0x4f, 0x2, 0x34f, 
    0x358, 0x3, 0x2, 0x2, 0x2, 0x350, 0x352, 0x5, 0x8a, 0x46, 0x2, 0x351, 
    0x353, 0x5, 0x92, 0x4a, 0x2, 0x352, 0x351, 0x3, 0x2, 0x2, 0x2, 0x352, 
    0x353, 0x3, 0x2, 0x2, 0x2, 0x353, 0x355, 0x3, 0x2, 0x2, 0x2, 0x354, 
    0x356, 0x5, 0x8c, 0x47, 0x2, 0x355, 0x354, 0x3, 0x2, 0x2, 0x2, 0x355, 
    0x356, 0x3, 0x2, 0x2, 0x2, 0x356, 0x358, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x335, 0x3, 0x2, 0x2, 0x2, 0x357, 0x336, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x33e, 0x3, 0x2, 0x2, 0x2, 0x357, 0x348, 0x3, 0x2, 0x2, 0x2, 0x357, 
    0x350, 0x3, 0x2, 0x2, 0x2, 0x358, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 
    0x7, 0x5d, 0x2, 0x2, 0x35a, 0x35b, 0x7, 0x7a, 0x2, 0x2, 0x35b, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x7, 0x5d, 0x2, 0x2, 0x35d, 0x35e, 
    0x5, 0x94, 0x4b, 0x2, 0x35e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x364, 
    0x5, 0x96, 0x4c, 0x2, 0x360, 0x361, 0x7, 0x5d, 0x2, 0x2, 0x361, 0x363, 
    0x5, 0x96, 0x4c, 0x2, 0x362, 0x360, 0x3, 0x2, 0x2, 0x2, 0x363, 0x366, 
    0x3, 0x2, 0x2, 0x2, 0x364, 0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 
    0x3, 0x2, 0x2, 0x2, 0x365, 0x95, 0x3, 0x2, 0x2, 0x2, 0x366, 0x364, 0x3, 
    0x2, 0x2, 0x2, 0x367, 0x36a, 0x5, 0x9e, 0x50, 0x2, 0x368, 0x36a, 0x5, 
    0x98, 0x4d, 0x2, 0x369, 0x367, 0x3, 0x2, 0x2, 0x2, 0x369, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x36a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36d, 0x7, 0x7b, 
    0x2, 0x2, 0x36c, 0x36e, 0x5, 0x9a, 0x4e, 0x2, 0x36d, 0x36c, 0x3, 0x2, 
    0x2, 0x2, 0x36d, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 
    0x2, 0x2, 0x36f, 0x370, 0x5, 0x9c, 0x4f, 0x2, 0x370, 0x371, 0x7, 0x7c, 
    0x2, 0x2, 0x371, 0x99, 0x3, 0x2, 0x2, 0x2, 0x372, 0x373, 0x7, 0x70, 
    0x2, 0x2, 0x373, 0x374, 0x7, 0x60, 0x2, 0x2, 0x374, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x375, 0x37a, 0x5, 0x9e, 0x50, 0x2, 0x376, 0x377, 0x7, 0x5d, 
    0x2, 0x2, 0x377, 0x379, 0x5, 0x9e, 0x50, 0x2, 0x378, 0x376, 0x3, 0x2, 
    0x2, 0x2, 0x379, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x378, 0x3, 0x2, 
    0x2, 0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x37c, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x5, 0x54, 0x2b, 
    0x2, 0x37e, 0x37f, 0x7, 0x40, 0x2, 0x2, 0x37f, 0x389, 0x3, 0x2, 0x2, 
    0x2, 0x380, 0x381, 0x5, 0x54, 0x2b, 0x2, 0x381, 0x382, 0x7, 0x21, 0x2, 
    0x2, 0x382, 0x383, 0x5, 0x58, 0x2d, 0x2, 0x383, 0x389, 0x3, 0x2, 0x2, 
    0x2, 0x384, 0x389, 0x5, 0x54, 0x2b, 0x2, 0x385, 0x386, 0x7, 0x1c, 0x2, 
    0x2, 0x386, 0x387, 0x7, 0x3e, 0x2, 0x2, 0x387, 0x389, 0x5, 0x4e, 0x28, 
    0x2, 0x388, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x388, 0x380, 0x3, 0x2, 0x2, 
    0x2, 0x388, 0x384, 0x3, 0x2, 0x2, 0x2, 0x388, 0x385, 0x3, 0x2, 0x2, 
    0x2, 0x389, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38c, 0x7, 0x68, 0x2, 
    0x2, 0x38b, 0x38d, 0x5, 0xa2, 0x52, 0x2, 0x38c, 0x38b, 0x3, 0x2, 0x2, 
    0x2, 0x38c, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x3, 0x2, 0x2, 
    0x2, 0x38e, 0x38f, 0x7, 0x6a, 0x2, 0x2, 0x38f, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x390, 0x395, 0x5, 0x5c, 0x2f, 0x2, 0x391, 0x392, 0x7, 0x5d, 0x2, 
    0x2, 0x392, 0x394, 0x5, 0x5c, 0x2f, 0x2, 0x393, 0x391, 0x3, 0x2, 0x2, 
    0x2, 0x394, 0x397, 0x3, 0x2, 0x2, 0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 
    0x2, 0x395, 0x396, 0x3, 0x2, 0x2, 0x2, 0x396, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0x397, 0x395, 0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 0x7, 0x68, 0x2, 0x2, 
    0x399, 0x39a, 0x5, 0xa6, 0x54, 0x2, 0x39a, 0x39b, 0x7, 0x6a, 0x2, 0x2, 
    0x39b, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 0x7, 0x68, 0x2, 0x2, 
    0x39d, 0x39e, 0x5, 0xa8, 0x55, 0x2, 0x39e, 0x39f, 0x7, 0x6a, 0x2, 0x2, 
    0x39f, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x7, 0x68, 0x2, 0x2, 
    0x3a1, 0x3a3, 0x7, 0x6a, 0x2, 0x2, 0x3a2, 0x398, 0x3, 0x2, 0x2, 0x2, 
    0x3a2, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a0, 0x3, 0x2, 0x2, 0x2, 
    0x3a3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a9, 0x5, 0x58, 0x2d, 0x2, 
    0x3a5, 0x3a6, 0x7, 0x5d, 0x2, 0x2, 0x3a6, 0x3a8, 0x5, 0x58, 0x2d, 0x2, 
    0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3ab, 0x3, 0x2, 0x2, 0x2, 
    0x3a9, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 
    0x3aa, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
    0x3b1, 0x5, 0x5c, 0x2f, 0x2, 0x3ad, 0x3ae, 0x7, 0x5d, 0x2, 0x2, 0x3ae, 
    0x3b0, 0x5, 0x5c, 0x2f, 0x2, 0x3af, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3b0, 
    0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3b1, 
    0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b1, 
    0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b6, 0x7, 0x68, 0x2, 0x2, 0x3b5, 0x3b7, 
    0x5, 0xa2, 0x52, 0x2, 0x3b6, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b7, 
    0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 
    0x7, 0x6a, 0x2, 0x2, 0x3b9, 0xab, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bb, 
    0x7, 0x68, 0x2, 0x2, 0x3bb, 0x3bc, 0x5, 0xa6, 0x54, 0x2, 0x3bc, 0x3bd, 
    0x7, 0x6a, 0x2, 0x2, 0x3bd, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 
    0x7, 0x68, 0x2, 0x2, 0x3bf, 0x3c0, 0x5, 0xa8, 0x55, 0x2, 0x3c0, 0x3c1, 
    0x7, 0x6a, 0x2, 0x2, 0x3c1, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c3, 
    0x7, 0x68, 0x2, 0x2, 0x3c3, 0x3c5, 0x7, 0x6a, 0x2, 0x2, 0x3c4, 0x3ba, 
    0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c2, 
    0x3, 0x2, 0x2, 0x2, 0x3c5, 0xad, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x7, 
    0x1b, 0x2, 0x2, 0x3c7, 0x3c8, 0x7, 0x68, 0x2, 0x2, 0x3c8, 0x3c9, 0x5, 
    0xb0, 0x59, 0x2, 0x3c9, 0x3ca, 0x7, 0x6a, 0x2, 0x2, 0x3ca, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x3cb, 0x3d5, 0x5, 0xb2, 0x5a, 0x2, 0x3cc, 0x3cd, 0x5, 
    0xb2, 0x5a, 0x2, 0x3cd, 0x3ce, 0x7, 0x5d, 0x2, 0x2, 0x3ce, 0x3d0, 0x5, 
    0x8a, 0x46, 0x2, 0x3cf, 0x3d1, 0x5, 0xb4, 0x5b, 0x2, 0x3d0, 0x3cf, 0x3, 
    0x2, 0x2, 0x2, 0x3d0, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d2, 0x3, 
    0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x5, 0x8c, 0x47, 0x2, 0x3d3, 0x3d5, 0x3, 
    0x2, 0x2, 0x2, 0x3d4, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3cc, 0x3, 
    0x2, 0x2, 0x2, 0x3d5, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d7, 0x5, 0xbc, 
    0x5f, 0x2, 0x3d7, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3d9, 0x7, 0x5d, 
    0x2, 0x2, 0x3d9, 0x3da, 0x5, 0xb6, 0x5c, 0x2, 0x3da, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0x3db, 0x3e0, 0x5, 0xb8, 0x5d, 0x2, 0x3dc, 0x3dd, 0x7, 0x5d, 
    0x2, 0x2, 0x3dd, 0x3df, 0x5, 0xb8, 0x5d, 0x2, 0x3de, 0x3dc, 0x3, 0x2, 
    0x2, 0x2, 0x3df, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3de, 0x3, 0x2, 
    0x2, 0x2, 0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x3e2, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e6, 0x5, 0xba, 0x5e, 
    0x2, 0x3e4, 0x3e6, 0x5, 0x54, 0x2b, 0x2, 0x3e5, 0x3e3, 0x3, 0x2, 0x2, 
    0x2, 0x3e5, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0x3e7, 0x3e8, 0x7, 0x7b, 0x2, 0x2, 0x3e8, 0x3e9, 0x5, 0x9a, 0x4e, 0x2, 
    0x3e9, 0x3ea, 0x5, 0xbc, 0x5f, 0x2, 0x3ea, 0x3eb, 0x7, 0x7c, 0x2, 0x2, 
    0x3eb, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3f1, 0x5, 0x54, 0x2b, 0x2, 
    0x3ed, 0x3ee, 0x7, 0x5d, 0x2, 0x2, 0x3ee, 0x3f0, 0x5, 0x54, 0x2b, 0x2, 
    0x3ef, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3f3, 0x3, 0x2, 0x2, 0x2, 
    0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x3, 0x2, 0x2, 0x2, 
    0x3f2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f4, 
    0x3f5, 0x7, 0x6e, 0x2, 0x2, 0x3f5, 0x3f6, 0x7, 0x60, 0x2, 0x2, 0x3f6, 
    0x3f7, 0x5, 0x58, 0x2d, 0x2, 0x3f7, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x3f8, 
    0x3f9, 0x7, 0x6e, 0x2, 0x2, 0x3f9, 0x3fa, 0x7, 0x62, 0x2, 0x2, 0x3fa, 
    0x3fb, 0x5, 0x4e, 0x28, 0x2, 0x3fb, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
    0x3ff, 0x5, 0xc4, 0x63, 0x2, 0x3fd, 0x3ff, 0x5, 0xcc, 0x67, 0x2, 0x3fe, 
    0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3ff, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 0x5, 0xc6, 0x64, 0x2, 0x401, 
    0x402, 0x5, 0x4e, 0x28, 0x2, 0x402, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x403, 
    0x404, 0x5, 0xc6, 0x64, 0x2, 0x404, 0x405, 0x7, 0x30, 0x2, 0x2, 0x405, 
    0x406, 0x5, 0x4e, 0x28, 0x2, 0x406, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x407, 
    0x408, 0x5, 0xc6, 0x64, 0x2, 0x408, 0x409, 0x7, 0x29, 0x2, 0x2, 0x409, 
    0x40a, 0x5, 0x4e, 0x28, 0x2, 0x40a, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40b, 
    0x400, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x403, 0x3, 0x2, 0x2, 0x2, 0x40b, 
    0x407, 0x3, 0x2, 0x2, 0x2, 0x40c, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x410, 
    0x7, 0x65, 0x2, 0x2, 0x40e, 0x40f, 0x7, 0x7d, 0x2, 0x2, 0x40f, 0x411, 
    0x7, 0x60, 0x2, 0x2, 0x410, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 
    0x3, 0x2, 0x2, 0x2, 0x411, 0x413, 0x3, 0x2, 0x2, 0x2, 0x412, 0x414, 
    0x5, 0xca, 0x66, 0x2, 0x413, 0x412, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 
    0x3, 0x2, 0x2, 0x2, 0x414, 0x415, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 
    0x5, 0xc8, 0x65, 0x2, 0x416, 0x417, 0x7, 0x66, 0x2, 0x2, 0x417, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0x418, 0x41b, 0x7, 0x70, 0x2, 0x2, 0x419, 0x41b, 
    0x5, 0x3a, 0x1e, 0x2, 0x41a, 0x418, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x419, 
    0x3, 0x2, 0x2, 0x2, 0x41b, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x9, 
    0x5, 0x2, 0x2, 0x41d, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 0x5, 0xce, 
    0x68, 0x2, 0x41f, 0x420, 0x5, 0x4e, 0x28, 0x2, 0x420, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0x421, 0x424, 0x7, 0x65, 0x2, 0x2, 0x422, 0x423, 0x7, 0x7d, 
    0x2, 0x2, 0x423, 0x425, 0x7, 0x60, 0x2, 0x2, 0x424, 0x422, 0x3, 0x2, 
    0x2, 0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 0x2, 0x425, 0x426, 0x3, 0x2, 
    0x2, 0x2, 0x426, 0x427, 0x7, 0x7d, 0x2, 0x2, 0x427, 0x428, 0x7, 0x66, 
    0x2, 0x2, 0x428, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42b, 0x7, 0x68, 
    0x2, 0x2, 0x42a, 0x42c, 0x5, 0xd2, 0x6a, 0x2, 0x42b, 0x42a, 0x3, 0x2, 
    0x2, 0x2, 0x42c, 0x42d, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42b, 0x3, 0x2, 
    0x2, 0x2, 0x42d, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 0x3, 0x2, 
    0x2, 0x2, 0x42f, 0x430, 0x7, 0x6a, 0x2, 0x2, 0x430, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0x431, 0x436, 0x5, 0xd4, 0x6b, 0x2, 0x432, 0x436, 0x5, 0xd6, 
    0x6c, 0x2, 0x433, 0x436, 0x5, 0xd8, 0x6d, 0x2, 0x434, 0x436, 0x5, 0x3a, 
    0x1e, 0x2, 0x435, 0x431, 0x3, 0x2, 0x2, 0x2, 0x435, 0x432, 0x3, 0x2, 
    0x2, 0x2, 0x435, 0x433, 0x3, 0x2, 0x2, 0x2, 0x435, 0x434, 0x3, 0x2, 
    0x2, 0x2, 0x436, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x437, 0x438, 0x7, 0x6e, 
    0x2, 0x2, 0x438, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x439, 0x43c, 0x7, 0x70, 
    0x2, 0x2, 0x43a, 0x43c, 0x5, 0x3a, 0x1e, 0x2, 0x43b, 0x439, 0x3, 0x2, 
    0x2, 0x2, 0x43b, 0x43a, 0x3, 0x2, 0x2, 0x2, 0x43c, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0x43d, 0x43e, 0x7, 0x6e, 0x2, 0x2, 0x43e, 0x43f, 0x7, 0x5a, 0x2, 
    0x2, 0x43f, 0x440, 0x5, 0xd6, 0x6c, 0x2, 0x440, 0x441, 0x7, 0x5b, 0x2, 
    0x2, 0x441, 0x448, 0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x7, 0x6d, 0x2, 
    0x2, 0x443, 0x444, 0x7, 0x5a, 0x2, 0x2, 0x444, 0x445, 0x5, 0xd6, 0x6c, 
    0x2, 0x445, 0x446, 0x7, 0x5b, 0x2, 0x2, 0x446, 0x448, 0x3, 0x2, 0x2, 
    0x2, 0x447, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x447, 0x442, 0x3, 0x2, 0x2, 
    0x2, 0x448, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x449, 0x44a, 0x7, 0x68, 0x2, 
    0x2, 0x44a, 0x44b, 0x5, 0xdc, 0x6f, 0x2, 0x44b, 0x44c, 0x7, 0x6a, 0x2, 
    0x2, 0x44c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x44f, 0x5, 0xde, 0x70, 
    0x2, 0x44e, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x450, 0x3, 0x2, 0x2, 
    0x2, 0x450, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x450, 0x451, 0x3, 0x2, 0x2, 
    0x2, 0x451, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x452, 0x456, 0x5, 0xd6, 0x6c, 
    0x2, 0x453, 0x456, 0x5, 0xd8, 0x6d, 0x2, 0x454, 0x456, 0x5, 0x3a, 0x1e, 
    0x2, 0x455, 0x452, 0x3, 0x2, 0x2, 0x2, 0x455, 0x453, 0x3, 0x2, 0x2, 
    0x2, 0x455, 0x454, 0x3, 0x2, 0x2, 0x2, 0x456, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0x457, 0x45a, 0x7, 0x59, 0x2, 0x2, 0x458, 0x459, 0x7, 0x5f, 0x2, 0x2, 
    0x459, 0x45b, 0x5, 0xe2, 0x72, 0x2, 0x45a, 0x458, 0x3, 0x2, 0x2, 0x2, 
    0x45b, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45a, 0x3, 0x2, 0x2, 0x2, 
    0x45c, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x45e, 0x3, 0x2, 0x2, 0x2, 
    0x45e, 0x45f, 0x7, 0x59, 0x2, 0x2, 0x45f, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0x460, 0x46a, 0x7, 0x70, 0x2, 0x2, 0x461, 0x462, 0x7, 0x6e, 0x2, 0x2, 
    0x462, 0x463, 0x7, 0x5a, 0x2, 0x2, 0x463, 0x464, 0x7, 0x70, 0x2, 0x2, 
    0x464, 0x46a, 0x7, 0x5b, 0x2, 0x2, 0x465, 0x466, 0x7, 0x6d, 0x2, 0x2, 
    0x466, 0x467, 0x7, 0x5a, 0x2, 0x2, 0x467, 0x468, 0x7, 0x70, 0x2, 0x2, 
    0x468, 0x46a, 0x7, 0x5b, 0x2, 0x2, 0x469, 0x460, 0x3, 0x2, 0x2, 0x2, 
    0x469, 0x461, 0x3, 0x2, 0x2, 0x2, 0x469, 0x465, 0x3, 0x2, 0x2, 0x2, 
    0x46a, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x46c, 0x7, 0x59, 0x2, 0x2, 
    0x46c, 0x46f, 0x5, 0xe2, 0x72, 0x2, 0x46d, 0x46e, 0x7, 0x5f, 0x2, 0x2, 
    0x46e, 0x470, 0x5, 0xe2, 0x72, 0x2, 0x46f, 0x46d, 0x3, 0x2, 0x2, 0x2, 
    0x470, 0x471, 0x3, 0x2, 0x2, 0x2, 0x471, 0x46f, 0x3, 0x2, 0x2, 0x2, 
    0x471, 0x472, 0x3, 0x2, 0x2, 0x2, 0x472, 0x473, 0x3, 0x2, 0x2, 0x2, 
    0x473, 0x474, 0x7, 0x59, 0x2, 0x2, 0x474, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0x475, 0x476, 0x5, 0xa0, 0x51, 0x2, 0x476, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0x477, 0x478, 0x7, 0x76, 0x2, 0x2, 0x478, 0xe9, 0x3, 0x2, 0x2, 0x2, 
    0x479, 0x47c, 0x5, 0xee, 0x78, 0x2, 0x47a, 0x47c, 0x5, 0x106, 0x84, 
    0x2, 0x47b, 0x479, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47a, 0x3, 0x2, 0x2, 
    0x2, 0x47c, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x480, 0x5, 0xf0, 0x79, 
    0x2, 0x47e, 0x480, 0x5, 0x108, 0x85, 0x2, 0x47f, 0x47d, 0x3, 0x2, 0x2, 
    0x2, 0x47f, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x480, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0x481, 0x482, 0x9, 0x6, 0x2, 0x2, 0x482, 0xef, 0x3, 0x2, 0x2, 0x2, 0x483, 
    0x488, 0x7, 0x74, 0x2, 0x2, 0x484, 0x488, 0x5, 0xf2, 0x7a, 0x2, 0x485, 
    0x488, 0x5, 0xf6, 0x7c, 0x2, 0x486, 0x488, 0x5, 0x100, 0x81, 0x2, 0x487, 
    0x483, 0x3, 0x2, 0x2, 0x2, 0x487, 0x484, 0x3, 0x2, 0x2, 0x2, 0x487, 
    0x485, 0x3, 0x2, 0x2, 0x2, 0x487, 0x486, 0x3, 0x2, 0x2, 0x2, 0x488, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48a, 0x7, 0x68, 0x2, 0x2, 0x48a, 
    0x48f, 0x5, 0xf4, 0x7b, 0x2, 0x48b, 0x48c, 0x7, 0x5d, 0x2, 0x2, 0x48c, 
    0x48e, 0x5, 0xf4, 0x7b, 0x2, 0x48d, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x48e, 
    0x491, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48f, 
    0x490, 0x3, 0x2, 0x2, 0x2, 0x490, 0x492, 0x3, 0x2, 0x2, 0x2, 0x491, 
    0x48f, 0x3, 0x2, 0x2, 0x2, 0x492, 0x493, 0x7, 0x6a, 0x2, 0x2, 0x493, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0x494, 0x499, 0x7, 0x74, 0x2, 0x2, 0x495, 
    0x499, 0x5, 0xf6, 0x7c, 0x2, 0x496, 0x499, 0x5, 0x100, 0x81, 0x2, 0x497, 
    0x499, 0x5, 0x3a, 0x1e, 0x2, 0x498, 0x494, 0x3, 0x2, 0x2, 0x2, 0x498, 
    0x495, 0x3, 0x2, 0x2, 0x2, 0x498, 0x496, 0x3, 0x2, 0x2, 0x2, 0x498, 
    0x497, 0x3, 0x2, 0x2, 0x2, 0x499, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x49b, 
    0x7, 0x68, 0x2, 0x2, 0x49b, 0x49c, 0x5, 0xf8, 0x7d, 0x2, 0x49c, 0x49d, 
    0x7, 0x5d, 0x2, 0x2, 0x49d, 0x49e, 0x5, 0xfa, 0x7e, 0x2, 0x49e, 0x49f, 
    0x7, 0x5d, 0x2, 0x2, 0x49f, 0x4a0, 0x5, 0xfc, 0x7f, 0x2, 0x4a0, 0x4a1, 
    0x7, 0x5d, 0x2, 0x2, 0x4a1, 0x4a2, 0x5, 0xfe, 0x80, 0x2, 0x4a2, 0x4a3, 
    0x7, 0x6a, 0x2, 0x2, 0x4a3, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x4a4, 0x4a5, 
    0x7, 0x70, 0x2, 0x2, 0x4a5, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 
    0x7, 0x70, 0x2, 0x2, 0x4a7, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 
    0x7, 0x70, 0x2, 0x2, 0x4a9, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ab, 
    0x7, 0x70, 0x2, 0x2, 0x4ab, 0xff, 0x3, 0x2, 0x2, 0x2, 0x4ac, 0x4ad, 
    0x7, 0x68, 0x2, 0x2, 0x4ad, 0x4ae, 0x5, 0x102, 0x82, 0x2, 0x4ae, 0x4af, 
    0x7, 0x5d, 0x2, 0x2, 0x4af, 0x4b0, 0x5, 0x104, 0x83, 0x2, 0x4b0, 0x4b1, 
    0x7, 0x6a, 0x2, 0x2, 0x4b1, 0x101, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 
    0x7, 0x70, 0x2, 0x2, 0x4b3, 0x103, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b5, 
    0x7, 0x70, 0x2, 0x2, 0x4b5, 0x105, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b7, 
    0x7, 0x1a, 0x2, 0x2, 0x4b7, 0x4b8, 0x7, 0x4d, 0x2, 0x2, 0x4b8, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4ba, 0x5, 0xa0, 0x51, 0x2, 0x4ba, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x4bb, 0x4bc, 0x9, 0x7, 0x2, 0x2, 0x4bc, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4c0, 0x5, 0x50, 0x29, 0x2, 0x4be, 0x4c0, 
    0x5, 0x52, 0x2a, 0x2, 0x4bf, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4be, 
    0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4c1, 0x4c2, 
    0x5, 0x110, 0x89, 0x2, 0x4c2, 0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c5, 
    0x5, 0x10e, 0x88, 0x2, 0x4c4, 0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4c4, 0x4c3, 
    0x3, 0x2, 0x2, 0x2, 0x4c5, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c7, 
    0x7, 0x4b, 0x2, 0x2, 0x4c7, 0x4c8, 0x5, 0x110, 0x89, 0x2, 0x4c8, 0x4c9, 
    0x7, 0x3e, 0x2, 0x2, 0x4c9, 0x4ca, 0x5, 0x4e, 0x28, 0x2, 0x4ca, 0x4ef, 
    0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cc, 0x7, 0x4b, 0x2, 0x2, 0x4cc, 0x4cd, 
    0x5, 0x112, 0x8a, 0x2, 0x4cd, 0x4ce, 0x7, 0x3e, 0x2, 0x2, 0x4ce, 0x4cf, 
    0x5, 0x4e, 0x28, 0x2, 0x4cf, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4d1, 
    0x7, 0x49, 0x2, 0x2, 0x4d1, 0x4d2, 0x5, 0x110, 0x89, 0x2, 0x4d2, 0x4d3, 
    0x7, 0x3e, 0x2, 0x2, 0x4d3, 0x4d4, 0x5, 0x4e, 0x28, 0x2, 0x4d4, 0x4ef, 
    0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4d6, 0x7, 0x49, 0x2, 0x2, 0x4d6, 0x4d7, 
    0x5, 0x112, 0x8a, 0x2, 0x4d7, 0x4d8, 0x7, 0x3e, 0x2, 0x2, 0x4d8, 0x4d9, 
    0x5, 0x4e, 0x28, 0x2, 0x4d9, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4db, 
    0x7, 0x4b, 0x2, 0x2, 0x4db, 0x4dc, 0x5, 0x110, 0x89, 0x2, 0x4dc, 0x4dd, 
    0x7, 0x3e, 0x2, 0x2, 0x4dd, 0x4de, 0x5, 0x54, 0x2b, 0x2, 0x4de, 0x4ef, 
    0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e0, 0x7, 0x4b, 0x2, 0x2, 0x4e0, 0x4e1, 
    0x5, 0x112, 0x8a, 0x2, 0x4e1, 0x4e2, 0x7, 0x3e, 0x2, 0x2, 0x4e2, 0x4e3, 
    0x5, 0x54, 0x2b, 0x2, 0x4e3, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e5, 
    0x7, 0x49, 0x2, 0x2, 0x4e5, 0x4e6, 0x5, 0x110, 0x89, 0x2, 0x4e6, 0x4e7, 
    0x7, 0x3e, 0x2, 0x2, 0x4e7, 0x4e8, 0x5, 0x54, 0x2b, 0x2, 0x4e8, 0x4ef, 
    0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4ea, 0x7, 0x49, 0x2, 0x2, 0x4ea, 0x4eb, 
    0x5, 0x112, 0x8a, 0x2, 0x4eb, 0x4ec, 0x7, 0x3e, 0x2, 0x2, 0x4ec, 0x4ed, 
    0x5, 0x54, 0x2b, 0x2, 0x4ed, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4c6, 
    0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4d0, 
    0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4da, 
    0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4e4, 
    0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x10f, 
    0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f1, 0x7, 0x5a, 0x2, 0x2, 0x4f1, 0x4f3, 
    0x5, 0x114, 0x8b, 0x2, 0x4f2, 0x4f4, 0x5, 0x16c, 0xb7, 0x2, 0x4f3, 0x4f2, 
    0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f5, 
    0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f6, 0x7, 0x5b, 0x2, 0x2, 0x4f6, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f8, 0x7, 0x4c, 0x2, 0x2, 0x4f8, 0x4f9, 
    0x5, 0x110, 0x89, 0x2, 0x4f9, 0x113, 0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4fb, 
    0x5, 0x116, 0x8c, 0x2, 0x4fb, 0x115, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 
    0x5, 0x118, 0x8d, 0x2, 0x4fd, 0x117, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x50a, 
    0x5, 0x11a, 0x8e, 0x2, 0x4ff, 0x500, 0x5, 0x11a, 0x8e, 0x2, 0x500, 0x501, 
    0x7, 0x5d, 0x2, 0x2, 0x501, 0x502, 0x7, 0x7a, 0x2, 0x2, 0x502, 0x50a, 
    0x3, 0x2, 0x2, 0x2, 0x503, 0x504, 0x5, 0x11a, 0x8e, 0x2, 0x504, 0x505, 
    0x7, 0x5d, 0x2, 0x2, 0x505, 0x506, 0x7, 0x7a, 0x2, 0x2, 0x506, 0x507, 
    0x7, 0x5d, 0x2, 0x2, 0x507, 0x508, 0x5, 0x11c, 0x8f, 0x2, 0x508, 0x50a, 
    0x3, 0x2, 0x2, 0x2, 0x509, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x509, 0x4ff, 
    0x3, 0x2, 0x2, 0x2, 0x509, 0x503, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x50b, 0x50c, 0x5, 0x11e, 0x90, 0x2, 0x50c, 0x11b, 
    0x3, 0x2, 0x2, 0x2, 0x50d, 0x50e, 0x5, 0x11e, 0x90, 0x2, 0x50e, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x50f, 0x513, 0x5, 0x120, 0x91, 0x2, 0x510, 0x511, 
    0x7, 0x14, 0x2, 0x2, 0x511, 0x513, 0x5, 0x128, 0x95, 0x2, 0x512, 0x50f, 
    0x3, 0x2, 0x2, 0x2, 0x512, 0x510, 0x3, 0x2, 0x2, 0x2, 0x513, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x514, 0x515, 0x8, 0x91, 0x1, 0x2, 0x515, 0x516, 
    0x5, 0x122, 0x92, 0x2, 0x516, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x517, 0x518, 
    0xc, 0x3, 0x2, 0x2, 0x518, 0x519, 0x5, 0x12a, 0x96, 0x2, 0x519, 0x51a, 
    0x5, 0x122, 0x92, 0x2, 0x51a, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x517, 
    0x3, 0x2, 0x2, 0x2, 0x51c, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51b, 
    0x3, 0x2, 0x2, 0x2, 0x51d, 0x51e, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x51f, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x520, 0x526, 
    0x5, 0x124, 0x93, 0x2, 0x521, 0x522, 0x5, 0x124, 0x93, 0x2, 0x522, 0x523, 
    0x5, 0x12c, 0x97, 0x2, 0x523, 0x524, 0x5, 0x124, 0x93, 0x2, 0x524, 0x526, 
    0x3, 0x2, 0x2, 0x2, 0x525, 0x520, 0x3, 0x2, 0x2, 0x2, 0x525, 0x521, 
    0x3, 0x2, 0x2, 0x2, 0x526, 0x123, 0x3, 0x2, 0x2, 0x2, 0x527, 0x52c, 
    0x5, 0x12e, 0x98, 0x2, 0x528, 0x529, 0x5, 0x126, 0x94, 0x2, 0x529, 0x52a, 
    0x5, 0x128, 0x95, 0x2, 0x52a, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x527, 
    0x3, 0x2, 0x2, 0x2, 0x52b, 0x528, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x52d, 0x52e, 0x5, 0x12e, 0x98, 0x2, 0x52e, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x52f, 0x530, 0x7, 0x28, 0x2, 0x2, 0x530, 0x531, 
    0x5, 0x12e, 0x98, 0x2, 0x531, 0x129, 0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 
    0x9, 0x8, 0x2, 0x2, 0x533, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x534, 0x535, 
    0x9, 0x9, 0x2, 0x2, 0x535, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x536, 0x53c, 
    0x5, 0x130, 0x99, 0x2, 0x537, 0x538, 0x7, 0x5a, 0x2, 0x2, 0x538, 0x539, 
    0x5, 0x11e, 0x90, 0x2, 0x539, 0x53a, 0x7, 0x5b, 0x2, 0x2, 0x53a, 0x53c, 
    0x3, 0x2, 0x2, 0x2, 0x53b, 0x536, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x537, 
    0x3, 0x2, 0x2, 0x2, 0x53c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x54a, 
    0x5, 0x132, 0x9a, 0x2, 0x53e, 0x54a, 0x5, 0x134, 0x9b, 0x2, 0x53f, 0x54a, 
    0x5, 0x138, 0x9d, 0x2, 0x540, 0x54a, 0x5, 0x144, 0xa3, 0x2, 0x541, 0x54a, 
    0x5, 0x112, 0x8a, 0x2, 0x542, 0x54a, 0x5, 0x142, 0xa2, 0x2, 0x543, 0x54a, 
    0x5, 0x146, 0xa4, 0x2, 0x544, 0x54a, 0x5, 0x15a, 0xae, 0x2, 0x545, 0x54a, 
    0x5, 0x15c, 0xaf, 0x2, 0x546, 0x54a, 0x5, 0x166, 0xb4, 0x2, 0x547, 0x54a, 
    0x5, 0x168, 0xb5, 0x2, 0x548, 0x54a, 0x5, 0x16a, 0xb6, 0x2, 0x549, 0x53d, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x549, 0x53f, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x540, 0x3, 0x2, 0x2, 0x2, 0x549, 0x541, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x542, 0x3, 0x2, 0x2, 0x2, 0x549, 0x543, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x544, 0x3, 0x2, 0x2, 0x2, 0x549, 0x545, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x546, 0x3, 0x2, 0x2, 0x2, 0x549, 0x547, 
    0x3, 0x2, 0x2, 0x2, 0x549, 0x548, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x54b, 0x54c, 0x5, 0x58, 0x2d, 0x2, 0x54c, 0x133, 
    0x3, 0x2, 0x2, 0x2, 0x54d, 0x54f, 0x5, 0x136, 0x9c, 0x2, 0x54e, 0x54d, 
    0x3, 0x2, 0x2, 0x2, 0x54e, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x550, 
    0x3, 0x2, 0x2, 0x2, 0x550, 0x551, 0x5, 0x4e, 0x28, 0x2, 0x551, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x552, 0x553, 0x7, 0x33, 0x2, 0x2, 0x553, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x554, 0x555, 0x5, 0x13a, 0x9e, 0x2, 0x555, 0x556, 
    0x7, 0x79, 0x2, 0x2, 0x556, 0x557, 0x5, 0x13c, 0x9f, 0x2, 0x557, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x558, 0x55d, 0x5, 0x13e, 0xa0, 0x2, 0x559, 0x55a, 
    0x5, 0x13e, 0xa0, 0x2, 0x55a, 0x55b, 0x7, 0x62, 0x2, 0x2, 0x55b, 0x55d, 
    0x3, 0x2, 0x2, 0x2, 0x55c, 0x558, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x559, 
    0x3, 0x2, 0x2, 0x2, 0x55d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x562, 
    0x5, 0x140, 0xa1, 0x2, 0x55f, 0x560, 0x7, 0x62, 0x2, 0x2, 0x560, 0x562, 
    0x5, 0x140, 0xa1, 0x2, 0x561, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x561, 0x55f, 
    0x3, 0x2, 0x2, 0x2, 0x562, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x563, 0x566, 
    0x5, 0x58, 0x2d, 0x2, 0x564, 0x566, 0x7, 0x39, 0x2, 0x2, 0x565, 0x563, 
    0x3, 0x2, 0x2, 0x2, 0x565, 0x564, 0x3, 0x2, 0x2, 0x2, 0x566, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0x567, 0x56a, 0x5, 0x58, 0x2d, 0x2, 0x568, 0x56a, 
    0x7, 0x37, 0x2, 0x2, 0x569, 0x567, 0x3, 0x2, 0x2, 0x2, 0x569, 0x568, 
    0x3, 0x2, 0x2, 0x2, 0x56a, 0x141, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56c, 
    0x5, 0x4e, 0x28, 0x2, 0x56c, 0x143, 0x3, 0x2, 0x2, 0x2, 0x56d, 0x56e, 
    0x7, 0x2e, 0x2, 0x2, 0x56e, 0x56f, 0x5, 0x110, 0x89, 0x2, 0x56f, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x570, 0x571, 0x7, 0x54, 0x2, 0x2, 0x571, 0x572, 
    0x7, 0x1d, 0x2, 0x2, 0x572, 0x577, 0x5, 0x148, 0xa5, 0x2, 0x573, 0x574, 
    0x7, 0x54, 0x2, 0x2, 0x574, 0x575, 0x7, 0x1c, 0x2, 0x2, 0x575, 0x577, 
    0x5, 0x14a, 0xa6, 0x2, 0x576, 0x570, 0x3, 0x2, 0x2, 0x2, 0x576, 0x573, 
    0x3, 0x2, 0x2, 0x2, 0x577, 0x147, 0x3, 0x2, 0x2, 0x2, 0x578, 0x579, 
    0x5, 0x110, 0x89, 0x2, 0x579, 0x149, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57d, 
    0x5, 0x14c, 0xa7, 0x2, 0x57b, 0x57d, 0x5, 0x14e, 0xa8, 0x2, 0x57c, 0x57a, 
    0x3, 0x2, 0x2, 0x2, 0x57c, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x14b, 
    0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x7, 0x68, 0x2, 0x2, 0x57f, 0x580, 
    0x5, 0x150, 0xa9, 0x2, 0x580, 0x581, 0x7, 0x6a, 0x2, 0x2, 0x581, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x582, 0x583, 0x7, 0x68, 0x2, 0x2, 0x583, 0x584, 
    0x7, 0x7a, 0x2, 0x2, 0x584, 0x585, 0x7, 0x5d, 0x2, 0x2, 0x585, 0x586, 
    0x5, 0x150, 0xa9, 0x2, 0x586, 0x587, 0x7, 0x6a, 0x2, 0x2, 0x587, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x588, 0x58e, 0x5, 0x152, 0xaa, 0x2, 0x589, 0x58a, 
    0x5, 0x152, 0xaa, 0x2, 0x58a, 0x58b, 0x7, 0x5d, 0x2, 0x2, 0x58b, 0x58c, 
    0x5, 0x150, 0xa9, 0x2, 0x58c, 0x58e, 0x3, 0x2, 0x2, 0x2, 0x58d, 0x588, 
    0x3, 0x2, 0x2, 0x2, 0x58d, 0x589, 0x3, 0x2, 0x2, 0x2, 0x58e, 0x151, 
    0x3, 0x2, 0x2, 0x2, 0x58f, 0x591, 0x7, 0x6e, 0x2, 0x2, 0x590, 0x592, 
    0x5, 0x154, 0xab, 0x2, 0x591, 0x590, 0x3, 0x2, 0x2, 0x2, 0x591, 0x592, 
    0x3, 0x2, 0x2, 0x2, 0x592, 0x153, 0x3, 0x2, 0x2, 0x2, 0x593, 0x594, 
    0x5, 0x156, 0xac, 0x2, 0x594, 0x595, 0x5, 0x158, 0xad, 0x2, 0x595, 0x599, 
    0x3, 0x2, 0x2, 0x2, 0x596, 0x599, 0x5, 0x158, 0xad, 0x2, 0x597, 0x599, 
    0x5, 0x156, 0xac, 0x2, 0x598, 0x593, 0x3, 0x2, 0x2, 0x2, 0x598, 0x596, 
    0x3, 0x2, 0x2, 0x2, 0x598, 0x597, 0x3, 0x2, 0x2, 0x2, 0x599, 0x155, 
    0x3, 0x2, 0x2, 0x2, 0x59a, 0x59b, 0x5, 0x110, 0x89, 0x2, 0x59b, 0x157, 
    0x3, 0x2, 0x2, 0x2, 0x59c, 0x59d, 0x9, 0xa, 0x2, 0x2, 0x59d, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x59e, 0x59f, 0x7, 0x41, 0x2, 0x2, 0x59f, 0x5a0, 
    0x5, 0x58, 0x2d, 0x2, 0x5a0, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x5a1, 0x5a2, 
    0x7, 0x4a, 0x2, 0x2, 0x5a2, 0x5a3, 0x7, 0x75, 0x2, 0x2, 0x5a3, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a5, 0x8, 0xb0, 0x1, 0x2, 0x5a5, 0x5a6, 
    0x5, 0x160, 0xb1, 0x2, 0x5a6, 0x5ab, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x5a8, 
    0xc, 0x3, 0x2, 0x2, 0x5a8, 0x5aa, 0x5, 0x160, 0xb1, 0x2, 0x5a9, 0x5a7, 
    0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ad, 0x3, 0x2, 0x2, 0x2, 0x5ab, 0x5a9, 
    0x3, 0x2, 0x2, 0x2, 0x5ab, 0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5ac, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ab, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5af, 
    0x5, 0x162, 0xb2, 0x2, 0x5af, 0x5b0, 0x7, 0x63, 0x2, 0x2, 0x5b0, 0x5b1, 
    0x5, 0x164, 0xb3, 0x2, 0x5b1, 0x161, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5b3, 
    0x7, 0x77, 0x2, 0x2, 0x5b3, 0x163, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b5, 
    0x7, 0x77, 0x2, 0x2, 0x5b5, 0x165, 0x3, 0x2, 0x2, 0x2, 0x5b6, 0x5b7, 
    0x5, 0x138, 0x9d, 0x2, 0x5b7, 0x167, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5b9, 
    0x5, 0x138, 0x9d, 0x2, 0x5b9, 0x169, 0x3, 0x2, 0x2, 0x2, 0x5ba, 0x5bb, 
    0x5, 0x138, 0x9d, 0x2, 0x5bb, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5bd, 
    0x7, 0x58, 0x2, 0x2, 0x5bd, 0x5be, 0x5, 0x16e, 0xb8, 0x2, 0x5be, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5c6, 0x5, 0x66, 0x34, 0x2, 0x5c0, 0x5c6, 
    0x5, 0x3a, 0x1e, 0x2, 0x5c1, 0x5c2, 0x5, 0x4e, 0x28, 0x2, 0x5c2, 0x5c3, 
    0x7, 0x60, 0x2, 0x2, 0x5c3, 0x5c4, 0x5, 0x58, 0x2d, 0x2, 0x5c4, 0x5c6, 
    0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c0, 
    0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c1, 0x3, 0x2, 0x2, 0x2, 0x5c6, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5c9, 0x5, 0x172, 0xba, 0x2, 0x5c8, 0x5c7, 
    0x3, 0x2, 0x2, 0x2, 0x5c9, 0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5ca, 0x5c8, 
    0x3, 0x2, 0x2, 0x2, 0x5ca, 0x5cb, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 0x7, 0x25, 0x2, 0x2, 0x5cd, 0x5ce, 
    0x7, 0x7d, 0x2, 0x2, 0x5ce, 0x173, 0x3, 0x2, 0x2, 0x2, 0x77, 0x179, 
    0x17c, 0x17f, 0x185, 0x18b, 0x18f, 0x19b, 0x1a0, 0x1ab, 0x1b5, 0x1bd, 
    0x1c6, 0x1c9, 0x1cf, 0x1d2, 0x1d7, 0x1df, 0x1e3, 0x1ea, 0x1f4, 0x1f9, 
    0x1fd, 0x201, 0x218, 0x233, 0x24f, 0x254, 0x25e, 0x262, 0x277, 0x284, 
    0x28b, 0x2a2, 0x2a7, 0x2ab, 0x2b7, 0x2bd, 0x2c2, 0x2cd, 0x2d2, 0x2dd, 
    0x2e7, 0x2ee, 0x2fa, 0x306, 0x30d, 0x314, 0x31e, 0x32c, 0x330, 0x33a, 
    0x342, 0x34a, 0x352, 0x355, 0x357, 0x364, 0x369, 0x36d, 0x37a, 0x388, 
    0x38c, 0x395, 0x3a2, 0x3a9, 0x3b1, 0x3b6, 0x3c4, 0x3d0, 0x3d4, 0x3e0, 
    0x3e5, 0x3f1, 0x3fe, 0x40b, 0x410, 0x413, 0x41a, 0x424, 0x42d, 0x435, 
    0x43b, 0x447, 0x450, 0x455, 0x45c, 0x469, 0x471, 0x47b, 0x47f, 0x487, 
    0x48f, 0x498, 0x4bf, 0x4c4, 0x4ee, 0x4f3, 0x509, 0x512, 0x51d, 0x525, 
    0x52b, 0x53b, 0x549, 0x54e, 0x55c, 0x561, 0x565, 0x569, 0x576, 0x57c, 
    0x58d, 0x591, 0x598, 0x5ab, 0x5c5, 0x5ca, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

asn1Parser::Initializer asn1Parser::_init;
