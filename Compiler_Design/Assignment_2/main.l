/* C Declarations */

%{
	#include<stdio.h>
	#include "main.tab.h"
	#include<stdlib.h>
	extern int yylval;
%}

/*RE and Action*/

%%

"int"	{ return INT; }
"float"	{ return FLOAT; }
"char"	{ return CHAR; }

[0-9]+	{
		yylval = atoi(yytext);
		return NUM;
	}

"("	{ return LP; }
")"	{ return RP; }
"{"	{ return LB; }
"}"	{ return RB; }
",,"	{ return CM; }
";;"	{ return SM; }
"add"	{ return PLUS; }
"sub"	{ return MINUS; }
"mul"	{ return MULT; }
"div"	{ return DIV; }
"<--"	{ return ASSIGN;  }
">"	{ return GT; }
"<"	{ return LT; }
"for" {return FOR;}
"range" {return RANGE;}
"if" {return IF;}
"else" {return ELSE;}
"in" {return IN;}


[a-z]	{
		yylval = *yytext - 'a';
		return	VAR;
	}
[,;]	{ return *yytext; }

"void start"	{ return VOIDMAIN; }

[ \t\n]*	;

.	{
		yyerror("Unknown Character.\n");
	}
%%

/* user subroutines */

int main()
{
	yyin = freopen("in.txt","r",stdin);
	yyout = freopen("out.txt","w",stdout);
	yyparse();

}
