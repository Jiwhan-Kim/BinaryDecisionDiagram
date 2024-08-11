#include "initBDD.h"

vector<vector<int>> readDesign(const char* name) {
    ifstream file(name, ios::in);
    if (!file.is_open()) return vector<vector<int>>();

    vector<vector<int>> data;
    string line;

    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}

void deleteDesign();
