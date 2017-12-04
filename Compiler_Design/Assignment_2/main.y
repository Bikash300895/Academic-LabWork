/* C Declarations */

%{
	#include<stdio.h>
	int sym[26],store[26], flag[26];
%}

/* BISON Declarations */

%token FOR IN RANGE NUM VAR IF ELSE VOIDMAIN INT FLOAT CHAR LP RP LB RB CM SM PLUS MINUS MULT DIV ASSIGN GT LT
%nonassoc IFX
%nonassoc ELSE
%left LT GT
%left PLUS MINUS
%left MULT DIV

/* Simple grammar rules */

%%

program: VOIDMAIN LP RP LB cstatement RB { printf("\nsuccessful compilation\n"); }
	 ;

cstatement: /* empty */

	| cstatement statement

	| cdeclaration
	;

cdeclaration:	TYPE ID1 ';'	{ printf("\nvalid declaration\n"); }
			;

TYPE : INT

     | FLOAT

     | CHAR
     ;

ID1  : ID1 ',' VAR	{
				// add your code here
				if(flag[$3]==1){
					printf("Declare duplication\n");
				} else {
					flag[$3]=1;
				}
			}

     |VAR	{
				// add your code here
				if(flag[$1]==1){
					printf("Declare duplication\n");
				} else {
					flag[$1]=1;
				}
			}
     ;

statement: ';'

	| expression ';' 			{ printf("\nvalue of expression: %d\n", $1); }

        | VAR ASSIGN expression ';' 		{
        					if(flag[$1]==1){
        						sym[$1] = $3;
								printf("\nValue of the variable: %d\t\n",$3);
        					} else {
        						printf("Variable not declared\n");
        					}

						}
		| IF LP expression RP expression ';' %prec IFX {
						if($3)
						{
							printf("\nvalue of expression in IF: %d\n",$5);
						}
						else
						{
						printf("condition value zero in IF block\n");
						}
				}

		| IF LP expression RP expression ';' ELSE expression ';' {
						 	if($3)
							{
								printf("value of expression in IF: %d\n",$5);
							}
							else
							{
								printf("value of expression in ELSE: %d\n",$8);
							}
					}
			| FOR VAR IN RANGE LP NUM RP LB expression {
				printf(" inside for loop\n");
			}
	;

expression: NUM				{ $$ = $1; 	}

	| VAR				{ $$ = sym[$1]; }

	| expression PLUS expression	{ $$ = $1 + $3; }

	| expression MINUS expression	{ $$ = $1 - $3; }

	| expression MULT expression	{ $$ = $1 * $3; }

	| expression DIV expression	{ 	if($3)
				  		{
				     			$$ = $1 / $3;
				  		}
				  		else
				  		{
							$$ = 0;
							printf("\ndivision by zero\t");
				  		}
				    	}

	| expression LT expression	{ $$ = $1 < $3; }

	| expression GT expression	{ $$ = $1 > $3; }

	| LP expression RP		{ $$ = $2;	}
	;
%%

int yywrap()
{
return 1;
}


yyerror(char *s){
	printf( "%s\n", s);
}
