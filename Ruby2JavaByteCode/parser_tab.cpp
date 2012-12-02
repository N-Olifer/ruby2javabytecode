
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
#define	EQUAL	271
#define	NOTEQUAL	272
#define	OR	273
#define	AND	274
#define	NIL	275
#define	TRUE	276
#define	FALSE	277
#define	IF	278
#define	ELSIF	279
#define	ELSE	280
#define	UNLESS	281
#define	THEN	282
#define	UMINUS	283
#define	UBR	284

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


#line 435 "parser.y"
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



#define	YYFINAL		573
#define	YYFLAG		-32768
#define	YYNTBASE	44

#define YYTRANSLATE(x) ((unsigned)(x) <= 284 ? yytranslate[x] : 61)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    35,     2,     2,     2,     2,     2,     2,    42,
    41,    33,    32,    43,    31,    37,    34,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
    28,    30,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    39,     2,    38,     2,     2,     2,     2,     2,     2,     2,
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
    26,    27,    36,    40
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     9,    14,    19,    23,    28,    32,    37,
    41,    45,    50,    54,    59,    63,    68,    72,    77,    81,
    86,    90,    95,    98,   102,   107,   110,   114,   119,   124,
   130,   135,   141,   147,   154,   159,   165,   170,   174,   177,
   181,   183,   185,   187,   189,   191,   197,   204,   212,   221,
   229,   236,   244,   253,   263,   272,   274,   278,   283,   289,
   296,   302,   304,   308,   313,   319,   326,   332,   334,   338,
   343,   345,   347,   349,   351,   353,   355,   357,   360,   362,
   363,   365,   367,   371,   374,   384,   395,   404,   414,   422,
   430,   439,   448,   458,   465,   466,   468,   470,   475,   479,
   481,   488,   494,   502,   509,   517,   524,   533,   541,   552,
   562,   572,   581,   591,   600,   609,   617,   624,   630,   638,
   645,   653,   660,   669,   677,   688,   698,   708,   717,   727,
   736,   745,   753,   763,   772,   781,   789,   796,   802,   803,
   805,   810,   816,   822,   828,   835,   842,   849,   857,   863,
   870,   877,   885,   892,   900,   908,   917,   924,   933,   941,
   949,   958,   968,   978,   989,   997,  1006,  1015,  1025,  1035,
  1046,  1057,  1068,  1080,  1092,  1105,  1111,  1119,  1126,  1133,
  1141,  1150,  1159,  1169,  1176,  1184,  1192,  1201,  1210,  1220,
  1230,  1240,  1251,  1262
};

