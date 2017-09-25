

%%

[a-zA-Z_]+|[a-zA-Z_]+[0-9]+|[a-zA-Z_]+[[][1-9]+[]]	{if(yyleng<=31)printf("variable\n");else printf("not a variable\n");}

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