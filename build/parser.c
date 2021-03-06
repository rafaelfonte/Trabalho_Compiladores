/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

/* COMPONENTES:
	Clemilson Dias
	Rafael da Fonte Lopes da Silva
*/


#include <stdlib.h>
#include <string.h>
#include "../include/main.h"

int yylineno;
int escopo_eh_local;
int passou_declaracoes_funcao;
int com_eh_input;
int contador_args_chamada_funcao;
int contador_regressivo_args_chamada_funcao;

int escopo_id_eh_global;

comp_dict_t *dicionario_escopo_global;
comp_dict_t *dicionario_escopo_local;
comp_dict_t *dicionario_atual;
comp_dict_item_t * pt_tabela_funcao;//Guarda um ponteiro para a entrada na tabela de simbolos da funcao que esta sendo reconhecida
comp_dict_item_t * pt_tabela_fun_chamada;

//Definicao de tamanhos de variaveis e vetores.
inline int sm_size_from_type_var(int type);
inline int sm_size_from_type_vec(int type,comp_list_t* dim_lst);


inline void sm_verify_if_variable(comp_dict_item_t* variable);
inline void sm_verify_if_vector(comp_dict_item_t* vector);
inline void sm_verify_if_function(comp_dict_item_t* item);
inline void inicializa_dic_escopo_global();
inline void inicializa_dic_escopo_local();
inline void sm_testa_tipos_output(comp_dict_item_t* item);
inline comp_dict_item_t* sm_define_tipo_funcao(int tipo_funcao, comp_dict_item_t* pt_tabela);
inline int sm_ret_verify_return_type(int fun_ret_type,int return_var_type);
inline void sm_insere_lista_args(int tipo,comp_dict_item_t* pt_id);
inline void sm_testa_qnt_args_missing(comp_dict_item_t* fun);
inline void sm_testa_qnt_args_excess_and_type(comp_dict_item_t* fun,comp_tree_t* expr);
inline int sm_fun_call_type_verify_coercion(int fun_arg_type,int expr_type);

//ETAPA 5
inline comp_list_t* sm_init_lista_dimensoes();
inline comp_list_t* sm_adiciona_dimensao(comp_list_t* lst,int t_dim);
ILOC_OP_LIST * geraCodigoExpr(ILOC_OP_LIST * res_list, ILOC_OP_LIST * l1, ILOC_OP_LIST * l2, int operation, comp_tree_t* node);
void concatena_codigo(ILOC_OP_LIST ** l1, ILOC_OP_LIST *l2);


int DESLOC_GLOBAL_VARIABLE_POINTER;
int DESLOC_FRAME_POINTER;

int base_global;
int base_local;




/* Line 268 of yacc.c  */
#line 132 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_PR_INT = 258,
     TK_PR_FLOAT = 259,
     TK_PR_BOOL = 260,
     TK_PR_CHAR = 261,
     TK_PR_STRING = 262,
     TK_PR_IF = 263,
     TK_PR_THEN = 264,
     TK_PR_ELSE = 265,
     TK_PR_WHILE = 266,
     TK_PR_DO = 267,
     TK_PR_INPUT = 268,
     TK_PR_OUTPUT = 269,
     TK_PR_RETURN = 270,
     TK_OC_LE = 271,
     TK_OC_GE = 272,
     TK_OC_EQ = 273,
     TK_OC_NE = 274,
     TK_OC_AND = 275,
     TK_OC_OR = 276,
     TK_LIT_INT = 277,
     TK_LIT_FLOAT = 278,
     TK_LIT_FALSE = 279,
     TK_LIT_TRUE = 280,
     TK_LIT_CHAR = 281,
     TK_LIT_STRING = 282,
     TK_IDENTIFICADOR = 283,
     TOKEN_ERRO = 284,
     TOKEN_EOF = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 62 "parser.y"
 
  comp_dict_item_t* symbol; 


/* Line 293 of yacc.c  */
#line 67 "parser.y"

 comp_tree_t * tree_node;


/* Line 293 of yacc.c  */
#line 72 "parser.y"

 int type_data;


/* Line 293 of yacc.c  */
#line 77 "parser.y"

 comp_list_t* dim_lst;



