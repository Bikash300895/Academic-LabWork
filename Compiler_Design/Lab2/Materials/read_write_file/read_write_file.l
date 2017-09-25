%{
	#include <stdio.h>
	
%}

%%


.+	{
		printf("%s\n", yytext);
		printf("length: %d\n",yyleng);
	}
\n	{
		printf("haha\n");
	}

%%

int yywrap()
{
	return 1;
}

int main()
{
            yyin = freopen( "in.txt", "r",stdin);
			yyout = freopen("out.txt", "w",stdout);
	yylex();
	fclose(yyin);
	fclose(yyout);
	return 0;
}