static const short yyrhs[] = {    48,
     0,     5,    48,     0,    45,    32,    45,     0,    45,    32,
     5,    45,     0,    45,    31,     5,    45,     0,    45,    31,
    45,     0,    45,    33,     5,    45,     0,    45,    33,    45,
     0,    45,    34,     5,    45,     0,    45,    34,    45,     0,
    45,    29,    45,     0,    45,    29,     5,    45,     0,    45,
    30,    45,     0,    45,    30,     5,    45,     0,    45,    16,
    45,     0,    45,    16,     5,    45,     0,    45,    17,    45,
     0,    45,    17,     5,    45,     0,    45,    18,    45,     0,
    45,    18,     5,    45,     0,    45,    19,    45,     0,    45,
    19,     5,    45,     0,    35,    45,     0,    45,    28,    45,
     0,    45,    28,     5,    45,     0,    31,    45,     0,    42,
    45,    41,     0,    42,    45,     5,    41,     0,    42,     5,
    45,    41,     0,    42,     5,    45,     5,    41,     0,    45,
    39,    45,    38,     0,    45,    39,    45,     5,    38,     0,
    45,    39,     5,    45,    38,     0,    45,    39,     5,    45,
     5,    38,     0,    39,     5,    46,    38,     0,    39,     5,
    46,     5,    38,     0,    39,    46,     5,    38,     0,    39,
    46,    38,     0,    39,    38,     0,    39,     5,    38,     0,
     3,     0,     4,     0,    20,     0,    21,     0,    22,     0,
    45,    37,    15,    42,    41,     0,    45,    37,    15,    42,
    46,    41,     0,    45,    37,    15,    42,     5,    46,    41,
     0,    45,    37,    15,    42,     5,    46,     5,    41,     0,
    45,    37,    15,    42,    46,     5,    41,     0,    45,    37,
     5,    15,    42,    41,     0,    45,    37,     5,    15,    42,
    46,    41,     0,    45,    37,     5,    15,    42,     5,    46,
    41,     0,    45,    37,     5,    15,    42,     5,    46,     5,
    41,     0,    45,    37,     5,    15,    42,    46,     5,    41,
     0,    15,     0,    15,    42,    41,     0,    15,    42,    46,
    41,     0,    15,    42,     5,    46,    41,     0,    15,    42,
     5,    46,     5,    41,     0,    15,    42,    46,     5,    41,
     0,    12,     0,    13,    42,    41,     0,    13,    42,    46,
    41,     0,    13,    42,     5,    46,    41,     0,    13,    42,
     5,    46,     5,    41,     0,    13,    42,    46,     5,    41,
     0,    45,     0,    46,    43,    45,     0,    46,    43,     5,
    45,     0,    45,     0,    50,     0,    56,     0,    54,     0,
    55,     0,    59,     0,    60,     0,    14,    45,     0,    14,
     0,     0,    49,     0,    47,     0,    49,     5,    47,     0,
    49,     5,     0,     6,     5,    15,    42,    51,     5,    41,
    48,     7,     0,     6,     5,    15,    42,    51,     5,    41,
     5,    48,     7,     0,     6,     5,    15,    42,    51,    41,
    48,     7,     0,     6,     5,    15,    42,    51,    41,     5,
    48,     7,     0,     6,     5,    15,    51,     5,    48,     7,
     0,     6,    15,    42,    51,    41,    48,     7,     0,     6,
    15,    42,    51,    41,     5,    48,     7,     0,     6,    15,
    42,    51,     5,    41,    48,     7,     0,     6,    15,    42,
    51,     5,    41,     5,    48,     7,     0,     6,    15,    51,
     5,    48,     7,     0,     0,    52,     0,    53,     0,    51,
    43,     5,    53,     0,    51,    43,    53,     0,    15,     0,
     8,     5,    45,     9,    48,     7,     0,     8,    45,     9,
    48,     7,     0,     8,     5,    45,     9,     5,    48,     7,
     0,     8,    45,     9,     5,    48,     7,     0,     8,     5,
    45,     5,     9,    48,     7,     0,     8,    45,     5,     9,
    48,     7,     0,     8,     5,    45,     5,     9,     5,    48,
     7,     0,     8,    45,     5,     9,     5,    48,     7,     0,
     8,     5,    42,     5,    45,     5,    41,     5,    48,     7,
     0,     8,     5,    42,     5,    45,    41,     5,    48,     7,
     0,     8,     5,    42,    45,     5,    41,     5,    48,     7,
     0,     8,     5,    42,    45,    41,     5,    48,     7,     0,
     8,    42,     5,    45,     5,    41,     5,    48,     7,     0,
     8,    42,     5,    45,    41,     5,    48,     7,     0,     8,
    42,    45,     5,    41,     5,    48,     7,     0,     8,    42,
    45,    41,     5,    48,     7,     0,    10,     5,    45,     9,
    48,     7,     0,    10,    45,     9,    48,     7,     0,    10,
     5,    45,     9,     5,    48,     7,     0,    10,    45,     9,
     5,    48,     7,     0,    10,     5,    45,     5,     9,    48,
     7,     0,    10,    45,     5,     9,    48,     7,     0,    10,
     5,    45,     5,     9,     5,    48,     7,     0,    10,    45,
     5,     9,     5,    48,     7,     0,    10,     5,    42,     5,
    45,     5,    41,     5,    48,     7,     0,    10,     5,    42,
     5,    45,    41,     5,    48,     7,     0,    10,     5,    42,
    45,     5,    41,     5,    48,     7,     0,    10,     5,    42,
    45,    41,     5,    48,     7,     0,    10,    42,     5,    45,
     5,    41,     5,    48,     7,     0,    10,    42,     5,    45,
    41,     5,    48,     7,     0,    10,    42,    45,     5,    41,
     5,    48,     7,     0,    10,    42,    45,    41,     5,    48,
     7,     0,    11,     5,    15,    29,     5,    15,     5,    48,
     7,     0,    11,     5,    15,    29,    15,     5,    48,     7,
     0,    11,    15,    29,     5,    15,     5,    48,     7,     0,
    11,    15,    29,    15,     5,    48,     7,     0,    11,     5,
    15,     5,    48,     7,     0,    11,    15,     5,    48,     7,
     0,     0,    58,     0,    24,    45,    27,    48,     0,    58,
    24,    45,    27,    48,     0,    24,     5,    45,    27,    48,
     0,    24,    45,     5,    27,    48,     0,    24,     5,    45,
     5,    27,    48,     0,    58,    24,     5,    45,    27,    48,
     0,    58,    24,    45,     5,    27,    48,     0,    58,    24,
     5,    45,     5,    27,    48,     0,    24,    45,    27,     5,
    48,     0,    24,    45,     5,    27,     5,    48,     0,    24,
     5,    45,    27,     5,    48,     0,    24,     5,    45,     5,
    27,     5,    48,     0,    58,    24,    45,    27,     5,    48,
     0,    58,    24,    45,     5,    27,     5,    48,     0,    58,
    24,     5,    45,    27,     5,    48,     0,    58,    24,     5,
    45,     5,    27,     5,    48,     0,    23,    45,    27,    48,
    57,     7,     0,    23,    45,    27,    48,    57,    25,    48,
     7,     0,    23,     5,    45,    27,    48,    57,     7,     0,
    23,    45,     5,    27,    48,    57,     7,     0,    23,     5,
    45,     5,    27,    48,    57,     7,     0,    23,     5,    45,
    27,    48,    57,    25,    48,     7,     0,    23,    45,     5,
    27,    48,    57,    25,    48,     7,     0,    23,     5,    45,
     5,    27,    48,    57,    25,    48,     7,     0,    23,    45,
    27,     5,    48,    57,     7,     0,    23,     5,    45,    27,
     5,    48,    57,     7,     0,    23,    45,     5,    27,     5,
    48,    57,     7,     0,    23,     5,    45,     5,    27,     5,
    48,    57,     7,     0,    23,    45,    27,    48,    57,    25,
     5,    48,     7,     0,    23,    45,    27,     5,    48,    57,
    25,     5,    48,     7,     0,    23,    45,     5,    27,    48,
    57,    25,     5,    48,     7,     0,    23,     5,    45,    27,
    48,    57,    25,     5,    48,     7,     0,    23,     5,    45,
     5,    27,    48,    57,    25,     5,    48,     7,     0,    23,
     5,    45,    27,     5,    48,    57,    25,     5,    48,     7,
     0,    23,     5,    45,     5,    27,     5,    48,    57,    25,
     5,    48,     7,     0,    26,    45,    27,    48,     7,     0,
    26,    45,    27,    48,    25,    48,     7,     0,    26,     5,
    45,    27,    48,     7,     0,    26,    45,     5,    27,    48,
     7,     0,    26,     5,    45,     5,    27,    48,     7,     0,
    26,     5,    45,    27,    48,    25,    48,     7,     0,    26,
    45,     5,    27,    48,    25,    48,     7,     0,    26,     5,
    45,     5,    27,    48,    25,    48,     7,     0,    26,    45,
    27,     5,    48,     7,     0,    26,    45,     5,    27,     5,
    48,     7,     0,    26,     5,    45,    27,     5,    48,     7,
     0,    26,     5,    45,     5,    27,     5,    48,     7,     0,
    26,    45,    27,    48,    25,     5,    48,     7,     0,    26,
    45,    27,     5,    48,    25,     5,    48,     7,     0,    26,
    45,     5,    27,    48,    25,     5,    48,     7,     0,    26,
     5,    45,    27,    48,    25,     5,    48,     7,     0,    26,
    45,     5,    27,     5,    48,    25,     5,    48,     7,     0,
    26,     5,    45,    27,     5,    48,    25,     5,    48,     7,
     0,    26,     5,    45,     5,    27,     5,    48,    25,     5,
    48,     7,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   515,   516,   519,   520,   522,   523,   525,   526,   528,   529,
   531,   532,   534,   535,   537,   538,   540,   541,   543,   544,
   546,   547,   549,   551,   552,   554,   556,   557,   558,   559,
   561,   562,   563,   564,   566,   567,   568,   569,   571,   572,
   574,   575,   576,   577,   578,   580,   581,   582,   583,   584,
   586,   587,   588,   589,   590,   593,   594,   595,   596,   597,
   598,   599,   601,   602,   603,   604,   605,   608,   609,   610,
   613,   614,   615,   616,   617,   618,   619,   620,   621,   625,
   626,   629,   630,   631,   634,   635,   636,   637,   638,   639,
   640,   641,   642,   643,   646,   647,   650,   651,   652,   655,
   658,   659,   660,   661,   663,   664,   665,   666,   668,   669,
   670,   671,   674,   675,   676,   677,   680,   681,   682,   683,
   685,   686,   687,   688,   690,   691,   692,   693,   696,   697,
   698,   699,   703,   704,   705,   706,   708,   709,   712,   713,
   716,   717,   719,   720,   721,   723,   724,   725,   727,   728,
   729,   730,   732,   733,   734,   735,   738,   739,   741,   742,
   743,   745,   746,   747,   749,   750,   751,   752,   754,   755,
   756,   757,   758,   759,   760,   763,   764,   766,   767,   768,
   770,   771,   772,   774,   775,   776,   777,   779,   780,   781,
   782,   783,   784,   785
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN","ID",
"EQUAL","NOTEQUAL","OR","AND","NIL","TRUE","FALSE","IF","ELSIF","ELSE","UNLESS",
"THEN","'='","'<'","'>'","'-'","'+'","'*'","'/'","'!'","UMINUS","'.'","']'",
"'['","UBR","')'","'('","','","program","expr","expr_seqE","stmt","stmt_seq",
"stmt_seqE","method_def","method_def_param_seq","method_def_param_seqE","method_def_param",
"while_stmt","until_stmt","class_def","elsif_seq","elsif_seqE","if_stmt","unless_stmt",
""
};
#endif

