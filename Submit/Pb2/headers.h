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
    char names[MAX_COLS][0x10]; // maximum 15 characters
} data_t;

typedef struct node_tt{
    int n;
    int cord;
    struct node_tt* left;
    struct node_tt* right;
} node_t;

typedef struct {
    int type; // 0 for no node, 1 for node, 2 for boolean
    int value; // node number or boolean value
} format_t;

#endif


