
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

struct ExprNode* createQBracketsExpr(struct ExprNode* left, struct ExprNode* right)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eQBrackets;
	result->left = left;
	result->right = right;
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
	result->params = NULL;
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



#line 360 "parcer.y"
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



#define	YYFINAL		385
#define	YYFLAG		-32768
#define	YYNTBASE	45

#define YYTRANSLATE(x) ((unsigned)(x) <= 285 ? yytranslate[x] : 58)

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
   225,   233,   238,   245,   253,   262,   272,   281,   283,   287,
   292,   298,   305,   311,   313,   315,   319,   324,   330,   337,
   343,   344,   346,   348,   352,   357,   359,   361,   363,   365,
   367,   370,   372,   373,   375,   377,   381,   384,   394,   405,
   414,   424,   432,   440,   449,   458,   468,   475,   476,   478,
   480,   485,   489,   491,   498,   504,   512,   519,   527,   534,
   543,   551,   562,   572,   582,   591,   601,   610,   619,   627,
   634,   640,   648,   655,   663,   670,   679,   687,   698,   708,
   718,   727,   737,   746,   755,   763,   773,   782,   791,   799,
   806,   812,   813,   815,   820,   826,   835,   846,   854
};

static const short yyrhs[] = {    49,
     0,     5,    49,     0,    46,    33,    46,     0,    46,    33,
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
     5,    39,     0,    40,     5,    47,    39,     0,    40,     5,
    47,     5,    39,     0,    40,    47,     5,    39,     0,    40,
    47,    39,     0,    40,    39,     0,    40,     5,    39,     0,
     3,     0,     4,     0,    21,     0,    22,     0,    23,     0,
    46,    38,    15,     0,    46,    38,    15,    43,    42,     0,
    46,    38,    15,    43,    47,    42,     0,    46,    38,    15,
    43,     5,    47,    42,     0,    46,    38,    15,    43,     5,
    47,     5,    42,     0,    46,    38,    15,    43,    47,     5,
    42,     0,    46,    38,     5,    15,     0,    46,    38,     5,
    15,    43,    42,     0,    46,    38,     5,    15,    43,    47,
    42,     0,    46,    38,     5,    15,    43,     5,    47,    42,
     0,    46,    38,     5,    15,    43,     5,    47,     5,    42,
     0,    46,    38,     5,    15,    43,    47,     5,    42,     0,
    15,     0,    15,    43,    42,     0,    15,    43,    47,    42,
     0,    15,    43,     5,    47,    42,     0,    15,    43,     5,
    47,     5,    42,     0,    15,    43,    47,     5,    42,     0,
    12,     0,    13,     0,    13,    43,    42,     0,    13,    43,
    47,    42,     0,    13,    43,     5,    47,    42,     0,    13,
    43,     5,    47,     5,    42,     0,    13,    43,    47,     5,
    42,     0,     0,    47,     0,    46,     0,    47,    44,    46,
     0,    47,    44,     5,    46,     0,    46,     0,    51,     0,
    57,     0,    55,     0,    56,     0,    14,    46,     0,    14,
     0,     0,    50,     0,    48,     0,    50,     5,    48,     0,
    50,     5,     0,     6,     5,    15,    43,    52,     5,    42,
    49,     7,     0,     6,     5,    15,    43,    52,     5,    42,
     5,    49,     7,     0,     6,     5,    15,    43,    52,    42,
    49,     7,     0,     6,     5,    15,    43,    52,    42,     5,
    49,     7,     0,     6,     5,    15,    52,     5,    49,     7,
     0,     6,    15,    43,    52,    42,    49,     7,     0,     6,
    15,    43,    52,    42,     5,    49,     7,     0,     6,    15,
    43,    52,     5,    42,    49,     7,     0,     6,    15,    43,
    52,     5,    42,     5,    49,     7,     0,     6,    15,    52,
     5,    49,     7,     0,     0,    53,     0,    54,     0,    52,
    44,     5,    54,     0,    52,    44,    54,     0,    15,     0,
     8,     5,    46,     9,    49,     7,     0,     8,    46,     9,
    49,     7,     0,     8,     5,    46,     9,     5,    49,     7,
     0,     8,    46,     9,     5,    49,     7,     0,     8,     5,
    46,     5,     9,    49,     7,     0,     8,    46,     5,     9,
    49,     7,     0,     8,     5,    46,     5,     9,     5,    49,
     7,     0,     8,    46,     5,     9,     5,    49,     7,     0,
     8,     5,    43,     5,    46,     5,    42,     5,    49,     7,
     0,     8,     5,    43,     5,    46,    42,     5,    49,     7,
     0,     8,     5,    43,    46,     5,    42,     5,    49,     7,
     0,     8,     5,    43,    46,    42,     5,    49,     7,     0,
     8,    43,     5,    46,     5,    42,     5,    49,     7,     0,
     8,    43,     5,    46,    42,     5,    49,     7,     0,     8,
    43,    46,     5,    42,     5,    49,     7,     0,     8,    43,
    46,    42,     5,    49,     7,     0,    10,     5,    46,     9,
    49,     7,     0,    10,    46,     9,    49,     7,     0,    10,
     5,    46,     9,     5,    49,     7,     0,    10,    46,     9,
     5,    49,     7,     0,    10,     5,    46,     5,     9,    49,
     7,     0,    10,    46,     5,     9,    49,     7,     0,    10,
     5,    46,     5,     9,     5,    49,     7,     0,    10,    46,
     5,     9,     5,    49,     7,     0,    10,     5,    43,     5,
    46,     5,    42,     5,    49,     7,     0,    10,     5,    43,
     5,    46,    42,     5,    49,     7,     0,    10,     5,    43,
    46,     5,    42,     5,    49,     7,     0,    10,     5,    43,
    46,    42,     5,    49,     7,     0,    10,    43,     5,    46,
     5,    42,     5,    49,     7,     0,    10,    43,     5,    46,
    42,     5,    49,     7,     0,    10,    43,    46,     5,    42,
     5,    49,     7,     0,    10,    43,    46,    42,     5,    49,
     7,     0,    11,     5,    15,    30,     5,    15,     5,    49,
     7,     0,    11,     5,    15,    30,    15,     5,    49,     7,
     0,    11,    15,    30,     5,    15,     5,    49,     7,     0,
    11,    15,    30,    15,     5,    49,     7,     0,    11,     5,
    15,     5,    49,     7,     0,    11,    15,     5,    49,     7,
     0,     0,     0,     0,    25,    46,    28,    49,     0,     0,
    25,    46,    28,    49,     0,    24,     5,    46,     5,    28,
    49,     0,     7,     0,    24,     5,    46,     5,    28,    49,
     0,    26,    49,     7,     0,    27,     5,    46,     5,    28,
    49,     7,     0,    27,     5,    46,     5,    28,    49,    26,
    49,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   437,   438,   441,   442,   444,   445,   447,   448,   450,   451,
   453,   454,   456,   457,   459,   460,   462,   463,   465,   466,
   468,   469,   471,   473,   474,   476,   478,   479,   480,   481,
   483,   484,   485,   486,   488,   489,   490,   491,   493,   494,
   496,   497,   498,   499,   500,   501,   503,   504,   505,   506,
   507,   509,   510,   511,   512,   513,   514,   517,   518,   519,
   520,   521,   522,   523,   525,   526,   527,   528,   529,   530,
   533,   534,   537,   538,   539,   544,   545,   546,   547,   548,
   549,   550,   554,   555,   558,   559,   560,   563,   564,   565,
   566,   567,   568,   569,   570,   571,   572,   575,   576,   579,
   580,   581,   584,   587,   588,   589,   590,   592,   593,   594,
   595,   597,   598,   599,   600,   603,   604,   605,   606,   609,
   610,   611,   612,   614,   615,   616,   617,   619,   620,   621,
   622,   625,   626,   627,   628,   650,   651,   652,   653,   655,
   656,   659,   660,   663,   664,   667,   668,   671,   672
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID",
"SPACE_BRACKET","EQUAL","NOTEQUAL","OR","AND","NIL","TRUE","FALSE","IF","ELSIF",
"ELSE","UNLESS","THEN","'='","'<'","'>'","'-'","'+'","'*'","'/'","'!'","UMINUS",
"'.'","']'","'['","UBR","')'","'('","','","program","expr","expr_seqE","stmt",
"stmt_seq","stmt_seqE","method_def","method_def_param_seq","method_def_param_seqE",
"method_def_param","while_stmt","until_stmt","class_def","class_def"
};
#endif