static const short yyr1[] = {     0,
    44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    46,    46,    46,
    47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
    48,    49,    49,    49,    50,    50,    50,    50,    50,    50,
    50,    50,    50,    50,    51,    51,    52,    52,    52,    53,
    54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
    54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
    55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
    55,    55,    56,    56,    56,    56,    56,    56,    57,    57,
    58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
    58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
    60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
    60,    60,    60,    60
};

static const short yyr2[] = {     0,
     1,     2,     3,     4,     4,     3,     4,     3,     4,     3,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     2,     3,     4,     2,     3,     4,     4,     5,
     4,     5,     5,     6,     4,     5,     4,     3,     2,     3,
     1,     1,     1,     1,     1,     5,     6,     7,     8,     7,
     6,     7,     8,     9,     8,     1,     3,     4,     5,     6,
     5,     1,     3,     4,     5,     6,     5,     1,     3,     4,
     1,     1,     1,     1,     1,     1,     1,     2,     1,     0,
     1,     1,     3,     2,     9,    10,     8,     9,     7,     7,
     8,     8,     9,     6,     0,     1,     1,     4,     3,     1,
     6,     5,     7,     6,     7,     6,     8,     7,    10,     9,
     9,     8,     9,     8,     8,     7,     6,     5,     7,     6,
     7,     6,     8,     7,    10,     9,     9,     8,     9,     8,
     8,     7,     9,     8,     8,     7,     6,     5,     0,     1,
     4,     5,     5,     5,     6,     6,     6,     7,     5,     6,
     6,     7,     6,     7,     7,     8,     6,     8,     7,     7,
     8,     9,     9,    10,     7,     8,     8,     9,     9,    10,
    10,    10,    11,    11,    12,     5,     7,     6,     6,     7,
     8,     8,     9,     6,     7,     7,     8,     8,     9,     9,
     9,    10,    10,    11
};

