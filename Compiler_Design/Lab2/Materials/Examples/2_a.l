

%%

[+]?[0-9]+	{printf("positive integer\n");}
[-][0-9]+	{printf("negative integer\n");}

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