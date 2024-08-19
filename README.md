# BinaryDecisionDiagram

## How to run?
1. Compile and run the algorithms
    - Type `make` on your terminal in the desired project directory.
        - If you want to compile the project `./03_ReduceBDD`, `make` on `./03_ReduceBDD`.
    - Or, compile each `*.c` into the object files `*.o` and link them into executable.
    - You may change the extension of final executable from `*.out` to `*.exe` if you are running this on windows.
2. Visualize
    - Import the environment using `conda`. (Be sure that `conda` is already installed.) `conda env create -f ./environment.yml` to import the environment.
    - You may activate the environment by `conda activate BDD`.
    - Or, you can manully install the modules using `pip install ...`



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
`make` will get two arguments - a path to the input file (default: `input.txt`) and a mode (default: `0`, or original BDD). You can specify the mode to `1` or reduced BDD.

The `reduceBDD()` on `./03_ReduceBDD/reduceBDD.c` will reduce a tree made by `createBDD()`. As a result, the least-significant-bit of 4-bit Full Adder will have only 3 nodes.

The `bestNode()` on `./03_ReduceBDD/permute.c` will return a tree with minimum number of nodes. It checks all the sequences using permutation, and return the best one.

The `printVisualFormat()` on the same route will print a tree starting the index 1. Index 1 will indicate the one node on the top. Index 2, 3 will indicate each left and right node of the root node. Multiply 2 on the coordinate of parent nodes will indicate left-child node, and add 1 on it to indicate right-child node.

Check more infos in PR message (#8).


## Submitted Files
1. 4-bit Full Adder Truth Table

Path: `./Submit/Pb1`

Result: `./Submit/Pb1/output`

Compile `main.cpp` using `Makefile` and run the executable to regenerate the truth tables.

2. 4-bit Full Adder BDD & Visualization

4. Reduction of 4-bit Full Adder BDD

Path: `./Submit/Pb2`

Result: `./Submit/Pb2/output`

Compile `*.c` and execute `main.out`. It will print the number of the nodes.

Then `python main.py` to make an DAG - Directed Acylclic Graph.


3. General BDD & Visualization

5. Reduction of General BDD

Path: `./Submit/Pb3`

Result: `./Submit/Pb2/output`

Give an input file as `input.txt`. There already exists an `input.txt`, but you can manually change the file.

Compile `*.c` and execute `main.out`. It will print the number of the nodes.

Then `python main.py` to make an DAG - Directed Acylclic Graph.

