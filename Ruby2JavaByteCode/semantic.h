#ifndef SEMANTICSTRUCTURES_H
#define SEMANTICSTRUCTURES_H
#include <QString.h>
#include <qlinkedlist.h>
#include <QTextStream.h>
#include "SemanticTables.h"
#include "structures.h"

class AttributedNode;
class AttrProgram;
class AttrStmt;
class AttrClassDef;
class AttrMethodDef;
class AttrMethodDefParam;
class AttrCycleStmt;
class AttrExprStmt;
class AttrExpr;
class AttrBinExpr;
class AttrUnExpr;
class AttrClassPropertyAcc;
class AttrMethodCall;
class AttrFieldAcc;
class AttrConstExpr;

class SemanticAnalyzer
{
public:
    SemanticAnalyzer(ProgramNode* root);

    QHash<QString, SemanticClass*> classTable;
    QList<QString> errors;
    AttrProgram* root; 

    void doSemantics();
    void transform();
    void dotPrint(QTextStream & out);
    void generate();
};

class AttributedNode
{
public:
    virtual void doSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors) = 0;
    virtual void doFirstSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors, AttrStmt* parentStmt);
    virtual void dotPrint(QTextStream & out) = 0;
    virtual void transform();
    void dotPrintStmtSeq(QLinkedList<AttrStmt*> seq, QTextStream & out);
    void dotPrintExprSeq(QLinkedList<AttrExpr*> seq, QTextStream & out);
    static void fillStmtList(StmtSeqNode* seq, QLinkedList<AttrStmt*> & list);
};


class AttrStmt : public AttributedNode
{
public:
    StmtNodeType type;

    static AttrStmt* fromParserNode(StmtNode* node);
    virtual void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod);
    virtual QLinkedList<AttrStmt*>* getBody() = 0;
};


class AttrProgram : public AttributedNode
{
public:
    QLinkedList<AttrStmt*> body;

    static AttrProgram* fromParserNode(ProgramNode* node);
    void doSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors);
    void doFirstSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors, AttrStmt* parentStmt);
    void dotPrint(QTextStream & out);
    void transform();
};


class AttrClassDef : public AttrStmt
{
public:
    QString id;
    QString parentId;
    QLinkedList<AttrStmt*> body;

    static AttrClassDef* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors);
    void doFirstSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors, AttrStmt* parentStmt);
    void dotPrint(QTextStream & out);
    void transform();
    void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod);
    QLinkedList<AttrStmt*>* getBody();
};


class AttrMethodDef : public AttrStmt
{
public:
    QString id;
    QLinkedList<AttrMethodDefParam*> params;
    QLinkedList<AttrStmt*> body;
    bool isConstructor;
    bool isStatic;

    AttrMethodDef() { isConstructor = false; isStatic = false; }
    static AttrMethodDef* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void doFirstSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors, AttrStmt* parentStmt);
    void dotPrint(QTextStream & out);
    void generateCode(QDataStream & out, SemanticClass* curClass);
    QLinkedList<AttrStmt*>* getBody();
};


class AttrMethodDefParam : public AttributedNode
{
public:
    QString id;

    static AttrMethodDefParam* fromParserNode(MethodDefParamNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
};


class AttrCycleStmt : public AttrStmt
{
public:
    enum
    {
        cycleWhile,
        cycleUntil
    } cycleType;

    QLinkedList<AttrStmt*> block;
    AttrExpr* expr;

    static AttrCycleStmt* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void doFirstSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors, AttrStmt* parentStmt);
    void dotPrint(QTextStream & out);
    void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod);
    QLinkedList<AttrStmt*>* getBody();
};

class AttrReturnStmt : public AttrStmt
{
public:
    AttrExpr* expr;

    static AttrReturnStmt* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream & out, SemanticClass* curClass, SemanticMethod *curMethod);
    QLinkedList<AttrStmt*>* getBody();
};


class AttrExprStmt : public AttrStmt
{
public:
    AttrExpr* expr;

    static AttrExprStmt* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    virtual void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod);
    QLinkedList<AttrStmt*>* getBody();
};


class AttrExpr : public AttributedNode
{
public:
    ExprNodeType type;

    static AttrExpr* fromParserNode(ExprNode* node);
    virtual void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod* curMethod) = 0;
};


class AttrBinExpr : public AttrExpr
{
public:
    AttrExpr* left;
    AttrExpr* right;

    AttrExpr* third;
    QString id;

    static AttrBinExpr* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void transform();
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod);
};


class AttrUnExpr : public AttrExpr
{
public:
    AttrExpr* expr;

    static AttrUnExpr* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod);
};


class AttrClassPropertyAcc : public AttrExpr
{
public:
    QString id;
    AttrExpr* left;
};


class AttrMethodCall : public AttrClassPropertyAcc
{
public:
    QLinkedList<AttrExpr*> arguments;
    bool isObjectCreating;
    int constClass;
    int constMethodRef;

    AttrMethodCall() { isObjectCreating = false; };
    static AttrMethodCall* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod);
};


class AttrFieldAcc : public AttrClassPropertyAcc
{
public:
    int number;
    int constFieldRef;

    static AttrFieldAcc* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod);
    bool existsInParent(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass);
};

class AttrLocal : public AttrExpr
{
public:
    int number;
    QString id;

    static AttrLocal* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod);
};

class AttrConstExpr : public AttrExpr
{
public:

    QString str;
    int intValue;

    int constValue;

    static AttrConstExpr* fromParserNode(ExprNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod);
};
class AttrElsif : public AttributedNode
{
public:
    AttrExpr* expr;
    QLinkedList<AttrStmt*> block;

    static AttrElsif* fromParserNode(ElsifNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, 
		SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
};
class AttrIfStmt : public AttrStmt
{
public:
    AttrExpr* expr;
    QLinkedList<AttrStmt*> block;
    QLinkedList<AttrStmt*> elseBlock;
	QLinkedList<AttrElsif*> elsifBlock;

    static AttrIfStmt* fromParserNode(StmtNode* node);
    void doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors);
    void dotPrint(QTextStream & out);
    void generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod);
    QLinkedList<AttrStmt*>* getBody();
};
#endif // SEMANTICSTRUCTURES_H
