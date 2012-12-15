
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
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
#define	IDFIELD	271
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

#line 1 "parser.y"

#include <stdio.h>
#include <malloc.h>
#include "structures.h"

void yyerror(const char *s);
extern int yylex(void);
struct ProgramNode* root;

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

/*struct ExprNode* createIdExpr(char* idStr)
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
} */

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

struct ExprNode* createFieldAccExpr(struct ExprNode* left, char* idStr)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eFieldAcc;
	result->left = left;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = idStr;
	result->str = NULL;
	
	return result;
}

struct ExprNode* createLocalExpr(char* idStr)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eLocal;
	result->left = NULL;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = idStr;
	result->str = NULL;
	
	return result;
}

struct ExprNode* createMethodCallExpr(struct ExprNode* left, char* idStr, struct ExprSeqNode* params)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eMethodCall;
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
	result->elseStmtBlock = NULL;
	result->elsifList = NULL;
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
	result->elseStmtBlock = NULL;
	result->elsifList = NULL;
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
		seq->last->next = statement;
	else
		seq->first = statement;
		
	seq->last = statement;
	
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
	result->elseStmtBlock = NULL;
	result->elsifList = NULL;
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
	result->elseStmtBlock = NULL;
	result->elsifList = NULL;
	return result;
}

struct ProgramNode* createProgram(struct StmtSeqNode* body)
{
	struct ProgramNode* result = (struct ProgramNode*)malloc(sizeof(struct ProgramNode));
	
	result->body = body;
	
	return result;
}

struct ElsifSeqNode* createElsifSeq(struct ExprNode *expression, struct StmtSeqNode *stmtSeqBlock)
{
	struct ElsifSeqNode *result = (struct ElsifSeqNode*)malloc(sizeof(struct ElsifSeqNode));
	
	result->first = (struct ElsifNode*)malloc(sizeof(struct ElsifNode));
	result->first->expr = expression;
	result->first->block = stmtSeqBlock;
	result->first->next = NULL;
	
	result->last = result->first;
		
	return result;
}
struct ElsifSeqNode* addToElsifSeq(struct ElsifSeqNode *seq, struct ExprNode *expression, struct StmtSeqNode *stmtSeqBlock)
{
	if(seq->first != NULL)
	{
		seq->last->next = (struct ElsifNode*)malloc(sizeof(struct ElsifNode));
		seq->last->next->expr = expression;
		seq->last->next->block = stmtSeqBlock;
		seq->last->next->next = NULL;
		seq->last = seq->last->next;
	}
	else
	{
		seq->first = (struct ElsifNode*)malloc(sizeof(struct ElsifNode));
		seq->first->expr = expression;
		seq->first->block = stmtSeqBlock;
		seq->first->next = NULL;
		seq->last = seq->first;
	}
	
	return seq;
}
struct StmtNode* createIfStmt(struct ExprNode *expression, struct StmtSeqNode* ifBlock, struct ElsifSeqNode* elsifBlock, struct StmtSeqNode* elseBlock)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	
	result->type = eIf;
	result->expr = expression;
	result->block = ifBlock;
	result->elseStmtBlock = elseBlock;
	result->elsifList = elsifBlock;
	result->params = NULL;
	result->next = NULL;
	return result;
}

struct StmtNode* createUnlessStmt(struct ExprNode *expression, struct StmtSeqNode* unlessBlock, struct StmtSeqNode* elseBlock)
{
	struct StmtNode* result = (struct StmtNode*)malloc(sizeof(struct StmtNode));
	
	result->type = eUnless;
	result->expr = expression;
	result->block = unlessBlock;
	result->elseStmtBlock = elseBlock;
	result->elsifList = NULL;
	result->params = NULL;
	result->next = NULL;
	return result;
}


#line 450 "parser.y"
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
	struct ElsifSeqNode *uElsifSeq;
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



#define	YYFINAL		574
#define	YYFLAG		-32768
#define	YYNTBASE	45

