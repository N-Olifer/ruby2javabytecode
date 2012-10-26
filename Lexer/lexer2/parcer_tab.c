
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
#define	ID	270
#define	SPACE_BRACKET	271
#define	EQUAL	272
#define	NOTEQUAL	273
#define	OR	274
#define	AND	275
#define	NIL	276
#define	TRUE	277
#define	FALSE	278
#define	IF	279
#define	ELSIF	280
#define	ELSE	281
#define	UNLESS	282
#define	THEN	283
#define	UMINUS	284
#define	UBR	285

#line 1 "parcer.y"

#include <stdio.h>
#include <malloc.h>
#include "structures.h"

void yyerror(char const *s);
extern int parse(void);
extern struct ProgramNode* root;

struct ExprNode* createBinExpr(enum ExprNodeType type, struct ExprNode* left, struct ExprNode* right)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = type;
	result->left = left;
	result->right = right;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
} 

struct ExprNode* createUnExpr(enum ExprNodeType type, struct ExprNode* left)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = type;
	result->left = left;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
} 

struct ExprNode* createIdExpr(char* idStr)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eId;
	result->left = NULL;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = idStr;
	result->str = NULL;
	
	return result;
} 

struct ExprNode* createIntExpr(int value)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eInt;
	result->left = NULL;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	result->value = value;
	
	return result;
} 

struct ExprNode* createStrExpr(char* str)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eString;
	result->left = NULL;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = str;
	
	return result;
} 

struct ExprNode* createBracketsExpr(struct ExprNode* expression)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eBrackets;
	result->left = expression;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
} 

struct ExprNode* createQBracketsExpr(struct ExprNode* expression)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eQBrackets;
	result->left = expression;
	result->right = NULL;
	result->list = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
} 

struct ExprNode* createQBracketsInitExpr(struct ExprSeqNode* expressions)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eQBracketsInit;
	result->left = NULL;
	result->list = expressions;
	result->right = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
}

struct ExprNode* createFieldAccExpr(struct ExprNode* left, char* idStr, struct ExprSeqNode* params)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eFieldAcc;
	result->left = left;
	result->list = params;
	result->right = NULL;
	result->next = NULL;
	result->id = idStr;
	result->str = NULL;
	
	return result;
}

struct ExprNode* createSuperExpr(struct ExprSeqNode* params)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eSuper;
	result->left = NULL;
	result->list = params;
	result->right = NULL;
	result->next = NULL;
	result->id = "super";
	result->str = NULL;
	
	return result;
}

struct ExprNode* createSelfExpr()
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eSelf;
	result->left = NULL;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = "self";
	result->str = NULL;
	
	return result;
}

struct ExprNode* createBoolExpr(char boolValue)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eBool;
	result->value = boolValue;
	result->left = NULL;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = NULL;
	result->str = NULL;
	
	return result;
}

struct ExprNode* createNilExpr()
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eNil;
	result->left = NULL;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = "nil";
	result->str = NULL;
	
	return result;
}


struct ExprSeqNode* createExprSeq(struct ExprNode* first)
{
	struct ExprSeqNode* result = (struct ExprSeqNode*)malloc(sizeof(struct ExprSeqNode));
	
	result->first = first;
	result->last = first;
	
	return result;
}

struct ExprSeqNode* addExprToSeq(struct ExprSeqNode* seq, struct ExprNode* expression)
{
	if(seq->last != NULL)
	{
		seq->last->next = expression;
		seq->last = expression;
	}
	else
	{	
		seq->first = expression;
		seq->last = expression;
	}
	return seq;
}

struct StmtNode* createStmt(enum StmtNodeType type, struct ExprNode* expression, struct StmtSeqNode* block)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	
	result->type = type;
	result->block = block;
	result->expr = expression;
	result->params = NULL;
	result->next = NULL;
	return result;
}

struct StmtNode* createReturnStmt(struct ExprNode* value)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	
	result->type = eReturn;
	result->block = NULL;
	result->expr = value;
	result->next = NULL;

	
	return result;
}

struct StmtSeqNode* createStmtSeq(struct StmtNode* first)
{	
	struct StmtSeqNode* result = (struct StmtSeqNode*)malloc(sizeof(struct StmtSeqNode));
	
	result->first = first;
	result->last = first;
	
	return result;
}

struct StmtSeqNode* addStmtToSeq(struct StmtSeqNode* seq, struct StmtNode* statement)
{
	if(seq->last != NULL)
	{
		seq->last->next = statement;
		seq->last = statement;
	}
	else
	{	
		seq->first = statement;
		seq->last = statement;
	}
	return seq;
}

struct StmtNode* createMethodDefStmt(char* id, struct MethodDefParamSeqNode* params, struct StmtSeqNode* body)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	result->id = id;
	result->params = params;
	result->block = body;
	result->expr = NULL;
	result->type = eMethodDef;
	result->next = NULL;
	
	return result;
}

struct MethodDefParamSeqNode* createMethodDefParamSeq(struct MethodDefParamNode* param)
{
	struct MethodDefParamSeqNode* result = (struct MethodDefParamSeqNode*)malloc(sizeof(struct MethodDefParamSeqNode));
	result->first = param;
	result->last = param;
	
	return result;
}

struct MethodDefParamSeqNode* addParamToMethodDefParamSeq(struct MethodDefParamSeqNode* seq, struct MethodDefParamNode* param)
{
	if(seq->last != NULL)
	{
		seq->last->next = param;
		seq->last = param;
	}
	else
	{	
		seq->first = param;
		seq->last = param;
	}
	
	return seq;
}

