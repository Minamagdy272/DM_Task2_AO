#include <iostream>
#include <string>
#include "Row.h"
#include "Circuit.h"
#include "TruthTable.h"
using namespace std;

int main() {
    Row originalTable[8], simplifiedTable[8];
    int origSize, simpSize;
    string original, simplified;

    cout << "===========================================" << endl;
    cout << "    Digital_Logic_Circuit_Simplification   " << endl;
    cout << "           Group AO - Task 2                      " << endl;
    cout << "===========================================" << endl;
    cout << "\nGate symbols:" << endl;
    cout << "  v  = OR" << endl;
    cout << "  ^  = AND" << endl;
    cout << "  ~  = NOT" << endl;
    cout << "  +  = XOR         " << " ##it's extension in our code that you can use XOR " << endl;
    cout << "\n###one more thing to get known : \n";
    cout << "###we use the way we deal with logic gates in c++ as laws of parenthesis when using not e.g : (~(Av(~B)))^(A^B)v(~C) is not eqv to ~(Av(~B))^(A^B)v(~C)" << endl;
    cout << "\n\n 1. Always use parentheses to clarify order of operations.\n";
    cout << "   Example: (~(A v (~B))) ^ (A ^ B) v (~C)\n";
    cout << "   If you want AND to be evaluated before OR, add extra parentheses:\n";
    cout << "   ((~(A v (~B))) v (A ^ B)) ^ (C)\n";
    cout << "2. Only three variables are supported: A, B, C.\n";
    cout << "3. Expressions are case-sensitive, use uppercase letters.\n";
    cout << "4. Avoid spaces inside variable names or operators.\n";
    cout << "5. NOT (~) always applies to the next variable or parenthesis group.\n";
    cout << "\nExample of correct input:\n";
    cout << "   (~(A v (~B))) ^ (A ^ B) ^ C\n";
    cout << "===========================================\n\n";
    cout << "\nEnter ORIGINAL circuit expression: ";
    getline(cin, original);
    cout << "Enter SIMPLIFIED circuit expression: ";
    getline(cin, simplified);

    while (true) {  // To make the requirement number 6 in pdf
        cout << "\n\n====== ORIGINAL CIRCUIT ======" << endl;
        analyzeCircuit(original, originalTable, origSize);

        cout << "\n\n\n====== SIMPLIFIED CIRCUIT ======" << endl;
        analyzeCircuit(simplified, simplifiedTable, simpSize);

        cout << "\n\n\n" << endl;
        cout << "         EQUIVALENCE CHECK" << endl;
        cout << "========================================" << endl;
        if (areEquivalent(originalTable, origSize, simplifiedTable, simpSize)) {
            cout << "Result: EQUIVALENT (same truth table)" << endl;
        } else {
            cout << "Result: NOT EQUIVALENT (different outputs)" << endl;
        }

        string orgStatus = checkStatus(originalTable, origSize);
        string simpleStatus = checkStatus(simplifiedTable, simpSize);

        bool needFix = false;
        if (orgStatus == "SATISFIABLE" && simpleStatus == "SATISFIABLE") {
            cout << "\n" << endl;
            cout << "              SUMMARY" << endl;
            cout << "========================================" << endl;
            cout << "Original   : " << original << endl;
            cout << "Status     : " << orgStatus << endl;
            cout << "simplified expression : " << simplified << endl;
            cout << "status     : " << simpleStatus << endl;
            cout << "Check equivalency: "
                 << (areEquivalent(originalTable, origSize, simplifiedTable, simpSize) ? "YES" : "NO") << endl;
            cout << "========================================" << endl;

            cout << "\nBoth expressions are SATISFIABLE. Analysis complete!\n";
            break;
        }

        if (orgStatus == "TAUTOLOGY" || orgStatus == "UNSATISFIABLE") {
            cout << "\n*** ORIGINAL CIRCUIT is " << orgStatus << " ***" << endl;
            cout << "Please modify it by changing one gate to make it SATISFIABLE.\n";
            cout << "Enter new full expression: ";
            getline(cin, original);
            needFix = true;
        }

        if (simpleStatus == "TAUTOLOGY" || simpleStatus == "UNSATISFIABLE") {
            cout << "\n*** SIMPLIFIED CIRCUIT is " << simpleStatus << " ***" << endl;
            cout << "Please modify it by changing one gate to make it SATISFIABLE.\n";
            cout << "Enter new SIMPLIFIED expression: ";
            getline(cin, simplified);
            needFix = true;
        }

        if (needFix) {
            cout << "reanalyzing with corrected expressions...\n";
            continue;
        }
    }

    return 0;
}