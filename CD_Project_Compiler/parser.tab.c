/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);

/* Symbol table implementation */
struct symbol {
    char* name;
    char* type;
    int address;  /* Memory address for the variable */
    struct symbol* next;
};

struct symbol* sym_table = NULL;
int next_address = 0;  /* Next available memory address */
int temp_count = 0;    /* Counter for temporary variables */

void add_symbol(char* name, char* type) {
    struct symbol* s = (struct symbol*)malloc(sizeof(struct symbol));
    s->name = strdup(name);
    s->type = strdup(type);
    s->address = next_address++;
    s->next = sym_table;
    sym_table = s;
}

struct symbol* find_symbol(char* name) {
    struct symbol* s;
    for (s = sym_table; s != NULL; s = s->next) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
    }
    return NULL;
}

/* Intermediate code generation */
FILE* outfile;
FILE* ir_file;  /* File for intermediate representation */
int label_count = 0;  /* Counter for labels */

char* new_temp() {
    char* temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    add_symbol(temp, "temp");
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(10);
    sprintf(label, "L%d", label_count++);
    return label;
}

void emit(char* op, char* arg1, char* arg2, char* result) {
    fprintf(ir_file, "%s, %s, %s, %s\n", op, arg1 ? arg1 : "", arg2 ? arg2 : "", result ? result : "");
}

void generate_program_header() {
    fprintf(outfile, "#include <stdio.h>\n");
    fprintf(outfile, "#include <stdlib.h>\n");
    fprintf(outfile, "#include <string.h>\n\n");
    fprintf(outfile, "// Generated C code from custom language\n\n");
    
    fprintf(ir_file, "// Intermediate Code\n");
    fprintf(ir_file, "// Format: Operation, Arg1, Arg2, Result\n\n");
}

void generate_main_header() {
    fprintf(outfile, "int main() {\n");
    emit("FUNC_BEGIN", "main", "", "");
}

void generate_main_footer() {
    fprintf(outfile, "    return 0;\n");
    fprintf(outfile, "}\n");
    emit("FUNC_END", "main", "", "");
}

