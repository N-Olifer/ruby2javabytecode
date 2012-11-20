#ifndef TEST_H
#define TEST_H

#include "structures.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void printConnect(int v1, int v2);
void printProgramName(struct ProgramNode* node);
void printProgram(struct ProgramNode* node);
void printStmtNodeName(struct StmtNode* node);
void printStmtNode(struct StmtNode* node);
void printStmtSeqNodeName(struct StmtSeqNode* node);
void printStmtSeqNode(struct StmtSeqNode* node);
void printExprNodeName(struct ExprNode* node);
void printExprNode(struct ExprNode* node);
void printExprSeqNodeName(struct ExprSeqNode* node);
void printExprSeqNode(struct ExprSeqNode* node);
void printMethodDefParamSeqNodeName(struct MethodDefParamSeqNode* node);
void printMethodDefParamSeqNode(struct MethodDefParamSeqNode* node);
void printMethodDefParamNodeName(struct MethodDefParamNode* node);

void printElsifNodeName(struct ElsifNode *node);
void printElsifNode(struct ElsifNode *node);
void printElsifSeqNodeName(struct ElsifSeqNode *node);
void printElsifSeqNode(struct ElsifSeqNode *node);


void printTree(struct ProgramNode* rootNode);


#endif