static const short yydefact[] = {    80,
    41,    42,    80,     0,     0,     0,     0,    62,     0,    79,
    56,    43,    44,    45,     0,     0,     0,     0,     0,     0,
    71,    82,     1,    81,    72,    74,    75,    73,    76,    77,
     2,     0,    95,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    78,     0,     0,     0,     0,     0,    26,    23,
     0,    39,    68,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
    95,   100,    95,     0,    96,    97,     0,     0,     0,     0,
     0,    80,     0,     0,     0,     0,     0,    80,     0,    80,
     0,     0,    63,     0,     0,    57,     0,     0,     0,    80,
     0,     0,    80,    40,     0,     0,    38,     0,     0,     0,
    27,     0,    15,     0,    17,     0,    19,     0,    21,     0,
    24,     0,    11,     0,    13,     0,     6,     0,     3,     0,
     8,     0,    10,     0,     0,     0,     0,    83,    95,     0,
     0,    80,     0,     0,     0,     0,    80,     0,     0,    27,
    80,    80,     0,     0,     0,     0,    80,     0,     0,    27,
    80,    80,     0,    80,     0,     0,     0,     0,     0,     0,
    64,     0,     0,    58,     0,    80,    80,    80,   139,     0,
    80,    80,    80,     0,     0,    35,    37,     0,    69,     0,
    29,    28,    16,    18,    20,    22,    25,    12,    14,     5,
     4,     7,     9,     0,     0,     0,     0,    31,     0,    80,
     0,    80,     0,     0,    99,     0,     0,    27,    80,    80,
     0,     0,    29,    28,    80,    80,     0,     0,   102,     0,
     0,    27,    80,    80,     0,     0,    29,    28,    80,    80,
     0,     0,   118,     0,     0,     0,   138,     0,    80,     0,
    65,    67,     0,    59,    61,    80,    80,   139,    80,   139,
   139,     0,     0,   140,    80,    80,     0,    80,     0,     0,
   176,    80,    36,    70,    30,     0,     0,    46,     0,     0,
    33,    32,     0,    80,     0,    80,    80,     0,    94,    98,
     0,    29,    28,    80,    80,     0,     0,   101,    30,    80,
    80,     0,     0,   106,   104,     0,    29,    28,    80,    80,
     0,     0,   117,    30,    80,    80,     0,     0,   122,   120,
   137,     0,    80,    80,     0,    66,    60,    80,   139,   139,
     0,   139,     0,     0,     0,     0,   157,    80,     0,    80,
     0,     0,   178,    80,     0,   179,    80,   184,     0,    80,
     0,     0,    51,     0,     0,     0,    47,    34,    80,    80,
     0,    89,    80,     0,     0,    90,    30,    80,    80,     0,
     0,   105,   103,    80,     0,     0,   116,   108,    30,    80,
    80,     0,     0,   121,   119,    80,     0,     0,   132,   124,
    80,     0,     0,   136,   139,     0,     0,   159,    80,     0,
   160,    80,   165,     0,     0,     0,    80,    80,     0,     0,
     0,     0,   180,    80,   186,     0,    80,     0,   185,     0,
    80,     0,    80,     0,   177,     0,     0,    52,     0,    48,
    50,    80,     0,     0,    87,     0,    92,    91,    80,     0,
     0,   112,   107,     0,   114,   115,    80,     0,     0,   128,
   123,     0,   130,   131,     0,   134,   135,     0,   161,    80,
   166,     0,    80,     0,   167,    80,     0,    80,     0,    80,
    80,    80,   141,     0,   158,     0,     0,    80,   187,     0,
     0,    80,     0,   181,    80,     0,   182,     0,   188,     0,
    53,    55,    49,     0,    85,    88,    93,     0,   110,   111,
   113,     0,   126,   127,   129,   133,   168,     0,    80,     0,
    80,     0,   162,     0,   163,     0,    80,    80,   143,    80,
   144,   149,   169,     0,    80,    80,    80,   142,    80,   183,
     0,   191,     0,   190,   189,    54,    86,   109,   125,    80,
     0,   164,     0,   172,   171,   170,    80,   145,   151,   150,
    80,    80,   146,    80,   147,   153,     0,   193,   192,     0,
   173,   174,   152,    80,   148,   155,   154,   194,   175,   156,
     0,     0,     0
};

static const short yydefgoto[] = {   571,
    21,    54,    22,    23,    24,    25,    74,    75,    76,    26,
    27,    28,   263,   264,    29,    30
};

static const short yypact[] = {   420,
-32768,-32768,  1909,     7,  2009,  2034,    78,-32768,   -18,  2649,
   -10,-32768,-32768,-32768,  2059,  2084,  2649,  2649,   190,  2109,
  3444,-32768,-32768,    33,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    24,    11,  2674,  2134,  3027,  2699,  2159,  3058,    74,
    76,   311,  3444,  1934,  2649,  3088,  2649,  3118,   -14,   -14,
  2184,-32768,  3444,     2,  2649,  2726,  2224,  2249,  2274,  2299,
  2324,  2349,  2374,  2399,  2424,  2449,  2474,   105,  2499,  1909,
    13,-32768,    88,     5,-32768,-32768,  2524,  3149,  2649,  2756,
    95,   490,  2549,  3180,  2649,  2786,   100,   552,    97,  1909,
   136,  2649,-32768,     6,  2649,-32768,    26,  3210,    85,   592,
  3240,    89,   632,-32768,    37,   119,-32768,  2574,  2816,   121,
-32768,  2649,   256,  2649,   256,  2649,  2201,  2649,   210,  2649,
  3444,  2649,   240,  2649,   240,  2649,   218,  2649,   218,  2649,
   -14,  2649,   -14,   155,   134,  2649,  3270,-32768,    88,     8,
    30,  1909,   141,  2649,  2846,   168,   672,  2876,   148,-32768,
   712,  1909,   185,  2649,  2906,   188,   752,  2936,   172,-32768,
   792,  1909,   194,  1909,   193,   199,   200,   213,    47,   178,
-32768,    65,   179,-32768,   197,   832,   872,  1909,   209,   207,
   912,   952,  1909,    -5,   212,-32768,-32768,  2649,  3444,   204,
-32768,-32768,   256,   256,  2201,   210,  3444,   240,   240,   218,
   218,   -14,   -14,   196,  1959,  3300,   220,-32768,    81,  1909,
   219,   992,   228,    88,-32768,  2966,   223,-32768,  1032,  1909,
   241,   225,-32768,-32768,  1909,  1909,   252,   260,-32768,  2996,
   227,-32768,  1072,  1909,   263,   237,-32768,-32768,  1909,  1909,
   273,   275,-32768,   287,   281,   294,-32768,   295,  1909,   261,
-32768,-32768,   262,-32768,-32768,  1112,  1909,   209,  1909,   209,
   209,  2599,    -4,   280,  1152,  1909,    70,  1909,   111,   130,
-32768,  1192,-32768,  3444,-32768,  1984,  2649,-32768,    87,   267,
-32768,-32768,   268,  1232,   301,  1272,  1909,   303,-32768,-32768,
   270,-32768,-32768,  1909,  1909,   310,   312,-32768,-32768,  1909,
  1909,   315,   320,-32768,-32768,   277,-32768,-32768,  1909,  1909,
   321,   322,-32768,-32768,  1909,  1909,   323,   329,-32768,-32768,
-32768,   334,  1909,  1909,   333,-32768,-32768,  1909,   209,   209,
   135,   209,   138,   158,  2649,  3330,-32768,  1312,  2624,  1909,
   159,   160,-32768,  1352,   161,-32768,  1392,-32768,   338,  1909,
   341,  2649,-32768,    91,   109,   304,-32768,-32768,  1432,  1909,
   342,-32768,  1909,   347,   348,-32768,-32768,  1909,  1909,   351,
   352,-32768,-32768,  1909,   354,   355,-32768,-32768,-32768,  1909,
  1909,   356,   357,-32768,-32768,  1909,   360,   361,-32768,-32768,
  1909,   362,   363,-32768,   209,   165,   174,-32768,  1472,   367,
-32768,  1512,-32768,   370,  3360,   349,  1552,  1909,   372,  2649,
  3390,   175,-32768,  1909,-32768,   375,  1909,   374,-32768,   377,
  1909,   378,  1909,   379,-32768,   128,   343,-32768,   346,-32768,
-32768,  1909,   382,   383,-32768,   384,-32768,-32768,  1909,   385,
   386,-32768,-32768,   387,-32768,-32768,  1909,   388,   390,-32768,
-32768,   391,-32768,-32768,   393,-32768,-32768,   189,-32768,  1592,
-32768,   396,  1909,   395,-32768,  1909,   399,  1909,   376,  1632,
  1672,  1909,-32768,   400,-32768,  3420,   381,  1712,-32768,   405,
   406,  1909,   408,-32768,  1909,   409,-32768,   410,-32768,   371,
-32768,-32768,-32768,   412,-32768,-32768,-32768,   414,-32768,-32768,
-32768,   415,-32768,-32768,-32768,-32768,-32768,   422,  1909,   430,
  1909,   431,-32768,   432,-32768,   438,  1752,  1909,-32768,  1909,
-32768,-32768,-32768,   423,  1792,  1832,  1909,-32768,  1909,-32768,
   440,-32768,   442,-32768,-32768,-32768,-32768,-32768,-32768,  1909,
   445,-32768,   446,-32768,-32768,-32768,  1909,-32768,-32768,-32768,
  1872,  1909,-32768,  1909,-32768,-32768,   447,-32768,-32768,   449,
-32768,-32768,-32768,  1909,-32768,-32768,-32768,-32768,-32768,-32768,
   458,   461,-32768
};

