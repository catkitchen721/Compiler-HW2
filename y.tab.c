/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
void yyerror(char *s);

typedef struct _symbol_table_entry {
	char name[32];
	char entry_type[32];
	char data_type[16];
	int scope_level;
	char formal_para[16][16];
}symbol_table_entry;

symbol_table_entry *symbol_table = NULL;
int table_pointer = 0;
extern int curr_scope;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char name[32]);
void create_symbol();
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]);
void dump_symbol();


#line 97 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    SEMICOLON = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    INC = 269,
    DEC = 270,
    MT = 271,
    LT = 272,
    MTE = 273,
    LTE = 274,
    EQ = 275,
    NE = 276,
    ASGN = 277,
    ADDASGN = 278,
    SUBASGN = 279,
    MULASGN = 280,
    DIVASGN = 281,
    MODASGN = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LB = 286,
    RB = 287,
    LCB = 288,
    RCB = 289,
    LSB = 290,
    RSB = 291,
    COMMA = 292,
    RET = 293,
    CONTINUE = 294,
    BREAK = 295,
    C_COMMENT = 296,
    CPP_COMMENT = 297,
    I_CONST = 298,
    F_CONST = 299,
    TRUE_RESULT = 300,
    FALSE_RESULT = 301,
    INT = 302,
    FLOAT = 303,
    BOOL = 304,
    STRING = 305,
    VOID = 306,
    STR_CONST = 307,
    ID = 308
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define MT 271
#define LT 272
#define MTE 273
#define LTE 274
#define EQ 275
#define NE 276
#define ASGN 277
#define ADDASGN 278
#define SUBASGN 279
#define MULASGN 280
#define DIVASGN 281
#define MODASGN 282
#define AND 283
#define OR 284
#define NOT 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define RET 293
#define CONTINUE 294
#define BREAK 295
#define C_COMMENT 296
#define CPP_COMMENT 297
#define I_CONST 298
#define F_CONST 299
#define TRUE_RESULT 300
#define FALSE_RESULT 301
#define INT 302
#define FLOAT 303
#define BOOL 304
#define STRING 305
#define VOID 306
#define STR_CONST 307
#define ID 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    int bool_val;

#line 250 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    73,    77,    78,    82,    83,    87,    88,
      92,   186,   283,   393,   394,   398,   399,   403,   408,   409,
     410,   411,   412,   416,   417,   421,   422,   426,   427,   428,
     429,   433,   434,   435,   439,   440,   444,   448,   452,   453,
     457,   458,   459,   460,   461,   462,   463,   464,   468,   469,
     470,   471,   472,   473,   477,   478,   482,   486,   487,   491,
     492,   496,   497,   498,   499,   503,   504,   508,   509,   513,
     514,   518,   519,   523,   524
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT",
  "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN",
  "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "COMMA", "RET", "CONTINUE", "BREAK", "C_COMMENT",
  "CPP_COMMENT", "I_CONST", "F_CONST", "TRUE_RESULT", "FALSE_RESULT",
  "INT", "FLOAT", "BOOL", "STRING", "VOID", "STR_CONST", "ID", "$accept",
  "program", "global_decl_or_functions", "global_decl_or_function",
  "global_decl", "var_decl", "function_decl", "para_area", "paras", "para",
  "type", "initializer", "logic_initializer", "number_initializer",
  "tf_initializer", "count_expr", "function_define", "combound_area",
  "combound_area_inner", "stat", "asgn_stat", "print_stat",
  "function_using", "para_area_using", "paras_using", "if_stat",
  "single_if_stat", "else_if_stats", "else_stat", "while_stat",
  "return_stat", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -73,     2,   -73,   -73,   -73,   -73,   -73,   -73,    89,   -73,
     -73,   -73,   -73,   -41,   -73,   -73,    -3,   -73,    72,    63,
      -4,    13,   -73,   -73,   -73,   -73,   -73,    17,   -73,   -73,
     -73,   -73,   -73,     1,   -73,   -19,   -73,   -73,   -73,    -6,
       3,   -73,   -73,    89,   -73,     7,   -73,   -73,   -73,    34,
      36,    58,   -73,   -73,    39,   104,   -73,    -9,   -73,   -73,
     -73,   -73,   -73,    54,   -73,   -73,   -13,    27,    27,   -73,
      60,    72,   -26,   -26,   -26,   -26,   -26,    56,    82,    -1,
      28,    88,   -73,    62,    64,    65,    66,   -73,   111,   -73,
     112,   113,   114,   115,   124,   -73,   -73,    37,   -73,   -73,
     -73,    54,    28,   -73,   125,   126,    28,    28,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,    72,    54,   -73,   -73,   -73,
     -73,   -73,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    18,    19,    20,    21,    22,     2,     5,
       6,     8,     9,     0,     7,     4,     0,    11,     0,     0,
       0,    27,    28,    31,    32,    24,    30,     0,    23,    25,
      26,    29,    14,     0,    16,     0,    12,    39,    36,     0,
       0,    10,    13,     0,    17,     0,    34,    35,    15,     0,
       0,     0,    47,    37,     0,     0,    41,     0,    38,    40,
      42,    43,    44,    64,    45,    46,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,     0,     0,    73,     0,    30,
       0,     0,     0,     0,     0,    58,    60,     0,    56,    69,
      70,    64,     0,    61,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    57,     0,    64,    54,    55,    65,
      66,    71,    72,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   133,   -73,     8,   -73,   -73,   -73,    99,
       5,   -51,   -25,    31,   -73,   -73,   -73,   -20,   -73,   -44,
     -73,   -73,   -73,   -73,   -73,   -73,   -72,   -73,    67,   -73,
     -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     8,     9,    10,    56,    12,    20,    33,    34,
      57,    27,    28,    29,    30,    31,    14,    99,    45,   100,
      59,    60,    61,    78,    97,    62,    63,    81,    82,    64,
      65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    58,     2,    70,    36,    17,    13,    17,   101,    11,
      49,    50,    16,    13,    51,    52,    11,    21,    22,    18,
      88,    18,    39,    40,    35,    41,    96,    89,    19,    37,
     116,    49,    50,    42,    44,    51,    52,    46,    43,    83,
      84,    53,    85,    86,    79,    54,    47,    69,    35,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    80,
      55,    37,   120,   122,   123,    66,    54,    67,    87,   114,
      21,    22,    23,    24,   115,     3,     4,     5,     6,     7,
      26,    55,    21,    22,    23,    24,   119,   121,    95,    68,
      98,    25,    26,   102,   104,    32,   105,   106,   107,    21,
      22,    23,    24,    90,    91,    92,    93,    94,    25,    26,
       3,     4,     5,     6,     7,    21,    22,    23,    24,   108,
     109,   110,   111,   112,    25,    26,    71,    72,    73,    74,
      75,    76,   113,   117,   118,    77,     3,     4,     5,     6,
       7,    15,    48,     0,     0,     0,     0,     0,   103
};