/* Line 293 of yacc.c  */
#line 222 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 234 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,     2,     2,     2,
      44,    45,    36,    34,    43,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    40,
      32,    31,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    36,    42,    46,    51,
      55,    56,    63,    68,    72,    73,    81,    88,    90,    91,
      94,    96,   100,   103,   107,   110,   113,   115,   119,   121,
     123,   125,   127,   129,   131,   133,   135,   137,   140,   147,
     150,   152,   154,   155,   159,   162,   164,   168,   171,   176,
     180,   182,   186,   190,   194,   198,   201,   205,   209,   213,
     217,   221,   225,   229,   233,   236,   238,   240,   244,   247,
     249,   251,   253,   255,   257,   259,   261,   263,   265,   269,
     274,   276,   277,   282,   289,   298,   306,   314,   316,   318,
     321,   324,   326
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,    50,    51,    30,    -1,    -1,    53,
      52,    51,    -1,    53,    -1,    55,    -1,    56,    -1,    60,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,    54,    39,    28,    40,    -1,    54,    39,    28,    57,
      40,    -1,    41,    22,    42,    -1,    41,    22,    42,    57,
      -1,    54,    39,    28,    -1,    -1,    54,    39,    28,    43,
      59,    58,    -1,    62,    65,    61,    66,    -1,    62,    61,
      66,    -1,    -1,    54,    39,    63,    64,    44,    58,    45,
      -1,    54,    39,    63,    64,    44,    45,    -1,    28,    -1,
      -1,    55,    65,    -1,    55,    -1,    46,    67,    47,    -1,
      46,    47,    -1,    69,    40,    67,    -1,    88,    67,    -1,
      69,    40,    -1,    88,    -1,    66,    40,    67,    -1,    66,
      -1,    40,    -1,    69,    -1,    88,    -1,    70,    -1,    74,
      -1,    76,    -1,    78,    -1,    79,    -1,    71,    83,    -1,
      72,    73,    83,    42,    31,    83,    -1,    28,    31,    -1,
      28,    -1,    41,    -1,    -1,    13,    75,    28,    -1,    14,
      77,    -1,    83,    -1,    83,    43,    77,    -1,    15,    83,
      -1,    80,    44,    86,    45,    -1,    80,    44,    45,    -1,
      28,    -1,    83,    34,    83,    -1,    83,    35,    83,    -1,
      83,    36,    83,    -1,    83,    37,    83,    -1,    35,    83,
      -1,    83,    16,    83,    -1,    83,    17,    83,    -1,    83,
      32,    83,    -1,    83,    33,    83,    -1,    83,    18,    83,
      -1,    83,    19,    83,    -1,    83,    20,    83,    -1,    83,
      21,    83,    -1,    38,    83,    -1,    81,    -1,    82,    -1,
      44,    83,    45,    -1,    84,    85,    -1,    28,    -1,    22,
      -1,    25,    -1,    24,    -1,    23,    -1,    79,    -1,    27,
      -1,    26,    -1,    28,    -1,    41,    83,    42,    -1,    41,
      83,    42,    85,    -1,    83,    -1,    -1,    83,    43,    87,
      86,    -1,     8,    44,    82,    45,     9,    90,    -1,     8,
      44,    82,    45,     9,    89,    10,    90,    -1,    11,    44,
      82,    45,    12,    91,    40,    -1,    12,    91,    11,    44,
      82,    45,    40,    -1,    68,    -1,    66,    -1,    68,    40,
      -1,    66,    40,    -1,    68,    -1,    66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   132,   142,   142,   151,   154,   155,   156,
     159,   160,   161,   162,   163,   166,   179,   190,   194,   199,
     200,   200,   203,   210,   219,   222,   223,   225,   227,   231,
     232,   235,   244,   251,   259,   267,   270,   273,   281,   284,
     289,   290,   293,   294,   295,   296,   297,   337,   349,   366,
     375,   383,   389,   389,   400,   409,   413,   422,   431,   440,
     448,   460,   471,   482,   493,   505,   517,   528,   539,   550,
     561,   572,   583,   596,   610,   621,   630,   639,   648,   661,
     679,   690,   700,   710,   723,   730,   753,   767,   774,   777,
     787,   793,   793,   801,   810,   820,   828,   838,   841,   844,
     847,   851,   854
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO",
  "TOKEN_EOF", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'!'",
  "':'", "';'", "'['", "']'", "','", "'('", "')'", "'{'", "'}'", "$accept",
  "s", "$@1", "k", "$@2", "declaracoes", "tipo", "decl_variavel",
  "decl_vetor", "dimensoes", "decl_parametro", "$@3", "decl_funcao",
  "passou_decl_action", "cabecalho", "id_funcao",
  "init_escopo_local_action", "decl_locais", "bloco", "comandos",
  "comando", "comando_simples", "atribuicao", "variavel_atr_simples",
  "variavel_atr_index_id", "variavel_atr_index_arvore", "entrada", "$@4",
  "saida", "lista_elementos", "retorno", "chamada_funcao",
  "chamada_funcao_id", "expressao_aritmetica", "expressao_logica",
  "expressao", "expressao_indexada_id", "expressao_indexada_dim",
  "lista_argumentos", "$@5", "fluxo_controle", "then", "then_else",
  "comandos_while_do", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    61,    60,    62,    43,    45,    42,    47,    33,    58,
      59,    91,    93,    44,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    49,    52,    51,    51,    53,    53,    53,
      54,    54,    54,    54,    54,    55,    56,    57,    57,    58,
      59,    58,    60,    60,    61,    62,    62,    63,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    70,    70,    71,
      72,    73,    75,    74,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    85,    85,
      86,    87,    86,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     3,     4,     3,
       0,     6,     4,     3,     0,     7,     6,     1,     0,     2,
       1,     3,     2,     3,     2,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     6,     2,
       1,     1,     0,     3,     2,     1,     3,     2,     4,     3,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     0,     4,     6,     8,     7,     7,     1,     1,     2,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    10,    11,    12,    13,    14,     0,
       4,     0,     7,     8,     9,    24,     3,     0,     0,     0,
      30,     0,    24,     5,    27,    28,     0,    29,     0,    23,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    50,    39,    32,    38,     0,     0,    42,     0,
       0,    43,    44,    45,    46,     0,    36,    22,     0,    16,
       0,     0,     0,   102,   101,    40,    41,     0,     0,    80,
      83,    82,    81,    86,    85,    79,     0,     0,     0,    54,
      84,    75,    76,    55,     0,    57,    49,     0,    31,    35,
      47,    51,     0,     0,    34,    17,    26,     0,     0,    76,
       0,    76,     0,    53,    65,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    37,    33,     0,    59,    90,     0,    18,     0,
      25,     0,     0,     0,    77,    66,    67,    70,    71,    72,
      73,    68,    69,    61,    62,    63,    64,    56,     0,     0,
      91,    58,    19,     0,     0,    76,    88,     0,     0,    20,
      98,    97,     0,    93,     0,     0,    89,    48,    92,     0,
     100,    99,     0,    95,    96,    21,     0,     0,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    17,    10,    11,    12,    13,    33,
      98,   169,    14,    21,    15,    25,    34,    22,    45,    46,
      64,    47,    48,    49,    50,    92,    51,    68,    52,    79,
      53,    80,    55,    81,    82,   100,    84,   121,   127,   158,
      56,   162,   163,    67
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -150
static const yytype_int16 yypact[] =
{
    -150,    15,    50,  -150,  -150,  -150,  -150,  -150,  -150,   -13,
      -9,     2,  -150,  -150,  -150,    50,  -150,    50,    20,    19,
      50,   -22,  -150,  -150,     3,  -150,    31,  -150,    24,  -150,
     -22,  -150,    -3,    28,    16,    29,    18,    32,    95,  -150,
     255,   255,   -11,  -150,  -150,    37,    48,    56,  -150,   255,
      61,  -150,  -150,  -150,  -150,    34,    86,  -150,    62,  -150,
      22,   255,   255,  -150,  -150,  -150,  -150,    94,    83,  -150,
    -150,  -150,  -150,  -150,  -150,   -10,   255,   255,   255,  -150,
    -150,  -150,  -150,   145,    71,   268,  -150,    86,  -150,    86,
     268,  -150,   255,   231,  -150,    72,  -150,    76,    75,    79,
     268,    80,    73,  -150,    10,  -150,   139,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,  -150,  -150,  -150,   201,  -150,   173,    84,  -150,    88,
    -150,   126,   124,   255,  -150,   290,   290,   290,   290,    38,
      38,   290,   290,    10,    10,  -150,  -150,  -150,   228,   107,
    -150,  -150,    96,    95,    95,    97,    71,   255,   255,  -150,
     103,   104,   135,  -150,   108,   109,  -150,   268,  -150,    50,
    -150,  -150,    95,  -150,  -150,  -150,   103,   104,  -150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   130,  -150,  -150,   -15,    -4,  -150,    55,
     -18,  -150,  -150,   131,  -150,  -150,  -150,   147,   -20,   -47,
    -149,   -35,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    49,
    -150,   -26,  -150,  -150,   -54,   -27,  -150,    13,    12,  -150,
     -32,  -150,    11,    33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      19,    29,    54,    65,   161,    19,    66,    99,   101,    94,
      57,    20,    54,    83,    85,     3,    20,    16,    63,    58,
      86,    -6,    90,   177,    28,     4,     5,     6,     7,     8,
      54,   -87,    36,   -60,   -60,    37,    38,    39,    40,    41,
     122,    18,   123,    31,    32,    97,   117,   118,    24,   104,
     105,   106,    42,     4,     5,     6,     7,     8,    26,    35,
      60,    54,    61,    54,    43,   124,   126,    96,    59,    31,
      28,    44,   115,   116,   117,   118,    62,    87,    93,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    83,   148,    36,    88,    89,    37,    38,    39,
      40,    41,    91,    36,    95,   102,    37,    38,    39,    40,
      41,   103,   120,    32,    42,   129,   152,   133,    65,    65,
     130,    66,    66,    42,   131,   132,    43,    54,    54,   151,
     167,   126,    28,   160,    63,   153,   154,    65,   157,   159,
      66,    28,   165,   170,   171,   172,    54,    23,   173,   174,
     128,   175,   176,    30,    97,   107,   108,   109,   110,   111,
     112,   107,   108,   109,   110,   111,   112,    27,   147,   166,
     168,   113,   114,   115,   116,   117,   118,   113,   114,   115,
     116,   117,   118,   178,   134,     0,     0,   164,   119,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,   150,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,     0,
       0,     0,     0,   149,   107,   108,   109,   110,   111,   112,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
     113,   114,   115,   116,   117,   118,    76,     0,     0,    77,
     156,     0,     0,     0,     0,    78,   125,    69,    70,    71,
      72,    73,    74,    75,   107,   108,   109,   110,   111,   112,
      76,     0,     0,    77,     0,     0,     0,     0,     0,    78,
     113,   114,   115,   116,   117,   118,   -88,   -88,   -88,   -88,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -88,   -88,   115,   116,   117,   118
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-150))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-88))

