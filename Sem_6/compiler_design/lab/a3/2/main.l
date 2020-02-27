%{ 
    #include <stdio.h>
    #include <string.h>
%} 
  
/* Rule: whenever space, tab or  
newline is encounterd, remove it*/
%% 
[/][/][a-zA-Z0-9" "]* {fprintf(yyout, "");} 

(if) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(else) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(for) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);;
(int) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(float) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(void) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(and) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);
(return) fprintf(yyout, "%s\t\t\tkeyword\n",yytext);

[_a-zA-Z][a-zA-Z0-9_]*  fprintf(yyout, "%s\t\t\tID\n ",yytext);

[+\-*/] fprintf(yyout, "%s\t\t\tarith-op\n",yytext);
[<>] fprintf(yyout, "%s\t\t\trel-op\n",yytext);
[=] fprintf(yyout, "%s\t\t\tassign-op\n",yytext);
[;,(){}] fprintf(yyout, "%s\t\t\tpunctuation\n",yytext);

[ \n\t]+ {fprintf(yyout, "");} 

[" "]+?[0-9]+[" "] fprintf(yyout, "%s\t\t\tINUM\n",yytext);
[" "]-[0-9]+[" "] fprintf(yyout, "%s\t\t\tINUM\n",yytext);
\+?[0-9]+\.[0-9]+  fprintf(yyout, "%s\t\t\tNUM\n ",yytext);
-[0-9]+\.[0-9]+     fprintf(yyout, "%s\t\t\tNUM\n",yytext);



.       { fprintf(yyout, "%s\t\t\tINVALID\n", yytext); } 
%% 
  
int yywrap(){} 
  
// driver code  
int main(int argc,char **argv) {
    extern FILE *yyin, *yyout; 
    yyin = fopen("Input.txt", "r"); 
    yyout = fopen("Output.txt", "w"); 
    yylex(); 
    return 0; 
} 