struct MethodDefParamNode* createMethodDefParam(char* id)
{
	struct MethodDefParamNode* result = (struct MethodDefParamNode*)malloc(sizeof(struct MethodDefParamNode));
	result->id = id;
	result->next = NULL;
	
	return result;
}

struct StmtNode* createClassDef(char* name, char* parent, struct StmtSeqNode* body)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	
	result->id = name;
	result->secondId = parent;
	
	result->params = NULL;
	result->block = body;
	result->expr = NULL;
	result->type = eClassDef;
	result->next = NULL;
	
	return result;
}

struct ProgramNode* createProgram(struct StmtSeqNode* body)
{
	struct ProgramNode* result = (struct ProgramNode*)malloc(sizeof(struct ProgramNode));
	
	result->body = body;
	
	return result;
}



#line 359 "parcer.y"
typedef union
{
	int uInt;
	char* uId;
	char* uString;
	struct ExprNode* uExpr;
	struct ExprSeqNode* uExprSeq;
	struct StmtNode* uStmt;
	struct StmtSeqNode* uStmtSeq;
	struct MethodDefParamSeqNode* uMethodDefParamSeq;
	struct MethodDefParamNode* uMethodDefParam;
	struct ProgramNode* uProgram;
} YYSTYPE;

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

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		321
#define	YYFLAG		-32768
#define	YYNTBASE	45

#define YYTRANSLATE(x) ((unsigned)(x) <= 285 ? yytranslate[x] : 59)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    36,     2,     2,     2,     2,     2,     2,    43,
    42,    34,    33,    44,    32,    38,    35,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
    29,    31,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    40,     2,    39,     2,     2,     2,     2,     2,     2,     2,
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
    26,    27,    28,    37,    41
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     9,    14,    19,    23,    28,    32,    37,
    41,    45,    50,    54,    59,    63,    68,    72,    77,    81,
    86,    90,    95,    98,   102,   107,   110,   114,   119,   124,
   130,   135,   141,   147,   154,   159,   165,   170,   174,   177,
   181,   183,   185,   187,   189,   191,   195,   201,   208,   216,
   225,   233,   235,   239,   244,   250,   257,   263,   265,   267,
   272,   273,   275,   277,   281,   286,   288,   290,   292,   294,
   296,   299,   300,   302,   304,   308,   311,   321,   329,   337,
   346,   353,   354,   356,   358,   363,   367,   369,   376,   382,
   390,   397,   408,   418,   428,   437,   447,   456,   465,   473,
   480,   486,   494,   501,   512,   522,   532,   541,   551,   560,
   569,   577,   587,   596,   605,   613,   620,   626,   627,   629,
   634,   640,   649,   660,   668
};

