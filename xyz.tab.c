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
#line 1 "xyz.y"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define MAX_VAR_NAME 100

int yydebug = 1;

extern int yylineno;

extern int yyerror(const char *msg, ...);
extern int yylex();

extern float getVar(const char *name);
extern void setVar(const char *name, float value);
extern void addVar(const char *name, int type);
extern void setScope(const char *scope);
extern void printVarTable();


#line 95 "xyz.tab.c"

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

#include "xyz.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_MAIN = 5,                       /* MAIN  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_FN = 7,                         /* FN  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_I64 = 9,                        /* I64  */
  YYSYMBOL_F64 = 10,                       /* F64  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_INC = 20,                       /* INC  */
  YYSYMBOL_DEC = 21,                       /* DEC  */
  YYSYMBOL_22_ = 22,                       /* '+'  */
  YYSYMBOL_23_ = 23,                       /* '-'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_UMINUS = 26,                    /* UMINUS  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_main = 40,                      /* main  */
  YYSYMBOL_function = 41,                  /* function  */
  YYSYMBOL_params = 42,                    /* params  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_declare = 44,                   /* declare  */
  YYSYMBOL_assign = 45,                    /* assign  */
  YYSYMBOL_return = 46,                    /* return  */
  YYSYMBOL_func_call = 47,                 /* func_call  */
  YYSYMBOL_call_params = 48,               /* call_params  */
  YYSYMBOL_branch = 49,                    /* branch  */
  YYSYMBOL_loop = 50,                      /* loop  */
  YYSYMBOL_expr = 51                       /* expr  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,    38,     2,     2,     2,    35,     2,     2,
      27,    28,    24,    22,    31,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    32,
      36,    34,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    41,    41,    42,    44,    47,    48,    49,    50,    53,
      54,    55,    56,    57,    58,    61,    62,    63,    64,    67,
      68,    69,    72,    75,    78,    79,    82,    83,    86,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "MAIN",
  "VAR", "FN", "RETURN", "I64", "F64", "IF", "ELSE", "WHILE", "EQ", "NE",
  "GE", "LE", "AND", "OR", "INC", "DEC", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "'('", "')'", "'{'", "'}'", "','", "';'", "':'", "'='", "'%'",
  "'<'", "'>'", "'!'", "$accept", "main", "function", "params",
  "statement", "declare", "assign", "return", "func_call", "call_params",
  "branch", "loop", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    -2,     7,    12,    -5,     2,   -67,   -67,    28,     9,
      39,   -19,    16,   -67,   -67,    23,    28,    27,    27,    22,
       0,    51,     1,     1,    48,    27,    25,    27,    27,    48,
      29,    30,     1,     1,    52,    27,   -67,    33,     1,     1,
       1,   -67,   118,   142,     1,    44,   -67,    27,   -67,   -67,
      54,   -67,   -67,   -14,   238,   166,    41,   -67,   252,   190,
     238,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    27,     1,     1,     1,    27,   214,   -67,   -67,   -67,
     -67,     1,   -67,    56,    57,   -67,   238,   238,   238,   238,
     238,   238,   252,   252,   205,   205,    62,   238,   238,   238,
      63,   -67,    67,     1,     1,    82,   -67,    64,    94,    74,
      51,   -67,    51,   -67,    27,   -67,   -67,    75,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     3,     8,     0,
       0,     0,     0,     5,     6,     0,     8,    14,    14,     7,
       0,     0,     0,     0,     0,    14,     0,    14,    14,     0,
       0,     0,     0,     0,     0,    14,    45,    46,     0,     0,
       0,    47,     0,     0,     0,     0,    10,    14,    12,    13,
       0,    20,    21,     0,    24,     0,     0,     9,    34,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,    14,     0,     2,    11,     4,
      23,     0,    19,     0,     0,    35,    40,    41,    39,    38,
      42,    43,    30,    29,    31,    32,     0,    33,    36,    37,
       0,    22,    25,     0,     0,    27,    28,     0,     0,     0,
       0,    17,     0,    18,    14,    15,    16,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   101,   -67,    98,   -12,   -66,   -67,    86,   -17,    40,
     -67,   -67,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    11,    24,    35,    25,    45,    41,    53,
      27,    28,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    26,     4,     5,    36,    37,    29,     6,    26,    15,
      26,    26,    16,    46,    80,    48,    49,    81,    26,     1,
      30,    31,     8,    57,    38,    42,    43,    32,    39,     9,
      26,    20,    10,    21,    33,    78,    55,    12,    22,    40,
      23,    58,    59,    60,   115,    17,   116,    76,    13,    14,
      83,    84,    18,    16,    26,    34,    44,    47,    26,    96,
      32,    51,    52,   100,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    97,    98,    99,    61,    62,
      63,    64,    65,    66,    79,    56,    67,    68,    69,    70,
     103,   104,   105,   106,   109,   110,   111,    26,    81,    72,
      73,    74,   117,   114,     7,   118,   107,   108,    61,    62,
      63,    64,    65,    66,    19,    50,    67,    68,    69,    70,
       0,   102,     0,     0,     0,   112,   113,     0,     0,    72,
      73,    74,    61,    62,    63,    64,    65,    66,     0,     0,
      67,    68,    69,    70,     0,     0,     0,    71,     0,     0,
       0,     0,     0,    72,    73,    74,    61,    62,    63,    64,
      65,    66,     0,     0,    67,    68,    69,    70,     0,     0,
       0,    75,     0,     0,     0,     0,     0,    72,    73,    74,
      61,    62,    63,    64,    65,    66,     0,     0,    67,    68,
      69,    70,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    72,    73,    74,    61,    62,    63,    64,    65,    66,
       0,     0,    67,    68,    69,    70,     0,     0,    85,    61,
      62,    63,    64,    65,    66,    72,    73,    74,    61,    62,
      63,    64,    65,    66,     0,     0,    67,    68,    69,    70,
      72,    73,    74,     0,     0,     0,   101,     0,     0,    72,
      73,    74,    61,    62,    63,    64,    65,    66,     0,     0,
      67,    68,    69,    70,     0,     0,    61,    62,    63,    64,
      65,    66,     0,    72,    73,    74,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74
};

static const yytype_int8 yycheck[] =
{
      17,    18,     4,     5,     3,     4,    18,     0,    25,    28,
      27,    28,    31,    25,    28,    27,    28,    31,    35,     7,
      20,    21,    27,    35,    23,    22,    23,    27,    27,    27,
      47,     4,     4,     6,    34,    47,    33,    28,    11,    38,
      13,    38,    39,    40,   110,    29,   112,    44,     9,    10,
       9,    10,    29,    31,    71,     4,     8,    32,    75,    71,
      27,    32,    32,    75,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    30,    72,    73,    74,    14,    15,
      16,    17,    18,    19,    30,    33,    22,    23,    24,    25,
      34,    34,    30,    30,    12,    31,    32,   114,    31,    35,
      36,    37,   114,    29,     3,    30,   103,   104,    14,    15,
      16,    17,    18,    19,    16,    29,    22,    23,    24,    25,
      -1,    81,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,    14,
      15,    16,    17,    18,    19,    35,    36,    37,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      35,    36,    37,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,    35,    36,    37,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    40,    41,     4,     5,     0,    40,    27,    27,
       4,    42,    28,     9,    10,    28,    31,    29,    29,    42,
       4,     6,    11,    13,    43,    45,    47,    49,    50,    43,
      20,    21,    27,    34,     4,    44,     3,     4,    23,    27,
      38,    47,    51,    51,     8,    46,    43,    32,    43,    43,
      46,    32,    32,    48,    51,    51,    33,    43,    51,    51,
      51,    14,    15,    16,    17,    18,    19,    22,    23,    24,
      25,    29,    35,    36,    37,    29,    51,    30,    43,    30,
      28,    31,    32,     9,    10,    28,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    43,    51,    51,    51,
      43,    32,    48,    34,    34,    30,    30,    51,    51,    12,
      31,    32,    31,    32,    29,    44,    44,    43,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    42,    42,    42,    42,    43,
      43,    43,    43,    43,    43,    44,    44,    44,    44,    45,
      45,    45,    46,    47,    48,    48,    49,    49,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     9,     2,     2,     3,     0,     3,
       2,     3,     2,     2,     0,     7,     7,     6,     6,     4,
       3,     3,     3,     4,     1,     3,     9,     5,     5,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1
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
  case 2: /* main: FN MAIN '(' ')' '{' statement return '}'  */
