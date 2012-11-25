%{
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

%}
%union
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
}

%type <uExpr> expr
%type <uExprSeq> expr_seqE
%type <uStmt> stmt
%type <uStmtSeq> stmt_seq
%type <uStmtSeq> stmt_seqE
%type <uStmt> method_def
%type <uMethodDefParamSeq> method_def_param_seq
%type <uMethodDefParamSeq> method_def_param_seqE
%type <uMethodDefParam> method_def_param
%type <uStmt> while_stmt
%type <uStmt> until_stmt
%type <uStmt> class_def
%type <uStmt> if_stmt
%type <uStmt> unless_stmt
%type <uElsifSeq> elsif_seq
%type <uElsifSeq> elsif_seqE
%type <uProgram> program

%token <uInt> INT
%token <uString> STRING
%token EOL
%token DEF
%token END
%token WHILE
%token DO
%token UNTIL
%token CLASS
%token SELF
%token SUPER
%token RETURN
%token <uId> ID
%token EQUAL
%token NOTEQUAL
%token OR
%token AND
%token NIL
%token TRUE
%token FALSE
%token IF
%token ELSIF
%token ELSE
%token UNLESS
%token THEN

%left EOL

%right '='

%left OR
%left AND
%left EQUAL NOTEQUAL

%left '<' '>'
%left '-' '+'
%left '*' '/'
%left '!' UMINUS
%left '.'
%left ']' '['
%nonassoc UBR

%nonassoc ')'


%%

program		: stmt_seq { $$ = createProgram($1); root = $$;}
			| EOL stmt_seq { $$ = createProgram($2); root = $$;}
			;

