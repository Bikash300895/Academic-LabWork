
/* C declarations */
						
%{
	#include <stdio.h>
	#include <math.h>
	#define YYSTYPE int
%}


/* Bison declarations */
		
/*%start declaration	 define the start symble */	
		     
%token INT FLOAT CHAR ID SM CM   /* define token type for numbers */

%%	  	


/* Simple grammar rules */

program: 
	|program declaration
	;

declaration: TYPE ID1 SM	{ 
					printf("\nValid Declaration\n");
					
				}


TYPE : INT	{ }

     | FLOAT	{ }

     | CHAR	{  }
     ;

ID1  : ID1 CM ID	{ }

     |ID		{ }
     ;