#define YYTRANSLATE(x) ((unsigned)(x) <= 285 ? yytranslate[x] : 62)

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
   181,   183,   185,   187,   189,   191,   197,   204,   212,   221,
   229,   236,   244,   253,   263,   272,   274,   276,   280,   285,
   291,   298,   304,   306,   310,   315,   321,   328,   334,   336,
   340,   345,   347,   349,   351,   353,   355,   357,   359,   362,
   364,   365,   367,   369,   373,   376,   386,   397,   406,   416,
   424,   432,   441,   450,   460,   467,   468,   470,   472,   477,
   481,   483,   490,   496,   504,   511,   519,   526,   535,   543,
   554,   564,   574,   583,   593,   602,   611,   619,   626,   632,
   640,   647,   655,   662,   671,   679,   690,   700,   710,   719,
   729,   738,   747,   755,   765,   774,   783,   791,   798,   804,
   805,   807,   812,   818,   824,   830,   837,   844,   851,   859,
   865,   872,   879,   887,   894,   902,   910,   919,   926,   935,
   943,   951,   960,   970,   980,   991,   999,  1008,  1017,  1027,
  1037,  1048,  1059,  1070,  1082,  1094,  1107,  1113,  1121,  1128,
  1135,  1143,  1152,  1161,  1171,  1178,  1186,  1194,  1203,  1212,
  1222,  1232,  1242,  1253,  1264
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
    46,    38,    15,    43,    42,     0,    46,    38,    15,    43,
    47,    42,     0,    46,    38,    15,    43,     5,    47,    42,
     0,    46,    38,    15,    43,     5,    47,     5,    42,     0,
    46,    38,    15,    43,    47,     5,    42,     0,    46,    38,
     5,    15,    43,    42,     0,    46,    38,     5,    15,    43,
    47,    42,     0,    46,    38,     5,    15,    43,     5,    47,
    42,     0,    46,    38,     5,    15,    43,     5,    47,     5,
    42,     0,    46,    38,     5,    15,    43,    47,     5,    42,
     0,    15,     0,    16,     0,    15,    43,    42,     0,    15,
    43,    47,    42,     0,    15,    43,     5,    47,    42,     0,
    15,    43,     5,    47,     5,    42,     0,    15,    43,    47,
     5,    42,     0,    12,     0,    13,    43,    42,     0,    13,
    43,    47,    42,     0,    13,    43,     5,    47,    42,     0,
    13,    43,     5,    47,     5,    42,     0,    13,    43,    47,
     5,    42,     0,    46,     0,    47,    44,    46,     0,    47,
    44,     5,    46,     0,    46,     0,    51,     0,    57,     0,
    55,     0,    56,     0,    60,     0,    61,     0,    14,    46,
     0,    14,     0,     0,    50,     0,    48,     0,    50,     5,
    48,     0,    50,     5,     0,     6,     5,    15,    43,    52,
     5,    42,    49,     7,     0,     6,     5,    15,    43,    52,
     5,    42,     5,    49,     7,     0,     6,     5,    15,    43,
    52,    42,    49,     7,     0,     6,     5,    15,    43,    52,
    42,     5,    49,     7,     0,     6,     5,    15,    52,     5,
    49,     7,     0,     6,    15,    43,    52,    42,    49,     7,
     0,     6,    15,    43,    52,    42,     5,    49,     7,     0,
     6,    15,    43,    52,     5,    42,    49,     7,     0,     6,
    15,    43,    52,     5,    42,     5,    49,     7,     0,     6,
    15,    52,     5,    49,     7,     0,     0,    53,     0,    54,
     0,    52,    44,     5,    54,     0,    52,    44,    54,     0,
    15,     0,     8,     5,    46,     9,    49,     7,     0,     8,
    46,     9,    49,     7,     0,     8,     5,    46,     9,     5,
    49,     7,     0,     8,    46,     9,     5,    49,     7,     0,
     8,     5,    46,     5,     9,    49,     7,     0,     8,    46,
     5,     9,    49,     7,     0,     8,     5,    46,     5,     9,
     5,    49,     7,     0,     8,    46,     5,     9,     5,    49,
     7,     0,     8,     5,    43,     5,    46,     5,    42,     5,
    49,     7,     0,     8,     5,    43,     5,    46,    42,     5,
    49,     7,     0,     8,     5,    43,    46,     5,    42,     5,
    49,     7,     0,     8,     5,    43,    46,    42,     5,    49,
     7,     0,     8,    43,     5,    46,     5,    42,     5,    49,
     7,     0,     8,    43,     5,    46,    42,     5,    49,     7,
     0,     8,    43,    46,     5,    42,     5,    49,     7,     0,
     8,    43,    46,    42,     5,    49,     7,     0,    10,     5,
    46,     9,    49,     7,     0,    10,    46,     9,    49,     7,
     0,    10,     5,    46,     9,     5,    49,     7,     0,    10,
    46,     9,     5,    49,     7,     0,    10,     5,    46,     5,
     9,    49,     7,     0,    10,    46,     5,     9,    49,     7,
     0,    10,     5,    46,     5,     9,     5,    49,     7,     0,
    10,    46,     5,     9,     5,    49,     7,     0,    10,     5,
    43,     5,    46,     5,    42,     5,    49,     7,     0,    10,
     5,    43,     5,    46,    42,     5,    49,     7,     0,    10,
     5,    43,    46,     5,    42,     5,    49,     7,     0,    10,
     5,    43,    46,    42,     5,    49,     7,     0,    10,    43,
     5,    46,     5,    42,     5,    49,     7,     0,    10,    43,
     5,    46,    42,     5,    49,     7,     0,    10,    43,    46,
     5,    42,     5,    49,     7,     0,    10,    43,    46,    42,
     5,    49,     7,     0,    11,     5,    15,    30,     5,    15,
     5,    49,     7,     0,    11,     5,    15,    30,    15,     5,
    49,     7,     0,    11,    15,    30,     5,    15,     5,    49,
     7,     0,    11,    15,    30,    15,     5,    49,     7,     0,
    11,     5,    15,     5,    49,     7,     0,    11,    15,     5,
    49,     7,     0,     0,    59,     0,    25,    46,    28,    49,
     0,    59,    25,    46,    28,    49,     0,    25,     5,    46,
    28,    49,     0,    25,    46,     5,    28,    49,     0,    25,
     5,    46,     5,    28,    49,     0,    59,    25,     5,    46,
    28,    49,     0,    59,    25,    46,     5,    28,    49,     0,
    59,    25,     5,    46,     5,    28,    49,     0,    25,    46,
    28,     5,    49,     0,    25,    46,     5,    28,     5,    49,
     0,    25,     5,    46,    28,     5,    49,     0,    25,     5,
    46,     5,    28,     5,    49,     0,    59,    25,    46,    28,
     5,    49,     0,    59,    25,    46,     5,    28,     5,    49,
     0,    59,    25,     5,    46,    28,     5,    49,     0,    59,
    25,     5,    46,     5,    28,     5,    49,     0,    24,    46,
    28,    49,    58,     7,     0,    24,    46,    28,    49,    58,
    26,    49,     7,     0,    24,     5,    46,    28,    49,    58,
     7,     0,    24,    46,     5,    28,    49,    58,     7,     0,
    24,     5,    46,     5,    28,    49,    58,     7,     0,    24,
     5,    46,    28,    49,    58,    26,    49,     7,     0,    24,
    46,     5,    28,    49,    58,    26,    49,     7,     0,    24,
     5,    46,     5,    28,    49,    58,    26,    49,     7,     0,
    24,    46,    28,     5,    49,    58,     7,     0,    24,     5,
    46,    28,     5,    49,    58,     7,     0,    24,    46,     5,
    28,     5,    49,    58,     7,     0,    24,     5,    46,     5,
    28,     5,    49,    58,     7,     0,    24,    46,    28,    49,
    58,    26,     5,    49,     7,     0,    24,    46,    28,     5,
    49,    58,    26,     5,    49,     7,     0,    24,    46,     5,
    28,    49,    58,    26,     5,    49,     7,     0,    24,     5,
    46,    28,    49,    58,    26,     5,    49,     7,     0,    24,
     5,    46,     5,    28,    49,    58,    26,     5,    49,     7,
     0,    24,     5,    46,    28,     5,    49,    58,    26,     5,
    49,     7,     0,    24,     5,    46,     5,    28,     5,    49,
    58,    26,     5,    49,     7,     0,    27,    46,    28,    49,
     7,     0,    27,    46,    28,    49,    26,    49,     7,     0,
    27,     5,    46,    28,    49,     7,     0,    27,    46,     5,
    28,    49,     7,     0,    27,     5,    46,     5,    28,    49,
     7,     0,    27,     5,    46,    28,    49,    26,    49,     7,
     0,    27,    46,     5,    28,    49,    26,    49,     7,     0,
    27,     5,    46,     5,    28,    49,    26,    49,     7,     0,
    27,    46,    28,     5,    49,     7,     0,    27,    46,     5,
    28,     5,    49,     7,     0,    27,     5,    46,    28,     5,
    49,     7,     0,    27,     5,    46,     5,    28,     5,    49,
     7,     0,    27,    46,    28,    49,    26,     5,    49,     7,
     0,    27,    46,    28,     5,    49,    26,     5,    49,     7,
     0,    27,    46,     5,    28,    49,    26,     5,    49,     7,
     0,    27,     5,    46,    28,    49,    26,     5,    49,     7,
     0,    27,    46,     5,    28,     5,    49,    26,     5,    49,
     7,     0,    27,     5,    46,    28,     5,    49,    26,     5,
    49,     7,     0,    27,     5,    46,     5,    28,     5,    49,
    26,     5,    49,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   531,   532,   535,   536,   538,   539,   541,   542,   544,   545,
   547,   548,   550,   551,   553,   554,   556,   557,   559,   560,
   562,   563,   565,   567,   568,   570,   572,   573,   574,   575,
   577,   578,   579,   580,   582,   583,   584,   585,   587,   588,
   590,   591,   592,   593,   594,   596,   597,   598,   599,   600,
   602,   603,   604,   605,   606,   609,   610,   611,   612,   613,
   614,   615,   616,   618,   619,   620,   621,   622,   625,   626,
   627,   630,   631,   632,   633,   634,   635,   636,   637,   638,
   642,   643,   646,   647,   648,   651,   652,   653,   654,   655,
   656,   657,   658,   659,   660,   663,   664,   667,   668,   669,
   672,   675,   676,   677,   678,   680,   681,   682,   683,   685,
   686,   687,   688,   691,   692,   693,   694,   697,   698,   699,
   700,   702,   703,   704,   705,   707,   708,   709,   710,   713,
   714,   715,   716,   720,   721,   722,   723,   725,   726,   729,
   730,   733,   734,   736,   737,   738,   740,   741,   742,   744,
   745,   746,   747,   749,   750,   751,   752,   755,   756,   758,
   759,   760,   762,   763,   764,   766,   767,   768,   769,   771,
   772,   773,   774,   775,   776,   777,   780,   781,   783,   784,
   785,   787,   788,   789,   791,   792,   793,   794,   796,   797,
   798,   799,   800,   801,   802
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID",
"IDFIELD","EQUAL","NOTEQUAL","OR","AND","NIL","TRUE","FALSE","IF","ELSIF","ELSE",
"UNLESS","THEN","'='","'<'","'>'","'-'","'+'","'*'","'/'","'!'","UMINUS","'.'",
"']'","'['","UBR","')'","'('","','","program","expr","expr_seqE","stmt","stmt_seq",
"stmt_seqE","method_def","method_def_param_seq","method_def_param_seqE","method_def_param",
"while_stmt","until_stmt","class_def","elsif_seq","elsif_seqE","if_stmt","unless_stmt",
""
};
#endif

static const short yyr1[] = {     0,
    45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
    46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
    47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    49,    49,    50,    50,    50,    51,    51,    51,    51,    51,
    51,    51,    51,    51,    51,    52,    52,    53,    53,    53,
    54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
    55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
    56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
    56,    56,    56,    57,    57,    57,    57,    57,    57,    58,
    58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
    60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
    60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
    61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
    61,    61,    61,    61,    61
};

