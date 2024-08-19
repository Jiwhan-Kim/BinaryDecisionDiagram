#include "createBDD.h"
#include "initBDD.h"
#include "printBDD.h"
#include "reduceBDD.h"
#include "permute.h"

int main(int argc, char *argv[]) {
    // char filename[256] = "input.txt";
    char filename[5][256] = {
        "../Pb1/output/S0.txt",
        "../Pb1/output/S1.txt",
        "../Pb1/output/S2.txt",
        "../Pb1/output/S3.txt",
        "../Pb1/output/Carry.txt"
    };
    int mode = 0; // 0 - original BDD, 1 - reduced BDD
    /*
    if (argc >= 2) strcpy(filename, argv[1]);
    if (argc >= 3) mode = atoi(argv[2]);
    */
    if (mode != 0 && mode != 1) {
        printf("Invalid mode\n");
        return 1;
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Reading file: %s\n", filename[i]);
        data_t* data = readData(filename[i]);
        if (data == NULL) {
            printf("Error reading file\n");
            return 1;
        }
        printf("Reading file done\n");

        printf("Searching BDD\n");
        printf("Selected Mode: ");
        node_t* root;
        if (mode == 0) {
            printf("Original BDD\n");
            uint32_t seq[MAX_COLS];
            for (int i = 0; i < data->cnt; i++) seq[i] = i;
            root = createBDD(data, seq);
        }

        if (mode == 1) {
            printf("Reduced BDD\n");
            root = bestNode(data);
        }
        
        printf("BDD found\n");
        printf("BDD size: %d\n", getFullNodes(root));
        printVisualFormat(root, data, filename[i] + 14); 

        printf("\n\n");
    }
    return 0;
}
