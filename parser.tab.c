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

#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/record.h"
#include "./lib/symbol_table.h"

// Protótipos de funções
int yylex(void);
void yyerror(const char *s);
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5);
const char* map_type(const char* o);

// Variáveis externas do Flex
extern int yylineno;
extern char *yytext;
extern FILE *yyin, *yyout;

// Contador para gerar labels
static int label_count = 0;
char *new_label() {
    char buf[32];
    sprintf(buf, "L%d", label_count++);
    return strdup(buf);
}

#line 99 "parser.tab.c"

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
  YYSYMBOL_UNIT = 3,                       /* UNIT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RATIONAL = 6,                   /* RATIONAL  */
  YYSYMBOL_MATRIX = 7,                     /* MATRIX  */
  YYSYMBOL_BST = 8,                        /* BST  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_PRINT_STRING = 10,              /* PRINT_STRING  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_REF = 14,                       /* REF  */
  YYSYMBOL_AMPERSAND = 15,                 /* AMPERSAND  */
  YYSYMBOL_ARROW_LEFT = 16,                /* ARROW_LEFT  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_MUL = 19,                       /* MUL  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NE = 26,                        /* NE  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_INT_LIT = 34,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 35,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 36,                /* STRING_LIT  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_decl_list = 39,                 /* decl_list  */
  YYSYMBOL_func_decl = 40,                 /* func_decl  */
  YYSYMBOL_param_list_opt = 41,            /* param_list_opt  */
  YYSYMBOL_param_list = 42,                /* param_list  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_stmt_list = 44,                 /* stmt_list  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_var_decl_stmt = 46,             /* var_decl_stmt  */
  YYSYMBOL_lvalue = 47,                    /* lvalue  */
  YYSYMBOL_assignment_stmt = 48,           /* assignment_stmt  */
  YYSYMBOL_func_call_stmt = 49,            /* func_call_stmt  */
  YYSYMBOL_print_stmt = 50,                /* print_stmt  */
  YYSYMBOL_print_string_stmt = 51,         /* print_string_stmt  */
  YYSYMBOL_return_stmt = 52,               /* return_stmt  */
  YYSYMBOL_if_stmt = 53,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 54,                /* while_stmt  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_expr = 56,                      /* expr  */
  YYSYMBOL_func_call = 57,                 /* func_call  */
  YYSYMBOL_arg_list_opt = 58,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 59                   /* arg_list  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    76,    77,    85,    92,   102,   103,   107,
     108,   116,   122,   135,   136,   144,   145,   146,   147,   148,
     149,   150,   151,   155,   161,   171,   183,   193,   210,   217,
     238,   252,   259,   270,   285,   286,   287,   288,   289,   290,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   312,   325,   326,   327,   331,   359,   360,   364,
     365
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
  "\"end of file\"", "error", "\"invalid token\"", "UNIT", "FLOAT", "INT",
  "RATIONAL", "MATRIX", "BST", "PRINT", "PRINT_STRING", "RETURN", "IF",
  "WHILE", "REF", "AMPERSAND", "ARROW_LEFT", "PLUS", "MINUS", "MUL", "DIV",
  "LT", "LE", "GT", "GE", "EQ", "NE", "SEMICOLON", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "COMMA", "ID", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "$accept", "program", "decl_list", "func_decl", "param_list_opt",
  "param_list", "param", "stmt_list", "stmt", "var_decl_stmt", "lvalue",
  "assignment_stmt", "func_call_stmt", "print_stmt", "print_string_stmt",
  "return_stmt", "if_stmt", "while_stmt", "type", "expr", "func_call",
  "arg_list_opt", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     212,  -104,  -104,  -104,  -104,  -104,  -104,    18,   212,  -104,
     -14,  -104,  -104,    -3,    72,   212,     1,    -6,  -104,     3,
      22,    41,    72,  -104,  -104,  -104,  -104,  -104,     2,   -11,
      -2,   -11,    42,    46,    36,  -104,    55,  -104,  -104,    68,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,    67,    74,    69,
     -11,    55,  -104,  -104,   144,  -104,    76,   155,   -11,   -11,
    -104,   -11,   -11,     0,  -104,  -104,   105,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,  -104,  -104,  -104,
     118,   131,   188,    77,    73,   166,   -11,  -104,  -104,    28,
      28,   200,   200,  -104,  -104,  -104,  -104,  -104,  -104,    78,
      79,  -104,   -11,  -104,   177,  -104,  -104,   188,  -104,    54,
      85,  -104,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    36,    35,    34,    37,    38,    39,     0,     2,     3,
       0,     1,     4,     0,     7,     0,     0,     8,     9,     0,
       0,     0,     0,    11,    12,     6,    13,    10,     0,     0,
       0,     0,     0,     0,     0,     5,    25,    14,    15,     0,
      16,    20,    17,    18,    19,    21,    22,     0,     0,     0,
       0,    52,    53,    54,     0,    55,     0,     0,     0,     0,
      26,    57,     0,     0,    28,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
       0,     0,    59,     0,    58,     0,     0,    23,    50,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
       0,    56,     0,    27,     0,    13,    13,    60,    24,     0,
       0,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,   102,  -104,  -104,    89,  -103,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    99,   -30,
     -28,  -104,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    16,    17,    18,    28,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    54,
      55,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    57,   109,   110,    49,     1,     2,     3,     4,     5,
       6,    29,    30,    31,    32,    33,    86,    50,    11,    13,
      66,    34,    51,    52,    53,    14,    22,    87,    80,    81,
      21,    82,    85,    35,    56,    36,    23,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    69,    70,    71,
      72,    73,    74,    75,    76,    24,   104,     1,     2,     3,
       4,     5,     6,    29,    30,    31,    32,    33,    25,    60,
      58,    26,   107,    34,    59,     1,     2,     3,     4,     5,
       6,    48,    48,    61,    62,   111,    15,    36,     1,     2,
       3,     4,     5,     6,    29,    30,    31,    32,    33,    10,
      63,    64,    65,    78,    34,   102,   101,    10,   105,   106,
      12,    27,     0,    19,    20,     0,   112,     0,    36,     0,
       0,    19,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    88,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    99,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
     100,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    79,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   103,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,   108,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     1,     2,     3,     4,     5,
       6,    71,    72,    73,    74,    75,    76
};

static const yytype_int8 yycheck[] =
{
      28,    31,   105,   106,    15,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    16,    28,     0,    33,
      50,    19,    33,    34,    35,    28,    32,    27,    58,    59,
      29,    61,    62,    31,    36,    33,    33,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    19,    20,    21,
      22,    23,    24,    25,    26,    33,    86,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    27,    33,
      28,    30,   102,    19,    28,     3,     4,     5,     6,     7,
       8,   109,   110,    28,    16,    31,    14,    33,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      33,    27,    33,    27,    19,    32,    29,     8,    30,    30,
       8,    22,    -1,    14,    15,    -1,    31,    -1,    33,    -1,
      -1,    22,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    29,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     3,     4,     5,     6,     7,
       8,    21,    22,    23,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    38,    39,    40,
      55,     0,    40,    33,    28,    14,    41,    42,    43,    55,
      55,    29,    32,    33,    33,    27,    30,    43,    44,     9,
      10,    11,    12,    13,    19,    31,    33,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    57,    15,
      28,    33,    34,    35,    56,    57,    36,    56,    28,    28,
      33,    28,    16,    33,    27,    33,    56,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    27,    27,
      56,    56,    56,    58,    59,    56,    16,    27,    29,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    29,
      29,    29,    32,    27,    56,    30,    30,    56,    27,    44,
      44,    31,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    58,    58,    59,
      59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     8,     6,     0,     1,     1,
       3,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     1,     2,     4,     2,     3,
       3,     3,     7,     7,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     4,     0,     1,     1,
       3
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
  case 2: /* program: decl_list  */
