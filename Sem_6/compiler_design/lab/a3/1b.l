%{
%}

proper_names [A-Z][a-z0-9]*
acronym [A-Z]+

%%
{proper_names} printf("Proper name:%s", yytext);
{acronym} printf("Acronym:%s", yytext);
.       ;
%%

int main()
{
	yylex();
	return 0;
}
