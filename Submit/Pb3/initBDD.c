#include "initBDD.h"

uint32_t const twos_b[32] = {
    0x00000001, 0x00000002, 0x00000004, 0x00000008,
    0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800,
    0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000,
    0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000,
    0x10000000, 0x20000000, 0x40000000, 0x80000000
};

data_t* readData(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return NULL;
    }
    
    data_t* data = (data_t*)malloc(sizeof(data_t));
    data->cnt = 0;

    char line[1024];
    if (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, " ");
        while (token != NULL) {
            strcpy(data->names[data->cnt], token);
            data->cnt += 1;
            token = strtok(NULL, " ");
        }
    }
    
    rewind(fp);
    fgets(line, sizeof(line), fp);

    int i = 0;
    int j = 0;

    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            data->matrix[i][j] = atoi(token);
            token = strtok(NULL, " ");
            j++;
        }
        i++;
        j = 0;
    }
    fclose(fp);
     data->cnt -= 1;
    return data; 
}