static const short yyrhs[] = {    50,
     0,     5,    50,     0,    46,    33,    46,     0,    46,    33,
     5,    46,     0,    46,    32,     5,    46,     0,    46,    32,
    46,     0,    46,    34,     5,    46,     0,    46,    34,    46,
     0,    46,    35,     5,    46,     0,    46,    35,    46,     0,
    46,    30,    46,     0,    46,    30,     5,    46,     0,    46,
    31,    46,     0,    46,    31,     5,    46,     0,    46,    17,
    46,     0,    46,    17,     5,    46,     0,    46,    18,    46,
     0,    46,    18,     5,    46,     0,    46,    19,    46,     0,
    46,    19,     5,    46,     0,    46,    20,    46,     0,    46,
    20,     5,    46,     0,    36,    46,     0,    46,    29,    46,
     0,    46,    29,     5,    46,     0,    32,    46,     0,    43,
    46,    42,     0,    43,    46,     5,    42,     0,    43,     5,
    46,    42,     0,    43,     5,    46,     5,    42,     0,    46,
    40,    46,    39,     0,    46,    40,    46,     5,    39,     0,
    46,    40,     5,    46,    39,     0,    46,    40,     5,    46,
     5,    39,     0,    40,     5,    48,    39,     0,    40,     5,
    48,     5,    39,     0,    40,    48,     5,    39,     0,    40,
    48,    39,     0,    40,    39,     0,    40,     5,    39,     0,
     3,     0,     4,     0,    21,     0,    22,     0,    23,     0,
    46,    38,    15,     0,    46,    38,    15,    43,    42,     0,
    46,    38,    15,    43,    48,    42,     0,    46,    38,    15,
    43,     5,    48,    42,     0,    46,    38,    15,    43,     5,
    48,     5,    42,     0,    46,    38,    15,    43,    48,     5,
    42,     0,    15,     0,    15,    43,    42,     0,    15,    43,
    48,    42,     0,    15,    43,     5,    48,    42,     0,    15,
    43,     5,    48,     5,    42,     0,    15,    43,    48,     5,
    42,     0,    12,     0,    13,     0,    13,    43,    47,    42,
     0,     0,    48,     0,    46,     0,    48,    44,    46,     0,
    48,    44,     5,    46,     0,    46,     0,    52,     0,    58,
     0,    56,     0,    57,     0,    14,    46,     0,     0,    51,
     0,    49,     0,    51,     5,    49,     0,    51,     5,     0,
     6,     5,    15,    43,    53,     5,    42,    50,     7,     0,
     6,     5,    15,    53,     5,    50,     7,     0,     6,    15,
    43,    53,    42,    50,     7,     0,     6,    15,    43,    53,
    42,     5,    50,     7,     0,     6,    15,    53,     5,    50,
     7,     0,     0,    54,     0,    55,     0,    53,    44,     5,
    55,     0,    53,    44,    55,     0,    15,     0,     8,     5,
    46,     9,    50,     7,     0,     8,    46,     9,    50,     7,
     0,     8,     5,    46,     9,     5,    50,     7,     0,     8,
    46,     9,     5,    50,     7,     0,     8,     5,    43,     5,
    46,     5,    42,     5,    50,     7,     0,     8,     5,    43,
     5,    46,    42,     5,    50,     7,     0,     8,     5,    43,
    46,     5,    42,     5,    50,     7,     0,     8,     5,    43,
    46,    42,     5,    50,     7,     0,     8,    43,     5,    46,
     5,    42,     5,    50,     7,     0,     8,    43,     5,    46,
    42,     5,    50,     7,     0,     8,    43,    46,     5,    42,
     5,    50,     7,     0,     8,    43,    46,    42,     5,    50,
     7,     0,    10,     5,    46,     9,    50,     7,     0,    10,
    46,     9,    50,     7,     0,    10,     5,    46,     9,     5,
    50,     7,     0,    10,    46,     9,     5,    50,     7,     0,
    10,     5,    43,     5,    46,     5,    42,     5,    50,     7,
     0,    10,     5,    43,     5,    46,    42,     5,    50,     7,
     0,    10,     5,    43,    46,     5,    42,     5,    50,     7,
     0,    10,     5,    43,    46,    42,     5,    50,     7,     0,
    10,    43,     5,    46,     5,    42,     5,    50,     7,     0,
    10,    43,     5,    46,    42,     5,    50,     7,     0,    10,
    43,    46,     5,    42,     5,    50,     7,     0,    10,    43,
    46,    42,     5,    50,     7,     0,    11,     5,    15,    30,
     5,    15,     5,    50,     7,     0,    11,     5,    15,    30,
    15,     5,    50,     7,     0,    11,    15,    30,     5,    15,
     5,    50,     7,     0,    11,    15,    30,    15,     5,    50,
     7,     0,    11,     5,    15,     5,    50,     7,     0,    11,
    15,     5,    50,     7,     0,     0,     0,     0,    25,    46,
    28,    50,     0,     0,    25,    46,    28,    50,     0,    24,
     5,    46,     5,    28,    50,     0,     7,     0,    24,     5,
    46,     5,    28,    50,     0,    26,    50,     7,     0,    27,
     5,    46,     5,    28,    50,     7,     0,    27,     5,    46,
     5,    28,    50,    26,    50,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   436,   437,   440,   441,   443,   444,   446,   447,   449,   450,
   452,   453,   455,   456,   458,   459,   461,   462,   464,   465,
   467,   468,   470,   472,   473,   475,   477,   478,   479,   480,
   482,   483,   484,   485,   487,   488,   489,   490,   492,   493,
   495,   496,   497,   498,   499,   500,   502,   503,   504,   505,
   506,   508,   509,   510,   511,   512,   513,   514,   515,   516,
   519,   520,   523,   524,   525,   530,   531,   532,   533,   534,
   535,   539,   540,   543,   544,   545,   548,   549,   550,   551,
   552,   555,   556,   559,   560,   561,   564,   567,   568,   569,
   570,   572,   573,   574,   575,   578,   579,   580,   581,   584,
   585,   586,   587,   589,   590,   591,   592,   595,   596,   597,
   598,   620,   621,   622,   623,   625,   626,   629,   630,   633,
   634,   637,   638,   641,   642
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID",
"SPACE_BRACKET","EQUAL","NOTEQUAL","OR","AND","NIL","TRUE","FALSE","IF","ELSIF",
"ELSE","UNLESS","THEN","'='","'<'","'>'","'-'","'+'","'*'","'/'","'!'","UMINUS",
"'.'","']'","'['","UBR","')'","'('","','","program","expr","expr_seq","expr_seqE",
"stmt","stmt_seq","stmt_seqE","method_def","method_def_param_seq","method_def_param_seqE",
"method_def_param","while_stmt","until_stmt","class_def","\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735\37777777735"
};
#endif

static const short yyr1[] = {     0,
    45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    47,    47,    48,    48,    48,    49,    49,    49,    49,    49,
    49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
    52,    53,    53,    54,    54,    54,    55,    56,    56,    56,
    56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
    57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
    57,    58,    58,    58,    58,    58,    58,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1
};

static const short yyr2[] = {     0,
     1,     2,     3,     4,     4,     3,     4,     3,     4,     3,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     2,     3,     4,     2,     3,     4,     4,     5,
     4,     5,     5,     6,     4,     5,     4,     3,     2,     3,
     1,     1,     1,     1,     1,     3,     5,     6,     7,     8,
     7,     1,     3,     4,     5,     6,     5,     1,     1,     4,
     0,     1,     1,     3,     4,     1,     1,     1,     1,     1,
     2,     0,     1,     1,     3,     2,     9,     7,     7,     8,
     6,     0,     1,     1,     4,     3,     1,     6,     5,     7,
     6,    10,     9,     9,     8,     9,     8,     8,     7,     6,
     5,     7,     6,    10,     9,     9,     8,     9,     8,     8,
     7,     9,     8,     8,     7,     6,     5,     0,     1,     4,
     5,     8,    10,     7,     9
};

