#include "createBDD.h"
#include "initBDD.h"
#include "printBDD.h"
#include "reduceBDD.h"

int main(int argc, char *argv[]) {
    char filename[256] = "../01_4bitFA/S0.txt";
    if (argc >= 2) strcpy(filename, argv[1]);

    printf("Reading file: %s\n", filename);
    data_t* data = readData(filename);
    printf("Reading file done\n");

    printf("Creating BDD\n");
    uint32_t sequence[MAX_COLS] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    node_t* root = createBDD(data, sequence); 

    printf("Reducing BDD\n");
    reduceBDD(root);
    printf("Reducing BDD done\n");

    printBDD(root);
    printVisualFormat(root, data); 
    return 0;
}
