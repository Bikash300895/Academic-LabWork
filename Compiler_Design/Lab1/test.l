%%
[A-Z][a-z]+[0-9]+ {
	printf("Found!!\n");
}

.* printf("Do nothing!!\n");
%% 

int yywrap()
{
	return 1;
}

int main()
{
	printf("Enter input: ");
	yylex();
	return 0;
}
