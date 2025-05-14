/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHECK = 258,                   /* CHECK  */
    ENDCHECK = 259,                /* ENDCHECK  */
    OTHERWISE = 260,               /* OTHERWISE  */
    ENDOTHERWISE = 261,            /* ENDOTHERWISE  */
    DEFAULT = 262,                 /* DEFAULT  */
    ENDDEFAULT = 263,              /* ENDDEFAULT  */
    LOOP = 264,                    /* LOOP  */
    ENDLOOP = 265,                 /* ENDLOOP  */
    START = 266,                   /* START  */
    END = 267,                     /* END  */
    CALL = 268,                    /* CALL  */
    GIVE = 269,                    /* GIVE  */
    SHOW = 270,                    /* SHOW  */
    ASK = 271,                     /* ASK  */
    INTO = 272,                    /* INTO  */
    WRITE = 273,                   /* WRITE  */
    TO = 274,                      /* TO  */
    READ = 275,                    /* READ  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    MULT = 278,                    /* MULT  */
    DIV = 279,                     /* DIV  */
    ASSIGN = 280,                  /* ASSIGN  */
    SEMICOLON = 281,               /* SEMICOLON  */
    COMMA = 282,                   /* COMMA  */
    EQ = 283,                      /* EQ  */
    NEQ = 284,                     /* NEQ  */
    GT = 285,                      /* GT  */
    LT = 286,                      /* LT  */
    GEQ = 287,                     /* GEQ  */
    LEQ = 288,                     /* LEQ  */
    COLON = 289,                   /* COLON  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    INT_LITERAL = 292,             /* INT_LITERAL  */
    FLOAT_LITERAL = 293,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 294,          /* STRING_LITERAL  */
    IDENTIFIER = 295               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 87 "parser.y"

    int ival;
    float fval;
    char* sval;
    struct {
        char* place;  /* Name of the temporary holding the value */
        char* code;   /* Generated code string */
        char* true_label;  /* For boolean expressions */
        char* false_label; /* For boolean expressions */
    } expr_attr;

#line 116 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