static const short yyr2[] = {     0,
     1,     2,     3,     4,     4,     3,     4,     3,     4,     3,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     2,     3,     4,     2,     3,     4,     4,     5,
     4,     5,     5,     6,     4,     5,     4,     3,     2,     3,
     1,     1,     1,     1,     1,     5,     6,     7,     8,     7,
     6,     7,     8,     9,     8,     1,     1,     3,     4,     5,
     6,     5,     1,     3,     4,     5,     6,     5,     1,     3,
     4,     1,     1,     1,     1,     1,     1,     1,     2,     1,
     0,     1,     1,     3,     2,     9,    10,     8,     9,     7,
     7,     8,     8,     9,     6,     0,     1,     1,     4,     3,
     1,     6,     5,     7,     6,     7,     6,     8,     7,    10,
     9,     9,     8,     9,     8,     8,     7,     6,     5,     7,
     6,     7,     6,     8,     7,    10,     9,     9,     8,     9,
     8,     8,     7,     9,     8,     8,     7,     6,     5,     0,
     1,     4,     5,     5,     5,     6,     6,     6,     7,     5,
     6,     6,     7,     6,     7,     7,     8,     6,     8,     7,
     7,     8,     9,     9,    10,     7,     8,     8,     9,     9,
    10,    10,    10,    11,    11,    12,     5,     7,     6,     6,
     7,     8,     8,     9,     6,     7,     7,     8,     8,     9,
     9,     9,    10,    10,    11
};

static const short yydefact[] = {    81,
    41,    42,    81,     0,     0,     0,     0,    63,     0,    80,
    56,    57,    43,    44,    45,     0,     0,     0,     0,     0,
     0,    72,    83,     1,    82,    73,    75,    76,    74,    77,
    78,     2,     0,    96,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    79,     0,     0,     0,     0,     0,    26,
    23,     0,    39,    69,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    85,    96,   101,    96,     0,    97,    98,     0,     0,     0,
     0,     0,    81,     0,     0,     0,     0,     0,    81,     0,
    81,     0,     0,    64,     0,     0,    58,     0,     0,     0,
    81,     0,     0,    81,    40,     0,     0,    38,     0,     0,
     0,    27,     0,    15,     0,    17,     0,    19,     0,    21,
     0,    24,     0,    11,     0,    13,     0,     6,     0,     3,
     0,     8,     0,    10,     0,     0,     0,     0,    84,    96,
     0,     0,    81,     0,     0,     0,     0,    81,     0,     0,
    27,    81,    81,     0,     0,     0,     0,    81,     0,     0,
    27,    81,    81,     0,    81,     0,     0,     0,     0,     0,
     0,    65,     0,     0,    59,     0,    81,    81,    81,   140,
     0,    81,    81,    81,     0,     0,    35,    37,     0,    70,
     0,    29,    28,    16,    18,    20,    22,    25,    12,    14,
     5,     4,     7,     9,     0,     0,     0,     0,    31,     0,
    81,     0,    81,     0,     0,   100,     0,     0,    27,    81,
    81,     0,     0,    29,    28,    81,    81,     0,     0,   103,
     0,     0,    27,    81,    81,     0,     0,    29,    28,    81,
    81,     0,     0,   119,     0,     0,     0,   139,     0,    81,
     0,    66,    68,     0,    60,    62,    81,    81,   140,    81,
   140,   140,     0,     0,   141,    81,    81,     0,    81,     0,
     0,   177,    81,    36,    71,    30,     0,     0,    46,     0,
     0,    33,    32,     0,    81,     0,    81,    81,     0,    95,
    99,     0,    29,    28,    81,    81,     0,     0,   102,    30,
    81,    81,     0,     0,   107,   105,     0,    29,    28,    81,
    81,     0,     0,   118,    30,    81,    81,     0,     0,   123,
   121,   138,     0,    81,    81,     0,    67,    61,    81,   140,
   140,     0,   140,     0,     0,     0,     0,   158,    81,     0,
    81,     0,     0,   179,    81,     0,   180,    81,   185,     0,
    81,     0,     0,    51,     0,     0,     0,    47,    34,    81,
    81,     0,    90,    81,     0,     0,    91,    30,    81,    81,
     0,     0,   106,   104,    81,     0,     0,   117,   109,    30,
    81,    81,     0,     0,   122,   120,    81,     0,     0,   133,
   125,    81,     0,     0,   137,   140,     0,     0,   160,    81,
     0,   161,    81,   166,     0,     0,     0,    81,    81,     0,
     0,     0,     0,   181,    81,   187,     0,    81,     0,   186,
     0,    81,     0,    81,     0,   178,     0,     0,    52,     0,
    48,    50,    81,     0,     0,    88,     0,    93,    92,    81,
     0,     0,   113,   108,     0,   115,   116,    81,     0,     0,
   129,   124,     0,   131,   132,     0,   135,   136,     0,   162,
    81,   167,     0,    81,     0,   168,    81,     0,    81,     0,
    81,    81,    81,   142,     0,   159,     0,     0,    81,   188,
     0,     0,    81,     0,   182,    81,     0,   183,     0,   189,
     0,    53,    55,    49,     0,    86,    89,    94,     0,   111,
   112,   114,     0,   127,   128,   130,   134,   169,     0,    81,
     0,    81,     0,   163,     0,   164,     0,    81,    81,   144,
    81,   145,   150,   170,     0,    81,    81,    81,   143,    81,
   184,     0,   192,     0,   191,   190,    54,    87,   110,   126,
    81,     0,   165,     0,   173,   172,   171,    81,   146,   152,
   151,    81,    81,   147,    81,   148,   154,     0,   194,   193,
     0,   174,   175,   153,    81,   149,   156,   155,   195,   176,
   157,     0,     0,     0
};

static const short yydefgoto[] = {   572,
    22,    55,    23,    24,    25,    26,    75,    76,    77,    27,
    28,    29,   264,   265,    30,    31
};

static const short yypact[] = {   490,
-32768,-32768,  1985,    18,  2113,  2139,    88,-32768,   -21,  2778,
   -18,-32768,-32768,-32768,-32768,  2165,  2191,  2778,  2778,   420,
  2217,  3568,-32768,-32768,    31,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    28,   -13,  2804,  2243,  3138,  2830,  2269,  3170,
    81,    -2,   328,  3568,  2011,  2778,  3201,  2778,  3232,   -11,
   -11,  2295,-32768,  3568,     2,  2778,   210,  2336,  2362,  2388,
  2414,  2440,  2466,  2492,  2518,  2544,  2570,  2596,    92,  2622,
  1985,    11,-32768,    90,     9,-32768,-32768,  2648,  3264,  2778,
  2858,    91,   553,  2674,  3296,  2778,  2889,   101,   594,    19,
  1985,    94,  2778,-32768,     6,  2778,-32768,    26,  3327,    83,
   635,  3358,   109,   676,-32768,    34,    78,-32768,  2700,  2920,
   110,-32768,  2778,   256,  2778,   256,  2778,  3587,  2778,   169,
  2778,  3568,  2778,   240,  2778,   240,  2778,   266,  2778,   266,
  2778,   -11,  2778,   -11,   123,   100,  2778,  3389,-32768,    90,
    27,    47,  1985,   120,  2778,  2951,   155,   717,  2982,   124,
-32768,   758,  1985,   161,  2778,  3013,   160,   799,  3044,   148,
-32768,   840,  1985,   184,  1985,   162,   191,   196,   208,    71,
   177,-32768,    85,   178,-32768,   193,   881,   922,  1985,   197,
   198,   963,  1004,  1985,    14,   194,-32768,-32768,  2778,  3568,
   192,-32768,-32768,   256,   256,  3587,   169,  3568,   240,   240,
   266,   266,   -11,   -11,   203,  2045,  3420,   212,-32768,    89,
  1985,   207,  1045,   229,    90,-32768,  3075,   211,-32768,  1086,
  1985,   249,   216,-32768,-32768,  1985,  1985,   252,   253,-32768,
  3106,   219,-32768,  1127,  1985,   258,   225,-32768,-32768,  1985,
  1985,   261,   262,-32768,   264,   268,   274,-32768,   276,  1985,
   255,-32768,-32768,   263,-32768,-32768,  1168,  1985,   197,  1985,
   197,   197,  2726,    49,   270,  1209,  1985,    80,  1985,    95,
    97,-32768,  1250,-32768,  3568,-32768,  2079,  2778,-32768,   114,
   271,-32768,-32768,   267,  1291,   296,  1332,  1985,   304,-32768,
-32768,   273,-32768,-32768,  1985,  1985,   305,   309,-32768,-32768,
  1985,  1985,   310,   311,-32768,-32768,   277,-32768,-32768,  1985,
  1985,   313,   316,-32768,-32768,  1985,  1985,   317,   318,-32768,
-32768,-32768,   322,  1985,  1985,   321,-32768,-32768,  1985,   197,
   197,   135,   197,   144,   146,  2778,  3451,-32768,  1373,  2752,
  1985,   156,   158,-32768,  1414,   171,-32768,  1455,-32768,   324,
  1985,   323,  2778,-32768,   129,   141,   292,-32768,-32768,  1496,
  1985,   330,-32768,  1985,   339,   340,-32768,-32768,  1985,  1985,
   346,   347,-32768,-32768,  1985,   348,   349,-32768,-32768,-32768,
  1985,  1985,   352,   355,-32768,-32768,  1985,   356,   358,-32768,
-32768,  1985,   362,   368,-32768,   197,   186,   188,-32768,  1537,
   369,-32768,  1578,-32768,   372,  3482,   353,  1619,  1985,   373,
  2778,  3513,   199,-32768,  1985,-32768,   377,  1985,   376,-32768,
   380,  1985,   379,  1985,   381,-32768,   152,   345,-32768,   350,
-32768,-32768,  1985,   383,   384,-32768,   386,-32768,-32768,  1985,
   387,   388,-32768,-32768,   389,-32768,-32768,  1985,   391,   392,
-32768,-32768,   394,-32768,-32768,   395,-32768,-32768,   209,-32768,
  1660,-32768,   398,  1985,   397,-32768,  1985,   400,  1985,   385,
  1701,  1742,  1985,-32768,   401,-32768,  3544,   390,  1783,-32768,
   404,   407,  1985,   409,-32768,  1985,   410,-32768,   413,-32768,
   396,-32768,-32768,-32768,   415,-32768,-32768,-32768,   419,-32768,
-32768,-32768,   421,-32768,-32768,-32768,-32768,-32768,   406,  1985,
   422,  1985,   424,-32768,   427,-32768,   432,  1824,  1985,-32768,
  1985,-32768,-32768,-32768,   399,  1865,  1906,  1985,-32768,  1985,
-32768,   433,-32768,   437,-32768,-32768,-32768,-32768,-32768,-32768,
  1985,   439,-32768,   440,-32768,-32768,-32768,  1985,-32768,-32768,
-32768,  1947,  1985,-32768,  1985,-32768,-32768,   441,-32768,-32768,
   443,-32768,-32768,-32768,  1985,-32768,-32768,-32768,-32768,-32768,
-32768,   451,   453,-32768
};