expr		: expr '+' expr { $$ = createBinExpr(ePlus, $1, $3); }
			| expr '+' EOL expr %prec '+' { $$ = createBinExpr(ePlus, $1, $4); }
			
			| expr '-' EOL expr %prec '-' { $$ = createBinExpr(eMinus, $1, $4); }
			| expr '-' expr { $$ = createBinExpr(eMinus, $1, $3); }
			
			| expr '*' EOL expr %prec '*' { $$ = createBinExpr(eMul, $1, $4); }
			| expr '*' expr  { $$ = createBinExpr(eMul, $1, $3); }
			
			| expr '/' EOL expr %prec '/'{ $$ = createBinExpr(eDiv, $1, $4); }
			| expr '/' expr { $$ = createBinExpr(eDiv, $1, $3); }
			
			| expr '<' expr { $$ = createBinExpr(eLess, $1, $3); }
			| expr '<' EOL expr %prec '<' { $$ = createBinExpr(eLess, $1, $4); }
			
			| expr '>' expr { $$ = createBinExpr(eMore, $1, $3); }
			| expr '>' EOL expr %prec '>' { $$ = createBinExpr(eMore, $1, $4); }
			
			| expr EQUAL expr { $$ = createBinExpr(eEqu, $1, $3); }
			| expr EQUAL EOL expr %prec EQUAL { $$ = createBinExpr(eEqu, $1, $4); }
			
			| expr NOTEQUAL expr { $$ = createBinExpr(eNEqu, $1, $3); }
			| expr NOTEQUAL EOL expr %prec NOTEQUAL { $$ = createBinExpr(eNEqu, $1, $4); }
			
			| expr OR expr { $$ = createBinExpr(eOr, $1, $3); }
			| expr OR EOL expr %prec OR { $$ = createBinExpr(eOr, $1, $4); }
			
			| expr AND expr { $$ = createBinExpr(eAnd, $1, $3); }
			| expr AND EOL expr %prec AND { $$ = createBinExpr(eAnd, $1, $4); }
			
			| '!' expr { $$ = createUnExpr(eNot, $2); }
			
			| expr '=' expr { $$ = createBinExpr(eAssign, $1, $3); }
			| expr '=' EOL expr %prec '=' { $$ = createBinExpr(eAssign, $1, $4); }
			
			| '-' expr %prec UMINUS { $$ = createUnExpr(eUMinus, $2); }
			
			| '(' expr ')' { $$ = createBracketsExpr($2); }
			| '(' expr EOL ')' { $$ = createBracketsExpr($2); }
			| '(' EOL expr ')' { $$ = createBracketsExpr($3); }
			| '(' EOL expr EOL ')' { $$ = createBracketsExpr($3); }
			
			| expr '[' expr ']' { $$ = createQBracketsExpr($1, $3); }
			| expr '[' expr EOL ']' { $$ = createQBracketsExpr($1, $3); }
			| expr '[' EOL expr ']' { $$ = createQBracketsExpr($1, $4); }
			| expr '[' EOL expr EOL ']' { $$ = createQBracketsExpr($1, $4); }
			
			| '[' EOL expr_seqE ']' %prec UBR { $$ = createQBracketsInitExpr($3); }
			| '[' EOL expr_seqE EOL ']' %prec UBR { $$ = createQBracketsInitExpr($3); }
			| '[' expr_seqE EOL ']' %prec UBR { $$ = createQBracketsInitExpr($2); }
			| '[' expr_seqE ']' %prec UBR { $$ = createQBracketsInitExpr($2); }
			
			| '[' ']' %prec UBR { $$ = createQBracketsInitExpr(NULL); }
			| '[' EOL ']' %prec UBR { $$ = createQBracketsInitExpr(NULL); }
			
			| INT { $$ = createIntExpr($1); }
			| STRING { $$ = createStrExpr($1); }
			| NIL { $$ = createNilExpr(); }
			| TRUE { $$ = createBoolExpr(1); }
			| FALSE { $$ = createBoolExpr(0); }
			| expr '.' ID { $$ = createFieldAccExpr($1, $3); }

			| expr '.' ID '(' ')' { $$ = createMethodCallExpr($1, $3, NULL); }
			| expr '.' ID '(' expr_seqE ')' { $$ = createMethodCallExpr($1, $3, $5); }
			| expr '.' ID '(' EOL expr_seqE ')' { $$ = createMethodCallExpr($1, $3, $6); }
			| expr '.' ID '(' EOL expr_seqE EOL ')' { $$ = createMethodCallExpr($1, $3, $6); }
			| expr '.' ID '(' expr_seqE EOL ')' { $$ = createMethodCallExpr($1, $3, $5); }
			
			| expr '.' EOL ID { $$ = createFieldAccExpr($1, $4); }
			| expr '.' EOL ID '(' ')' { $$ = createMethodCallExpr($1, $4, NULL); }
			| expr '.' EOL ID '(' expr_seqE ')' { $$ = createMethodCallExpr($1, $4, $6); }
			| expr '.' EOL ID '(' EOL expr_seqE ')' { $$ = createMethodCallExpr($1, $4, $7); }
			| expr '.' EOL ID '(' EOL expr_seqE EOL ')' { $$ = createMethodCallExpr($1, $4, $7); }
			| expr '.' EOL ID '(' expr_seqE EOL ')' { $$ = createMethodCallExpr($1, $4, $6); }


			| ID { $$ = createFieldAccExpr(NULL, $1); }
			| ID '(' ')' { $$ = createMethodCallExpr(NULL, $1, NULL); }
			| ID '(' expr_seqE ')' { $$ = createMethodCallExpr(NULL, $1, $3); }
			| ID '(' EOL expr_seqE ')' { $$ = createMethodCallExpr(NULL, $1, $4); }
			| ID '(' EOL expr_seqE EOL ')' { $$ = createMethodCallExpr(NULL, $1, $4); }
			| ID '(' expr_seqE EOL ')' { $$ = createMethodCallExpr(NULL, $1, $3); }
			| SELF { $$ = createSelfExpr(); }
			
			| SUPER '(' ')' { $$ = createSuperExpr(NULL); }
			| SUPER '(' expr_seqE ')' { $$ = createSuperExpr($3); }
			| SUPER '(' EOL expr_seqE ')' { $$ = createSuperExpr($4); }
			| SUPER '(' EOL expr_seqE EOL ')' { $$ = createSuperExpr($4); }
			| SUPER '(' expr_seqE EOL ')' { $$ = createSuperExpr($3); }
			;
	
expr_seqE	: expr { $$ = createExprSeq($1); }
			| expr_seqE ',' expr { $$ = addExprToSeq($1, $3); }
			| expr_seqE ',' EOL expr { $$ = addExprToSeq($1, $4); }
			;

stmt		: expr { $$ = createStmt(eExpr, $1, NULL); }
			| method_def { $$ = $1; }
			| class_def { $$ = $1; }
			| while_stmt { $$ = $1; }
			| until_stmt { $$ = $1; }
			| if_stmt { $$ = $1; }
			| unless_stmt { $$ = $1; }
			| RETURN expr { $$ = createReturnStmt($2); }
			| RETURN { $$ = createReturnStmt(NULL); }
			;


stmt_seq    : /*empty*/ { $$ = NULL; }
			| stmt_seqE { $$ = $1; }
			;
			