static const yytype_int8 yycheck[] =
{
      20,    45,     0,    54,     8,     8,     1,     8,    80,     1,
       3,     4,    53,     8,     7,     8,     8,    43,    44,    22,
      71,    22,     9,    10,    19,     8,    77,    53,    31,    33,
     102,     3,     4,    32,    53,     7,     8,    43,    37,    52,
      53,    34,    67,    68,    53,    38,    43,     8,    43,    47,
      48,    49,    50,    51,    47,    48,    49,    50,    51,     5,
      53,    33,   106,   107,   115,    31,    38,    31,     8,    32,
      43,    44,    45,    46,    37,    47,    48,    49,    50,    51,
      53,    53,    43,    44,    45,    46,   106,   107,    32,    31,
       8,    52,    53,     5,    32,    32,    32,    32,    32,    43,
      44,    45,    46,    72,    73,    74,    75,    76,    52,    53,
      47,    48,    49,    50,    51,    43,    44,    45,    46,     8,
       8,     8,     8,     8,    52,    53,    22,    23,    24,    25,
      26,    27,     8,     8,     8,    31,    47,    48,    49,    50,
      51,     8,    43,    -1,    -1,    -1,    -1,    -1,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,    47,    48,    49,    50,    51,    56,    57,
      58,    59,    60,    64,    70,    57,    53,     8,    22,    31,
      61,    43,    44,    45,    46,    52,    53,    65,    66,    67,
      68,    69,    32,    62,    63,    64,     8,    33,    71,     9,
      10,     8,    32,    37,    53,    72,    43,    43,    63,     3,
       4,     7,     8,    34,    38,    53,    59,    64,    73,    74,
      75,    76,    79,    80,    83,    84,    31,    31,    31,     8,
      65,    22,    23,    24,    25,    26,    27,    31,    77,    53,
       5,    81,    82,    52,    53,    66,    66,     8,    65,    53,
      67,    67,    67,    67,    67,    32,    65,    78,     8,    71,
      73,    80,     5,    82,    32,    32,    32,    32,     8,     8,
       8,     8,     8,     8,    32,    37,    80,     8,     8,    71,
      73,    71,    73,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    70,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    77,    77,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       5,     3,     4,     3,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     5,     5,     3,     3,     2,     3,
       1,     3,     2,     2,     1,     5,     5,     3,     2,     2,
       2,     5,     5,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 10:
#line 92 "compiler_hw2.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-4].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-3].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-3].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-3].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-4].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-3].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-3].string), "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-3].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		// semantic error
    		printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| %s can not be declared \"void\"", (yyvsp[-3].string));
			printf("\n|-----------------------------------------------|\n\n");
    	}
    }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 186 "compiler_hw2.y" /* yacc.c:1646  */
    {
    	if(strcmp((yyvsp[-2].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-1].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-1].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-1].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-2].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    		int targetIndex = lookup_symbol((yyvsp[-1].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-1].string), "variable", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared variable %s", (yyvsp[-1].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		// semantic error
    		printf("\n|-----------------------------------------------|\n");
			printf("| Error found in line %d: %s\n", yylineno, buf);
			printf("| %s can not be declared \"void\"", (yyvsp[-1].string));
			printf("\n|-----------------------------------------------|\n\n");
    	}
    }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 283 "compiler_hw2.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-3].string), "int") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "int", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "int", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", (yyvsp[-2].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "float") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "float", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "float", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", (yyvsp[-2].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "bool") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "bool", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "bool", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", (yyvsp[-2].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else if(strcmp((yyvsp[-3].string), "string") == 0)
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "string", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "string", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", (yyvsp[-2].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
    	else
    	{
    		char temp[16][16] = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "decl"};
    		int targetIndex = lookup_symbol((yyvsp[-2].string));
    		if(targetIndex == -1)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "void", curr_scope, temp);
    		}
    		else if(targetIndex != -1 && symbol_table[targetIndex].scope_level != curr_scope)
    		{
    			insert_symbol((yyvsp[-2].string), "function", "void", curr_scope, temp);
    		}
    		else
    		{
    			// semantic error
				printf("\n|-----------------------------------------------|\n");
				printf("| Error found in line %d: %s\n", yylineno, buf);
				printf("| Redeclared function %s", (yyvsp[-2].string));
				printf("\n|-----------------------------------------------|\n\n");
    		}
    	}
	}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 408 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 409 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 410 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 411 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 412 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 448 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_symbol(); curr_scope--; }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1790 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 527 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 1;
    create_symbol();
    printf("1. ");
    curr_scope = 0;

    yyparse();
    dump_symbol();
	printf("\nTotal lines: %d \n",yylineno);
	
	if(symbol_table != NULL)
	{
		free(symbol_table);
	}
    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {
	symbol_table = (symbol_table_entry *)malloc(sizeof(symbol_table_entry) * 30);
	for(int i=0; i<30; i++)
	{
		strcpy(symbol_table[i].name, "\0");
		strcpy(symbol_table[i].entry_type, "\0");
		strcpy(symbol_table[i].data_type, "\0");
		symbol_table[i].scope_level = -1;
		for(int j=0; j<16; j++)
			strcpy(symbol_table[i].formal_para[i], "\0");
	}
}
void insert_symbol(char name[32], char entry_type[32], char data_type[16], int scope_level, char formal_para[16][16]) {
	if(lookup_symbol(name) != -1)
	{
		//semantic error.
	}
	else if(lookup_symbol(name) == -1)
	{
		strcpy(symbol_table[table_pointer].name, name);
		strcpy(symbol_table[table_pointer].entry_type, entry_type);
		strcpy(symbol_table[table_pointer].data_type, data_type);
		symbol_table[table_pointer].scope_level = scope_level;
		for(int i=0; i<16; i++)
			strcpy(symbol_table[table_pointer].formal_para[i], formal_para[i]);
		
		if(table_pointer != 29) table_pointer++;
	}
	else
	{
		//unknown error, here is imposible in general.
	}
}
int lookup_symbol(char name[32]) {
	for(int i=0; i<30; i++)
	{
		if(strcmp(symbol_table[i].name, name) == 0)
		{
			return i;  //used
		}
	}
	return -1;
}
void dump_symbol() {
	int myFlag = 0;
	for(int i=0; i<30; i++)
	{
		if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
		{
			myFlag = 1;
		}
	}
	if(myFlag)
	{
		printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	}
    int dump_index = 0;
           
    for(int i=0; i<30; i++)
    {
    	char attribute[10] = "\0";
    	char index_str[10] = "\0";
    	char scope_str[10] = "\0";
    	
    	if(symbol_table[i].scope_level == curr_scope && strcmp(symbol_table[i].name, "\0") != 0)
    	{
    		for(int j=0; j<15; j++)
    		{
    			strcat(attribute, symbol_table[i].formal_para[j]);
    			if(j != 14 && strcmp(symbol_table[i].formal_para[j+1], "\0") != 0 && strcmp(symbol_table[i].formal_para[j+1], "decl") != 0) strcat(attribute, ", ");
    		}
    		sprintf(index_str, "%d", dump_index);
    		sprintf(scope_str, "%d", symbol_table[i].scope_level);
    		printf("%-10s%-10s%-12s%-10s%-10s%-10s\n",
           index_str, symbol_table[i].name, symbol_table[i].entry_type, symbol_table[i].data_type, scope_str, attribute);
           
           strcpy(symbol_table[i].name, "\0");
		   strcpy(symbol_table[i].entry_type, "\0");
		   strcpy(symbol_table[i].data_type, "\0");
		   symbol_table[i].scope_level = -1;
		   for(int j=0; j<16; j++)
			   strcpy(symbol_table[i].formal_para[i], "\0");
           
           dump_index++;
    	}
    }
}
