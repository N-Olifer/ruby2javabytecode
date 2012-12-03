
#include "semantic.h"
#include "structures.h"
#include "test.h"

SemanticAnalyzer::SemanticAnalyzer(ProgramNode* root)
{
    this->root = AttrProgram::fromParserNode(root);
}

void SemanticAnalyzer::doSemantics()
{
    //Создание общего предка
    SemanticClass* commonClass = new SemanticClass();
    commonClass->id = NAME_COMMON_CLASS;
    commonClass->parentId = NAME_JAVA_OBJECT;
    commonClass->constClass = commonClass->addConstantClass(QString(NAME_COMMON_CLASS));
    commonClass->constParent = commonClass->addConstantClass(QString(NAME_JAVA_OBJECT));
    SemanticMethod* constr = new SemanticMethod();
    constr->id = NAME_DEFAULT_CONSTRUCTOR;
    commonClass->methods.insert(constr->id, constr);

    constr->constName = commonClass->addConstantUtf8(QString(NAME_DEFAULT_CONSTRUCTOR));
    constr->constDesc = commonClass->addConstantUtf8(QString("()V"));


    classTable.insert(commonClass->id, commonClass);
    root->doSemantics(classTable, NULL, NULL, errors);
}


void SemanticAnalyzer::dotPrint(QTextStream & out)
{
    out << QString("digraph G{ node[shape=\"rectangle\",style=\"rounded, filled\",fillcolor=\"white\"] \n");
    root->dotPrint(out);
    out << QString("}");
}

void AttributedNode::fillStmtList(StmtSeqNode* seq, QLinkedList<AttrStmt*> & list)
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

void AttributedNode::transform()
{
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

void AttrProgram::doSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors)
{
    transform();
    body.first()->doSemantics(classTable, NULL, NULL, errors);
}

AttrProgram* AttrProgram::fromParserNode(ProgramNode* node)
{
    AttrProgram* result = new AttrProgram();
    AttributedNode::fillStmtList(node->body, result->body);
    return result;
}

void AttrProgram::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + QString("[label = \"Program\"]") + QString("\n");
    dotPrintStmtSeq(body, out);
}

void AttrProgram::transform()
{
    AttrClassDef* mainClass = new AttrClassDef();
    mainClass->id = NAME_MAIN_CLASS;
    mainClass->parentId = NAME_JAVA_OBJECT;

    AttrMethodDef* mainMethod = new AttrMethodDef();
    mainMethod->id = NAME_MAIN_CLASS_METHOD;
    mainMethod->params << new AttrMethodDefParam();
    mainMethod->params.first()->id = "argv";
    mainClass->body << mainMethod;
    mainMethod->body << body;

    body.clear();
    body << mainClass;
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
    AttributedNode::fillStmtList(node->block, result->body);
    return result;
}

void AttrClassDef::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> & errors)
{
    // Проверка переопределения
    if(classTable.contains(id))
    {
        errors << "Class redefinition: " + id + ".";
        return;
    }
    if(!id[0].isUpper() && id[0].isLetter())
    {
        errors << "Incorrect class name: " + id + ".";
        return;
    }

    transform();

    SemanticClass* semClass = new SemanticClass();

    semClass->id = id;
    semClass->parentId = parentId;
    semClass->constClass = semClass->addConstantClass(id);

    classTable.insert(id, semClass);

    // Проверка существования родителя
    if(parentId != NAME_COMMON_CLASS && parentId != NAME_JAVA_OBJECT)
    {
        if(!classTable.contains(parentId))
        {
            errors << "Parent class " + parentId + " of " + id + " not found.";
            return;
        }
    }
    semClass->constParent = semClass->addConstantClass(parentId);



    foreach(AttrStmt* stmt, body)
        stmt->doSemantics(classTable, semClass, NULL, errors);

    // Проверка существования конструктора
    if(!semClass->methods.contains(id))
    {
        AttrMethodDef* defaultConstructor = new AttrMethodDef();
        defaultConstructor->id = NAME_DEFAULT_CONSTRUCTOR;
        defaultConstructor->isConstructor = true;

        AttrExprStmt* stmt = new AttrExprStmt();
        AttrMethodCall* superCall = new AttrMethodCall();
        superCall->id = "super";
        superCall->left = NULL;
        stmt->expr = superCall;

        defaultConstructor->body << stmt;

        defaultConstructor->doSemantics(classTable, semClass, NULL, errors);
    }
}