static const short yydefact[] = {    72,
    41,    42,    72,     0,     0,     0,     0,    58,    59,     0,
    52,    43,    44,    45,     0,     0,     0,     0,    66,    74,
     1,    73,    67,    69,    70,    68,     2,     0,    82,     0,
     0,     0,     0,     0,     0,     0,     0,    61,    71,     0,
    26,    23,     0,    39,    63,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    76,    82,    87,    82,     0,    83,    84,     0,     0,
     0,     0,    72,     0,     0,     0,     0,    72,     0,    72,
     0,     0,    62,     0,    53,     0,    40,     0,     0,    38,
     0,     0,     0,    27,     0,    15,     0,    17,     0,    19,
     0,    21,     0,    24,     0,    11,     0,    13,     0,     6,
     0,     3,     0,     8,     0,    10,    46,     0,     0,    75,
    82,     0,     0,    72,     0,     0,     0,    72,     0,     0,
    27,    72,     0,     0,     0,    72,     0,     0,    27,    72,
     0,    72,     0,     0,     0,     0,    60,     0,     0,    54,
     0,    35,    37,     0,    64,     0,    29,    28,    16,    18,
    20,    22,    25,    12,    14,     5,     4,     7,     9,     0,
     0,     0,    31,     0,    72,    72,     0,     0,    86,     0,
     0,    27,    72,     0,     0,    29,    28,    72,     0,    89,
     0,     0,    27,    72,     0,     0,    29,    28,    72,     0,
   101,     0,     0,     0,   117,     0,    72,     0,    55,    57,
    36,    65,    30,     0,    47,     0,     0,    33,    32,     0,
     0,    72,     0,    81,    85,     0,    29,    28,    72,     0,
    88,    30,    72,    72,     0,    91,     0,    29,    28,    72,
     0,   100,    30,    72,    72,     0,   103,   116,     0,    72,
    72,     0,    56,     0,     0,    48,    34,    72,    78,     0,
    79,    30,    72,    72,     0,    90,    72,     0,     0,    99,
    30,    72,    72,     0,   102,    72,     0,     0,   111,    72,
     0,     0,   115,     0,    49,    51,     0,    80,    72,     0,
     0,    95,     0,    97,    98,    72,     0,     0,   107,     0,
   109,   110,     0,   113,   114,    50,    77,     0,    93,    94,
    96,     0,   105,   106,   108,   112,    92,   104,     0,     0,
     0
};

static const short yydefgoto[] = {   319,
    19,    82,    46,    20,    21,    22,    23,    66,    67,    68,
    24,    25,    26
};

static const short yypact[] = {   277,
-32768,-32768,   520,     5,   231,   572,     6,-32768,   -37,  1034,
   -10,-32768,-32768,-32768,  1034,  1034,   123,   598,  1578,-32768,
-32768,    81,-32768,-32768,-32768,-32768,-32768,    72,   -13,  1072,
   624,  1473,  1077,   650,  1500,    76,     7,  1034,  1578,   166,
   -14,   -14,   666,-32768,  1578,    -4,  1034,  1105,   707,   712,
   753,   758,   799,   804,   845,   850,   891,   896,   937,    77,
   942,   520,    53,-32768,    89,    20,-32768,-32768,   983,  1527,
  1034,  1136,   318,   988,  1554,  1034,  1167,   359,    13,   520,
    75,    64,    66,  1034,-32768,    18,-32768,    22,    69,-32768,
  1029,  1198,    70,-32768,  1034,   272,  1034,   272,  1034,   183,
  1034,  1597,  1034,  1578,  1034,   311,  1034,   311,  1034,    80,
  1034,    80,  1034,   -14,  1034,   -14,    74,  1034,  1415,-32768,
    89,    39,    58,   520,    79,  1034,  1229,   400,  1260,    88,
   114,   520,   115,  1034,  1291,   441,  1322,    92,   118,   520,
   124,   520,    83,   133,   126,   137,-32768,    29,   101,-32768,
   108,-32768,-32768,  1034,  1578,   106,-32768,-32768,   272,   272,
   183,  1597,  1578,   311,   311,    80,    80,   -14,   -14,   546,
  1446,   111,-32768,    41,   520,   482,   144,    89,-32768,  1353,
   112,   148,   520,   149,   116,   152,   155,   520,   154,-32768,
  1384,   122,   160,   520,   167,   125,   170,   171,   520,   175,
-32768,   176,   162,   179,-32768,   181,   520,   150,-32768,-32768,
-32768,  1578,-32768,  1034,-32768,    34,   151,-32768,-32768,   153,
   187,   520,   190,-32768,-32768,   157,   200,   202,   520,   203,
-32768,   206,   520,   520,   213,-32768,   180,   219,   220,   520,
   221,-32768,   222,   520,   520,   225,-32768,-32768,   224,   520,
   520,   226,-32768,    37,   196,-32768,-32768,   520,-32768,   232,
-32768,   235,   520,   520,   238,-32768,   520,   242,   243,-32768,
   246,   520,   520,   249,-32768,   520,   250,   251,-32768,   520,
   252,   255,-32768,   223,-32768,-32768,   259,-32768,   520,   261,
   265,-32768,   268,-32768,-32768,   520,   269,   271,-32768,   287,
-32768,-32768,   288,-32768,-32768,-32768,-32768,   289,-32768,-32768,
-32768,   290,-32768,-32768,-32768,-32768,-32768,-32768,   279,   284,
-32768
};

static const short yypgoto[] = {-32768,
    -2,-32768,   -21,   239,    -3,-32768,-32768,   -56,-32768,  -120,
-32768,-32768,-32768
};


#define	YYLAST		1637