static const short yyr1[] = {     0,
    45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    -1,    -1,    47,    47,    47,    48,    48,    48,    48,    48,
    48,    48,    49,    49,    50,    50,    50,    51,    51,    51,
    51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
    53,    53,    54,    55,    55,    55,    55,    55,    55,    55,
    55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
    56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
    56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1
};

static const short yyr2[] = {     0,
     1,     2,     3,     4,     4,     3,     4,     3,     4,     3,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     2,     3,     4,     2,     3,     4,     4,     5,
     4,     5,     5,     6,     4,     5,     4,     3,     2,     3,
     1,     1,     1,     1,     1,     3,     5,     6,     7,     8,
     7,     4,     6,     7,     8,     9,     8,     1,     3,     4,
     5,     6,     5,     1,     1,     3,     4,     5,     6,     5,
     0,     1,     1,     3,     4,     1,     1,     1,     1,     1,
     2,     1,     0,     1,     1,     3,     2,     9,    10,     8,
     9,     7,     7,     8,     8,     9,     6,     0,     1,     1,
     4,     3,     1,     6,     5,     7,     6,     7,     6,     8,
     7,    10,     9,     9,     8,     9,     8,     8,     7,     6,
     5,     7,     6,     7,     6,     8,     7,    10,     9,     9,
     8,     9,     8,     8,     7,     9,     8,     8,     7,     6,
     5,     0,     1,     4,     5,     8,    10,     7,     9
};

