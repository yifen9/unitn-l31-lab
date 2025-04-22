using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

bool amtNum(int);

int main(int argc, char *argv[]){
    if(argc!=2) {cout << "Incorrect input words number!" << endl; return 0;}

    string fName = argv[1];

    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << "Missing file name!" << endl; return 0;}

    int A[10];
    for(int i=0; i<10; i++){fIn >> A[i];}

    for(int i=0; i<10; i++){
        cout << endl;
        cout << "Number: " << A[i] << endl;
        cout << " - ";

        if(amtNum(A[i])){cout << "Armostrong number" << endl;}
        else{cout << "not an Armostrong number" << endl;}
    }

    fIn.close();

    return 0;
}

bool amtNum(int input){
    int num=input, A[100] = {0};
    int re=num, i=0;
    while(re>10){
        num = re;
        re /= 10;
        A[i] = num%re;
        i++;
    }
    A[i] = re;
    i++;
    
    int product, res=0;
    for(int j=0; j<i; j++){
        product = 1;
        for(int k=0; k<i; k++){product *= A[j];}
        res += product;
    }

    return (res==input);
}