#line 41 "xyz.y"
                                                                                { (yyval.f) = (yyvsp[-1].f); setScope((yyvsp[-6].s)); printVarTable(); exit(0); }
#line 1229 "xyz.tab.c"
    break;

  case 3: /* main: function main  */
#line 42 "xyz.y"
                                                                                                                { (yyval.f) = (yyvsp[0].f); }
#line 1235 "xyz.tab.c"
    break;

  case 4: /* function: FN ID '(' params ')' '{' statement return '}'  */
#line 44 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-1].f); setScope((yyvsp[-7].s)); }
#line 1241 "xyz.tab.c"
    break;

  case 5: /* params: ID I64  */
#line 47 "xyz.y"
                                                                        { addVar((yyvsp[-1].s), INT_TYPE  ); }
#line 1247 "xyz.tab.c"
    break;

  case 6: /* params: ID F64  */
#line 48 "xyz.y"
                                                                                { addVar((yyvsp[-1].s), FLOAT_TYPE); }
#line 1253 "xyz.tab.c"
    break;

  case 7: /* params: params ',' params  */
#line 49 "xyz.y"
                                                                        {}
#line 1259 "xyz.tab.c"
    break;

  case 8: /* params: %empty  */
#line 50 "xyz.y"
                                                                                        {}