void AttrClassDef::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label = \"class " + id + "\"]" + QString("\n");
    dotPrintStmtSeq(body, out);
}

void AttrClassDef::transform()
{
    if(parentId.isEmpty())
        parentId = NAME_COMMON_CLASS;
}

AttrMethodDef* AttrMethodDef::fromParserNode(StmtNode* node)
{
    AttrMethodDef* result = new AttrMethodDef();
    result->id = node->id;
    AttributedNode::fillStmtList(node->block, result->body);
    MethodDefParamNode* current = node->params->first;
    while(current)
    {
        result->params << AttrMethodDefParam::fromParserNode(current);
        current = current->next;
    }
    return result;
}

void AttrMethodDef::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> & errors)
{
    if(curClass->methods.contains(id))
    {
        errors << QString("Method already defined: " + id);
        return;
    }
    SemanticMethod* newMethod = new SemanticMethod();
    newMethod->id = id;
    if(curClass->id == id)
        isConstructor = true;

    QString desc("(");
    int count = params.count();
    for(int  i = 0; i < count; i++)
        desc += DESC_COMMON_CLASS;
    desc += QString(")");
    if(isConstructor)
        desc += "V";
    else
        desc += DESC_COMMON_CLASS;

    newMethod->constName = curClass->addConstantUtf8(id);
    newMethod->constDesc = curClass->addConstantUtf8(desc);

    // Добавление метода в общего родителя
    SemanticClass* commonClass = classTable.value(QString(NAME_COMMON_CLASS));

    SemanticMethod* newMethodC = new SemanticMethod();
    newMethodC->id = id;
    newMethodC->constName = commonClass->addConstantUtf8(id);
    newMethodC->constDesc = commonClass->addConstantUtf8(desc);

    commonClass->methods.insert(id, newMethodC);

    curClass->methods.insert(id, newMethod);

    newMethod->paramCount = params.count();
    foreach(AttrMethodDefParam* param, params)
        param->doSemantics(classTable, curClass, newMethod, errors);
    foreach(AttrStmt* stmt, body)
        stmt->doSemantics(classTable, curClass, newMethod, errors);
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


void AttrMethodDefParam::doSemantics(QHash<QString, SemanticClass*> & classTable, SemanticClass* curClass, SemanticMethod* curMethod, QList<QString> & errors)
{
    curMethod->addLocalVar(id, curClass);
}

void AttrMethodDefParam::dotPrint(QTextStream & out)
{
    out << QString::number((int)this) + "[label=\"" + id + "\"]" + QString("\n");
}

AttrCycleStmt* AttrCycleStmt::fromParserNode(StmtNode* node)
{
    AttrCycleStmt* result = new AttrCycleStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    AttributedNode::fillStmtList(node->block, result->block);
    if( node->type == eWhile)
        result->cycleType = cycleWhile;
    else
        result->cycleType = cycleUntil;
    return result;
}


void AttrCycleStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    expr->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrStmt* stmt, block)
        stmt->doSemantics(classTable, curClass, curMethod, errors);
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


void AttrReturnStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    expr->doSemantics(classTable, curClass, curMethod, errors);
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


void AttrExprStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    expr->doSemantics(classTable, curClass, curMethod, errors);
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
    case eSuper:
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

