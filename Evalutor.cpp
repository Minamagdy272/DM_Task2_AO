#include "Evaluator.h"

// Evaluate Expression Tree for given A, B, C
int evalTree(Node* node, int A, int B, int C) {
    if (!node) return 0;

    // Leaf node
    if (node->op == 0) {
        if (node->varName == "A") return A;
        if (node->varName == "B") return B;
        if (node->varName == "C") return C;
        return 0;
    }

    // NOT operator
    if (node->op == '~') return !evalTree(node->left, A, B, C);

    // Binary operators
    int leftVal = evalTree(node->left, A, B, C);
    int rightVal = evalTree(node->right, A, B, C);

    if (node->op == '^') return leftVal && rightVal;
    if (node->op == '+') return (leftVal && !rightVal) || (!leftVal && rightVal);
    if (node->op == 'v') return leftVal || rightVal;

    return 0;
}