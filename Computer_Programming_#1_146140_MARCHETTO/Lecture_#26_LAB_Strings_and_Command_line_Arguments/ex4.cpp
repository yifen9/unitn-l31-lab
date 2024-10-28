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
    int A[100] = {0}, B[100] = {0}, n1=0, n2=0;
    while(inA >> f) {n1++; A[n1-1]=stoi(f);}
    while(inB >> f) {n2++; B[n2-1]=stoi(f);}

    int a1 = 0, a2 = 0;
    for(int i=0; i<n1; i++){a1 += A[i];}
    for(int i=0; i<n2; i++){a2 += B[i];}

    outC << (float(a1)/float(n1)) << endl;
    outC << (float(a2)/float(n2)) << endl;

    inA.close();
    inB.close();
    outC.close();

    return 0;
}