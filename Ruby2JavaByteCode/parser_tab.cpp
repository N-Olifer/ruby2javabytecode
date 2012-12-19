
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INT	258
#define	STRING	259
#define	EOL	260
#define	DEF	261
#define	DEF_STATIC	262
#define	END	263
#define	WHILE	264
#define	DO	265
#define	UNTIL	266
#define	CLASS	267
#define	SELF	268
#define	SUPER	269
#define	RETURN	270
#define	ID	271
#define	IDFIELD	272
#define	ID_STATIC_FIELD	273
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

struct ExprNode* createFieldAccExpr(struct ExprNode* left, char* idStr, bool isStatic)
{
	struct ExprNode* result = (struct ExprNode*)malloc(sizeof(struct ExprNode));
	
	result->type = eFieldAcc;
	result->left = left;
	result->list = NULL;
	result->right = NULL;
	result->next = NULL;
	result->id = idStr;
	result->str = NULL;
	
	result->isStatic = isStatic;
	
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

struct StmtNode* createMethodDefStmt(char* id, struct MethodDefParamSeqNode* params, struct StmtSeqNode* body, bool isStatic)
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
	
	result->isStatic = isStatic;

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


#line 455 "parser.y"
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



#define	YYFINAL		617
#define	YYFLAG		-32768
#define	YYNTBASE	47

#define YYTRANSLATE(x) ((unsigned)(x) <= 287 ? yytranslate[x] : 64)

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
     0,     2,     5,     9,    14,    19,    23,    28,    32,    37,
    41,    45,    50,    54,    59,    63,    68,    72,    77,    81,
    86,    90,    95,    98,   102,   107,   110,   114,   119,   124,
   130,   135,   141,   147,   154,   159,   165,   170,   174,   177,
   181,   183,   185,   187,   189,   191,   197,   204,   212,   221,
   229,   236,   244,   253,   263,   272,   274,   276,   278,   282,
   287,   293,   300,   306,   308,   312,   317,   323,   330,   336,
   338,   342,   347,   349,   351,   353,   355,   357,   359,   361,
   364,   366,   367,   369,   371,   375,   378,   388,   399,   408,
   418,   426,   434,   443,   452,   462,   469,   479,   490,   499,
   509,   517,   525,   534,   543,   553,   560,   561,   563,   565,
   570,   574,   576,   583,   589,   597,   604,   612,   619,   628,
   636,   647,   657,   667,   676,   686,   695,   704,   712,   719,
   725,   733,   740,   748,   755,   764,   772,   783,   793,   803,
   812,   822,   831,   840,   848,   858,   867,   876,   884,   891,
   897,   898,   900,   905,   911,   917,   923,   930,   937,   944,
   952,   958,   965,   972,   980,   987,   995,  1003,  1012,  1019,
  1028,  1036,  1044,  1053,  1063,  1073,  1084,  1092,  1101,  1110,
  1120,  1130,  1141,  1152,  1163,  1175,  1187,  1200,  1206,  1214,
  1221,  1228,  1236,  1245,  1254,  1264,  1271,  1279,  1287,  1296,
  1305,  1315,  1325,  1335,  1346,  1357
};

static const short yyrhs[] = {    51,
     0,     5,    51,     0,    48,    35,    48,     0,    48,    35,
     5,    48,     0,    48,    34,     5,    48,     0,    48,    34,
    48,     0,    48,    36,     5,    48,     0,    48,    36,    48,
     0,    48,    37,     5,    48,     0,    48,    37,    48,     0,
    48,    32,    48,     0,    48,    32,     5,    48,     0,    48,
    33,    48,     0,    48,    33,     5,    48,     0,    48,    19,
    48,     0,    48,    19,     5,    48,     0,    48,    20,    48,
     0,    48,    20,     5,    48,     0,    48,    21,    48,     0,
    48,    21,     5,    48,     0,    48,    22,    48,     0,    48,
    22,     5,    48,     0,    38,    48,     0,    48,    31,    48,
     0,    48,    31,     5,    48,     0,    34,    48,     0,    45,
    48,    44,     0,    45,    48,     5,    44,     0,    45,     5,
    48,    44,     0,    45,     5,    48,     5,    44,     0,    48,
    42,    48,    41,     0,    48,    42,    48,     5,    41,     0,
    48,    42,     5,    48,    41,     0,    48,    42,     5,    48,
     5,    41,     0,    42,     5,    49,    41,     0,    42,     5,
    49,     5,    41,     0,    42,    49,     5,    41,     0,    42,
    49,    41,     0,    42,    41,     0,    42,     5,    41,     0,
     3,     0,     4,     0,    23,     0,    24,     0,    25,     0,
    48,    40,    16,    45,    44,     0,    48,    40,    16,    45,
    49,    44,     0,    48,    40,    16,    45,     5,    49,    44,
     0,    48,    40,    16,    45,     5,    49,     5,    44,     0,
    48,    40,    16,    45,    49,     5,    44,     0,    48,    40,
     5,    16,    45,    44,     0,    48,    40,     5,    16,    45,
    49,    44,     0,    48,    40,     5,    16,    45,     5,    49,
    44,     0,    48,    40,     5,    16,    45,     5,    49,     5,
    44,     0,    48,    40,     5,    16,    45,    49,     5,    44,
     0,    16,     0,    17,     0,    18,     0,    16,    45,    44,
     0,    16,    45,    49,    44,     0,    16,    45,     5,    49,
    44,     0,    16,    45,     5,    49,     5,    44,     0,    16,
    45,    49,     5,    44,     0,    13,     0,    14,    45,    44,
     0,    14,    45,    49,    44,     0,    14,    45,     5,    49,
    44,     0,    14,    45,     5,    49,     5,    44,     0,    14,
    45,    49,     5,    44,     0,    48,     0,    49,    46,    48,
     0,    49,    46,     5,    48,     0,    48,     0,    53,     0,
    59,     0,    57,     0,    58,     0,    62,     0,    63,     0,
    15,    48,     0,    15,     0,     0,    52,     0,    50,     0,
    52,     5,    50,     0,    52,     5,     0,     6,     5,    16,
    45,    54,     5,    44,    51,     8,     0,     6,     5,    16,
    45,    54,     5,    44,     5,    51,     8,     0,     6,     5,
    16,    45,    54,    44,    51,     8,     0,     6,     5,    16,
    45,    54,    44,     5,    51,     8,     0,     6,     5,    16,
    54,     5,    51,     8,     0,     6,    16,    45,    54,    44,
    51,     8,     0,     6,    16,    45,    54,    44,     5,    51,
     8,     0,     6,    16,    45,    54,     5,    44,    51,     8,
     0,     6,    16,    45,    54,     5,    44,     5,    51,     8,
     0,     6,    16,    54,     5,    51,     8,     0,     7,     5,
    16,    45,    54,     5,    44,    51,     8,     0,     7,     5,
    16,    45,    54,     5,    44,     5,    51,     8,     0,     7,
     5,    16,    45,    54,    44,    51,     8,     0,     7,     5,
    16,    45,    54,    44,     5,    51,     8,     0,     7,     5,
    16,    54,     5,    51,     8,     0,     7,    16,    45,    54,
    44,    51,     8,     0,     7,    16,    45,    54,    44,     5,
    51,     8,     0,     7,    16,    45,    54,     5,    44,    51,
     8,     0,     7,    16,    45,    54,     5,    44,     5,    51,
     8,     0,     7,    16,    54,     5,    51,     8,     0,     0,
    55,     0,    56,     0,    54,    46,     5,    56,     0,    54,
    46,    56,     0,    16,     0,     9,     5,    48,    10,    51,
     8,     0,     9,    48,    10,    51,     8,     0,     9,     5,
    48,    10,     5,    51,     8,     0,     9,    48,    10,     5,
    51,     8,     0,     9,     5,    48,     5,    10,    51,     8,
     0,     9,    48,     5,    10,    51,     8,     0,     9,     5,
    48,     5,    10,     5,    51,     8,     0,     9,    48,     5,
    10,     5,    51,     8,     0,     9,     5,    45,     5,    48,
     5,    44,     5,    51,     8,     0,     9,     5,    45,     5,
    48,    44,     5,    51,     8,     0,     9,     5,    45,    48,
     5,    44,     5,    51,     8,     0,     9,     5,    45,    48,
    44,     5,    51,     8,     0,     9,    45,     5,    48,     5,
    44,     5,    51,     8,     0,     9,    45,     5,    48,    44,
     5,    51,     8,     0,     9,    45,    48,     5,    44,     5,
    51,     8,     0,     9,    45,    48,    44,     5,    51,     8,
     0,    11,     5,    48,    10,    51,     8,     0,    11,    48,
    10,    51,     8,     0,    11,     5,    48,    10,     5,    51,
     8,     0,    11,    48,    10,     5,    51,     8,     0,    11,
     5,    48,     5,    10,    51,     8,     0,    11,    48,     5,
    10,    51,     8,     0,    11,     5,    48,     5,    10,     5,
    51,     8,     0,    11,    48,     5,    10,     5,    51,     8,
     0,    11,     5,    45,     5,    48,     5,    44,     5,    51,
     8,     0,    11,     5,    45,     5,    48,    44,     5,    51,
     8,     0,    11,     5,    45,    48,     5,    44,     5,    51,
     8,     0,    11,     5,    45,    48,    44,     5,    51,     8,
     0,    11,    45,     5,    48,     5,    44,     5,    51,     8,
     0,    11,    45,     5,    48,    44,     5,    51,     8,     0,
    11,    45,    48,     5,    44,     5,    51,     8,     0,    11,
    45,    48,    44,     5,    51,     8,     0,    12,     5,    16,
    32,     5,    16,     5,    51,     8,     0,    12,     5,    16,
    32,    16,     5,    51,     8,     0,    12,    16,    32,     5,
    16,     5,    51,     8,     0,    12,    16,    32,    16,     5,
    51,     8,     0,    12,     5,    16,     5,    51,     8,     0,
    12,    16,     5,    51,     8,     0,     0,    61,     0,    27,
    48,    30,    51,     0,    61,    27,    48,    30,    51,     0,
    27,     5,    48,    30,    51,     0,    27,    48,     5,    30,
    51,     0,    27,     5,    48,     5,    30,    51,     0,    61,
    27,     5,    48,    30,    51,     0,    61,    27,    48,     5,
    30,    51,     0,    61,    27,     5,    48,     5,    30,    51,
     0,    27,    48,    30,     5,    51,     0,    27,    48,     5,
    30,     5,    51,     0,    27,     5,    48,    30,     5,    51,
     0,    27,     5,    48,     5,    30,     5,    51,     0,    61,
    27,    48,    30,     5,    51,     0,    61,    27,    48,     5,
    30,     5,    51,     0,    61,    27,     5,    48,    30,     5,
    51,     0,    61,    27,     5,    48,     5,    30,     5,    51,
     0,    26,    48,    30,    51,    60,     8,     0,    26,    48,
    30,    51,    60,    28,    51,     8,     0,    26,     5,    48,
    30,    51,    60,     8,     0,    26,    48,     5,    30,    51,
    60,     8,     0,    26,     5,    48,     5,    30,    51,    60,
     8,     0,    26,     5,    48,    30,    51,    60,    28,    51,
     8,     0,    26,    48,     5,    30,    51,    60,    28,    51,
     8,     0,    26,     5,    48,     5,    30,    51,    60,    28,
    51,     8,     0,    26,    48,    30,     5,    51,    60,     8,
     0,    26,     5,    48,    30,     5,    51,    60,     8,     0,
    26,    48,     5,    30,     5,    51,    60,     8,     0,    26,
     5,    48,     5,    30,     5,    51,    60,     8,     0,    26,
    48,    30,    51,    60,    28,     5,    51,     8,     0,    26,
    48,    30,     5,    51,    60,    28,     5,    51,     8,     0,
    26,    48,     5,    30,    51,    60,    28,     5,    51,     8,
     0,    26,     5,    48,    30,    51,    60,    28,     5,    51,
     8,     0,    26,     5,    48,     5,    30,    51,    60,    28,
     5,    51,     8,     0,    26,     5,    48,    30,     5,    51,
    60,    28,     5,    51,     8,     0,    26,     5,    48,     5,
    30,     5,    51,    60,    28,     5,    51,     8,     0,    29,
    48,    30,    51,     8,     0,    29,    48,    30,    51,    28,
    51,     8,     0,    29,     5,    48,    30,    51,     8,     0,
    29,    48,     5,    30,    51,     8,     0,    29,     5,    48,
     5,    30,    51,     8,     0,    29,     5,    48,    30,    51,
    28,    51,     8,     0,    29,    48,     5,    30,    51,    28,
    51,     8,     0,    29,     5,    48,     5,    30,    51,    28,
    51,     8,     0,    29,    48,    30,     5,    51,     8,     0,
    29,    48,     5,    30,     5,    51,     8,     0,    29,     5,
    48,    30,     5,    51,     8,     0,    29,     5,    48,     5,
    30,     5,    51,     8,     0,    29,    48,    30,    51,    28,
     5,    51,     8,     0,    29,    48,    30,     5,    51,    28,
     5,    51,     8,     0,    29,    48,     5,    30,    51,    28,
     5,    51,     8,     0,    29,     5,    48,    30,    51,    28,
     5,    51,     8,     0,    29,    48,     5,    30,     5,    51,
    28,     5,    51,     8,     0,    29,     5,    48,    30,     5,
    51,    28,     5,    51,     8,     0,    29,     5,    48,     5,
    30,     5,    51,    28,     5,    51,     8,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   538,   539,   542,   543,   545,   546,   548,   549,   551,   552,
   554,   555,   557,   558,   560,   561,   563,   564,   566,   567,
   569,   570,   572,   574,   575,   577,   579,   580,   581,   582,
   584,   585,   586,   587,   589,   590,   591,   592,   594,   595,
   597,   598,   599,   600,   601,   603,   604,   605,   606,   607,
   609,   610,   611,   612,   613,   616,   617,   618,   619,   620,
   621,   622,   623,   624,   626,   627,   628,   629,   630,   633,
   634,   635,   638,   639,   640,   641,   642,   643,   644,   645,
   646,   650,   651,   654,   655,   656,   659,   660,   661,   662,
   663,   664,   665,   666,   667,   668,   670,   671,   672,   673,
   674,   675,   676,   677,   678,   679,   682,   683,   686,   687,
   688,   691,   694,   695,   696,   697,   699,   700,   701,   702,
   704,   705,   706,   707,   710,   711,   712,   713,   716,   717,
   718,   719,   721,   722,   723,   724,   726,   727,   728,   729,
   732,   733,   734,   735,   739,   740,   741,   742,   744,   745,
   748,   749,   752,   753,   755,   756,   757,   759,   760,   761,
   763,   764,   765,   766,   768,   769,   770,   771,   774,   775,
   777,   778,   779,   781,   782,   783,   785,   786,   787,   788,
   790,   791,   792,   793,   794,   795,   796,   799,   800,   802,
   803,   804,   806,   807,   808,   810,   811,   812,   813,   815,
   816,   817,   818,   819,   820,   821
};