static const short yytable[] = {    27,
    89,    64,    32,    35,   179,    38,   122,    39,   123,    28,
    36,    80,    41,    42,    45,    48,    83,   142,    86,    29,
    37,    88,   149,    60,   124,    61,   151,    70,    72,    65,
    75,    77,    40,   208,    90,    45,    81,    45,   255,    91,
    45,   284,   143,   175,    92,   220,    96,    98,   100,   102,
   104,   106,   108,   110,   112,   114,   116,   225,   119,   150,
   152,    91,   148,   125,   174,    91,   127,    64,   129,   133,
   209,   135,    91,   137,   141,   256,   144,    91,   285,   145,
    91,    45,   125,   178,   125,    62,    63,   203,   155,   146,
    79,   117,   159,    64,   160,   121,   161,   204,   162,   176,
   163,   125,   164,    64,   165,   147,   166,   153,   167,    91,
   168,   158,   169,    58,    59,   171,   170,    60,   188,    61,
   177,   190,   199,   180,   184,     1,     2,    43,   189,   187,
   201,   191,   195,   198,     8,     9,   200,    11,   202,   205,
   206,   207,   210,    12,    13,    14,   211,   213,   216,   219,
   224,   212,   229,   228,    15,   231,   233,   232,    16,   234,
   236,    44,    17,   239,   240,    18,   243,    45,     1,     2,
    84,   221,   223,   242,   244,   245,   249,     8,     9,   230,
    11,   247,   248,   250,   235,   251,    12,    13,    14,   257,
   241,   253,   254,   259,   258,   246,   261,    15,   262,    49,
    50,    16,    52,   252,   263,    17,   264,    85,    18,   266,
   267,    45,    54,    55,    56,    57,    58,    59,   260,   270,
    60,   271,    61,   272,   273,   265,   276,   275,   280,   268,
   269,   279,   283,     1,     2,    30,   274,   286,   288,   289,
   277,   278,     8,     9,   292,    11,   281,   282,   294,   295,
   296,    12,    13,    14,   287,   299,   301,   302,   304,   290,
   291,   305,    15,   293,   306,   307,    16,   309,   297,   298,
    17,   310,   300,    31,   311,   313,   303,   314,   320,     1,
     2,     3,     4,   321,     5,   308,     6,     7,     8,     9,
    10,    11,   312,   315,   316,   317,   318,    12,    13,    14,
   120,    54,    55,    56,    57,    58,    59,     0,    15,    60,
     0,    61,    16,     0,     0,     0,    17,     0,     0,    18,
     1,     2,   132,     4,     0,     5,     0,     6,     7,     8,
     9,    10,    11,     0,     0,     0,     0,     0,    12,    13,
    14,     0,    56,    57,    58,    59,     0,     0,    60,    15,
    61,     0,     0,    16,     0,     0,     0,    17,     0,     0,
    18,     1,     2,   140,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,     0,     0,     0,     0,     0,    12,
    13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
    15,     0,     0,     0,    16,     0,     0,     0,    17,     0,
     0,    18,     1,     2,   183,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
    12,    13,    14,     0,     0,     0,     0,     0,     0,     0,
     0,    15,     0,     0,     0,    16,     0,     0,     0,    17,
     0,     0,    18,     1,     2,   194,     4,     0,     5,     0,
     6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
     0,    12,    13,    14,     0,     0,     0,     0,     0,     0,
     0,     0,    15,     0,     0,     0,    16,     0,     0,     0,
    17,     0,     0,    18,     1,     2,   222,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     0,     0,     0,    15,     0,     0,     0,    16,     0,     0,
     0,    17,     1,     2,    18,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
    12,    13,    14,     0,     0,     0,     0,     0,     1,     2,
   214,    15,     0,     0,     0,    16,     0,     8,     9,    17,
    11,     0,    18,     0,     0,     0,    12,    13,    14,     0,
     0,     0,     0,     0,     1,     2,    33,    15,     0,     0,
     0,    16,     0,     8,     9,    17,    11,   215,    18,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     1,     2,    47,    15,     0,     0,     0,    16,     0,     8,
     9,    17,    11,     0,    34,     0,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,    71,    15,
     0,     0,     0,    16,     0,     8,     9,    17,    11,     0,
    18,     0,     0,     0,    12,    13,    14,     0,     0,     0,
     0,     0,     1,     2,    76,    15,     0,     0,     0,    16,
     0,     8,     9,    17,    11,     0,    18,     0,     1,     2,
    12,    13,    14,     0,     0,     0,     0,     8,     9,     0,
    11,    15,     0,     0,     0,    16,    12,    13,    14,    17,
     0,     0,    18,     0,     0,     0,     0,    15,     0,     0,
     0,    16,     0,     0,    87,    17,     0,     0,    18,     1,
     2,    95,     0,     0,     1,     2,    97,     0,     8,     9,
     0,    11,     0,     8,     9,     0,    11,    12,    13,    14,
     0,     0,    12,    13,    14,     0,     0,     0,    15,     0,
     0,     0,    16,    15,     0,     0,    17,    16,     0,    18,
     0,    17,     0,     0,    18,     1,     2,    99,     0,     0,
     1,     2,   101,     0,     8,     9,     0,    11,     0,     8,
     9,     0,    11,    12,    13,    14,     0,     0,    12,    13,
    14,     0,     0,     0,    15,     0,     0,     0,    16,    15,
     0,     0,    17,    16,     0,    18,     0,    17,     0,     0,
    18,     1,     2,   103,     0,     0,     1,     2,   105,     0,
     8,     9,     0,    11,     0,     8,     9,     0,    11,    12,
    13,    14,     0,     0,    12,    13,    14,     0,     0,     0,
    15,     0,     0,     0,    16,    15,     0,     0,    17,    16,
     0,    18,     0,    17,     0,     0,    18,     1,     2,   107,
     0,     0,     1,     2,   109,     0,     8,     9,     0,    11,
     0,     8,     9,     0,    11,    12,    13,    14,     0,     0,
    12,    13,    14,     0,     0,     0,    15,     0,     0,     0,
    16,    15,     0,     0,    17,    16,     0,    18,     0,    17,
     0,     0,    18,     1,     2,   111,     0,     0,     1,     2,
   113,     0,     8,     9,     0,    11,     0,     8,     9,     0,
    11,    12,    13,    14,     0,     0,    12,    13,    14,     0,
     0,     0,    15,     0,     0,     0,    16,    15,     0,     0,
    17,    16,     0,    18,     0,    17,     0,     0,    18,     1,
     2,   115,     0,     0,     1,     2,   118,     0,     8,     9,
     0,    11,     0,     8,     9,     0,    11,    12,    13,    14,
     0,     0,    12,    13,    14,     0,     0,     0,    15,     0,
     0,     0,    16,    15,     0,     0,    17,    16,     0,    18,
     0,    17,     0,     0,    18,     1,     2,   126,     0,     0,
     1,     2,   134,     0,     8,     9,     0,    11,     0,     8,
     9,     0,    11,    12,    13,    14,     0,     0,    12,    13,
    14,     0,     0,     0,    15,     0,     0,     0,    16,    15,
     0,     0,    17,    16,     0,    18,     0,    17,     0,     0,
    18,     1,     2,   154,     0,     0,     1,     2,     0,     0,
     8,     9,     0,    11,     0,     8,     9,     0,    11,    12,
    13,    14,     0,     0,    12,    13,    14,     0,     0,     0,
    15,     0,     0,     0,    16,    15,     0,     0,    17,    16,
     0,    18,     0,    17,     1,     2,    18,     0,     0,     1,
     2,     0,     0,     8,     9,     0,    11,     0,     8,     9,
     0,    11,    12,    13,    14,     0,     0,    12,    13,    14,
     0,     0,     0,    15,     0,     0,     0,    16,    15,    93,
     0,    17,    16,     0,    69,     0,    17,     0,     0,    74,
     0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
     0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
   130,     0,    60,     0,    61,     0,    94,     0,     0,     0,
     0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
     0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
    59,   138,     0,    60,     0,    61,     0,   131,     0,     0,
     0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
     0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
    58,    59,   156,     0,    60,     0,    61,     0,   139,     0,
     0,     0,     0,     0,    49,    50,    51,    52,     0,     0,
     0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
    57,    58,    59,   181,     0,    60,     0,    61,     0,   157,
     0,     0,     0,     0,     0,    49,    50,    51,    52,     0,
     0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
    56,    57,    58,    59,   185,     0,    60,     0,    61,     0,
   182,     0,     0,     0,     0,     0,    49,    50,    51,    52,
     0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
    55,    56,    57,    58,    59,   192,     0,    60,     0,    61,
     0,   186,     0,     0,     0,     0,     0,    49,    50,    51,
    52,     0,     0,     0,     0,     0,     0,     0,     0,    53,
    54,    55,    56,    57,    58,    59,   196,     0,    60,     0,
    61,     0,   193,     0,     0,     0,     0,     0,    49,    50,
    51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
    53,    54,    55,    56,    57,    58,    59,   226,     0,    60,
     0,    61,     0,   197,     0,     0,     0,     0,     0,    49,
    50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
     0,    53,    54,    55,    56,    57,    58,    59,   237,     0,
    60,     0,    61,     0,   227,     0,     0,     0,     0,     0,
    49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     0,     0,    53,    54,    55,    56,    57,    58,    59,   172,
     0,    60,     0,    61,     0,   238,     0,     0,     0,     0,
     0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
     0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
   217,     0,    60,   173,    61,     0,     0,     0,     0,     0,
     0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
     0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
    59,    73,     0,    60,   218,    61,     0,     0,     0,    49,
    50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
     0,    53,    54,    55,    56,    57,    58,    59,    78,     0,
    60,     0,    61,     0,     0,     0,    49,    50,    51,    52,
     0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
    55,    56,    57,    58,    59,   128,     0,    60,     0,    61,
     0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
     0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
    58,    59,   136,     0,    60,     0,    61,     0,     0,     0,
    49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     0,     0,    53,    54,    55,    56,    57,    58,    59,     0,
     0,    60,     0,    61,    49,    50,    51,    52,     0,     0,
     0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
    57,    58,    59,    49,    50,    60,     0,    61,     0,     0,
     0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
    58,    59,     0,     0,    60,     0,    61
};

