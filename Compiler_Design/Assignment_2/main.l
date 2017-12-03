/* C Declarations */

%{
	#include<stdio.h>
	#include "main.tab.h"
	#include <string.h>
	#include<stdlib.h>
	//extern int yylval;
	extern int string_var_name;
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
"cm"	{ return CM; }
"sm"	{ return SM; }
"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*"	{ return MULT; }
"/"	{ return DIV; }
"<-"	{ return ASSIGN;  }
"GT"	{ return GT; }
"LT"	{ return LT; }


[,;]	{ return *yytext; }

"void start"	{ return VOIDMAIN; }

[ \t\n]*	;

[a-zA-Z][a-zA-Z0-9]*	{
		string_var_name = 0;
		//strcpy(string_var_name, "name");
		//printf("%s\n", string_var_name);
		return	VAR;
	}

.	{
		yyerror("Unknown Character.\n");
	}
%%

/* user subroutines */

int main()
{
	yyin = freopen("a.txt","r",stdin);
	yyout = freopen("out.txt","w",stdout);
	yyparse();

}
