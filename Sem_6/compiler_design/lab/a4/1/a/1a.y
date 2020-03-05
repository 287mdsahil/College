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
%type <c> S A B
%%
S : A B  {printf("Accepted Strinng:%s%s\n", $1,$2);}
A : A a {strcpy($$, strcat($1, $2));}
  | a   {strcpy($$, $1);}
B : B b {strcpy($$, strcat($1, $2));}
  | b   {strcpy($$, $1);}
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
