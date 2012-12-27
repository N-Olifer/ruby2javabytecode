
#include "semantic.h"
#include "structures.h"
#include "test.h"
#include <QFile>
#include <QDataStream>
#include "CodeCommands.h"

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
    commonClass->addRTLConstants();
    //SemanticMethod* constr = new SemanticMethod();
    //constr->id = NAME_DEFAULT_CONSTRUCTOR;
    //commonClass->methods.insert(constr->id, constr);
    //constr->constName = commonClass->addConstantUtf8(QString(NAME_DEFAULT_CONSTRUCTOR));
    //constr->constDesc = commonClass->addConstantUtf8(QString("()V"));

    AttrMethodDef* defaultConstructor = new AttrMethodDef();
    defaultConstructor->id = NAME_DEFAULT_CONSTRUCTOR;
    defaultConstructor->isConstructor = true;

    AttrExprStmt* stmt = new AttrExprStmt();
    AttrMethodCall* superCall = new AttrMethodCall();
    superCall->id = NAME_SUPER_METHOD;
    superCall->left = NULL;
    stmt->expr = superCall;
    stmt->expr->type = eMethodCall;
    defaultConstructor->body << stmt;

    defaultConstructor->doFirstSemantics(classTable, commonClass, NULL, errors, NULL);
    defaultConstructor->doSemantics(classTable, commonClass, NULL, errors);


    classTable.insert(commonClass->id, commonClass);
    root->doFirstSemantics(classTable, NULL, NULL, errors, NULL);
    root->doSemantics(classTable, NULL, NULL, errors);
}


void SemanticAnalyzer::dotPrint(QTextStream & out)
{
    out << QString("digraph G{ node[shape=\"rectangle\",style=\"rounded, filled\",fillcolor=\"white\"] \n");
    root->dotPrint(out);
    out << QString("}");
}

void SemanticAnalyzer::generate()
{
    foreach(SemanticClass* semClass, classTable)
        semClass->generate();
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

void AttributedNode::doFirstSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors, AttrStmt *parentStmt)
{
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

    body.first()->doSemantics(classTable, NULL, NULL, errors);
}

void AttrProgram::doFirstSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors, AttrStmt* parentStmt)
{
    transform();
    body.first()->doFirstSemantics(classTable, NULL, NULL, errors, parentStmt);
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
    mainClass->parentId = NAME_COMMON_CLASS;

    AttrMethodDef* mainMethod = new AttrMethodDef();
    mainMethod->id = NAME_MAIN_CLASS_METHOD;
    mainMethod->params << new AttrMethodDefParam();
    mainMethod->params.first()->id = "argv";
    mainMethod->isStatic = true;
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
	case eIf:
		return AttrIfStmt::fromParserNode(node);
    }
}

void AttrStmt::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
}

AttrClassDef* AttrClassDef::fromParserNode(StmtNode* node)
{
    AttrClassDef* result = new AttrClassDef();
    result->id = node->id;
    result->parentId = node->secondId;
    result->type = node->type;
    AttributedNode::fillStmtList(node->block, result->body);
    return result;
}

void AttrClassDef::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> & errors)
{

    if(!id[0].isUpper() && id[0].isLetter())
    {
        errors << "Incorrect class name: " + id + ".";
        return;
    }
    //if(curClass->id != NAME_MAIN_CLASS && curMethod->id != NAME_MAIN_CLASS_METHOD)
    //{
    //    errors << "Class definition in wrong place: " + id + ".";
    //    return;
   // }

    transform();

    SemanticClass* semClass = classTable.value(id);

    semClass->addRTLConstants();

    //semClass->id = id;
    semClass->parentId = parentId;
    semClass->constClass = semClass->addConstantClass(id);



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


}

