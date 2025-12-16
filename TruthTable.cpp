#include "TruthTable.h"
#include "Evaluator.h"
#include <iostream>
using namespace std;

// Build truth table from expression tree
void buildTableTree(Node* root, Row table[], int &size) {
    size = 0;
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            for (int c = 0; c <= 1; c++) {
                table[size].A = a;
                table[size].B = b;
                table[size].C = c;
                table[size].output = evalTree(root, a, b, c);
                size++;
            }
}

// Print truth table
void printTable(string title, Row table[], int size) {
    cout << "\n" << title << endl;
    cout << "A  B  C  Output\n";
    cout << "---------------\n";
    for (int i = 0; i < size; i++) {
        cout << table[i].A << "  "
             << table[i].B << "  "
             << table[i].C << "    "
             << table[i].output << endl;
    }
}

// Check if two truth tables are equivalent
bool areEquivalent(Row t1[], int s1, Row t2[], int s2) {
    if (s1 != s2) return false;
    for (int i = 0; i < s1; i++)
        if (t1[i].output != t2[i].output) return false;
    return true;
}

// Check status of circuit (TAUTOLOGY, SATISFIABLE, UNSATISFIABLE)
string checkStatus(Row table[], int size) {
    bool flag1 = false, flag0 = false;
    for (int i = 0; i < size; i++) {
        if (table[i].output == 1) flag1 = true;
        if (table[i].output == 0) flag0 = true;
    }
    if (flag1 && flag0) return "SATISFIABLE";
    if (flag1) return "TAUTOLOGY";
    return "UNSATISFIABLE";
}

// Show inputs that make the circuit satisfiable
void showSatisfying(Row table[], int size) {
    string status = checkStatus(table, size);
    if (status == "SATISFIABLE") {
        cout << "\nInputs that make output 1:\n";
        for (int i = 0; i < size; i++)
            if (table[i].output == 1)
                cout << "A=" << table[i].A << " B=" << table[i].B << " C=" << table[i].C << endl;
    } else if (status == "TAUTOLOGY")
        cout << "All inputs make output 1\n";
    else
        cout << "All inputs make output 0\n";
}