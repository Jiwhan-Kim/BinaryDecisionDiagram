#include "printBDD.h"

uint32_t getNodes(node_t* root) {
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    return 1 + getNodes(root->left) + getNodes(root->right);
}

void printBDD(node_t* root) {
    uint32_t numNodes = getNodes(root);
    printf("Number of nodes: %d\n", numNodes);
}
