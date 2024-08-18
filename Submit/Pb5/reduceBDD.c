#include "reduceBDD.h"

int isIdentical(node_t* left, node_t* right) {
    // returns 1 if the nodes are identical
    if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
        return 0; 
    }
    else if (left->left == NULL && left->right == NULL && right->left == NULL && right->right == NULL)
        return left->n == right->n; // 0 or 1
    else if (left->n != right->n){
        return 0;
    }

    int isLeftIdentical = isIdentical(left->left, right->left);
    int isRightIdentical = isIdentical(left->right, right->right);
    return isLeftIdentical && isRightIdentical;

}

void updateCord(node_t* root, int cord) {
    if (root == NULL) return;
    root->cord = cord;
    updateCord(root->left, cord * 2);
    updateCord(root->right, cord * 2 + 1);
}

// rec function
void reduceBDD(node_t* root) {
    if (root->left == NULL && root->right == NULL) return;
    reduceBDD(root->left);
    reduceBDD(root->right);
    
    if (isIdentical(root->left, root->right)) {
        node_t* old = root->left;
        clearBDD(root->right);
        root->n = old->n;
        root->left = old->left;
        root->right = old->right;
        free(old);
        updateCord(root, root->cord);
    }
}


void clearBDD(node_t* root) {
    if (root->left != NULL) {
        clearBDD(root->left);
    }
    if (root->right != NULL) {
        clearBDD(root->right);
    }
    free(root);
}