static const short yydefact[] = {    83,
    41,    42,    83,     0,     0,     0,     0,    64,    65,    82,
    58,    43,    44,    45,     0,     0,     0,     0,    76,    85,
     1,    84,    77,    79,    80,    78,     2,     0,    98,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
    26,    23,     0,    39,    73,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    87,    98,   103,    98,     0,    99,   100,     0,     0,
     0,     0,     0,    83,     0,     0,     0,     0,     0,    83,
     0,    83,     0,     0,    66,     0,     0,    59,     0,    40,
     0,     0,    38,     0,     0,     0,    27,     0,    15,     0,
    17,     0,    19,     0,    21,     0,    24,     0,    11,     0,
    13,     0,     6,     0,     3,     0,     8,     0,    10,     0,
    46,     0,     0,    86,    98,     0,     0,    83,     0,     0,
     0,     0,    83,     0,     0,    27,    83,    83,     0,     0,
     0,     0,    83,     0,     0,    27,    83,    83,     0,    83,
     0,     0,     0,     0,     0,     0,    67,     0,     0,    60,
     0,    35,    37,     0,    74,     0,    29,    28,    16,    18,
    20,    22,    25,    12,    14,     5,     4,     7,     9,    52,
     0,     0,     0,    31,     0,    83,     0,    83,     0,     0,
   102,     0,     0,    27,    83,    83,     0,     0,    29,    28,
    83,    83,     0,     0,   105,     0,     0,    27,    83,    83,
     0,     0,    29,    28,    83,    83,     0,     0,   121,     0,
     0,     0,   141,     0,    83,     0,    68,    70,     0,    61,
    63,    36,    75,    30,     0,     0,    47,     0,     0,    33,
    32,     0,    83,     0,    83,    83,     0,    97,   101,     0,
    29,    28,    83,    83,     0,     0,   104,    30,    83,    83,
     0,     0,   109,   107,     0,    29,    28,    83,    83,     0,
     0,   120,    30,    83,    83,     0,     0,   125,   123,   140,
     0,    83,    83,     0,    69,    62,     0,    53,     0,     0,
     0,    48,    34,    83,    83,     0,    92,    83,     0,     0,
    93,    30,    83,    83,     0,     0,   108,   106,    83,     0,
     0,   119,   111,    30,    83,    83,     0,     0,   124,   122,
    83,     0,     0,   135,   127,    83,     0,     0,   139,     0,
     0,    54,     0,    49,    51,    83,     0,     0,    90,     0,
    95,    94,    83,     0,     0,   115,   110,     0,   117,   118,
    83,     0,     0,   131,   126,     0,   133,   134,     0,   137,
   138,     0,    55,    57,    50,     0,    88,    91,    96,     0,
   113,   114,   116,     0,   129,   130,   132,   136,    56,    89,
   112,   128,     0,     0,     0
};

static const short yydefgoto[] = {   383,
    19,    46,    20,    21,    22,    23,    66,    67,    68,    24,
    25,    26
};

static const short yypact[] = {   146,
-32768,-32768,   820,     4,   950,   976,    18,-32768,   -32,  1438,
   -26,-32768,-32768,-32768,  1438,  1438,   205,  1002,  2002,-32768,
-32768,    32,-32768,-32768,-32768,-32768,-32768,    25,   -13,  1476,
  1028,  1820,  1481,  1054,  1852,    71,    13,   846,  2002,   872,
   -18,   -18,  1070,-32768,  2002,     0,  1438,  1509,  1111,  1116,
  1157,  1162,  1203,  1208,  1249,  1254,  1295,  1300,  1341,    20,
  1346,   820,    -9,-32768,    73,     2,-32768,-32768,  1387,  1884,
  1438,  1540,    81,   331,  1392,  1916,  1438,  1571,    94,   372,
    65,   820,    82,  1438,-32768,    16,  1438,-32768,    19,-32768,
    37,    54,-32768,  1433,  1602,    75,-32768,  1438,   326,  1438,
   326,  1438,   229,  1438,  2021,  1438,  2002,  1438,   162,  1438,
   162,  1438,   136,  1438,   136,  1438,   -18,  1438,   -18,   100,
    76,  1438,  1947,-32768,    73,    21,    22,   820,    84,  1438,
  1633,   109,   413,  1664,    80,-32768,   454,   820,   122,  1438,
  1695,   123,   495,  1726,    95,-32768,   536,   820,   132,   820,
    86,   134,   127,   138,    63,   111,-32768,    69,   113,-32768,
   125,-32768,-32768,  1438,  2002,   124,-32768,-32768,   326,   326,
   229,  2021,  2002,   162,   162,   136,   136,   -18,   -18,   129,
   898,  1978,   141,-32768,    79,   820,   135,   577,   174,    73,
-32768,  1757,   142,-32768,   618,   820,   180,   148,-32768,-32768,
   820,   820,   181,   184,-32768,  1788,   159,-32768,   659,   820,
   196,   163,-32768,-32768,   820,   820,   197,   204,-32768,   207,
   200,   211,-32768,   214,   820,   182,-32768,-32768,   183,-32768,
-32768,-32768,  2002,-32768,   924,  1438,-32768,    89,   190,-32768,
-32768,   188,   700,   216,   741,   820,   224,-32768,-32768,   193,
-32768,-32768,   820,   820,   225,   231,-32768,-32768,   820,   820,
   232,   245,-32768,-32768,   194,-32768,-32768,   820,   820,   246,
   247,-32768,-32768,   820,   820,   248,   251,-32768,-32768,-32768,
   263,   820,   820,   266,-32768,-32768,  1438,-32768,   104,   121,
   228,-32768,-32768,   782,   820,   267,-32768,   820,   270,   271,
-32768,-32768,   820,   820,   274,   275,-32768,-32768,   820,   276,
   277,-32768,-32768,-32768,   820,   820,   279,   280,-32768,-32768,
   820,   281,   282,-32768,-32768,   820,   283,   286,-32768,   131,
   252,-32768,   254,-32768,-32768,   820,   290,   291,-32768,   292,
-32768,-32768,   820,   295,   296,-32768,-32768,   297,-32768,-32768,
   820,   298,   300,-32768,-32768,   301,-32768,-32768,   302,-32768,
-32768,   268,-32768,-32768,-32768,   304,-32768,-32768,-32768,   307,
-32768,-32768,-32768,   308,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   316,   317,-32768
};

