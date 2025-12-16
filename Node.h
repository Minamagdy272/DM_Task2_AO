#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// Expression Tree Node
struct Node {
    char op;          // '^', 'v', '+', '~' or 0 if leaf
    string varName;   // "A", "B", "C" if leaf
    Node* left;
    Node* right;

    Node(char o = 0, string v = "", Node* l = nullptr, Node* r = nullptr);
};

#endif