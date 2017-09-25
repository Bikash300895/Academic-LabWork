%{
int num_lines=0, num_chars=0;
%}
%%
\n	 {++num_lines; ++num_chars;}
.	  {++num_chars;}
%%
int yywrap()
{
	return 1;
}
int main()
{
	yylex();
	printf("number of lines %d and number of characters %d", num_lines, num_chars);
	return 0;
}