void AttrClassDef::doFirstSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors, AttrStmt *parentStmt)
{
    // Проверка переопределения
    if(classTable.contains(id))
    {
        errors << "Class redefinition: " + id + ".";
        return;
    }

    SemanticClass* semClass = new SemanticClass();
    semClass->id = id;
    semClass->classDef = this;
    classTable.insert(id, semClass);

    // Перемещение определения класса в тело класса
    if(parentStmt)
    {
        QLinkedList<AttrStmt*>* parentBody = parentStmt->getBody();
        parentBody->removeOne(this);
        curClass->classDef->getBody()->append(this);
    }

    foreach(AttrStmt* stmt, body)
        stmt->doFirstSemantics(classTable, semClass, NULL, errors, this);

    // Проверка существования конструктора
    if(!semClass->methods.contains(id) && id != NAME_MAIN_CLASS)
    {
        AttrMethodDef* defaultConstructor = new AttrMethodDef();
        defaultConstructor->id = NAME_DEFAULT_CONSTRUCTOR;
        defaultConstructor->isConstructor = true;

        AttrExprStmt* stmt = new AttrExprStmt();
        AttrMethodCall* superCall = new AttrMethodCall();
        superCall->id = NAME_SUPER_METHOD;
        superCall->left = NULL;
        stmt->expr = superCall;
        stmt->expr->type = eMethodCall;

        defaultConstructor->body << stmt;

        defaultConstructor->doFirstSemantics(classTable, semClass, NULL, errors, this);
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

void AttrClassDef::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
}

QLinkedList<AttrStmt *> *AttrClassDef::getBody()
{
    return &body;
}

AttrMethodDef* AttrMethodDef::fromParserNode(StmtNode* node)
{
    AttrMethodDef* result = new AttrMethodDef();
    result->id = node->id;
    AttributedNode::fillStmtList(node->block, result->body);
    MethodDefParamNode* current = node->params->first;
    result->isStatic = node->isStatic;
    while(current)
    {
        result->params << AttrMethodDefParam::fromParserNode(current);
        current = current->next;
    }
    result->type = node->type;
    result->id += QString::number(result->params.count());
    return result;
}

void AttrMethodDef::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> & errors)
{

    SemanticMethod* newMethod = curClass->methods.value(id);
    newMethod->methodDef = this;


    if(curClass->id == id)
        isConstructor = true;
    if(curClass->id == NAME_MAIN_CLASS)
        isStatic = true;

    QString desc;
    if(curClass->id == NAME_MAIN_CLASS && id == NAME_MAIN_CLASS_METHOD)
        desc = DESC_MAIN_CLASS_METHOD;
    else
    {
        desc = QString("(");
        int count = params.count();
        for(int  i = 0; i < count; i++)
            desc += DESC_COMMON_VALUE;
        desc += QString(")");
        if(isConstructor)
            desc += "V";
        else
            desc += DESC_COMMON_VALUE;
    }


    newMethod->constName = curClass->addConstantUtf8(id);
    newMethod->constDesc = curClass->addConstantUtf8(desc);
    newMethod->constCode = curClass->addConstantUtf8(QString(ATTR_CODE));

    // Добавление метода в общего родителя
    //if(curClass->id != NAME_MAIN_CLASS)
    //{
    SemanticMethod* newMethodC;
    if(!isStatic && !isConstructor)
    {
        SemanticClass* commonClass = classTable.value(QString(NAME_COMMON_CLASS));

        newMethodC = new SemanticMethod();
        newMethodC->id = id;
        newMethodC->constName = commonClass->addConstantUtf8(id);
        newMethodC->constDesc = commonClass->addConstantUtf8(desc);
        newMethodC->constCode = commonClass->addConstantUtf8(QString(ATTR_CODE));
        newMethodC->methodDef = this;

        commonClass->methods.insert(id, newMethodC);
    }

    foreach(AttrMethodDefParam* param, params)
        param->doSemantics(classTable, curClass, newMethod, errors);

    // Поправка return
    if(body.isEmpty())
    {
        AttrReturnStmt* newLast = new AttrReturnStmt();
        AttrConstExpr* value = new AttrConstExpr();
        value->intValue = 0;
        value->type = eInt;
        newLast->expr = value;
        body << newLast;
    }
    else
    {
        AttrStmt* lastStmt = body.last();

        if(lastStmt->type != eReturn)
        {
            AttrReturnStmt* newLast = new AttrReturnStmt();
            if(newMethod->methodDef->isConstructor || newMethod->id == NAME_MAIN_CLASS_METHOD && curClass->id == NAME_MAIN_CLASS)
            {// Для конструкторов и main просто return
                newLast->expr = NULL;
            }
            else if(lastStmt->type == eExpr)
            {// Если в конце идёт выражение - заменяем его на return
                newLast->expr = ((AttrExprStmt*)lastStmt)->expr;
                body.removeLast();
                delete lastStmt;
            }
            else
            {// Иначе return 0
                // TODO nil
                AttrConstExpr* value = new AttrConstExpr();
                value->intValue = 0;
                value->type = eInt;
                newLast->expr = value;
            }
            body << newLast;
        }
    }

    foreach(AttrStmt* stmt, body)
        stmt->doSemantics(classTable, curClass, newMethod, errors);

    if(!isStatic && !isConstructor)
        newMethodC->locals = newMethod->locals;
}

