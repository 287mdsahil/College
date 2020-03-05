%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1a.tab.h"
%}

%option noyywrap

%%

A {strcpy(yylval.c,yytext); return a;}
B {strcpy(yylval.c,yytext); return b;}
. {;}

%%