#line 157 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHECK = 3,                      /* CHECK  */
  YYSYMBOL_ENDCHECK = 4,                   /* ENDCHECK  */
  YYSYMBOL_OTHERWISE = 5,                  /* OTHERWISE  */
  YYSYMBOL_ENDOTHERWISE = 6,               /* ENDOTHERWISE  */
  YYSYMBOL_DEFAULT = 7,                    /* DEFAULT  */
  YYSYMBOL_ENDDEFAULT = 8,                 /* ENDDEFAULT  */
  YYSYMBOL_LOOP = 9,                       /* LOOP  */
  YYSYMBOL_ENDLOOP = 10,                   /* ENDLOOP  */
  YYSYMBOL_START = 11,                     /* START  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_CALL = 13,                      /* CALL  */
  YYSYMBOL_GIVE = 14,                      /* GIVE  */
  YYSYMBOL_SHOW = 15,                      /* SHOW  */
  YYSYMBOL_ASK = 16,                       /* ASK  */
  YYSYMBOL_INTO = 17,                      /* INTO  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_TO = 19,                        /* TO  */
  YYSYMBOL_READ = 20,                      /* READ  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_GEQ = 32,                       /* GEQ  */
  YYSYMBOL_LEQ = 33,                       /* LEQ  */
  YYSYMBOL_COLON = 34,                     /* COLON  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_INT_LITERAL = 37,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 38,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 39,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 40,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_statement_list = 44,            /* statement_list  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_assignment = 46,                /* assignment  */
  YYSYMBOL_conditional_statement = 47,     /* conditional_statement  */
  YYSYMBOL_check_block = 48,               /* check_block  */
  YYSYMBOL_check_statement = 49,           /* check_statement  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_otherwise_statement_list = 51,  /* otherwise_statement_list  */
  YYSYMBOL_otherwise_statement = 52,       /* otherwise_statement  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_default_statement = 54,         /* default_statement  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_loop_statement = 56,            /* loop_statement  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_loop_init = 58,                 /* loop_init  */
  YYSYMBOL_loop_update = 59,               /* loop_update  */
  YYSYMBOL_function_definition = 60,       /* function_definition  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_param_list = 62,                /* param_list  */
  YYSYMBOL_function_call = 63,             /* function_call  */
  YYSYMBOL_arg_list = 64,                  /* arg_list  */
  YYSYMBOL_show_statement = 65,            /* show_statement  */
  YYSYMBOL_input_statement = 66,           /* input_statement  */
  YYSYMBOL_file_write_statement = 67,      /* file_write_statement  */
  YYSYMBOL_file_read_statement = 68,       /* file_read_statement  */
  YYSYMBOL_return_statement = 69,          /* return_statement  */
  YYSYMBOL_expr = 70                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   127,   149,   150,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   167,   185,   189,   190,
     191,   196,   195,   215,   216,   221,   220,   239,   238,   255,
     254,   278,   290,   299,   298,   313,   321,   332,   344,   349,
     357,   369,   389,   410,   435,   446,   451,   458,   465,   472,
     477,   482,   487,   492,   497,   502,   507,   512,   517,   522
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHECK", "ENDCHECK",
  "OTHERWISE", "ENDOTHERWISE", "DEFAULT", "ENDDEFAULT", "LOOP", "ENDLOOP",
  "START", "END", "CALL", "GIVE", "SHOW", "ASK", "INTO", "WRITE", "TO",
  "READ", "PLUS", "MINUS", "MULT", "DIV", "ASSIGN", "SEMICOLON", "COMMA",
  "EQ", "NEQ", "GT", "LT", "GEQ", "LEQ", "COLON", "LPAREN", "RPAREN",
  "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "$accept", "program", "$@1", "statement_list", "statement", "assignment",
  "conditional_statement", "check_block", "check_statement", "$@2",
  "otherwise_statement_list", "otherwise_statement", "$@3",
  "default_statement", "$@4", "loop_statement", "$@5", "loop_init",
  "loop_update", "function_definition", "$@6", "param_list",
  "function_call", "arg_list", "show_statement", "input_statement",
  "file_write_statement", "file_read_statement", "return_statement",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,     2,   129,   -34,    60,   -33,   -23,   -21,    60,    60,
      60,    60,    -1,   129,   -34,   -34,   -34,   -34,    24,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,    60,   -34,   -34,
     -34,   -34,   184,     7,     8,    -7,    60,   225,   225,   142,
     171,   114,   -34,    60,    13,   -34,   155,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,   -34,    60,    60,
     -34,   -26,    10,   225,     0,    60,    60,   225,   198,     1,
     -34,   -34,   -34,   236,   236,   -19,   -19,   225,   225,   225,
     225,   225,   225,   129,   225,   212,    15,   -34,    60,   -34,
     225,   225,   -34,   -34,    12,    16,   -34,   129,   225,   129,
     129,   -34,    14,    25,    54,    71,   101,    60,   -34,   -34,
     -34,   -34,   225,   129,   115,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     6,     7,    17,    18,     8,
       9,    10,    11,    12,    13,    14,    15,     0,    46,    47,
      48,    45,     0,     0,     0,     0,     0,    44,    40,     0,
       0,     0,     5,     0,    19,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
      35,     0,    37,    38,     0,     0,     0,    16,     0,     0,
      24,    20,    59,    49,    50,    51,    52,    57,    58,    53,
      54,    55,    56,     0,    31,     0,     0,    33,     0,    41,
      42,    43,    25,    27,     0,     0,    36,     0,    39,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    29,    34,
      26,    28,    32,     0,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,    23,   -13,   -34,   -34,   -34,   -34,   -34,
     -34,    -3,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    14,    15,    16,    17,    18,    83,
      44,    45,    99,    71,   100,    19,   113,    34,   103,    20,
      97,    61,    21,    62,    22,    23,    24,    25,    26,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    86,     3,    37,    38,    39,    40,    33,    87,    51,
      52,    53,    54,    55,    56,     4,   101,    35,    43,    36,
      69,     5,    46,     6,    41,     7,     8,     9,    10,    43,
      11,    63,    58,    60,    59,    93,    67,    88,    68,   107,
      89,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    12,    84,    85,    96,   102,     4,     0,   108,
      90,    91,     0,     5,     0,     6,   109,     7,     8,     9,
      10,     0,    11,     0,     4,     0,     0,   110,     0,     0,
       5,    42,     6,    98,     7,     8,     9,    10,     0,    11,
       0,    42,    42,    42,    12,    27,     0,    28,    29,    30,
      31,    42,   112,     0,     4,     0,    94,     0,     0,   111,
       5,    12,     6,     0,     7,     8,     9,    10,     4,    11,
     104,     0,   105,   106,     5,   115,     6,     0,     7,     8,
       9,    10,     4,    11,    66,     0,   114,     0,     5,     0,
       6,    12,     7,     8,     9,    10,     0,    11,     0,    27,
       0,    28,    29,    30,    31,    12,     0,     0,     0,    64,
       0,     0,     0,    47,    48,    49,    50,     0,     0,    12,
      51,    52,    53,    54,    55,    56,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,     0,
      65,    72,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,    47,
      48,    49,    50,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    92,    47,    48,    49,    50,     0,    95,     0,
      51,    52,    53,    54,    55,    56,    47,    48,    49,    50,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56
};