void AttrBinExpr::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    transform();

    if(type == eAssign && left->type != eFieldAccAssign)
    {
        errors << "Not lvalue left of \"=\"";
        return;
    }
    if(left)
        left->doSemantics(classTable, curClass, curMethod, errors);
    right->doSemantics(classTable, curClass, curMethod, errors);
}

void AttrBinExpr::dotPrint(QTextStream & out)
{
    transform();
    if(type == eFieldAccAssign)
        out << QString::number((int)this) + "[label=\" = " + id + "\"]" + QString("\n");
    else
    {
        char str[25];
        exprTypeToStr(type, str);
        out << QString::number((int)this) + "[label=\"" + str + "\"]" + QString("\n");
    }
    if(left)
        left->dotPrint(out);
    right->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)left) + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)right) + QString("\n");
}

void AttrBinExpr::transform()
{
    if(type == eAssign)
    {
        if(left->type == eFieldAcc)
        {
            type = eFieldAccAssign;
            AttrExpr* newLeft;
            newLeft = ((AttrFieldAcc*)left)->left;
            id = ((AttrFieldAcc*)left)->id;
            delete left;
            left = newLeft;
        }
        // TODO array
    }
}

AttrUnExpr* AttrUnExpr::fromParserNode(ExprNode* node)
{
    AttrUnExpr* result = new AttrUnExpr();
    result->expr = AttrExpr::fromParserNode(node->left);
    result->type = node->type;
    return result;
}

void AttrUnExpr::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    transform();
    if(expr->type == eBool || expr->type == eString)
    {
        errors << "Incorrect type with uMinus";
        return;
    }
    expr->doSemantics(classTable, curClass, curMethod, errors);
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

void AttrMethodCall::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(left)
    {
        QString leftId = ((AttrFieldAcc*)left)->id;
        if(left->type == eFieldAcc && id == "new" && leftId[0].isUpper())
        {
            if(!classTable.contains(leftId))
            {
                errors << "Class doesn't exist when creating object: " + id;
                return;
            }
            isObjectCreating = true;
            //constClass = curClass->addConstantClass(id);
        }
        else
        {
            isObjectCreating = false;
            //constClass = EMPTY_CONST_NUMBER;
        }

        QString desc("(");
        int count = arguments.count();
        for(int  i = 0; i < count; i++)
            desc += DESC_COMMON_CLASS;
        desc += QString(")");

        if(!isObjectCreating)
            desc += DESC_COMMON_CLASS;
        else
            desc += "V";

        bool methodFound = false;
        foreach(SemanticClass* semClass, classTable)
            foreach(SemanticMethod* method, semClass->methods)
                if(method->id == id && method->paramCount == arguments.count())
                {
                    if(isObjectCreating)
                        constMethodRef = curClass->addConstantMethodRef(leftId, id, desc);
                    else
                        constMethodRef = curClass->addConstantMethodRef(QString(NAME_COMMON_CLASS), id, desc);
                    methodFound = true;
                }
        if(!methodFound)
        {
            errors << "Method not exists: " + id;
            return;
        }
        left->doSemantics(classTable, curClass, curMethod, errors);
    }
    if(id == "super")
    {
        if(classTable.contains(curClass->parentId) && !classTable.value(curClass->parentId)->methods.contains(curMethod->id))
            errors << "Parent class doesn't have method:" + curMethod->id;
    }
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



void AttrFieldAcc::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(left != NULL)
    {
        left->doSemantics(classTable, curClass, curMethod, errors);
    }
    else
    {
        if(id.left(1) != QString("@"))
            curMethod->addLocalVar(id, curClass);
        else
        {
            curClass->addField(id);
            constFieldRef = curClass->addConstantFieldRef(curClass->id, id, QString(DESC_COMMON_CLASS));
        }
    }
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

void AttrConstExpr::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(type == eInt && value > VALUE_MAX2BIT)
    {
        constValue = curClass->addConstantInteger(value);
    }
    else if(type == eString)
    {
        constValue = curClass->addConstantString(str);
    }
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
