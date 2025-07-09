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

// Protótipos
int yylex(void);
void yyerror(const char *s);
char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5);
const char* map_type(const char* o);

// Variáveis externas
extern int yylineno;
extern char *yytext;
extern FILE *yyin, *yyout;

// Variáveis Globais para o Parser
static int label_count = 0;
static char* current_struct_name = NULL; // Guarda o nome da struct sendo definida

char *new_label() {
    char buf[32];
    sprintf(buf, "L%d", label_count++);
    return strdup(buf);
}

char* deref_if_needed(struct record* rec) {
    if (rec && rec->opt1 && strncmp(rec->opt1, "ref", 3) == 0) {
        return cat("*", rec->code, "", "", "");
    }
    return strdup(rec->code);
}


#line 109 "parser.tab.c"

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
  YYSYMBOL_PRINT_INLINE = 10,              /* PRINT_INLINE  */
  YYSYMBOL_PRINT_STRING = 11,              /* PRINT_STRING  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_STRUCT = 15,                    /* STRUCT  */
  YYSYMBOL_NEW = 16,                       /* NEW  */
  YYSYMBOL_NULL_LIT = 17,                  /* NULL_LIT  */
  YYSYMBOL_DOT = 18,                       /* DOT  */
  YYSYMBOL_REF = 19,                       /* REF  */
  YYSYMBOL_AMPERSAND = 20,                 /* AMPERSAND  */
  YYSYMBOL_ARROW_LEFT = 21,                /* ARROW_LEFT  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_GE = 29,                        /* GE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 33,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 34,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 35,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 36,                    /* RBRACE  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_INT_LIT = 39,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 40,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 41,                /* STRING_LIT  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_decl_list = 44,                 /* decl_list  */
  YYSYMBOL_struct_decl = 45,               /* struct_decl  */
  YYSYMBOL_field_list = 46,                /* field_list  */
  YYSYMBOL_field = 47,                     /* field  */
  YYSYMBOL_func_decl = 48,                 /* func_decl  */
  YYSYMBOL_param_list_opt = 49,            /* param_list_opt  */
  YYSYMBOL_param_list = 50,                /* param_list  */
  YYSYMBOL_param = 51,                     /* param  */
  YYSYMBOL_stmt_list = 52,                 /* stmt_list  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_var_decl_stmt = 54,             /* var_decl_stmt  */
  YYSYMBOL_assignment_stmt = 55,           /* assignment_stmt  */
  YYSYMBOL_func_call_stmt = 56,            /* func_call_stmt  */
  YYSYMBOL_print_stmt = 57,                /* print_stmt  */
  YYSYMBOL_print_inline_stmt = 58,         /* print_inline_stmt  */
  YYSYMBOL_print_string_stmt = 59,         /* print_string_stmt  */
  YYSYMBOL_return_stmt = 60,               /* return_stmt  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 62,                /* while_stmt  */
  YYSYMBOL_type = 63,                      /* type  */
  YYSYMBOL_lvalue = 64,                    /* lvalue  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_func_call = 66,                 /* func_call  */
  YYSYMBOL_arg_list_opt = 67,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 68                   /* arg_list  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    88,    89,    90,    95,   105,   117,   118,
     126,   143,   150,   160,   161,   165,   166,   174,   180,   193,
     194,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     214,   220,   231,   245,   252,   267,   276,   288,   293,   299,
     311,   329,   330,   331,   332,   333,   334,   335,   343,   348,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   376,   379,   380,   381,   388,   389,   390,   394,   409,
     410,   414,   415
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
  "RATIONAL", "MATRIX", "BST", "PRINT", "PRINT_INLINE", "PRINT_STRING",
  "RETURN", "IF", "WHILE", "STRUCT", "NEW", "NULL_LIT", "DOT", "REF",
  "AMPERSAND", "ARROW_LEFT", "PLUS", "MINUS", "MUL", "DIV", "LT", "LE",
  "GT", "GE", "EQ", "NE", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "COMMA", "ID", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "$accept",
  "program", "decl_list", "struct_decl", "field_list", "field",
  "func_decl", "param_list_opt", "param_list", "param", "stmt_list",
  "stmt", "var_decl_stmt", "assignment_stmt", "func_call_stmt",
  "print_stmt", "print_inline_stmt", "print_string_stmt", "return_stmt",
  "if_stmt", "while_stmt", "type", "lvalue", "expr", "func_call",
  "arg_list_opt", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,  -124,  -124,  -124,  -124,  -124,  -124,   -18,  -124,    25,
      23,  -124,  -124,    -5,    -1,  -124,  -124,  -124,     9,   122,
      80,   116,  -124,     5,   122,    10,    26,  -124,    24,  -124,
    -124,    46,    41,   -13,    80,  -124,  -124,  -124,  -124,  -124,
    -124,     3,   156,   156,    40,   146,    56,    61,  -124,   -15,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      57,    59,    64,    75,  -124,    76,   156,    82,  -124,  -124,
      79,   214,  -124,   225,    84,  -124,   236,   156,   156,   156,
       0,    93,   156,  -124,  -124,  -124,   175,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,  -124,  -124,  -124,
    -124,   188,   201,   269,    83,    95,   156,  -124,  -124,   247,
    -124,   114,   114,    29,    29,  -124,  -124,  -124,  -124,  -124,
    -124,   100,   111,  -124,   156,   258,  -124,  -124,  -124,   269,
    -124,    62,    98,  -124,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    43,    42,    41,    44,    45,    46,     0,    47,     0,
       2,     4,     3,     0,     0,     1,     6,     5,     0,     0,
      13,     0,     8,     0,     0,     0,    14,    15,     0,     7,
       9,     0,     0,     0,     0,    17,    10,    18,    12,    19,
      16,     0,     0,     0,     0,     0,     0,     0,    11,    48,
      20,    21,    22,    27,    23,    24,    25,    26,    28,    29,
       0,     0,     0,     0,    61,     0,     0,    48,    65,    66,
      62,     0,    67,     0,     0,    38,     0,     0,     0,    69,
       0,     0,     0,    33,    60,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
      37,     0,     0,    71,     0,    70,     0,    30,    49,     0,
      63,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    68,     0,     0,    32,    19,    19,    72,
      31,     0,     0,    39,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   123,  -124,   127,   139,  -124,  -124,   117,
    -123,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,   137,   -41,   -42,   -39,  -124,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    21,    22,    12,    25,    26,    27,
      41,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    70,    71,    72,   104,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    73,    62,    76,   131,   132,     1,     2,     3,     4,
       5,     6,    42,    43,    44,    45,    46,    47,    79,    38,
      14,   106,    39,   -47,    86,    15,     1,     2,     3,     4,
       5,     6,   107,    18,    19,   101,   102,   103,     7,    48,
     109,    49,    20,    31,    33,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    91,    92,    93,    94,    95,
      96,     8,    35,    34,   125,     1,     2,     3,     4,     5,
       6,    42,    43,    44,    45,    46,    47,    81,    36,    37,
      82,    74,   129,     1,     2,     3,     4,     5,     6,    77,
      61,    61,    62,    62,    78,    80,    83,    81,   133,    24,
      49,     1,     2,     3,     4,     5,     6,    42,    43,    44,
      45,    46,    47,    84,    85,    79,    99,   123,     8,     1,
       2,     3,     4,     5,     6,     1,     2,     3,     4,     5,
       6,   108,   124,    16,   134,   127,    49,    13,    89,    90,
      91,    92,    93,    94,    95,    96,   128,    13,    30,    17,
       0,    40,    29,     0,     8,     0,    23,    28,    23,     0,
       8,    32,    63,    64,     0,     0,    65,     0,     0,     0,
       0,    28,    63,    64,     0,     0,    65,     0,    75,    66,
       0,     0,     0,     0,    67,    68,    69,     0,     0,    66,
       0,     0,     0,     0,    67,    68,    69,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,   110,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,   121,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,   122,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    98,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   100,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   126,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     130,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96
};

static const yytype_int16 yycheck[] =
{
      41,    43,    41,    45,   127,   128,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    33,    32,
      38,    21,    35,    38,    66,     0,     3,     4,     5,     6,
       7,     8,    32,    38,    35,    77,    78,    79,    15,    36,
      82,    38,    33,    38,    34,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    26,    27,    28,    29,    30,
      31,    38,    38,    37,   106,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    18,    32,    38,
      21,    41,   124,     3,     4,     5,     6,     7,     8,    33,
     131,   132,   131,   132,    33,    38,    32,    18,    36,    19,
      38,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    38,    38,    33,    32,    34,    38,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    38,    37,    10,    36,    35,    38,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    35,    10,    21,    10,
      -1,    34,    36,    -1,    38,    -1,    19,    20,    21,    -1,
      38,    24,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    34,    16,    17,    -1,    -1,    20,    -1,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    15,    38,    43,
      44,    45,    48,    63,    38,     0,    45,    48,    38,    35,
      33,    46,    47,    63,    19,    49,    50,    51,    63,    36,
      47,    38,    63,    34,    37,    38,    32,    38,    32,    35,
      51,    52,     9,    10,    11,    12,    13,    14,    36,    38,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    16,    17,    20,    33,    38,    39,    40,
      64,    65,    66,    65,    41,    32,    65,    33,    33,    33,
      38,    18,    21,    32,    38,    38,    65,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    32,    32,
      32,    65,    65,    65,    67,    68,    21,    32,    38,    65,
      34,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    34,    34,    34,    37,    65,    32,    35,    35,    65,
      32,    52,    52,    36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    56,    57,    58,    59,    60,    60,    61,
      62,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     5,     1,     2,
       3,     8,     6,     0,     1,     1,     3,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     4,     2,     3,     3,     3,     3,     2,     7,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     3,     2,     1,     1,     1,     4,     0,
       1,     1,     3
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
#line 75 "parser.y"
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
#line 1297 "parser.tab.c"
    break;

  case 5: /* decl_list: decl_list func_decl  */