stmt_seqE   : stmt { $$ = createStmtSeq($1); }
			| stmt_seqE EOL stmt { $$ = addStmtToSeq($1, $3); }
			| stmt_seqE EOL { $$ = $1; }
			;
	
method_def	: DEF EOL ID '(' method_def_param_seq EOL ')' stmt_seq  END { $$ = createMethodDefStmt($3, $5, $8); }
			| DEF EOL ID '(' method_def_param_seq EOL ')' EOL stmt_seq  END { $$ = createMethodDefStmt($3, $5, $9); }
			| DEF EOL ID '(' method_def_param_seq ')' stmt_seq  END { $$ = createMethodDefStmt($3, $5, $7); }
			| DEF EOL ID '(' method_def_param_seq ')' EOL stmt_seq  END { $$ = createMethodDefStmt($3, $5, $8); }
			| DEF EOL ID method_def_param_seq EOL stmt_seq END { $$ = createMethodDefStmt($3, $4, $6); }
			| DEF ID '(' method_def_param_seq ')' stmt_seq END { $$ = createMethodDefStmt($2, $4, $6); }
			| DEF ID '(' method_def_param_seq ')' EOL stmt_seq END { $$ = createMethodDefStmt($2, $4, $7); }
			| DEF ID '(' method_def_param_seq EOL ')' stmt_seq END { $$ = createMethodDefStmt($2, $4, $7); }
			| DEF ID '(' method_def_param_seq EOL ')' EOL stmt_seq END { $$ = createMethodDefStmt($2, $4, $8); }
			| DEF ID method_def_param_seq EOL stmt_seq END { $$ = createMethodDefStmt($2, $3, $5); }
			;

method_def_param_seq: /* empty */ { $$ = createMethodDefParamSeq(NULL); }
			| method_def_param_seqE { $$ = $1;}
			;

method_def_param_seqE: method_def_param { $$ = createMethodDefParamSeq($1); }
			| method_def_param_seq ',' EOL method_def_param { $$ = addParamToMethodDefParamSeq($1, $4); }
			| method_def_param_seq ',' method_def_param { $$ = addParamToMethodDefParamSeq($1, $3); }
			;

method_def_param: ID { $$ = createMethodDefParam($1); }
			;

while_stmt	: WHILE EOL expr DO stmt_seq END { $$ = createStmt(eWhile, $3, $5); }
			| WHILE expr DO stmt_seq END { $$ = createStmt(eWhile, $2, $4); }
			| WHILE EOL expr DO EOL stmt_seq END { $$ = createStmt(eWhile, $3, $6); }
			| WHILE expr DO EOL stmt_seq END { $$ = createStmt(eWhile, $2, $5); }
			
			| WHILE EOL expr EOL DO stmt_seq END { $$ = createStmt(eWhile, $3, $6); }
			| WHILE expr EOL DO stmt_seq END { $$ = createStmt(eWhile, $2, $5); }
			| WHILE EOL expr EOL DO EOL stmt_seq END { $$ = createStmt(eWhile, $3, $7); }
			| WHILE expr EOL DO EOL stmt_seq END { $$ = createStmt(eWhile, $2, $6); }

			| WHILE EOL '(' EOL expr EOL ')' EOL stmt_seq END { $$ = createStmt(eWhile, $5, $9); }
			| WHILE EOL '(' EOL expr ')' EOL stmt_seq END { $$ = createStmt(eWhile, $5, $8); }
			| WHILE EOL '(' expr EOL ')' EOL stmt_seq END { $$ = createStmt(eWhile, $4, $8); }
			| WHILE EOL '(' expr ')' EOL stmt_seq END { $$ = createStmt(eWhile, $4, $7); }
			
			
			| WHILE '(' EOL expr EOL ')' EOL stmt_seq END { $$ = createStmt(eWhile, $4, $8); }
			| WHILE '(' EOL expr ')' EOL stmt_seq END { $$ = createStmt(eWhile, $4, $7); }
			| WHILE '(' expr EOL ')' EOL stmt_seq END { $$ = createStmt(eWhile, $3, $7); }
			| WHILE '(' expr ')' EOL stmt_seq END { $$ = createStmt(eWhile, $3, $6); }
			;
	
