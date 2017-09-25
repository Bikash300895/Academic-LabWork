

%%

.+?[a,e,i,o,u][a,e,i,o,u][a,e,i,o,u][a,e,i,o,u][a,e,i,o,u].+?	{printf("string\n");}
.+?[A,E,I,O,U][A,E,I,O,U][A,E,I,O,U][A,E,I,O,U][A,E,I,O,U].+?	{printf("string\n");}

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