#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_COLS 16

#ifndef ONES
#define ONES 1

typedef struct data_tt{
    int cnt; // number of columns
    int matrix[0x10000][MAX_COLS + 1];
} data_t;

typedef struct node_tt{
    int n;
    struct node_tt* left;
    struct node_tt* right;
} node_t;

#endif