#line 1265 "xyz.tab.c"
    break;

  case 9: /* statement: VAR declare statement  */
#line 53 "xyz.y"
                                                        {}
#line 1271 "xyz.tab.c"
    break;

  case 10: /* statement: assign statement  */
#line 54 "xyz.y"
                                                                        {}
#line 1277 "xyz.tab.c"
    break;

  case 11: /* statement: func_call ';' statement  */
#line 55 "xyz.y"
                                                                {}
#line 1283 "xyz.tab.c"
    break;

  case 12: /* statement: branch statement  */
#line 56 "xyz.y"
                                                                        {}
#line 1289 "xyz.tab.c"
    break;

  case 13: /* statement: loop statement  */
#line 57 "xyz.y"
                                                                        {}
#line 1295 "xyz.tab.c"
    break;

  case 14: /* statement: %empty  */
#line 58 "xyz.y"
                                                                                        {}
#line 1301 "xyz.tab.c"
    break;

  case 15: /* declare: ID ':' I64 '=' expr ',' declare  */
#line 61 "xyz.y"
                                                                { addVar((yyvsp[-6].s), INT_TYPE  ); setVar((yyvsp[-6].s), (yyvsp[-2].f)); }
#line 1307 "xyz.tab.c"
    break;

  case 16: /* declare: ID ':' F64 '=' expr ',' declare  */
#line 62 "xyz.y"
                                                                        { addVar((yyvsp[-6].s), FLOAT_TYPE); setVar((yyvsp[-6].s), (yyvsp[-2].f)); }
#line 1313 "xyz.tab.c"
    break;

  case 17: /* declare: ID ':' I64 '=' expr ';'  */
#line 63 "xyz.y"
                                                                                { addVar((yyvsp[-5].s), INT_TYPE  ); setVar((yyvsp[-5].s), (yyvsp[-1].f)); }
#line 1319 "xyz.tab.c"
    break;

  case 18: /* declare: ID ':' F64 '=' expr ';'  */
#line 64 "xyz.y"
                                                                                { addVar((yyvsp[-5].s), FLOAT_TYPE); setVar((yyvsp[-5].s), (yyvsp[-1].f)); }