static const short yypgoto[] = {-32768,
    -2,    40,   257,    -3,-32768,-32768,   -53,-32768,  -128,-32768,
-32768,-32768
};


#define	YYLAST		2061


static const short yytable[] = {    27,
   191,    64,    32,    35,    92,    64,   128,    39,    28,   126,
    38,   127,    41,    42,    45,    48,    40,    82,    29,    60,
   156,    61,    36,   159,   120,   186,   187,    70,    72,    65,
    76,    78,    37,   125,   121,    45,    62,    45,    93,    63,
    45,   161,    83,    94,    95,   129,    99,   101,   103,   105,
   107,   109,   111,   113,   115,   117,   119,   157,   123,    94,
   160,   249,    94,   188,   129,   129,   131,   226,   134,   150,
   139,   185,   141,   229,   144,   162,   149,    86,   152,    89,
    94,    45,    91,   242,    45,    81,   153,    64,   190,   137,
   221,   165,   163,   291,   151,   169,   154,   170,    64,   171,
   222,   172,   147,   173,   227,   174,    94,   175,   331,   176,
   230,   177,    94,   178,   180,   179,   168,   195,   181,   182,
   243,   200,   129,   155,   189,   333,   158,   192,   205,   197,
   292,   209,    94,   203,   204,   362,   214,   206,   219,   211,
   223,   224,   225,   217,   218,   332,   220,    94,     1,     2,
     3,     4,   228,     5,   231,     6,     7,     8,     9,    10,
    11,   233,   334,   232,    94,   234,    12,    13,    14,    58,
    59,   235,   363,    60,    94,    61,   245,    15,    45,   241,
   248,    16,   244,   252,   247,    17,   257,   263,    18,   258,
   264,   255,   256,    56,    57,    58,    59,   261,   262,    60,
   267,    61,   272,   278,   273,   270,   271,     1,     2,    43,
   279,   276,   277,   280,   281,   282,     8,     9,   283,    11,
   238,   284,   297,   285,   286,    12,    13,    14,   293,   294,
   301,   307,    45,    45,   302,   314,    15,   308,   312,   296,
    16,   299,   300,    44,    17,    49,    50,    18,    52,   305,
   306,   313,   319,   320,   324,   310,   311,   325,    54,    55,
    56,    57,    58,    59,   317,   318,    60,   326,    61,   335,
   322,   323,   329,   339,   289,   290,   341,   342,   327,   328,
   346,   347,   349,   350,    45,   354,   355,   357,   358,   360,
   337,   338,   361,   364,   340,   365,   367,   368,   369,   344,
   345,   371,   372,   373,   375,   348,   376,   377,   378,   379,
   380,   352,   353,   381,   382,   384,   385,   356,   124,     0,
     0,     0,   359,     0,     0,     0,   330,     0,     0,     0,
     0,     0,   366,     1,     2,   138,     4,     0,     5,   370,
     6,     7,     8,     9,    10,    11,     0,   374,     0,     0,
     0,    12,    13,    14,     0,    54,    55,    56,    57,    58,
    59,     0,    15,    60,     0,    61,    16,     0,     0,     0,
    17,     0,     0,    18,     1,     2,   148,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     0,     0,     0,    15,     0,     0,     0,    16,     0,     0,
     0,    17,     0,     0,    18,     1,     2,   196,     4,     0,
     5,     0,     6,     7,     8,     9,    10,    11,     0,     0,
     0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     0,     0,     0,    15,     0,     0,     0,    16,     0,
     0,     0,    17,     0,     0,    18,     1,     2,   202,     4,
     0,     5,     0,     6,     7,     8,     9,    10,    11,     0,
     0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
     0,     0,     0,     0,     0,    15,     0,     0,     0,    16,
     0,     0,     0,    17,     0,     0,    18,     1,     2,   210,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
     0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
     0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
    16,     0,     0,     0,    17,     0,     0,    18,     1,     2,
   216,     4,     0,     5,     0,     6,     7,     8,     9,    10,
    11,     0,     0,     0,     0,     0,    12,    13,    14,     0,
     0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
     0,    16,     0,     0,     0,    17,     0,     0,    18,     1,
     2,   246,     4,     0,     5,     0,     6,     7,     8,     9,
    10,    11,     0,     0,     0,     0,     0,    12,    13,    14,
     0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
     0,     0,    16,     0,     0,     0,    17,     0,     0,    18,
     1,     2,   254,     4,     0,     5,     0,     6,     7,     8,
     9,    10,    11,     0,     0,     0,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
     0,     0,     0,    16,     0,     0,     0,    17,     0,     0,
    18,     1,     2,   269,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,     0,     0,     0,     0,     0,    12,
    13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
    15,     0,     0,     0,    16,     0,     0,     0,    17,     0,
     0,    18,     1,     2,   295,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
    12,    13,    14,     0,     0,     0,     0,     0,     0,     0,
     0,    15,     0,     0,     0,    16,     0,     0,     0,    17,
     0,     0,    18,     1,     2,   298,     4,     0,     5,     0,
     6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
     0,    12,    13,    14,     0,     0,     0,     0,     0,     0,
     0,     0,    15,     0,     0,     0,    16,     0,     0,     0,
    17,     0,     0,    18,     1,     2,   336,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     0,     0,     0,    15,     0,     0,     0,    16,     0,     0,
     0,    17,     1,     2,    18,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
    12,    13,    14,     0,     0,     0,     0,     0,     1,     2,
    84,    15,     0,     0,     0,    16,     0,     8,     9,    17,
    11,     0,    18,     0,     0,     0,    12,    13,    14,     0,
     0,     0,     0,     0,     1,     2,    87,    15,     0,     0,
     0,    16,     0,     8,     9,    17,    11,    85,    18,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     1,     2,   236,    15,     0,     0,     0,    16,     0,     8,
     9,    17,    11,    88,    18,     0,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   287,    15,
     0,     0,     0,    16,     0,     8,     9,    17,    11,   237,
    18,     0,     0,     0,    12,    13,    14,     0,     0,     0,
     0,     0,     1,     2,    30,    15,     0,     0,     0,    16,
     0,     8,     9,    17,    11,   288,    18,     0,     0,     0,
    12,    13,    14,     0,     0,     0,     0,     0,     1,     2,
    33,    15,     0,     0,     0,    16,     0,     8,     9,    17,
    11,     0,    31,     0,     0,     0,    12,    13,    14,     0,
     0,     0,     0,     0,     1,     2,    47,    15,     0,     0,
     0,    16,     0,     8,     9,    17,    11,     0,    34,     0,
     0,     0,    12,    13,    14,     0,     0,     0,     0,     0,
     1,     2,    71,    15,     0,     0,     0,    16,     0,     8,
     9,    17,    11,     0,    18,     0,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,    77,    15,
     0,     0,     0,    16,     0,     8,     9,    17,    11,     0,
    18,     0,     1,     2,    12,    13,    14,     0,     0,     0,
     0,     8,     9,     0,    11,    15,     0,     0,     0,    16,
    12,    13,    14,    17,     0,     0,    18,     0,     0,     0,
     0,    15,     0,     0,     0,    16,     0,     0,    90,    17,
     0,     0,    18,     1,     2,    98,     0,     0,     1,     2,
   100,     0,     8,     9,     0,    11,     0,     8,     9,     0,
    11,    12,    13,    14,     0,     0,    12,    13,    14,     0,
     0,     0,    15,     0,     0,     0,    16,    15,     0,     0,
    17,    16,     0,    18,     0,    17,     0,     0,    18,     1,
     2,   102,     0,     0,     1,     2,   104,     0,     8,     9,
     0,    11,     0,     8,     9,     0,    11,    12,    13,    14,
     0,     0,    12,    13,    14,     0,     0,     0,    15,     0,
     0,     0,    16,    15,     0,     0,    17,    16,     0,    18,
     0,    17,     0,     0,    18,     1,     2,   106,     0,     0,
     1,     2,   108,     0,     8,     9,     0,    11,     0,     8,
     9,     0,    11,    12,    13,    14,     0,     0,    12,    13,
    14,     0,     0,     0,    15,     0,     0,     0,    16,    15,
     0,     0,    17,    16,     0,    18,     0,    17,     0,     0,
    18,     1,     2,   110,     0,     0,     1,     2,   112,     0,
     8,     9,     0,    11,     0,     8,     9,     0,    11,    12,
    13,    14,     0,     0,    12,    13,    14,     0,     0,     0,
    15,     0,     0,     0,    16,    15,     0,     0,    17,    16,
     0,    18,     0,    17,     0,     0,    18,     1,     2,   114,
     0,     0,     1,     2,   116,     0,     8,     9,     0,    11,
     0,     8,     9,     0,    11,    12,    13,    14,     0,     0,
    12,    13,    14,     0,     0,     0,    15,     0,     0,     0,
    16,    15,     0,     0,    17,    16,     0,    18,     0,    17,
     0,     0,    18,     1,     2,   118,     0,     0,     1,     2,
   122,     0,     8,     9,     0,    11,     0,     8,     9,     0,
    11,    12,    13,    14,     0,     0,    12,    13,    14,     0,
     0,     0,    15,     0,     0,     0,    16,    15,     0,     0,
    17,    16,     0,    18,     0,    17,     0,     0,    18,     1,
     2,   130,     0,     0,     1,     2,   140,     0,     8,     9,
     0,    11,     0,     8,     9,     0,    11,    12,    13,    14,
     0,     0,    12,    13,    14,     0,     0,     0,    15,     0,
     0,     0,    16,    15,     0,     0,    17,    16,     0,    18,
     0,    17,     0,     0,    18,     1,     2,   164,     0,     0,
     1,     2,     0,     0,     8,     9,     0,    11,     0,     8,
     9,     0,    11,    12,    13,    14,     0,     0,    12,    13,
    14,     0,     0,     0,    15,     0,     0,     0,    16,    15,
     0,     0,    17,    16,     0,    18,     0,    17,     1,     2,
    18,     0,     0,     1,     2,     0,     0,     8,     9,     0,
    11,     0,     8,     9,     0,    11,    12,    13,    14,     0,
     0,    12,    13,    14,     0,     0,     0,    15,     0,     0,
     0,    16,    15,    96,     0,    17,    16,     0,    69,     0,
    17,     0,     0,    75,     0,    49,    50,    51,    52,     0,
     0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
    56,    57,    58,    59,   135,     0,    60,     0,    61,     0,
    97,     0,     0,     0,     0,     0,    49,    50,    51,    52,
     0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
    55,    56,    57,    58,    59,   145,     0,    60,     0,    61,
     0,   136,     0,     0,     0,     0,     0,    49,    50,    51,
    52,     0,     0,     0,     0,     0,     0,     0,     0,    53,
    54,    55,    56,    57,    58,    59,   166,     0,    60,     0,
    61,     0,   146,     0,     0,     0,     0,     0,    49,    50,
    51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
    53,    54,    55,    56,    57,    58,    59,   193,     0,    60,
     0,    61,     0,   167,     0,     0,     0,     0,     0,    49,
    50,    51,    52,     0,     0,     0,     0,     0,     0,     0,
     0,    53,    54,    55,    56,    57,    58,    59,   198,     0,
    60,     0,    61,     0,   194,     0,     0,     0,     0,     0,
    49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     0,     0,    53,    54,    55,    56,    57,    58,    59,   207,
     0,    60,     0,    61,     0,   199,     0,     0,     0,     0,
     0,    49,    50,    51,    52,     0,     0,     0,     0,     0,
     0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
   212,     0,    60,     0,    61,     0,   208,     0,     0,     0,
     0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
     0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
    59,   250,     0,    60,     0,    61,     0,   213,     0,     0,
     0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
     0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
    58,    59,   265,     0,    60,     0,    61,     0,   251,     0,
     0,     0,     0,     0,    49,    50,    51,    52,     0,     0,
     0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
    57,    58,    59,     0,    73,    60,     0,    61,    74,   266,
     0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
     0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
    55,    56,    57,    58,    59,     0,    79,    60,     0,    61,
    80,     0,     0,     0,     0,     0,     0,     0,    49,    50,
    51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
    53,    54,    55,    56,    57,    58,    59,     0,   132,    60,
     0,    61,   133,     0,     0,     0,     0,     0,     0,     0,
    49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
     0,     0,    53,    54,    55,    56,    57,    58,    59,     0,
   142,    60,     0,    61,   143,     0,     0,     0,     0,     0,
     0,     0,    49,    50,    51,    52,     0,     0,     0,     0,
     0,     0,     0,     0,    53,    54,    55,    56,    57,    58,
    59,   183,     0,    60,     0,    61,     0,     0,     0,     0,
     0,     0,     0,    49,    50,    51,    52,     0,     0,     0,
     0,     0,     0,     0,     0,    53,    54,    55,    56,    57,
    58,    59,   239,     0,    60,   184,    61,     0,     0,     0,
     0,     0,     0,     0,    49,    50,    51,    52,     0,     0,
     0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
    57,    58,    59,     0,     0,    60,   240,    61,    49,    50,
    51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
    53,    54,    55,    56,    57,    58,    59,    49,    50,    60,
     0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
    54,    55,    56,    57,    58,    59,     0,     0,    60,     0,
    61
};