static const short yypgoto[] = {-32768,
    -1,    96,   402,    -3,-32768,-32768,   -66,-32768,  -143,-32768,
-32768,-32768,  -249,-32768,-32768,-32768
};


#define	YYLAST		3627


static const short yytable[] = {    32,
   216,    73,    91,    37,    40,   141,   107,   142,    44,   332,
   171,   334,   335,   143,    47,    49,    50,    51,    54,    57,
   272,    43,    33,   165,    45,    73,    69,    92,    70,    74,
   174,   211,    34,    79,    81,    71,    85,    87,   186,   273,
   108,    54,    72,    54,    99,   109,   102,   172,   166,   109,
    54,   212,   144,   140,   110,   338,   114,   116,   118,   120,
   122,   124,   126,   128,   130,   132,   134,   175,   138,   109,
   144,   291,   187,   210,   339,   251,   146,   109,   149,   154,
   397,   398,   156,   401,   159,   164,   344,   167,   213,   254,
   144,    54,    41,   284,    54,    90,   135,   180,   168,   152,
   185,   347,    42,   349,    73,   345,   136,   190,   169,   162,
   178,   194,   252,   195,   109,   196,   188,   197,   357,   198,
   348,   199,   350,   200,   215,   201,   255,   202,   109,   203,
   285,   204,   144,   428,    73,   207,   183,   205,    95,   214,
    98,   399,   206,   217,   222,   430,   459,   106,   228,   229,
   402,   193,   404,   231,   236,   358,   491,   109,   242,   243,
   400,   245,   414,   220,   416,   225,   246,   230,   234,   403,
   429,   405,   109,   259,   261,   262,   247,   420,   268,   270,
   271,   415,   431,   417,   109,    58,    59,   275,   170,   239,
   244,   173,   460,   492,   462,   109,   421,   248,    63,    64,
    65,    66,    67,    68,    54,   480,    69,   286,    70,   289,
   249,   461,   250,   463,   111,   508,   297,   298,   253,   256,
   257,   263,   303,   304,   481,   266,    58,    59,    60,    61,
   312,   313,   274,   276,   509,   290,   318,   319,    62,    63,
    64,    65,    66,    67,    68,   277,   326,    69,   287,    70,
   283,   112,   294,   330,   331,   299,   333,   300,   305,   306,
   309,   337,   342,   343,   314,   346,   315,   320,   321,   352,
   322,    65,    66,    67,    68,    54,    54,    69,   324,    70,
   325,   362,   323,   365,   366,    63,    64,    65,    66,    67,
    68,   371,   372,    69,   340,    70,   327,   376,   377,    67,
    68,   280,   363,    69,   328,    70,   383,   384,   360,   359,
   367,   373,   388,   389,   368,   374,   378,   379,   380,   385,
   393,   394,   386,   390,   391,   396,   392,   395,   424,   426,
     1,     2,    93,   432,   406,   410,   436,   413,   412,     8,
     9,   419,    11,    12,   423,   438,   439,   425,    13,    14,
    15,    54,   443,   444,   446,   447,   434,   435,   451,    18,
   437,   452,   454,    19,   455,   441,   442,    20,   457,    94,
    21,   445,   355,   356,   458,   466,   469,   449,   450,   476,
   472,   483,   485,   453,   486,   488,   493,   490,   456,   496,
   497,   494,   498,   500,   501,   502,   465,   504,   505,   468,
   506,   507,   512,   514,   474,   475,   516,   524,   530,   477,
   541,   482,   518,   531,   484,   533,   535,   527,   487,   536,
   489,   538,     1,     2,    52,   539,   552,   540,   543,   495,
   545,     8,     9,   546,    11,    12,   499,   537,   547,   559,
    13,    14,    15,   560,   503,   562,   563,   569,   427,   570,
   573,    18,   574,     0,     0,    19,     0,   511,    53,    20,
   513,     0,    21,   515,     0,   517,     0,   520,   522,   523,
     0,     0,   139,     0,     0,   529,     0,     0,     0,   532,
     0,     0,   534,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     1,     2,     3,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,    12,   542,     0,   544,     0,
    13,    14,    15,    16,   549,   550,    17,   551,     0,     0,
     0,    18,   554,   556,   557,    19,   558,     0,     0,    20,
     0,     0,    21,     0,     0,     0,     0,   561,     0,     0,
     0,     0,     0,     0,   564,     0,     0,     0,   566,   567,
     0,   568,     0,     0,     0,     1,     2,   153,     4,     0,
     5,   571,     6,     7,     8,     9,    10,    11,    12,     0,
     0,     0,     0,    13,    14,    15,    16,     0,     0,    17,
     0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
     0,     0,    20,     0,     0,    21,     1,     2,   163,     4,
     0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
     0,     0,     0,     0,    13,    14,    15,    16,     0,     0,
    17,     0,     0,     0,     0,    18,     0,     0,     0,    19,
     0,     0,     0,    20,     0,     0,    21,     1,     2,   179,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
    12,     0,     0,     0,     0,    13,    14,    15,    16,     0,
     0,    17,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,     0,    20,     0,     0,    21,     1,     2,
   184,     4,     0,     5,     0,     6,     7,     8,     9,    10,
    11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
     0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
     0,    19,     0,     0,     0,    20,     0,     0,    21,     1,
     2,   221,     4,     0,     5,     0,     6,     7,     8,     9,
    10,    11,    12,     0,     0,     0,     0,    13,    14,    15,
    16,     0,     0,    17,     0,     0,     0,     0,    18,     0,
     0,     0,    19,     0,     0,     0,    20,     0,     0,    21,
     1,     2,   227,     4,     0,     5,     0,     6,     7,     8,
     9,    10,    11,    12,     0,     0,     0,     0,    13,    14,
    15,    16,     0,     0,    17,     0,     0,     0,     0,    18,
     0,     0,     0,    19,     0,     0,     0,    20,     0,     0,
    21,     1,     2,   235,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
    14,    15,    16,     0,     0,    17,     0,     0,     0,     0,
    18,     0,     0,     0,    19,     0,     0,     0,    20,     0,
     0,    21,     1,     2,   241,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
    13,    14,    15,    16,     0,     0,    17,     0,     0,     0,
     0,    18,     0,     0,     0,    19,     0,     0,     0,    20,
     0,     0,    21,     1,     2,   258,     4,     0,     5,     0,
     6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
     0,    13,    14,    15,    16,     0,     0,    17,     0,     0,
     0,     0,    18,     0,     0,     0,    19,     0,     0,     0,
    20,     0,     0,    21,     1,     2,   260,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
     0,     0,    13,    14,    15,    16,     0,     0,    17,     0,
     0,     0,     0,    18,     0,     0,     0,    19,     0,     0,
     0,    20,     0,     0,    21,     1,     2,   267,     4,     0,
     5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
     0,     0,     0,    13,    14,    15,    16,     0,     0,    17,
     0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
     0,     0,    20,     0,     0,    21,     1,     2,   269,     4,
     0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
     0,     0,     0,     0,    13,    14,    15,    16,     0,     0,
    17,     0,     0,     0,     0,    18,     0,     0,     0,    19,
     0,     0,     0,    20,     0,     0,    21,     1,     2,   288,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
    12,     0,     0,     0,     0,    13,    14,    15,    16,     0,
     0,    17,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,     0,    20,     0,     0,    21,     1,     2,
   296,     4,     0,     5,     0,     6,     7,     8,     9,    10,
    11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
     0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
     0,    19,     0,     0,     0,    20,     0,     0,    21,     1,
     2,   311,     4,     0,     5,     0,     6,     7,     8,     9,
    10,    11,    12,     0,     0,     0,     0,    13,    14,    15,
    16,     0,     0,    17,     0,     0,     0,     0,    18,     0,
     0,     0,    19,     0,     0,     0,    20,     0,     0,    21,
     1,     2,   329,     4,     0,     5,     0,     6,     7,     8,
     9,    10,    11,    12,     0,     0,     0,     0,    13,    14,
    15,    16,     0,     0,    17,     0,     0,     0,     0,    18,
     0,     0,     0,    19,     0,     0,     0,    20,     0,     0,
    21,     1,     2,   341,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
    14,    15,    16,     0,     0,    17,     0,     0,     0,     0,
    18,     0,     0,     0,    19,     0,     0,     0,    20,     0,
     0,    21,     1,     2,   351,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
    13,    14,    15,    16,     0,     0,    17,     0,     0,     0,
     0,    18,     0,     0,     0,    19,     0,     0,     0,    20,
     0,     0,    21,     1,     2,   361,     4,     0,     5,     0,
     6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
     0,    13,    14,    15,    16,     0,     0,    17,     0,     0,
     0,     0,    18,     0,     0,     0,    19,     0,     0,     0,
    20,     0,     0,    21,     1,     2,   364,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
     0,     0,    13,    14,    15,    16,     0,     0,    17,     0,
     0,     0,     0,    18,     0,     0,     0,    19,     0,     0,
     0,    20,     0,     0,    21,     1,     2,   409,     4,     0,
     5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
     0,     0,     0,    13,    14,    15,    16,     0,     0,    17,
     0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
     0,     0,    20,     0,     0,    21,     1,     2,   418,     4,
     0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
     0,     0,     0,     0,    13,    14,    15,    16,     0,     0,
    17,     0,     0,     0,     0,    18,     0,     0,     0,    19,
     0,     0,     0,    20,     0,     0,    21,     1,     2,   422,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
    12,     0,     0,     0,     0,    13,    14,    15,    16,     0,
     0,    17,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,     0,    20,     0,     0,    21,     1,     2,
   433,     4,     0,     5,     0,     6,     7,     8,     9,    10,
    11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
     0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
     0,    19,     0,     0,     0,    20,     0,     0,    21,     1,
     2,   464,     4,     0,     5,     0,     6,     7,     8,     9,
    10,    11,    12,     0,     0,     0,     0,    13,    14,    15,
    16,     0,     0,    17,     0,     0,     0,     0,    18,     0,
     0,     0,    19,     0,     0,     0,    20,     0,     0,    21,
     1,     2,   467,     4,     0,     5,     0,     6,     7,     8,
     9,    10,    11,    12,     0,     0,     0,     0,    13,    14,
    15,    16,     0,     0,    17,     0,     0,     0,     0,    18,
     0,     0,     0,    19,     0,     0,     0,    20,     0,     0,
    21,     1,     2,   473,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,    12,     0,     0,     0,     0,    13,
    14,    15,    16,     0,     0,    17,     0,     0,     0,     0,
    18,     0,     0,     0,    19,     0,     0,     0,    20,     0,
     0,    21,     1,     2,   510,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
    13,    14,    15,    16,     0,     0,    17,     0,     0,     0,
     0,    18,     0,     0,     0,    19,     0,     0,     0,    20,
     0,     0,    21,     1,     2,   519,     4,     0,     5,     0,
     6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
     0,    13,    14,    15,    16,     0,     0,    17,     0,     0,
     0,     0,    18,     0,     0,     0,    19,     0,     0,     0,
    20,     0,     0,    21,     1,     2,   521,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
     0,     0,    13,    14,    15,    16,     0,     0,    17,     0,
     0,     0,     0,    18,     0,     0,     0,    19,     0,     0,
     0,    20,     0,     0,    21,     1,     2,   528,     4,     0,
     5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
     0,     0,     0,    13,    14,    15,    16,     0,     0,    17,
     0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
     0,     0,    20,     0,     0,    21,     1,     2,   548,     4,
     0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
     0,     0,     0,     0,    13,    14,    15,    16,     0,     0,
    17,     0,     0,     0,     0,    18,     0,     0,     0,    19,
     0,     0,     0,    20,     0,     0,    21,     1,     2,   553,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
    12,     0,     0,     0,     0,    13,    14,    15,    16,     0,
     0,    17,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,     0,    20,     0,     0,    21,     1,     2,
   555,     4,     0,     5,     0,     6,     7,     8,     9,    10,
    11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
     0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
     0,    19,     0,     0,     0,    20,     0,     0,    21,     1,
     2,   565,     4,     0,     5,     0,     6,     7,     8,     9,
    10,    11,    12,     0,     0,     0,     0,    13,    14,    15,
    16,     0,     0,    17,     0,     0,     0,     0,    18,     0,
     0,     0,    19,     0,     0,     0,    20,     1,     2,    21,
     4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
    12,     0,     0,     0,     0,    13,    14,    15,    16,     0,
     0,    17,     0,     1,     2,    96,    18,     0,     0,     0,
    19,     0,     8,     9,    20,    11,    12,    21,     0,     0,
     0,    13,    14,    15,     0,     0,     0,     0,     0,     0,
     0,     0,    18,     0,     0,     0,    19,     1,     2,   278,
    20,     0,    97,    21,     0,     0,     8,     9,     0,    11,
    12,     0,     0,     0,     0,    13,    14,    15,     0,     0,
     0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     1,     2,   353,    20,     0,   279,    21,     0,     0,
     8,     9,     0,    11,    12,     0,     0,     0,     0,    13,
    14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
    18,     0,     0,     0,    19,     1,     2,    35,    20,     0,
   354,    21,     0,     0,     8,     9,     0,    11,    12,     0,
     0,     0,     0,    13,    14,    15,     0,     0,     0,     0,
     0,     1,     2,    38,    18,     0,     0,     0,    19,     0,
     8,     9,    20,    11,    12,    36,     0,     0,     0,    13,
    14,    15,     0,     0,     0,     0,     0,     1,     2,    46,
    18,     0,     0,     0,    19,     0,     8,     9,    20,    11,
    12,    39,     0,     0,     0,    13,    14,    15,     0,     0,
     0,     0,     0,     1,     2,    48,    18,     0,     0,     0,
    19,     0,     8,     9,    20,    11,    12,    21,     0,     0,
     0,    13,    14,    15,     0,     0,     0,     0,     0,     1,
     2,    56,    18,     0,     0,     0,    19,     0,     8,     9,
    20,    11,    12,    21,     0,     0,     0,    13,    14,    15,
     0,     0,     0,     0,     0,     1,     2,    80,    18,     0,
     0,     0,    19,     0,     8,     9,    20,    11,    12,    21,
     0,     0,     0,    13,    14,    15,     0,     0,     0,     0,
     0,     1,     2,    86,    18,     0,     0,     0,    19,     0,
     8,     9,    20,    11,    12,    21,     0,     0,     0,    13,
    14,    15,     0,     0,     0,     0,     0,     1,     2,     0,
    18,     0,     0,     0,    19,     0,     8,     9,    20,    11,
    12,    21,     0,     0,     0,    13,    14,    15,     0,     0,
     0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,   105,    20,     0,     0,    21,     1,     2,
   113,     0,     0,     0,     0,     0,     0,     8,     9,     0,
    11,    12,     0,     0,     0,     0,    13,    14,    15,     0,
     0,     0,     0,     0,     1,     2,   115,    18,     0,     0,
     0,    19,     0,     8,     9,    20,    11,    12,    21,     0,
     0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
     1,     2,   117,    18,     0,     0,     0,    19,     0,     8,
     9,    20,    11,    12,    21,     0,     0,     0,    13,    14,
    15,     0,     0,     0,     0,     0,     1,     2,   119,    18,
     0,     0,     0,    19,     0,     8,     9,    20,    11,    12,
    21,     0,     0,     0,    13,    14,    15,     0,     0,     0,
     0,     0,     1,     2,   121,    18,     0,     0,     0,    19,
     0,     8,     9,    20,    11,    12,    21,     0,     0,     0,
    13,    14,    15,     0,     0,     0,     0,     0,     1,     2,
   123,    18,     0,     0,     0,    19,     0,     8,     9,    20,
    11,    12,    21,     0,     0,     0,    13,    14,    15,     0,
     0,     0,     0,     0,     1,     2,   125,    18,     0,     0,
     0,    19,     0,     8,     9,    20,    11,    12,    21,     0,
     0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
     1,     2,   127,    18,     0,     0,     0,    19,     0,     8,
     9,    20,    11,    12,    21,     0,     0,     0,    13,    14,
    15,     0,     0,     0,     0,     0,     1,     2,   129,    18,
     0,     0,     0,    19,     0,     8,     9,    20,    11,    12,
    21,     0,     0,     0,    13,    14,    15,     0,     0,     0,
     0,     0,     1,     2,   131,    18,     0,     0,     0,    19,
     0,     8,     9,    20,    11,    12,    21,     0,     0,     0,
    13,    14,    15,     0,     0,     0,     0,     0,     1,     2,
   133,    18,     0,     0,     0,    19,     0,     8,     9,    20,
    11,    12,    21,     0,     0,     0,    13,    14,    15,     0,
     0,     0,     0,     0,     1,     2,   137,    18,     0,     0,
     0,    19,     0,     8,     9,    20,    11,    12,    21,     0,
     0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
     1,     2,   145,    18,     0,     0,     0,    19,     0,     8,
     9,    20,    11,    12,    21,     0,     0,     0,    13,    14,
    15,     0,     0,     0,     0,     0,     1,     2,   155,    18,
     0,     0,     0,    19,     0,     8,     9,    20,    11,    12,
    21,     0,     0,     0,    13,    14,    15,     0,     0,     0,
     0,     0,     1,     2,   189,    18,     0,     0,     0,    19,
     0,     8,     9,    20,    11,    12,    21,     0,     0,     0,
    13,    14,    15,     0,     0,     0,     0,     0,     1,     2,
   336,    18,     0,     0,     0,    19,     0,     8,     9,    20,
    11,    12,    21,     0,     0,     0,    13,    14,    15,     0,
     0,     0,     0,     0,     1,     2,   411,    18,     0,     0,
     0,    19,     0,     8,     9,    20,    11,    12,    21,     0,
     0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
     1,     2,     0,    18,     0,     0,     0,    19,     0,     8,
     9,    20,    11,    12,    21,     0,     0,     0,    13,    14,
    15,     0,     0,     0,     0,     0,     1,     2,     0,    18,
     0,     0,     0,    19,     0,     8,     9,    20,    11,    12,
    21,     0,     0,     0,    13,    14,    15,     0,     0,     0,
     0,     0,     1,     2,     0,    18,     0,     0,     0,    19,
     0,     8,     9,    20,    11,    12,    78,     0,     0,     0,
    13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
     0,    18,   150,     0,     0,    19,     0,     0,     0,    20,
     0,     0,    84,     0,    58,    59,    60,    61,     0,     0,
     0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
    66,    67,    68,   160,     0,    69,     0,    70,     0,   151,
     0,     0,     0,     0,     0,    58,    59,    60,    61,     0,
     0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
    65,    66,    67,    68,   191,     0,    69,     0,    70,     0,
   161,     0,     0,     0,     0,     0,    58,    59,    60,    61,
     0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
    64,    65,    66,    67,    68,   218,     0,    69,     0,    70,
     0,   192,     0,     0,     0,     0,     0,    58,    59,    60,
    61,     0,     0,     0,     0,     0,     0,     0,     0,    62,
    63,    64,    65,    66,    67,    68,   223,     0,    69,     0,
    70,     0,   219,     0,     0,     0,     0,     0,    58,    59,
    60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
    62,    63,    64,    65,    66,    67,    68,   232,     0,    69,
     0,    70,     0,   224,     0,     0,     0,     0,     0,    58,
    59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
     0,    62,    63,    64,    65,    66,    67,    68,   237,     0,
    69,     0,    70,     0,   233,     0,     0,     0,     0,     0,
    58,    59,    60,    61,     0,     0,     0,     0,     0,     0,
     0,     0,    62,    63,    64,    65,    66,    67,    68,   292,
     0,    69,     0,    70,     0,   238,     0,     0,     0,     0,
     0,    58,    59,    60,    61,     0,     0,     0,     0,     0,
     0,     0,     0,    62,    63,    64,    65,    66,    67,    68,
   307,     0,    69,     0,    70,     0,   293,     0,     0,     0,
     0,     0,    58,    59,    60,    61,     0,     0,     0,     0,
     0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
    68,     0,    82,    69,     0,    70,    83,   308,     0,     0,
     0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
     0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
    66,    67,    68,     0,    88,    69,     0,    70,    89,     0,
     0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
     0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
    64,    65,    66,    67,    68,   100,     0,    69,     0,    70,
     0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
    61,     0,     0,     0,     0,     0,     0,     0,   101,    62,
    63,    64,    65,    66,    67,    68,   103,     0,    69,     0,
    70,     0,     0,     0,     0,     0,     0,     0,    58,    59,
    60,    61,     0,     0,     0,     0,     0,     0,     0,   104,
    62,    63,    64,    65,    66,    67,    68,     0,   147,    69,
     0,    70,   148,     0,     0,     0,     0,     0,     0,     0,
    58,    59,    60,    61,     0,     0,     0,     0,     0,     0,
     0,     0,    62,    63,    64,    65,    66,    67,    68,     0,
   157,    69,     0,    70,   158,     0,     0,     0,     0,     0,
     0,     0,    58,    59,    60,    61,     0,     0,     0,     0,
     0,     0,     0,     0,    62,    63,    64,    65,    66,    67,
    68,   176,     0,    69,     0,    70,     0,     0,     0,     0,
     0,     0,     0,    58,    59,    60,    61,     0,     0,     0,
     0,     0,     0,     0,   177,    62,    63,    64,    65,    66,
    67,    68,   181,     0,    69,     0,    70,     0,     0,     0,
     0,     0,     0,     0,    58,    59,    60,    61,     0,     0,
     0,     0,     0,     0,     0,   182,    62,    63,    64,    65,
    66,    67,    68,   208,     0,    69,     0,    70,     0,     0,
     0,     0,     0,     0,     0,    58,    59,    60,    61,     0,
     0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
    65,    66,    67,    68,   281,     0,    69,   209,    70,     0,
     0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
     0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
    64,    65,    66,    67,    68,   407,     0,    69,   282,    70,
     0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
    61,     0,     0,     0,     0,     0,     0,     0,   408,    62,
    63,    64,    65,    66,    67,    68,   470,     0,    69,     0,
    70,     0,     0,     0,     0,     0,     0,     0,    58,    59,
    60,    61,     0,     0,     0,     0,     0,     0,     0,   471,
    62,    63,    64,    65,    66,    67,    68,   478,     0,    69,
     0,    70,     0,     0,     0,     0,     0,     0,     0,    58,
    59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
   479,    62,    63,    64,    65,    66,    67,    68,   525,     0,
    69,     0,    70,     0,     0,     0,     0,     0,     0,     0,
    58,    59,    60,    61,     0,     0,     0,     0,     0,     0,
     0,   526,    62,    63,    64,    65,    66,    67,    68,     0,
     0,    69,     0,    70,    58,    59,    60,    61,     0,     0,
     0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
    66,    67,    68,    58,    59,    69,    61,    70,     0,     0,
     0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
    67,    68,     0,     0,    69,     0,    70
};

