%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

void yyerror(const char* s);
%}

%%
"check"         { return CHECK; }
"endcheck"      { return ENDCHECK; }
"otherwise"     { return OTHERWISE; }
"endotherwise"  { return ENDOTHERWISE; }
"default"       { return DEFAULT; }
"enddefault"    { return ENDDEFAULT; }
"show"          { return SHOW; }
"loop"          { return LOOP; }
"endloop"       { return ENDLOOP; }
"start"         { return START; }
"end"           { return END; }
"call"          { return CALL; }
"give"          { return GIVE; }
"ask"           { return ASK; }
"into"          { return INTO; }
"write"         { return WRITE; }
"to"            { return TO; }
"read"          { return READ; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"="             { return ASSIGN; }
";"             { return SEMICOLON; }
","             { return COMMA; }

"=="            { return EQ; }
"!="            { return NEQ; }
">"             { return GT; }
"<"             { return LT; }
">="            { return GEQ; }
"<="            { return LEQ; }

":"             { return COLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }

[0-9]+          { yylval.ival = atoi(yytext); return INT_LITERAL; }
[0-9]+\.[0-9]+  { yylval.fval = atof(yytext); return FLOAT_LITERAL; }
\"[^\"]*\"      { 
                  /* Remove quotes from string */
                  yytext[strlen(yytext)-1] = '\0';
                  yylval.sval = strdup(yytext+1);
                  return STRING_LITERAL; 
                }
'[^']*'         { 
                  /* Remove quotes from string */
                  yytext[strlen(yytext)-1] = '\0';
                  yylval.sval = strdup(yytext+1);
                  return STRING_LITERAL; 
                }

"//"[^\n]*      { /* Ignore comments */ }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }

[ \t]           { /* Ignore whitespace */ }
\n              { yylineno++; }
.               { yyerror("Invalid character"); }
%%

int yywrap() {
    return 1;
}