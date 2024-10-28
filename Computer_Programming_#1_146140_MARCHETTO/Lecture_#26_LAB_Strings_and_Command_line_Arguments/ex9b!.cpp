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

    fIn.close();

    return 0;
}