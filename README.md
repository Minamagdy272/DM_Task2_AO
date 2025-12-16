<<<<<<< HEAD
# DM Full Coded Task Implementation #
# Task2_GroupAO_DMTasks  
### Digital Logic Circuit Simplification - Group AO Submission  

> **Course**: Discrete Mathematics 
> **Task**: Task 2 – Group Assignment (Digital Circuit Simplification)  
> **Group**: AO  
> **Submitted by**: Mina Magdy Fayez Zaki  (@Minamagdy272) 
> **ID**: 2200675   

---

## 📌 Project Overview

This repository hosts the implementation for **Task 2** of the Digital Logic course, developed by **Group AO**. The project centers on the analysis, simplification, and programmatic evaluation of a digital logic circuit composed of 2-3 inputs using basic gates (AND, OR, NOT) and outputting to a light bulb indicator.

### Core Objectives
- **Analytical Simplification**: Manually simplify the given logical expression to its minimal form using Boolean algebra (performed on paper).
- **Truth Table Generation**: Compute truth tables for both original and simplified expressions.
- **Equivalence Verification**: Confirm if the simplified expression is logically equivalent to the original.
- **Satisfiability Analysis**: Identify input values that satisfy the circuit expression; handle unsatisfiable/tautology cases by gate modification.
- **User-Interactive C++ Program**: Build a modular C++ application that queries users for circuit details, builds truth tables, evaluates functions, and extends to other gate types.

The assigned circuit (visualized below) features inputs A, B, C connected through NOT, AND, OR gates to control a light bulb output.

![Circuit Diagram](circuit_diagram.png)  
*(Schematic: Inputs A (with NOT), B (with NOT), C (with NOT) feeding into a series of OR and AND gates, culminating in an AND gate to the light bulb.)*

We implemented all requirements in C++17, focusing on clean, extensible code with user input handling, truth table printing, and analytical reporting.

---

=======
# Task2_GroupAO_DMTasks# Digital Logic Circuit Simplification - Group AO Task 2

## Project Description
This program analyzes and compares digital logic circuits by generating truth tables and checking their equivalence. It supports AND, OR, NOT, and XOR gates.

## File Structure
```
├── Node.h              # Node structure definition
├── Node.cpp            # Node implementation
├── Row.h               # Truth table row structure
├── Parser.h            # Expression parser header
├── Parser.cpp          # Expression parser implementation
├── Evaluator.h         # Expression evaluator header
├── Evaluator.cpp       # Expression evaluator implementation
├── TruthTable.h        # Truth table operations header
├── TruthTable.cpp      # Truth table operations implementation
├── Circuit.h           # Circuit analysis header
├── Circuit.cpp         # Circuit analysis implementation
├── main.cpp            # Main program entry point
└── README.md           # This file
```

## Compilation Instructions

### Using g++:
```bash
g++ -o circuit main.cpp Node.cpp Parser.cpp Evaluator.cpp TruthTable.cpp Circuit.cpp
```

### Using a Makefile (optional):
Create a `Makefile` with the following content:
```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = circuit
OBJS = main.o Node.o Parser.o Evaluator.o TruthTable.o Circuit.o

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

clean:
    rm -f $(OBJS) $(TARGET)
```

Then run:
```bash
make
```

## Running the Program
```bash
./circuit
```

## Usage

### Gate Symbols:
- `v` = OR
- `^` = AND
- `~` = NOT
- `+` = XOR

### Input Rules:
1. Always use parentheses to clarify order of operations
2. Only three variables are supported: A, B, C
3. Expressions are case-sensitive, use uppercase letters
4. Avoid spaces inside variable names or operators
5. NOT (~) always applies to the next variable or parenthesis group

### Example Input:
```
Original circuit: (~(A v (~B))) ^ (A ^ B) ^ C
Simplified circuit: A ^ B ^ C
```

## Features
- Parse logical expressions into expression trees
- Generate truth tables for circuits
- Check circuit equivalence
- Determine if circuits are SATISFIABLE, TAUTOLOGY, or UNSATISFIABLE
- Interactive correction if circuits are not satisfiable

## Group Information
**Group:** AO  
**Task:** 2  
**Project:** Digital Logic Circuit Simplification
>>>>>>> b3e99f3 ( a new edit)
# DM_Task2_AO