#include "headers.h"

uint32_t getNodes(node_t*);
void printBDD(node_t*);

typedef struct {
    int type; // 0 for no node, 1 for node, 2 for boolean
    int value; // node number or boolean value
} format_t;

void printVisualFormat(node_t* root, data_t* data);