static const short yycheck[] = {     3,
   129,    15,     5,     6,     5,    15,     5,    10,     5,    63,
    43,    65,    15,    16,    17,    18,    43,     5,    15,    38,
     5,    40,     5,     5,     5,     5,     5,    30,    31,    43,
    33,    34,    15,    43,    15,    38,     5,    40,    39,    15,
    43,     5,    30,    44,    47,    44,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    42,    61,    44,
    42,   190,    44,    42,    44,    44,    69,     5,    71,     5,
    74,   125,    75,     5,    77,    39,    80,    38,    82,    40,
    44,    84,    43,     5,    87,    15,     5,    15,     5,     9,
     5,    94,    39,     5,    30,    98,    15,   100,    15,   102,
    15,   104,     9,   106,    42,   108,    44,   110,     5,   112,
    42,   114,    44,   116,    15,   118,    42,     9,    43,   122,
    42,    42,    44,    84,   128,     5,    87,   130,     7,   133,
    42,     9,    44,   137,   138,     5,    42,   140,     7,   143,
     7,    15,     5,   147,   148,    42,   150,    44,     3,     4,
     5,     6,    42,     8,    42,    10,    11,    12,    13,    14,
    15,   164,    42,    39,    44,    42,    21,    22,    23,    34,
    35,    43,    42,    38,    44,    40,    42,    32,   181,    39,
     7,    36,   186,    42,   188,    40,     7,     7,    43,    42,
     7,   195,   196,    32,    33,    34,    35,   201,   202,    38,
    42,    40,     7,     7,    42,   209,   210,     3,     4,     5,
     7,   215,   216,     7,    15,     5,    12,    13,     5,    15,
   181,   225,     7,    42,    42,    21,    22,    23,    39,    42,
     7,     7,   235,   236,    42,    42,    32,     7,     7,   243,
    36,   245,   246,    39,    40,    17,    18,    43,    20,   253,
   254,     7,     7,     7,     7,   259,   260,     7,    30,    31,
    32,    33,    34,    35,   268,   269,    38,     5,    40,    42,
   274,   275,     7,     7,   235,   236,     7,     7,   282,   283,
     7,     7,     7,     7,   287,     7,     7,     7,     7,     7,
   294,   295,     7,    42,   298,    42,     7,     7,     7,   303,
   304,     7,     7,     7,     7,   309,     7,     7,     7,    42,
     7,   315,   316,     7,     7,     0,     0,   321,    62,    -1,
    -1,    -1,   326,    -1,    -1,    -1,   287,    -1,    -1,    -1,
    -1,    -1,   336,     3,     4,     5,     6,    -1,     8,   343,
    10,    11,    12,    13,    14,    15,    -1,   351,    -1,    -1,
    -1,    21,    22,    23,    -1,    30,    31,    32,    33,    34,
    35,    -1,    32,    38,    -1,    40,    36,    -1,    -1,    -1,
    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,
    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,
     8,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,
    -1,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,
     5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
    15,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,
     4,     5,     6,    -1,     8,    -1,    10,    11,    12,    13,
    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
     3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
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
    13,    40,    15,    42,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    42,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    42,    43,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,
    15,    -1,    43,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    -1,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    -1,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    -1,
    43,    -1,     3,     4,    21,    22,    23,    -1,    -1,    -1,
    -1,    12,    13,    -1,    15,    32,    -1,    -1,    -1,    36,
    21,    22,    23,    40,    -1,    -1,    43,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,
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
     3,     4,    -1,    -1,    12,    13,    -1,    15,    -1,    12,
    13,    -1,    15,    21,    22,    23,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    32,
    -1,    -1,    40,    36,    -1,    43,    -1,    40,     3,     4,
    43,    -1,    -1,     3,     4,    -1,    -1,    12,    13,    -1,
    15,    -1,    12,    13,    -1,    15,    21,    22,    23,    -1,
    -1,    21,    22,    23,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    32,     5,    -1,    40,    36,    -1,    43,    -1,
    40,    -1,    -1,    43,    -1,    17,    18,    19,    20,    -1,
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
     5,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,     5,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
    34,    35,     5,    -1,    38,    -1,    40,    -1,    42,    -1,
    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,    -1,     5,    38,    -1,    40,     9,    42,
    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
    31,    32,    33,    34,    35,    -1,     5,    38,    -1,    40,
     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    29,    30,    31,    32,    33,    34,    35,    -1,     5,    38,
    -1,    40,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
     5,    38,    -1,    40,     9,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,     5,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
    34,    35,     5,    -1,    38,    39,    40,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,    -1,    -1,    38,    39,    40,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    29,    30,    31,    32,    33,    34,    35,    17,    18,    38,
    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    30,    31,    32,    33,    34,    35,    -1,    -1,    38,    -1,
    40
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
#line 437 "parcer.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 2:
#line 438 "parcer.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 3:
#line 441 "parcer.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 4:
#line 442 "parcer.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 5:
#line 444 "parcer.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 6:
#line 445 "parcer.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 7:
#line 447 "parcer.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 8:
#line 448 "parcer.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 9:
#line 450 "parcer.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 10:
#line 451 "parcer.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 11:
#line 453 "parcer.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 12:
#line 454 "parcer.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 13:
#line 456 "parcer.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 14:
#line 457 "parcer.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 15:
#line 459 "parcer.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 16:
#line 460 "parcer.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 17:
#line 462 "parcer.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 18:
#line 463 "parcer.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 19:
#line 465 "parcer.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 20:
#line 466 "parcer.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 21:
#line 468 "parcer.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 22:
#line 469 "parcer.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 23:
#line 471 "parcer.y"
{ yyval.uExpr = createUnExpr(eNot, yyvsp[0].uExpr); ;
    break;}
case 24:
#line 473 "parcer.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 25:
#line 474 "parcer.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 26:
#line 476 "parcer.y"
{ yyval.uExpr = createUnExpr(eUMinus, yyvsp[0].uExpr); ;
    break;}
case 27:
#line 478 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 28:
#line 479 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 29:
#line 480 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 30:
#line 481 "parcer.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 31:
#line 483 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-3].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 32:
#line 484 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 33:
#line 485 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 34:
#line 486 "parcer.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-5].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 35:
#line 488 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 36:
#line 489 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 37:
#line 490 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 38:
#line 491 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 39:
#line 493 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 40:
#line 494 "parcer.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 41:
#line 496 "parcer.y"
{ yyval.uExpr = createIntExpr(yyvsp[0].uId); ;
    break;}
case 42:
#line 497 "parcer.y"
{ yyval.uExpr = createStrExpr(yyvsp[0].uString); ;
    break;}
case 43:
#line 498 "parcer.y"
{ yyval.uExpr = createNilExpr(); ;
    break;}
case 44:
#line 499 "parcer.y"
{ yyval.uExpr = createBoolExpr(1); ;
    break;}
case 45:
#line 500 "parcer.y"
{ yyval.uExpr = createBoolExpr(0); ;
    break;}
case 46:
#line 501 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-2].uExpr, yyvsp[0].uId, NULL); ;
    break;}
