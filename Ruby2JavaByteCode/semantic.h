//#ifndef SEMANTICSTRUCTURES_H
//#define SEMANTICSTRUCTURES_H
//#include <QString.h>
//#include <qlinkedlist.h>
//#include <QTextStream.h>>
//#include "SemanticTables.h"

//class AttributedNode;
//class AttrProgramNode;
//class AttrStmt;
//class AttrClassDef;
//class AttrMethodDefStmt;
//class AttrMethodDefParam;
//class AttrCycleStmt;
//class AttrExpr;
//class AttrBinExpr;
//class AttrUnExpr;
//class AttrClassPropertyAcc;
//class AttrMethodCall;
//class AttrFieldAcc;
//class AttrConstExpr;


//class Semantics
//{
//public:
//    AttrProgramNode* root;
//    QHash<QString,TableClass> classTable;

//    void doSemantics();
//};

//class AttributedNode
//{
//public:
//    virtual void check() = 0;
//    virtual void doSemantics() = 0;
//    virtual void fromStructure(void* structure) = 0;
//    virtual void dotPrint(QTextStream & out) = 0;
//};


//class AttrStmt : public AttributedNode
//{
//public:

//};


//class AttrProgramNode : public AttributedNode
//{
//public:
//    QLinkedList<AttrStmt*> body;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrClassDef : public AttrStmt
//{
//public:
//    QString id;
//    QString parentId;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrMethodDefStmt : public AttrStmt
//{
//public:
//    QString id;
//    QLinkedList<AttrMethodDefParam*> params;
//    QLinkedList<AttrStmt*> block;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrMethodDefParam : public AttributedNode
//{
//    QString id;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrCycleStmt : public AttrStmt
//{
//public:
//    QLinkedList<AttrStmt*> block;
//    AttrExpr* expr;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrExpr : public AttributedNode
//{
//public:
//    //enum ExprNodeType type; // Тип
//    int value;
//    QString str;
//    QLinkedList<AttrExpr*> list;
//};


//class AttrBinExpr : public AttrExpr
//{
//public:
//    AttrExpr* left;
//    AttrExpr* right;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrUnExpr : public AttrExpr
//{
//public:
//    AttrExpr* expr;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrClassPropertyAcc : public AttrExpr
//{
//public:
//    QString id;
//    AttrExpr* left;

//};


//class AttrMethodCall : public AttrClassPropertyAcc
//{
//public:
//    QLinkedList<AttrExpr*> arguments;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrFieldAcc : public AttrClassPropertyAcc
//{
//public:
//    int number;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};


//class AttrConstExpr : public AttrExpr
//{
//public:
//    enum
//    {
//        tInt,
//        tStr,
//        tBool
//    } type;

//    QString str;
//    int value;

//    void check();
//    void doSemantics();
//    void fromStructure(void* structure);
//    void dotPrint(QTextStream & out);
//};



//#endif // SEMANTICSTRUCTURES_H
