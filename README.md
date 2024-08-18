# BinaryDecisionDiagram

## How to compile?
Do `make` on your terminal in the desired project directory.

If you want to compile the project `./03_ReduceBDD`, `make` on `./03_ReduceBDD`.

If your computer doesn't support `Makefile`, compile each `*.c` into object files (`*.o`) and link them.

## Project
### 01_4bitFA
A 4-bit Full Adder to Truth-Table conversion. The code is written in `cpp`.

The output file will be stored in `./01_4bitFA/Submit/`. Be sure the directory has been created (by `mkdir` or ...) before you run the program.

### 02_InitBDD
The `main.c` will create a general BDD. No reduction has been done in this level.

The output of `createBDD()` on `./02_InitBDD/createBDD.c` will be a `node_t*` type root. (`node_t` is declared on `headers.h` on every BDD-related projects.)

`printBDD()` on `./02_InitBDD/printBDD.c` will print the number of nodes in the tree. The node indicating boolean values `0`, `1` will not be counted on this.

For example, `z = x & y` would have 3 nodes, not 7 including boolean nodes.

### 03_ReduceBDD
The `main.c` will create a reduced BDD.

The `reduceBDD()` on `./03_ReduceBDD/reduceBDD.c` will reduce a tree made by `createBDD()`. As a result, the least-significant-bit of 4-bit Full Adder will have only 3 nodes.

The `printVisualFormat()` on the same route will print a tree starting the index 1. Index 1 will indicate the one node on the top. Index 2, 3 will indicate each left and right node of the root node. Multiply 2 on the coordinate of parent nodes will indicate left-child node, and add 1 on it to indicate right-child node.