static const short yycheck[] = {     3,
   144,    15,     5,     5,     6,    72,     5,    74,    10,   259,
     5,   261,   262,     5,    16,    17,    18,    19,    20,    21,
     7,    43,     5,     5,    43,    15,    38,    30,    40,    43,
     5,     5,    15,    35,    36,     5,    38,    39,     5,    26,
    39,    43,    15,    45,    46,    44,    48,    42,    30,    44,
    52,     5,    44,    43,    56,     7,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    42,    70,    44,
    44,   215,    39,   140,    26,     5,    78,    44,    80,    83,
   330,   331,    84,   333,    86,    89,     7,    91,    42,     5,
    44,    93,     5,     5,    96,    15,     5,   101,     5,     9,
   104,     7,    15,     7,    15,    26,    15,   109,    15,     9,
    28,   113,    42,   115,    44,   117,    39,   119,     5,   121,
    26,   123,    26,   125,     5,   127,    42,   129,    44,   131,
    42,   133,    44,     5,    15,   137,    28,    15,    43,   143,
    45,     7,    43,   145,   148,     5,   396,    52,   152,   153,
     7,    42,     7,   155,   158,    42,     5,    44,   162,   163,
    26,   165,     7,     9,     7,    42,     5,     7,     9,    26,
    42,    26,    44,   177,   178,   179,    15,     7,   182,   183,
   184,    26,    42,    26,    44,    17,    18,   189,    93,    42,
     7,    96,     7,    42,     7,    44,    26,     7,    30,    31,
    32,    33,    34,    35,   206,     7,    38,   211,    40,   213,
    15,    26,     5,    26,     5,     7,   220,   221,    42,    42,
    28,    25,   226,   227,    26,    28,    17,    18,    19,    20,
   234,   235,    39,    42,    26,     7,   240,   241,    29,    30,
    31,    32,    33,    34,    35,    43,   250,    38,    42,    40,
    39,    42,    42,   257,   258,     7,   260,    42,     7,     7,
    42,   263,   266,   267,     7,   269,    42,     7,     7,   273,
     7,    32,    33,    34,    35,   277,   278,    38,     5,    40,
     5,   285,    15,   287,   288,    30,    31,    32,    33,    34,
    35,   295,   296,    38,    25,    40,    42,   301,   302,    34,
    35,   206,     7,    38,    42,    40,   310,   311,    42,    39,
     7,     7,   316,   317,    42,     7,     7,     7,    42,     7,
   324,   325,     7,     7,     7,   329,     5,     7,     5,     7,
     3,     4,     5,    42,   336,   339,     7,   341,   340,    12,
    13,   345,    15,    16,   348,     7,     7,   351,    21,    22,
    23,   353,     7,     7,     7,     7,   360,   361,     7,    32,
   364,     7,     7,    36,     7,   369,   370,    40,     7,    42,
    43,   375,   277,   278,     7,     7,     5,   381,   382,     7,
    28,     5,     7,   387,     5,     7,    42,     7,   392,     7,
     7,    42,     7,     7,     7,     7,   400,     7,     7,   403,
     7,     7,     5,     7,   408,   409,     7,     7,     5,   411,
     5,   415,    28,     7,   418,     7,     7,    28,   422,     7,
   424,     7,     3,     4,     5,     7,    28,     7,     7,   433,
     7,    12,    13,     7,    15,    16,   440,    42,     7,     7,
    21,    22,    23,     7,   448,     7,     7,     7,   353,     7,
     0,    32,     0,    -1,    -1,    36,    -1,   461,    39,    40,
   464,    -1,    43,   467,    -1,   469,    -1,   471,   472,   473,
    -1,    -1,    71,    -1,    -1,   479,    -1,    -1,    -1,   483,
    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,   510,    -1,   512,    -1,
    21,    22,    23,    24,   518,   519,    27,   521,    -1,    -1,
    -1,    32,   526,   527,   528,    36,   530,    -1,    -1,    40,
    -1,    -1,    43,    -1,    -1,    -1,    -1,   541,    -1,    -1,
    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,   552,   553,
    -1,   555,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
     8,   565,    10,    11,    12,    13,    14,    15,    16,    -1,
    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,
    -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,
     5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,
     4,     5,     6,    -1,     8,    -1,    10,    11,    12,    13,
    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
     3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
    43,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,
    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,
    10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,
    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,
    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,
     8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,
    -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,
     5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,
     4,     5,     6,    -1,     8,    -1,    10,    11,    12,    13,
    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
     3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
    43,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,
    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,
    10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,
    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,
    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,
     8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,
    -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,
     5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,
     4,     5,     6,    -1,     8,    -1,    10,    11,    12,    13,
    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,
     3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
    43,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,
    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,    -1,
    10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,
    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    -1,
    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,
    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,    -1,
     8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,     6,
    -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,     4,
     5,     6,    -1,     8,    -1,    10,    11,    12,    13,    14,
    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    43,     3,
     4,     5,     6,    -1,     8,    -1,    10,    11,    12,    13,
    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
    -1,    -1,    36,    -1,    -1,    -1,    40,     3,     4,    43,
     6,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
    -1,    27,    -1,     3,     4,     5,    32,    -1,    -1,    -1,
    36,    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,
    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    -1,    36,     3,     4,     5,
    40,    -1,    42,    43,    -1,    -1,    12,    13,    -1,    15,
    16,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,     3,     4,     5,    40,    -1,    42,    43,    -1,    -1,
    12,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    32,    -1,    -1,    -1,    36,     3,     4,     5,    40,    -1,
    42,    43,    -1,    -1,    12,    13,    -1,    15,    16,    -1,
    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,
    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,
    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,
    16,    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,
    36,    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,
    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,
     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,
    40,    15,    16,    43,    -1,    -1,    -1,    21,    22,    23,
    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,
    -1,    -1,    36,    -1,    12,    13,    40,    15,    16,    43,
    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,
    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,
    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,
    16,    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
    36,    -1,    -1,    39,    40,    -1,    -1,    43,     3,     4,
     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    16,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    16,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,
    15,    16,    43,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    16,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    16,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,
    15,    16,    43,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    16,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,     5,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    16,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,     3,     4,
     5,    32,    -1,    -1,    -1,    36,    -1,    12,    13,    40,
    15,    16,    43,    -1,    -1,    -1,    21,    22,    23,    -1,
    -1,    -1,    -1,    -1,     3,     4,     5,    32,    -1,    -1,
    -1,    36,    -1,    12,    13,    40,    15,    16,    43,    -1,
    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     3,     4,    -1,    32,    -1,    -1,    -1,    36,    -1,    12,
    13,    40,    15,    16,    43,    -1,    -1,    -1,    21,    22,
    23,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    32,
    -1,    -1,    -1,    36,    -1,    12,    13,    40,    15,    16,
    43,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
    -1,    -1,     3,     4,    -1,    32,    -1,    -1,    -1,    36,
    -1,    12,    13,    40,    15,    16,    43,    -1,    -1,    -1,
    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    32,     5,    -1,    -1,    36,    -1,    -1,    -1,    40,
    -1,    -1,    43,    -1,    17,    18,    19,    20,    -1,    -1,
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
     5,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,    -1,     5,    38,    -1,    40,     9,    42,    -1,    -1,
    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,    -1,     5,    38,    -1,    40,     9,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
    31,    32,    33,    34,    35,     5,    -1,    38,    -1,    40,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
    30,    31,    32,    33,    34,    35,     5,    -1,    38,    -1,
    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
    29,    30,    31,    32,    33,    34,    35,    -1,     5,    38,
    -1,    40,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
     5,    38,    -1,    40,     9,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
    35,     5,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
    34,    35,     5,    -1,    38,    -1,    40,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
    33,    34,    35,     5,    -1,    38,    -1,    40,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
    32,    33,    34,    35,     5,    -1,    38,    39,    40,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
    31,    32,    33,    34,    35,     5,    -1,    38,    39,    40,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
    30,    31,    32,    33,    34,    35,     5,    -1,    38,    -1,
    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
    29,    30,    31,    32,    33,    34,    35,     5,    -1,    38,
    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    28,    29,    30,    31,    32,    33,    34,    35,     5,    -1,
    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
    -1,    38,    -1,    40,    17,    18,    19,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
    33,    34,    35,    17,    18,    38,    20,    40,    -1,    -1,
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
#line 531 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 2:
#line 532 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 3:
#line 535 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 4:
#line 536 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 5:
#line 538 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 6:
#line 539 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 7:
#line 541 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 8:
#line 542 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 9:
#line 544 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 10:
#line 545 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 11:
#line 547 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 12:
#line 548 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 13:
#line 550 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 14:
#line 551 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 15:
#line 553 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 16:
#line 554 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 17:
#line 556 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 18:
#line 557 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 19:
#line 559 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 20:
#line 560 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 21:
#line 562 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 22:
#line 563 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 23:
#line 565 "parser.y"
{ yyval.uExpr = createUnExpr(eNot, yyvsp[0].uExpr); ;
    break;}
case 24:
#line 567 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 25:
#line 568 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 26:
#line 570 "parser.y"
{ yyval.uExpr = createUnExpr(eUMinus, yyvsp[0].uExpr); ;
    break;}
case 27:
#line 572 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 28:
#line 573 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 29:
#line 574 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 30:
#line 575 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 31:
#line 577 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-3].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 32:
#line 578 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 33:
#line 579 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 34:
#line 580 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-5].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 35:
#line 582 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 36:
#line 583 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 37:
#line 584 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 38:
#line 585 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 39:
#line 587 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 40:
#line 588 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 41:
#line 590 "parser.y"
{ yyval.uExpr = createIntExpr(yyvsp[0].uInt); ;
    break;}
case 42:
#line 591 "parser.y"
{ yyval.uExpr = createStrExpr(yyvsp[0].uString); ;
    break;}
case 43:
#line 592 "parser.y"
{ yyval.uExpr = createNilExpr(); ;
    break;}
case 44:
#line 593 "parser.y"
{ yyval.uExpr = createBoolExpr(1); ;
    break;}
case 45:
#line 594 "parser.y"
{ yyval.uExpr = createBoolExpr(0); ;
    break;}
case 46:
#line 596 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-4].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 47:
#line 597 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 48:
#line 598 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 49:
#line 599 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 50:
#line 600 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 51:
#line 602 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 52:
#line 603 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 53:
#line 604 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 54:
#line 605 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-8].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 55:
#line 606 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 56:
#line 609 "parser.y"
{ yyval.uExpr = createLocalExpr(yyvsp[0].uId); ;
    break;}
case 57:
#line 610 "parser.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId); ;
    break;}
