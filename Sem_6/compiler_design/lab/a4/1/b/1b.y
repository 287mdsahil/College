%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern int yylex();
void yyerror(char*);
%}


%union{
  char c[100];
}
%token <c> a b
%type <c> S C A B
%%

S : C   {printf("Accepted Strinng:%s\n", $1);}
  ;

C : A C B  {strcpy($$, strcat($1, $2));strcat($$,$3);}
  | A B    {strcpy($$, strcat($1, $2));}
  ;

A : a   {strcpy($$, $1);}
  ;

B : b   {strcpy($$, $1);}
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
