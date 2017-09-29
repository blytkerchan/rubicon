#ifndef rubicon_compiler_listener_hpp
#define rubicon_compiler_listener_hpp

#include "../generated/asn1BaseListener.h"
#include <ostream>

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

private :
	enum TagDefault {
		  explicit_tags__
		, implicit_tags__
		, automatic_tags__
		};
	std::string namespace_prefix_;
	std::string namespace_suffix_;

	// from parsing
	std::string module_namespace_;
	asn1Parser::Definitive_identificationContext *module_definitive_identification_ = nullptr;
	TagDefault tag_default_ = explicit_tags__;
	bool module_types_extensibility_implied_ = false;
	bool export_all_ = false;
	std::vector< std::string > symbols_to_export_;
};
}}}

#endif


