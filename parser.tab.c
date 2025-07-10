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
static char* current_struct_name = NULL;

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
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_STRUCT = 16,                    /* STRUCT  */
  YYSYMBOL_NEW = 17,                       /* NEW  */
  YYSYMBOL_NULL_LIT = 18,                  /* NULL_LIT  */
  YYSYMBOL_DOT = 19,                       /* DOT  */
  YYSYMBOL_REF = 20,                       /* REF  */
  YYSYMBOL_AMPERSAND = 21,                 /* AMPERSAND  */
  YYSYMBOL_ARROW_LEFT = 22,                /* ARROW_LEFT  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MUL = 25,                       /* MUL  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 36,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_INT_LIT = 40,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 41,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 42,                /* STRING_LIT  */
  YYSYMBOL_IF_NO_ELSE = 43,                /* IF_NO_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_decl_list = 46,                 /* decl_list  */
  YYSYMBOL_struct_decl = 47,               /* struct_decl  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_field_list = 49,                /* field_list  */
  YYSYMBOL_field = 50,                     /* field  */
  YYSYMBOL_func_decl = 51,                 /* func_decl  */
  YYSYMBOL_param_list_opt = 52,            /* param_list_opt  */
  YYSYMBOL_param_list = 53,                /* param_list  */
  YYSYMBOL_param = 54,                     /* param  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_block_content = 57,             /* block_content  */
  YYSYMBOL_stmt_list_non_empty = 58,       /* stmt_list_non_empty  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_var_decl_stmt = 60,             /* var_decl_stmt  */
  YYSYMBOL_assignment_stmt = 61,           /* assignment_stmt  */
  YYSYMBOL_func_call_stmt = 62,            /* func_call_stmt  */
  YYSYMBOL_print_stmt = 63,                /* print_stmt  */
  YYSYMBOL_print_inline_stmt = 64,         /* print_inline_stmt  */
  YYSYMBOL_print_string_stmt = 65,         /* print_string_stmt  */
  YYSYMBOL_return_stmt = 66,               /* return_stmt  */
  YYSYMBOL_if_stmt = 67,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 68,                /* while_stmt  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_lvalue = 70,                    /* lvalue  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_func_call = 72,                 /* func_call  */
  YYSYMBOL_arg_list_opt = 73,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 74                   /* arg_list  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    96,    97,    98,   103,   113,   113,   125,
     126,   134,   149,   156,   166,   167,   171,   172,   180,   186,
     199,   199,   209,   210,   214,   215,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   237,   244,   253,   257,
     265,   269,   276,   287,   296,   308,   313,   319,   334,   359,
     383,   384,   385,   386,   387,   388,   389,   405,   410,   423,
     428,   438,   448,   458,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   484,   485,   486,   490,   501,   502,
     506,   507
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "UNIT", "FLOAT", "INT",
  "RATIONAL", "MATRIX", "BST", "PRINT", "PRINT_INLINE", "PRINT_STRING",
  "RETURN", "IF", "ELSE", "WHILE", "STRUCT", "NEW", "NULL_LIT", "DOT",
  "REF", "AMPERSAND", "ARROW_LEFT", "PLUS", "MINUS", "MUL", "DIV", "LT",
  "LE", "GT", "GE", "EQ", "NE", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "COMMA", "ID", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "IF_NO_ELSE", "$accept", "program", "decl_list", "struct_decl", "$@1",
  "field_list", "field", "func_decl", "param_list_opt", "param_list",
  "param", "block", "$@2", "block_content", "stmt_list_non_empty", "stmt",
  "var_decl_stmt", "assignment_stmt", "func_call_stmt", "print_stmt",
  "print_inline_stmt", "print_string_stmt", "return_stmt", "if_stmt",
  "while_stmt", "type", "lvalue", "expr", "func_call", "arg_list_opt",
  "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -46,   -46,   -46,   -46,   -46,   -46,   -33,   -46,     8,
       7,   -46,   -46,   -14,   -46,   -46,   -46,   -46,    -7,     0,
      25,    85,    85,    12,    10,   -46,    22,    66,   -46,    27,
      28,    29,    25,   -46,    51,   -46,    52,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   107,   127,   127,    33,   117,    61,
      62,   -30,   -46,    49,   107,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,    63,    75,    67,    65,   -46,
      68,   127,    72,   -46,   -46,    82,   185,   -46,   196,    88,
     -46,   207,   127,   127,   127,   -46,   -46,   -17,    69,     1,
     -46,   -46,   -46,   146,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   -46,   -46,   -46,   -46,   159,   172,
     240,    93,    91,    42,   -46,   -46,   -46,   218,   -46,    -5,
      -5,   -46,   -46,    54,    54,    54,    54,    54,    54,    87,
      87,   -46,   127,   -46,   229,   -46,   116,   -46,   240,   -46,
      87,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    52,    51,    50,    53,    54,    55,     0,    56,     0,
       2,     4,     3,     0,     7,     1,     6,     5,     0,     0,
      14,     0,     0,     0,    15,    16,     0,     0,     9,     0,
       0,     0,     0,    18,     0,    10,     0,    19,    13,    20,
      12,    17,     8,    11,    22,     0,     0,     0,     0,     0,
       0,    57,    35,     0,    23,    24,    26,    27,    32,    28,
      29,    30,    31,    33,    34,     0,     0,     0,     0,    70,
       0,     0,    57,    74,    75,    71,     0,    76,     0,     0,
      46,     0,     0,     0,    78,    21,    25,     0,     0,     0,
      41,    59,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,     0,     0,
      80,     0,    79,     0,    36,    58,    40,     0,    72,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,    77,     0,    38,     0,    39,    47,    49,    81,    37,
       0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   121,   -46,   -46,   106,   126,   -46,   -46,
     108,   -31,   -46,   -46,   -46,    98,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   105,   -37,   -45,   -20,   -46,
     -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    19,    27,    28,    12,    23,    24,
      25,    52,    44,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    13,    75,    76,    77,   111,
     112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    78,   116,    81,    84,   113,    14,    66,    15,   -56,
       1,     2,     3,     4,     5,     6,   114,    66,    68,    69,
      96,    97,    70,     7,    67,    18,    93,    20,     1,     2,
       3,     4,     5,     6,    67,    71,    21,   108,   109,   110,
      72,    73,    74,   133,   117,    22,     8,    31,    32,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    68,
      69,    33,    38,    70,     8,    39,    36,    37,   134,     1,
       2,     3,     4,     5,     6,    79,    71,    94,    95,    96,
      97,    72,    73,    74,    42,    43,    85,   138,     1,     2,
       3,     4,     5,     6,    88,    82,    83,    89,   136,   137,
      90,    88,    87,    34,    91,     8,    84,    92,   115,   141,
       1,     2,     3,     4,     5,     6,    45,    46,    47,    48,
      49,   106,    50,    39,     8,    26,    29,    30,   131,   132,
     140,    16,    29,    35,    68,    69,    17,    26,    70,     0,
      41,     0,     0,    39,    68,    69,    51,     0,    70,    65,
      80,    71,    86,     0,     0,     0,    72,    73,    74,    65,
       0,    71,     0,     0,     0,     0,    72,    73,    74,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,   118,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,   129,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   130,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     107,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   135,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   139,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      31,    46,     1,    48,    34,    22,    39,    44,     0,    39,
       3,     4,     5,     6,     7,     8,    33,    54,    17,    18,
      25,    26,    21,    16,    44,    39,    71,    34,     3,     4,
       5,     6,     7,     8,    54,    34,    36,    82,    83,    84,
      39,    40,    41,     1,    89,    20,    39,    35,    38,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    17,
      18,    39,    33,    21,    39,    36,    39,    39,   113,     3,
       4,     5,     6,     7,     8,    42,    34,    23,    24,    25,
      26,    39,    40,    41,    33,    33,    37,   132,     3,     4,
       5,     6,     7,     8,    19,    34,    34,    22,   129,   130,
      33,    19,    39,    37,    39,    39,    34,    39,    39,   140,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    33,    15,    36,    39,    20,    21,    22,    35,    38,
      14,    10,    27,    27,    17,    18,    10,    32,    21,    -1,
      32,    -1,    -1,    36,    17,    18,    39,    -1,    21,    44,
      33,    34,    54,    -1,    -1,    -1,    39,    40,    41,    54,
      -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    35,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    35,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    35,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    16,    39,    45,
      46,    47,    51,    69,    39,     0,    47,    51,    39,    48,
      34,    36,    20,    52,    53,    54,    69,    49,    50,    69,
      69,    35,    38,    39,    37,    50,    39,    39,    33,    36,
      55,    54,    33,    33,    56,     9,    10,    11,    12,    13,
      15,    39,    55,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    72,    17,    18,
      21,    34,    39,    40,    41,    70,    71,    72,    71,    42,
      33,    71,    34,    34,    34,    37,    59,    39,    19,    22,
      33,    39,    39,    71,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    33,    33,    33,    71,    71,
      71,    73,    74,    22,    33,    39,     1,    71,    35,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    35,
      35,    35,    38,     1,    71,    33,    55,    55,    71,    33,
      14,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    48,    47,    49,
      49,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      56,    55,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    73,    73,
      74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     0,     7,     1,
       2,     3,     6,     6,     0,     1,     1,     3,     2,     3,
       0,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     4,     4,
       3,     2,     3,     3,     3,     3,     2,     5,     7,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     2,     1,     1,     1,     4,     0,     1,
       1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
#line 83 "parser.y"
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
#line 1576 "parser.tab.c"
    break;

  case 5: /* decl_list: decl_list func_decl  */
