#include "Circuit.h"
#include "Parser.h"
#include "TruthTable.h"
#include <iostream>
using namespace std;

// Layer to connect hidden layer to main and user
void analyzeCircuit(string expr, Row table[], int &size) {
    Node* root = parseExpression(expr);
    buildTableTree(root, table, size);
    printTable("Truth Table", table, size);
    cout << "\nStatus: " << checkStatus(table, size) << endl;
    showSatisfying(table, size);
}