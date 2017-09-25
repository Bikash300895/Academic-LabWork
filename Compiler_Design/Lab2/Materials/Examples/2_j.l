%{ 
#include <string.h>

char s[10000];
int i,j,k;
%}

%%

[01]+	{
		strcpy(s,yytext);
		for(j=k=i=0;i<strlen(s);i++)
		{
			if(s[i]=='0')
			j++;
			else
			k++;
		}
		if(j%2==0&&k%2==1)
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