static const yytype_int8 yycheck[] =
{
      13,    27,     0,     8,     9,    10,    11,    40,    34,    28,
      29,    30,    31,    32,    33,     3,     4,    40,     5,    40,
       7,     9,    27,    11,    25,    13,    14,    15,    16,     5,
      18,    36,    25,    40,    26,    34,    41,    27,    43,    25,
      40,    44,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    40,    58,    59,    40,    40,     3,    -1,    34,
      65,    66,    -1,     9,    -1,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,     3,    -1,    -1,     6,    -1,    -1,
       9,    94,    11,    88,    13,    14,    15,    16,    -1,    18,
      -1,   104,   105,   106,    40,    35,    -1,    37,    38,    39,
      40,   114,   107,    -1,     3,    -1,    83,    -1,    -1,     8,
       9,    40,    11,    -1,    13,    14,    15,    16,     3,    18,
      97,    -1,    99,   100,     9,    10,    11,    -1,    13,    14,
      15,    16,     3,    18,    20,    -1,   113,    -1,     9,    -1,
      11,    40,    13,    14,    15,    16,    -1,    18,    -1,    35,
      -1,    37,    38,    39,    40,    40,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    40,
      28,    29,    30,    31,    32,    33,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      19,    36,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    21,    22,    23,    24,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,     9,    11,    13,    14,    15,
      16,    18,    40,    44,    45,    46,    47,    48,    49,    56,
      60,    63,    65,    66,    67,    68,    69,    35,    37,    38,
      39,    40,    70,    40,    58,    40,    40,    70,    70,    70,
      70,    25,    45,     5,    51,    52,    70,    21,    22,    23,
      24,    28,    29,    30,    31,    32,    33,    34,    25,    26,
      40,    62,    64,    70,    17,    19,    20,    70,    70,     7,
      52,    54,    36,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    50,    70,    70,    27,    34,    27,    40,
      70,    70,    34,    34,    44,    26,    40,    61,    70,    53,
      55,     4,    40,    59,    44,    44,    44,    25,    34,    12,
       6,     8,    70,    57,    44,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    47,    48,    48,
      48,    50,    49,    51,    51,    53,    52,    55,    54,    57,
      56,    58,    59,    61,    60,    62,    62,    63,    64,    64,
      65,    66,    67,    68,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       3,     0,     6,     1,     2,     0,     6,     0,     5,     0,
      10,     3,     3,     0,     7,     1,     3,     3,     1,     3,
       2,     4,     4,     4,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 127 "parser.y"
    { 
        /* Initialize output files and write headers */
        outfile = fopen("output.c", "w");
        ir_file = fopen("intermediate.ir", "w");
        if (outfile == NULL || ir_file == NULL) {
            fprintf(stderr, "Failed to open output files\n");
            exit(1);
        }
        generate_program_header();
        generate_main_header();
    }
#line 1330 "parser.tab.c"
    break;

  case 3: /* program: $@1 statement_list  */
#line 139 "parser.y"
    { 
        /* Write footers and close files */
        generate_main_footer();
        fclose(outfile);
        fclose(ir_file);
        printf("Compilation successful. Generated intermediate.ir\n");
    }
#line 1342 "parser.tab.c"
    break;

  case 16: /* assignment: IDENTIFIER ASSIGN expr  */
#line 168 "parser.y"
    { 
        /* Add symbol to table if not already there */
        if (!find_symbol((yyvsp[-2].sval))) {
            add_symbol((yyvsp[-2].sval), "var");
        }
        
        /* Generate C code */
        fprintf(outfile, "    /* Assignment */\n");
        fprintf(outfile, "    %s = %s;\n", (yyvsp[-2].sval), (yyvsp[0].expr_attr).place);
        
        /* Generate intermediate code */
        emit("ASSIGN", (yyvsp[0].expr_attr).place, "", (yyvsp[-2].sval));
    }
#line 1360 "parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 196 "parser.y"
    { 
        char* label_else = new_label();
        char* label_end = new_label();
        
        /* Generate C code */
        fprintf(outfile, "    /* Check statement */\n");
        fprintf(outfile, "    if (%s) {\n", (yyvsp[-1].expr_attr).place);
        
        /* Generate intermediate code */
        emit("IF_FALSE", (yyvsp[-1].expr_attr).place, "", label_else);
    }
#line 1376 "parser.tab.c"
    break;

  case 22: /* check_statement: CHECK expr COLON $@2 statement_list ENDCHECK  */
#line 208 "parser.y"
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_if");
    }
