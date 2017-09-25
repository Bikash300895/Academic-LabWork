%{ 
#include <string.h>

char s[10000];
int i;
%}

%%

[0-9]+	{
		int a[10]={0};
		strcpy(s,yytext);
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='0')
			a[0]++;
			else if(s[i]=='1')
			a[1]++;
			else if(s[i]=='2')
			a[2]++;
			else if(s[i]=='3')
			a[3]++;
			else if(s[i]=='4')
			a[4]++;
			else if(s[i]=='5')
			a[5]++;
			else if(s[i]=='6')
			a[6]++;
			else if(s[i]=='7')
			a[7]++;
			else if(s[i]=='8')
			a[8]++;
			else if(s[i]=='9')
			a[9]++;
		}
		for(i=0;i<10;i++)
		{
			if(a[i]>1)
			break;
		}
		if(i==10)
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