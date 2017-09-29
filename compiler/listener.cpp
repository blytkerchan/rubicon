#include "listener.hpp"
#include "../exceptions/contract.hpp"
#include "../tracing.hpp"
#include <algorithm>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
Listener::Listener(string const &namespace_prefix, string const &namespace_suffix)
	: namespace_prefix_(namespace_prefix)
	, namespace_suffix_(namespace_suffix)
{ /* no-op */ }

/*virtual */void Listener::exitModule_identifier(asn1Parser::Module_identifierContext *ctx)/* override*/
{
	pre_condition(ctx);
	pre_condition(ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE());
	module_namespace_ = namespace_prefix_ + ctx->TYPE_REFERENCE_OR_MODULE_REFERENCE()->getText() + namespace_suffix_;
	tracer__->trace(1, TRACE_INFO, "Will be using namespace name %s\n", module_namespace_.c_str());
	module_definitive_identification_ = ctx->definitive_identification();
}

/*virtual */void Listener::exitEncoding_reference_default(asn1Parser::Encoding_reference_defaultContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->ENCODING_REFERENCE())
	{
		if (ctx->ENCODING_REFERENCE()->getText() != "TAG")
		{
			tracer__->trace(1, TRACE_WARN, "%s:%u:%u: warning: encoding reference \"%s\" specified. We only implement DER (\"TAG\" encoding reference).\n", ctx->ENCODING_REFERENCE()->getSymbol()->getTokenSource()->getSourceName().c_str(), ctx->ENCODING_REFERENCE()->getSymbol()->getLine(), ctx->ENCODING_REFERENCE()->getSymbol()->getCharPositionInLine(), ctx->ENCODING_REFERENCE()->getText().c_str());
		}
		else
		{ /* nothing to warn about */ }
	}
	else
	{ /* definitely nothing to warn about */ }
}

/*virtual */void Listener::exitExplicit_tags(asn1Parser::Explicit_tagsContext *ctx)/* override*/
{
	tag_default_ = explicit_tags__;
}
/*virtual */void Listener::exitImplicit_tags(asn1Parser::Implicit_tagsContext *ctx)/* override*/
{
	tag_default_ = implicit_tags__;
}
/*virtual */void Listener::exitAutomatic_tags(asn1Parser::Automatic_tagsContext *ctx)/* overrid*/
{
	tag_default_ = automatic_tags__;
}
/*virtual */void Listener::exitExtension_default(asn1Parser::Extension_defaultContext *ctx)/* override*/
{
	pre_condition(ctx);
	module_types_extensibility_implied_ = (ctx->EXTENSIBILITY_RW() && ctx->IMPLIED_RW());
}
/*virtual */void Listener::exitEncoding_control_section(asn1Parser::Encoding_control_sectionContext *ctx)/* override*/
{
	pre_condition(ctx);
	pre_condition(ctx->ENCODING_REFERENCE());
	if (ctx->ENCODING_REFERENCE()->getText() != "TAG")
	{
		tracer__->trace(1, TRACE_WARN, "%s:%u:%u: warning: encoding reference \"%s\" specified. We only implement DER (\"TAG\" encoding reference).\n", ctx->ENCODING_REFERENCE()->getSymbol()->getTokenSource()->getSourceName().c_str(), ctx->ENCODING_REFERENCE()->getSymbol()->getLine(), ctx->ENCODING_REFERENCE()->getSymbol()->getCharPositionInLine(), ctx->ENCODING_REFERENCE()->getText().c_str());
	}
	else
	{
		tracer__->trace(1, TRACE_WARN, "%s:%u:%u: warning: encoding reference \"TAG\" specified. According to X.680-201508 this is not allowed in this context.\n", ctx->ENCODING_REFERENCE()->getSymbol()->getTokenSource()->getSourceName().c_str(), ctx->ENCODING_REFERENCE()->getSymbol()->getLine(), ctx->ENCODING_REFERENCE()->getSymbol()->getCharPositionInLine());
	}
}
/*virtual */void Listener::exitExports(asn1Parser::ExportsContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->symbols_exported())
	{
		if (ctx->symbols_exported()->symbol_list())
		{
			auto symbols(ctx->symbols_exported()->symbol_list()->symbol());
			if (symbols.empty())
			{
				tracer__->trace(1, TRACE_WARN, "%s:%u:%u: warning: EXPORTS clause without any symbols to export.\n", ctx->getStart()->getTokenSource()->getSourceName().c_str(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
			}
			transform(symbols.begin(), symbols.end(), back_inserter(symbols_to_export_), [](auto symbol) -> string { assert(symbol); return symbol->getText(); });
		}
		else
		{
			tracer__->trace(1, TRACE_WARN, "%s:%u:%u: warning: EXPORTS clause without any symbols to export.\n", ctx->getStart()->getTokenSource()->getSourceName().c_str(), ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
		}
	}
	else if (ctx->ALL_RW())
	{
		export_all_ = true;
	}
	else
	{ /* no exports clause */ }
	//TODO when done parsing, make sure all of these symbols are defined in this module.
	//     also generate a header file with the exported symbols
	//     also tag the classes for export (so they'll be visible from a DLL or DSO)
}
/*virtual */void Listener::exitImports(asn1Parser::ImportsContext *ctx)/* override*/
{
	pre_condition(ctx);
	if (ctx->symbols_imported() && ctx->symbols_imported()->symbols_from_module_list())
	{
		auto symbols_from_modules(ctx->symbols_imported()->symbols_from_module_list()->symbols_from_module());
		for_each(symbols_from_modules.begin(), symbols_from_modules.end(), [](auto symbols_from_module){
				assert(symbols_from_module);
				// the module being referred to is known by two names: the TYPE_REFERENCE_OR_MODULE_REFERENCE,
				// which is the name that will be used in this module, and the assigned_identifier, which is 
				// optional and presumed to be the TYPE_REFERENCE_OR_MODULE_REFERENCE if absent. If it is not 
				// absent, it is either an OID or a defined_value. If it's an OID, that OID will correspond 
				// to the OID of the module being imported, which may have another name than what's given 
				// here. If it's a defined_value, that will be the name we expect the module to have.
				// In any case, symbols from this module will be referred to by the
				// TYPE_REFERENCE_OR_MODULE_REFERENCE name in this module, not by whatever other name it 
				// may have.
				//TODO get the two names, as described, and the symbols mapped to those names.
				//     Check that there are no two modules being imported from with the same name
				//     Check that the same module is not referenced twice with different names.
				//     Build an ADT with the thus-gathered data.
			});
	}
	else
	{ /* no imports clause */ }
}
}}}




