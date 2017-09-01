grammar preproc;

text
	: c_style_comment
	| ada_style_comment
	| QUOTE
	| CHAR*?
	;

c_style_comment
	: BEGIN_C_STYLE_COMMENT ~END_C_STYLE_COMMENT* END_C_STYLE_COMMENT
	;
ada_style_comment
	: ADA_STYLE_COMMENT_DELIM ~(ADA_STYLE_COMMENT_DELIM | NEWLINE)* NEWLINE
	| ADA_STYLE_COMMENT_DELIM ~(ADA_STYLE_COMMENT_DELIM | NEWLINE)* ADA_STYLE_COMMENT_DELIM
	;

BEGIN_C_STYLE_COMMENT	: '/*' ;
END_C_STYLE_COMMENT	: '*/' ;
ADA_STYLE_COMMENT_DELIM	: '--' ;
NEWLINE			: '\n' | '\u000B' | '\u000C' | '\r' ;
QUOTE			: '"' ;
CHAR			: . ;