static const short yypgoto[] = {-32768,
    -1,    96,   394,    -3,-32768,-32768,   -65,-32768,  -142,-32768,
-32768,-32768,  -231,-32768,-32768,-32768
};


#define	YYLAST		3483


static const short yytable[] = {    31,
   215,   271,   337,    36,    39,   140,   106,   141,    43,   142,
   170,    32,   210,    46,    48,    49,    50,    53,    56,   272,
   338,    33,    68,    42,    69,    72,   331,    72,   333,   334,
   173,    44,    78,    80,   211,    84,    86,    70,    71,   107,
    53,   185,    53,    98,   108,   101,   171,   143,   108,    53,
   143,   250,    73,   109,   139,   113,   115,   117,   119,   121,
   123,   125,   127,   129,   131,   133,   174,   137,   108,   253,
   212,   290,   143,   209,   186,   145,   343,   148,   153,   108,
    90,   155,    40,   158,   163,   283,   166,   251,    89,   108,
    53,   356,    41,    53,   344,   427,   179,   396,   397,   184,
   400,   164,    72,   151,    91,   254,   189,   108,   161,   134,
   193,   177,   194,   429,   195,   182,   196,   346,   197,   135,
   198,   284,   199,   143,   200,   165,   201,   357,   202,   108,
   203,   428,   490,   108,   206,   347,   348,    94,   213,    97,
   167,   398,   216,   221,   401,   214,   105,   227,   228,   430,
   168,   108,   230,   235,   349,    72,   187,   241,   242,   399,
   244,   192,   402,   458,   403,   413,   415,   419,   491,   204,
   108,   459,   258,   260,   261,   205,   219,   267,   269,   270,
   461,   479,   404,   414,   416,   420,   274,   169,   224,   460,
   172,   229,     1,     2,    51,   507,   233,   245,   462,   480,
   243,     8,     9,    53,    11,   247,   285,   246,   288,    12,
    13,    14,   238,   508,   248,   296,   297,   249,   252,   255,
    17,   302,   303,   256,    18,    57,    58,    52,    19,   311,
   312,    20,   262,   265,   289,   317,   318,   276,    62,    63,
    64,    65,    66,    67,   275,   325,    68,   298,    69,   273,
    66,    67,   329,   330,    68,   332,    69,   282,   304,   286,
   336,   341,   342,   293,   345,   299,   305,   308,   351,   313,
    64,    65,    66,    67,    53,    53,    68,   314,    69,   319,
   361,   320,   364,   365,    62,    63,    64,    65,    66,    67,
   370,   371,    68,   321,    69,   322,   375,   376,   323,   324,
   279,   326,   327,   339,   358,   382,   383,   362,   359,   366,
   367,   387,   388,     1,     2,    92,   372,   379,   373,   392,
   393,   377,     8,     9,   395,    11,   378,   384,   385,   389,
    12,    13,    14,   405,   409,   390,   412,   411,   391,   394,
   418,    17,   423,   422,   431,    18,   424,   425,   435,    19,
    53,    93,    20,   437,   438,   433,   434,   442,   443,   436,
   445,   446,   450,   451,   440,   441,   453,   454,   456,   457,
   444,   354,   355,   465,   468,   471,   448,   449,   475,   482,
   484,   485,   452,   492,   487,   489,   493,   455,   495,   496,
   497,   499,   500,   501,   503,   464,   504,   505,   467,   506,
   511,   513,   517,   473,   474,   515,   523,   526,   476,   529,
   481,   536,   530,   483,   532,   534,   535,   486,   537,   488,
   538,   539,     1,     2,     3,     4,   540,     5,   494,     6,
     7,     8,     9,    10,    11,   498,   542,   544,   545,    12,
    13,    14,    15,   502,   546,    16,   558,   426,   559,   551,
    17,   561,   562,   568,    18,   569,   510,   572,    19,   512,
   573,    20,   514,   138,   516,     0,   519,   521,   522,     0,
     0,     0,     0,     0,   528,     0,     0,     0,   531,     0,
     0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     1,     2,   152,     4,     0,     5,     0,     6,
     7,     8,     9,    10,    11,   541,     0,   543,     0,    12,
    13,    14,    15,   548,   549,    16,   550,     0,     0,     0,
    17,   553,   555,   556,    18,   557,     0,     0,    19,     0,
     0,    20,     0,     0,     0,     0,   560,     0,     0,     0,
     0,     0,     0,   563,     0,     0,     0,   565,   566,     0,
   567,     0,     0,     0,     1,     2,   162,     4,     0,     5,
   570,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   178,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   183,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   220,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   226,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   234,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   240,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   257,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   259,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   266,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   268,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   287,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   295,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   310,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   328,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   340,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   350,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   360,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   363,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   408,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   417,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   421,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   432,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   463,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   466,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   472,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   509,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   518,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   520,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   527,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   547,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   552,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   554,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     0,     0,    20,     1,     2,   564,     4,     0,     5,
     0,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     0,    12,    13,    14,    15,     0,     0,    16,     0,     0,
     0,     0,    17,     0,     0,     0,    18,     0,     0,     0,
    19,     1,     2,    20,     4,     0,     5,     0,     6,     7,
     8,     9,    10,    11,     0,     0,     0,     0,    12,    13,
    14,    15,     0,     0,    16,     0,     1,     2,    95,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   277,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,    96,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   352,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,   278,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,    34,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,   353,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,    37,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    35,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,    45,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    38,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,    47,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,    55,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,    79,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,    85,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,     0,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     0,     0,     0,    17,     0,    57,    58,    18,    60,
     0,   104,    19,     0,     0,    20,     1,     2,   112,    62,
    63,    64,    65,    66,    67,     8,     9,    68,    11,    69,
     0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   114,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   116,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   118,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   120,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   122,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   124,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   126,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   128,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   130,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   132,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   136,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   144,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   154,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   188,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,   335,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,   410,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,     0,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    20,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     1,     2,     0,    17,
     0,     0,     0,    18,     0,     8,     9,    19,    11,     0,
    20,     0,     0,    12,    13,    14,     0,     0,     0,     0,
     0,     1,     2,     0,    17,     0,     0,     0,    18,     0,
     8,     9,    19,    11,     0,    77,     0,     0,    12,    13,
    14,     0,     0,     0,     0,     0,     0,     0,     0,    17,
   110,     0,     0,    18,     0,     0,     0,    19,     0,     0,
    83,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   149,     0,    68,     0,    69,     0,   111,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   159,     0,    68,     0,    69,     0,   150,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   190,     0,    68,     0,    69,     0,   160,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   217,     0,    68,     0,    69,     0,   191,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   222,     0,    68,     0,    69,     0,   218,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   231,     0,    68,     0,    69,     0,   223,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   236,     0,    68,     0,    69,     0,   232,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   291,     0,    68,     0,    69,     0,   237,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
   306,     0,    68,     0,    69,     0,   292,     0,     0,     0,
     0,    57,    58,    59,    60,     0,     0,     0,     0,     0,
     0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
     0,    81,    68,     0,    69,    82,   307,     0,     0,     0,
     0,     0,    57,    58,    59,    60,     0,     0,     0,     0,
     0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
    67,     0,    87,    68,     0,    69,    88,     0,     0,     0,
     0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
     0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
    66,    67,    99,     0,    68,     0,    69,     0,     0,     0,
     0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
     0,     0,     0,     0,   100,    61,    62,    63,    64,    65,
    66,    67,   102,     0,    68,     0,    69,     0,     0,     0,
     0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
     0,     0,     0,     0,   103,    61,    62,    63,    64,    65,
    66,    67,     0,   146,    68,     0,    69,   147,     0,     0,
     0,     0,     0,     0,    57,    58,    59,    60,     0,     0,
     0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
    65,    66,    67,     0,   156,    68,     0,    69,   157,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
    64,    65,    66,    67,   175,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   176,    61,    62,    63,
    64,    65,    66,    67,   180,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   181,    61,    62,    63,
    64,    65,    66,    67,   207,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
    64,    65,    66,    67,   280,     0,    68,   208,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
    64,    65,    66,    67,   406,     0,    68,   281,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   407,    61,    62,    63,
    64,    65,    66,    67,   469,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   470,    61,    62,    63,
    64,    65,    66,    67,   477,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   478,    61,    62,    63,
    64,    65,    66,    67,   524,     0,    68,     0,    69,     0,
     0,     0,     0,     0,     0,    57,    58,    59,    60,     0,
     0,     0,     0,     0,     0,     0,   525,    61,    62,    63,
    64,    65,    66,    67,     0,     0,    68,     0,    69,    57,
    58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
     0,    61,    62,    63,    64,    65,    66,    67,     0,     0,
    68,     0,    69
};