#line 90 "parser.y"
                          {
        char *s = cat((yyvsp[-1].rec)->code, "\n\n", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1307 "parser.tab.c"
    break;

  case 6: /* decl_list: decl_list struct_decl  */
#line 95 "parser.y"
                            {
        char *s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1317 "parser.tab.c"
    break;

  case 7: /* struct_decl: STRUCT ID LBRACE field_list RBRACE  */
#line 105 "parser.y"
                                       {
        current_struct_name = strdup((yyvsp[-3].str_val));
        char *typedef_def = cat("typedef struct ", (yyvsp[-3].str_val), " {\n", (yyvsp[-1].rec)->code, "} ");
        char *complete_def = cat(typedef_def, (yyvsp[-3].str_val), ";\n", "", "");
        (yyval.rec) = createRecord(complete_def, "");
        free(typedef_def); free(complete_def); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
        free(current_struct_name);
        current_struct_name = NULL;
    }
#line 1331 "parser.tab.c"
    break;

  case 9: /* field_list: field_list field  */
#line 118 "parser.y"
                       {
        char *s = cat((yyvsp[-1].rec)->code, (yyvsp[0].rec)->code, "", "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1341 "parser.tab.c"
    break;

  case 10: /* field: type ID SEMICOLON  */
#line 126 "parser.y"
                      {
        if (current_struct_name && (yyvsp[-2].rec)->opt1 && strcmp((yyvsp[-2].rec)->opt1, current_struct_name) == 0) {
            char* self_ptr_field = cat("    struct ", current_struct_name, "* ", (yyvsp[-1].str_val), ";\n");
            (yyval.rec) = createRecord(self_ptr_field, "");
            free(self_ptr_field);
        } else {
            char *s = cat("    ", (yyvsp[-2].rec)->code, " ", (yyvsp[-1].str_val), ";\n");
            (yyval.rec) = createRecord(s, "");
            free(s);
        }
        freeRecord((yyvsp[-2].rec)); free((yyvsp[-1].str_val));
    }
#line 1358 "parser.tab.c"
    break;

  case 11: /* func_decl: type ID LPAREN param_list_opt RPAREN LBRACE stmt_list RBRACE  */
#line 143 "parser.y"
                                                                 {
        const char *rt = strcmp((yyvsp[-6].str_val), "main")==0 ? "int" : (yyvsp[-7].rec)->code;
        char *h = cat(rt, " ", (yyvsp[-6].str_val), "(", (yyvsp[-4].rec)->code);
        char *b = cat(h, ") {\n", (yyvsp[-1].rec)->code, "}\n", "");
        (yyval.rec) = createRecord(b, ""); free(h); free(b);
        freeRecord((yyvsp[-7].rec)); free((yyvsp[-6].str_val)); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1370 "parser.tab.c"
    break;

  case 12: /* func_decl: type ID LPAREN param_list_opt RPAREN SEMICOLON  */
#line 150 "parser.y"
                                                   {
        const char *rt = (yyvsp[-5].rec)->code;
        char *h = cat(rt, " ", (yyvsp[-4].str_val), "(", (yyvsp[-2].rec)->code);
        char *p = cat(h, ");\n", "", "", "");
        (yyval.rec) = createRecord(p, ""); free(h); free(p);
        freeRecord((yyvsp[-5].rec)); free((yyvsp[-4].str_val)); freeRecord((yyvsp[-2].rec));
    }
#line 1382 "parser.tab.c"
    break;

  case 13: /* param_list_opt: %empty  */
#line 160 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1388 "parser.tab.c"
    break;

  case 16: /* param_list: param_list COMMA param  */
#line 166 "parser.y"
                             {
        char *s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1398 "parser.tab.c"
    break;

  case 17: /* param: type ID  */
#line 174 "parser.y"
            {
        char *s = cat((yyvsp[-1].rec)->code, " ", (yyvsp[0].str_val), "", "");
        (yyval.rec) = createRecord(s, (yyvsp[-1].rec)->opt1);
        insertSymbol((yyvsp[0].str_val), (yyvsp[-1].rec)->opt1);
        free(s); freeRecord((yyvsp[-1].rec)); free((yyvsp[0].str_val));
    }
#line 1409 "parser.tab.c"
    break;

  case 18: /* param: REF type ID  */
#line 180 "parser.y"
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
#line 1424 "parser.tab.c"
    break;

  case 19: /* stmt_list: %empty  */
#line 193 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1430 "parser.tab.c"
    break;

  case 20: /* stmt_list: stmt_list stmt  */
#line 194 "parser.y"
                     {
        char *s = cat((yyvsp[-1].rec)->code, (yyvsp[0].rec)->code, "\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1440 "parser.tab.c"
    break;

  case 30: /* var_decl_stmt: type ID SEMICOLON  */
#line 214 "parser.y"
                      {
        char *s = cat("    ", (yyvsp[-2].rec)->code, " ", (yyvsp[-1].str_val), ";");
        (yyval.rec) = createRecord(s, ""); free(s);
        insertSymbol((yyvsp[-1].str_val), (yyvsp[-2].rec)->opt1);
        freeRecord((yyvsp[-2].rec)); free((yyvsp[-1].str_val));
    }
#line 1451 "parser.tab.c"
    break;

  case 31: /* var_decl_stmt: type ID ARROW_LEFT expr SEMICOLON  */
#line 220 "parser.y"
                                      {
        char* val = deref_if_needed((yyvsp[-1].rec));
        char *p = cat("    ", (yyvsp[-4].rec)->code, " ", (yyvsp[-3].str_val), " = ");
        char *s = cat(p, val, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(p); free(s); free(val);
        insertSymbol((yyvsp[-3].str_val), (yyvsp[-4].rec)->opt1);
        freeRecord((yyvsp[-4].rec)); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 1464 "parser.tab.c"
    break;

  case 32: /* assignment_stmt: lvalue ARROW_LEFT expr SEMICOLON  */
#line 231 "parser.y"
                                     {
        char *s;
        char* val = deref_if_needed((yyvsp[-1].rec));
        if ((yyvsp[-3].rec)->opt1 && strncmp((yyvsp[-3].rec)->opt1, "ref", 3) == 0) {
            s = cat("    *", (yyvsp[-3].rec)->code, " = ", val, ";");
        } else {
            s = cat("    ", (yyvsp[-3].rec)->code, " = ", val, ";");
        }
        (yyval.rec) = createRecord(s, ""); free(s); free(val);
        freeRecord((yyvsp[-3].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1480 "parser.tab.c"
    break;

  case 33: /* func_call_stmt: func_call SEMICOLON  */
#line 245 "parser.y"
                        {
        char *s = cat("    ", (yyvsp[-1].rec)->code, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); freeRecord((yyvsp[-1].rec));
    }
#line 1489 "parser.tab.c"
    break;

  case 34: /* print_stmt: PRINT expr SEMICOLON  */
#line 252 "parser.y"
                         {
        char *s;
        char* val = deref_if_needed((yyvsp[-1].rec));
        if (strcmp((yyvsp[-1].rec)->opt1, "Float") == 0) {
            s = cat("    printf(\"%f\\n\", ", val, ");", "", "");
        } else if (strcmp((yyvsp[-1].rec)->opt1, "Int") == 0) {
            s = cat("    printf(\"%d\\n\", ", val, ");", "", "");
        } else {
            s = cat("    printf(\"unsupported_print_type\\n\");", "", "", "", "");
        }
        (yyval.rec) = createRecord(s, ""); free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1506 "parser.tab.c"
    break;

  case 35: /* print_inline_stmt: PRINT_INLINE expr SEMICOLON  */
#line 267 "parser.y"
                                {
        char* val = deref_if_needed((yyvsp[-1].rec));
        char* s = cat("    printf(\"%d \", ", val, ");", "", "");
        (yyval.rec) = createRecord(s, "");
        free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1517 "parser.tab.c"
    break;

  case 36: /* print_string_stmt: PRINT_STRING STRING_LIT SEMICOLON  */
#line 276 "parser.y"
                                      {
        char *str = (yyvsp[-1].str_val);
        int len = strlen(str);
        char *clean_str = malloc(len - 1);
        strncpy(clean_str, str + 1, len - 2);
        clean_str[len - 2] = '\0';
        char *s = cat("    printf(\"", clean_str, "\\n\");", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); free(clean_str); free((yyvsp[-1].str_val));
    }
#line 1531 "parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN expr SEMICOLON  */
#line 288 "parser.y"
                          {
        char* val = deref_if_needed((yyvsp[-1].rec));
        char *s = cat("    return ", val, ";", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1541 "parser.tab.c"
    break;

  case 38: /* return_stmt: RETURN SEMICOLON  */
#line 293 "parser.y"
                     {
        (yyval.rec) = createRecord("    return;", "");
    }
#line 1549 "parser.tab.c"
    break;

  case 39: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 299 "parser.y"
                                                  {
        char *val = deref_if_needed((yyvsp[-4].rec));
        char *lend = new_label();
        char *cond = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body = (yyvsp[-1].rec)->code;
        char *code = cat(cond, "\n", body, "\n", lend);
        code = cat(code, ":", "", "", "");
        (yyval.rec) = createRecord(code, ""); free(cond); free(lend); free(val); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1563 "parser.tab.c"
    break;

  case 40: /* while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 311 "parser.y"
                                                     {
        char *val = deref_if_needed((yyvsp[-4].rec));
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start = cat(lbegin, ":\n", "", "", "");
        char *cond  = cat("    if (!(", val, ")) goto ", lend, ";");
        char *body  = (yyvsp[-1].rec)->code;
        char *back  = cat("    goto ", lbegin, ";", "", "");
        char *end   = cat(lend, ":", "", "", "");
        char *tmp   = cat(start, cond, "\n", body, "\n");
        tmp = cat(tmp, back, "\n", end, "");
        (yyval.rec) = createRecord(tmp, ""); free(tmp); free(val); freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1581 "parser.tab.c"
    break;

  case 41: /* type: INT  */
#line 329 "parser.y"
             { (yyval.rec) = createRecord("int", "Int"); }
#line 1587 "parser.tab.c"
    break;

  case 42: /* type: FLOAT  */
#line 330 "parser.y"
             { (yyval.rec) = createRecord("float", "Float"); }
#line 1593 "parser.tab.c"
    break;

  case 43: /* type: UNIT  */
#line 331 "parser.y"
             { (yyval.rec) = createRecord("void", "Unit"); }
#line 1599 "parser.tab.c"
    break;

  case 44: /* type: RATIONAL  */
#line 332 "parser.y"
             { (yyval.rec) = createRecord("rational_t", "Rational"); }
#line 1605 "parser.tab.c"
    break;

  case 45: /* type: MATRIX  */
#line 333 "parser.y"
             { (yyval.rec) = createRecord("matrix_t*", "Matrix"); }
#line 1611 "parser.tab.c"
    break;

  case 46: /* type: BST  */
#line 334 "parser.y"
             { (yyval.rec) = createRecord("TreeNode*", "BST"); }
#line 1617 "parser.tab.c"
    break;

  case 47: /* type: ID  */
#line 335 "parser.y"
             { 
        char *ptr_type = cat((yyvsp[0].str_val), "*", "", "", "");
        (yyval.rec) = createRecord(ptr_type, (yyvsp[0].str_val)); 
        free(ptr_type); free((yyvsp[0].str_val));
    }
#line 1627 "parser.tab.c"
    break;

  case 48: /* lvalue: ID  */
#line 343 "parser.y"
       { 
        const char* type = lookupSymbol((yyvsp[0].str_val));
        (yyval.rec) = createRecord((yyvsp[0].str_val), strdup(type ? type : "Unknown"));
        free((yyvsp[0].str_val)); 
    }
#line 1637 "parser.tab.c"
    break;

  case 49: /* lvalue: lvalue DOT ID  */
#line 348 "parser.y"
                  {
        char* member_access = cat((yyvsp[-2].rec)->code, "->", (yyvsp[0].str_val), "", "");
        const char* field_type = "Int"; // Assume Int por padrão
        if (strcmp((yyvsp[0].str_val), "left") == 0 || strcmp((yyvsp[0].str_val), "right") == 0) {
            field_type = (yyvsp[-2].rec)->opt1;
        }
        (yyval.rec) = createRecord(member_access, strdup(field_type));
        free(member_access); free((yyvsp[0].str_val));
        freeRecord((yyvsp[-2].rec));
    }
#line 1652 "parser.tab.c"
    break;

  case 50: /* expr: expr PLUS expr  */
#line 361 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " + ", s3, ")"); (yyval.rec) = createRecord(s, (yyvsp[-2].rec)->opt1); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1658 "parser.tab.c"
    break;

  case 51: /* expr: expr MINUS expr  */
#line 362 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " - ", s3, ")"); (yyval.rec) = createRecord(s, (yyvsp[-2].rec)->opt1); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1664 "parser.tab.c"
    break;

  case 52: /* expr: expr MUL expr  */
#line 363 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " * ", s3, ")"); (yyval.rec) = createRecord(s, (yyvsp[-2].rec)->opt1); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1670 "parser.tab.c"
    break;

  case 53: /* expr: expr DIV expr  */
#line 364 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " / ", s3, ")"); (yyval.rec) = createRecord(s, (yyvsp[-2].rec)->opt1); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1676 "parser.tab.c"
    break;

  case 54: /* expr: expr LT expr  */
#line 365 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " < ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1682 "parser.tab.c"
    break;

  case 55: /* expr: expr LE expr  */
#line 366 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " <= ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1688 "parser.tab.c"
    break;

  case 56: /* expr: expr GT expr  */
#line 367 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " > ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1694 "parser.tab.c"
    break;

  case 57: /* expr: expr GE expr  */
#line 368 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " >= ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1700 "parser.tab.c"
    break;

  case 58: /* expr: expr EQ expr  */
#line 369 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " == ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1706 "parser.tab.c"
    break;

  case 59: /* expr: expr NE expr  */
#line 370 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " != ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 1712 "parser.tab.c"
    break;

  case 60: /* expr: NEW ID  */
#line 371 "parser.y"
             {
        char* malloc_call = cat("malloc(sizeof(struct ", (yyvsp[0].str_val), "))", "", "");
        (yyval.rec) = createRecord(malloc_call, (yyvsp[0].str_val));
        free(malloc_call); free((yyvsp[0].str_val));
    }
#line 1722 "parser.tab.c"
    break;

  case 61: /* expr: NULL_LIT  */
#line 376 "parser.y"
               {
        (yyval.rec) = createRecord("NULL", "null");
    }
#line 1730 "parser.tab.c"
    break;

  case 62: /* expr: lvalue  */
#line 379 "parser.y"
             { (yyval.rec) = (yyvsp[0].rec); }
#line 1736 "parser.tab.c"
    break;

  case 63: /* expr: LPAREN expr RPAREN  */
#line 380 "parser.y"
                         { (yyval.rec) = (yyvsp[-1].rec); }
#line 1742 "parser.tab.c"
    break;

  case 64: /* expr: AMPERSAND ID  */
#line 381 "parser.y"
                   {
        char* addr_expr = cat("&", (yyvsp[0].str_val), "", "", "");
        const char* base_type = lookupSymbol((yyvsp[0].str_val));
        char* ptr_type_name = cat("ref", base_type, "", "", "");
        (yyval.rec) = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free((yyvsp[0].str_val));
    }
#line 1754 "parser.tab.c"
    break;

  case 65: /* expr: INT_LIT  */
#line 388 "parser.y"
                       { char b[32]; sprintf(b,"%d",(yyvsp[0].int_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Int"); }
#line 1760 "parser.tab.c"
    break;

  case 66: /* expr: FLOAT_LIT  */
#line 389 "parser.y"
                       { char b[32]; sprintf(b,"%f",(yyvsp[0].float_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Float"); }
#line 1766 "parser.tab.c"
    break;

  case 67: /* expr: func_call  */
#line 390 "parser.y"
                       { (yyval.rec) = (yyvsp[0].rec); }
#line 1772 "parser.tab.c"
    break;

  case 68: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 394 "parser.y"
                                  {
        char *s = cat((yyvsp[-3].str_val), "(", (yyvsp[-1].rec)->code, ")", "");
        const char *type = "Unit"; 
        if (strcmp((yyvsp[-3].str_val), "get_height") == 0 || strcmp((yyvsp[-3].str_val), "max") == 0) {
            type = "Int";
        } else if (strcmp((yyvsp[-3].str_val), "insert") == 0) {
            type = "TreeNode";
        }
        // Adicione aqui outras funções com retorno para compatibilidade
        (yyval.rec) = createRecord(s, (char*)type);
        free(s); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 1789 "parser.tab.c"
    break;

  case 69: /* arg_list_opt: %empty  */
#line 409 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1795 "parser.tab.c"
    break;

  case 72: /* arg_list: arg_list COMMA expr  */
#line 415 "parser.y"
                          { 
        char *s=cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", ""); 
        (yyval.rec)=createRecord(s,""); 
        free(s); 
        freeRecord((yyvsp[-2].rec)); 
        freeRecord((yyvsp[0].rec)); 
    }
#line 1807 "parser.tab.c"
    break;


#line 1811 "parser.tab.c"

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

#line 424 "parser.y"


// --- CÓDIGO AUXILIAR ---

void yyerror(const char *s) {
    fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
}

char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5) {
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + 1;
    char *o = malloc(len);
    if (!o) { fprintf(stderr, "Erro de malloc!\n"); exit(1); }
    sprintf(o, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    return o;
}

const char* map_type(const char* o) {
    if (strcmp(o, "Int") == 0) return "int";
    if (strcmp(o, "Float") == 0) return "float";
    if (strcmp(o, "Unit") == 0) return "void";
    if (strcmp(o, "Rational") == 0) return "rational_t";
    if (strcmp(o, "Matrix") == 0) return "matrix_t*";
    if (strcmp(o, "BST") == 0) return "TreeNode*";
    return "void";
}

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
