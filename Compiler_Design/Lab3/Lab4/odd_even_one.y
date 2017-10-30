/*bison flex same file*/


/*C declarations*/

%{
	#include<stdio.h>
%}

/*bison declarations*/

%start input
%token EVEN ODD

/*grammer rules*/

%%
input:	EVEN	{ printf("\nEVEN NUMBER\n");}

	|ODD	{ printf("\nODD NUMBER\n");}
	; 

%%

/*lexical analyzer*/

int yylex( void ) 
{
	int c = getchar();		/* read from stdin */
	if (c < 0) 
	{
	   return 0;		/* end of the input*/
	}
	while ( c == ' ' || c == '\t' ) 
	{
	   c = getchar( );
	}	
	if ( isdigit(c) || c == '.' )
	{
		ungetc(c, stdin);	 	/* put c back into input */
		scanf ("%d", &yylval); 		/* get value using scanf */
		if(yylval%2==0)
	  	{
	   		printf("\nValue Given = %d\n",yylval);
	   		return EVEN; 		 /* return the token type */
	 	}
		else
		{
			printf("\nValue Given = %d\n",yylval);
			return ODD; 		 /* return the token type */
		}
	}
}


int yywrap(void)
{
	return 1;
}

/*display error message */

int yyerror( char *errmsg ) 
{ 
	printf("Error:  %s\n", errmsg); 
}


/*main function */

int main() 
{ 
	printf("\nType a number: ");
	yyparse( ); 
	return 0;
}