void AttrMethodDef::doFirstSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors, AttrStmt *parentStmt)
{
    if(curClass->methods.contains(id))
    {
        errors << QString("Method already defined: " + id);
        return;
    }

    SemanticMethod* newMethod = new SemanticMethod();
    newMethod->paramCount = params.count();
    newMethod->id = id;
    curClass->methods.insert(id, newMethod);

    // Перемещение определения функции в тело класса
    if(parentStmt)
    {
        QLinkedList<AttrStmt*>* parentBody = parentStmt->getBody();
        parentBody->removeOne(this);
        curClass->classDef->getBody()->append(this);
    }
    foreach(AttrStmt* stmt, body)
        stmt->doFirstSemantics(classTable, curClass, newMethod, errors, this);
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

void AttrMethodDef::generateCode(QDataStream &out, SemanticClass *curClass)
{ 
    SemanticMethod* semMethod = curClass->methods.value(id);

    out << (quint16)semMethod->constCode;

    QByteArray attribute;
    QDataStream attOut(&attribute, QIODevice::WriteOnly);

    attOut << (quint16)1000;
    int localsCount = semMethod->locals.count();
    if(!isStatic)
        localsCount++;
    attOut << (quint16)localsCount;

    QByteArray byteCode;
    QDataStream byteOut(&byteCode, QIODevice::WriteOnly);


    int lastParamIndex = semMethod->methodDef->params.count();
    int i = semMethod->locals.count();

    if(isStatic)
    {
        i--;
        lastParamIndex--;
    }
    // Создание объектов для всех локальных переменных (не параметров)
    for(;i > lastParamIndex; i--)
    {
        byteOut << NEW << (quint16)curClass->constCommonValueClass;
        byteOut << DUP;
        byteOut << ASTORE << (quint8)i;
        byteOut << INVOKESPECIAL << (quint16)curClass->constRTLInitUninitRef;
    }

    if(curClass->id != NAME_COMMON_CLASS || (curClass->id == NAME_COMMON_CLASS && id == NAME_DEFAULT_CONSTRUCTOR))
        foreach(AttrStmt* stmt, body)
        {
            stmt->generate(byteOut, curClass, semMethod);
        }
    else if(id == NAME_MAIN_CLASS_METHOD || id == NAME_DEFAULT_CONSTRUCTOR)
        byteOut << RETURN;
    else
    {
        byteOut << NEW << (quint16)curClass->constants.value(curClass->constCommonValueClass)->number;
        byteOut << DUP;
        byteOut << BIPUSH << (qint8)0;
        byteOut << INVOKESPECIAL << (quint16)curClass->constants.value(curClass->constRTLInitIntRef)->number;
        byteOut << ARETURN;
        // TODO кидать исключение
    }


    attOut << (quint32)byteCode.length();
    attOut.writeRawData(byteCode.data(), byteCode.size());
    attOut << (quint16)0;
    attOut << (quint16)0;
    out << (quint32)attribute.size();
    out.writeRawData(attribute.data(), attribute.size());
}

QLinkedList<AttrStmt *> *AttrMethodDef::getBody()
{
    return &body;
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
    result->type = node->type;
    return result;
}


void AttrCycleStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    expr->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrStmt* stmt, block)
        stmt->doSemantics(classTable, curClass, curMethod, errors);
}

void AttrCycleStmt::doFirstSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors, AttrStmt *parentStmt)
{
    foreach(AttrStmt* stmt, block)
        stmt->doFirstSemantics(classTable, curClass, curMethod, errors, this);
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

void AttrCycleStmt::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    QByteArray codeBlock;
    QDataStream blockOut(&codeBlock, QIODevice::WriteOnly);

    foreach(AttrStmt* stmt, block)
        stmt->generate(blockOut, curClass, curMethod);

    out << GOTO << (qint16)(codeBlock.size() + 3);

    QByteArray exprBlock;
    QDataStream exprOut(&exprBlock, QIODevice::WriteOnly);
    expr->generate(exprOut, curClass, curMethod);

    exprOut << INVOKEVIRTUAL << (quint16)curClass->constRTLGetIntRef;

    out.writeRawData(codeBlock.data(), codeBlock.size());
    out.writeRawData(exprBlock.data(), exprBlock.size());

    int pos = -exprBlock.size() - codeBlock.size();

    if(cycleType == cycleWhile)
        out << IFNE << (qint16)(pos);
    else
        out << IFEQ << (qint16)(pos);
}

QLinkedList<AttrStmt *> *AttrCycleStmt::getBody()
{
    return &block;
}


AttrReturnStmt* AttrReturnStmt::fromParserNode(StmtNode* node)
{
    AttrReturnStmt* result = new AttrReturnStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    result->type = node->type;
    return result;
}


void AttrReturnStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(!expr)
    {
        if(curMethod->id != NAME_DEFAULT_CONSTRUCTOR && !(curClass->id == NAME_MAIN_CLASS && curMethod->id == NAME_MAIN_CLASS_METHOD))
        {
            AttrConstExpr* value = new AttrConstExpr();
            value->intValue = 0;
            value->type = eInt;
            expr = value;
        }
    }
    else if(curMethod->id == NAME_DEFAULT_CONSTRUCTOR || curClass->id == NAME_MAIN_CLASS && curMethod->id == NAME_MAIN_CLASS_METHOD)
    {
        errors << "wrong return with value in constructor or main.";
        return;
    }

    if(expr)
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

void AttrReturnStmt::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    if(expr)
    {
        expr->generate(out, curClass, curMethod);
        out << ARETURN;
    }
    else
        out << RETURN;
}

QLinkedList<AttrStmt *> *AttrReturnStmt::getBody()
{
    return NULL;
}

AttrExprStmt* AttrExprStmt::fromParserNode(StmtNode* node)
{
    AttrExprStmt* result = new AttrExprStmt();
    result->expr = AttrExpr::fromParserNode(node->expr);
    result->type = node->type;
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

void AttrExprStmt::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    expr->generate(out, curClass, curMethod);
    if(expr->type == eMethodCall && (((AttrMethodCall*)expr)->id == NAME_DEFAULT_CONSTRUCTOR || ((AttrMethodCall*)expr)->id == NAME_SUPER_METHOD))
        return;
    out << POP; // Если значение возвращается, но не используетс, оно снимается со стека
}

QLinkedList<AttrStmt *> *AttrExprStmt::getBody()
{
    return NULL;
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
    case eLocal:
        return AttrLocal::fromParserNode(node);
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
	case eQBracketsInit:
		return AttrQBracketsInit::fromParserNode(node);
	case eQBrackets:
		return AttrBinExpr::fromParserNode(node);
    }
}

void AttrExpr::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod)
{

}

AttrBinExpr* AttrBinExpr::fromParserNode(ExprNode* node)
{
    AttrBinExpr* result = new AttrBinExpr();
    result->left = AttrExpr::fromParserNode(node->left);
    result->right = AttrExpr::fromParserNode(node->right);
    result->type = node->type;
	result->third = NULL;
    return result;
}

void AttrBinExpr::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    transform();

    if(type == eAssign && left->type != eLocalNewRef && left->type != eFieldAccRef)
    {
        errors << "Not lvalue left of \"=\"";
        return;
    }
    if(left)
        left->doSemantics(classTable, curClass, curMethod, errors);
    right->doSemantics(classTable, curClass, curMethod, errors);
    if(third)
        third->doSemantics(classTable, curClass, curMethod, errors);
}

void AttrBinExpr::dotPrint(QTextStream & out)
{
    transform();
    if(type == eAssign && left->type != eLocalRef && left->type != eFieldAccRef)
    {
        out << QString::number((int)this) + "[label=\" = \"]" + QString("\n");
    }
    else
    {
        char str[25];
        exprTypeToStr(type, str);
        out << QString::number((int)this) + "[label=\"" + str + "\"]" + QString("\n");
    }
    if(left)
        left->dotPrint(out);
    right->dotPrint(out);
	if(type == eQBracketsLvalue)
        third->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)left) + QString("\n");
    out << QString::number((int)this) + "->" + QString::number((int)right) + QString("\n");
	if(type == eQBracketsLvalue)
		out << QString::number((int)this) + "->" + QString::number((int)third) + QString("\n");
}

void AttrBinExpr::transform()
{
    if(type == eAssign)
    {
        if(left->type == eFieldAcc)
        {
            //type = eFieldAccAssign;
            left->type = eFieldAccRef;
           // AttrExpr* newLeft;
          //  newLeft = ((AttrFieldAcc*)left)->left;
           // id = ((AttrFieldAcc*)left)->id;
           // delete left;
           // left = newLeft;
        }
        else if(left->type == eLocal)
        {
            //type = eLocalAssign;
            left->type = eLocalNewRef;
            //AttrExpr* newLeft;
            //newLeft = ((AttrLocal*)left)->left;
            //id = ((AttrFieldAcc*)left)->id;
            //delete left;
            //left = newLeft;
        }
        // TODO array
		if(left->type == eQBrackets)
		{
			third = right;
			right = dynamic_cast<AttrBinExpr*>(left)->right;
			left = dynamic_cast<AttrBinExpr*>(left)->left;
			type = eQBracketsLvalue;
		}
    }
}

