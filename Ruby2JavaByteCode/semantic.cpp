
#include "semantic.h"
#include "structures.h"
#include "test.h"

Semantics::Semantics(ProgramNode* root)
{
    this->root = AttrProgram::fromParserNode(root);
}

void Semantics::fillStmtList(StmtSeqNode* seq, QLinkedList<AttrStmt*> & list)
{
    if(seq)
    {
        StmtNode* current = seq->first;
        while(current)
        {
            list << AttrStmt::fromParserNode(current);
            current = current->next;
        }
    }
}

void Semantics::doSemantics()
{
    root->doSemantics();
}

void Semantics::dotPrint(QTextStream & out)
{
    out << QString("digraph G{ node[shape=\"rectangle\",style=\"rounded, filled\",fillcolor=\"white\"] \n");
    root->dotPrint(out);
    out << QString("}");
}

void AttributedNode::dotPrintStmtSeq(QLinkedList<AttrStmt*> seq, QTextStream & out)
{
    out << QString::number((int)this + 1) + "[label = \"stmt seq\"]" + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)this + 1) + QString("\n");
    foreach(AttrStmt* stmt, seq)
    {
        stmt->dotPrint(out);
        out << QString::number((int)this + 1) + "->" + QString::number((int)stmt) + QString("\n");
    }
}

void AttributedNode::dotPrintExprSeq(QLinkedList<AttrExpr*> seq, QTextStream & out)
{
    out << QString::number((int)this + 1) + "[label = \"expr seq\"]" + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)this + 1) + QString("\n");
    foreach(AttrExpr* expr, seq)
    {
        expr->dotPrint(out);
        out << QString::number((int)this + 1) + "->" + QString::number((int)expr) + QString("\n");
    }
}

void AttrProgram::check()
{

}

void AttrProgram::doSemantics()
{

}

AttrProgram* AttrProgram::fromParserNode(ProgramNode* node)
{
    AttrProgram* result = new AttrProgram();
    Semantics::fillStmtList(node->body, result->body);
    return result;
}

void AttrProgram::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + QString("[label=Program]") + QString("\n");
    dotPrintStmtSeq(body, out);
}

AttrStmt* AttrStmt::fromParserNode(StmtNode* node)
{
    switch(node->type)
    {
    case eExpr:
        return AttrExprStmt::fromParserNode(node);
    case eWhile:
    case eUntil:
        return AttrCycleStmt::fromParserNode(node);
    case eClassDef:
        return AttrClassDef::fromParserNode(node);
    case eMethodDef:
        return AttrMethodDef::fromParserNode(node);
    case eReturn:
        return AttrReturnStmt::fromParserNode(node);
    }
}

AttrClassDef* AttrClassDef::fromParserNode(StmtNode* node)
{
    AttrClassDef* result = new AttrClassDef();
    result->id = node->id;
    result->parentId = node->secondId;
    Semantics::fillStmtList(node->block, result->body);
    return result;
}

void AttrClassDef::check()
{

}

void AttrClassDef::doSemantics()
{

}

void AttrClassDef::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label = \"class " + id + "\"]" + QString("\n");
    dotPrintStmtSeq(body, out);
}

AttrMethodDef* AttrMethodDef::fromParserNode(StmtNode* node)
{
    AttrMethodDef* result = new AttrMethodDef();
    result->id = node->id;
    Semantics::fillStmtList(node->block, result->body);
    MethodDefParamNode* current = node->params->first;
    while(current)
    {
        result->params << AttrMethodDefParam::fromParserNode(current);
        current = current->next;
    }
    return result;
}

void AttrMethodDef::check()
{

}

void AttrMethodDef::doSemantics()
{

}

void AttrMethodDef::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label = \"method " + id + "\"]" + QString("\n");
    dotPrintStmtSeq(body, out);

    out << QString::number((int)this + 2) + "[label = \"param seq\"]" + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)this + 2) + QString("\n");
    foreach(AttrMethodDefParam* param, params)
    {
        param->dotPrint(out);
        out << QString::number((int)this + 2) + "->" + QString::number((int)param) + QString("\n");
    }
}

AttrMethodDefParam* AttrMethodDefParam::fromParserNode(MethodDefParamNode* node)
{
    AttrMethodDefParam* result = new AttrMethodDefParam();
    result->id = node->id;
    return result;
}

void AttrMethodDefParam::check()
{

}

void AttrMethodDefParam::doSemantics()
{

}

void AttrMethodDefParam::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label=\"" + id + "\"]" + QString("\n");
}

AttrCycleStmt* AttrCycleStmt::fromParserNode(StmtNode* node)
{
    AttrCycleStmt* result = new AttrCycleStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    Semantics::fillStmtList(node->block, result->block);
    if( node->type == eWhile)
        result->cycleType = cycleWhile;
    else
        result->cycleType = cycleUntil;
    return result;
}

void AttrCycleStmt::check()
{

}

void AttrCycleStmt::doSemantics()
{

}

void AttrCycleStmt::dotPrint(QTextStream & out)
{
    QString label;
    if(cycleType == cycleWhile)
        label = "while";
    else
        label = "until";
    out << QString::number((int)this) + "[label = \"" + label +"\"]" + QString("\n");
    dotPrintStmtSeq(block, out);
    expr->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
}


