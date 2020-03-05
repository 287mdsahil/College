%{
#include <stdio.h>
#include <stdlib.h>

#include "2.tab.h"
%}

%option noyywrap

%%

[0-9]+(\.[0-9])? 	{yylval.f = atof(yytext); return NUM;}
[-+/*] 			{return yytext[0];}
[ \t\n] 		{;}

%%