void AttrBinExpr::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
	if(type != eAssign && type != eQBrackets && type != eQBracketsLvalue)
    {
        left->generate(out, curClass, curMethod);
        right->generate(out, curClass, curMethod);
    }
    switch(type)
    {
        case eAssign:
        {
            if(left->type == eFieldAccRef)
            {
                if(!((AttrFieldAcc*)left)->isStatic)
                {
                    out << ALOAD << (quint8)0;
                    right->generate(out, curClass, curMethod);
                    out << PUTFIELD << (quint16)((AttrFieldAcc*)left)->constFieldRef;
                    out << ALOAD << (quint8)0;
                    out << GETFIELD << (quint16)((AttrFieldAcc*)left)->constFieldRef; // Оставляем на стеке ссылку как возвращаемое значение
                }
                else
                {
                    right->generate(out, curClass, curMethod);
                    out << PUTSTATIC << (quint16)((AttrFieldAcc*)left)->constFieldRef;
                    out << GETSTATIC << (quint16)((AttrFieldAcc*)left)->constFieldRef;
                }
            }
            else
            {
                left->generate(out, curClass, curMethod);
                right->generate(out, curClass, curMethod);
                out << INVOKEVIRTUAL << (quint16)curClass->constRTLAssignRef;
            }
            break;
        }
        case ePlus:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLAddRef;
            break;
        }
        case eMinus:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLMinusRef;
            break;
        }
        case eMul:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLMulRef;
            break;
        }
        case eDiv:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLDivRef;
            break;
        }
        case eLess:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLLessRef;
            break;
        }
        case eMore:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLMoreRef;
            break;
        }
        case eOr:
        case eAnd:
        case eEqu:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLEquRef;
            break;
        }
        case eNEqu:
        {
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLNequRef;
            break;
        }
		case eQBrackets:
		{
			left->generate(out, curClass, curMethod);
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLGetArrayRef;
			right->generate(out, curClass, curMethod);
			out << INVOKEVIRTUAL << (quint16)curClass->constRTLArrayGetRef;
			break;
		}
		case eQBracketsLvalue:
		{
			left->generate(out, curClass, curMethod);
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLGetArrayRef;
			right->generate(out, curClass, curMethod);
			third->generate(out, curClass, curMethod);
			out << INVOKEVIRTUAL << (quint16)curClass->constRTLArraySetRef;
			break;
		}

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

void AttrUnExpr::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    switch(type)
    {
        case eBrackets:
        {
            expr->generate(out, curClass, curMethod);
            break;
        }
        case eUMinus:
        {
            expr->generate(out, curClass, curMethod);
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLUMinusRef;
            break;
        }
    }
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

    if(!SemanticMethod::isSpecialMethodName(result->id))
        result->id += QString::number(result->arguments.count());
    return result;
}

void AttrMethodCall::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    bool methodFound = false;
    if(left == NULL)
    {
        if(id == NAME_SUPER_METHOD ||
                id == NAME_PRINTINT_METHOD)
            methodFound = true;
    }
    else if(id == NAME_NEW_METHOD)
    {
        methodFound = true;
    }

    if(!methodFound)
    {
        foreach(SemanticClass* semClass, classTable)
            foreach(SemanticMethod* method, semClass->methods)
                if(method->id == id && method->paramCount == arguments.count())
                    methodFound = true;
    }
    if(!methodFound)
    {
        errors << "Method with " + QString::number(arguments.count()) + " arguments doesn't exists: " + id;
        return;
    }

    QString desc("(");
    int count = arguments.count();
    for(int  i = 0; i < count; i++)
        desc += DESC_COMMON_VALUE;
    desc += QString(")");

    if(left)
    {
        // Проверка на операцию new
        QString leftId;
        if(left->type == eLocal)
        {
            leftId = ((AttrLocal*)left)->id;

            if(leftId[0].isUpper())
            {
                if(!classTable.contains(leftId))
                {
                    errors << "Class doesn't exist: " + leftId;
                    return;
                }
                if(id == NAME_NEW_METHOD)
                    isObjectCreating = true;
                else
                    isStaticCall = true;

                constClass = curClass->addConstantClass(leftId);
            }
            else if(id == NAME_NEW_METHOD)
            {
                errors << "Incorrect object creating: " + leftId;
                return;
            }


        }
        else
        {
            isObjectCreating = false;
        }

        if(!isObjectCreating)
            desc += DESC_COMMON_VALUE;
        else
            desc += "V";

        if(isObjectCreating)
            constMethodRef = curClass->addConstantMethodRef(leftId, QString(NAME_DEFAULT_CONSTRUCTOR), desc);
        else if(isStaticCall)
            constMethodRef = curClass->addConstantMethodRef(leftId, id, desc);
        else
            constMethodRef = curClass->addConstantMethodRef(QString(NAME_COMMON_CLASS), id, desc);

        if(!isObjectCreating && !isStaticCall)
            left->doSemantics(classTable, curClass, curMethod, errors);
    }
    else
    {
        desc += DESC_COMMON_VALUE;
        if(id != NAME_SUPER_METHOD)
        {
            if(id != NAME_RTL_CONSOLE_PRINT_INT && id != NAME_RTL_CONSOLE_PRINT_STRING)
            {
                if(curClass->id == NAME_MAIN_CLASS)
                // Статический метод класса MainClass
                    constMethodRef = curClass->addConstantMethodRef(QString(NAME_MAIN_CLASS), id, desc);
                else
                // Обычный метод
                    constMethodRef = curClass->addConstantMethodRef(QString(NAME_COMMON_CLASS), id, desc);
            }
        }
        else
        {
            if(curClass->id != NAME_COMMON_CLASS)
                constMethodRef = curClass->addConstantMethodRef(curClass->parentId, curMethod->id, curClass->constants.value(curMethod->constDesc)->strValue);
            else
                constMethodRef = curClass->addConstantMethodRef(QString(NAME_JAVA_OBJECT), curMethod->id, curClass->constants.value(curMethod->constDesc)->strValue);
        }
    }
    if(id == NAME_SUPER_METHOD)
    {
        if(classTable.contains(curClass->parentId) && !classTable.value(curClass->parentId)->methods.contains(curMethod->id))
            errors << "Parent class doesn't have method:" + curMethod->id;
    }
    foreach(AttrExpr* argument, arguments)
        argument->doSemantics(classTable, curClass, curMethod, errors);
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

