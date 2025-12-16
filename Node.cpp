#include "Node.h"

Node::Node(char o, string v, Node* l, Node* r)
    : op(o), varName(v), left(l), right(r) {}