case 47:
#line 503 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-4].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 48:
#line 504 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-5].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 49:
#line 505 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 50:
#line 506 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-7].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 51:
#line 507 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 52:
#line 509 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-3].uExpr, yyvsp[0].uId, NULL); ;
    break;}
case 53:
#line 510 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-5].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 54:
#line 511 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-6].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 55:
#line 512 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 56:
#line 513 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-8].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 57:
#line 514 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 58:
#line 517 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId, NULL); ;
    break;}
case 59:
#line 518 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-2].uId, NULL); ;
    break;}
case 60:
#line 519 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 61:
#line 520 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 62:
#line 521 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 63:
#line 522 "parcer.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 64:
#line 523 "parcer.y"
{ yyval.uExpr = createSelfExpr(); ;
    break;}
case 65:
#line 525 "parcer.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 66:
#line 526 "parcer.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 67:
#line 527 "parcer.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 68:
#line 528 "parcer.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 69:
#line 529 "parcer.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 70:
#line 530 "parcer.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 71:
#line 533 "parcer.y"
{ yyval.uExprSeq = createExprSeq(NULL); ;
    break;}
case 72:
#line 534 "parcer.y"
{ yyval.uExprSeq = yyvsp[0].uExprSeq; ;
    break;}
case 73:
#line 537 "parcer.y"
{ yyval.uExprSeq = createExprSeq(yyvsp[0].uExpr); ;
    break;}