static const yytype_int16 yycheck[] =
{
      15,    21,    28,    38,   153,    20,    38,    61,    62,    56,
      30,    15,    38,    40,    41,     0,    20,    30,    38,    22,
      31,    30,    49,   172,    46,     3,     4,     5,     6,     7,
      56,    41,     8,    44,    44,    11,    12,    13,    14,    15,
      87,    39,    89,    40,    41,    60,    36,    37,    28,    76,
      77,    78,    28,     3,     4,     5,     6,     7,    39,    28,
      44,    87,    44,    89,    40,    92,    93,    45,    40,    40,
      46,    47,    34,    35,    36,    37,    44,    40,    44,   133,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     8,    47,    40,    11,    12,    13,
      14,    15,    41,     8,    42,    11,    11,    12,    13,    14,
      15,    28,    41,    41,    28,    39,    28,    44,   153,   154,
      45,   153,   154,    28,    45,    45,    40,   153,   154,    45,
     157,   158,    46,   153,   154,     9,    12,   172,    31,    43,
     172,    46,    45,    40,    40,    10,   172,    17,    40,    40,
      95,   169,   172,    22,   169,    16,    17,    18,    19,    20,
      21,    16,    17,    18,    19,    20,    21,    20,   119,   156,
     158,    32,    33,    34,    35,    36,    37,    32,    33,    34,
      35,    36,    37,   172,    45,    -1,    -1,   154,    43,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      32,    33,    34,    35,    36,    37,    35,    -1,    -1,    38,
      42,    -1,    -1,    -1,    -1,    44,    45,    22,    23,    24,
      25,    26,    27,    28,    16,    17,    18,    19,    20,    21,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      32,    33,    34,    35,    36,    37,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     3,     4,     5,     6,     7,    51,
      53,    54,    55,    56,    60,    62,    30,    52,    39,    54,
      55,    61,    65,    51,    28,    63,    39,    65,    46,    66,
      61,    40,    41,    57,    64,    28,     8,    11,    12,    13,
      14,    15,    28,    40,    47,    66,    67,    69,    70,    71,
      72,    74,    76,    78,    79,    80,    88,    66,    22,    40,
      44,    44,    44,    66,    68,    69,    88,    91,    75,    22,
      23,    24,    25,    26,    27,    28,    35,    38,    44,    77,
      79,    81,    82,    83,    84,    83,    31,    40,    47,    40,
      83,    41,    73,    44,    67,    42,    45,    54,    58,    82,
      83,    82,    11,    28,    83,    83,    83,    16,    17,    18,
      19,    20,    21,    32,    33,    34,    35,    36,    37,    43,
      41,    85,    67,    67,    83,    45,    83,    86,    57,    39,
      45,    45,    45,    44,    45,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    77,    83,    42,
      43,    45,    28,     9,    12,    82,    42,    31,    87,    43,
      66,    68,    89,    90,    91,    45,    85,    83,    86,    59,
      40,    40,    10,    40,    40,    58,    66,    68,    90
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    {inicializa_dic_escopo_global();}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 133 "parser.y"
    {
		 if((yyvsp[(2) - (3)].tree_node) != NULL){//Se tiver funcoes...
			 comp_tree_t * nodo_programa = arvoreCriaNodo(1,IKS_AST_PROGRAMA);
			 arvoreInsereNodo(nodo_programa,(yyvsp[(2) - (3)].tree_node));
		 	 gv_declare(IKS_AST_PROGRAMA,(const void*)nodo_programa,NULL);
			 gv_connect(nodo_programa,(yyvsp[(2) - (3)].tree_node));
		 }
		 return IKS_SYNTAX_SUCESSO; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    {inicializa_dic_escopo_global();}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    {
		 		if((yyvsp[(1) - (3)].tree_node) != NULL && (yyvsp[(3) - (3)].tree_node) != NULL){
					arvoreInsereNodo((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
			  		(yyval.tree_node) = (yyvsp[(3) - (3)].tree_node);
					gv_connect((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
			  	}
		  		else
					(yyval.tree_node) = (yyvsp[(3) - (3)].tree_node);
   		 	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 151 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    {(yyval.tree_node) = NULL;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    {(yyval.tree_node) = NULL;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    {(yyval.tree_node) =   (yyvsp[(1) - (1)].tree_node);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    {(yyval.type_data) = IKS_INT;}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    {(yyval.type_data) = IKS_FLOAT;}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    {(yyval.type_data) = IKS_BOOL;}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    {(yyval.type_data) = IKS_CHAR;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    {(yyval.type_data) = IKS_STRING;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    {
									(yyvsp[(3) - (4)].symbol)->tipo_dado = (yyvsp[(1) - (4)].type_data);
									(yyvsp[(3) - (4)].symbol)->tipo_estrutura = IKS_TYPE_VARIABLE; //É uma variável simples...
									(yyvsp[(3) - (4)].symbol)->tamanho = sm_size_from_type_var((yyvsp[(1) - (4)].type_data));
									if(escopo_eh_local){//usar fp
										(yyvsp[(3) - (4)].symbol)->endereco = DESLOC_FRAME_POINTER;
										DESLOC_FRAME_POINTER += + (yyvsp[(3) - (4)].symbol)->tamanho;
									}
									else{//usar vp
										(yyvsp[(3) - (4)].symbol)->endereco = DESLOC_GLOBAL_VARIABLE_POINTER;
										DESLOC_GLOBAL_VARIABLE_POINTER += (yyvsp[(3) - (4)].symbol)->tamanho;
									}
								}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    {
								(yyvsp[(3) - (5)].symbol)->tipo_dado = (yyvsp[(1) - (5)].type_data);
								(yyvsp[(3) - (5)].symbol)->tipo_estrutura = IKS_TYPE_VECTOR;//É um vetor...
								(yyvsp[(3) - (5)].symbol)->lista_tamanhos_dimensao = (yyvsp[(4) - (5)].dim_lst);
								(yyvsp[(3) - (5)].symbol)->tamanho = sm_size_from_type_vec((yyvsp[(1) - (5)].type_data),(yyvsp[(4) - (5)].dim_lst));
								
								//ESCOPO eh sempre GLOBAL!!
								(yyvsp[(3) - (5)].symbol)->endereco = DESLOC_GLOBAL_VARIABLE_POINTER;
								DESLOC_GLOBAL_VARIABLE_POINTER += (yyvsp[(3) - (5)].symbol)->tamanho;
							}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    {
					(yyval.dim_lst) = sm_init_lista_dimensoes();
					(yyval.dim_lst) = sm_adiciona_dimensao((yyval.dim_lst),atoi((yyvsp[(2) - (3)].symbol)->chave));
				}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    {
							(yyval.dim_lst) = sm_adiciona_dimensao((yyvsp[(4) - (4)].dim_lst),atoi((yyvsp[(2) - (4)].symbol)->chave));
						}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 199 "parser.y"
    {sm_insere_lista_args((yyvsp[(1) - (3)].type_data),(yyvsp[(3) - (3)].symbol));(yyvsp[(3) - (3)].symbol)->tamanho = sm_size_from_type_var((yyvsp[(1) - (3)].type_data));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    {sm_insere_lista_args((yyvsp[(1) - (4)].type_data),(yyvsp[(3) - (4)].symbol));(yyvsp[(3) - (4)].symbol)->tamanho = sm_size_from_type_var((yyvsp[(1) - (4)].type_data));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    {
						(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_FUNCAO);/*PASS NODE UP*/
						(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (4)].symbol);
						arvoreInsereNodo((yyval.tree_node),(yyvsp[(4) - (4)].tree_node));
						gv_declare(IKS_AST_FUNCAO,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
						gv_connect((yyval.tree_node),(yyvsp[(4) - (4)].tree_node));
					 }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {
				/*Mesma coisa aqui...*/
				(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_FUNCAO);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (3)].symbol);
				arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
				gv_declare(IKS_AST_FUNCAO,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
				gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
			     }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    {passou_declaracoes_funcao = 1;}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    {(yyval.symbol) = sm_define_tipo_funcao((yyvsp[(1) - (7)].type_data),(yyvsp[(3) - (7)].symbol));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    {(yyval.symbol) = sm_define_tipo_funcao((yyvsp[(1) - (6)].type_data),(yyvsp[(3) - (6)].symbol));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 225 "parser.y"
    {pt_tabela_funcao = (yyvsp[(1) - (1)].symbol); (yyval.symbol) = (yyvsp[(1) - (1)].symbol);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    {inicializa_dic_escopo_local();}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    {
				comp_tree_t * nodo_bloco = arvoreCriaNodo(2,IKS_AST_BLOCO);//Filhos: comandos dentro do bloco e proximo comando.
				if((yyvsp[(2) - (3)].tree_node) != NULL)
					arvoreInsereNodo(nodo_bloco,(yyvsp[(2) - (3)].tree_node));//Insere o nodo vindo de comandos. 
				(yyval.tree_node) = nodo_bloco;
				gv_declare(IKS_AST_BLOCO,(const void*)(yyval.tree_node),NULL);
				if((yyvsp[(2) - (3)].tree_node) != NULL)
					gv_connect((yyval.tree_node),(yyvsp[(2) - (3)].tree_node));
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    {
			(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_BLOCO);//Somente um filho - o proximo comando, que sera definido um nivel acima.
			gv_declare(IKS_AST_BLOCO,(const void*)(yyval.tree_node),NULL);
	       }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    {
						if((yyvsp[(3) - (3)].tree_node) != NULL){
							arvoreInsereNodo((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_connect((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
							concatena_codigo(&((yyvsp[(1) - (3)].tree_node)->code), (yyvsp[(3) - (3)].tree_node)->code);
						}
						(yyval.tree_node) = (yyvsp[(1) - (3)].tree_node);
					}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 259 "parser.y"
    {
						if((yyvsp[(2) - (2)].tree_node) != NULL){
							arvoreInsereNodo((yyvsp[(1) - (2)].tree_node),(yyvsp[(2) - (2)].tree_node));
							gv_connect((yyvsp[(1) - (2)].tree_node),(yyvsp[(2) - (2)].tree_node));
							concatena_codigo(&((yyvsp[(1) - (2)].tree_node)->code), (yyvsp[(2) - (2)].tree_node)->code);
						}
						(yyval.tree_node) = (yyvsp[(1) - (2)].tree_node);
					}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 267 "parser.y"
    {
						(yyval.tree_node) = (yyvsp[(1) - (2)].tree_node);
					}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    {
						(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);//TODO: Passagem de labels...
					}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 273 "parser.y"
    {
						if((yyvsp[(3) - (3)].tree_node) != NULL){
							arvoreInsereNodo((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_connect((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
							concatena_codigo(&((yyvsp[(1) - (3)].tree_node)->code), (yyvsp[(3) - (3)].tree_node)->code);
						}
						(yyval.tree_node) = (yyvsp[(1) - (3)].tree_node);
					}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    {
						(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
					}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    {
						(yyval.tree_node) = NULL;				
					}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 289 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 290 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 293 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 294 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 295 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 296 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 297 "parser.y"
    {(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 337 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (2)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
							gv_declare(IKS_AST_ATRIBUICAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (2)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
							
							//Acoes semanticas...
							int has_to_convert = sm_atr_verify_coercion_possible((yyvsp[(1) - (2)].tree_node)->tipo_dado,(yyvsp[(2) - (2)].tree_node)->tipo_dado);//Determinar se deve ocorrer coercao.
						}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 349 "parser.y"
    {
													(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ATRIBUICAO);
													arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (6)].tree_node));
													arvoreInsereNodo((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
													arvoreInsereNodo((yyvsp[(2) - (6)].tree_node),(yyvsp[(1) - (6)].tree_node));
													arvoreInsereNodo((yyvsp[(2) - (6)].tree_node),(yyvsp[(3) - (6)].tree_node));

													gv_declare(IKS_AST_ATRIBUICAO,(const void*)(yyval.tree_node),NULL);
													gv_connect((yyval.tree_node),(yyvsp[(2) - (6)].tree_node));
													gv_connect((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
													gv_connect((yyvsp[(2) - (6)].tree_node),(yyvsp[(1) - (6)].tree_node));
													gv_connect((yyvsp[(2) - (6)].tree_node),(yyvsp[(3) - (6)].tree_node));
													sm_atr_verify_coercion_possible(IKS_INT,(yyvsp[(3) - (6)].tree_node)->tipo_dado);//TODO: coercao possivel nesse caso?
													int has_to_convert = sm_atr_verify_coercion_possible((yyvsp[(1) - (6)].tree_node)->tipo_dado,(yyvsp[(6) - (6)].tree_node)->tipo_dado);
								}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    {
							//Verificando que eh variavel...
							(void)sm_verify_if_variable((yyvsp[(1) - (2)].symbol));
							(yyval.tree_node) = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (2)].symbol);
							(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (2)].symbol)->tipo_dado;
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
						}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 375 "parser.y"
    {
							//Verificando que eh vetor...
							(void)sm_verify_if_vector((yyvsp[(1) - (1)].symbol));
							(yyval.tree_node) = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
							(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].symbol)->tipo_dado;
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
						}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 383 "parser.y"
    {
					(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_VETOR_INDEXADO);
					gv_declare(IKS_AST_VETOR_INDEXADO,(const void*)(yyval.tree_node),NULL);
				}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 389 "parser.y"
    {com_eh_input = 1;}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 389 "parser.y"
    {
						(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_INPUT);
						comp_tree_t* id = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
						id->pt_tabela = (void*)(yyvsp[(3) - (3)].symbol);
						arvoreInsereNodo((yyval.tree_node),id);
						gv_declare(IKS_AST_INPUT,(const void*)(yyval.tree_node),NULL);
						gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)id->pt_tabela)->chave);
						gv_connect((yyval.tree_node),id);
					}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 400 "parser.y"
    {
						(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_OUTPUT);
						arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
						
						gv_declare(IKS_AST_OUTPUT,(const void*)(yyval.tree_node),NULL);
						gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
					}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 409 "parser.y"
    {
								sm_testa_tipos_output((comp_dict_item_t*)((yyvsp[(1) - (1)].tree_node)->pt_tabela));
								(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
							}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 413 "parser.y"
    {
								sm_testa_tipos_output((comp_dict_item_t*)((yyvsp[(1) - (3)].tree_node)->pt_tabela));
								arvoreInsereNodo((yyvsp[(1) - (3)].tree_node),(yyvsp[(3) - (3)].tree_node));
								(yyval.tree_node) = (yyvsp[(1) - (3)].tree_node);
								
								gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 422 "parser.y"
    {
					int ret_coerc = sm_ret_verify_return_type(pt_tabela_funcao->tipo_dado,(yyvsp[(2) - (2)].tree_node)->tipo_dado);
					(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_RETURN);
					arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
					gv_declare(IKS_AST_RETURN,(const void*)(yyval.tree_node),NULL);
					gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 431 "parser.y"
    { 	sm_testa_qnt_args_missing((comp_dict_item_t*)((yyvsp[(1) - (4)].tree_node)->pt_tabela));
									(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);
									arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (4)].tree_node));
									arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (4)].tree_node));
									(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (4)].tree_node)->tipo_dado;
									gv_declare(IKS_AST_CHAMADA_DE_FUNCAO,(const void*)(yyval.tree_node),NULL);
									gv_connect((yyval.tree_node),(yyvsp[(1) - (4)].tree_node));
									gv_connect((yyval.tree_node),(yyvsp[(3) - (4)].tree_node));
								}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 440 "parser.y"
    {
							sm_testa_qnt_args_missing((comp_dict_item_t*)((yyvsp[(1) - (3)].tree_node)->pt_tabela));
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_CHAMADA_DE_FUNCAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (3)].tree_node)->tipo_dado;
							gv_declare(IKS_AST_CHAMADA_DE_FUNCAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
						}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 448 "parser.y"
    {
						(yyval.tree_node) = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
						(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
						(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].symbol)->tipo_dado;
						gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);

						//Etapa 4
						contador_args_chamada_funcao = 0;//Conta quantos argumentos estao sendo chamados na
						pt_tabela_fun_chamada = (yyvsp[(1) - (1)].symbol);
					}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 460 "parser.y"
    { 
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ARIM_SOMA);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_ARIM_SOMA,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							
							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_ADD,(yyval.tree_node));
						}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 471 "parser.y"
    { 
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ARIM_SUBTRACAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_ARIM_SUBTRACAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_SUB,(yyval.tree_node));
						}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    { 
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ARIM_MULTIPLICACAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_ARIM_MULTIPLICACAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_MULT,(yyval.tree_node));
						}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 493 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_ARIM_DIVISAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_ARIM_DIVISAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_DIV,(yyval.tree_node));

						}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 505 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_ARIM_INVERSAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
							gv_declare(IKS_AST_ARIM_INVERSAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));

							(yyval.tree_node)->tipo_dado = (yyvsp[(2) - (2)].tree_node)->tipo_dado;
							//TODO: inversao $$->code = geraCodigoExpr($$->code,$1->code,$3->code,ILOC_ADD/*??*/,$$);

						}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 517 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_LE);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_LE,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
				
							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_LE,(yyval.tree_node));
						}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 528 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_GE);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_GE,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_GE,(yyval.tree_node));
						}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 539 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_L);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_L,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_LT,(yyval.tree_node));
						}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 550 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_G);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_G,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_GT,(yyval.tree_node));
						}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 561 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_IGUAL);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_IGUAL,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_EQ,(yyval.tree_node));
						}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 572 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_COMP_DIF);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_DIF,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_CMP_NE,(yyval.tree_node));
						}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 583 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_E);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_E,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_AND,(yyval.tree_node));

							
						}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 596 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_LOGICO_OU);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));
							gv_declare(IKS_AST_LOGICO_OU,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(1) - (3)].tree_node));
							gv_connect((yyval.tree_node),(yyvsp[(3) - (3)].tree_node));

							(yyval.tree_node)->tipo_dado = sm_infer_type_from_expr((yyvsp[(1) - (3)].tree_node)->tipo_dado,(yyvsp[(3) - (3)].tree_node)->tipo_dado);
							(yyval.tree_node)->code = geraCodigoExpr((yyval.tree_node)->code,(yyvsp[(1) - (3)].tree_node)->code,(yyvsp[(3) - (3)].tree_node)->code,ILOC_OR,(yyval.tree_node));

							
							
						}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 610 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(2,IKS_AST_LOGICO_COMP_NEGACAO);
							arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
							gv_declare(IKS_AST_LOGICO_COMP_NEGACAO,(const void*)(yyval.tree_node),NULL);
							gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));

							(yyval.tree_node)->tipo_dado = (yyvsp[(2) - (2)].tree_node)->tipo_dado;
							//$$->code = geraCodigoExpr($$->code,$1->code,$3->code,ILOC_ADD/*??*/,$$);
						}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 621 "parser.y"
    {	(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
					(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].tree_node)->tipo_dado;

					/*
					 *	CODE
					 */

					(yyval.tree_node)->code = (yyvsp[(1) - (1)].tree_node)->code;//Pode dar problema caso se queira "passar" pelo codigo do nodo $1.
				}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 630 "parser.y"
    {	(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
					(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].tree_node)->tipo_dado;

					/*
					 *	CODE
					 */

					(yyval.tree_node)->code = (yyvsp[(1) - (1)].tree_node)->code;
				}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 639 "parser.y"
    {
					(yyval.tree_node) = (yyvsp[(2) - (3)].tree_node);
					(yyval.tree_node)->tipo_dado = (yyvsp[(2) - (3)].tree_node)->tipo_dado;
					/*
					 *	CODE
					 */

					(yyval.tree_node)->code = (yyvsp[(2) - (3)].tree_node)->code;
				}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 648 "parser.y"
    {
								(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_VETOR_INDEXADO);
								arvoreInsereNodo((yyval.tree_node),(yyvsp[(1) - (2)].tree_node));
								arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
	
								gv_declare(IKS_AST_VETOR_INDEXADO,(const void*)(yyval.tree_node),NULL);
								gv_connect((yyval.tree_node),(yyvsp[(1) - (2)].tree_node));
								gv_connect((yyval.tree_node),(yyvsp[(2) - (2)].tree_node));
								(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (2)].tree_node)->tipo_dado;
								
								//Definir .code aqui!
								calc_idx_expr_addr((yyval.tree_node),(yyvsp[(1) - (2)].tree_node),(yyvsp[(2) - (2)].tree_node));
							}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 661 "parser.y"
    {
					(yyval.tree_node) = arvoreCriaNodo(1/*pode ter mais!*/,IKS_AST_IDENTIFICADOR);
					(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
					(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].symbol)->tipo_dado;
					gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);

					/*
					 *	CODE
					 */
					int endereco_variavel;
					if((yyvsp[(1) - (1)].symbol)->escopo_eh_global){
						endereco_variavel = (yyvsp[(1) - (1)].symbol)->endereco + base_global;//TODO::????
					}
					else{
						endereco_variavel = (yyvsp[(1) - (1)].symbol)->endereco + base_local;//TODO::????
					}
					(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_LOAD,endereco_variavel,-1,ILOC_reg()));
				}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 679 "parser.y"
    {	
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_INT;
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);

					/*
					 *	CODE
					 */
				(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_LOAD_I,atoi(((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave),-1,ILOC_reg()));//Carrega inteiro num novo registrador...
			}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 690 "parser.y"
    {
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_BOOL;
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
					/*
					 *	CODE
					 */
				(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_C_LOAD_AI,1/*carrega '1' - true*/,-1,ILOC_reg()));//Carrega inteiro num novo registrador...
			}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 700 "parser.y"
    {	
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_BOOL;
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
					/*
					 *	CODE
					 */
				(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_C_LOAD_AI,0/*carrega '0' - false*/,-1,ILOC_reg()));//Carrega inteiro num novo registrador...
			}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 710 "parser.y"
    {	
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_FLOAT;
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
					/*
					 *	CODE
					 */
				//Indefinido???
				//TODO: revisar floats!!!!
				(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_LOAD_I,(int)(atof(((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave)),-1,ILOC_reg()));//Carrega inteiro num novo registrador...

			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 723 "parser.y"
    {	(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
					(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].tree_node)->tipo_dado;
					/*
					 *	CODE
					 */
					(yyval.tree_node)->code = (yyvsp[(1) - (1)].tree_node)->code;
				}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 730 "parser.y"
    {
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_STRING;

				//Adaptando a string de saida ao formato desejado...
				char * str_ptr = ((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave;
				char chave[strlen(str_ptr)+3];//Contando-se o '\0' e mais duas barras '\\'
				chave[0] = '\\';
				chave[1] = '\"';
				strcpy(chave+2,str_ptr+1);
				int pos = strlen(chave);
				chave[pos - 1] = '\\';
				chave[pos] = '\"';
				chave[pos + 1] = '\0';
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),chave);

					/*
					 *	CODE
					 */
					//TODO: O que fazer???

			}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 753 "parser.y"
    {	
				(yyval.tree_node) = arvoreCriaNodo(1,IKS_AST_LITERAL);
				(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
				(yyval.tree_node)->tipo_dado = IKS_CHAR;
				gv_declare(IKS_AST_LITERAL,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);

					/*
					 *	CODE
					 */
				//TODO: qual 
				(yyval.tree_node)->code = ILOC_add_to_list((yyval.tree_node)->code,ILOC_create_operation(ILOC_C_LOAD_AI,(((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave[1]),-1,ILOC_reg()));//Carrega inteiro num novo registrador...

			}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 767 "parser.y"
    {
							(yyval.tree_node) = arvoreCriaNodo(0,IKS_AST_IDENTIFICADOR);
							(yyval.tree_node)->pt_tabela = (void*)(yyvsp[(1) - (1)].symbol);
							gv_declare(IKS_AST_IDENTIFICADOR,(const void*)(yyval.tree_node),((comp_dict_item_t*)(yyval.tree_node)->pt_tabela)->chave);
							(yyval.tree_node)->tipo_dado = (yyvsp[(1) - (1)].symbol)->tipo_dado;//Olha a partir do tipo da tabela de simbolos.
						}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 774 "parser.y"
    {
								(yyval.tree_node) = (yyvsp[(2) - (3)].tree_node);
						}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 778 "parser.y"
    {
								(yyval.tree_node) = (yyvsp[(2) - (4)].tree_node);
								arvoreInsereNodo((yyval.tree_node),(yyvsp[(4) - (4)].tree_node));
								gv_connect((yyval.tree_node),(yyvsp[(4) - (4)].tree_node));
						}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 787 "parser.y"
    {//Ultima expressao reconhecida, agora "subiremos" na arvore de derivacao testando cada tipo de argumento com as acoes da proxima regra.
					(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
					contador_args_chamada_funcao++;
					contador_regressivo_args_chamada_funcao = contador_args_chamada_funcao;
					sm_testa_qnt_args_excess_and_type(pt_tabela_fun_chamada,(yyvsp[(1) - (1)].tree_node));
				}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 793 "parser.y"
    {contador_args_chamada_funcao++;}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 793 "parser.y"
    {
												(yyval.tree_node) = (yyvsp[(1) - (4)].tree_node);
												arvoreInsereNodo((yyvsp[(1) - (4)].tree_node),(yyvsp[(4) - (4)].tree_node));
												gv_connect((yyval.tree_node),(yyvsp[(4) - (4)].tree_node));
												sm_testa_qnt_args_excess_and_type(pt_tabela_fun_chamada,(yyvsp[(1) - (4)].tree_node));
											}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 801 "parser.y"
    {
										(yyval.tree_node) = arvoreCriaNodo(4,IKS_AST_IF_ELSE);
										arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));//Condicao
										arvoreInsereNodo((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));//Comando, se verdade
										(yyval.tree_node)->filhos[2] = NULL;//Comando, se falso //TODO : REVIEW THIS!!!!
										gv_declare(IKS_AST_IF_ELSE,(const void*)(yyval.tree_node),NULL);
										gv_connect((yyval.tree_node),(yyvsp[(3) - (6)].tree_node));
										gv_connect((yyval.tree_node),(yyvsp[(6) - (6)].tree_node));
									}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 810 "parser.y"
    { 
												(yyval.tree_node) = arvoreCriaNodo(4,IKS_AST_IF_ELSE);
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (8)].tree_node));//Condicao
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(6) - (8)].tree_node));//Comando, se verdade
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(8) - (8)].tree_node));//Comando, se falso
												gv_declare(IKS_AST_IF_ELSE,(const void*)(yyval.tree_node),NULL);
												gv_connect((yyval.tree_node),(yyvsp[(3) - (8)].tree_node));
												gv_connect((yyval.tree_node),(yyvsp[(6) - (8)].tree_node));
												gv_connect((yyval.tree_node),(yyvsp[(8) - (8)].tree_node));
											}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 820 "parser.y"
    {
												(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_WHILE_DO);
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(3) - (7)].tree_node));//Condicao
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(6) - (7)].tree_node));//Comando
												gv_declare(IKS_AST_WHILE_DO,(const void*)(yyval.tree_node),NULL);
												gv_connect((yyval.tree_node),(yyvsp[(3) - (7)].tree_node));
												gv_connect((yyval.tree_node),(yyvsp[(6) - (7)].tree_node));
											}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 828 "parser.y"
    {
												(yyval.tree_node) = arvoreCriaNodo(3,IKS_AST_DO_WHILE);
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(2) - (7)].tree_node));//Comando
												arvoreInsereNodo((yyval.tree_node),(yyvsp[(5) - (7)].tree_node));//Condicao
												gv_declare(IKS_AST_DO_WHILE,(const void*)(yyval.tree_node),NULL);
												gv_connect((yyval.tree_node),(yyvsp[(2) - (7)].tree_node));
												gv_connect((yyval.tree_node),(yyvsp[(5) - (7)].tree_node));
											}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 838 "parser.y"
    {
			(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
		}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 841 "parser.y"
    {
			(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 844 "parser.y"
    {
				(yyval.tree_node) = (yyvsp[(1) - (2)].tree_node);
			}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 847 "parser.y"
    {
				(yyval.tree_node) = (yyvsp[(1) - (2)].tree_node);
			}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 851 "parser.y"
    {
					(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
				}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 854 "parser.y"
    {
					(yyval.tree_node) = (yyvsp[(1) - (1)].tree_node);
				}
    break;



/* Line 1806 of yacc.c  */
#line 2876 "/home/rafael/UFRGS - ENGENHARIA DE COMPUTACAO/ETAPA 07/INF01147 - Compiladores/Final/TrabalhoCompiladores/build/parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 858 "parser.y"


int yyerror (char const *mensagem)
{
  fprintf (stderr, "ERRO %s na linha: %d\n",mensagem,yylineno);
  return IKS_SYNTAX_ERRO;
}

int sm_size_from_type_var(int type){
	switch(type){
		case IKS_INT:		{return IKS_SIZE_INT;}
		case IKS_FLOAT:		{return	IKS_SIZE_FLOAT;}
		case IKS_CHAR:		{return IKS_SIZE_CHAR;}
		case IKS_BOOL:		{return IKS_SIZE_BOOL;}
		case IKS_STRING:	{return 0;}//TODO: CUIDAR COM AS STRINGS!
		default:{
			fprintf(stderr, "ERRO : tipo informado inexistente...\n");
			exit(200);//TODO: o que fazer neste caso??
		} 
	};
}

inline int sm_size_from_type_vec(int type,comp_list_t* dim_lst){
	int length = listaCalculaProduto(dim_lst);
	switch(type){
		case IKS_INT:		{return IKS_SIZE_VECTOR_INT(length);}
		case IKS_FLOAT:		{return	IKS_SIZE_VECTOR_FLOAT(length);}
		case IKS_CHAR:		{return IKS_SIZE_VECTOR_CHAR(length);}
		case IKS_BOOL:		{return IKS_SIZE_VECTOR_BOOL(length);}
		case IKS_STRING:	{return 0;}//TODO: CUIDAR COM AS STRINGS!
		default:{
			fprintf(stderr, "ERRO : tipo informado inexistente...\n");
			exit(200);//TODO: o que fazer neste caso??
		} 
	};
}

inline int sm_infer_type_from_expr(int tau_one, int tau_two){

	switch(tau_one){
		case IKS_STRING:{if(tau_two == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_STRING_TO_X);}
		case IKS_CHAR:	{if(tau_two == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_CHAR_TO_X);  }
		default:{
			if(tau_two == IKS_STRING)
				exit(IKS_ERROR_STRING_TO_X);
			if(tau_two == IKS_CHAR)
				exit(IKS_ERROR_CHAR_TO_X);
			if(tau_two == IKS_FLOAT)
				return IKS_FLOAT;
			if(tau_two == IKS_INT)
				return IKS_INT;
			return IKS_BOOL;
		}
	};
}

/*
 *	Funcao que determina a possibilidade de coercao de valores em atribuicoes.
 */
int sm_atr_verify_coercion_possible(int type_var,int type_value){
	switch(type_var){
		case IKS_STRING:{if(type_value == IKS_STRING) return IKS_STRING; else 
											{
												if(type_value != IKS_CHAR)
													exit(IKS_ERROR_WRONG_TYPE);
												exit(IKS_ERROR_CHAR_TO_X);
											}}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(type_value == IKS_CHAR)   return IKS_CHAR;   else
											{
												if(type_value != IKS_STRING)
													exit(IKS_ERROR_WRONG_TYPE);  
												exit(IKS_ERROR_STRING_TO_X);
											}}
		default:{
			if(type_value == IKS_STRING)
				exit(IKS_ERROR_STRING_TO_X);
			if(type_value == IKS_CHAR)
				exit(IKS_ERROR_CHAR_TO_X);
			return type_var; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};

}

/*
 *	Verificacao do tipo do argumento de retorno de funcao.
 */
inline int sm_ret_verify_return_type(int fun_ret_type,int return_var_type){
	switch(fun_ret_type){
		case IKS_STRING:{if(return_var_type == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_WRONG_PAR_RETURN);}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(return_var_type == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_WRONG_PAR_RETURN);  }
		default:{
			if(return_var_type == IKS_STRING)
				exit(IKS_ERROR_WRONG_PAR_RETURN);
			if(return_var_type == IKS_CHAR)
				exit(IKS_ERROR_WRONG_PAR_RETURN);
			return fun_ret_type; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};
}

inline void sm_verify_if_variable(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_VARIABLE){
		if(item->tipo_estrutura == IKS_TYPE_VECTOR)
			exit(IKS_ERROR_VECTOR);//Caso em que se esta utilizando como variavel um identificador de um dado do tipo vetor.
		exit(IKS_ERROR_FUNCTION);
	}
}

inline void sm_verify_if_vector(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_VECTOR){
		if(item->tipo_estrutura == IKS_TYPE_VARIABLE)
			exit(IKS_ERROR_VARIABLE);
		exit(IKS_ERROR_FUNCTION);
	}
}

inline void sm_verify_if_function(comp_dict_item_t* item){
	if(item->tipo_estrutura != IKS_TYPE_FUNCTION){
		if(item->tipo_estrutura == IKS_TYPE_VARIABLE)
			exit(IKS_ERROR_VARIABLE);
		exit(IKS_ERROR_VECTOR);
	}
}

inline void inicializa_dic_escopo_global(){
	dicionario_atual = dicionario_escopo_global;
	escopo_eh_local = 0;
	passou_declaracoes_funcao = 0;
//Etapa 5 - inicializando fp e vp
	DESLOC_GLOBAL_VARIABLE_POINTER = 0;
	DESLOC_FRAME_POINTER = 0;	
}

inline void inicializa_dic_escopo_local(){
	escopo_eh_local = 1;
	passou_declaracoes_funcao = 0;
	dicionario_escopo_global = dicionario_atual;
	dicionarioRemove(&dicionario_escopo_local);
	dicionario_atual = dicionario_escopo_local;
//Etapa 5 - inicializando fp
	DESLOC_FRAME_POINTER = 0;

}

//Funcao que testa se o tipo do argumento utilizado num comando output eh correto.
inline void sm_testa_tipos_output(comp_dict_item_t* item){
	if(item->tipo_dado == IKS_CHAR)//Com os tipos atuais, unico caso onde a funcao nao esta definida
		exit(IKS_ERROR_WRONG_PAR_OUTPUT);
}

inline comp_dict_item_t* sm_define_tipo_funcao(int tipo_funcao, comp_dict_item_t* pt_tabela){
	pt_tabela_funcao = pt_tabela;
	pt_tabela->tipo_dado = tipo_funcao;
	pt_tabela->tipo_estrutura = IKS_TYPE_FUNCTION;
	return pt_tabela;
}

inline void sm_insere_lista_args(int tipo,comp_dict_item_t* pt_id){
	listaInsereNodo(&(pt_tabela_funcao->lista_args_funcao),listaCriaNodo(tipo));
	pt_id->tipo_dado = tipo;
	pt_id->tipo_estrutura = IKS_TYPE_VARIABLE;
}

inline void sm_testa_qnt_args_missing(comp_dict_item_t* fun){
	if(contador_args_chamada_funcao < listaQtdeNodos(fun->lista_args_funcao))
		exit(IKS_ERROR_MISSING_ARGS);
}
inline int sm_fun_call_type_verify_coercion(int fun_arg_type,int expr_type){
	switch(fun_arg_type){
		case IKS_STRING:{if(expr_type == IKS_STRING) return IKS_STRING; else exit(IKS_ERROR_WRONG_TYPE_ARGS);}//TODO: ou seria IKS_ERROR_WRONG_TYPE??
		case IKS_CHAR:  {if(expr_type == IKS_CHAR)   return IKS_CHAR;   else exit(IKS_ERROR_WRONG_TYPE_ARGS);}
		default:{
			if(expr_type == IKS_STRING)
				exit(IKS_ERROR_WRONG_TYPE_ARGS);
			if(expr_type == IKS_CHAR)
				exit(IKS_ERROR_WRONG_TYPE_ARGS);
			return fun_arg_type; //Fazer a coercao para qualquer tipo que seja, ja que qualquer uma eh possivel.
		}
	};
} 
inline void sm_testa_qnt_args_excess_and_type(comp_dict_item_t* fun,comp_tree_t* expr){
	if(contador_args_chamada_funcao > listaQtdeNodos(fun->lista_args_funcao))
		exit(IKS_ERROR_EXCESS_ARGS);
	contador_regressivo_args_chamada_funcao--;
	sm_fun_call_type_verify_coercion((listaRetornaNodoIdx(fun->lista_args_funcao,contador_regressivo_args_chamada_funcao))->info,expr->tipo_dado);
	
}

//ETAPA 5

inline comp_list_t* sm_init_lista_dimensoes(){
	return listaCria();
}

inline comp_list_t* sm_adiciona_dimensao(comp_list_t* lst,int t_dim){
	if(t_dim < 1)
		exit(IKS_ERROR_DIM_NOT_POSITIVE);
	return listaAdicionaNodo_Inicio(lst,listaCriaNodo(t_dim));//Adiciona novo elemento ao inicio da lista.
}


ILOC_OP_LIST * geraCodigoExpr(ILOC_OP_LIST * res_list, ILOC_OP_LIST * l1, ILOC_OP_LIST * l2, int operation, comp_tree_t* node){
	res_list = ILOC_concat_lists(res_list,l1);
	res_list = ILOC_concat_lists(res_list,l2);
	res_list = ILOC_add_to_list(res_list,ILOC_create_operation(operation,l1->last->result_operand,l2->last->result_operand,l2->last->result_operand));
	node->result_reg = l2->last->result_operand;
	return res_list;
}

void concatena_codigo(ILOC_OP_LIST ** l1, ILOC_OP_LIST *l2){
	*l1 = ILOC_concat_lists(*l1,l2);
}



void calc_idx_expr_addr(comp_tree_t* vec, comp_tree_t* id, comp_tree_t* index){
	comp_list_t* list_idx = ((comp_dict_item_t*)id->pt_tabela)->lista_tamanhos_dimensao;//Lista de tamanhos de indices.
	ILOC_OP_LIST* p_list_aux;//Var. auxiliar para pegar o codigo das expressoes.
	
	int num_dimensions = listaQtdeNodos(list_idx);
	
	if(list_idx == NULL){
		printf(stderr,"ERROR: dimension list is null!\n");
		exit(IKS_FATAL_ERROR);
	}
	if(index == NULL){
		printf(stderr,"ERROR: index list is null!\n");
		exit(IKS_FATAL_ERROR);
	}
	ILOC_OP_LIST * idx_code_list = ILOC_create_operation_list();//Variavel onde sera colocado o codigo final.
	//Aloca registrador para receber o resultado
		int RESULT_REGISTER = ILOC_reg();

	p_list_aux = index->code;//TODO: funcao que calcula a proxima expr...
	idx_code_list = ILOC_concat_lists(idx_code_list,p_list_aux);
	idx_code_list->last->result_operand = RESULT_REGISTER;//Resultado do primeiro indice, ver se tem mais
	
	index = arvorePegaUltimoFilho(index);
	
	int idx = 1;	
	
	while(index != NULL){
		p_list_aux = index->code;//Pega codigo da expressao...
		//idx_code_list->last->result_reg

		int size_dim = listaRetornaNodoIdx(list_idx,idx)->info;//Calcula o tamanho da dimensao

		idx_code_list = ILOC_add_to_list(idx_code_list, ILOC_create_operation(ILOC_MULT_I,RESULT_REGISTER,size_dim,RESULT_REGISTER));//Multiplica pelo tamanho indicado
		idx_code_list = ILOC_concat_lists(idx_code_list,p_list_aux);//Copia codigo da expressao...		
		idx_code_list = ILOC_add_to_list(idx_code_list, ILOC_create_operation(ILOC_ADD,RESULT_REGISTER,idx_code_list->last->result_operand,RESULT_REGISTER));//Soma valor do resultado
		index = arvorePegaUltimoFilho(index);

		idx++;
	}
	
	if(idx != num_dimensions){
		printf(stderr,"ERROR: using wrong quantity of dimensions on indexed vector!\n");
		exit(IKS_FATAL_ERROR);
	}
	idx_code_list = ILOC_add_to_list(idx_code_list, ILOC_create_operation(ILOC_MULT_I,RESULT_REGISTER,sm_size_from_type_var(id->tipo_dado),RESULT_REGISTER));//Multiplica pelo tamanho da variavel indicado
	idx_code_list = ILOC_add_to_list(idx_code_list, ILOC_create_operation(ILOC_ADD_I,RESULT_REGISTER,((comp_dict_item_t*)id->pt_tabela)->endereco,RESULT_REGISTER));//Soma a base.

	vec->result_reg = RESULT_REGISTER;
	vec->code = idx_code_list;
}


ILOC_OP_LIST* geraCodigoExprShortCircuit(int label_true, int label_false, int operation){
	switch(operation){
		case ILOC_AND:{
			//se primeiro eh falso, falso
		}
		case ILOC_OR:{
			//se primeiro eh verdade, verdade
		}
		default:{
			printf(stderr,"ERROR: operation not available for short-circuiting!\n");
			exit(IKS_FATAL_ERROR);
		}
	};
}