void AttrMethodCall::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    //TODO
    if(id == NAME_PRINTINT_METHOD)
    {
        foreach(AttrExpr* argument, arguments)
            argument->generate(out, curClass, curMethod);
        out << INVOKESTATIC << (quint16)curClass->constants.value(curClass->constRTLConsolePrintIntRef)->number;
    }
    else if(id == NAME_SUPER_METHOD)
    {
        // TODO
        out << ALOAD << (quint8)0;

        foreach(AttrExpr* argument, arguments)
            argument->generate(out, curClass, curMethod);

        out << INVOKESPECIAL << (quint16)constMethodRef;
    }
    else if(isObjectCreating)
    {
        out << NEW << (quint16)curClass->constCommonValueClass;
        out << DUP;

        out << NEW << (quint16)constClass;
        out << DUP;
        out << INVOKESPECIAL << (quint16)constMethodRef;

        out << INVOKESPECIAL << (quint16)curClass->constRTLInitObjectRef;
    }
    else
    {
        if(left && !isStaticCall)
            left->generate(out, curClass, curMethod);

        if(!left && curClass->id == NAME_MAIN_CLASS)
        {// Статический метод класса MainClass
            foreach(AttrExpr* argument, arguments)
                argument->generate(out, curClass, curMethod);
            out << INVOKESTATIC << (quint16)constMethodRef;
        }
        else if(isStaticCall)
        {
            foreach(AttrExpr* argument, arguments)
                argument->generate(out, curClass, curMethod);
            out << INVOKESTATIC << (quint16)constMethodRef;
        }
        else
        {// Обычный метод
            //if(!(left->type == eLocal && ((AttrLocal*)left)->isSelf))
            out << INVOKEVIRTUAL << (quint16)curClass->constRTLGetObjectRef;
            foreach(AttrExpr* argument, arguments)
                argument->generate(out, curClass, curMethod);
            out << INVOKEVIRTUAL << (quint16)constMethodRef;
        }
    }
}

AttrFieldAcc* AttrFieldAcc::fromParserNode(ExprNode* node)
{
    AttrFieldAcc* result = new AttrFieldAcc();
    result->id = node->id;
    result->type = node->type;
    result->left = AttrExpr::fromParserNode(node->left);
    result->isStatic = node->isStatic;
    return result;
}