#line 1385 "parser.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 221 "parser.y"
    {
        char* label_else = new_label();
        
        fprintf(outfile, "    /* Otherwise statement */\n");
        fprintf(outfile, "    else if (%s) {\n", (yyvsp[-1].expr_attr).place);
        
        /* Generate intermediate code */
        emit("IF_FALSE", (yyvsp[-1].expr_attr).place, "", label_else);
    }
#line 1399 "parser.tab.c"
    break;

  case 26: /* otherwise_statement: OTHERWISE expr COLON $@3 statement_list ENDOTHERWISE  */
#line 231 "parser.y"
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_elif");
    }
#line 1408 "parser.tab.c"
    break;

  case 27: /* $@4: %empty  */
#line 239 "parser.y"
    {
        fprintf(outfile, "    /* Default statement */\n");
        fprintf(outfile, "    else {\n");
        
        /* Generate intermediate code */
        emit("LABEL", "", "", "else_block");
    }
#line 1420 "parser.tab.c"
    break;

  case 28: /* default_statement: DEFAULT COLON $@4 statement_list ENDDEFAULT  */
#line 247 "parser.y"
    {
        fprintf(outfile, "    }\n");
        emit("LABEL", "", "", "end_if_all");
    }
#line 1429 "parser.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 255 "parser.y"
    {
        char* start_label = new_label();
        char* end_label = new_label();
        
        fprintf(outfile, "    /* Loop statement */\n");
        fprintf(outfile, "    for (%s; %s; %s) {\n", (yyvsp[-5].expr_attr).place, (yyvsp[-3].expr_attr).place, (yyvsp[-1].expr_attr).place);
        
        /* Generate intermediate code */
        emit("LABEL", "", "", start_label);
        emit("IF_FALSE", (yyvsp[-3].expr_attr).place, "", end_label);
    }