static const short yycheck[] = {     3,
     5,    15,     5,     6,   125,    43,    63,    10,    65,     5,
     5,     5,    15,    16,    17,    18,    38,     5,    40,    15,
    15,    43,     5,    38,     5,    40,     5,    30,    31,    43,
    33,    34,    43,     5,    39,    38,    30,    40,     5,    44,
    43,     5,    30,     5,    47,     5,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,   178,    61,    42,
    39,    44,    84,    44,   121,    44,    69,    15,    71,    73,
    42,    74,    44,    76,    78,    42,    80,    44,    42,     5,
    44,    84,    44,     5,    44,     5,    15,     5,    91,    15,
    15,    15,    95,    15,    97,    43,    99,    15,   101,    42,
   103,    44,   105,    15,   107,    42,   109,    39,   111,    44,
   113,    42,   115,    34,    35,   118,    43,    38,     5,    40,
   124,     7,     5,   126,   128,     3,     4,     5,   132,    42,
     7,   134,   136,    42,    12,    13,   140,    15,   142,     7,
    15,     5,    42,    21,    22,    23,    39,    42,   170,    39,
     7,   154,     5,    42,    32,     7,     5,    42,    36,     5,
     7,    39,    40,    42,     5,    43,    42,   170,     3,     4,
     5,   175,   176,     7,     5,     5,    15,    12,    13,   183,
    15,     7,     7,     5,   188,     5,    21,    22,    23,    39,
   194,    42,   214,     7,    42,   199,     7,    32,    42,    17,
    18,    36,    20,   207,     5,    40,     5,    42,    43,     7,
     5,   214,    30,    31,    32,    33,    34,    35,   222,     7,
    38,    42,    40,     5,     5,   229,     5,     7,     5,   233,
   234,     7,     7,     3,     4,     5,   240,    42,     7,     5,
   244,   245,    12,    13,     7,    15,   250,   251,     7,     7,
     5,    21,    22,    23,   258,     7,     7,     7,     7,   263,
   264,     7,    32,   267,    42,     7,    36,     7,   272,   273,
    40,     7,   276,    43,     7,     7,   280,     7,     0,     3,
     4,     5,     6,     0,     8,   289,    10,    11,    12,    13,
    14,    15,   296,     7,     7,     7,     7,    21,    22,    23,
    62,    30,    31,    32,    33,    34,    35,    -1,    32,    38,
    -1,    40,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
     3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
    23,    -1,    32,    33,    34,    35,    -1,    -1,    38,    32,
    40,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
    43,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,
    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,
    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,
    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,
    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,
    -1,    40,     3,     4,    43,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,
    15,    -1,    43,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    42,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    -1,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    -1,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    -1,    43,    -1,     3,     4,
    21,    22,    23,    -1,    -1,    -1,    -1,    12,    13,    -1,
    15,    32,    -1,    -1,    -1,    36,    21,    22,    23,    40,
    -1,    -1,    43,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    39,    40,    -1,    -1,    43,     3,
     4,     5,    -1,    -1,     3,     4,     5,    -1,    12,    13,
    -1,    15,    -1,    12,    13,    -1,    15,    21,    22,    23,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    32,    -1,    -1,    40,    36,    -1,    43,
    -1,    40,    -1,    -1,    43,     3,     4,     5,    -1,    -1,
     3,     4,     5,    -1,    12,    13,    -1,    15,    -1,    12,
    13,    -1,    15,    21,    22,    23,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    32,
    -1,    -1,    40,    36,    -1,    43,    -1,    40,    -1,    -1,
    43,     3,     4,     5,    -1,    -1,     3,     4,     5,    -1,
    12,    13,    -1,    15,    -1,    12,    13,    -1,    15,    21,
    22,    23,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    32,    -1,    -1,    40,    36,
    -1,    43,    -1,    40,    -1,    -1,    43,     3,     4,     5,
    -1,    -1,     3,     4,     5,    -1,    12,    13,    -1,    15,
    -1,    12,    13,    -1,    15,    21,    22,    23,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    32,    -1,    -1,    40,    36,    -1,    43,    -1,    40,
    -1,    -1,    43,     3,     4,     5,    -1,    -1,     3,     4,
     5,    -1,    12,    13,    -1,    15,    -1,    12,    13,    -1,
    15,    21,    22,    23,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,    32,    -1,    -1,
    40,    36,    -1,    43,    -1,    40,    -1,    -1,    43,     3,
     4,     5,    -1,    -1,     3,     4,     5,    -1,    12,    13,
    -1,    15,    -1,    12,    13,    -1,    15,    21,    22,    23,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    32,    -1,    -1,    40,    36,    -1,    43,
    -1,    40,    -1,    -1,    43,     3,     4,     5,    -1,    -1,
     3,     4,     5,    -1,    12,    13,    -1,    15,    -1,    12,
    13,    -1,    15,    21,    22,    23,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    32,
    -1,    -1,    40,    36,    -1,    43,    -1,    40,    -1,    -1,
    43,     3,     4,     5,    -1,    -1,     3,     4,    -1,    -1,
    12,    13,    -1,    15,    -1,    12,    13,    -1,    15,    21,
    22,    23,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    32,    -1,    -1,    40,    36,
    -1,    43,    -1,    40,     3,     4,    43,    -1,    -1,     3,
     4,    -1,    -1,    12,    13,    -1,    15,    -1,    12,    13,
    -1,    15,    21,    22,    23,    -1,    -1,    21,    22,    23,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    32,     5,
    -1,    40,    36,    -1,    43,    -1,    40,    -1,    -1,    43,
    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
     5,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,     5,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
    34,    35,     5,    -1,    38,    -1,    40,    -1,    42,    -1,
    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,     5,    -1,    38,    -1,    40,    -1,    42,
    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
    32,    33,    34,    35,     5,    -1,    38,    -1,    40,    -1,
    42,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
    31,    32,    33,    34,    35,     5,    -1,    38,    -1,    40,
    -1,    42,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
    30,    31,    32,    33,    34,    35,     5,    -1,    38,    -1,
    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    29,    30,    31,    32,    33,    34,    35,     5,    -1,    38,
    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    17,
    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    29,    30,    31,    32,    33,    34,    35,     5,    -1,
    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    29,    30,    31,    32,    33,    34,    35,     5,
    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
     5,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,     9,    -1,    38,    39,    40,    -1,    -1,    -1,    17,
    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    29,    30,    31,    32,    33,    34,    35,     9,    -1,
    38,    -1,    40,    -1,    -1,    -1,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
    31,    32,    33,    34,    35,     9,    -1,    38,    -1,    40,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
    34,    35,     9,    -1,    38,    -1,    40,    -1,    -1,    -1,
    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
    -1,    38,    -1,    40,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,    17,    18,    38,    -1,    40,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
    34,    35,    -1,    -1,    38,    -1,    40
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

case 1:
#line 436 "parcer.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 2:
#line 437 "parcer.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 3:
#line 440 "parcer.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 4:
#line 441 "parcer.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 5:
#line 443 "parcer.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 6:
#line 444 "parcer.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 7:
#line 446 "parcer.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 8:
#line 447 "parcer.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 9:
#line 449 "parcer.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 10:
#line 450 "parcer.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 11:
#line 452 "parcer.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 12:
#line 453 "parcer.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 13:
#line 455 "parcer.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 14:
#line 456 "parcer.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 15:
#line 458 "parcer.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 16:
#line 459 "parcer.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 17:
#line 461 "parcer.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 18:
#line 462 "parcer.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 19:
#line 464 "parcer.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 20:
#line 465 "parcer.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 21:
#line 467 "parcer.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 22:
#line 468 "parcer.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 23:
#line 470 "parcer.y"
{ yyval.uExpr = createUnExpr(eNot, yyvsp[0].uExpr); ;
    break;}
case 24:
#line 472 "parcer.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 25:
#line 473 "parcer.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 26:
#line 475 "parcer.y"
{ yyval.uExpr = createUnExpr(eUMinus, yyvsp[0].uExpr); ;
    break;}
case 27:
#line 477 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 28:
#line 478 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 29:
#line 479 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 30:
#line 480 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 31:
#line 482 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 32:
#line 483 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 33:
#line 484 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 34:
#line 485 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 35:
#line 487 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 36:
#line 488 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 37:
#line 489 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 38:
#line 490 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 39:
#line 492 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 40:
#line 493 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 41:
#line 495 "parcer.y"
{ yyval.uExpr = createIntExpr(yyvsp[0].uId); ;
    break;}
case 42:
#line 496 "parcer.y"
{ yyval.uExpr = createStrExpr(yyvsp[0].uString); ;
    break;}
case 43:
#line 497 "parcer.y"
{ yyval.uExpr = createNilExpr(); ;
    break;}
case 44:
#line 498 "parcer.y"
{ yyval.uExpr = createBoolExpr(1); ;
    break;}
case 45:
#line 499 "parcer.y"
{ yyval.uExpr = createBoolExpr(0); ;
    break;}
case 46:
#line 500 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-2].uExpr, yyvsp[0].uId, NULL); ;
    break;}