static const char * const yytname[] = {   "$","error","$undefined.","INT","STRING",
"EOL","DEF","DEF_STATIC","END","WHILE","DO","UNTIL","CLASS","SELF","SUPER","RETURN",
"ID","IDFIELD","ID_STATIC_FIELD","EQUAL","NOTEQUAL","OR","AND","NIL","TRUE",
"FALSE","IF","ELSIF","ELSE","UNLESS","THEN","'='","'<'","'>'","'-'","'+'","'*'",
"'/'","'!'","UMINUS","'.'","']'","'['","UBR","')'","'('","','","program","expr",
"expr_seqE","stmt","stmt_seq","stmt_seqE","method_def","method_def_param_seq",
"method_def_param_seqE","method_def_param","while_stmt","until_stmt","class_def",
"elsif_seq","elsif_seqE","if_stmt","unless_stmt",""
};
#endif

static const short yyr1[] = {     0,
    47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
    49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
    50,    51,    51,    52,    52,    52,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
    55,    56,    57,    57,    57,    57,    57,    57,    57,    57,
    57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
    58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
    58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
    60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
    61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
    62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
    62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
    63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
    63,    63,    63,    63,    63,    63
};

static const short yyr2[] = {     0,
     1,     2,     3,     4,     4,     3,     4,     3,     4,     3,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     2,     3,     4,     2,     3,     4,     4,     5,
     4,     5,     5,     6,     4,     5,     4,     3,     2,     3,
     1,     1,     1,     1,     1,     5,     6,     7,     8,     7,
     6,     7,     8,     9,     8,     1,     1,     1,     3,     4,
     5,     6,     5,     1,     3,     4,     5,     6,     5,     1,
     3,     4,     1,     1,     1,     1,     1,     1,     1,     2,
     1,     0,     1,     1,     3,     2,     9,    10,     8,     9,
     7,     7,     8,     8,     9,     6,     9,    10,     8,     9,
     7,     7,     8,     8,     9,     6,     0,     1,     1,     4,
     3,     1,     6,     5,     7,     6,     7,     6,     8,     7,
    10,     9,     9,     8,     9,     8,     8,     7,     6,     5,
     7,     6,     7,     6,     8,     7,    10,     9,     9,     8,
     9,     8,     8,     7,     9,     8,     8,     7,     6,     5,
     0,     1,     4,     5,     5,     5,     6,     6,     6,     7,
     5,     6,     6,     7,     6,     7,     7,     8,     6,     8,
     7,     7,     8,     9,     9,    10,     7,     8,     8,     9,
     9,    10,    10,    10,    11,    11,    12,     5,     7,     6,
     6,     7,     8,     8,     9,     6,     7,     7,     8,     8,
     9,     9,     9,    10,    10,    11
};