#line 1325 "xyz.tab.c"
    break;

  case 19: /* assign: ID '=' expr ';'  */
#line 67 "xyz.y"
                                                                { setVar((yyvsp[-3].s), (yyvsp[-1].f)); 			  }
#line 1331 "xyz.tab.c"
    break;

  case 20: /* assign: ID INC ';'  */
#line 68 "xyz.y"
                                                                                { setVar((yyvsp[-2].s), getVar((yyvsp[-2].s)) + 1); }
#line 1337 "xyz.tab.c"
    break;

  case 21: /* assign: ID DEC ';'  */
#line 69 "xyz.y"
                                                                                { setVar((yyvsp[-2].s), getVar((yyvsp[-2].s)) - 1); }
#line 1343 "xyz.tab.c"
    break;

  case 22: /* return: RETURN expr ';'  */
#line 72 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-1].f); }
#line 1349 "xyz.tab.c"
    break;

  case 23: /* func_call: ID '(' call_params ')'  */
#line 75 "xyz.y"
                                                        {}
#line 1355 "xyz.tab.c"
    break;

  case 24: /* call_params: expr  */
#line 78 "xyz.y"
                                                                                        { (yyval.f) = (yyvsp[0].f); }
#line 1361 "xyz.tab.c"
    break;

  case 25: /* call_params: call_params ',' call_params  */
#line 79 "xyz.y"
                                                                                {}
#line 1367 "xyz.tab.c"
    break;

  case 26: /* branch: IF expr '{' statement '}' ELSE '{' statement '}'  */
#line 82 "xyz.y"
                                                                      {}
#line 1373 "xyz.tab.c"
    break;

  case 27: /* branch: IF expr '{' statement '}'  */
#line 83 "xyz.y"
                                                                  {}
#line 1379 "xyz.tab.c"
    break;

  case 28: /* loop: WHILE expr '{' statement '}'  */
#line 86 "xyz.y"
                                                                                          {}
#line 1385 "xyz.tab.c"
    break;

  case 29: /* expr: expr '-' expr  */
#line 89 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) - (yyvsp[0].f); 		   }
#line 1391 "xyz.tab.c"
    break;

  case 30: /* expr: expr '+' expr  */
#line 90 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-2].f) + (yyvsp[0].f); 		   }
#line 1397 "xyz.tab.c"
    break;

  case 31: /* expr: expr '*' expr  */
#line 91 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-2].f) * (yyvsp[0].f); 		   }
#line 1403 "xyz.tab.c"
    break;

  case 32: /* expr: expr '/' expr  */
#line 92 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-2].f) / (yyvsp[0].f); 		   }
#line 1409 "xyz.tab.c"
    break;

  case 33: /* expr: expr '%' expr  */
#line 93 "xyz.y"
                                                                { (yyval.f) = (int)(yyvsp[-2].f) % (int)(yyvsp[0].f);  }
#line 1415 "xyz.tab.c"
    break;

  case 34: /* expr: '-' expr  */
#line 94 "xyz.y"
                                                                        { (yyval.f) = -(yyvsp[0].f);				   }
#line 1421 "xyz.tab.c"
    break;

  case 35: /* expr: '(' expr ')'  */
#line 95 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-1].f); 				   }
#line 1427 "xyz.tab.c"
    break;

  case 36: /* expr: expr '<' expr  */
#line 96 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-2].f) <  (yyvsp[0].f) ? 1. : 0.; }
#line 1433 "xyz.tab.c"
    break;

  case 37: /* expr: expr '>' expr  */
#line 97 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) >  (yyvsp[0].f) ? 1. : 0.; }
#line 1439 "xyz.tab.c"
    break;

  case 38: /* expr: expr LE expr  */
#line 98 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) <= (yyvsp[0].f) ? 1. : 0.; }
#line 1445 "xyz.tab.c"
    break;

  case 39: /* expr: expr GE expr  */
