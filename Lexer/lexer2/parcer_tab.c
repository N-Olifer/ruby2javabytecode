
/*  A Bison parser, made from parcer.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INT	258
#define	STRING	259
#define	EOL	260
#define	DEF	261
#define	END	262
#define	WHILE	263
#define	DO	264
#define	UNTIL	265
#define	CLASS	266
#define	SELF	267
#define	SUPER	268
#define	RETURN	269
#define	ID_CAP	270
#define	ID_LOW	271
#define	ID_FUNC	272
#define	ID_VAR_FIELD	273
#define	EQUAL	274
#define	NOTEQUAL	275
#define	OR	276
#define	AND	277
#define	NIL	278
#define	TRUE	279
#define	FALSE	280
#define	IF	281
#define	ELSIF	282
#define	ELSE	283
#define	UNLESS	284
#define	THEN	285
#define	UMINUS	286
#define	UBR	287

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



#define	YYFINAL		178
#define	YYFLAG		-32768
#define	YYNTBASE	47

#define YYTRANSLATE(x) ((unsigned)(x) <= 287 ? yytranslate[x] : 65)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    38,     2,     2,     2,     2,     2,     2,    45,
    44,    36,    35,    46,    34,    40,    37,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
    31,    33,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    42,     2,    41,     2,     2,     2,     2,     2,     2,     2,
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
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    39,    43
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     3,     5,     7,     9,    11,    13,    18,    23,
    28,    33,    38,    43,    48,    53,    58,    63,    66,    71,
    74,    80,    87,    93,    95,    97,    99,   101,   103,   105,
   109,   116,   118,   120,   121,   123,   125,   129,   130,   132,
   134,   136,   138,   140,   143,   145,   147,   149,   153,   163,
   171,   172,   174,   176,   181,   188,   199,   206,   217,   218,
   220,   225,   231,   240,   251,   259,   269,   279
};

static const short yyrhs[] = {    54,
     0,     0,     5,     0,    15,     0,    16,     0,    17,     0,
    18,     0,    50,    35,    48,    50,     0,    50,    34,    48,
    50,     0,    50,    36,    48,    50,     0,    50,    37,    48,
    50,     0,    50,    32,    48,    50,     0,    50,    33,    48,
    50,     0,    50,    19,    48,    50,     0,    50,    20,    48,
    50,     0,    50,    21,    48,    50,     0,    50,    22,    48,
    50,     0,    38,    50,     0,    50,    31,    48,    50,     0,
    34,    50,     0,    45,    48,    50,    48,    44,     0,    50,
    42,    48,    50,    48,    41,     0,    42,    48,    51,    48,
    41,     0,     3,     0,     4,     0,    49,     0,    23,     0,
    24,     0,    25,     0,    50,    40,    49,     0,    50,    40,
    49,    45,    51,    44,     0,    12,     0,    13,     0,     0,
    52,     0,    50,     0,    51,    46,    50,     0,     0,    50,
     0,    55,     0,    64,     0,    58,     0,    59,     0,    14,
    51,     0,    62,     0,    63,     0,    53,     0,    54,     5,
    53,     0,     6,    48,    49,    45,    56,    48,    44,    54,
     7,     0,     6,    48,    49,    56,     5,    54,     7,     0,
     0,    57,     0,    16,     0,    56,    46,    48,    16,     0,
     8,    48,    50,     9,    54,     7,     0,     8,    48,    45,
    48,    50,    48,    44,     5,    54,     7,     0,    10,    48,
    50,     9,    54,     7,     0,    10,    48,    45,    48,    50,
    48,    44,     5,    54,     7,     0,     0,    61,     0,    27,
    50,    30,    54,     0,    61,    27,    50,    30,    54,     0,
    26,    48,    50,    48,    30,    54,    60,     7,     0,    26,
    48,    50,    48,    30,    54,    60,    28,    54,     7,     0,
    29,    48,    50,    48,    30,    54,     7,     0,    29,    48,
    50,    48,    30,    54,    28,    54,     7,     0,    11,    48,
    15,    32,    48,    15,     5,    54,     7,     0,    11,    48,
    15,     5,    54,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    75,    77,    78,    81,    82,    83,    84,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   115,   116,   119,   120,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   134,   135,   138,   139,
   142,   143,   146,   147,   150,   151,   154,   155,   158,   159,
   162,   163,   166,   167,   170,   171,   174,   175
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID_CAP",
"ID_LOW","ID_FUNC","ID_VAR_FIELD","EQUAL","NOTEQUAL","OR","AND","NIL","TRUE",
"FALSE","IF","ELSIF","ELSE","UNLESS","THEN","'='","'<'","'>'","'-'","'+'","'*'",
"'/'","'!'","UMINUS","'.'","']'","'['","UBR","')'","'('","','","program","eln",
"id","expr","expr_seq","expr_seqE","stmt","stmt_seq","method_def","method_def_param_seq",
"method_def_param_seqE","while_stmt","until_stmt","elsif_seq","elsif_seqE","if_stmt",
"unless_stmt","class_def",""
};
#endif

static const short yyr1[] = {     0,
    47,    48,    48,    49,    49,    49,    49,    50,    50,    50,
    50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
    50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
    50,    50,    50,    51,    51,    52,    52,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
    56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
    61,    61,    62,    62,    63,    63,    64,    64
};

static const short yyr2[] = {     0,
     1,     0,     1,     1,     1,     1,     1,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     2,     4,     2,
     5,     6,     5,     1,     1,     1,     1,     1,     1,     3,
     6,     1,     1,     0,     1,     1,     3,     0,     1,     1,
     1,     1,     1,     2,     1,     1,     1,     3,     9,     7,
     0,     1,     1,     4,     6,    10,     6,    10,     0,     1,
     4,     5,     8,    10,     7,     9,     9,     6
};

static const short yydefact[] = {    38,
    24,    25,     2,     2,     2,     2,    32,    33,    34,     4,
     5,     6,     7,    27,    28,    29,     2,     2,     0,     0,
     2,     2,    26,    39,    47,     1,    40,    42,    43,    45,
    46,    41,     3,     0,     0,     0,     0,    36,    44,    35,
     0,     0,    20,    18,    34,     0,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     0,     2,    38,
    51,     2,     0,     2,     0,     0,     0,     2,     2,     2,
     2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    30,     0,    48,    53,    51,     0,    52,     0,
    38,     0,    38,    38,     2,    37,     0,     0,     0,     0,
    14,    15,    16,    17,    19,    12,    13,     9,     8,    10,
    11,    34,     2,     2,    38,     2,     2,     0,     2,     0,
     0,     0,    38,    38,    23,    21,     0,     0,     0,     0,
     0,     0,    55,     0,    57,    68,     0,    59,     0,    31,
    22,    38,    50,    54,    21,    21,    38,     0,     0,    60,
    65,    38,     0,    38,    38,     0,     0,    63,    38,     0,
     0,    49,     0,     0,    67,    38,     0,     0,    66,    56,
    58,    61,    64,    38,    62,     0,     0,     0
};

static const short yydefgoto[] = {   176,
    34,    23,    24,    39,    40,    25,    26,    27,    88,    89,
    28,    29,   149,   150,    30,    31,    32
};

static const short yypact[] = {   218,
-32768,-32768,    23,    23,    23,    23,-32768,-32768,     0,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    23,    23,     0,     0,
    23,    23,-32768,   138,-32768,    30,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   146,   254,   290,    64,   138,    41,-32768,
     0,     0,   -21,   -21,     0,     0,    23,    23,    23,    23,
    23,    23,    23,    23,    23,    23,    23,   146,    23,   218,
   -15,    23,    76,    23,   346,     9,     0,   317,   317,    -3,
   317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    46,     0,-32768,-32768,    83,     1,-32768,     0,
   218,     0,   218,   218,    23,   138,    58,    62,    96,    61,
   249,   249,   413,    20,   249,   162,   162,   112,   112,   -21,
   -21,     0,   317,     3,   218,    23,   317,    15,   317,    39,
    43,   123,   218,   218,-32768,-32768,    40,   104,    70,    95,
   134,   121,-32768,   122,-32768,-32768,   151,     4,    54,-32768,
-32768,   218,-32768,-32768,   177,   178,   218,     0,    73,   157,
-32768,   218,    99,   218,   218,   110,   370,-32768,   218,     0,
   125,-32768,   128,   148,-32768,   218,   174,   394,-32768,-32768,
-32768,    30,-32768,   218,    30,   187,   190,-32768
};

static const short yypgoto[] = {-32768,
    72,   -29,    -9,   -38,-32768,   132,    53,-32768,   106,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		455


static const short yytable[] = {    38,
    86,    33,     1,     2,    61,   115,    70,    33,    60,    43,
    44,     7,     8,    94,    10,    11,    12,    13,    58,    60,
    59,   133,    14,    15,    16,    63,    65,    33,    83,    87,
   148,    68,    69,    19,    60,    38,    71,    20,    47,    48,
    95,    21,    67,    60,    22,   135,   116,    60,   116,   136,
    51,    52,    53,    54,    55,    56,    57,    96,    60,    58,
   151,    59,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   127,   113,    35,    36,    37,    66,   158,
   117,   152,   119,   140,    91,    67,    67,   123,    41,    42,
   112,   124,    45,    46,    47,    48,    49,    50,    86,    60,
   159,   143,    38,    60,   126,   162,    51,    52,    53,    54,
    55,    56,    57,   142,    60,    58,   165,    59,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    60,
    84,   169,    60,    90,   170,    92,   125,   137,   157,    97,
    98,    99,   100,   118,   141,   120,   121,    56,    57,   144,
   168,    58,    60,    59,   171,   147,    47,    48,    49,    50,
    10,    11,    12,    13,   145,   146,   122,   130,    51,    52,
    53,    54,    55,    56,    57,   138,   139,    58,    60,    59,
   173,   154,   155,   160,   128,   129,   177,   131,   132,   178,
   134,    85,   114,     0,   153,    54,    55,    56,    57,   156,
     0,    58,     0,    59,   161,     0,   163,   164,     0,     0,
     0,   167,     0,     0,     0,     0,     0,     0,   172,     0,
     1,     2,     0,     3,     0,     4,   175,     5,     6,     7,
     8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
    14,    15,    16,    17,     0,     0,    18,     0,     0,     0,
     0,    19,     0,     0,     0,    20,     1,     2,     0,    21,
     0,     0,    22,     0,     0,     7,     8,     0,    10,    11,
    12,    13,     0,     0,     0,     0,    14,    15,    16,    51,
    52,    53,    54,    55,    56,    57,     0,    19,    58,     0,
    59,    20,     1,     2,     0,    21,     0,     0,    62,     0,
     0,     7,     8,     0,    10,    11,    12,    13,     0,     0,
     0,     0,    14,    15,    16,     0,     0,     0,     0,     0,
     0,    33,     0,    19,     0,     0,     0,    20,     0,     0,
     0,    21,     0,     0,    64,    47,    48,    49,    50,     0,
     0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
    54,    55,    56,    57,    93,     0,    58,     0,    59,     0,
     0,     0,     0,     0,    47,    48,    49,    50,     0,     0,
     0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
    55,    56,    57,     0,     0,    58,     0,    59,    47,    48,
    49,    50,     0,     0,     0,     0,     0,     0,     0,   166,
    51,    52,    53,    54,    55,    56,    57,     0,     0,    58,
     0,    59,    47,    48,    49,    50,     0,     0,     0,     0,
     0,     0,     0,   174,    51,    52,    53,    54,    55,    56,
    57,    47,    48,    58,    50,    59,     0,     0,     0,     0,
     0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
     0,     0,    58,     0,    59
};

static const short yycheck[] = {     9,
    16,     5,     3,     4,    34,     5,    45,     5,     5,    19,
    20,    12,    13,     5,    15,    16,    17,    18,    40,     5,
    42,     7,    23,    24,    25,    35,    36,     5,    58,    45,
    27,    41,    42,    34,     5,    45,    46,    38,    19,    20,
    32,    42,    46,     5,    45,     7,    46,     5,    46,     7,
    31,    32,    33,    34,    35,    36,    37,    67,     5,    40,
     7,    42,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,   112,    84,     4,     5,     6,    15,     7,
    90,    28,    92,    44,     9,    46,    46,    30,    17,    18,
    45,    30,    21,    22,    19,    20,    21,    22,    16,     5,
    28,     7,   112,     5,    44,     7,    31,    32,    33,    34,
    35,    36,    37,    44,     5,    40,     7,    42,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,     5,
    59,     7,     5,    62,     7,    64,    41,    15,   148,    68,
    69,    70,    71,    91,    41,    93,    94,    36,    37,    16,
   160,    40,     5,    42,     7,     5,    19,    20,    21,    22,
    15,    16,    17,    18,    44,    44,    95,   115,    31,    32,
    33,    34,    35,    36,    37,   123,   124,    40,     5,    42,
     7,     5,     5,    27,   113,   114,     0,   116,   117,     0,
   119,    60,    87,    -1,   142,    34,    35,    36,    37,   147,
    -1,    40,    -1,    42,   152,    -1,   154,   155,    -1,    -1,
    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
     3,     4,    -1,     6,    -1,     8,   174,    10,    11,    12,
    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,     3,     4,    -1,    42,
    -1,    -1,    45,    -1,    -1,    12,    13,    -1,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    31,
    32,    33,    34,    35,    36,    37,    -1,    34,    40,    -1,
    42,    38,     3,     4,    -1,    42,    -1,    -1,    45,    -1,
    -1,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
    -1,     5,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
    -1,    42,    -1,    -1,    45,    19,    20,    21,    22,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    35,    36,    37,     9,    -1,    40,    -1,    42,    -1,
    -1,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
    35,    36,    37,    -1,    -1,    40,    -1,    42,    19,    20,
    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
    31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
    -1,    42,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
    37,    19,    20,    40,    22,    42,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
    -1,    -1,    40,    -1,    42
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
#line 179 "parcer.y"

%error-verbose
void yyerror(char const *s)
{
 printf("%s",s);
}

