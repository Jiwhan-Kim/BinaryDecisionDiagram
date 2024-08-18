#include "permute.h"

data_t* data;
node_t* best;
int lowest_node = 0x7fffffff;

void swap(uint32_t* x, uint32_t* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(uint32_t* seq, int start, int end) {
    if (start == end) {
        node_t* root = createBDD(data, seq);
        reduceBDD(root);

        int cnt = getNodes(root); 
        if (cnt < lowest_node) {
            lowest_node = cnt;
            best = root;
        } else {
            clearBDD(root);
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap((seq + start), seq + i);
            permute(seq, start + 1, end);
            swap((seq + start), seq + i);
        }
    }
}

node_t* bestNode(data_t* data_ref) {
    data = data_ref;
    best = NULL;
    lowest_node = 0x7fffffff;
    int n = data->cnt;
    uint32_t seq[MAX_COLS];
    for (int i = 0; i < n; i++) {
        seq[i] = i;
    }
    permute(seq, 0, n - 1);
    return best;
}
