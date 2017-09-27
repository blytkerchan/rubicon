grammar preproc;

file
	: text*
	;

text
	: c_style_comment
	| ada_style_comment
	| quoted_text
	| non_quoted_text
	;

c_style_comment
	: BEGIN_C_STYLE_COMMENT ~END_C_STYLE_COMMENT* END_C_STYLE_COMMENT
	| ADA_STYLE_COMMENT_DELIM ~(ADA_STYLE_COMMENT_DELIM | NEWLINE)* ADA_STYLE_COMMENT_DELIM
	;
ada_style_comment
	: ADA_STYLE_COMMENT_DELIM ~(ADA_STYLE_COMMENT_DELIM | NEWLINE)* NEWLINE
	;
quoted_text
	: QUOTE CHAR*? QUOTE
	;

non_quoted_text
	: CHAR+?
	| NEWLINE
	;

BEGIN_C_STYLE_COMMENT	: '/*' ;
END_C_STYLE_COMMENT	: '*/' ;
ADA_STYLE_COMMENT_DELIM	: '--' ;
NEWLINE			: '\n' | '\u000B' | '\u000C' | '\r' ;
QUOTE			: '"' ;
CHAR			: . ;