static const short yydefact[] = {    82,
    41,    42,    82,     0,     0,     0,     0,     0,    64,     0,
    81,    56,    57,    58,    43,    44,    45,     0,     0,     0,
     0,     0,     0,    73,    84,     1,    83,    74,    76,    77,
    75,    78,    79,     2,     0,   107,     0,   107,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
     0,     0,     0,    26,    23,     0,    39,    70,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    86,   107,   112,   107,     0,   108,
   109,   107,   107,     0,     0,     0,     0,     0,     0,    82,
     0,     0,     0,     0,     0,    82,     0,    82,     0,     0,
    65,     0,     0,    59,     0,     0,     0,    82,     0,     0,
    82,    40,     0,     0,    38,     0,     0,     0,    27,     0,
    15,     0,    17,     0,    19,     0,    21,     0,    24,     0,
    11,     0,    13,     0,     6,     0,     3,     0,     8,     0,
    10,     0,     0,     0,     0,    85,   107,     0,     0,    82,
     0,   107,     0,     0,    82,     0,     0,     0,    82,     0,
     0,    27,    82,    82,     0,     0,     0,     0,    82,     0,
     0,    27,    82,    82,     0,    82,     0,     0,     0,     0,
     0,     0,    66,     0,     0,    60,     0,    82,    82,    82,
   151,     0,    82,    82,    82,     0,     0,    35,    37,     0,
    71,     0,    29,    28,    16,    18,    20,    22,    25,    12,
    14,     5,     4,     7,     9,     0,     0,     0,     0,    31,
     0,    82,     0,    82,     0,     0,   111,     0,    82,     0,
    82,     0,     0,     0,    27,    82,    82,     0,     0,    29,
    28,    82,    82,     0,     0,   114,     0,     0,    27,    82,
    82,     0,     0,    29,    28,    82,    82,     0,     0,   130,
     0,     0,     0,   150,     0,    82,     0,    67,    69,     0,
    61,    63,    82,    82,   151,    82,   151,   151,     0,     0,
   152,    82,    82,     0,    82,     0,     0,   188,    82,    36,
    72,    30,     0,     0,    46,     0,     0,    33,    32,     0,
    82,     0,    82,    82,     0,    96,   110,     0,    82,     0,
    82,    82,     0,   106,     0,    29,    28,    82,    82,     0,
     0,   113,    30,    82,    82,     0,     0,   118,   116,     0,
    29,    28,    82,    82,     0,     0,   129,    30,    82,    82,
     0,     0,   134,   132,   149,     0,    82,    82,     0,    68,
    62,    82,   151,   151,     0,   151,     0,     0,     0,     0,
   169,    82,     0,    82,     0,     0,   190,    82,     0,   191,
    82,   196,     0,    82,     0,     0,    51,     0,     0,     0,
    47,    34,    82,    82,     0,    91,    82,     0,     0,    92,
    82,    82,     0,   101,    82,     0,     0,   102,    30,    82,
    82,     0,     0,   117,   115,    82,     0,     0,   128,   120,
    30,    82,    82,     0,     0,   133,   131,    82,     0,     0,
   144,   136,    82,     0,     0,   148,   151,     0,     0,   171,
    82,     0,   172,    82,   177,     0,     0,     0,    82,    82,
     0,     0,     0,     0,   192,    82,   198,     0,    82,     0,
   197,     0,    82,     0,    82,     0,   189,     0,     0,    52,
     0,    48,    50,    82,     0,     0,    89,     0,    94,    93,
    82,     0,     0,    99,     0,   104,   103,    82,     0,     0,
   124,   119,     0,   126,   127,    82,     0,     0,   140,   135,
     0,   142,   143,     0,   146,   147,     0,   173,    82,   178,
     0,    82,     0,   179,    82,     0,    82,     0,    82,    82,
    82,   153,     0,   170,     0,     0,    82,   199,     0,     0,
    82,     0,   193,    82,     0,   194,     0,   200,     0,    53,
    55,    49,     0,    87,    90,    95,     0,    97,   100,   105,
     0,   122,   123,   125,     0,   138,   139,   141,   145,   180,
     0,    82,     0,    82,     0,   174,     0,   175,     0,    82,
    82,   155,    82,   156,   161,   181,     0,    82,    82,    82,
   154,    82,   195,     0,   203,     0,   202,   201,    54,    88,
    98,   121,   137,    82,     0,   176,     0,   184,   183,   182,
    82,   157,   163,   162,    82,    82,   158,    82,   159,   165,
     0,   205,   204,     0,   185,   186,   164,    82,   160,   167,
   166,   206,   187,   168,     0,     0,     0
};

static const short yydefgoto[] = {   615,
    24,    59,    25,    26,    27,    28,    79,    80,    81,    29,
    30,    31,   280,   281,    32,    33
};

static const short yypact[] = {   530,
-32768,-32768,  2266,    11,    18,  2437,  2460,   195,-32768,   -34,
  3032,   -19,-32768,-32768,-32768,-32768,-32768,  2483,  2506,  3032,
  3032,  2302,  2529,  3708,-32768,-32768,    27,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    78,    -9,    94,    -2,  3055,  2552,
   292,  3078,  2575,  3402,    97,     3,  2345,  3708,  2368,  3032,
   458,  3032,  3426,    61,    61,  2598,-32768,  3708,     4,  3032,
   224,  2641,  2664,  2687,  2710,  2733,  2756,  2779,  2802,  2825,
  2848,  2871,   207,  2894,  2266,    13,-32768,   101,     7,-32768,
-32768,    15,   101,    10,  2917,  3459,  3032,  3105,    90,   595,
  2940,  3492,  3032,  3138,    99,   638,   102,  2266,   208,  3032,
-32768,     8,  3032,-32768,    28,  3516,   115,   681,  3540,   142,
   724,-32768,    35,    79,-32768,  2963,  3171,    82,-32768,  3032,
   306,  3032,   306,  3032,   490,  3032,  3727,  3032,  3708,  3032,
   254,  3032,   254,  3032,   -12,  3032,   -12,  3032,    61,  3032,
    61,   106,   131,  3032,  3564,-32768,   101,    32,    39,  2266,
   226,   101,    42,    52,  2266,  3032,  3204,   171,   767,  3237,
   135,-32768,   810,  2266,   175,  3032,  3270,   178,   853,  3303,
   165,-32768,   896,  2266,   209,  2266,   233,   214,   216,   230,
    70,   192,-32768,    84,   193,-32768,   211,   939,   982,  2266,
   223,   221,  1025,  1068,  2266,    83,   228,-32768,-32768,  3032,
  3708,   218,-32768,-32768,   306,   306,   490,  3727,  3708,   254,
   254,   -12,   -12,    61,    61,   220,  2391,  3588,   231,-32768,
    92,  2266,   232,  1111,   244,   101,-32768,   113,  2266,   237,
  1154,   259,  3336,   239,-32768,  1197,  2266,   266,   240,-32768,
-32768,  2266,  2266,   267,   269,-32768,  3369,   241,-32768,  1240,
  2266,   279,   251,-32768,-32768,  2266,  2266,   291,   295,-32768,
   296,   289,   302,-32768,   312,  2266,   274,-32768,-32768,   275,
-32768,-32768,  1283,  2266,   223,  2266,   223,   223,  2986,    96,
   293,  1326,  2266,   104,  2266,   140,   146,-32768,  1369,-32768,
  3708,-32768,  2414,  3032,-32768,   136,   294,-32768,-32768,   303,
  1412,   325,  1455,  2266,   342,-32768,-32768,   307,  1498,   344,
  1541,  2266,   345,-32768,   310,-32768,-32768,  2266,  2266,   347,
   348,-32768,-32768,  2266,  2266,   349,   352,-32768,-32768,   319,
-32768,-32768,  2266,  2266,   356,   358,-32768,-32768,  2266,  2266,
   359,   361,-32768,-32768,-32768,   365,  2266,  2266,   364,-32768,
-32768,  2266,   223,   223,   150,   223,   156,   161,  3032,  3612,
-32768,  1584,  3009,  2266,   167,   169,-32768,  1627,   186,-32768,
  1670,-32768,   368,  2266,   366,  3032,-32768,   157,   158,   332,
-32768,-32768,  1713,  2266,   369,-32768,  2266,   370,   371,-32768,
  1756,  2266,   374,-32768,  2266,   375,   377,-32768,-32768,  2266,
  2266,   382,   383,-32768,-32768,  2266,   385,   386,-32768,-32768,
-32768,  2266,  2266,   387,   388,-32768,-32768,  2266,   391,   392,
-32768,-32768,  2266,   393,   394,-32768,   223,   190,   197,-32768,
  1799,   396,-32768,  1842,-32768,   400,  3636,   376,  1885,  2266,
   399,  3032,  3660,   199,-32768,  2266,-32768,   403,  2266,   404,
-32768,   406,  2266,   405,  2266,   408,-32768,   162,   373,-32768,
   378,-32768,-32768,  2266,   410,   411,-32768,   413,-32768,-32768,
  2266,   415,   416,-32768,   417,-32768,-32768,  2266,   418,   419,
-32768,-32768,   421,-32768,-32768,  2266,   422,   424,-32768,-32768,
   425,-32768,-32768,   426,-32768,-32768,   202,-32768,  1928,-32768,
   409,  2266,   427,-32768,  2266,   430,  2266,   412,  1971,  2014,
  2266,-32768,   431,-32768,  3684,   414,  2057,-32768,   435,   437,
  2266,   439,-32768,  2266,   440,-32768,   441,-32768,   407,-32768,
-32768,-32768,   445,-32768,-32768,-32768,   446,-32768,-32768,-32768,
   447,-32768,-32768,-32768,   448,-32768,-32768,-32768,-32768,-32768,
   452,  2266,   450,  2266,   451,-32768,   454,-32768,   456,  2100,
  2266,-32768,  2266,-32768,-32768,-32768,   436,  2143,  2186,  2266,
-32768,  2266,-32768,   457,-32768,   459,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  2266,   462,-32768,   463,-32768,-32768,-32768,
  2266,-32768,-32768,-32768,  2229,  2266,-32768,  2266,-32768,-32768,
   464,-32768,-32768,   465,-32768,-32768,-32768,  2266,-32768,-32768,
-32768,-32768,-32768,-32768,   460,   474,-32768
};

static const short yypgoto[] = {-32768,
    -1,    93,   401,    -3,-32768,-32768,    68,-32768,  -149,-32768,
-32768,-32768,  -274,-32768,-32768,-32768
};


#define	YYLAST		3769


