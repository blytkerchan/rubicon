#include "listener.hpp"

namespace Vlinder { namespace Rubicon { namespace Preprocessor {
Listener::Listener(std::ostream &os)
	: os_(os)
{ /* no-op */ }

/*virtual */void Listener::exitNon_quoted_text(preprocParser::Non_quoted_textContext *ctx)/* override*/
{
	os_ << ctx->getText();
}

/*virtual */void Listener::exitQuoted_text(preprocParser::Quoted_textContext *ctx)/* override*/
{
	os_ << ctx->getText();
}
/*virtual */void Listener::exitAda_style_comment(preprocParser::Ada_style_commentContext *ctx)/* override*/
{
	os_ << '\n';
}

}}}




