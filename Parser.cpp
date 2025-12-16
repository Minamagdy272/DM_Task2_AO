#include "Parser.h"

// Helper function to remove spaces
string removeSpaces(string expr) {
    string res;
    for (char c : expr) if (c != ' ') res += c;
    return res;
}

// Helper function to find matching closing parenthesis
int findClosingParen(string expr, int openPos) {
    int depth = 1;
    for (int i = openPos + 1; i < expr.length(); i++) {
        if (expr[i] == '(') depth++;
        if (expr[i] == ')') {
            depth--;
            if (depth == 0) return i;
        }
    }
    return -1;
}

// Find main operator (lowest precedence) outside parentheses
// precedence: OR(v)=1 < XOR(+)=2 < AND(^)=3
int findMainOp(string expr, int start, int end) {
    int depth = 0;
    int pos = -1;
    int minPrec = 4;

    for (int i = start; i <= end; i++) {
        char c = expr[i];
        if (c == '(') depth++;
        if (c == ')') depth--;

        if (depth == 0) {
            int prec = 0;
            if (c == 'v') prec = 1;
            else if (c == '+') prec = 2;
            else if (c == '^') prec = 3;
            else continue;

            if (prec < minPrec) {
                pos = i;
                minPrec = prec;
            }
        }
    }
    return pos;
}

// Parse expression into Expression Tree
Node* parseExpr(string expr, int start, int end) {
    while (start <= end && expr[start] == ' ') start++;
    while (end >= start && expr[end] == ' ') end--;

    // Remove outer parentheses if they wrap entire expression
    if (expr[start] == '(' && findClosingParen(expr, start) == end) {
        start++; end--;
    }

    // Handle NOT at beginning
    if (expr[start] == '~') {
        Node* leftNode;
        if (expr[start+1] == '(') {
            int closePos = findClosingParen(expr, start+1);
            leftNode = parseExpr(expr, start+2, closePos-1);
        } else {
            leftNode = parseExpr(expr, start+1, end);
        }
        return new Node('~', "", leftNode, nullptr);
    }

    // Find main operator outside parentheses
    int opPos = findMainOp(expr, start, end);
    if (opPos != -1) {
        Node* leftNode = parseExpr(expr, start, opPos-1);
        Node* rightNode = parseExpr(expr, opPos+1, end);
        return new Node(expr[opPos], "", leftNode, rightNode);
    }

    // Leaf node (variable)
    string varName = expr.substr(start, end-start+1);
    return new Node(0, varName);
}

Node* parseExpression(string expr) {
    expr = removeSpaces(expr);
    return parseExpr(expr, 0, expr.length()-1);
}