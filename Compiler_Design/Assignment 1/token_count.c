%{
	#include<stdio.h>
	#include<stdlib.h>
	int keywords = 0;
	int variables=0;
	int numbers = 0;
	int operators = 0;
	int functions = 0;
	int loops = 0;
	int coditionalStatements = 0;
	int syntexs = 0;
	int functionCalls = 0;
%}

%%

"\t"|"\n"|[" "]* {
	// printf("syntex\n");
}

"+="|"-="|"*="|"/="|"**"|"+"|"-"|"*"|"/"|"=="|"<"|">"|"<="|">=" {
	operators++;
	//printf("%s\n", yytext );
}

[";" | "=" | ":" |"("|")"|"{"|"}"] {
	syntexs++;
}

"def "[a-zA-Z_][a-zA-Z_0-9]*"(" {
	functions++;
}

"if" {
	coditionalStatements++;
}

"for"|"while" {
	loops++;
	keywords++;
}

[a-zA-Z_][a-zA-Z_0-9]*"(" {
	functionCalls++;
}

"import"|"int"|"string"|"char"|"float"|"in"|"range"|"return" {
	keywords++;
}

[a-zA-Z_][a-zA-Z_0-9]* {
	variables++;
}


[0-9]*["."]?[0-9]+ {
	numbers++;
}

. {
	printf("syntex error %s\n", yytext);
}
%%

int yywrap()
{
	return 1;
}

main(){
	yyin = freopen("in.txt","r",stdin);
	yyout = freopen("out.txt","w",stdout);
	yylex();

	printf("\nNumber of tokens----\n");
	printf("Number of keyword = %d\n", keywords);
	printf("Number of variables = %d\n", variables);
	printf("Number of systexs = %d\n", syntexs);
	printf("Number of numbers = %d\n", numbers);
	printf("Number of operators= %d\n", operators);
	printf("Number of loops= %d\n", loops);
	printf("Number of functions= %d\n", functions);
	printf("Number of coditionalStatements= %d\n", coditionalStatements);
	printf("Number of functionCalls= %d\n", functionCalls);

	fclose(yyin);
	fclose(yyout);
	return 0;
}