#line 98 "parser.y"
                          {
        char *s = cat((yyvsp[-1].rec)->code, "\n\n", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1586 "parser.tab.c"
    break;

  case 6: /* decl_list: decl_list struct_decl  */
#line 103 "parser.y"
                            {
        char *s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1596 "parser.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 113 "parser.y"
              { current_struct_name = strdup((yyvsp[0].str_val)); insertSymbol((yyvsp[0].str_val), (yyvsp[0].str_val)); }
#line 1602 "parser.tab.c"
    break;

  case 8: /* struct_decl: STRUCT ID $@1 LBRACE field_list RBRACE SEMICOLON  */
#line 113 "parser.y"
                                                                                                             {
        char *typedef_def = cat("typedef struct ", (yyvsp[-5].str_val), " {\n", (yyvsp[-2].rec)->code, "} ");
        char *complete_def = cat(typedef_def, (yyvsp[-5].str_val), ";\n", "", "");
        (yyval.rec) = createRecord(complete_def, "");
        free(typedef_def); free(complete_def);
        freeRecord((yyvsp[-2].rec));
        free(current_struct_name); current_struct_name = NULL;
        free((yyvsp[-5].str_val));
    }
#line 1616 "parser.tab.c"
    break;

  case 10: /* field_list: field_list field  */
#line 126 "parser.y"
                       {
        char *s = cat((yyvsp[-1].rec)->code, (yyvsp[0].rec)->code, "", "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1626 "parser.tab.c"
    break;

  case 11: /* field: type ID SEMICOLON  */
#line 134 "parser.y"
                      {
        if (current_struct_name && (yyvsp[-2].rec)->opt1 && strcmp((yyvsp[-2].rec)->opt1, current_struct_name) == 0) {
            char* self_ptr_field = cat("    struct ", current_struct_name, "* ", (yyvsp[-1].str_val), ";\n");
            (yyval.rec) = createRecord(self_ptr_field, ""); free(self_ptr_field);
        } else {
            char *s = cat("    ", (yyvsp[-2].rec)->code, " ", (yyvsp[-1].str_val), ";\n");
            (yyval.rec) = createRecord(s, ""); free(s);
        }
        freeRecord((yyvsp[-2].rec)); free((yyvsp[-1].str_val));
    }
#line 1641 "parser.tab.c"
    break;

  case 12: /* func_decl: type ID LPAREN param_list_opt RPAREN block  */
#line 149 "parser.y"
                                               {
        const char *rt = strcmp((yyvsp[-4].str_val), "main")==0 ? "int" : (yyvsp[-5].rec)->code;
        char *h = cat(rt, " ", (yyvsp[-4].str_val), "(", (yyvsp[-2].rec)->code);
        char *b = cat(h, ") ", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(b, ""); free(h); free(b);
        freeRecord((yyvsp[-5].rec)); free((yyvsp[-4].str_val)); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1653 "parser.tab.c"
    break;

  case 13: /* func_decl: type ID LPAREN param_list_opt RPAREN SEMICOLON  */
#line 156 "parser.y"
                                                     {
        const char *rt = (yyvsp[-5].rec)->code;
        char *h = cat(rt, " ", (yyvsp[-4].str_val), "(", (yyvsp[-2].rec)->code);
        char *p = cat(h, ");\n", "", "", "");
        (yyval.rec) = createRecord(p, ""); free(h); free(p);
        freeRecord((yyvsp[-5].rec)); free((yyvsp[-4].str_val)); freeRecord((yyvsp[-2].rec));
    }
#line 1665 "parser.tab.c"
    break;

  case 14: /* param_list_opt: %empty  */
#line 166 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 1671 "parser.tab.c"
    break;

  case 17: /* param_list: param_list COMMA param  */
#line 172 "parser.y"
                             {
        char *s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "");
        (yyval.rec) = createRecord(s, ""); free(s);
        freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1681 "parser.tab.c"
    break;

  case 18: /* param: type ID  */
#line 180 "parser.y"
            {
        char *s = cat((yyvsp[-1].rec)->code, " ", (yyvsp[0].str_val), "", "");
        (yyval.rec) = createRecord(s, (yyvsp[-1].rec)->opt1);
        insertSymbol((yyvsp[0].str_val), (yyvsp[-1].rec)->opt1);
        free(s); freeRecord((yyvsp[-1].rec)); free((yyvsp[0].str_val));
    }
#line 1692 "parser.tab.c"
    break;

  case 19: /* param: REF type ID  */
#line 186 "parser.y"
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
#line 1707 "parser.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 199 "parser.y"
           { pushScope(); }
#line 1713 "parser.tab.c"
    break;

  case 21: /* block: LBRACE $@2 block_content RBRACE  */
#line 199 "parser.y"
                                                 {
        char* body = cat("{\n", (yyvsp[-1].rec)->code, "}\n", "", "");
        (yyval.rec) = createRecord(body, "");
        free(body);
        popScope();
        freeRecord((yyvsp[-1].rec));
    }
#line 1725 "parser.tab.c"
    break;

  case 22: /* block_content: %empty  */
#line 209 "parser.y"
                { (yyval.rec) = createRecord("", ""); }
#line 1731 "parser.tab.c"
    break;

  case 25: /* stmt_list_non_empty: stmt_list_non_empty stmt  */
#line 215 "parser.y"
                               {
        char *s = cat((yyvsp[-1].rec)->code, (yyvsp[0].rec)->code, "", "", "");
        (yyval.rec) = createRecord(s, "");
        free(s);
        freeRecord((yyvsp[-1].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1742 "parser.tab.c"
    break;

  case 36: /* var_decl_stmt: type ID SEMICOLON  */
#line 237 "parser.y"
                      {
        if (getCurrentScope() > 0) { checkDuplicateVariable((yyvsp[-1].str_val)); }
        char *s = cat("    ", (yyvsp[-2].rec)->code, " ", (yyvsp[-1].str_val), ";\n");
        (yyval.rec) = createRecord(s, ""); free(s);
        insertSymbol((yyvsp[-1].str_val), (yyvsp[-2].rec)->opt1);
        freeRecord((yyvsp[-2].rec)); free((yyvsp[-1].str_val));
    }
#line 1754 "parser.tab.c"
    break;

  case 37: /* var_decl_stmt: type ID ARROW_LEFT expr SEMICOLON  */
#line 244 "parser.y"
                                        {
        if (getCurrentScope() > 0) { checkDuplicateVariable((yyvsp[-3].str_val)); }
        char* val = deref_if_needed((yyvsp[-1].rec));
        char *p = cat("    ", (yyvsp[-4].rec)->code, " ", (yyvsp[-3].str_val), " = ");
        char *s = cat(p, val, ";\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(p); free(s); free(val);
        insertSymbol((yyvsp[-3].str_val), (yyvsp[-4].rec)->opt1);
        freeRecord((yyvsp[-4].rec)); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 1768 "parser.tab.c"
    break;

  case 38: /* var_decl_stmt: type ID ARROW_LEFT error  */
#line 253 "parser.y"
                               { yyerror("';' esperado após expressão"); YYABORT; }
#line 1774 "parser.tab.c"
    break;

  case 39: /* assignment_stmt: lvalue ARROW_LEFT expr SEMICOLON  */
#line 257 "parser.y"
                                     {
        char *s;
        char* val = deref_if_needed((yyvsp[-1].rec));
        if ((yyvsp[-3].rec)->opt1 && strncmp((yyvsp[-3].rec)->opt1, "ref", 3) == 0) { s = cat("    *", (yyvsp[-3].rec)->code, " = ", val, ";\n"); }
        else { s = cat("    ", (yyvsp[-3].rec)->code, " = ", val, ";\n"); }
        (yyval.rec) = createRecord(s, ""); free(s); free(val);
        freeRecord((yyvsp[-3].rec)); freeRecord((yyvsp[-1].rec));
    }
#line 1787 "parser.tab.c"
    break;

  case 40: /* assignment_stmt: lvalue ARROW_LEFT error  */
#line 265 "parser.y"
                              { yyerror("';' esperado após expressão"); YYABORT; }
#line 1793 "parser.tab.c"
    break;

  case 41: /* func_call_stmt: func_call SEMICOLON  */
#line 269 "parser.y"
                        {
        char *s = cat("    ", (yyvsp[-1].rec)->code, ";\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); freeRecord((yyvsp[-1].rec));
    }
#line 1802 "parser.tab.c"
    break;

  case 42: /* print_stmt: PRINT expr SEMICOLON  */
#line 276 "parser.y"
                         {
        char *s;
        char* val = deref_if_needed((yyvsp[-1].rec));
        if (strcmp((yyvsp[-1].rec)->opt1, "Float") == 0) { s = cat("    printf(\"%f\\n\", ", val, ");\n", "", ""); }
        else if (strcmp((yyvsp[-1].rec)->opt1, "Int") == 0) { s = cat("    printf(\"%d\\n\", ", val, ");\n", "", ""); }
        else { s = cat("    printf(\"unsupported_print_type\\n\");", "", "", "", ""); }
        (yyval.rec) = createRecord(s, ""); free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1815 "parser.tab.c"
    break;

  case 43: /* print_inline_stmt: PRINT_INLINE expr SEMICOLON  */
#line 287 "parser.y"
                                {
        char* val = deref_if_needed((yyvsp[-1].rec));
        char* s = cat("    printf(\"%d \", ", val, ");\n", "", "");
        (yyval.rec) = createRecord(s, "");
        free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1826 "parser.tab.c"
    break;

  case 44: /* print_string_stmt: PRINT_STRING STRING_LIT SEMICOLON  */
#line 296 "parser.y"
                                      {
        char *str = (yyvsp[-1].str_val);
        int len = strlen(str);
        char *clean_str = malloc(len - 1);
        strncpy(clean_str, str + 1, len - 2);
        clean_str[len - 2] = '\0';
        char *s = cat("    printf(\"", clean_str, "\\n\");\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); free(clean_str); free((yyvsp[-1].str_val));
    }
#line 1840 "parser.tab.c"
    break;

  case 45: /* return_stmt: RETURN expr SEMICOLON  */
#line 308 "parser.y"
                          {
        char* val = deref_if_needed((yyvsp[-1].rec));
        char *s = cat("    return ", val, ";\n", "", "");
        (yyval.rec) = createRecord(s, ""); free(s); free(val); freeRecord((yyvsp[-1].rec));
    }
#line 1850 "parser.tab.c"
    break;

  case 46: /* return_stmt: RETURN SEMICOLON  */
#line 313 "parser.y"
                       {
        (yyval.rec) = createRecord("    return;\n", "");
    }
#line 1858 "parser.tab.c"
    break;

  case 47: /* if_stmt: IF LPAREN expr RPAREN block  */
#line 319 "parser.y"
                                                 {
        char *val = deref_if_needed((yyvsp[-2].rec));
        char *lend = new_label();
        char *cond_code = cat("    if (!(", val, ")) goto ", lend, ";\n");
        char *body_code = (yyvsp[0].rec)->code;
        
        // Correção: Adicionado "" para completar os 5 argumentos
        char* part1 = cat(cond_code, body_code, "\n", "", "");
        char* final_code = cat(part1, lend, ":;\n", "", "");

        (yyval.rec) = createRecord(final_code, "");
        
        free(val); free(lend); free(cond_code); free(part1); free(final_code);
        freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1878 "parser.tab.c"
    break;

  case 48: /* if_stmt: IF LPAREN expr RPAREN block ELSE block  */
#line 334 "parser.y"
                                             {
        char *val = deref_if_needed((yyvsp[-4].rec));
        char *lelse = new_label();
        char *lend = new_label();
        char *if_body = (yyvsp[-2].rec)->code;
        char *else_body = (yyvsp[0].rec)->code;

        // Correção: Todas as chamadas a 'cat' agora têm 5 argumentos
        char *p1 = cat("    if (!(", val, ")) goto ", lelse, ";\n");
        char *p2 = cat(p1, if_body, "\n", "", "");
        char *p3 = cat(p2, "    goto ", lend, ";\n", "");
        char *p4 = cat(p3, lelse, ":\n", "", "");
        char *p5 = cat(p4, else_body, "\n", "", "");
        char *final_code = cat(p5, lend, ":;\n", "", "");

        (yyval.rec) = createRecord(final_code, "");
        
        free(val); free(lelse); free(lend);
        free(p1); free(p2); free(p3); free(p4); free(p5);
        free(final_code);
        freeRecord((yyvsp[-4].rec)); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1905 "parser.tab.c"
    break;

  case 49: /* while_stmt: WHILE LPAREN expr RPAREN block  */
#line 359 "parser.y"
                                   {
        char *val = deref_if_needed((yyvsp[-2].rec));
        char *lbegin = new_label();
        char *lend   = new_label();
        char *start_label = cat(lbegin, ":\n", "", "", "");
        char *cond_code   = cat("    if (!(", val, ")) goto ", lend, ";\n");
        char *body_code   = (yyvsp[0].rec)->code;
        char *goto_begin  = cat("    goto ", lbegin, ";\n", "", "");
        char *end_label   = cat(lend, ":;\n", "", "", "");
        char *p1 = cat(start_label, cond_code, "", "", "");
        char *p2 = cat(p1, body_code, "", "", "");
        char *p3 = cat(p2, goto_begin, "", "", "");
        char *final_code = cat(p3, end_label, "", "", "");
        (yyval.rec) = createRecord(final_code, "");
        free(val); free(lbegin); free(lend);
        free(start_label); free(cond_code); free(goto_begin); free(end_label);
        free(p1); free(p2); free(p3); free(final_code);
        freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 1929 "parser.tab.c"
    break;

  case 50: /* type: INT  */
#line 383 "parser.y"
             { (yyval.rec) = createRecord("int", "Int"); }
#line 1935 "parser.tab.c"
    break;

  case 51: /* type: FLOAT  */
#line 384 "parser.y"
               { (yyval.rec) = createRecord("float", "Float"); }
#line 1941 "parser.tab.c"
    break;

  case 52: /* type: UNIT  */
#line 385 "parser.y"
               { (yyval.rec) = createRecord("void", "Unit"); }
#line 1947 "parser.tab.c"
    break;

  case 53: /* type: RATIONAL  */
#line 386 "parser.y"
               { (yyval.rec) = createRecord("rational_t", "Rational"); }
#line 1953 "parser.tab.c"
    break;

  case 54: /* type: MATRIX  */
#line 387 "parser.y"
               { (yyval.rec) = createRecord("matrix_t*", "Matrix"); }
#line 1959 "parser.tab.c"
    break;

  case 55: /* type: BST  */
#line 388 "parser.y"
               { (yyval.rec) = createRecord("TreeNode*", "BST"); }
#line 1965 "parser.tab.c"
    break;

  case 56: /* type: ID  */
#line 389 "parser.y"
               {
        const char* found_type = lookupSymbol((yyvsp[0].str_val));
        if (found_type && strcmp(found_type, (yyvsp[0].str_val)) == 0) {
            char *ptr_type = cat((yyvsp[0].str_val), "*", "", "", "");
            (yyval.rec) = createRecord(ptr_type, strdup((yyvsp[0].str_val)));
            free(ptr_type);
        } else {
            char *ptr_type = cat((yyvsp[0].str_val), "*", "", "", "");
            (yyval.rec) = createRecord(ptr_type, strdup((yyvsp[0].str_val)));
            free(ptr_type);
        }
        free((yyvsp[0].str_val));
    }
#line 1983 "parser.tab.c"
    break;

  case 57: /* lvalue: ID  */
#line 405 "parser.y"
       {
        checkUndeclaredVariable((yyvsp[0].str_val));
        const char* type = lookupSymbol((yyvsp[0].str_val));
        (yyval.rec) = createRecord((yyvsp[0].str_val), strdup(type ? type : "Int"));
    }
#line 1993 "parser.tab.c"
    break;

  case 58: /* lvalue: lvalue DOT ID  */
#line 410 "parser.y"
                    {
        char* member_access = cat((yyvsp[-2].rec)->code, "->", (yyvsp[0].str_val), "", "");
        const char* field_type = "Int";
        if (strcmp((yyvsp[0].str_val), "left") == 0 || strcmp((yyvsp[0].str_val), "right") == 0) {
            field_type = (yyvsp[-2].rec)->opt1;
        }
        (yyval.rec) = createRecord(member_access, strdup(field_type));
        free(member_access); free((yyvsp[0].str_val));
        freeRecord((yyvsp[-2].rec));
    }
#line 2008 "parser.tab.c"
    break;

  case 59: /* expr: NEW ID  */
#line 423 "parser.y"
             {
        char* malloc_call = cat("malloc(sizeof(struct ", (yyvsp[0].str_val), "))", "", "");
        (yyval.rec) = createRecord(malloc_call, (yyvsp[0].str_val));
        free(malloc_call);
    }
#line 2018 "parser.tab.c"
    break;

  case 60: /* expr: expr PLUS expr  */
#line 428 "parser.y"
                       {
        if (((yyvsp[-2].rec)->opt1 && strncmp((yyvsp[-2].rec)->opt1, "TreeNode", 8) == 0) || ((yyvsp[0].rec)->opt1 && strncmp((yyvsp[0].rec)->opt1, "TreeNode", 8) == 0)) {
            yyerror("operação '+' não suportada para tipos struct"); exit(1);
        }
        char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec));
        char *s = cat("(", s1, " + ", s3, ")");
        const char* result_type = (strcmp((yyvsp[-2].rec)->opt1, "Float") == 0 || strcmp((yyvsp[0].rec)->opt1, "Float") == 0) ? "Float" : (yyvsp[-2].rec)->opt1;
        (yyval.rec) = createRecord(s, strdup(result_type));
        free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 2033 "parser.tab.c"
    break;

  case 61: /* expr: expr MINUS expr  */
#line 438 "parser.y"
                       {
        if (((yyvsp[-2].rec)->opt1 && strncmp((yyvsp[-2].rec)->opt1, "TreeNode", 8) == 0) || ((yyvsp[0].rec)->opt1 && strncmp((yyvsp[0].rec)->opt1, "TreeNode", 8) == 0)) {
            yyerror("operação '-' não suportada para tipos struct"); exit(1);
        }
        char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec));
        char *s = cat("(", s1, " - ", s3, ")");
        const char* result_type = (strcmp((yyvsp[-2].rec)->opt1, "Float") == 0 || strcmp((yyvsp[0].rec)->opt1, "Float") == 0) ? "Float" : (yyvsp[-2].rec)->opt1;
        (yyval.rec) = createRecord(s, strdup(result_type));
        free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 2048 "parser.tab.c"
    break;

  case 62: /* expr: expr MUL expr  */
#line 448 "parser.y"
                       {
        if (((yyvsp[-2].rec)->opt1 && strncmp((yyvsp[-2].rec)->opt1, "TreeNode", 8) == 0) || ((yyvsp[0].rec)->opt1 && strncmp((yyvsp[0].rec)->opt1, "TreeNode", 8) == 0)) {
            yyerror("operação '*' não suportada para tipos struct"); exit(1);
        }
        char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec));
        char *s = cat("(", s1, " * ", s3, ")");
        const char* result_type = (strcmp((yyvsp[-2].rec)->opt1, "Float") == 0 || strcmp((yyvsp[0].rec)->opt1, "Float") == 0) ? "Float" : (yyvsp[-2].rec)->opt1;
        (yyval.rec) = createRecord(s, strdup(result_type));
        free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 2063 "parser.tab.c"
    break;

  case 63: /* expr: expr DIV expr  */
#line 458 "parser.y"
                       {
        if (((yyvsp[-2].rec)->opt1 && strncmp((yyvsp[-2].rec)->opt1, "TreeNode", 8) == 0) || ((yyvsp[0].rec)->opt1 && strncmp((yyvsp[0].rec)->opt1, "TreeNode", 8) == 0)) {
            yyerror("operação '/' não suportada para tipos struct"); exit(1);
        }
        char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec));
        char *s = cat("(", s1, " / ", s3, ")");
        const char* result_type = "Float";
        (yyval.rec) = createRecord(s, strdup(result_type));
        free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec));
    }
#line 2078 "parser.tab.c"
    break;

  case 64: /* expr: expr LT expr  */
#line 468 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " < ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2084 "parser.tab.c"
    break;

  case 65: /* expr: expr LE expr  */
#line 469 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " <= ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2090 "parser.tab.c"
    break;

  case 66: /* expr: expr GT expr  */
#line 470 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " > ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2096 "parser.tab.c"
    break;

  case 67: /* expr: expr GE expr  */
#line 471 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " >= ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2102 "parser.tab.c"
    break;

  case 68: /* expr: expr EQ expr  */
#line 472 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " == ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2108 "parser.tab.c"
    break;

  case 69: /* expr: expr NE expr  */
#line 473 "parser.y"
                       { char* s1 = deref_if_needed((yyvsp[-2].rec)); char* s3 = deref_if_needed((yyvsp[0].rec)); char *s = cat("(", s1, " != ", s3, ")"); (yyval.rec) = createRecord(s, "Int"); free(s); free(s1); free(s3); freeRecord((yyvsp[-2].rec)); freeRecord((yyvsp[0].rec)); }
#line 2114 "parser.tab.c"
    break;

  case 70: /* expr: NULL_LIT  */
#line 474 "parser.y"
                       { (yyval.rec) = createRecord("NULL", "null"); }
#line 2120 "parser.tab.c"
    break;

  case 71: /* expr: lvalue  */
#line 475 "parser.y"
                       { (yyval.rec) = (yyvsp[0].rec); }
#line 2126 "parser.tab.c"
    break;

  case 72: /* expr: LPAREN expr RPAREN  */
#line 476 "parser.y"
                         { (yyval.rec) = (yyvsp[-1].rec); }
#line 2132 "parser.tab.c"
    break;

  case 73: /* expr: AMPERSAND ID  */
#line 477 "parser.y"
                       {
        char* addr_expr = cat("&", (yyvsp[0].str_val), "", "", "");
        const char* base_type = lookupSymbol((yyvsp[0].str_val));
        char* ptr_type_name = cat("ref", base_type ? base_type : "", "", "", "");
        (yyval.rec) = createRecord(addr_expr, ptr_type_name);
        free(addr_expr); free(ptr_type_name); free((yyvsp[0].str_val));
    }
#line 2144 "parser.tab.c"
    break;

  case 74: /* expr: INT_LIT  */
#line 484 "parser.y"
                       { char b[32]; sprintf(b,"%d",(yyvsp[0].int_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Int"); }
#line 2150 "parser.tab.c"
    break;

  case 75: /* expr: FLOAT_LIT  */
#line 485 "parser.y"
                       { char b[32]; sprintf(b,"%f",(yyvsp[0].float_val)); (yyval.rec)=createRecord(strdup(b),(char*)"Float"); }
#line 2156 "parser.tab.c"
    break;

  case 76: /* expr: func_call  */
#line 486 "parser.y"
                       { (yyval.rec) = (yyvsp[0].rec); }
#line 2162 "parser.tab.c"
    break;

  case 77: /* func_call: ID LPAREN arg_list_opt RPAREN  */
#line 490 "parser.y"
                                  {
        char *s = cat((yyvsp[-3].str_val), "(", (yyvsp[-1].rec)->code, ")", "");
        const char *type = "Unit";
        if (strcmp((yyvsp[-3].str_val), "get_height") == 0 || strcmp((yyvsp[-3].str_val), "max") == 0) { type = "Int"; }
        else if (strcmp((yyvsp[-3].str_val), "insert") == 0) { type = "TreeNode"; }
        (yyval.rec) = createRecord(s, (char*)type);
        free(s); free((yyvsp[-3].str_val)); freeRecord((yyvsp[-1].rec));
    }
#line 2175 "parser.tab.c"
    break;

  case 78: /* arg_list_opt: %empty  */
#line 501 "parser.y"
                  { (yyval.rec) = createRecord("", ""); }
#line 2181 "parser.tab.c"
    break;

  case 81: /* arg_list: arg_list COMMA expr  */
#line 507 "parser.y"
                          {
        char *s=cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "");
        (yyval.rec)=createRecord(s,"");
        free(s);
        freeRecord((yyvsp[-2].rec));
        freeRecord((yyvsp[0].rec));
    }
#line 2193 "parser.tab.c"
    break;


#line 2197 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 516 "parser.y"


// --- CÓDIGO AUXILIAR ---

void yyerror(const char *s) {
    fprintf(stderr, "ERRO DE SINTAXE: %s na linha %d perto de '%s'\n", s, yylineno, yytext);
    exit(1);
}

char* cat(const char *s1, const char *s2, const char *s3, const char *s4, const char *s5) {
    if (!s1 || !s2 || !s3 || !s4 || !s5) {
        fprintf(stderr, "Erro: argumento nulo passado para cat()\n");
        exit(1);
    }
    size_t len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + 1;
    char *o = malloc(len);
    if (!o) { fprintf(stderr, "Erro de malloc!\n"); exit(1); }
    sprintf(o, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    return o;
}

const char* map_type(const char* o) {
    if (o == NULL) return "void";
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