until_stmt	: UNTIL EOL expr DO stmt_seq END { $$ = createStmt(eUntil, $3, $5); }
			| UNTIL expr DO stmt_seq END { $$ = createStmt(eUntil, $2, $4); }
			| UNTIL EOL expr DO EOL stmt_seq END { $$ = createStmt(eUntil, $3, $6); }
			| UNTIL expr DO EOL stmt_seq END { $$ = createStmt(eUntil, $2, $5); }
			
			| UNTIL EOL expr EOL DO stmt_seq END { $$ = createStmt(eUntil, $3, $6); }
			| UNTIL expr EOL DO stmt_seq END { $$ = createStmt(eUntil, $2, $5); }
			| UNTIL EOL expr EOL DO EOL stmt_seq END { $$ = createStmt(eUntil, $3, $7); }
			| UNTIL expr EOL DO EOL stmt_seq END { $$ = createStmt(eUntil, $2, $6); }

			| UNTIL EOL '(' EOL expr EOL ')' EOL stmt_seq END { $$ = createStmt(eUntil, $5, $9); }
			| UNTIL EOL '(' EOL expr ')' EOL stmt_seq END { $$ = createStmt(eUntil, $5, $8); }
			| UNTIL EOL '(' expr EOL ')' EOL stmt_seq END { $$ = createStmt(eUntil, $4, $8); }
			| UNTIL EOL '(' expr ')' EOL stmt_seq END { $$ = createStmt(eUntil, $4, $7); }
			
			
			| UNTIL '(' EOL expr EOL ')' EOL stmt_seq END { $$ = createStmt(eUntil, $4, $8); }
			| UNTIL '(' EOL expr ')' EOL stmt_seq END { $$ = createStmt(eUntil, $4, $7); }
			| UNTIL '(' expr EOL ')' EOL stmt_seq END { $$ = createStmt(eUntil, $3, $7); }
			| UNTIL '(' expr ')' EOL stmt_seq END { $$ = createStmt(eUntil, $3, $6); }
			;
			
			
class_def	: CLASS EOL ID '<' EOL ID EOL stmt_seq END { $$ = createClassDef($3, $6, $8); }
			| CLASS EOL ID '<' ID EOL stmt_seq END { $$ = createClassDef($3, $5, $7); }
			| CLASS ID '<' EOL ID EOL stmt_seq END { $$ = createClassDef($2, $5, $7); }
			| CLASS ID '<' ID EOL stmt_seq END { $$ = createClassDef($2, $4, $6); }
			
			| CLASS EOL ID EOL stmt_seq END { $$ = createClassDef($3, NULL, $5); }
			| CLASS ID EOL stmt_seq END { $$ = createClassDef($2, NULL, $4); }
			;

elsif_seq	: /* empty */ { $$ = NULL }
			| elsif_seqE { $$ = $1 }
			;
					
elsif_seqE	: ELSIF expr THEN stmt_seq { $$ = createElsifSeq($2, $4) }
			| elsif_seqE ELSIF expr THEN stmt_seq { $$ = addToElsifSeq($1, $3, $5) }
			
			| ELSIF EOL expr THEN stmt_seq { $$ = createElsifSeq($3, $5) }
			| ELSIF expr EOL THEN stmt_seq { $$ = createElsifSeq($2, $5) }
			| ELSIF EOL expr EOL THEN stmt_seq { $$ = createElsifSeq($3, $6) }
			
			| elsif_seqE ELSIF EOL expr THEN stmt_seq { $$ = addToElsifSeq($1, $4, $6) }
			| elsif_seqE ELSIF expr EOL THEN stmt_seq { $$ = addToElsifSeq($1, $3, $6) }
			| elsif_seqE ELSIF EOL expr EOL THEN stmt_seq { $$ = addToElsifSeq($1, $4, $7) }

			| ELSIF expr THEN EOL stmt_seq { $$ = createElsifSeq($2, $5) }
			| ELSIF expr EOL THEN EOL stmt_seq { $$ = createElsifSeq($2, $6) }
			| ELSIF EOL expr THEN EOL stmt_seq { $$ = createElsifSeq($3, $6) }
			| ELSIF EOL expr EOL THEN EOL stmt_seq { $$ = createElsifSeq($3, $7) }

			| elsif_seqE ELSIF expr THEN EOL stmt_seq { $$ = addToElsifSeq($1, $3, $6) }
			| elsif_seqE ELSIF expr EOL THEN EOL stmt_seq { $$ = addToElsifSeq($1, $3, $7) }
			| elsif_seqE ELSIF EOL expr THEN EOL stmt_seq { $$ = addToElsifSeq($1, $4, $7) }
			| elsif_seqE ELSIF EOL expr EOL THEN EOL stmt_seq { $$ = addToElsifSeq($1, $4, $8) }
			;
			
