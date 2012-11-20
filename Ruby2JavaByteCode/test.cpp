#include "test.h"
#include <qprocess.h>

void stmtTypeToStr(enum StmtNodeType type, char *str)
{
    switch(type)
    {
    case eExpr:
        strcpy(str, "expr_stmt");
        break;
    case eIf:
        strcpy(str, "if_stmt");
        break;
    case eWhile:
        strcpy(str, "while_stmt");
        break;
    case eUnless:
        strcpy(str, "unless_stmt");
        break;
    case eUntil:
        strcpy(str, "until_stmt");
        break;
    case eClassDef:
        strcpy(str, "class_def_stmt");
        break;
    case eMethodDef:
        strcpy(str, "method_def_stmt");
        break;
    case eReturn:
        strcpy(str, "return_stmt");
    }
}

void exprTypeToStr(enum ExprNodeType type, char* str)
{
    switch(type)
    {
        case eInt:
            strcpy(str, "int"); break;
        case eBool:
            strcpy(str, "bool"); break;
        case eString:
            strcpy(str, "string"); break;
        case eId:
            strcpy(str, "id"); break;
        case eAssign:
            strcpy(str, "assign"); break;
        case ePlus:
            strcpy(str, "plus"); break;
        case eMinus:
            strcpy(str, "minus"); break;
        case eMul:
            strcpy(str, "mul"); break;
        case eDiv:
            strcpy(str, "div"); break;
        case eLess:
            strcpy(str, "less"); break;
        case eMore:
            strcpy(str, "more"); break;
        case eOr:
            strcpy(str, "or"); break;
        case eAnd:
            strcpy(str, "and"); break;
        case eEqu:
            strcpy(str, "equ"); break;
        case eNEqu:
            strcpy(str, "nequ"); break;
        case eNot:
            strcpy(str, "not"); break;
        case eUMinus:
            strcpy(str, "uminus"); break;
        case eBrackets:
            strcpy(str, "brackets"); break;
        case eQBrackets:
            strcpy(str, "q_brackets"); break;
        case eQBracketsInit:
            strcpy(str, "q_brackets_init"); break;
        case eFieldAcc:
            strcpy(str, "field_acc"); break;
        case eSuper:
            strcpy(str, "super"); break;
        case eSelf:
            strcpy(str, "self"); break;
        case eNil:
            strcpy(str, "nil"); break;
    }
}

void printConnect(int v1, int v2)
{
    char text[150];
    char buf1[40];
    char buf2[20];
    printf(strcat(strcat(strcat(itoa(v1, buf1, 10), "->"), itoa(v2, buf2, 10)), "\n"));
}

void printProgramName(struct ProgramNode* node)
{
    char buf[10];
    char text[150] = "";
    struct StmtNode* current = node->body->first;

    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), "program"), "]");
    printf(text);

    printStmtSeqNodeName(node->body);
}

void printProgram(struct ProgramNode* node)
{
    printConnect((int)node,(int)node->body);
    printStmtSeqNode(node->body);
}

void printStmtNodeName(struct StmtNode* node)
{
    char buf[10];
    char text[150] = "";
    char type[30];
    stmtTypeToStr(node->type, type);

    if(node->type == eMethodDef)
        strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = method_"), node->id), "]");
    else if(node->type == eClassDef)
    {
        if(node->secondId)
            strcat(strcat(strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = class_"), node->id), "____"), node->secondId), "]");
        else
            strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = class_"), node->id), "]");
    }
    else if(node->type == eWhile)
        strcat(strcat(text, itoa((int)node, buf, 10)), "[label = while]");
    else if(node->type == eIf)
        strcat(strcat(text, itoa((int)node, buf, 10)), "[label = if]");
    else
        strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), type), "]");
    printf(text);

    if(node->expr != NULL)
        printExprNodeName(node->expr);
    if(node->block != NULL)
        printStmtSeqNodeName(node->block);
    if(node->params != NULL)
        printMethodDefParamSeqNodeName(node->params);
    if(node->elseStmtBlock != NULL)
        printStmtSeqNodeName(node->elseStmtBlock);
    if(node->elsifList != NULL)
        printElsifSeqNodeName(node->elsifList);

}
void printStmtNode(struct StmtNode* node)
{
    char buf1[30];
    char buf2[10];
    char text[150] = "";

    if(node->expr != NULL)
    {
        printConnect((int)node, (int)node->expr);
        printExprNode(node->expr);
    }
    if(node->params != NULL)
    {
        printConnect((int)node, (int)node->params);
        printMethodDefParamSeqNode(node->params);
    }
    if(node->block != NULL)
    {
        printConnect((int)node, (int)node->block);
        printStmtSeqNode(node->block);
    }
    if(node->elseStmtBlock != NULL)
    {
        printConnect((int)node, (int)node->elseStmtBlock);
        printStmtSeqNode(node->elseStmtBlock);
    }
    if(node->elsifList != NULL)
    {
        printConnect((int)node, (int)node->elsifList);
        printElsifSeqNode(node->elsifList);
    }
}

