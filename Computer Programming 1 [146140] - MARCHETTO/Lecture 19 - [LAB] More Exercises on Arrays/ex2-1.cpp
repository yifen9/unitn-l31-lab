using namespace std;
#include <iostream>
#include <string>

int main(){
    string I;
    cout << "Please input a string: ";
    cin >> I;

    int len = 0;
    while(I[len]){len++;}
    
    int A[len] = {0};
    for(int i=0; i<len; i++){A[i]=I[i]-int('0');}

    cout << "Array: ";
    for(int i=0; i<len; i++){cout << A[i];}
    cout << endl;

    return 0;
}