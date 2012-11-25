#ifndef SEMANTICSTRUCTURES_H
#define SEMANTICSTRUCTURES_H
#include <QString.h>
#include <qlinkedlist.h>
#include <QTextStream.h>>
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


class Semantics
{
public:
    Semantics(ProgramNode* root);

    AttrProgram* root;
    QHash<QString, SemanticClass> classTable;

    static void fillStmtList(StmtSeqNode* seq, QLinkedList<AttrStmt*> & list);
    void doSemantics();
    void dotPrint(QTextStream & out);
};

class AttributedNode
{
public:
    virtual void check() = 0;
    virtual void doSemantics() = 0;
    virtual void dotPrint(QTextStream & out) = 0;
    void dotPrintStmtSeq(QLinkedList<AttrStmt*> seq, QTextStream & out);
    void dotPrintExprSeq(QLinkedList<AttrExpr*> seq, QTextStream & out);
};


class AttrStmt : public AttributedNode
{
public:
    static AttrStmt* fromParserNode(StmtNode* node);

};


class AttrProgram : public AttributedNode
{
public:
    QLinkedList<AttrStmt*> body;

    static AttrProgram* fromParserNode(ProgramNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrClassDef : public AttrStmt
{
public:
    QString id;
    QString parentId;
    QLinkedList<AttrStmt*> body;

    static AttrClassDef* fromParserNode(StmtNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrMethodDef : public AttrStmt
{
public:
    QString id;
    QLinkedList<AttrMethodDefParam*> params;
    QLinkedList<AttrStmt*> body;

    static AttrMethodDef* fromParserNode(StmtNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrMethodDefParam : public AttributedNode
{
public:
    QString id;

    static AttrMethodDefParam* fromParserNode(MethodDefParamNode* node);
    void check();
    void doSemantics();
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
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};

class AttrReturnStmt : public AttrStmt
{
public:
    AttrExpr* expr;

    static AttrReturnStmt* fromParserNode(StmtNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrExprStmt : public AttrStmt
{
public:
    AttrExpr* expr;

    static AttrExprStmt* fromParserNode(StmtNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrExpr : public AttributedNode
{
public:
    ExprNodeType type;

    static AttrExpr* fromParserNode(ExprNode* node);
};


class AttrBinExpr : public AttrExpr
{
public:
    AttrExpr* left;
    AttrExpr* right;

    static AttrBinExpr* fromParserNode(ExprNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrUnExpr : public AttrExpr
{
public:
    AttrExpr* expr;

    static AttrUnExpr* fromParserNode(ExprNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
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

    static AttrMethodCall* fromParserNode(ExprNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrFieldAcc : public AttrClassPropertyAcc
{
public:
    int number;

    static AttrFieldAcc* fromParserNode(ExprNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};


class AttrConstExpr : public AttrExpr
{
public:

    QString str;
    int value;

    static AttrConstExpr* fromParserNode(ExprNode* node);
    void check();
    void doSemantics();
    void dotPrint(QTextStream & out);
};



#endif // SEMANTICSTRUCTURES_H
