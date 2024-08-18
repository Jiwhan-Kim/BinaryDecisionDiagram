#include <iostream>
#include <fstream>

using namespace std;
uint32_t truth[256][3];

int main(int argc, char* argv[]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            truth[i*16+j][0] = i;
            truth[i*16+j][1] = j;
            truth[i*16+j][2] = i + j;
        }
    }
    
    ofstream fS0("S0.txt", ios::out | ios::binary);
    fS0 << "a3 a2 a1 a0 b3 b2 b1 b0 y" << endl;
    for (int i = 0 ; i < 256; i++) {
        fS0 << ((truth[i][0] >> 3) & 1) << " " << ((truth[i][0] >> 2) & 1) << " " << ((truth[i][0] >> 1) & 1) << " " << (truth[i][0] & 1);
        fS0 << " ";
        fS0 << ((truth[i][1] >> 3) & 1) << " " << ((truth[i][1] >> 2) & 1) << " " << ((truth[i][1] >> 1) & 1) << " " << (truth[i][1] & 1);
        fS0 << " ";
        fS0 << (truth[i][2] & 1);
        fS0 << endl;
    }
    fS0.close();

    ofstream fS1("S1.txt", ios::out | ios::binary);
    fS1 << "a3 a2 a1 a0 b3 b2 b1 b0 y" << endl;
    for (int i = 0 ; i < 256; i++) {
        fS1 << ((truth[i][0] >> 3) & 1) << " " << ((truth[i][0] >> 2) & 1) << " " << ((truth[i][0] >> 1) & 1) << " " << (truth[i][0] & 1);
        fS1 << " ";
        fS1 << ((truth[i][1] >> 3) & 1) << " " << ((truth[i][1] >> 2) & 1) << " " << ((truth[i][1] >> 1) & 1) << " " << (truth[i][1] & 1);
        fS1 << " ";
        fS1 << ((truth[i][2] >> 1) & 1);
        fS1 << endl;
    }
    fS1.close();

    ofstream fS2("S2.txt", ios::out | ios::binary);
    fS2 << "a3 a2 a1 a0 b3 b2 b1 b0 y" << endl;
    for (int i = 0 ; i < 256; i++) {
        fS2 << ((truth[i][0] >> 3) & 1) << " " << ((truth[i][0] >> 2) & 1) << " " << ((truth[i][0] >> 1) & 1) << " " << (truth[i][0] & 1);
        fS2 << " ";
        fS2 << ((truth[i][1] >> 3) & 1) << " " << ((truth[i][1] >> 2) & 1) << " " << ((truth[i][1] >> 1) & 1) << " " << (truth[i][1] & 1);
        fS2 << " ";
        fS2 << ((truth[i][2] >> 2) & 1);
        fS2 << endl;
    }
    fS2.close();

    ofstream fS3("S3.txt", ios::out | ios::binary);
    fS3 << "a3 a2 a1 a0 b3 b2 b1 b0 y" << endl;
    for (int i = 0 ; i < 256; i++) {
        fS3 << ((truth[i][0] >> 3) & 1) << " " << ((truth[i][0] >> 2) & 1) << " " << ((truth[i][0] >> 1) & 1) << " " << (truth[i][0] & 1);
        fS3 << " ";
        fS3 << ((truth[i][1] >> 3) & 1) << " " << ((truth[i][1] >> 2) & 1) << " " << ((truth[i][1] >> 1) & 1) << " " << (truth[i][1] & 1);
        fS3 << " ";
        fS3 << ((truth[i][2] >> 3) & 1);
        fS3 << endl;
    }
    fS3.close();
 
    ofstream fOut("Carry.txt", ios::out | ios::binary);
    fOut << "a3 a2 a1 a0 b3 b2 b1 b0 y" << endl;
    for (int i = 0 ; i < 256; i++) {
        fOut << ((truth[i][0] >> 3) & 1) << " " << ((truth[i][0] >> 2) & 1) << " " << ((truth[i][0] >> 1) & 1) << " " << (truth[i][0] & 1);
        fOut << " ";
        fOut << ((truth[i][1] >> 3) & 1) << " " << ((truth[i][1] >> 2) & 1) << " " << ((truth[i][1] >> 1) & 1) << " " << (truth[i][1] & 1);
        fOut << " ";
        fOut << ((truth[i][2] >> 4) & 1);
        fOut << endl;
    }
    fOut.close();
 
    

    return 0;
}