static const short yytable[] = {    34,
   355,   227,   357,   358,    41,    44,    77,    98,   114,    48,
    47,   150,   182,    77,   155,    35,    51,    53,    54,    55,
    58,    61,    37,    71,    72,    49,    36,    73,    77,    74,
    77,    75,   185,    38,    99,    78,   222,    86,    88,   197,
    92,    94,    83,   223,   115,    58,   229,    58,   106,   116,
   109,   183,   151,   116,    58,   151,   230,   147,   117,   152,
   121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
   141,   186,   145,   116,   267,   198,   307,   151,   428,   429,
   116,   432,   224,   157,   151,   160,   165,   151,   270,   167,
   288,   170,   175,    76,   178,   231,   300,   151,    58,   163,
    73,    58,    74,   361,   191,    84,   176,   196,   173,    82,
   289,   367,    97,   268,   201,   116,    77,   308,   205,   199,
   206,   216,   207,   362,   208,   204,   209,   271,   210,   116,
   211,   368,   212,   177,   213,   301,   214,   151,   215,   102,
   380,   105,   218,   148,   189,   149,   225,   370,   113,   153,
   154,   232,   497,   372,   233,   238,   309,   430,   151,   244,
   245,   459,   461,   433,   247,   252,   529,   371,   435,   258,
   259,   194,   261,   373,   445,   217,   447,   431,   241,   381,
   236,   116,   246,   434,   275,   277,   278,   250,   436,   284,
   286,   287,   181,   451,   446,   184,   448,   498,   291,    45,
   460,   462,   116,   116,   500,   530,   518,   116,   255,   550,
    46,   142,   179,   452,   221,    58,   260,   499,   302,   228,
   305,   264,   143,   180,   501,   310,   519,   313,   118,   551,
   226,   265,   320,   321,   266,   269,   272,   262,   326,   327,
   273,    77,    62,    63,    64,    65,   335,   336,   263,   279,
   282,   306,   341,   342,    66,    67,    68,    69,    70,    71,
    72,   292,   349,    73,   293,    74,   314,   119,   290,   353,
   354,   299,   356,   322,   328,   303,   329,   360,   365,   366,
   311,   369,   317,   323,   332,   375,   337,    69,    70,    71,
    72,    58,    58,    73,   338,    74,    89,   385,   343,   388,
   389,    90,   344,   345,   346,   393,   347,   396,   397,   296,
    62,    63,    64,    65,   402,   403,   348,   350,   351,   363,
   407,   408,    66,    67,    68,    69,    70,    71,    72,   414,
   415,    73,   386,    74,   382,   419,   420,    67,    68,    69,
    70,    71,    72,   424,   425,    73,   383,    74,   427,   390,
   391,   394,   398,   399,   404,   405,   409,   437,   441,   410,
   444,   443,   411,   416,   450,   417,   421,   454,   422,   423,
   456,   426,   455,   457,    58,   463,   467,   469,   470,   465,
   466,   474,   476,   468,   477,   378,   379,   472,   473,   481,
   482,   475,   484,   485,   489,   490,   479,   480,   492,   493,
   495,   496,   483,   504,   507,   510,   514,   521,   487,   488,
   524,   523,   526,   554,   491,   528,   531,   534,   535,   494,
   536,   532,   538,   539,   540,   542,   543,   503,   544,   546,
   506,   547,   548,   549,   556,   512,   513,   558,   566,   572,
   515,   560,   520,   569,   573,   522,   575,   577,   578,   525,
   579,   527,   580,   581,   582,   583,   584,   586,   588,   616,
   533,   589,   107,   590,   602,   595,   603,   537,   458,   605,
   606,   612,   613,   617,   541,   146,    62,    63,    64,    65,
     0,     0,   545,     0,     0,     0,     0,   108,    66,    67,
    68,    69,    70,    71,    72,   553,     0,    73,   555,    74,
     0,   557,     0,   559,     0,   562,   564,   565,    62,    63,
     0,    65,     0,   571,     0,     0,     0,   574,     0,     0,
   576,    67,    68,    69,    70,    71,    72,     0,     0,    73,
     0,    74,     1,     2,     3,     4,     5,     0,     6,     0,
     7,     8,     9,    10,    11,    12,    13,    14,   585,     0,
   587,     0,    15,    16,    17,    18,   592,   593,    19,   594,
     0,     0,     0,    20,   597,   599,   600,    21,   601,     0,
     0,    22,     0,     0,    23,     0,     0,     0,     0,     0,
   604,     0,     0,     0,     0,     0,     0,   607,     0,     0,
     0,   609,   610,     0,   611,     0,     0,     1,     2,   164,
     4,     5,     0,     6,   614,     7,     8,     9,    10,    11,
    12,    13,    14,     0,     0,     0,     0,    15,    16,    17,
    18,     0,     0,    19,     0,     0,     0,     0,    20,     0,
     0,     0,    21,     0,     0,     0,    22,     0,     0,    23,
     1,     2,   174,     4,     5,     0,     6,     0,     7,     8,
     9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
    15,    16,    17,    18,     0,     0,    19,     0,     0,     0,
     0,    20,     0,     0,     0,    21,     0,     0,     0,    22,
     0,     0,    23,     1,     2,   190,     4,     5,     0,     6,
     0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
     0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
     0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
     0,     0,    22,     0,     0,    23,     1,     2,   195,     4,
     5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
    13,    14,     0,     0,     0,     0,    15,    16,    17,    18,
     0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
     0,    21,     0,     0,     0,    22,     0,     0,    23,     1,
     2,   237,     4,     5,     0,     6,     0,     7,     8,     9,
    10,    11,    12,    13,    14,     0,     0,     0,     0,    15,
    16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
    20,     0,     0,     0,    21,     0,     0,     0,    22,     0,
     0,    23,     1,     2,   243,     4,     5,     0,     6,     0,
     7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
     0,     0,    15,    16,    17,    18,     0,     0,    19,     0,
     0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
     0,    22,     0,     0,    23,     1,     2,   251,     4,     5,
     0,     6,     0,     7,     8,     9,    10,    11,    12,    13,
    14,     0,     0,     0,     0,    15,    16,    17,    18,     0,
     0,    19,     0,     0,     0,     0,    20,     0,     0,     0,
    21,     0,     0,     0,    22,     0,     0,    23,     1,     2,
   257,     4,     5,     0,     6,     0,     7,     8,     9,    10,
    11,    12,    13,    14,     0,     0,     0,     0,    15,    16,
    17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
     0,     0,     0,    21,     0,     0,     0,    22,     0,     0,
    23,     1,     2,   274,     4,     5,     0,     6,     0,     7,
     8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
     0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
     0,     0,    20,     0,     0,     0,    21,     0,     0,     0,
    22,     0,     0,    23,     1,     2,   276,     4,     5,     0,
     6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
     0,     0,     0,     0,    15,    16,    17,    18,     0,     0,
    19,     0,     0,     0,     0,    20,     0,     0,     0,    21,
     0,     0,     0,    22,     0,     0,    23,     1,     2,   283,
     4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
    12,    13,    14,     0,     0,     0,     0,    15,    16,    17,
    18,     0,     0,    19,     0,     0,     0,     0,    20,     0,
     0,     0,    21,     0,     0,     0,    22,     0,     0,    23,
     1,     2,   285,     4,     5,     0,     6,     0,     7,     8,
     9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
    15,    16,    17,    18,     0,     0,    19,     0,     0,     0,
     0,    20,     0,     0,     0,    21,     0,     0,     0,    22,
     0,     0,    23,     1,     2,   304,     4,     5,     0,     6,
     0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
     0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
     0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
     0,     0,    22,     0,     0,    23,     1,     2,   312,     4,
     5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
    13,    14,     0,     0,     0,     0,    15,    16,    17,    18,
     0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
     0,    21,     0,     0,     0,    22,     0,     0,    23,     1,
     2,   319,     4,     5,     0,     6,     0,     7,     8,     9,
    10,    11,    12,    13,    14,     0,     0,     0,     0,    15,
    16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
    20,     0,     0,     0,    21,     0,     0,     0,    22,     0,
     0,    23,     1,     2,   334,     4,     5,     0,     6,     0,
     7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
     0,     0,    15,    16,    17,    18,     0,     0,    19,     0,
     0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
     0,    22,     0,     0,    23,     1,     2,   352,     4,     5,
     0,     6,     0,     7,     8,     9,    10,    11,    12,    13,
    14,     0,     0,     0,     0,    15,    16,    17,    18,     0,
     0,    19,     0,     0,     0,     0,    20,     0,     0,     0,
    21,     0,     0,     0,    22,     0,     0,    23,     1,     2,
   364,     4,     5,     0,     6,     0,     7,     8,     9,    10,
    11,    12,    13,    14,     0,     0,     0,     0,    15,    16,
    17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
     0,     0,     0,    21,     0,     0,     0,    22,     0,     0,
    23,     1,     2,   374,     4,     5,     0,     6,     0,     7,
     8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
     0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
     0,     0,    20,     0,     0,     0,    21,     0,     0,     0,
    22,     0,     0,    23,     1,     2,   384,     4,     5,     0,
     6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
     0,     0,     0,     0,    15,    16,    17,    18,     0,     0,
    19,     0,     0,     0,     0,    20,     0,     0,     0,    21,
     0,     0,     0,    22,     0,     0,    23,     1,     2,   387,
     4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
    12,    13,    14,     0,     0,     0,     0,    15,    16,    17,
    18,     0,     0,    19,     0,     0,     0,     0,    20,     0,
     0,     0,    21,     0,     0,     0,    22,     0,     0,    23,
     1,     2,   392,     4,     5,     0,     6,     0,     7,     8,
     9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
    15,    16,    17,    18,     0,     0,    19,     0,     0,     0,
     0,    20,     0,     0,     0,    21,     0,     0,     0,    22,
     0,     0,    23,     1,     2,   395,     4,     5,     0,     6,
     0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
     0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
     0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
     0,     0,    22,     0,     0,    23,     1,     2,   440,     4,
     5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
    13,    14,     0,     0,     0,     0,    15,    16,    17,    18,
     0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
     0,    21,     0,     0,     0,    22,     0,     0,    23,     1,
     2,   449,     4,     5,     0,     6,     0,     7,     8,     9,
    10,    11,    12,    13,    14,     0,     0,     0,     0,    15,
    16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
    20,     0,     0,     0,    21,     0,     0,     0,    22,     0,
     0,    23,     1,     2,   453,     4,     5,     0,     6,     0,
     7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
     0,     0,    15,    16,    17,    18,     0,     0,    19,     0,
     0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
     0,    22,     0,     0,    23,     1,     2,   464,     4,     5,
     0,     6,     0,     7,     8,     9,    10,    11,    12,    13,
    14,     0,     0,     0,     0,    15,    16,    17,    18,     0,
     0,    19,     0,     0,     0,     0,    20,     0,     0,     0,
    21,     0,     0,     0,    22,     0,     0,    23,     1,     2,
   471,     4,     5,     0,     6,     0,     7,     8,     9,    10,
    11,    12,    13,    14,     0,     0,     0,     0,    15,    16,
    17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
     0,     0,     0,    21,     0,     0,     0,    22,     0,     0,
    23,     1,     2,   502,     4,     5,     0,     6,     0,     7,
     8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
     0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
     0,     0,    20,     0,     0,     0,    21,     0,     0,     0,
    22,     0,     0,    23,     1,     2,   505,     4,     5,     0,
     6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
     0,     0,     0,     0,    15,    16,    17,    18,     0,     0,
    19,     0,     0,     0,     0,    20,     0,     0,     0,    21,
     0,     0,     0,    22,     0,     0,    23,     1,     2,   511,
     4,     5,     0,     6,     0,     7,     8,     9,    10,    11,
    12,    13,    14,     0,     0,     0,     0,    15,    16,    17,
    18,     0,     0,    19,     0,     0,     0,     0,    20,     0,
     0,     0,    21,     0,     0,     0,    22,     0,     0,    23,
     1,     2,   552,     4,     5,     0,     6,     0,     7,     8,
     9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
    15,    16,    17,    18,     0,     0,    19,     0,     0,     0,
     0,    20,     0,     0,     0,    21,     0,     0,     0,    22,
     0,     0,    23,     1,     2,   561,     4,     5,     0,     6,
     0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
     0,     0,     0,    15,    16,    17,    18,     0,     0,    19,
     0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
     0,     0,    22,     0,     0,    23,     1,     2,   563,     4,
     5,     0,     6,     0,     7,     8,     9,    10,    11,    12,
    13,    14,     0,     0,     0,     0,    15,    16,    17,    18,
     0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
     0,    21,     0,     0,     0,    22,     0,     0,    23,     1,
     2,   570,     4,     5,     0,     6,     0,     7,     8,     9,
    10,    11,    12,    13,    14,     0,     0,     0,     0,    15,
    16,    17,    18,     0,     0,    19,     0,     0,     0,     0,
    20,     0,     0,     0,    21,     0,     0,     0,    22,     0,
     0,    23,     1,     2,   591,     4,     5,     0,     6,     0,
     7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
     0,     0,    15,    16,    17,    18,     0,     0,    19,     0,
     0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
     0,    22,     0,     0,    23,     1,     2,   596,     4,     5,
     0,     6,     0,     7,     8,     9,    10,    11,    12,    13,
    14,     0,     0,     0,     0,    15,    16,    17,    18,     0,
     0,    19,     0,     0,     0,     0,    20,     0,     0,     0,
    21,     0,     0,     0,    22,     0,     0,    23,     1,     2,
   598,     4,     5,     0,     6,     0,     7,     8,     9,    10,
    11,    12,    13,    14,     0,     0,     0,     0,    15,    16,
    17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
     0,     0,     0,    21,     0,     0,     0,    22,     0,     0,
    23,     1,     2,   608,     4,     5,     0,     6,     0,     7,
     8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
     0,    15,    16,    17,    18,     0,     0,    19,     0,     0,
     0,     0,    20,     0,     0,     0,    21,     0,     1,     2,
    22,     4,     5,    23,     6,     0,     7,     8,     9,    10,
    11,    12,    13,    14,     0,     0,     0,     0,    15,    16,
    17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
     0,     0,     0,    21,     1,     2,    56,    22,     0,     0,
    23,     0,     0,     0,     9,    10,     0,    12,    13,    14,
     0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
     0,     0,     0,     0,     0,    20,     0,     0,     0,    21,
     0,     0,    57,    22,     0,     0,    23,     1,     2,   100,
     0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
    12,    13,    14,     0,     0,     0,     0,    15,    16,    17,
     1,     2,   103,     0,     0,     0,     0,     0,    20,     0,
     9,    10,    21,    12,    13,    14,    22,     0,   101,    23,
    15,    16,    17,     1,     2,   294,     0,     0,     0,     0,
     0,    20,     0,     9,    10,    21,    12,    13,    14,    22,
     0,   104,    23,    15,    16,    17,     1,     2,   376,     0,
     0,     0,     0,     0,    20,     0,     9,    10,    21,    12,
    13,    14,    22,     0,   295,    23,    15,    16,    17,     1,
     2,    39,     0,     0,     0,     0,     0,    20,     0,     9,
    10,    21,    12,    13,    14,    22,     0,   377,    23,    15,
    16,    17,     1,     2,    42,     0,     0,     0,     0,     0,
    20,     0,     9,    10,    21,    12,    13,    14,    22,     0,
     0,    40,    15,    16,    17,     1,     2,    50,     0,     0,
     0,     0,     0,    20,     0,     9,    10,    21,    12,    13,
    14,    22,     0,     0,    43,    15,    16,    17,     1,     2,
    52,     0,     0,     0,     0,     0,    20,     0,     9,    10,
    21,    12,    13,    14,    22,     0,     0,    23,    15,    16,
    17,     1,     2,    60,     0,     0,     0,     0,     0,    20,
     0,     9,    10,    21,    12,    13,    14,    22,     0,     0,
    23,    15,    16,    17,     1,     2,    87,     0,     0,     0,
     0,     0,    20,     0,     9,    10,    21,    12,    13,    14,
    22,     0,     0,    23,    15,    16,    17,     1,     2,    93,
     0,     0,     0,     0,     0,    20,     0,     9,    10,    21,
    12,    13,    14,    22,     0,     0,    23,    15,    16,    17,
     1,     2,     0,     0,     0,     0,     0,     0,    20,     0,
     9,    10,    21,    12,    13,    14,    22,     0,     0,    23,
    15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
     0,    20,     0,     0,     0,    21,     0,     0,   112,    22,
     0,     0,    23,     1,     2,   120,     0,     0,     0,     0,
     0,     0,     0,     9,    10,     0,    12,    13,    14,     0,
     0,     0,     0,    15,    16,    17,     1,     2,   122,     0,
     0,     0,     0,     0,    20,     0,     9,    10,    21,    12,
    13,    14,    22,     0,     0,    23,    15,    16,    17,     1,
     2,   124,     0,     0,     0,     0,     0,    20,     0,     9,
    10,    21,    12,    13,    14,    22,     0,     0,    23,    15,
    16,    17,     1,     2,   126,     0,     0,     0,     0,     0,
    20,     0,     9,    10,    21,    12,    13,    14,    22,     0,
     0,    23,    15,    16,    17,     1,     2,   128,     0,     0,
     0,     0,     0,    20,     0,     9,    10,    21,    12,    13,
    14,    22,     0,     0,    23,    15,    16,    17,     1,     2,
   130,     0,     0,     0,     0,     0,    20,     0,     9,    10,
    21,    12,    13,    14,    22,     0,     0,    23,    15,    16,
    17,     1,     2,   132,     0,     0,     0,     0,     0,    20,
     0,     9,    10,    21,    12,    13,    14,    22,     0,     0,
    23,    15,    16,    17,     1,     2,   134,     0,     0,     0,
     0,     0,    20,     0,     9,    10,    21,    12,    13,    14,
    22,     0,     0,    23,    15,    16,    17,     1,     2,   136,
     0,     0,     0,     0,     0,    20,     0,     9,    10,    21,
    12,    13,    14,    22,     0,     0,    23,    15,    16,    17,
     1,     2,   138,     0,     0,     0,     0,     0,    20,     0,
     9,    10,    21,    12,    13,    14,    22,     0,     0,    23,
    15,    16,    17,     1,     2,   140,     0,     0,     0,     0,
     0,    20,     0,     9,    10,    21,    12,    13,    14,    22,
     0,     0,    23,    15,    16,    17,     1,     2,   144,     0,
     0,     0,     0,     0,    20,     0,     9,    10,    21,    12,
    13,    14,    22,     0,     0,    23,    15,    16,    17,     1,
     2,   156,     0,     0,     0,     0,     0,    20,     0,     9,
    10,    21,    12,    13,    14,    22,     0,     0,    23,    15,
    16,    17,     1,     2,   166,     0,     0,     0,     0,     0,
    20,     0,     9,    10,    21,    12,    13,    14,    22,     0,
     0,    23,    15,    16,    17,     1,     2,   200,     0,     0,
     0,     0,     0,    20,     0,     9,    10,    21,    12,    13,
    14,    22,     0,     0,    23,    15,    16,    17,     1,     2,
   359,     0,     0,     0,     0,     0,    20,     0,     9,    10,
    21,    12,    13,    14,    22,     0,     0,    23,    15,    16,
    17,     1,     2,   442,     0,     0,     0,     0,     0,    20,
     0,     9,    10,    21,    12,    13,    14,    22,     0,     0,
    23,    15,    16,    17,     1,     2,     0,     0,     0,     0,
     0,     0,    20,     0,     9,    10,    21,    12,    13,    14,
    22,     0,     0,    23,    15,    16,    17,     1,     2,     0,
     0,     0,     0,     0,     0,    20,     0,     9,    10,    21,
    12,    13,    14,    22,     0,     0,    23,    15,    16,    17,
     1,     2,     0,     0,     0,     0,     0,     0,    20,     0,
     9,    10,    21,    12,    13,    14,    22,     0,     0,    85,
    15,    16,    17,     0,     0,     0,     0,     0,     0,   161,
     0,    20,     0,     0,     0,    21,     0,     0,     0,    22,
     0,     0,    91,    62,    63,    64,    65,     0,     0,     0,
     0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
    71,    72,   171,     0,    73,     0,    74,     0,   162,     0,
     0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
     0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
    68,    69,    70,    71,    72,   202,     0,    73,     0,    74,
     0,   172,     0,     0,     0,     0,     0,     0,     0,    62,
    63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
     0,    66,    67,    68,    69,    70,    71,    72,   234,     0,
    73,     0,    74,     0,   203,     0,     0,     0,     0,     0,
     0,     0,    62,    63,    64,    65,     0,     0,     0,     0,
     0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
    72,   239,     0,    73,     0,    74,     0,   235,     0,     0,
     0,     0,     0,     0,     0,    62,    63,    64,    65,     0,
     0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
    69,    70,    71,    72,   248,     0,    73,     0,    74,     0,
   240,     0,     0,     0,     0,     0,     0,     0,    62,    63,
    64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
    66,    67,    68,    69,    70,    71,    72,   253,     0,    73,
     0,    74,     0,   249,     0,     0,     0,     0,     0,     0,
     0,    62,    63,    64,    65,     0,     0,     0,     0,     0,
     0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
   315,     0,    73,     0,    74,     0,   254,     0,     0,     0,
     0,     0,     0,     0,    62,    63,    64,    65,     0,     0,
     0,     0,     0,     0,     0,     0,    66,    67,    68,    69,
    70,    71,    72,   330,     0,    73,     0,    74,     0,   316,
     0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
    65,     0,     0,     0,     0,     0,     0,     0,     0,    66,
    67,    68,    69,    70,    71,    72,    95,     0,    73,     0,
    74,    96,   331,     0,     0,     0,     0,     0,     0,     0,
    62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
   110,     0,    66,    67,    68,    69,    70,    71,    72,     0,
     0,    73,     0,    74,    62,    63,    64,    65,     0,     0,
     0,     0,     0,     0,     0,   111,    66,    67,    68,    69,
    70,    71,    72,   158,     0,    73,     0,    74,   159,     0,
     0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
    65,     0,     0,     0,     0,     0,     0,     0,     0,    66,
    67,    68,    69,    70,    71,    72,   168,     0,    73,     0,
    74,   169,     0,     0,     0,     0,     0,     0,     0,     0,
    62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
   187,     0,    66,    67,    68,    69,    70,    71,    72,     0,
     0,    73,     0,    74,    62,    63,    64,    65,     0,     0,
     0,     0,     0,     0,   192,   188,    66,    67,    68,    69,
    70,    71,    72,     0,     0,    73,     0,    74,    62,    63,
    64,    65,     0,     0,     0,     0,     0,     0,   219,   193,
    66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
     0,    74,    62,    63,    64,    65,     0,     0,     0,     0,
     0,     0,   297,     0,    66,    67,    68,    69,    70,    71,
    72,     0,     0,    73,   220,    74,    62,    63,    64,    65,
     0,     0,     0,     0,     0,     0,   438,     0,    66,    67,
    68,    69,    70,    71,    72,     0,     0,    73,   298,    74,
    62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
   508,   439,    66,    67,    68,    69,    70,    71,    72,     0,
     0,    73,     0,    74,    62,    63,    64,    65,     0,     0,
     0,     0,     0,     0,   516,   509,    66,    67,    68,    69,
    70,    71,    72,     0,     0,    73,     0,    74,    62,    63,
    64,    65,     0,     0,     0,     0,     0,     0,   567,   517,
    66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
     0,    74,    62,    63,    64,    65,     0,     0,     0,     0,
     0,     0,     0,   568,    66,    67,    68,    69,    70,    71,
    72,     0,     0,    73,     0,    74,    62,    63,    64,    65,
     0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
    68,    69,    70,    71,    72,    62,    63,    73,     0,    74,
     0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
    69,    70,    71,    72,     0,     0,    73,     0,    74
};

