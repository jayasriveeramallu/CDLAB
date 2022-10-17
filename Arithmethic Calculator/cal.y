%{
#include<stdio.h>
extern int yylex();
extern void yyerror(char*);
%}
%start stat
%token NUMBER
%token ID
%left '+' '-'
%left '*' '/'
%%
stat:   exp '\n'        {
                        printf("%d\n",$1);
                        }
                ;
exp:    exp '+' exp    {
                                $$ = $1+$3;
                       }
        | exp '-' exp  {
                                $$ = $1-$3;
                       }
        | exp '*' exp  {
                                $$=$1*$3;
                       }
        | exp '/' exp  {
                                $$=$1*$3;
                       }
        | NUMBER       {
                                $$=$1;
                       }
       | ID            {
                                printf("\nEnter value:");
                                int tmp;
                                scanf("%d",&tmp);
                                $$=tmp;
                      }
        ;

%%
int main()
{
        yyparse();
}

