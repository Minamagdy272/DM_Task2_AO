#ifndef PARSER_H
#define PARSER_H

#include "Node.h"
#include <string>
using namespace std;

// Helper functions
string removeSpaces(string expr);
int findClosingParen(string expr, int openPos);
int findMainOp(string expr, int start, int end);

// Parse expression into Expression Tree
Node* parseExpr(string expr, int start, int end);
Node* parseExpression(string expr);

#endif