void AttrFieldAcc::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(left != NULL)
    {
        left->doSemantics(classTable, curClass, curMethod, errors);
        errors << "wat"; //^_^
    }
    else
    {
        if(!existsInParent(classTable, curClass))
            curClass->addField(id, isStatic);

        if(isStatic)
        {
            constFieldRef = curClass->addConstantFieldRef(curClass->id, id, QString(DESC_COMMON_VALUE));
        }
        else
        {
            classTable.value(NAME_COMMON_CLASS)->addField(id, isStatic);
            constFieldRef = curClass->addConstantFieldRef(QString(NAME_COMMON_CLASS), id, QString(DESC_COMMON_VALUE));
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

void AttrFieldAcc::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    if(!isStatic)
    {
        out << ALOAD << (quint8)0;
        out << GETFIELD << (quint16)constFieldRef;
    }
    else
    {
        out << GETSTATIC << (quint16)constFieldRef;
    }
}

bool AttrFieldAcc::existsInParent(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass)
{
    if(curClass->fields.contains(id))
        return true;
    if(curClass->id == NAME_COMMON_CLASS)
    {
        if(curClass->fields.contains(id))
            return true;
        return false;
    }
    else
        return existsInParent(classTable, classTable.value(curClass->parentId));
}

AttrConstExpr* AttrConstExpr::fromParserNode(ExprNode* node)
{
    AttrConstExpr* result = new AttrConstExpr();
    result->str = node->str;
    result->intValue = node->value;
    result->type = node->type;
    return result;
}

void AttrConstExpr::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(type == eInt && intValue > VALUE_MAX2BIT)
    {
        constValue = curClass->addConstantInteger(intValue);
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
        label = QString::number(intValue);
        break;
    case eBool:
        if(intValue)
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

void AttrConstExpr::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod *curMethod)
{
    if(type == eInt)
    {
        out << NEW << (quint16)curClass->constants.value(curClass->constCommonValueClass)->number;
        out << DUP;
        //TODO long int
        out << BIPUSH << (qint8)intValue;
        out << INVOKESPECIAL << (quint16)curClass->constants.value(curClass->constRTLInitIntRef)->number;
    }
}


AttrLocal *AttrLocal::fromParserNode(ExprNode *node)
{
    AttrLocal* result = new AttrLocal();
    result->id = node->id;
    result->type = eLocal;
    return result;
}

void AttrLocal::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    if(id == NAME_NIL)
    {
        isNil = true;
        isSelf = false;
    }
    else if(id == NAME_SELF)
    {
        isNil = false;
        isSelf = true;
        if(curMethod->methodDef->isStatic)
        {
            errors << "self in static method: " + curMethod->id;
            return;
        }
    }
    else
    {
        isNil = false;
        isSelf = false;
        curMethod->addLocalVar(id, curClass);
    }
}

void AttrLocal::dotPrint(QTextStream &out)
{
    out << QString::number((int)this) + "[label=\" local access: " + id + "\"]" + QString("\n");
}

void AttrLocal::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod)
{
    if(isNil)
    {
        out << NEW << (quint16)curClass->constCommonValueClass;
        out << DUP;
        out << INVOKESPECIAL << (quint16)curClass->constRTLInitUninitRef;
    }
    else if(!isSelf)
    {
        out << ALOAD << (quint8)curMethod->locals.value(id)->number;
    }
    else
    {
        out << NEW << (quint16)curClass->constCommonValueClass;
        out << DUP;
        out << ALOAD << (quint8)0;
        out << INVOKESPECIAL << (quint16)curClass->constRTLInitObjectRef;

    }
    //else if(type == eLocalNewRef)
    //{
    //    out << NEW << (quint16)curClass->constants.value(curClass->constCommonValueClass)->number;
     //   out << DUP;
      //  out << DUP;
      //  out << ASTORE << (quint8)curMethod->locals.value(id)->number;
      //  out << INVOKESPECIAL << (quint16)curClass->constants.value(curClass->constRTLInitUninitRef)->number;
    //}
}

AttrElsif* AttrElsif::fromParserNode(ElsifNode* node)
{
	AttrElsif *result = new AttrElsif();
	result->expr = AttrExpr::fromParserNode(node->expr);
	AttributedNode::fillStmtList(node->block, result->block);
	return result;
}
void AttrElsif::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    expr->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrStmt* stmt, block)
        stmt->doSemantics(classTable, curClass, curMethod, errors);
}
void AttrElsif::dotPrint(QTextStream & out)
{
    QString label = "elsif";
    out << QString::number((int)this) + "[label = \"" + label +"\"]" + QString("\n");
    dotPrintStmtSeq(block, out);
    expr->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
}