static const short yycheck[] = {     3,
   143,     7,     7,     5,     6,    71,     5,    73,    10,     5,
     5,     5,     5,    15,    16,    17,    18,    19,    20,    25,
    25,    15,    37,    42,    39,    15,   258,    15,   260,   261,
     5,    42,    34,    35,     5,    37,    38,     5,    15,    38,
    42,     5,    44,    45,    43,    47,    41,    43,    43,    51,
    43,     5,    42,    55,    42,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    41,    69,    43,     5,
    41,   214,    43,   139,    38,    77,     7,    79,    82,    43,
     5,    83,     5,    85,    88,     5,    90,    41,    15,    43,
    92,     5,    15,    95,    25,     5,   100,   329,   330,   103,
   332,     5,    15,     9,    29,    41,   108,    43,     9,     5,
   112,    27,   114,     5,   116,    27,   118,     7,   120,    15,
   122,    41,   124,    43,   126,    29,   128,    41,   130,    43,
   132,    41,     5,    43,   136,    25,     7,    42,   142,    44,
     5,     7,   144,   147,     7,     5,    51,   151,   152,    41,
    15,    43,   154,   157,    25,    15,    38,   161,   162,    25,
   164,    41,    25,   395,     7,     7,     7,     7,    41,    15,
    43,     7,   176,   177,   178,    42,     9,   181,   182,   183,
     7,     7,    25,    25,    25,    25,   188,    92,    41,    25,
    95,     7,     3,     4,     5,     7,     9,     5,    25,    25,
     7,    12,    13,   205,    15,     7,   210,    15,   212,    20,
    21,    22,    41,    25,    15,   219,   220,     5,    41,    41,
    31,   225,   226,    27,    35,    16,    17,    38,    39,   233,
   234,    42,    24,    27,     7,   239,   240,    42,    29,    30,
    31,    32,    33,    34,    41,   249,    37,     7,    39,    38,
    33,    34,   256,   257,    37,   259,    39,    38,     7,    41,
   262,   265,   266,    41,   268,    41,     7,    41,   272,     7,
    31,    32,    33,    34,   276,   277,    37,    41,    39,     7,
   284,     7,   286,   287,    29,    30,    31,    32,    33,    34,
   294,   295,    37,     7,    39,    15,   300,   301,     5,     5,
   205,    41,    41,    24,    38,   309,   310,     7,    41,     7,
    41,   315,   316,     3,     4,     5,     7,    41,     7,   323,
   324,     7,    12,    13,   328,    15,     7,     7,     7,     7,
    20,    21,    22,   335,   338,     7,   340,   339,     5,     7,
   344,    31,     5,   347,    41,    35,   350,     7,     7,    39,
   352,    41,    42,     7,     7,   359,   360,     7,     7,   363,
     7,     7,     7,     7,   368,   369,     7,     7,     7,     7,
   374,   276,   277,     7,     5,    27,   380,   381,     7,     5,
     7,     5,   386,    41,     7,     7,    41,   391,     7,     7,
     7,     7,     7,     7,     7,   399,     7,     7,   402,     7,
     5,     7,    27,   407,   408,     7,     7,    27,   410,     5,
   414,    41,     7,   417,     7,     7,     7,   421,     7,   423,
     7,     7,     3,     4,     5,     6,     5,     8,   432,    10,
    11,    12,    13,    14,    15,   439,     7,     7,     7,    20,
    21,    22,    23,   447,     7,    26,     7,   352,     7,    27,
    31,     7,     7,     7,    35,     7,   460,     0,    39,   463,
     0,    42,   466,    70,   468,    -1,   470,   471,   472,    -1,
    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,   482,    -1,
    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
    11,    12,    13,    14,    15,   509,    -1,   511,    -1,    20,
    21,    22,    23,   517,   518,    26,   520,    -1,    -1,    -1,
    31,   525,   526,   527,    35,   529,    -1,    -1,    39,    -1,
    -1,    42,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,
    -1,    -1,    -1,   547,    -1,    -1,    -1,   551,   552,    -1,
   554,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
   564,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,    -1,    -1,    42,     3,     4,     5,     6,    -1,     8,
    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
    -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
    39,     3,     4,    42,     6,    -1,     8,    -1,    10,    11,
    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,
    22,    23,    -1,    -1,    26,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    41,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    41,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    41,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    31,    -1,    16,    17,    35,    19,
    -1,    38,    39,    -1,    -1,    42,     3,     4,     5,    29,
    30,    31,    32,    33,    34,    12,    13,    37,    15,    39,
    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,     5,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,    -1,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    31,
    -1,    -1,    -1,    35,    -1,    12,    13,    39,    15,    -1,
    42,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,     3,     4,    -1,    31,    -1,    -1,    -1,    35,    -1,
    12,    13,    39,    15,    -1,    42,    -1,    -1,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
     5,    -1,    -1,    35,    -1,    -1,    -1,    39,    -1,    -1,
    42,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
     5,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
    -1,     5,    37,    -1,    39,     9,    41,    -1,    -1,    -1,
    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
    34,    -1,     5,    37,    -1,    39,     9,    -1,    -1,    -1,
    -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
    33,    34,     5,    -1,    37,    -1,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
    33,    34,     5,    -1,    37,    -1,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
    33,    34,    -1,     5,    37,    -1,    39,     9,    -1,    -1,
    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
    32,    33,    34,    -1,     5,    37,    -1,    39,     9,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    38,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    38,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,     5,    -1,    37,    -1,    39,    -1,
    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,    -1,    -1,    37,    -1,    39,    16,
    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
    37,    -1,    39
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
#line 515 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 2:
#line 516 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 3:
#line 519 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 4:
#line 520 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 5:
#line 522 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 6:
#line 523 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 7:
#line 525 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 8:
#line 526 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 9:
#line 528 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 10:
#line 529 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 11:
#line 531 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 12:
#line 532 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 13:
#line 534 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 14:
#line 535 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 15:
#line 537 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 16:
#line 538 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 17:
#line 540 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 18:
#line 541 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 19:
#line 543 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 20:
#line 544 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 21:
#line 546 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 22:
#line 547 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 23:
#line 549 "parser.y"
{ yyval.uExpr = createUnExpr(eNot, yyvsp[0].uExpr); ;
    break;}
case 24:
#line 551 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 25:
#line 552 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 26:
#line 554 "parser.y"
{ yyval.uExpr = createUnExpr(eUMinus, yyvsp[0].uExpr); ;
    break;}
case 27:
#line 556 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 28:
#line 557 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 29:
#line 558 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 30:
#line 559 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 31:
#line 561 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-3].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 32:
#line 562 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 33:
#line 563 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 34:
#line 564 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-5].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 35:
#line 566 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 36:
#line 567 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 37:
#line 568 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 38:
#line 569 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 39:
#line 571 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 40:
#line 572 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 41:
#line 574 "parser.y"
{ yyval.uExpr = createIntExpr(yyvsp[0].uInt); ;
    break;}
case 42:
#line 575 "parser.y"
{ yyval.uExpr = createStrExpr(yyvsp[0].uString); ;
    break;}
case 43:
#line 576 "parser.y"
{ yyval.uExpr = createNilExpr(); ;
    break;}
case 44:
#line 577 "parser.y"
{ yyval.uExpr = createBoolExpr(1); ;
    break;}
case 45:
#line 578 "parser.y"
{ yyval.uExpr = createBoolExpr(0); ;
    break;}
case 46:
#line 580 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-4].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 47:
#line 581 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 48:
#line 582 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 49:
#line 583 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 50:
#line 584 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 51:
#line 586 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 52:
#line 587 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 53:
#line 588 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 54:
#line 589 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-8].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 55:
#line 590 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 56:
#line 593 "parser.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId); ;
    break;}
