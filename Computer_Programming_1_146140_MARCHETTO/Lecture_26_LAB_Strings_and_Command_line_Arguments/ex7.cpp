using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=2) {cout << "Incorrect input words number!" << endl; return 0;}

    string fName = argv[1];

    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << "Missing file name!" << endl; return 0;}

    int m; fIn >> m;
    int n; fIn >> n;

    int A[m][n] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){fIn >> A[i][j];}
    }

    int B[n][m] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){B[i][j] = A[j][i];}
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){cout << B[i][j] << " ";} cout << endl;
    }

    fIn.close();

    return 0;
}