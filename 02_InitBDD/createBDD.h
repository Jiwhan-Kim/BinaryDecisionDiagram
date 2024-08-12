#include "headers.h"

node_t* initnode(int num);
void recTree(int level, uint32_t dataidx, node_t* root);
node_t* createBDD(data_t* data, uint32_t* seq);
void recPrint(node_t* root);
