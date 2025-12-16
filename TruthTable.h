#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

#include "Node.h"
#include "Row.h"
#include <string>
using namespace std;

// Truth table functions
void buildTableTree(Node* root, Row table[], int &size);
void printTable(string title, Row table[], int size);
bool areEquivalent(Row t1[], int s1, Row t2[], int s2);
string checkStatus(Row table[], int size);
void showSatisfying(Row table[], int size);

#endif