case 57:
#line 594 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-2].uId, NULL); ;
    break;}
case 58:
#line 595 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 59:
#line 596 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 60:
#line 597 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 61:
#line 598 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 62:
#line 599 "parser.y"
{ yyval.uExpr = createSelfExpr(); ;
    break;}
case 63:
#line 601 "parser.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 64:
#line 602 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 65:
#line 603 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 66:
#line 604 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 67:
#line 605 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 68:
#line 608 "parser.y"
{ yyval.uExprSeq = createExprSeq(yyvsp[0].uExpr); ;
    break;}
case 69:
#line 609 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-2].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 70:
#line 610 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-3].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 71:
#line 613 "parser.y"
{ yyval.uStmt = createStmt(eExpr, yyvsp[0].uExpr, NULL); ;
    break;}
case 72:
#line 614 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 73:
#line 615 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 74:
#line 616 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 75:
#line 617 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 76:
#line 618 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 77:
#line 619 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 78:
#line 620 "parser.y"
{ yyval.uStmt = createReturnStmt(yyvsp[0].uExpr); ;
    break;}
case 79:
#line 621 "parser.y"
{ yyval.uStmt = createReturnStmt(NULL); ;
    break;}
case 80:
#line 625 "parser.y"
{ yyval.uStmtSeq = NULL; ;
    break;}
