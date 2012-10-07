
/*  A Bison parser, made from parcer.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INT	258
#define	EOL	259
#define	DEF	260
#define	END	261
#define	WHILE	262
#define	DO	263
#define	UNTIL	264
#define	CLASS	265
#define	SELF	266
#define	SUPER	267
#define	RETURN	268
#define	ID_CAP	269
#define	ID_LOW	270
#define	ID_FUNC	271
#define	ID_VAR_FIELD	272
#define	EQUAL	273
#define	UMINUS	274

#line 1 "parcer.y"

#include <stdio.h>
#include <malloc.h>
void yyerror(char const *s);
extern int yylex(void);


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		143
#define	YYFLAG		-32768
#define	YYNTBASE	31

#define YYTRANSLATE(x) ((unsigned)(x) <= 274 ? yytranslate[x] : 50)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
    24,    21,    20,    30,    19,    29,    22,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
    27,    26,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    23
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     3,     5,     7,     9,    14,    19,    24,    29,
    34,    39,    44,    49,    52,    58,    60,    62,    64,    66,
    68,    72,    74,    76,    77,    79,    81,    85,    87,    89,
    91,    93,    95,    98,    99,   101,   103,   107,   112,   116,
   128,   137,   139,   141,   143,   144,   146,   148,   153,   162,
   174,   183,   195,   206
};

static const short yyrhs[] = {    40,
     0,     0,     4,     0,    14,     0,    15,     0,    34,    20,
    32,    34,     0,    34,    19,    32,    34,     0,    34,    21,
    32,    34,     0,    34,    22,    32,    34,     0,    34,    25,
    32,    34,     0,    34,    26,    32,    34,     0,    34,    18,
    32,    34,     0,    34,    27,    32,    34,     0,    19,    34,
     0,    28,    32,    34,    32,    24,     0,     3,     0,    35,
     0,    42,     0,    11,     0,    36,     0,    35,    29,    36,
     0,    33,     0,    17,     0,     0,    38,     0,    34,     0,
    37,    30,    34,     0,    34,     0,    43,     0,    49,     0,
    47,     0,    48,     0,    13,    37,     0,     0,    41,     0,
    39,     0,    40,     4,    39,     0,    44,    28,    37,    24,
     0,    33,    29,    42,     0,     5,    32,    44,    28,    45,
    32,    24,    32,    40,    32,     6,     0,     5,    32,    44,
    45,     4,    40,    32,     6,     0,    33,     0,    16,     0,
    12,     0,     0,    46,     0,    15,     0,    45,    30,    32,
    15,     0,     7,    32,    34,     8,    32,    40,    32,     6,
     0,     7,    32,    28,    32,    34,    32,    24,     4,    40,
    32,     6,     0,     9,    32,    34,     8,    32,    40,    32,
     6,     0,     9,    32,    28,    32,    34,    32,    24,     4,
    40,    32,     6,     0,    10,    32,    14,    25,    32,    14,
     4,    40,    32,     6,     0,    10,    32,    14,     4,    40,
    32,     6,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    49,    51,    52,    55,    56,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    75,
    76,    79,    80,    83,    84,    87,    88,    91,    92,    93,
    94,    95,    96,    99,   100,   103,   104,   107,   108,   112,
   113,   116,   117,   118,   121,   122,   125,   126,   129,   130,
   133,   134,   137,   138
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","EOL",
"DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID_CAP","ID_LOW",
"ID_FUNC","ID_VAR_FIELD","EQUAL","'-'","'+'","'*'","'/'","UMINUS","')'","'<'",
"'>'","'='","'('","'.'","','","program","eln","id","expr","var_id","var_id_simple",
"expr_seq","expr_seqE","stmt","stmt_seq","stmt_seqE","method_call","method_def",
"method_id","method_def_param_seq","method_def_param_seqE","while_stmt","until_stmt",
"class_def",""
};
#endif

static const short yyr1[] = {     0,
    31,    32,    32,    33,    33,    34,    34,    34,    34,    34,
    34,    34,    34,    34,    34,    34,    34,    34,    34,    35,
    35,    36,    36,    37,    37,    38,    38,    39,    39,    39,
    39,    39,    39,    40,    40,    41,    41,    42,    42,    43,
    43,    44,    44,    44,    45,    45,    46,    46,    47,    47,
    48,    48,    49,    49
};

static const short yyr2[] = {     0,
     1,     0,     1,     1,     1,     4,     4,     4,     4,     4,
     4,     4,     4,     2,     5,     1,     1,     1,     1,     1,
     3,     1,     1,     0,     1,     1,     3,     1,     1,     1,
     1,     1,     2,     0,     1,     1,     3,     4,     3,    11,
     8,     1,     1,     1,     0,     1,     1,     4,     8,    11,
     8,    11,    10,     7
};

static const short yydefact[] = {    34,
    16,     2,     2,     2,     2,    19,    44,    24,     4,     5,
    43,    23,     0,     2,    22,    28,    17,    20,    36,     1,
    35,    18,    29,     0,    31,    32,    30,     3,     0,     0,
     0,     0,    26,    33,    25,    14,     0,     0,     2,     2,
     2,     2,     2,     2,     2,     2,     0,     0,    24,    42,
    45,     2,     0,     2,     0,     0,     0,     2,    42,    39,
     0,     0,     0,     0,     0,     0,     0,     0,    22,    21,
    37,     0,    47,    45,     0,    46,     0,     2,     0,     2,
    34,     2,    27,     0,    12,     7,     6,     8,     9,    10,
    11,    13,    38,     2,    34,     2,     2,    34,     2,    34,
     2,     0,    15,     0,     2,     0,     0,     2,     0,     2,
     3,     0,     0,     2,     0,    48,    15,     0,    15,     0,
    54,    34,    34,    41,    34,    49,    34,    51,     2,     2,
     2,     2,     0,     0,     0,     0,    53,    40,    50,    52,
     0,     0,     0
};

static const short yydefgoto[] = {   141,
    29,    15,    16,    17,    18,    34,    35,    19,    20,    21,
    22,    23,    24,    75,    76,    25,    26,    27
};

static const short yypact[] = {   127,
-32768,     8,     8,     8,     8,-32768,-32768,   105,-32768,-32768,
-32768,-32768,   105,     8,    17,   194,   -14,-32768,-32768,    12,
-32768,-32768,-32768,     7,-32768,-32768,-32768,-32768,   135,   142,
   157,    36,   194,    23,-32768,    74,   105,   135,     8,     8,
     8,     8,     8,     8,     8,     8,    69,   127,   105,-32768,
    19,     8,   169,     8,   184,     5,   105,     2,    35,-32768,
   105,   105,   105,   105,   105,   105,   105,   105,-32768,-32768,
-32768,    24,-32768,    50,     1,-32768,   105,     8,   105,     8,
   127,     8,   194,    45,   194,    -8,    -8,    74,    74,   194,
   194,   194,-32768,     3,   127,     8,     2,   127,     2,   127,
    62,    56,-32768,    49,    62,    61,    54,    62,    57,    62,
   127,    82,    86,     8,    89,-32768,    93,    97,   100,   107,
-32768,   127,   127,-32768,   127,-32768,   127,-32768,    62,    62,
    62,    62,   109,   112,   117,   119,-32768,-32768,-32768,-32768,
   106,   131,-32768
};

static const short yypgoto[] = {-32768,
    -3,    42,    -5,-32768,    88,    99,-32768,   -44,   -13,-32768,
   114,-32768,   133,    90,-32768,-32768,-32768,-32768
};


#define	YYLAST		221


static const short yytable[] = {    30,
    31,    32,    33,    71,    95,    28,    28,    36,    81,    39,
    37,    28,    42,    43,    47,    48,    44,    45,    46,    39,
    40,    41,    42,    43,    53,    55,    44,    45,    46,    82,
    96,    58,    96,    73,    49,    61,    62,    63,    64,    65,
    66,    67,    68,    33,   -42,    38,    74,    93,    77,    56,
    79,    83,    57,    57,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    38,    73,   111,    71,   101,   103,   113,
    50,    97,   114,    99,    98,   116,   100,   117,   102,    59,
   119,   105,     9,    10,   108,    12,   110,   121,    69,   122,
   104,    39,   106,   107,   124,   109,   125,   112,    44,    45,
    46,   115,   126,   127,   118,   142,   120,     1,   129,   130,
   123,   131,   128,   132,   137,     6,     7,   138,     9,    10,
    11,    12,   139,    13,   140,   133,   134,   135,   136,     1,
   143,     2,    14,     3,    70,     4,     5,     6,     7,     8,
     9,    10,    11,    12,     1,    13,     7,    72,     9,    10,
    11,    60,     6,     7,    14,     9,    10,    11,    12,     1,
    13,    51,     0,    94,     0,     0,     0,     6,     7,    52,
     9,    10,    11,    12,     0,    13,    78,     0,     0,     0,
     0,     0,     0,     0,    54,     0,    39,    40,    41,    42,
    43,    80,     0,    44,    45,    46,     0,     0,     0,     0,
     0,    39,    40,    41,    42,    43,     0,     0,    44,    45,
    46,    39,    40,    41,    42,    43,     0,     0,    44,    45,
    46
};

static const short yycheck[] = {     3,
     4,     5,     8,    48,     4,     4,     4,    13,     4,    18,
    14,     4,    21,    22,    29,     4,    25,    26,    27,    18,
    19,    20,    21,    22,    30,    31,    25,    26,    27,    25,
    30,    37,    30,    15,    28,    39,    40,    41,    42,    43,
    44,    45,    46,    49,    28,    29,    28,    24,    52,    14,
    54,    57,    30,    30,    58,    61,    62,    63,    64,    65,
    66,    67,    68,    29,    15,     4,   111,    81,    24,    14,
    29,    77,    24,    79,    78,    15,    80,    24,    82,    38,
    24,    95,    14,    15,    98,    17,   100,     6,    47,     4,
    94,    18,    96,    97,     6,    99,     4,   101,    25,    26,
    27,   105,     6,     4,   108,     0,   110,     3,   122,   123,
   114,   125,     6,   127,     6,    11,    12,     6,    14,    15,
    16,    17,     6,    19,     6,   129,   130,   131,   132,     3,
     0,     5,    28,     7,    47,     9,    10,    11,    12,    13,
    14,    15,    16,    17,     3,    19,    12,    49,    14,    15,
    16,    38,    11,    12,    28,    14,    15,    16,    17,     3,
    19,    29,    -1,    74,    -1,    -1,    -1,    11,    12,    28,
    14,    15,    16,    17,    -1,    19,     8,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    28,    -1,    18,    19,    20,    21,
    22,     8,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
    27,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
    27
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 140 "parcer.y"


void yyerror(char const *s)
{
 printf("%s",s);
}

