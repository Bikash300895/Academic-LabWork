%{ 
#include <string.h>

char s[10000];
int i;
%}

%%

[a-zA-Z]+	{
		strcpy(s,yytext);
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]<s[i-1])
			break;
			
		}
		if(i==strlen(s))
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