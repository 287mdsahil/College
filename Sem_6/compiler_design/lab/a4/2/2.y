%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
void yyerror(char*);
%}

%union{
float f;
}

%type <f> S E T F
%token <f> NUM

%%
S : E  		{printf("%f\n",$1);}
  ;

E : E '+' T 	{$$ = $1 + $3;}
  | E '-' T  	{$$ = $1 - $3;}
  | T 		{$$ = $1;}
  ;

T : T '*' F 	{$$ = $1 * $3;}
  | T '/' F 	{$$ = $1 / $3;}
  | F 		{$$ = $1;}
  ;

F : '-' F 	{$$ = -$2;}
  | NUM 	{$$ = $1;}
  ;

%%

void yyerror(char *msg)
{
	fprintf(stderr,"%s\n",msg);
	exit(1);
}

int main()
{
	yyparse();
	return 0;
}