static const short yycheck[] = {     3,
   275,   151,   277,   278,     6,     7,    16,     5,     5,    11,
    45,     5,     5,    16,     5,     5,    18,    19,    20,    21,
    22,    23,     5,    36,    37,    45,    16,    40,    16,    42,
    16,     5,     5,    16,    32,    45,     5,    39,    40,     5,
    42,    43,    45,     5,    41,    47,     5,    49,    50,    46,
    52,    44,    46,    46,    56,    46,     5,    45,    60,    45,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    44,    74,    46,     5,    41,   226,    46,   353,   354,
    46,   356,    44,    85,    46,    87,    90,    46,     5,    91,
     8,    93,    96,    16,    98,    44,     5,    46,   100,    10,
    40,   103,    42,     8,   108,    38,     5,   111,    10,    16,
    28,     8,    16,    44,   116,    46,    16,     5,   120,    41,
   122,    16,   124,    28,   126,    44,   128,    44,   130,    46,
   132,    28,   134,    32,   136,    44,   138,    46,   140,    47,
     5,    49,   144,    76,    30,    78,   150,     8,    56,    82,
    83,   155,   427,     8,   156,   159,    44,     8,    46,   163,
   164,     5,     5,     8,   166,   169,     5,    28,     8,   173,
   174,    30,   176,    28,     8,    45,     8,    28,    44,    44,
    10,    46,     8,    28,   188,   189,   190,    10,    28,   193,
   194,   195,   100,     8,    28,   103,    28,     8,   200,     5,
    44,    44,    46,    46,     8,    44,     8,    46,    44,     8,
    16,     5,     5,    28,   147,   217,     8,    28,   222,   152,
   224,     8,    16,    16,    28,   229,    28,   231,     5,    28,
     5,    16,   236,   237,     5,    44,    44,     5,   242,   243,
    30,    16,    19,    20,    21,    22,   250,   251,    16,    27,
    30,     8,   256,   257,    31,    32,    33,    34,    35,    36,
    37,    44,   266,    40,    45,    42,     8,    44,    41,   273,
   274,    41,   276,     8,     8,    44,     8,   279,   282,   283,
    44,   285,    44,    44,    44,   289,     8,    34,    35,    36,
    37,   293,   294,    40,    44,    42,     5,   301,     8,   303,
   304,    10,     8,     8,    16,   309,     5,   311,   312,   217,
    19,    20,    21,    22,   318,   319,     5,    44,    44,    27,
   324,   325,    31,    32,    33,    34,    35,    36,    37,   333,
   334,    40,     8,    42,    41,   339,   340,    32,    33,    34,
    35,    36,    37,   347,   348,    40,    44,    42,   352,     8,
    44,     8,     8,    44,     8,     8,     8,   359,   362,     8,
   364,   363,    44,     8,   368,     8,     8,   371,     8,     5,
   374,     8,     5,     8,   376,    44,     8,     8,     8,   383,
   384,     8,     8,   387,     8,   293,   294,   391,   392,     8,
     8,   395,     8,     8,     8,     8,   400,   401,     8,     8,
     8,     8,   406,     8,     5,    30,     8,     5,   412,   413,
     5,     8,     8,     5,   418,     8,    44,     8,     8,   423,
     8,    44,     8,     8,     8,     8,     8,   431,     8,     8,
   434,     8,     8,     8,     8,   439,   440,     8,     8,     5,
   442,    30,   446,    30,     8,   449,     8,     8,     8,   453,
    44,   455,     8,     8,     8,     8,     5,     8,     8,     0,
   464,     8,     5,     8,     8,    30,     8,   471,   376,     8,
     8,     8,     8,     0,   478,    75,    19,    20,    21,    22,
    -1,    -1,   486,    -1,    -1,    -1,    -1,    30,    31,    32,
    33,    34,    35,    36,    37,   499,    -1,    40,   502,    42,
    -1,   505,    -1,   507,    -1,   509,   510,   511,    19,    20,
    -1,    22,    -1,   517,    -1,    -1,    -1,   521,    -1,    -1,
   524,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
    -1,    42,     3,     4,     5,     6,     7,    -1,     9,    -1,
    11,    12,    13,    14,    15,    16,    17,    18,   552,    -1,
   554,    -1,    23,    24,    25,    26,   560,   561,    29,   563,
    -1,    -1,    -1,    34,   568,   569,   570,    38,   572,    -1,
    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
   584,    -1,    -1,    -1,    -1,    -1,    -1,   591,    -1,    -1,
    -1,   595,   596,    -1,   598,    -1,    -1,     3,     4,     5,
     6,     7,    -1,     9,   608,    11,    12,    13,    14,    15,
    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
     3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
    -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,
    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,
    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
     7,    -1,     9,    -1,    11,    12,    13,    14,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,
     4,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
    -1,    45,     3,     4,     5,     6,     7,    -1,     9,    -1,
    11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,     7,
    -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,
     5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
    45,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
    12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
    42,    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,
     9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,
     6,     7,    -1,     9,    -1,    11,    12,    13,    14,    15,
    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
     3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
    -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,
    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,
    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
     7,    -1,     9,    -1,    11,    12,    13,    14,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,
     4,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
    -1,    45,     3,     4,     5,     6,     7,    -1,     9,    -1,
    11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,     7,
    -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,
     5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
    45,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
    12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
    42,    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,
     9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,
     6,     7,    -1,     9,    -1,    11,    12,    13,    14,    15,
    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
     3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
    -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,
    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,
    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
     7,    -1,     9,    -1,    11,    12,    13,    14,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,
     4,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
    -1,    45,     3,     4,     5,     6,     7,    -1,     9,    -1,
    11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,     7,
    -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,
     5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
    45,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
    12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
    42,    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,
     9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,
     6,     7,    -1,     9,    -1,    11,    12,    13,    14,    15,
    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,
     3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
    -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,
    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,
    -1,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
     7,    -1,     9,    -1,    11,    12,    13,    14,    15,    16,
    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,
     4,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
    -1,    45,     3,     4,     5,     6,     7,    -1,     9,    -1,
    11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,     7,
    -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
    38,    -1,    -1,    -1,    42,    -1,    -1,    45,     3,     4,
     5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
    45,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
    12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,     3,     4,
    42,     6,     7,    45,     9,    -1,    11,    12,    13,    14,
    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
    -1,    -1,    -1,    38,     3,     4,     5,    42,    -1,    -1,
    45,    -1,    -1,    -1,    13,    14,    -1,    16,    17,    18,
    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
    -1,    -1,    41,    42,    -1,    -1,    45,     3,     4,     5,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,
    13,    14,    38,    16,    17,    18,    42,    -1,    44,    45,
    23,    24,    25,     3,     4,     5,    -1,    -1,    -1,    -1,
    -1,    34,    -1,    13,    14,    38,    16,    17,    18,    42,
    -1,    44,    45,    23,    24,    25,     3,     4,     5,    -1,
    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,
    17,    18,    42,    -1,    44,    45,    23,    24,    25,     3,
     4,     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,
    14,    38,    16,    17,    18,    42,    -1,    44,    45,    23,
    24,    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
    34,    -1,    13,    14,    38,    16,    17,    18,    42,    -1,
    -1,    45,    23,    24,    25,     3,     4,     5,    -1,    -1,
    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,
    18,    42,    -1,    -1,    45,    23,    24,    25,     3,     4,
     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,
    38,    16,    17,    18,    42,    -1,    -1,    45,    23,    24,
    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    34,
    -1,    13,    14,    38,    16,    17,    18,    42,    -1,    -1,
    45,    23,    24,    25,     3,     4,     5,    -1,    -1,    -1,
    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,    18,
    42,    -1,    -1,    45,    23,    24,    25,     3,     4,     5,
    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,
    16,    17,    18,    42,    -1,    -1,    45,    23,    24,    25,
     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
    13,    14,    38,    16,    17,    18,    42,    -1,    -1,    45,
    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
    -1,    -1,    45,     3,     4,     5,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    13,    14,    -1,    16,    17,    18,    -1,
    -1,    -1,    -1,    23,    24,    25,     3,     4,     5,    -1,
    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,
    17,    18,    42,    -1,    -1,    45,    23,    24,    25,     3,
     4,     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,
    14,    38,    16,    17,    18,    42,    -1,    -1,    45,    23,
    24,    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
    34,    -1,    13,    14,    38,    16,    17,    18,    42,    -1,
    -1,    45,    23,    24,    25,     3,     4,     5,    -1,    -1,
    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,
    18,    42,    -1,    -1,    45,    23,    24,    25,     3,     4,
     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,
    38,    16,    17,    18,    42,    -1,    -1,    45,    23,    24,
    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    34,
    -1,    13,    14,    38,    16,    17,    18,    42,    -1,    -1,
    45,    23,    24,    25,     3,     4,     5,    -1,    -1,    -1,
    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,    18,
    42,    -1,    -1,    45,    23,    24,    25,     3,     4,     5,
    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,
    16,    17,    18,    42,    -1,    -1,    45,    23,    24,    25,
     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,
    13,    14,    38,    16,    17,    18,    42,    -1,    -1,    45,
    23,    24,    25,     3,     4,     5,    -1,    -1,    -1,    -1,
    -1,    34,    -1,    13,    14,    38,    16,    17,    18,    42,
    -1,    -1,    45,    23,    24,    25,     3,     4,     5,    -1,
    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,
    17,    18,    42,    -1,    -1,    45,    23,    24,    25,     3,
     4,     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,
    14,    38,    16,    17,    18,    42,    -1,    -1,    45,    23,
    24,    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
    34,    -1,    13,    14,    38,    16,    17,    18,    42,    -1,
    -1,    45,    23,    24,    25,     3,     4,     5,    -1,    -1,
    -1,    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,
    18,    42,    -1,    -1,    45,    23,    24,    25,     3,     4,
     5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,
    38,    16,    17,    18,    42,    -1,    -1,    45,    23,    24,
    25,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    34,
    -1,    13,    14,    38,    16,    17,    18,    42,    -1,    -1,
    45,    23,    24,    25,     3,     4,    -1,    -1,    -1,    -1,
    -1,    -1,    34,    -1,    13,    14,    38,    16,    17,    18,
    42,    -1,    -1,    45,    23,    24,    25,     3,     4,    -1,
    -1,    -1,    -1,    -1,    -1,    34,    -1,    13,    14,    38,
    16,    17,    18,    42,    -1,    -1,    45,    23,    24,    25,
     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
    13,    14,    38,    16,    17,    18,    42,    -1,    -1,    45,
    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,     5,
    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
    -1,    -1,    45,    19,    20,    21,    22,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
    36,    37,     5,    -1,    40,    -1,    42,    -1,    44,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
    33,    34,    35,    36,    37,     5,    -1,    40,    -1,    42,
    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    31,    32,    33,    34,    35,    36,    37,     5,    -1,
    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
    37,     5,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    35,    36,    37,     5,    -1,    40,    -1,    42,    -1,
    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    31,    32,    33,    34,    35,    36,    37,     5,    -1,    40,
    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
     5,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
    35,    36,    37,     5,    -1,    40,    -1,    42,    -1,    44,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
    32,    33,    34,    35,    36,    37,     5,    -1,    40,    -1,
    42,    10,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     5,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
    -1,    40,    -1,    42,    19,    20,    21,    22,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
    35,    36,    37,     5,    -1,    40,    -1,    42,    10,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
    32,    33,    34,    35,    36,    37,     5,    -1,    40,    -1,
    42,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     5,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
    -1,    40,    -1,    42,    19,    20,    21,    22,    -1,    -1,
    -1,    -1,    -1,    -1,     5,    30,    31,    32,    33,    34,
    35,    36,    37,    -1,    -1,    40,    -1,    42,    19,    20,
    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,     5,    30,
    31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
    -1,    42,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,    -1,     5,    -1,    31,    32,    33,    34,    35,    36,
    37,    -1,    -1,    40,    41,    42,    19,    20,    21,    22,
    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    31,    32,
    33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     5,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
    -1,    40,    -1,    42,    19,    20,    21,    22,    -1,    -1,
    -1,    -1,    -1,    -1,     5,    30,    31,    32,    33,    34,
    35,    36,    37,    -1,    -1,    40,    -1,    42,    19,    20,
    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,     5,    30,
    31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
    -1,    42,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
    37,    -1,    -1,    40,    -1,    42,    19,    20,    21,    22,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
    33,    34,    35,    36,    37,    19,    20,    40,    -1,    42,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
    34,    35,    36,    37,    -1,    -1,    40,    -1,    42
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
#line 538 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 2:
#line 539 "parser.y"
{ yyval.uProgram = createProgram(yyvsp[0].uStmtSeq); root = yyval.uProgram;;
    break;}
case 3:
#line 542 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 4:
#line 543 "parser.y"
{ yyval.uExpr = createBinExpr(ePlus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 5:
#line 545 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 6:
#line 546 "parser.y"
{ yyval.uExpr = createBinExpr(eMinus, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 7:
#line 548 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 8:
#line 549 "parser.y"
{ yyval.uExpr = createBinExpr(eMul, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 9:
#line 551 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 10:
#line 552 "parser.y"
{ yyval.uExpr = createBinExpr(eDiv, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 11:
#line 554 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 12:
#line 555 "parser.y"
{ yyval.uExpr = createBinExpr(eLess, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 13:
#line 557 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 14:
#line 558 "parser.y"
{ yyval.uExpr = createBinExpr(eMore, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 15:
#line 560 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 16:
#line 561 "parser.y"
{ yyval.uExpr = createBinExpr(eEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 17:
#line 563 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 18:
#line 564 "parser.y"
{ yyval.uExpr = createBinExpr(eNEqu, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 19:
#line 566 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 20:
#line 567 "parser.y"
{ yyval.uExpr = createBinExpr(eOr, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 21:
#line 569 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 22:
#line 570 "parser.y"
{ yyval.uExpr = createBinExpr(eAnd, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 23:
#line 572 "parser.y"
{ yyval.uExpr = createUnExpr(eNot, yyvsp[0].uExpr); ;
    break;}
case 24:
#line 574 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-2].uExpr, yyvsp[0].uExpr); ;
    break;}
case 25:
#line 575 "parser.y"
{ yyval.uExpr = createBinExpr(eAssign, yyvsp[-3].uExpr, yyvsp[0].uExpr); ;
    break;}
case 26:
#line 577 "parser.y"
{ yyval.uExpr = createUnExpr(eUMinus, yyvsp[0].uExpr); ;
    break;}
case 27:
#line 579 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 28:
#line 580 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 29:
#line 581 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-1].uExpr); ;
    break;}
case 30:
#line 582 "parser.y"
{ yyval.uExpr = createBracketsExpr(yyvsp[-2].uExpr); ;
    break;}
case 31:
#line 584 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-3].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 32:
#line 585 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 33:
#line 586 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-4].uExpr, yyvsp[-1].uExpr); ;
    break;}
case 34:
#line 587 "parser.y"
{ yyval.uExpr = createQBracketsExpr(yyvsp[-5].uExpr, yyvsp[-2].uExpr); ;
    break;}
case 35:
#line 589 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 36:
#line 590 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 37:
#line 591 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 38:
#line 592 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 39:
#line 594 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 40:
#line 595 "parser.y"
{ yyval.uExpr = createQBracketsInitExpr(NULL); ;
    break;}
case 41:
#line 597 "parser.y"
{ yyval.uExpr = createIntExpr(yyvsp[0].uInt); ;
    break;}
case 42:
#line 598 "parser.y"
{ yyval.uExpr = createStrExpr(yyvsp[0].uString); ;
    break;}
case 43:
#line 599 "parser.y"
{ yyval.uExpr = createNilExpr(); ;
    break;}
case 44:
#line 600 "parser.y"
{ yyval.uExpr = createBoolExpr(1); ;
    break;}
case 45:
#line 601 "parser.y"
{ yyval.uExpr = createBoolExpr(0); ;
    break;}
case 46:
#line 603 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-4].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 47:
#line 604 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 48:
#line 605 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 49:
#line 606 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 50:
#line 607 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 51:
#line 609 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-5].uExpr, yyvsp[-2].uId, NULL); ;
    break;}
case 52:
#line 610 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-6].uExpr, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 53:
#line 611 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 54:
#line 612 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-8].uExpr, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 55:
#line 613 "parser.y"
{ yyval.uExpr = createMethodCallExpr(yyvsp[-7].uExpr, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 56:
#line 616 "parser.y"
{ yyval.uExpr = createLocalExpr(yyvsp[0].uId); ;
    break;}
case 57:
#line 617 "parser.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId, false); ;
    break;}
case 58:
#line 618 "parser.y"
{ yyval.uExpr = createFieldAccExpr(NULL, yyvsp[0].uId, true); ;
    break;}
case 59:
#line 619 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-2].uId, NULL); ;
    break;}
case 60:
#line 620 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-3].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 61:
#line 621 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-1].uExprSeq); ;
    break;}
case 62:
#line 622 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-5].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 63:
#line 623 "parser.y"
{ yyval.uExpr = createMethodCallExpr(NULL, yyvsp[-4].uId, yyvsp[-2].uExprSeq); ;
    break;}
case 64:
#line 624 "parser.y"
{ yyval.uExpr = createSelfExpr(); ;
    break;}
case 65:
#line 626 "parser.y"
{ yyval.uExpr = createSuperExpr(NULL); ;
    break;}
case 66:
#line 627 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 67:
#line 628 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-1].uExprSeq); ;
    break;}
case 68:
#line 629 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 69:
#line 630 "parser.y"
{ yyval.uExpr = createSuperExpr(yyvsp[-2].uExprSeq); ;
    break;}
case 70:
#line 633 "parser.y"
{ yyval.uExprSeq = createExprSeq(yyvsp[0].uExpr); ;
    break;}
case 71:
#line 634 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-2].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 72:
#line 635 "parser.y"
{ yyval.uExprSeq = addExprToSeq(yyvsp[-3].uExprSeq, yyvsp[0].uExpr); ;
    break;}
case 73:
#line 638 "parser.y"
{ yyval.uStmt = createStmt(eExpr, yyvsp[0].uExpr, NULL); ;
    break;}
case 74:
#line 639 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 75:
#line 640 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 76:
#line 641 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 77:
#line 642 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 78:
#line 643 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 79:
#line 644 "parser.y"
{ yyval.uStmt = yyvsp[0].uStmt; ;
    break;}
case 80:
#line 645 "parser.y"
{ yyval.uStmt = createReturnStmt(yyvsp[0].uExpr); ;
    break;}
case 81:
#line 646 "parser.y"
{ yyval.uStmt = createReturnStmt(NULL); ;
    break;}
case 82:
#line 650 "parser.y"
{ yyval.uStmtSeq = NULL; ;
    break;}
case 83:
#line 651 "parser.y"
{ yyval.uStmtSeq = yyvsp[0].uStmtSeq; ;
    break;}
case 84:
#line 654 "parser.y"
{ yyval.uStmtSeq = createStmtSeq(yyvsp[0].uStmt); ;
    break;}
case 85:
#line 655 "parser.y"
{ yyval.uStmtSeq = addStmtToSeq(yyvsp[-2].uStmtSeq, yyvsp[0].uStmt); ;
    break;}
case 86:
#line 656 "parser.y"
{ yyval.uStmtSeq = yyvsp[-1].uStmtSeq; ;
    break;}
case 87:
#line 659 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 88:
#line 660 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 89:
#line 661 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 90:
#line 662 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 91:
#line 663 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 92:
#line 664 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 93:
#line 665 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 94:
#line 666 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 95:
#line 667 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 96:
#line 668 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, false); ;
    break;}
case 97:
#line 670 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 98:
#line 671 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 99:
#line 672 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 100:
#line 673 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 101:
#line 674 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 102:
#line 675 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-5].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 103:
#line 676 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 104:
#line 677 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-6].uId, yyvsp[-4].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 105:
#line 678 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-7].uId, yyvsp[-5].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 106:
#line 679 "parser.y"
{ yyval.uStmt = createMethodDefStmt(yyvsp[-4].uId, yyvsp[-3].uMethodDefParamSeq, yyvsp[-1].uStmtSeq, true); ;
    break;}
case 107:
#line 682 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(NULL); ;
    break;}
case 108:
#line 683 "parser.y"
{ yyval.uMethodDefParamSeq = yyvsp[0].uMethodDefParamSeq;;
    break;}
case 109:
#line 686 "parser.y"
{ yyval.uMethodDefParamSeq = createMethodDefParamSeq(yyvsp[0].uMethodDefParam); ;
    break;}
case 110:
#line 687 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-3].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 111:
#line 688 "parser.y"
{ yyval.uMethodDefParamSeq = addParamToMethodDefParamSeq(yyvsp[-2].uMethodDefParamSeq, yyvsp[0].uMethodDefParam); ;
    break;}
case 112:
#line 691 "parser.y"
{ yyval.uMethodDefParam = createMethodDefParam(yyvsp[0].uId); ;
    break;}
case 113:
#line 694 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 114:
#line 695 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 115:
#line 696 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 116:
#line 697 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 117:
#line 699 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 118:
#line 700 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 119:
#line 701 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 120:
#line 702 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 121:
#line 704 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 122:
#line 705 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 123:
#line 706 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 124:
#line 707 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 125:
#line 710 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 126:
#line 711 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 127:
#line 712 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 128:
#line 713 "parser.y"
{ yyval.uStmt = createStmt(eWhile, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 129:
#line 716 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 130:
#line 717 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 131:
#line 718 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 132:
#line 719 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 133:
#line 721 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 134:
#line 722 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 135:
#line 723 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 136:
#line 724 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 137:
#line 726 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 138:
#line 727 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 139:
#line 728 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 140:
#line 729 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 141:
#line 732 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 142:
#line 733 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 143:
#line 734 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 144:
#line 735 "parser.y"
{ yyval.uStmt = createStmt(eUntil, yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq); ;
    break;}
case 145:
#line 739 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 146:
#line 740 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 147:
#line 741 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-6].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 148:
#line 742 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-5].uId, yyvsp[-3].uId, yyvsp[-1].uStmtSeq); ;
    break;}
case 149:
#line 744 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 150:
#line 745 "parser.y"
{ yyval.uStmt = createClassDef(yyvsp[-3].uId, NULL, yyvsp[-1].uStmtSeq); ;
    break;}
case 151:
#line 748 "parser.y"
{ yyval.uElsifSeq = NULL ;
    break;}
case 152:
#line 749 "parser.y"
{ yyval.uElsifSeq = yyvsp[0].uElsifSeq ;
    break;}
case 153:
#line 752 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 154:
#line 753 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-4].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 155:
#line 755 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 156:
#line 756 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 157:
#line 757 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 158:
#line 759 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-2].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 159:
#line 760 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 160:
#line 761 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 161:
#line 763 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 162:
#line 764 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 163:
#line 765 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 164:
#line 766 "parser.y"
{ yyval.uElsifSeq = createElsifSeq(yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 165:
#line 768 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-5].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 166:
#line 769 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 167:
#line 770 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-6].uElsifSeq, yyvsp[-3].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 168:
#line 771 "parser.y"
{ yyval.uElsifSeq = addToElsifSeq(yyvsp[-7].uElsifSeq, yyvsp[-4].uExpr, yyvsp[0].uStmtSeq) ;
    break;}
case 169:
#line 774 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 170:
#line 775 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 171:
#line 777 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-4].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 172:
#line 778 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 173:
#line 779 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 174:
#line 781 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 175:
#line 782 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 176:
#line 783 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-3].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 177:
#line 785 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 178:
#line 786 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-5].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 179:
#line 787 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 180:
#line 788 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-6].uExpr, yyvsp[-2].uStmtSeq, yyvsp[-1].uElsifSeq, NULL) ;
    break;}
case 181:
#line 790 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 182:
#line 791 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 183:
#line 792 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 184:
#line 793 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-7].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 185:
#line 794 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 186:
#line 795 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-8].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 187:
#line 796 "parser.y"
{ yyval.uStmt = createIfStmt(yyvsp[-9].uExpr, yyvsp[-5].uStmtSeq, yyvsp[-4].uElsifSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 188:
#line 799 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 189:
#line 800 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 190:
#line 802 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-3].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 191:
#line 803 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 192:
#line 804 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 193:
#line 806 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 194:
#line 807 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 195:
#line 808 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-3].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 196:
#line 810 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 197:
#line 811 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 198:
#line 812 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-4].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 199:
#line 813 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-5].uExpr, yyvsp[-1].uStmtSeq, NULL) ;
    break;}
case 200:
#line 815 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 201:
#line 816 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 202:
#line 817 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 203:
#line 818 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-6].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 204:
#line 819 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-8].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 205:
#line 820 "parser.y"
{ yyval.uStmt = createUnlessStmt(yyvsp[-7].uExpr, yyvsp[-4].uStmtSeq, yyvsp[-1].uStmtSeq) ;
    break;}
case 206:
#line 821 "parser.y"
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
#line 824 "parser.y"

void yyerror(const char *s)
{
    printf("%s !",s);
}