#line 1445 "parser.tab.c"
    break;

  case 30: /* loop_statement: LOOP loop_init SEMICOLON expr SEMICOLON loop_update COLON $@5 statement_list ENDLOOP  */
#line 267 "parser.y"
    {
        fprintf(outfile, "    }\n");
        
        /* Generate loop continuation */
        emit("GOTO", "", "", "loop_start");
        emit("LABEL", "", "", "loop_end");
    }
#line 1457 "parser.tab.c"
    break;

  case 31: /* loop_init: IDENTIFIER ASSIGN expr  */
#line 279 "parser.y"
    {
        if (!find_symbol((yyvsp[-2].sval))) {
            add_symbol((yyvsp[-2].sval), "var");
        }
        (yyval.expr_attr).place = malloc(strlen((yyvsp[-2].sval)) + strlen((yyvsp[0].expr_attr).place) + 5);
        sprintf((yyval.expr_attr).place, "%s = %s", (yyvsp[-2].sval), (yyvsp[0].expr_attr).place);
        emit("ASSIGN", (yyvsp[0].expr_attr).place, "", (yyvsp[-2].sval));
    }
#line 1470 "parser.tab.c"
    break;

  case 32: /* loop_update: IDENTIFIER ASSIGN expr  */
#line 291 "parser.y"
    {
        (yyval.expr_attr).place = malloc(strlen((yyvsp[-2].sval)) + strlen((yyvsp[0].expr_attr).place) + 5);
        sprintf((yyval.expr_attr).place, "%s = %s", (yyvsp[-2].sval), (yyvsp[0].expr_attr).place);
        emit("ASSIGN", (yyvsp[0].expr_attr).place, "", (yyvsp[-2].sval));
    }
#line 1480 "parser.tab.c"
    break;

  case 33: /* $@6: %empty  */
#line 299 "parser.y"
    {
        fprintf(outfile, "\n/* Function definition */\n");
        
        /* Generate intermediate code */
        emit("FUNC_BEGIN", (yyvsp[-2].sval), "", "");
    }
#line 1491 "parser.tab.c"
    break;

  case 34: /* function_definition: START IDENTIFIER param_list COLON $@6 statement_list END  */
#line 306 "parser.y"
    {
        fprintf(outfile, "}\n\n");
        emit("FUNC_END", "", "", "");
    }
#line 1500 "parser.tab.c"
    break;

  case 35: /* param_list: IDENTIFIER  */
#line 314 "parser.y"
    {
        fprintf(outfile, "void %s(int %s) {\n", (yyvsp[(-1) - (1)].sval), (yyvsp[0].sval));
        add_symbol((yyvsp[0].sval), "param");
        
        /* Generate intermediate code */
        emit("PARAM", (yyvsp[0].sval), "", "");
    }
#line 1512 "parser.tab.c"
    break;

  case 36: /* param_list: param_list COMMA IDENTIFIER  */
#line 322 "parser.y"
    {
        // Add parameter to symbol table
        add_symbol((yyvsp[0].sval), "param");
        
        /* Generate intermediate code */
        emit("PARAM", (yyvsp[0].sval), "", "");
    }
#line 1524 "parser.tab.c"
    break;

  case 37: /* function_call: CALL IDENTIFIER arg_list  */
#line 333 "parser.y"
    {
        // Generate function call code
        fprintf(outfile, "    /* Function call */\n");
        fprintf(outfile, "    %s(/* args */);\n", (yyvsp[-1].sval));
        
        /* Generate intermediate code */
        emit("CALL", (yyvsp[-1].sval), "", "");
    }
#line 1537 "parser.tab.c"
    break;

  case 38: /* arg_list: expr  */
#line 345 "parser.y"
    {
        /* Generate intermediate code */
        emit("ARG", (yyvsp[0].expr_attr).place, "", "");
    }
