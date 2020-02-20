%{
#include<stdio.h>
int count_chars = 0;
int count_words = 0;
int count_lines = 0;
%}

%%
\n          count_lines++; count_words++; count_chars++;
[\t \s]     count_words++; count_chars++;
.           count_chars++;
%%

int main()
{
	yylex();
	printf("No of chars:%d\nNo of words:%d\nNo of lines:%d\n", count_chars, count_words, count_lines);
	return 0;
}