case 47:
#line 502 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-4].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 48:
#line 503 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-5].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 49:
#line 504 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 50:
#line 505 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-7].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 51:
#line 506 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 52:
#line 508 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId, NULL); ;
    break;}
case 53:
#line 509 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-2].uId, NULL); ;
    break;}
case 54:
#line 510 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 55:
#line 511 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 56:
#line 512 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 57:
#line 513 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 58:
#line 514 "parcer.y"
{ yyval.uExpr = createSelfExpr(); ;
    break;}
case 59:
#line 515 "parcer.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 60:
#line 516 "parcer.y"
{ yyval.uExpr = createSelfExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 61:
#line 519 "parcer.y"
{ yyval.uExprSeq = createExprSeq(NULL); ;
    break;}
case 62:
#line 520 "parcer.y"
{ yyval.uExprSeq = yyvsp[0].uExprSeq; ;
    break;}
case 63:
#line 523 "parcer.y"
{ yyval.uExprSeq = createExprSeq(yyvsp[0].uExpr); ;
    break;}
case 64:
#line 524 "parcer.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-2].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 65:
#line 525 "parcer.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-3].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 66:
#line 530 "parcer.y"
{ yyval.uStmt = createStmt(eExpr, yyvsp[0].uExpr, NULL); ;
    break;}
case 67:
#line 531 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 68:
#line 532 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 69:
#line 533 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 70:
#line 534 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 71:
#line 535 "parcer.y"
{ yyval.uStmt = createReturnStmt(yyvsp[0].uExpr); ;
    break;}
case 72:
#line 539 "parcer.y"
{ yyval.uStmtSeq = NULL; ;
    break;}
case 73:
#line 540 "parcer.y"
{ yyval.uStmtSeq = yyvsp[0].uStmtSeq; ;
    break;}
case 74:
#line 543 "parcer.y"
{ yyval.uStmtSeq = createStmtSeq(yyvsp[0].uStmt); ;
    break;}
case 75:
#line 544 "parcer.y"
{ yyval.uStmtSeq = addStmtToSeq(yyvsp[-2].uStmtSeq, yyvsp[0].uStmt); ;
    break;}
case 76:
#line 545 "parcer.y"
{ yyval.uStmtSeq = yyvsp[-1].uStmtSeq; ;
    break;}
case 77:
#line 548 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 78:
#line 549 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 79:
#line 550 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 80:
#line 551 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 81:
#line 552 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 82:
#line 555 "parcer.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(NULL); ;
    break;}
