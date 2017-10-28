#ifndef rubicon_compiler_listener_hpp
#define rubicon_compiler_listener_hpp

#include "../generated/asn1BaseListener.h"
#include "constraint.hpp"
#include "modulenamemappings.hpp"
#include "namednumber.hpp"
#include "namedtype.hpp"
#include "tag.hpp"
#include "typeassignment.hpp"
#include "typedescriptor.hpp"
#include "value.hpp"
#include <ostream>
#include <memory>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Listener : public ::asn1BaseListener
{
public :
	Listener(std::string const &namespace_prefix, std::string const &namespace_suffix);

	virtual void exitModule_identifier(asn1Parser::Module_identifierContext *ctx) override;
	virtual void exitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext *ctx) override;
	virtual void exitExplicit_tags(asn1Parser::Explicit_tagsContext *ctx) override;
	virtual void exitImplicit_tags(asn1Parser::Implicit_tagsContext *ctx) override;
	virtual void exitAutomatic_tags(asn1Parser::Automatic_tagsContext *ctx) override;
	virtual void exitExtension_default(asn1Parser::Extension_defaultContext *ctx) override;
	virtual void exitEncoding_control_section(asn1Parser::Encoding_control_sectionContext *ctx) override;
	virtual void exitExports(asn1Parser::ExportsContext *ctx) override;
	virtual void exitImports(asn1Parser::ImportsContext *ctx) override;
	virtual void exitAssignment_list(asn1Parser::Assignment_listContext *ctx) override;

private :
	enum struct TagDefault {
		  explicit_tags__
		, implicit_tags__
		, automatic_tags__
		};
	typedef std::map< std::string, std::vector< std::string > > ImportedSymbols;

	ObjectIdentifier parseObjectIdentifier(asn1Parser::Object_identifier_valueContext *ctx);
	DefinedValue parseDefinedValue(asn1Parser::Defined_valueContext *ctx);
	unsigned int parseNumber(antlr4::tree::TerminalNode *node);
	TypeAssignment parseTypeAssignment(asn1Parser::Type_assignmentContext *ctx);
	std::shared_ptr< TypeDescriptor > parseType(asn1Parser::TypeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseBuiltinType(asn1Parser::Builtin_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseBitStringType(asn1Parser::Bit_string_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseCharacterStringType(asn1Parser::Character_string_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseChoiceType(asn1Parser::Choice_typeContext *ctx);
	NamedType parseNamedType(asn1Parser::Named_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseEnumeratedType(asn1Parser::Enumerated_typeContext *ctx);
	NamedNumber parseNamedNumber(asn1Parser::Named_numberContext *ctx);
	long parseSignedNumber(asn1Parser::Signed_numberContext *ctx);
	std::shared_ptr< TypeDescriptor > parseIntegerType(asn1Parser::Integer_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseSequenceOrSetType(asn1Parser::Sequence_or_set_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseSequenceOrSetOfType(asn1Parser::Sequence_or_set_of_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parsePrefixedType(asn1Parser::Prefixed_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseDefinedType(asn1Parser::Defined_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseUsefulType(asn1Parser::Useful_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseSelectionType(asn1Parser::Selection_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseContrainedType(asn1Parser::Constrained_typeContext *ctx);
	std::shared_ptr< TypeDescriptor > parseReferencedType(asn1Parser::Referenced_typeContext *ctx);
	Constraint parseConstraint(asn1Parser::ConstraintContext *ctx);

	Tag parseTag(asn1Parser::TagContext *ctx);

	std::shared_ptr< Value > parseValue(asn1Parser::ValueContext *ctx);

	static void emitWarning(antlr4::ParserRuleContext *ctx, char const *fmt, ...);
	static void emitWarning(antlr4::tree::TerminalNode *node, char const *fmt, ...);
	static void emitError(antlr4::ParserRuleContext *ctx, char const *fmt, ...);
	static void emitError(antlr4::tree::TerminalNode *node, char const *fmt, ...);

	std::string namespace_prefix_;
	std::string namespace_suffix_;

	// from parsing
	std::string module_namespace_;
	asn1Parser::Definitive_identificationContext *module_definitive_identification_ = nullptr;
	TagDefault tag_default_ = TagDefault::explicit_tags__;
	bool module_types_extensibility_implied_ = false;
	bool export_all_ = false;
	std::vector< std::string > symbols_to_export_;
	ModuleNameMappings module_name_mappings_;
	ImportedSymbols imported_symbols_;
};
}}}

#endif


