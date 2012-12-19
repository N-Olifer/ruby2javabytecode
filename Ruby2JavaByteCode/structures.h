#ifndef STRUCTURES_H
#define STRUCTURES_H


// ��� ���������
enum ExprNodeType
{
	eInt,
	eBool,
	eString,
	eAssign,
	ePlus,
	eMinus,
	eMul,
	eDiv,
	eLess,
	eMore,
	eOr,
	eAnd,
	eEqu,
	eNEqu,
	eNot,
	eUMinus,
	eBrackets,
	eQBrackets,
    eQBracketsLvalue,
	eQBracketsInit,
    eFieldAccRef,
	eFieldAcc,
    //eFieldAccAssign,
	eLocal,
    //eLocalAssign,
    eLocalRef,
    eLocalNewRef,
    eMethodCall,
	eSuper,
	eSelf,
    eNil

};

// ��� ���������
enum StmtNodeType
{
	eExpr,
	eIf,
	eWhile,
	eUnless,
	eUntil,
	eClassDef,
	eMethodDef,
	eReturn
};

// ���������
struct ExprNode
{
	enum ExprNodeType type; // ���
	
	int value; // �������� �������� (��� ����������)
	char* id; // ���
	char* str; // ������ (��� ��������� ���������)
	
	struct ExprNode* left; // ����� �������
	struct ExprNode* right; // ������ �������
	struct ExprSeqNode* list; // ������ ��������� (��� ������ �������)
	
	bool isStatic;
	
	struct ExprNode* next; // ��������� � ������
};

// ������������������ ���������
struct ExprSeqNode
{
	struct ExprNode* first; // ������ �������
	struct ExprNode* last; // ��������� �������
};

// ��������
struct StmtNode
{
	enum StmtNodeType type; // ���
	
	struct ExprNode* expr; // ���������
	struct StmtSeqNode* block; // ���� ����������
	
	char* id; // ������������� (��� ���������� ������� � �������)
	char* secondId; // ������ ������������� (��� ������������)
	struct MethodDefParamSeqNode* params; // ��������� ����������� �������
	
	struct StmtNode* next; // ��������� � ������
	
	struct StmtSeqNode *elseStmtBlock;	//���� ���������� ��� else � ��������� if
	struct ElsifSeqNode *elsifList;		//���� ���������� elsif � ��������� if
	
	bool isStatic;
};

// ������������������ ����������
struct StmtSeqNode
{
	struct StmtNode* first; // ������
	struct StmtNode* last; // ���������
};

// ������������������ ���������� � ���������� �������
struct MethodDefParamSeqNode
{
	struct MethodDefParamNode* first; // ������
	struct MethodDefParamNode* last;// ���������
};

// �������� � ���������� �������
struct MethodDefParamNode
{
	char* id; // �������������
	struct MethodDefParamNode* next; // ��������� � ������
};

// ������ ������
struct ProgramNode
{
	struct StmtSeqNode* body; // ���� ���� ���������
};

struct ElsifNode
{
	struct ExprNode *expr;
	struct StmtSeqNode *block;
	struct ElsifNode *next;
};

struct ElsifSeqNode
{
	struct ElsifNode *first;
	struct ElsifNode *last;
};

#endif 