case 58:
#line 611 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-2].uId, NULL); ;
    break;}
case 59:
#line 612 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 60:
#line 613 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 61:
#line 614 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 62:
#line 615 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 63:
#line 616 "parser.y"
{ yyval.uExpr = createSelfExpr(); ;
    break;}
case 64:
#line 618 "parser.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 65:
#line 619 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 66:
#line 620 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 67:
#line 621 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 68:
#line 622 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 69:
#line 625 "parser.y"
{ yyval.uExprSeq = createExprSeq(yyvsp[0].uExpr); ;
    break;}
case 70:
#line 626 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-2].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 71:
#line 627 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-3].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 72:
#line 630 "parser.y"
{ yyval.uStmt = createStmt(eExpr, yyvsp[0].uExpr, NULL); ;
    break;}
case 73:
#line 631 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 74:
#line 632 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 75:
#line 633 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 76:
#line 634 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 77:
#line 635 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 78:
#line 636 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 79:
#line 637 "parser.y"
{ yyval.uStmt = createReturnStmt(yyvsp[0].uExpr); ;
    break;}
case 80:
#line 638 "parser.y"
{ yyval.uStmt = createReturnStmt(NULL); ;
    break;}
case 81:
#line 642 "parser.y"
{ yyval.uStmtSeq = NULL; ;
    break;}