void printMethodDefParamSeqNodeName(struct MethodDefParamSeqNode* node)
{
    char buf[10];
    char text[150] = "";
    struct MethodDefParamNode* current = node->first;

    printf(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = param_seq ]"));

    while(current)
    {
        printMethodDefParamNodeName(current);
        current = current->next;
    }
}

void printMethodDefParamSeqNode(struct MethodDefParamSeqNode* node)
{
    struct MethodDefParamNode* current = node->first;
    while(current)
    {
        printConnect((int)node, (int)current);
        current = current->next;
    }
}


void printMethodDefParamNodeName(struct MethodDefParamNode* node)
{
    char buf[10];
    char text[150] = "";

    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), node->id), "]");
    printf(text);
}

void printStmtSeqNodeName(struct StmtSeqNode* node)
{
    char buf[10];
    char text[150] = "";
    struct StmtNode* current = node->first;
    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), "stmt_seq"), "]");

    printf(text);

    while(current)
    {
        printStmtNodeName(current);
        current = current->next;
    }
}
void printStmtSeqNode(struct StmtSeqNode* node)
{
    struct StmtNode* current = node->first;
    while(current)
    {
        printConnect((int)node, (int)current);
        printStmtNode(current);
        current = current->next;
    }
}

void printExprNodeName(struct ExprNode* node)
{
    char buf[10];
    char buf2[20];
    char text[150] = "";
    char type[30];
    exprTypeToStr(node->type, type);

    if(node->type == eInt)
        strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), itoa(node->value, buf2, 10)), "]");
    else if(node->type == eFieldAcc)
        strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), node->id), "]");
    else if(node->type == eBool)
    {
        if(node->value)
            strcat(strcat(text, itoa((int)node, buf, 10)), "[label = true ]");
        else
            strcat(strcat(text, itoa((int)node, buf, 10)), "[label = false ]");
    }
    else
        strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), type), "]");
    printf(text);

    if(node->left)
        printExprNodeName(node->left);
    if(node->right)
        printExprNodeName(node->right);
    if(node->list)
        printExprSeqNodeName(node->list);
}
void printExprNode(struct ExprNode* node)
{
    if(node->left)
    {
        printConnect((int)node, (int)node->left);
        printExprNode(node->left);
    }
    if(node->right)
    {
        printConnect((int)node, (int)node->right);
        printExprNode(node->right);
    }
    if(node->list)
    {
        printConnect((int)node, (int)node->list);
        printExprSeqNode(node->list);
    }
}

void printExprSeqNodeName(struct ExprSeqNode* node)
{
    char buf[10];
    char text[150] = "";
    struct ExprNode* current = node->first;
    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), "expr_seq"), "]");

    printf(text);

    while(current)
    {
        printExprNodeName(current);
        current = current->next;
    }
}

void printExprSeqNode(struct ExprSeqNode* node)
{
    struct ExprNode* current = node->first;

    while(current)
    {
        printConnect((int)node, (int)current);
        printExprNode(current);
        current = current->next;
    }
}
void printElsifNodeName(struct ElsifNode *node)
{
    char buf[10];
    char text[150] = "";

    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), "elsif"), "]");
    printf(text);

    if(node->expr)
        printExprNodeName(node->expr);
    if(node->block)
        printStmtSeqNodeName(node->block);
    if(node->next)
        printElsifNodeName(node->next);
}
void printElsifNode(struct ElsifNode *node)
{
    if(node->block)
    {
        printConnect((int)node, (int)node->block);
        printStmtSeqNode(node->block);
    }
    if(node->expr)
    {
        printConnect((int)node, (int)node->expr);
        printExprNode(node->expr);
    }
    if(node->next)
    {
        printConnect((int)node, (int)node->next);
    }
}
void printElsifSeqNodeName(struct ElsifSeqNode *node)
{
    char buf[10];
    char text[150] = "";
    struct ElsifNode* current = node->first;
    strcat(strcat(strcat(strcat(text, itoa((int)node, buf, 10)), "[label = "), "elsif_seq"), "]");

    printf(text);

    while(current)
    {
        printElsifNodeName(current);
        current = current->next;
    }
}
void printElsifSeqNode(struct ElsifSeqNode *node)
{
    struct ElsifNode* current = node->first;

    while(current)
    {
        printConnect((int)node, (int)current);
        printElsifNode(current);
        current = current->next;
    }
}

void printTree(struct ProgramNode* rootNode)
{
    if(!rootNode)
    {
        puts("err");
        getchar();
        return;
    }
    freopen("dot.txt", "w", stdout);
    printf("digraph G{ node[shape=\"rectangle\",style=\"rounded, filled\",fillcolor=\"white\"] \n");
    printProgramName(rootNode);
    printProgram(rootNode);
    printf("}");
    fclose(stdout);
    QProcess::execute("dot.exe -Tpng -oresult.png dot.txt");
}
