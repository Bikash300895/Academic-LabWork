%{ 
#include <string.h>

char s[10000];
int i;
%}

%%

[01]+	{
			strcpy(s,yytext);
			for(i=1;i<strlen(s);i++)
			{
				if(s[i]=='1'&&s[i-1]=='1')
				break;
				if(s[i]=='0'&&s[i-1]=='0')
				break;
			}
			if(strlen(s)==i)
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