case 74:
#line 538 "parcer.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-2].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 75:
#line 539 "parcer.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-3].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 76:
#line 544 "parcer.y"
{ yyval.uStmt = createStmt(eExpr, yyvsp[0].uExpr, NULL); ;
    break;}
case 77:
#line 545 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 78:
#line 546 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 79:
#line 547 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 80:
#line 548 "parcer.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 81:
#line 549 "parcer.y"
{ yyval.uStmt = createReturnStmt(yyvsp[0].uExpr); ;
    break;}
case 82:
#line 550 "parcer.y"
{ yyval.uStmt = createReturnStmt(NULL); ;
    break;}
case 83:
#line 554 "parcer.y"
{ yyval.uStmtSeq = NULL; ;
    break;}
case 84:
#line 555 "parcer.y"
{ yyval.uStmtSeq = yyvsp[0].uStmtSeq; ;
    break;}
case 85:
#line 558 "parcer.y"
{ yyval.uStmtSeq = createStmtSeq(yyvsp[0].uStmt); ;
    break;}
case 86:
#line 559 "parcer.y"
{ yyval.uStmtSeq = addStmtToSeq(yyvsp[-2].uStmtSeq, yyvsp[0].uStmt); ;
    break;}
case 87:
#line 560 "parcer.y"
{ yyval.uStmtSeq = yyvsp[-1].uStmtSeq; ;
    break;}
