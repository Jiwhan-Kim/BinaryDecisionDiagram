#include "initBDD.h"
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    char filename[256] = "../01_4bitFA/S0.txt";
    if (argc >= 2) {
        strcpy(filename, argv[1]);
    }
    cout << "Reading file: " << filename << endl;

    vector<vector<int>> data = readDesign(filename);

    // Print the data
    /*
    for (const auto& row: data) {
        for (const auto& val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
    */


    return 0;
}
