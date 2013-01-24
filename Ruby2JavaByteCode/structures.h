#ifndef STRUCTURES_H
#define STRUCTURES_H


// Тип выражения
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

// Тип оператора
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

// Выражение
struct ExprNode
{
	enum ExprNodeType type; // Тип
	
	int value; // Числовое значение (или логическое)
	char* id; // Имя
	char* str; // Строка (для строковых литералов)
	
	struct ExprNode* left; // Левый операнд
	struct ExprNode* right; // Правый операнд
	struct ExprSeqNode* list; // Список выражений (для вызова функции)
	
	bool isStatic;
	
	struct ExprNode* next; // Следующее в списке
};

// Последовательность выражений
struct ExprSeqNode
{
	struct ExprNode* first; // Первый элемент
	struct ExprNode* last; // Последний элемент
};

// Оператор
struct StmtNode
{
	enum StmtNodeType type; // Тип
	
	struct ExprNode* expr; // Выражение
	struct StmtSeqNode* block; // Блок операторов
	
	char* id; // Идентификатор (для объявлений классов и методов)
	char* secondId; // Второй идентификатор (для наследования)
	struct MethodDefParamSeqNode* params; // Параметры объявляемой функции
	
	struct StmtNode* next; // Следующий в списке
	
	struct StmtSeqNode *elseStmtBlock;	//Блок операторов для else в операторе if
	struct ElsifSeqNode *elsifList;		//Блок операторов elsif в операторе if
	
	bool isStatic;
};

// Последовательность операторов
struct StmtSeqNode
{
	struct StmtNode* first; // Первый
	struct StmtNode* last; // Последний
};

// Последовательность параметров в объявлении функции
struct MethodDefParamSeqNode
{
	struct MethodDefParamNode* first; // Первый
	struct MethodDefParamNode* last;// Последний
};

// Параметр в объявлении фукнции
struct MethodDefParamNode
{
	char* id; // Идентификатор
	struct MethodDefParamNode* next; // Следующий в списке
};

// Корень дерева
struct ProgramNode
{
	struct StmtSeqNode* body; // Тело всей программы
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
