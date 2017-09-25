    %{ 
#include <string.h>

char s[10000];
%}

%%

[01]+	{
			strcpy(s,yytext);
			if(s[strlen(s)-1]=='0')
			printf("correct\n");
			else
			printf("incorrect\n");
		}

%%

int yywrap()
{
	return 1;
}

int main()
{
	yylex();
	return 0;
}