#line 1546 "parser.tab.c"
    break;

  case 39: /* arg_list: arg_list COMMA expr  */
#line 350 "parser.y"
    {
        /* Generate intermediate code */
        emit("ARG", (yyvsp[0].expr_attr).place, "", "");
    }
#line 1555 "parser.tab.c"
    break;

  case 40: /* show_statement: SHOW expr  */
#line 358 "parser.y"
    {
        /* Generate C code for print statement */
        fprintf(outfile, "    /* Show statement */\n");
        fprintf(outfile, "    printf(\"%s\\n\");\n", (yyvsp[0].expr_attr).place);
        
        /* Generate intermediate code */
        emit("PRINT", (yyvsp[0].expr_attr).place, "", "");
    }
#line 1568 "parser.tab.c"
    break;

  case 41: /* input_statement: ASK expr INTO IDENTIFIER  */
#line 370 "parser.y"
    {
        /* Add variable to symbol table */
        add_symbol((yyvsp[0].sval), "var");
        
        /* Generate C code for input */
        fprintf(outfile, "    /* Input statement */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        printf(\"%s \");\n", (yyvsp[-2].expr_attr).place);
        fprintf(outfile, "        char %s[100];\n", (yyvsp[0].sval));
        fprintf(outfile, "        scanf(\"%%s\", %s);\n", (yyvsp[0].sval));
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("PROMPT", (yyvsp[-2].expr_attr).place, "", "");
        emit("INPUT", "", "", (yyvsp[0].sval));
    }
#line 1589 "parser.tab.c"
    break;

  case 42: /* file_write_statement: WRITE expr TO expr  */
#line 390 "parser.y"
    {
        fprintf(outfile, "    /* Write to file */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        FILE* f = fopen(%s, \"w\");\n", (yyvsp[0].expr_attr).place);
        fprintf(outfile, "        if (f != NULL) {\n");
        fprintf(outfile, "            fprintf(f, \"%%s\", %s);\n", (yyvsp[-2].expr_attr).place);
        fprintf(outfile, "            fclose(f);\n");
        fprintf(outfile, "        } else {\n");
        fprintf(outfile, "            printf(\"Error opening file\\n\");\n");
        fprintf(outfile, "        }\n");
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("FOPEN", (yyvsp[0].expr_attr).place, "w", "file_ptr");
        emit("FWRITE", (yyvsp[-2].expr_attr).place, "", "file_ptr");
        emit("FCLOSE", "file_ptr", "", "");
    }
#line 1611 "parser.tab.c"
    break;

  case 43: /* file_read_statement: IDENTIFIER ASSIGN READ expr  */
#line 411 "parser.y"
    {
        /* Add variable to symbol table */
        add_symbol((yyvsp[-3].sval), "var");
        
        fprintf(outfile, "    /* Read from file */\n");
        fprintf(outfile, "    {\n");
        fprintf(outfile, "        FILE* f = fopen(%s, \"r\");\n", (yyvsp[0].expr_attr).place);
        fprintf(outfile, "        if (f != NULL) {\n");
        fprintf(outfile, "            char %s[1000];\n", (yyvsp[-3].sval));
        fprintf(outfile, "            fgets(%s, 1000, f);\n", (yyvsp[-3].sval));
        fprintf(outfile, "            fclose(f);\n");
        fprintf(outfile, "        } else {\n");
        fprintf(outfile, "            printf(\"Error opening file\\n\");\n");
        fprintf(outfile, "        }\n");
        fprintf(outfile, "    }\n");
        
        /* Generate intermediate code */
        emit("FOPEN", (yyvsp[0].expr_attr).place, "r", "file_ptr");
        emit("FREAD", "", "", (yyvsp[-3].sval));
        emit("FCLOSE", "file_ptr", "", "");
    }
#line 1637 "parser.tab.c"
    break;

  case 44: /* return_statement: GIVE expr  */