AttrIfStmt* AttrIfStmt::fromParserNode(StmtNode* node)
{
	AttrIfStmt *result = new AttrIfStmt();
	result->expr = AttrExpr::fromParserNode(node->expr);
	AttributedNode::fillStmtList(node->block, result->block);
	AttributedNode::fillStmtList(node->elseStmtBlock, result->elseBlock);
	if(node->elsifList)
    {
        ElsifNode* current = node->elsifList->first;
        while(current)
        {
            result->elsifBlock << AttrElsif::fromParserNode(current);
            current = current->next;
        }
    }
	return result;
}
void AttrIfStmt::transform()
{
	if(elsifBlock.isEmpty())//paranoir mode on
		return;

	AttrIfStmt *tmp = new AttrIfStmt();
	tmp->expr = elsifBlock.first()->expr;
	tmp->block = elsifBlock.first()->block;
	elseBlock << tmp;
	elsifBlock.removeFirst();
	tmp->elsifBlock << elsifBlock;
	elsifBlock.clear();
	tmp->transform();
}
void AttrIfStmt::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
	if(!elsifBlock.isEmpty())
		transform();
    expr->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrStmt* stmt, block)
        stmt->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrElsif* elsif, elsifBlock)
        elsif->doSemantics(classTable, curClass, curMethod, errors);
    foreach(AttrStmt* stmt, elseBlock)
        stmt->doSemantics(classTable, curClass, curMethod, errors);
}
void AttrIfStmt::dotPrint(QTextStream & out)
{
    QString label = "if";
    out << QString::number((int)this) + "[label = \"" + label +"\"]" + QString("\n");
    dotPrintStmtSeq(block, out);
    expr->dotPrint(out);
    out << QString::number((int)this) + "->" + QString::number((int)expr) + QString("\n");
	if(!elsifBlock.isEmpty())
	{
		out << QString::number((int)this + 2) + "[label = \"elseif seq\"]" + QString("\n");
		out << QString::number((int)this) + "->" + QString::number((int)this + 2) + QString("\n");
		foreach(AttrElsif* elsif, elsifBlock)
		{
			elsif->dotPrint(out);
			out << QString::number((int)this + 2) + "->" + QString::number((int)elsif) + QString("\n");
		}
	}

	if(!elseBlock.isEmpty())
	{
		out << QString::number((int)this + 3) + "[label = \"else\"]" + QString("\n");
		out << QString::number((int)this) + "->" + QString::number((int)this + 3) + QString("\n");
		foreach(AttrStmt* elseStmt, elseBlock)
		{
			elseStmt->dotPrint(out);
			out << QString::number((int)this + 3) + "->" + QString::number((int)elseStmt) + QString("\n");
		}
	}
}
void AttrIfStmt::generate(QDataStream & out, SemanticClass * curClass, SemanticMethod *curMethod)
{
	expr->generate(out, curClass, curMethod);
	out << INVOKEVIRTUAL << (quint16)curClass->constRTLGetIntRef;

	QByteArray stmtBC;
	QDataStream stmtBCOut(&stmtBC, QIODevice::WriteOnly);
	foreach(AttrStmt* stmt, block)
		stmt->generate(stmtBCOut,curClass,curMethod);
	out << IFEQ << (quint16)(stmtBC.size() + 6);
	out.writeRawData(stmtBC.data(), stmtBC.size());

	QByteArray elseStmtBC;
	QDataStream elseStmtBCOut(&elseStmtBC, QIODevice::WriteOnly);
	foreach(AttrStmt* stmt, elseBlock)
		stmt->generate(elseStmtBCOut, curClass, curMethod);

	out << GOTO << (quint16)(elseStmtBC.size() + 3);
	out.writeRawData(elseStmtBC.data(), elseStmtBC.size());
}
QLinkedList<AttrStmt*>* AttrIfStmt::getBody()
{
	return &block;
}
AttrQBracketsInit* AttrQBracketsInit::fromParserNode(ExprNode* node)
{
	AttrQBracketsInit *result = new AttrQBracketsInit();
    if(node->list)
    {
        ExprNode* current = node->list->first;
        while(current)
        {
            result->exprList << AttrExpr::fromParserNode(current);
            current = current->next;
        }
    }
	return result;
}
void AttrQBracketsInit::doSemantics(QHash<QString, SemanticClass *> &classTable, SemanticClass *curClass, SemanticMethod *curMethod, QList<QString> &errors)
{
    foreach(AttrExpr* expr, exprList)
        expr->doSemantics(classTable, curClass, curMethod, errors);
}
void AttrQBracketsInit::dotPrint(QTextStream & out)
{
    QString label = "QBracketsInit";
    out << QString::number((int)this) + "[label = \"" + label +"\"]" + QString("\n");
	dotPrintExprSeq(exprList, out);
}
void AttrQBracketsInit::transform()
{

}
void AttrQBracketsInit::generate(QDataStream &out, SemanticClass *curClass, SemanticMethod* curMethod)
{
	out << NEW << (quint16)curClass->constCommonValueClass;
	out << DUP;
	out << NEW << (quint16)curClass->constRTLClassArray;
	out << DUP;
	out << INVOKESPECIAL << (quint16)curClass->constRTLInitArrayRef;

	int dupCount = exprList.count();
	for(int i = 0; i < dupCount; i++)
		out << DUP;

	foreach(AttrExpr *expr, exprList)
	{
		expr->generate(out, curClass, curMethod);
		out << INVOKEVIRTUAL << (quint16)curClass->constRTLArrayAppendRef;
	}

	out << INVOKESPECIAL << (quint16)curClass->constRTLInitByArrayRef;
}