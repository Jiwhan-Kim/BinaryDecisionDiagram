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

uint32_t const twos[32] = {
    0x00000001, 0x00000002, 0x00000004, 0x00000008,
    0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800,
    0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000,
    0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000,
    0x10000000, 0x20000000, 0x40000000, 0x80000000
};

void printVisualFormat(node_t* root, data_t* data) {
    FILE* fp = fopen("./output/tree.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    format[0].value = 0; // maximum index
    recGetData(root);
   
    int two = 0;
    while (format[0].value > twos[two]) two++;

    fprintf(fp, "TotalVariables %d\n", data->cnt);
    fprintf(fp, "TotalNodes %d\n", getNodes(root));
    fprintf(fp, "TotalTreeNodes %d\n", twos[two] - 1);

    for (int i = 1; i < twos[two]; i++) {
        if (format[i].type == 1) { // node
            fprintf(fp, "N %s\n", data->names[format[i].value]);
        } else if (format[i].type == 2){ // boolean
            fprintf(fp, "B %d\n", format[i].value);
        } else { // no node
            fprintf(fp, "X X\n");
        }
    } 
}
