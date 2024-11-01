using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=4) {cout << "Incorrect input words number!" << endl; return 0;}
    
    string fA = argv[1], fB = argv[2], fC = argv[3];

    fstream inA, inB, outC;
    inA.open(fA, ios::in);
    inB.open(fB, ios::in);
    outC.open(fC, ios :: out | ios :: app);

    if(!(inA.is_open()) || !(inB.is_open())) {cout << "Missing file name!" << endl; return 0;}

    string f;
    while(inA >> f) {outC << f << endl;}
    while(inB >> f) {outC << f << endl;}

    inA.close();
    inB.close();
    outC.close();

    return 0;
}