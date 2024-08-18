#include "headers.h"

node_t* initnode(int num, int cord);
void recTree(int level, int cord, uint32_t dataidx, node_t* root);
node_t* createBDD(data_t* data, uint32_t* seq);
