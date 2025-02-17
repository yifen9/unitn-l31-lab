using namespace std;
#include <iostream>

int main(){
    int A;
    cout << "Please input A: ";
    cin >> A;

    for(int i=0; i<A; i++){
        for(int j=0; j<(A-i-1); j++){cout << " ";}
        for(int j=0; j<(i*2+1); j++){cout << "*";}
        for(int j=0; j<(A-i-1); j++){cout << " ";}

        cout << endl;
    }

    return 0;
}