if_stmt		: IF expr THEN stmt_seq elsif_seq END { $$ = createIfStmt($2, $4, $5, NULL) }
			| IF expr THEN stmt_seq elsif_seq ELSE stmt_seq END { $$ = createIfStmt($2, $4, $5, $7) }
			
			| IF EOL expr THEN stmt_seq elsif_seq END { $$ = createIfStmt($3, $5, $6, NULL) }
			| IF expr EOL THEN stmt_seq elsif_seq END { $$ = createIfStmt($2, $5, $6, NULL) }
			| IF EOL expr EOL THEN stmt_seq elsif_seq END { $$ = createIfStmt($3, $6, $7, NULL) }
			
			| IF EOL expr THEN stmt_seq elsif_seq ELSE stmt_seq END { $$ = createIfStmt($3, $5, $6, $8) }
			| IF expr EOL THEN stmt_seq elsif_seq ELSE stmt_seq END { $$ = createIfStmt($2, $5, $6, $8) }
			| IF EOL expr EOL THEN stmt_seq elsif_seq ELSE stmt_seq END { $$ = createIfStmt($3, $6, $7, $9) }
			
			| IF expr THEN EOL stmt_seq elsif_seq END { $$ = createIfStmt($2, $5, $6, NULL) }
			| IF EOL expr THEN EOL stmt_seq elsif_seq END { $$ = createIfStmt($3, $6, $7, NULL) }
			| IF expr EOL THEN EOL stmt_seq elsif_seq END { $$ = createIfStmt($2, $6, $7, NULL) }
			| IF EOL expr EOL THEN EOL stmt_seq elsif_seq END { $$ = createIfStmt($3, $7, $8, NULL) }
			
			| IF expr THEN stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($2, $4, $5, $8) }
			| IF expr THEN EOL stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($2, $5, $6, $9) }
			| IF expr EOL THEN stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($2, $5, $6, $9) }
			| IF EOL expr THEN stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($3, $5, $6, $9) }
			| IF EOL expr EOL THEN stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($3, $6, $7, $10) }
			| IF EOL expr THEN EOL stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($3, $6, $7, $10) }			
			| IF EOL expr EOL THEN EOL stmt_seq elsif_seq ELSE EOL stmt_seq END { $$ = createIfStmt($3, $7, $8, $11) }
			;

unless_stmt	: UNLESS expr THEN stmt_seq END { $$ = createUnlessStmt($2, $4, NULL) }
			| UNLESS expr THEN stmt_seq ELSE stmt_seq END { $$ = createUnlessStmt($2, $4, $6) }
			
			| UNLESS EOL expr THEN stmt_seq END { $$ = createUnlessStmt($3, $5, NULL) }
			| UNLESS expr EOL THEN stmt_seq END { $$ = createUnlessStmt($2, $5, NULL) }
			| UNLESS EOL expr EOL THEN stmt_seq END { $$ = createUnlessStmt($3, $6, NULL) }
			
			| UNLESS EOL expr THEN stmt_seq ELSE stmt_seq END { $$ = createUnlessStmt($3, $5, $7) }
			| UNLESS expr EOL THEN stmt_seq ELSE stmt_seq END { $$ = createUnlessStmt($2, $5, $7) }
			| UNLESS EOL expr EOL THEN stmt_seq ELSE stmt_seq END { $$ = createUnlessStmt($3, $6, $8) }
			
			| UNLESS expr THEN EOL stmt_seq END { $$ = createUnlessStmt($2, $5, NULL) }
			| UNLESS expr EOL THEN EOL stmt_seq END { $$ = createUnlessStmt($2, $6, NULL) }
			| UNLESS EOL expr THEN EOL stmt_seq END { $$ = createUnlessStmt($3, $6, NULL) }
			| UNLESS EOL expr EOL THEN EOL stmt_seq END { $$ = createUnlessStmt($3, $7, NULL) }
			
			| UNLESS expr THEN stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($2, $4, $7) }
			| UNLESS expr THEN EOL stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($2, $5, $8) }
			| UNLESS expr EOL THEN stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($2, $5, $8) }
			| UNLESS EOL expr THEN stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($3, $5, $8) }
			| UNLESS expr EOL THEN EOL stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($2, $6, $9) }
			| UNLESS EOL expr THEN EOL stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($3, $6, $9) }
			| UNLESS EOL expr EOL THEN EOL stmt_seq ELSE EOL stmt_seq END { $$ = createUnlessStmt($3, $7, $10) }
			;
			
%%
void yyerror(const char *s)
{
    printf("%s !",s);
}

