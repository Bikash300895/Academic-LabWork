%%
[A-Za-z]+[-:" "]*[0-9]+ {printf("Accepted");}
" "*
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