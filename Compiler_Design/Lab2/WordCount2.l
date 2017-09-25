%{
int num_lines=0, num_chars=0, num_words=0;
%}
%%
[A-Za-z]+" "*\n* {++num_words;}
" "*
%%
int yywrap()
{
	return 1;
}
int main()
{
	yyin = freopen("input.txt", "r", stdin);
	yylex();
	printf("number of words %d", num_words);
	fclose(yyin);
	return 0;
}