AttrReturnStmt* AttrReturnStmt::fromParserNode(StmtNode* node)
{
    AttrReturnStmt* result = new AttrReturnStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    return result;
}

void AttrReturnStmt::check()
{

}

void AttrReturnStmt::doSemantics()
{

}

void AttrReturnStmt::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label = \"return\"]" + QString("\n");
    if(expr)
    {
        expr->dotPrint(out);
        out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
    }
}

AttrExprStmt* AttrExprStmt::fromParserNode(StmtNode* node)
{
    AttrExprStmt* result = new AttrExprStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    return result;
}

void AttrExprStmt::check()
{

}

void AttrExprStmt::doSemantics()
{

}

void AttrExprStmt::dotPrint(QTextStream & out)
{
    expr->dotPrint(out);
    out << QString::number((int)this) + "[label=\"expr stmt\"]" + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
}

AttrExpr* AttrExpr::fromParserNode(ExprNode* node)
{
    if(!node)
        return NULL;
    switch(node->type)
    {
    case eInt:
    case eBool:
    case eString:
        return AttrConstExpr::fromParserNode(node);
    case eFieldAcc:
        return AttrFieldAcc::fromParserNode(node);
    case eMethodCall:
        return AttrMethodCall::fromParserNode(node);
    case eAssign:
    case ePlus:
    case eMinus:
    case eMul:
    case eDiv:
    case eLess:
    case eMore:
    case eOr:
    case eAnd:
    case eEqu:
    case eNEqu:
        return AttrBinExpr::fromParserNode(node);
    case eNot:
    case eUMinus:
    case eBrackets:
        return AttrUnExpr::fromParserNode(node);
    }
}

AttrBinExpr* AttrBinExpr::fromParserNode(ExprNode* node)
{
    AttrBinExpr* result = new AttrBinExpr();
    result->left = AttrExpr::fromParserNode(node->left);
    result->right = AttrExpr::fromParserNode(node->right);
    result->type = node->type;
    return result;
}

void AttrBinExpr::check()
{

}

void AttrBinExpr::doSemantics()
{

}

void AttrBinExpr::dotPrint(QTextStream & out)
{
    char str[25];
    exprTypeToStr(type, str);
    out << QString::number((int)this) + "[label=\"" + str + "\"]" + QString("\n");
    left->dotPrint(out);
    right->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)left) + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)right) + QString("\n");
}

AttrUnExpr* AttrUnExpr::fromParserNode(ExprNode* node)
{
    AttrUnExpr* result = new AttrUnExpr();
    result->expr = AttrExpr::fromParserNode(node->left);
    result->type = node->type;
    return result;
}

void AttrUnExpr::check()
{

}

void AttrUnExpr::doSemantics()
{

}

void AttrUnExpr::dotPrint(QTextStream & out)
{
    char str[25];
    exprTypeToStr(type, str);
    out << QString::number((int)this) + "[label=\"" + str + "\"]" + QString("\n");
    expr->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
}

AttrMethodCall* AttrMethodCall::fromParserNode(ExprNode* node)
{
    AttrMethodCall* result = new AttrMethodCall();
    result->type = node->type;
    result->id = node->id;

    if(node->list)
    {
        ExprNode* current = node->list->first;
        while(current)
        {
            result->arguments << AttrExpr::fromParserNode(current);
            current = current->next;
        }
    }
    result->left = AttrExpr::fromParserNode(node->left);
    return result;
}

void AttrMethodCall::check()
{

}

void AttrMethodCall::doSemantics()
{

}

void AttrMethodCall::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label=\" method call: " + id + "\"]" + QString("\n");

    dotPrintExprSeq(arguments, out);
    if(left != NULL)
    {
        left->dotPrint(out);
        out << QString::number((int)this) + "->" + QString::number((int)left) + QString("\n");
    }
}

AttrFieldAcc* AttrFieldAcc::fromParserNode(ExprNode* node)
{
    AttrFieldAcc* result = new AttrFieldAcc();
    result->id = node->id;
    result->type = node->type;
    result->left = AttrExpr::fromParserNode(node->left);
    return result;
}

void AttrFieldAcc::check()
{

}

void AttrFieldAcc::doSemantics()
{

}

void AttrFieldAcc::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label=\" field access: " + id + "\"]" + QString("\n");
    if(left != NULL)
    {
        left->dotPrint(out);
        out << QString::number((int)this) + "->" + QString::number((int)left) + QString("\n");
    }
}

AttrConstExpr* AttrConstExpr::fromParserNode(ExprNode* node)
{
    AttrConstExpr* result = new AttrConstExpr();
    result->str = node->str;
    result->value = node->value;
    result->type = node->type;
    return result;
}

void AttrConstExpr::check()
{

}

void AttrConstExpr::doSemantics()
{

}

void AttrConstExpr::dotPrint(QTextStream & out)
{
    QString label;
    switch(type)
    {
    case eInt:
        label = QString::number(value);
        break;
    case eBool:
        if(value)
            label = QString("true");
        else
            label = QString("false");
        break;
    case eString:
        label = str;
        break;
    }
    out << QString::number((int)this) + "[label=\"" + label + "\"]" + QString("\n");
}