#line 63 "parser.y"
              {
        fprintf(yyout,
            "#include <stdio.h>\n"
            "#include <stdlib.h>\n"
            "#include <stdbool.h>\n"
            "float read() { float v; if (scanf(\"%%f\", &v)!=1) return -1.0f; return v;}\n\n"
        );
        fprintf(yyout, "%s\n", (yyvsp[0].rec)->code);
        freeRecord((yyvsp[0].rec));
    }
#line 1251 "parser.tab.c"
    break;

  case 4: /* decl_list: decl_list func_decl  */
#line 77 "parser.y"
                          {
        char *s = cat((yyvsp[-1].rec)->code, "\n\n", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1261 "parser.tab.c"
    break;

  case 5: /* func_decl: type ID LPAREN param_list_opt RPAREN LBRACE stmt_list RBRACE  */
#line 85 "parser.y"
                                                                 {
        const char *rt = strcmp((yyvsp[-6].str_val), "main")==0 ? "int" : map_type((yyvsp[-7].rec)->code);
        char *h = cat(rt, " ", (yyvsp[-6].str_val), "(", (yyvsp[-4].rec)->code);
        char *b = cat(h, ") {\n", (yyvsp[-1].rec)->code, "}\n", "");
        (yyval.rec) = createRecord(b, ""); free(h); free(b);
        freeRecord((yyvsp[-7].rec)); free((yyvsp[-6].str_val)); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1273 "parser.tab.c"
    break;

  case 6: /* func_decl: type ID LPAREN param_list_opt RPAREN SEMICOLON  */
#line 92 "parser.y"
                                                   {
        const char *rt = map_type((yyvsp[-5].rec)->code);
        char *h = cat(rt, " ", (yyvsp[-4].str_val), "(", (yyvsp[-2].rec)->code);
        char *p = cat(h, ");\n", "", "", "");
        (yyval.rec) = createRecord(p, ""); free(h); free(p);
        freeRecord((yyvsp[-5].rec)); free((yyvsp[-4].str_val)); freeRecord((yyvsp[-2].rec));
    }
#line 1285 "parser.tab.c"
    break;

  case 7: /* param_list_opt: %empty  */
#line 102 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1291 "parser.tab.c"
    break;

  case 10: /* param_list: param_list COMMA param  */
#line 108 "parser.y"
                             {
        char *s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1301 "parser.tab.c"
    break;

  case 11: /* param: type ID  */
#line 116 "parser.y"
            {
        char *s = cat((yyvsp[-1].rec)->code, " ", (yyvsp[0].str_val), "", "");
        (yyval.rec) = createRecord(s, (yyvsp[-1].rec)->opt1);
        insertSymbol((yyvsp[0].str_val), (yyvsp[-1].rec)->opt1);
        free(s); freeRecord((yyvsp[-1].rec)); free((yyvsp[0].str_val));
    }
#line 1312 "parser.tab.c"
    break;

  case 12: /* param: REF type ID  */
#line 122 "parser.y"
                {
        const char* c_type = map_type((yyvsp[-1].rec)->opt1);
        char* ptr_type = cat(c_type, "*", "", "", "");
        char* param_decl = cat(ptr_type, " ", (yyvsp[0].str_val), "", "");
        char* lang_type = cat("ref", (yyvsp[-1].rec)->opt1, "", "", "");
        (yyval.rec) = createRecord(param_decl, lang_type);
        insertSymbol((yyvsp[0].str_val), lang_type);
        free(ptr_type); free(param_decl); free(lang_type);
        freeRecord((yyvsp[-1].rec)); free((yyvsp[0].str_val));
    }
#line 1327 "parser.tab.c"
    break;

  case 13: /* stmt_list: %empty  */
#line 135 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1333 "parser.tab.c"
    break;

  case 14: /* stmt_list: stmt_list stmt  */
#line 136 "parser.y"
                     {
        char *s = cat((yyvsp[-1].rec)->code, (yyvsp[0].rec)->code, "\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1343 "parser.tab.c"
    break;

  case 23: /* var_decl_stmt: type ID SEMICOLON  */
#line 155 "parser.y"
                      {
        char *s = cat("    ", (yyvsp[-2].rec)->code, " ", (yyvsp[-1].str_val), ";");
        (yyval.rec) = createRecord(s, ""); free(s);
        insertSymbol((yyvsp[-1].str_val), (yyvsp[-2].rec)->opt1);
        freeRecord((yyvsp[-2].rec)); free((yyvsp[-1].str_val));
    }
#line 1354 "parser.tab.c"
    break;

  case 24: /* var_decl_stmt: type ID ARROW_LEFT expr SEMICOLON  */
#line 161 "parser.y"
                                      {
        char *p = cat("    ", (yyvsp[-4].rec)->code, " ", (yyvsp[-3].str_val), " = ");
        char *s = cat(p, (yyvsp[-1].rec)->code, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(p); free(s);
        insertSymbol((yyvsp[-3].str_val), (yyvsp[-4].rec)->opt1);
        freeRecord((yyvsp[-4].rec)); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 1366 "parser.tab.c"
    break;

  case 25: /* lvalue: ID  */
#line 171 "parser.y"
       { 
        const char* type = lookupSymbol((yyvsp[0].str_val));
        if (type && strncmp(type, "ref", 3) == 0) {
            // Para parâmetros de referência, marcamos com prefixo especial
            char* ref_code = cat("REF_", (yyvsp[0].str_val), "", "", "");
            (yyval.rec) = createRecord(ref_code, strdup(type));
            free(ref_code);
        } else {
            (yyval.rec) = createRecord((yyvsp[0].str_val), strdup(type ? type : "Unknown"));
        }
        free((yyvsp[0].str_val)); 
    }
#line 1383 "parser.tab.c"
    break;

  case 26: /* lvalue: MUL ID  */
#line 183 "parser.y"
           {
        char* deref_code = cat("*", (yyvsp[0].str_val), "", "", "");
        const char* ptr_type = lookupSymbol((yyvsp[0].str_val));
        char* base_type = strdup(ptr_type ? ptr_type + 3 : "Unknown");
        (yyval.rec) = createRecord(deref_code, base_type);
        free(deref_code); free(base_type); free((yyvsp[0].str_val));
    }
#line 1395 "parser.tab.c"
    break;

  case 27: /* assignment_stmt: lvalue ARROW_LEFT expr SEMICOLON  */
#line 193 "parser.y"
                                     {
        char *s;
        
        // Se o lvalue tem prefixo REF_, é um parâmetro de referência
        if (strncmp((yyvsp[-3].rec)->code, "REF_", 4) == 0) {
            char* var_name = (yyvsp[-3].rec)->code + 4; // Remove prefixo REF_
            s = cat("    *", var_name, " = ", (yyvsp[-1].rec)->code, ";");
        } else {
            s = cat("    ", (yyvsp[-3].rec)->code, " = ", (yyvsp[-1].rec)->code, ";");
        }
        
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-3].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1414 "parser.tab.c"
    break;

  case 28: /* func_call_stmt: func_call SEMICOLON  */
#line 210 "parser.y"
                        {
        char *s = cat("    ", (yyvsp[-1].rec)->code, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); freeRecord((yyvsp[-1].rec));
    }
#line 1423 "parser.tab.c"
    break;

  case 29: /* print_stmt: PRINT expr SEMICOLON  */
#line 217 "parser.y"
                         {
        char *s;
        if (strcmp((yyvsp[-1].rec)->opt1, "Float") == 0) {
            s = cat("    printf(\"%f\\n\", ", (yyvsp[-1].rec)->code, ");", "", "");
        } else if (strcmp((yyvsp[-1].rec)->opt1, "Int") == 0) {
            s = cat("    printf(\"%d\\n\", ", (yyvsp[-1].rec)->code, ");", "", "");
        } else if (strcmp((yyvsp[-1].rec)->opt1, "Rational") == 0) {
            s = cat("    print_rational(", (yyvsp[-1].rec)->code, ");", "", "");
        } else if (strcmp((yyvsp[-1].rec)->opt1, "Matrix") == 0) {
            s = cat("    print_matrix(", (yyvsp[-1].rec)->code, ");", "", "");
        } else if (strcmp((yyvsp[-1].rec)->opt1, "BST") == 0) {
            s = cat("    print_bst_by_level(", (yyvsp[-1].rec)->code, ");", "", "");
        } else {
            // Padrão: assume Float para valores desconhecidos
            s = cat("    printf(\"%f\\n\", ", (yyvsp[-1].rec)->code, ");", "", "");
        }
        (yyval.rec) = createRecord(s, ""); free(s); freeRecord((yyvsp[-1].rec));
    }
#line 1446 "parser.tab.c"
    break;

  case 30: /* print_string_stmt: PRINT_STRING STRING_LIT SEMICOLON  */
#line 238 "parser.y"
                                      {
        // Remove as aspas da string literal
        char *str = (yyvsp[-1].str_val);
        int len = strlen(str);
        char *clean_str = malloc(len - 1);
        strncpy(clean_str, str + 1, len - 2);
        clean_str[len - 2] = '\0';
        
        char *s = cat("    printf(\"", clean_str, "\\n\");", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); free(clean_str); free((yyvsp[-1].str_val));
    }
#line 1462 "parser.tab.c"
    break;

  case 31: /* return_stmt: RETURN expr SEMICOLON  */
#line 252 "parser.y"
                          {
        char *s = cat("    return ", (yyvsp[-1].rec)->code, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); freeRecord((yyvsp[-1].rec));
    }
#line 1471 "parser.tab.c"
    break;

  case 32: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 259 "parser.y"
                                                  {
        char *lend = new_label();
        char *cond = cat("    if (!(", (yyvsp[-4].rec)->code, ")) goto ", lend, ";");
        char *body = (yyvsp[-1].rec)->code;
        char *code = cat(cond, "\n", body, "\n", lend);
        code = cat(code, ":", "", "", "");
        (yyval.rec) = createRecord(code, ""); free(cond); free(lend); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1484 "parser.tab.c"
    break;

  case 33: /* while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 270 "parser.y"
                                                     {
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start = cat(lbegin, ":\n", "", "", "");
        char *cond  = cat("    if (!(", (yyvsp[-4].rec)->code, ")) goto ", lend, ";");
        char *body  = (yyvsp[-1].rec)->code;
        char *back  = cat("    goto ", lbegin, ";", "", "");
        char *end   = cat(lend, ":", "", "", "");
        char *tmp   = cat(start, cond, "\n", body, "\n");
        tmp = cat(tmp, back, "\n", end, "");
        (yyval.rec) = createRecord(tmp, ""); free(tmp); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1501 "parser.tab.c"
    break;

  case 34: /* type: INT  */
#line 285 "parser.y"
             { (yyval.rec) = createRecord("int", "Int"); }
#line 1507 "parser.tab.c"
    break;

  case 35: /* type: FLOAT  */
#line 286 "parser.y"
             { (yyval.rec) = createRecord("float", "Float"); }
#line 1513 "parser.tab.c"
    break;

  case 36: /* type: UNIT  */
#line 287 "parser.y"
             { (yyval.rec) = createRecord("void", "Unit"); }
#line 1519 "parser.tab.c"
    break;

  case 37: /* type: RATIONAL  */
#line 288 "parser.y"
             { (yyval.rec) = createRecord("rational_t", "Rational"); }
#line 1525 "parser.tab.c"
    break;

  case 38: /* type: MATRIX  */
#line 289 "parser.y"
             { (yyval.rec) = createRecord("matrix_t*", "Matrix"); }
#line 1531 "parser.tab.c"
    break;

  case 39: /* type: BST  */
#line 290 "parser.y"
             { (yyval.rec) = createRecord("TreeNode*", "BST"); }
#line 1537 "parser.tab.c"
    break;

  case 40: /* expr: expr PLUS expr  */
#line 294 "parser.y"
                       { char *s=cat("(", (yyvsp[-2].rec)->code, " + ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(yyvsp[-2].rec)->opt1); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1543 "parser.tab.c"
    break;

  case 41: /* expr: expr MINUS expr  */
#line 295 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " - ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(yyvsp[-2].rec)->opt1); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1549 "parser.tab.c"
    break;

  case 42: /* expr: expr MUL expr  */
#line 296 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " * ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(yyvsp[-2].rec)->opt1); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1555 "parser.tab.c"
    break;

  case 43: /* expr: expr DIV expr  */
#line 297 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " / ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(yyvsp[-2].rec)->opt1); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1561 "parser.tab.c"
    break;

  case 44: /* expr: expr LT expr  */
#line 298 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " < ",  (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1567 "parser.tab.c"
    break;

  case 45: /* expr: expr LE expr  */
#line 299 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " <= ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1573 "parser.tab.c"
    break;

  case 46: /* expr: expr GT expr  */
#line 300 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " > ",  (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1579 "parser.tab.c"
    break;

  case 47: /* expr: expr GE expr  */
#line 301 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " >= ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1585 "parser.tab.c"
    break;

  case 48: /* expr: expr EQ expr  */
#line 302 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " == ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1591 "parser.tab.c"
    break;

  case 49: /* expr: expr NE expr  */
#line 303 "parser.y"
                      { char *s=cat("(", (yyvsp[-2].rec)->code, " != ", (yyvsp[0].rec)->code, ")"); (yyval.rec)=createRecord(s,(char*)"Int"); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1597 "parser.tab.c"
    break;

  case 50: /* expr: LPAREN expr RPAREN  */
#line 304 "parser.y"
                         { (yyval.rec) = (yyvsp[-1].rec); }
#line 1603 "parser.tab.c"
    break;

  case 51: /* expr: AMPERSAND ID  */
#line 305 "parser.y"
                   {
        char* addr_expr = cat("&", (yyvsp[0].str_val), "", "", "");
        const char* base_type = lookupSymbol((yyvsp[0].str_val));
        char* ptr_type_name = cat("ref", base_type, "", "", "");
        (yyval.rec) = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free((yyvsp[0].str_val));
    }
#line 1615 "parser.tab.c"
    break;

  case 52: /* expr: ID  */
#line 312 "parser.y"
                        { 
        const char *t = lookupSymbol((yyvsp[0].str_val)); 
        // Se o tipo começa com "ref", é um parâmetro por referência
        if (strncmp(t, "ref", 3) == 0) {
            char* deref_code = cat("*", (yyvsp[0].str_val), "", "", "");
            char* base_type = strdup(t + 3); // Remove "ref" do início
            (yyval.rec) = createRecord(deref_code, base_type);
            free(deref_code); free(base_type);
        } else {
            (yyval.rec) = createRecord((yyvsp[0].str_val), strdup(t));
        }
        free((yyvsp[0].str_val)); 
    }
#line 1633 "parser.tab.c"
    break;

  case 53: /* expr: INT_LIT  */
#line 325 "parser.y"
                        { char b[32]; sprintf(b,"%d",(yyvsp[0].int_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Int"); }
#line 1639 "parser.tab.c"
    break;

  case 54: /* expr: FLOAT_LIT  */
#line 326 "parser.y"
                        { char b[32]; sprintf(b,"%f",(yyvsp[0].float_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Float"); }
#line 1645 "parser.tab.c"
    break;

  case 55: /* expr: func_call  */
#line 327 "parser.y"
                        { (yyval.rec) = (yyvsp[0].rec); }
#line 1651 "parser.tab.c"
    break;

  case 56: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 331 "parser.y"
                                  {
        char *s = cat((yyvsp[-3].str_val), "(", (yyvsp[-1].rec)->code, ")", "");
        const char *type = "Unit"; // Tipo padrão para funções sem retorno (void)

        // Lógica para determinar o tipo de retorno das funções
        if (strcmp((yyvsp[-3].str_val), "create_rational") == 0 || strcmp((yyvsp[-3].str_val), "add") == 0 ||
            strcmp((yyvsp[-3].str_val), "subtract") == 0 || strcmp((yyvsp[-3].str_val), "multiply") == 0 ||
            strcmp((yyvsp[-3].str_val), "divide") == 0 || strcmp((yyvsp[-3].str_val), "negate") == 0 ||
            strcmp((yyvsp[-3].str_val), "inverse") == 0) {
            type = "Rational";
        } else if (strcmp((yyvsp[-3].str_val), "are_equal") == 0) {
            type = "Int";
        } else if (strcmp((yyvsp[-3].str_val), "create_matrix") == 0 || strcmp((yyvsp[-3].str_val), "add_matrices") == 0 ||
                   strcmp((yyvsp[-3].str_val), "multiply_matrices") == 0) {
            type = "Matrix";
        } else if (strcmp((yyvsp[-3].str_val), "create_bst_from_sequence") == 0) {
            type = "BST";
        } else if (strcmp((yyvsp[-3].str_val), "get_min_value") == 0 || strcmp((yyvsp[-3].str_val), "get_min_level") == 0 ||
                   strcmp((yyvsp[-3].str_val), "get_max_value") == 0 || strcmp((yyvsp[-3].str_val), "get_max_level") == 0) {
            type = "Int";
        }
        
        (yyval.rec) = createRecord(s, (char*)type);
        free(s); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 1681 "parser.tab.c"
    break;

  case 57: /* arg_list_opt: %empty  */
#line 359 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1687 "parser.tab.c"
    break;

  case 60: /* arg_list: arg_list COMMA expr  */
#line 365 "parser.y"
                          { char *s=cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", ""); (yyval.rec)=createRecord(s,""); free(s); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1693 "parser.tab.c"
    break;


#line 1697 "parser.tab.c"

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

#line 368 "parser.y"


// --- CÓDIGO AUXILIAR ---

void yyerror(const char *s) {
    fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
    exit(1); // Termina o programa com erro
}

// Concatena até 5 strings
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5) {
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + 1;
    char *o = malloc(len);
    if (!o) { fprintf(stderr, "Erro de malloc!\n"); exit(1); }
    sprintf(o, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    return o;
}

// Mapeia o tipo interno da linguagem para o tipo correspondente em C
const char* map_type(const char* o) {
    if (strcmp(o, "Int") == 0) return "int";
    if (strcmp(o, "Float") == 0) return "float";
    if (strcmp(o, "Unit") == 0) return "void";
    if (strcmp(o, "Rational") == 0) return "rational_t";
    if (strcmp(o, "Matrix") == 0) return "matrix_t*";
    if (strcmp(o, "BST") == 0) return "TreeNode*";
    return "void"; // Padrão
}

// Função principal que orquestra a compilação
int main(int argc, char **argv) {
    if (argc != 3) { fprintf(stderr, "Uso: %s <in> <out>\n", argv[0]); return 1; }
    yyin = fopen(argv[1], "r"); if (!yyin) { perror("fopen"); return 1; }
    yyout = fopen(argv[2], "w"); if (!yyout) { perror("fopen"); fclose(yyin); return 1; }
    
    initSymbolTable();
    yyparse();
    freeSymbolTable();
    
    fclose(yyin);
    fclose(yyout);
    
    return 0;
}