#line 99 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) >= (yyvsp[0].f) ? 1. : 0.; }
#line 1451 "xyz.tab.c"
    break;

  case 40: /* expr: expr EQ expr  */
#line 100 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) == (yyvsp[0].f) ? 1. : 0.; }
#line 1457 "xyz.tab.c"
    break;

  case 41: /* expr: expr NE expr  */
#line 101 "xyz.y"
                                                                { (yyval.f) = (yyvsp[-2].f) != (yyvsp[0].f) ? 1. : 0.; }
#line 1463 "xyz.tab.c"
    break;

  case 42: /* expr: expr AND expr  */
#line 102 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) && (yyvsp[0].f) ? 1. : 0.; }
#line 1469 "xyz.tab.c"
    break;

  case 43: /* expr: expr OR expr  */
#line 103 "xyz.y"
                                                        { (yyval.f) = (yyvsp[-2].f) || (yyvsp[0].f) ? 1. : 0.; }
#line 1475 "xyz.tab.c"
    break;

  case 44: /* expr: '!' expr  */
#line 104 "xyz.y"
                                                                { (yyval.f) = (yyvsp[0].f) == 0. ? 1. : 0.; }
#line 1481 "xyz.tab.c"
    break;

  case 45: /* expr: NUM  */
#line 105 "xyz.y"
                                                                                { (yyval.f) = (yyvsp[0].f); 				   }
#line 1487 "xyz.tab.c"
    break;

  case 46: /* expr: ID  */
#line 106 "xyz.y"
                                                                                { (yyval.f) = getVar((yyvsp[0].s)); 		   }
#line 1493 "xyz.tab.c"
    break;

  case 47: /* expr: func_call  */
#line 107 "xyz.y"
                                                                        { (yyval.f) = (yyvsp[0].f);				   }
#line 1499 "xyz.tab.c"
    break;


#line 1503 "xyz.tab.c"

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

#line 111 "xyz.y"


#include "xyz.yy.c"
#include <stdbool.h>

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define MAX_VARIABLES 100
#define MAX_VAR_NAME 100

typedef struct {
	int type;
    float value;
    char name[MAX_VAR_NAME];
} Variable;

int variableCount = 0;
int lastScopeDefined = -1;
Variable variables[MAX_VARIABLES];

int yyerror (char const *msg, ...);
int yylex();

float getVar(const char *name);
bool isVarDeclared(const char* name);
void setVar(const char *name, float value);
void addVar(const char *name, int type);
void setScope(const char *scope);

void addVar(const char *name, int type) {
	char fullName[MAX_VAR_NAME];

	if(variableCount > MAX_VARIABLES - 1) {
		yyerror("Erro: tabela de variaveis cheia.\n");
		return;
	}

	if(isVarDeclared(name)) {
		yyerror("Erro: mais de uma declaração para a mesma variável.\n");
		return;
	}

	strcpy(variables[variableCount].name, name);
	variables[variableCount].type = type;
	variableCount++;
}

void setVar(const char *name, float value) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
			variables[i].value = value;
			return;
        }
    }
	yyerror("Erro: variável não declarada.\n");
}

bool isVarDeclared(const char* name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0)
            return true;
    }
    return false;
}

float getVar(const char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0)
			return variables[i].value;
    }
	yyerror("Erro: variável não declarada.\n");
    return 0;
}

void setScope(const char *scope) {
	char fullName[MAX_VAR_NAME];

    for (int i = lastScopeDefined + 1; i < variableCount; i++) {
		strcpy(fullName, scope);
		strcat(fullName, ".");
		strcat(fullName, variables[i].name);
		strcpy(variables[i].name, fullName);
		lastScopeDefined = i;
    }
}

void printVarTable() {
	printf("\nTabela de símbolos:\n\n");
	for(int i = 0; i < variableCount; i++) {
		printf("%s [%s]\n", variables[i].name, variables[i].type == INT_TYPE ? "i64" : "f64");
	}
	printf("\n");
}

int yyerror(const char *msg, ...) {
	va_list args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

int main (int argc, char **argv) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }

    return yyparse();
}