case 83:
#line 556 "parcer.y"
{ yyval.uMethodDefParamSeq = yyvsp[0].uMethodDefParamSeq;;
    break;}
case 84:
#line 559 "parcer.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(yyvsp[0].uMethodDefParam); ;
    break;}
case 85:
#line 560 "parcer.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-3].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 86:
#line 561 "parcer.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-2].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 87:
#line 564 "parcer.y"
{ yyval.uMethodDefParam = createMethodDefParam(yyvsp[0].uId); ;
    break;}
case 88:
#line 567 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 89:
#line 568 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 90:
#line 569 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 91:
#line 570 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 92:
#line 572 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 93:
#line 573 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 94:
#line 574 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 95:
#line 575 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 96:
#line 578 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 97:
#line 579 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 98:
#line 580 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 99:
#line 581 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 100:
#line 584 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 101:
#line 585 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 102:
#line 586 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 103:
#line 587 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 104:
#line 589 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 105:
#line 590 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 106:
#line 591 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 107:
#line 592 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 108:
#line 595 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 109:
#line 596 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 110:
#line 597 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 111:
#line 598 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 112:
#line 620 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 113:
#line 621 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 114:
#line 622 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 115:
#line 623 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 116:
#line 625 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 117:
#line 626 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
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
#line 645 "parcer.y"

void yyerror(char const *s)
{
 printf("%s !!!!!!11",s);
}