case 88:
#line 563 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 89:
#line 564 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 90:
#line 565 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 91:
#line 566 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 92:
#line 567 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 93:
#line 568 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 94:
#line 569 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 95:
#line 570 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 96:
#line 571 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 97:
#line 572 "parcer.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 98:
#line 575 "parcer.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(NULL); ;
    break;}
case 99:
#line 576 "parcer.y"
{ yyval.uMethodDefParamSeq = yyvsp[0].uMethodDefParamSeq;;
    break;}
case 100:
#line 579 "parcer.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(yyvsp[0].uMethodDefParam); ;
    break;}
case 101:
#line 580 "parcer.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-3].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 102:
#line 581 "parcer.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-2].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 103:
#line 584 "parcer.y"
{ yyval.uMethodDefParam = createMethodDefParam(yyvsp[0].uId); ;
    break;}
case 104:
#line 587 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 105:
#line 588 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 106:
#line 589 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 107:
#line 590 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 108:
#line 592 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 109:
#line 593 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 110:
#line 594 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 111:
#line 595 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 112:
#line 597 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 113:
#line 598 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 114:
#line 599 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 115:
#line 600 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 116:
#line 603 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 117:
#line 604 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 118:
#line 605 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 119:
#line 606 "parcer.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 120:
#line 609 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 121:
#line 610 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 122:
#line 611 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 123:
#line 612 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 124:
#line 614 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 125:
#line 615 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 126:
#line 616 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 127:
#line 617 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 128:
#line 619 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 129:
#line 620 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 130:
#line 621 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 131:
#line 622 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 132:
#line 625 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 133:
#line 626 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 134:
#line 627 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 135:
#line 628 "parcer.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 136:
#line 650 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 137:
#line 651 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 138:
#line 652 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 139:
#line 653 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 140:
#line 655 "parcer.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 141:
#line 656 "parcer.y"
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
#line 675 "parcer.y"

void yyerror(char const *s)
{
 printf("%s !!!!!!11",s);
}

