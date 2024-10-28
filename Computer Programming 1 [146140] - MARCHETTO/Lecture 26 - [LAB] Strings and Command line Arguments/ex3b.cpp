using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=3) {cout << "Incorrect input words number!" << endl; return 0;}

    string fA = argv[1], fB = argv[2];

    fstream inA, inB;
    inA.open(fA, ios :: out | ios :: app);
    inB.open(fB, ios::in);

    if(!(inA.is_open())) {cout << "Missing file name!" << endl; return 0;}

    string f;

    inB >> f;
    inA << f;

    inA.close();
    inB.close();

    return 0;
}