case 81:
#line 626 "parser.y"
{ yyval.uStmtSeq = yyvsp[0].uStmtSeq; ;
    break;}
case 82:
#line 629 "parser.y"
{ yyval.uStmtSeq = createStmtSeq(yyvsp[0].uStmt); ;
    break;}
case 83:
#line 630 "parser.y"
{ yyval.uStmtSeq = addStmtToSeq(yyvsp[-2].uStmtSeq, yyvsp[0].uStmt); ;
    break;}
case 84:
#line 631 "parser.y"
{ yyval.uStmtSeq = yyvsp[-1].uStmtSeq; ;
    break;}
case 85:
#line 634 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 86:
#line 635 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 87:
#line 636 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 88:
#line 637 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 89:
#line 638 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 90:
#line 639 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 91:
#line 640 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 92:
#line 641 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 93:
#line 642 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 94:
#line 643 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq); ;
    break;}
case 95:
#line 646 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(NULL); ;
    break;}
case 96:
#line 647 "parser.y"
{ yyval.uMethodDefParamSeq = yyvsp[0].uMethodDefParamSeq;;
    break;}
case 97:
#line 650 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(yyvsp[0].uMethodDefParam); ;
    break;}
case 98:
#line 651 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-3].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 99:
#line 652 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-2].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 100:
#line 655 "parser.y"
{ yyval.uMethodDefParam = createMethodDefParam(yyvsp[0].uId); ;
    break;}
case 101:
#line 658 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 102:
#line 659 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 103:
#line 660 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 104:
#line 661 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 105:
#line 663 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 106:
#line 664 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 107:
#line 665 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 108:
#line 666 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 109:
#line 668 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 110:
#line 669 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 111:
#line 670 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 112:
#line 671 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 113:
#line 674 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 114:
#line 675 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 115:
#line 676 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 116:
#line 677 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 117:
#line 680 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 118:
#line 681 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 119:
#line 682 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 120:
#line 683 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 121:
#line 685 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 122:
#line 686 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 123:
#line 687 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 124:
#line 688 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 125:
#line 690 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 126:
#line 691 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 127:
#line 692 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 128:
#line 693 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 129:
#line 696 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 130:
#line 697 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 131:
#line 698 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 132:
#line 699 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 133:
#line 703 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 134:
#line 704 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 135:
#line 705 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 136:
#line 706 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 137:
#line 708 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 138:
#line 709 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 139:
#line 712 "parser.y"
{ yyval.uElsifSeq = NULL ;
    break;}
case 140:
#line 713 "parser.y"
{ yyval.uElsifSeq = yyvsp[0].uElsifSeq ;
    break;}
case 141:
#line 716 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 142:
#line 717 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-4].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 143:
#line 719 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 144:
#line 720 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 145:
#line 721 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 146:
#line 723 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 147:
#line 724 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 148:
#line 725 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 149:
#line 727 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 150:
#line 728 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 151:
#line 729 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 152:
#line 730 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 153:
#line 732 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 154:
#line 733 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 155:
#line 734 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 156:
#line 735 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-7].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 157:
#line 738 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 158:
#line 739 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 159:
#line 741 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 160:
#line 742 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 161:
#line 743 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 162:
#line 745 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 163:
#line 746 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 164:
#line 747 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 165:
#line 749 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 166:
#line 750 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 167:
#line 751 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 168:
#line 752 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 169:
#line 754 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 170:
#line 755 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 171:
#line 756 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 172:
#line 757 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 173:
#line 758 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 174:
#line 759 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 175:
#line 760 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-9].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 176:
#line 763 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 177:
#line 764 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 178:
#line 766 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 179:
#line 767 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 180:
#line 768 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 181:
#line 770 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 182:
#line 771 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 183:
#line 772 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 184:
#line 774 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 185:
#line 775 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 186:
#line 776 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 187:
#line 777 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 188:
#line 779 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 189:
#line 780 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 190:
#line 781 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 191:
#line 782 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 192:
#line 783 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-8].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 193:
#line 784 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 194:
#line 785 "parser.y"
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
#line 788 "parser.y"

void yyerror(const char *s)
{
    printf("%s !",s);
}

