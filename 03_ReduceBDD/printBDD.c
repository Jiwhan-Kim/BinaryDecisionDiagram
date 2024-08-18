#include "printBDD.h"

uint32_t getNodes(node_t* root) {
    if ((root->left == NULL) && (root->right == NULL)) {
        return 0;
    }
    return 1 + getNodes(root->left) + getNodes(root->right);
}

void printBDD(node_t* root) {
    uint32_t numNodes = getNodes(root);
    printf("Number of nodes: %d\n", numNodes);
}

format_t format[0x100001];

void recGetData(node_t* root) {
    if (root->left == NULL && root->right == NULL) {
        format[root->cord].type = 2; // boolean
        format[root->cord].value = root->n;
        if (root->cord > format[0].value) {
            format[0].value = root->cord;
        }
        return;
    }
    format[root->cord].type = 1; // node
    format[root->cord].value = root->n;
    recGetData(root->left);
    recGetData(root->right);
}

void printVisualFormat(node_t* root, data_t* data) {
    FILE* fp = fopen("./output/tree.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    format[0].value = 0; // maximum index
    recGetData(root);

    for (int i = 1; i <= format[0].value; i++) {
        if (format[i].type == 1) { // node
            fprintf(fp, "N %s\n", data->names[format[i].value]);
        } else if (format[i].type == 2){ // boolean
            fprintf(fp, "B %d\n", format[i].value);
        } else { // no node
            fprintf(fp, "X X\n");
        }
    } 
}
