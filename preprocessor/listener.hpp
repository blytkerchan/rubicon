#ifndef rubicon_preprocessor_listener_hpp
#define rubicon_preprocessor_listener_hpp

#include "../generated/preprocBaseListener.h"
#include <ostream>

namespace Vlinder { namespace Rubicon { namespace Preprocessor {
class Listener : public ::preprocBaseListener
{
public :
	Listener(std::ostream &os);

	virtual void exitNon_quoted_text(preprocParser::Non_quoted_textContext *ctx) override;
	virtual void exitQuoted_text(preprocParser::Quoted_textContext *ctx) override;
	virtual void exitAda_style_comment(preprocParser::Ada_style_commentContext *ctx) override;

private :
	std::ostream &os_;
};
}}}

#endif


