#include "createBDD.h"

data_t* data_ref;
uint32_t* seq_ref;

uint32_t const twos_a[32] = {
    0x00000001, 0x00000002, 0x00000004, 0x00000008,
    0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800,
    0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000,
    0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000,
    0x10000000, 0x20000000, 0x40000000, 0x80000000
};

node_t* initnode(int num) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->n = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void recTree(int level, uint32_t dataidx, node_t* root) {
    if (level == data_ref->cnt - 1) {
        root->left = initnode(data_ref->matrix[dataidx][data_ref->cnt]);
        root->right = initnode(data_ref->matrix[dataidx + twos_a[data_ref->cnt - 1 - seq_ref[level]]][data_ref->cnt]);
        return;
    } 
    root->left = initnode(seq_ref[level + 1]);
    recTree(level + 1, dataidx, root->left);
    root->right = initnode(seq_ref[level + 1]);
    recTree(level + 1, dataidx + twos_a[data_ref->cnt - 1 - seq_ref[level]], root->right);
}

node_t* createBDD(data_t* data, uint32_t* seq) {
    data_ref = data;
    seq_ref = seq;

    node_t* root = initnode(seq[0]);
    recTree(0, 0, root);

    return root;    
}

void recPrint(node_t* root) {
    if (root == NULL) return;
    recPrint(root->left);
    if (root -> left == NULL && root -> right == NULL) printf("%d ", root->n);
    recPrint(root->right);
}