case 82:
#line 643 "parser.y"
{ yyval.uStmtSeq = yyvsp[0].uStmtSeq; ;
    break;}
case 83:
#line 646 "parser.y"
{ yyval.uStmtSeq = createStmtSeq(yyvsp[0].uStmt); ;
    break;}
case 84:
#line 647 "parser.y"
{ yyval.uStmtSeq = addStmtToSeq(yyvsp[-2].uStmtSeq, yyvsp[0].uStmt); ;
    break;}
case 85:
#line 648 "parser.y"
{ yyval.uStmtSeq = yyvsp[-1].uStmtSeq; ;
    break;}
case 86:
#line 651 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 87:
#line 652 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 88:
#line 653 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 89:
#line 654 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 90:
#line 655 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 91:
#line 656 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 92:
#line 657 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 93:
#line 658 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 94:
#line 659 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 95:
#line 660 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 96:
#line 663 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(NULL); ;
    break;}
case 97:
#line 664 "parser.y"
{ yyval.uMethodDefParamSeq = yyvsp[0].uMethodDefParamSeq;;
    break;}
case 98:
#line 667 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(yyvsp[0].uMethodDefParam); ;
    break;}
case 99:
#line 668 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-3].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 100:
#line 669 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-2].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 101:
#line 672 "parser.y"
{ yyval.uMethodDefParam = createMethodDefParam(yyvsp[0].uId); ;
    break;}