#line 436 "parser.y"
    {
        fprintf(outfile, "    /* Return statement */\n");
        fprintf(outfile, "    return %s;\n", (yyvsp[0].expr_attr).place);
        
        /* Generate intermediate code */
        emit("RETURN", (yyvsp[0].expr_attr).place, "", "");
    }
#line 1649 "parser.tab.c"
    break;

  case 45: /* expr: IDENTIFIER  */
#line 447 "parser.y"
    { 
        (yyval.expr_attr).place = (yyvsp[0].sval);
        (yyval.expr_attr).code = strdup("");
    }
#line 1658 "parser.tab.c"
    break;

  case 46: /* expr: INT_LITERAL  */
#line 452 "parser.y"
    { 
        char temp[20]; 
        sprintf(temp, "%d", (yyvsp[0].ival)); 
        (yyval.expr_attr).place = strdup(temp);
        (yyval.expr_attr).code = strdup("");
    }
#line 1669 "parser.tab.c"
    break;

  case 47: /* expr: FLOAT_LITERAL  */
#line 459 "parser.y"
    { 
        char temp[20]; 
        sprintf(temp, "%f", (yyvsp[0].fval)); 
        (yyval.expr_attr).place = strdup(temp);
        (yyval.expr_attr).code = strdup("");
    }
#line 1680 "parser.tab.c"
    break;

  case 48: /* expr: STRING_LITERAL  */
#line 466 "parser.y"
    { 
        char temp[strlen((yyvsp[0].sval)) + 3]; 
        sprintf(temp, "\"%s\"", (yyvsp[0].sval)); 
        (yyval.expr_attr).place = strdup(temp);
        (yyval.expr_attr).code = strdup("");
    }
#line 1691 "parser.tab.c"
    break;

  case 49: /* expr: expr PLUS expr  */
#line 473 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("ADD", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1700 "parser.tab.c"
    break;

  case 50: /* expr: expr MINUS expr  */
#line 478 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("SUB", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1709 "parser.tab.c"
    break;

  case 51: /* expr: expr MULT expr  */
#line 483 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("MUL", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1718 "parser.tab.c"
    break;

  case 52: /* expr: expr DIV expr  */
#line 488 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("DIV", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1727 "parser.tab.c"
    break;

  case 53: /* expr: expr GT expr  */
#line 493 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("GT", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1736 "parser.tab.c"
    break;

  case 54: /* expr: expr LT expr  */
#line 498 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("LT", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1745 "parser.tab.c"
    break;

  case 55: /* expr: expr GEQ expr  */
#line 503 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("GE", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1754 "parser.tab.c"
    break;

  case 56: /* expr: expr LEQ expr  */
#line 508 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("LE", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1763 "parser.tab.c"
    break;

  case 57: /* expr: expr EQ expr  */
#line 513 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("EQ", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1772 "parser.tab.c"
    break;

  case 58: /* expr: expr NEQ expr  */
#line 518 "parser.y"
    { 
        (yyval.expr_attr).place = new_temp();
        emit("NE", (yyvsp[-2].expr_attr).place, (yyvsp[0].expr_attr).place, (yyval.expr_attr).place);
    }
#line 1781 "parser.tab.c"
    break;

  case 59: /* expr: LPAREN expr RPAREN  */
#line 523 "parser.y"
    { 
        (yyval.expr_attr).place = (yyvsp[-1].expr_attr).place;
        (yyval.expr_attr).code = (yyvsp[-1].expr_attr).code;
    }
#line 1790 "parser.tab.c"
    break;


#line 1794 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 529 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s near '%s'\n", yylineno, s, yytext);
    exit(1);
}

int main(int argc, char* argv[]) {
    printf("Starting compiler for custom language...\n");
    
    /* If filename provided, read from file */
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open input file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    /* Parse input */
    yyparse();
    
    printf("Parsing completed successfully.\n");
    return 0;
}