case 102:
#line 675 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 103:
#line 676 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 104:
#line 677 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 105:
#line 678 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 106:
#line 680 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 107:
#line 681 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 108:
#line 682 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 109:
#line 683 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 110:
#line 685 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 111:
#line 686 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 112:
#line 687 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 113:
#line 688 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 114:
#line 691 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 115:
#line 692 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 116:
#line 693 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 117:
#line 694 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 118:
#line 697 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 119:
#line 698 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 120:
#line 699 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 121:
#line 700 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 122:
#line 702 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 123:
#line 703 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 124:
#line 704 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 125:
#line 705 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 126:
#line 707 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 127:
#line 708 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 128:
#line 709 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 129:
#line 710 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 130:
#line 713 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 131:
#line 714 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 132:
#line 715 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 133:
#line 716 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 134:
#line 720 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 135:
#line 721 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 136:
#line 722 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 137:
#line 723 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 138:
#line 725 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 139:
#line 726 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 140:
#line 729 "parser.y"
{ yyval.uElsifSeq = NULL ;
    break;}
case 141:
#line 730 "parser.y"
{ yyval.uElsifSeq = yyvsp[0].uElsifSeq ;
    break;}
case 142:
#line 733 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 143:
#line 734 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-4].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 144:
#line 736 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 145:
#line 737 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 146:
#line 738 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 147:
#line 740 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 148:
#line 741 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 149:
#line 742 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 150:
#line 744 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 151:
#line 745 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 152:
#line 746 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 153:
#line 747 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 154:
#line 749 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 155:
#line 750 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 156:
#line 751 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 157:
#line 752 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-7].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 158:
#line 755 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 159:
#line 756 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 160:
#line 758 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 161:
#line 759 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 162:
#line 760 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 163:
#line 762 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 164:
#line 763 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 165:
#line 764 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 166:
#line 766 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 167:
#line 767 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 168:
#line 768 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 169:
#line 769 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 170:
#line 771 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 171:
#line 772 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 172:
#line 773 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 173:
#line 774 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 174:
#line 775 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 175:
#line 776 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 176:
#line 777 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-9].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 177:
#line 780 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 178:
#line 781 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 179:
#line 783 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 180:
#line 784 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 181:
#line 785 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 182:
#line 787 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 183:
#line 788 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 184:
#line 789 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 185:
#line 791 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 186:
#line 792 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 187:
#line 793 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 188:
#line 794 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 189:
#line 796 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 190:
#line 797 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 191:
#line 798 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 192:
#line 799 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 193:
#line 800 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-8].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 194:
#line 801 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 195:
#line 802 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-8].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
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
#line 805 "parser.y"

void yyerror(const char *s)
{
    printf("%s !",s);
}

