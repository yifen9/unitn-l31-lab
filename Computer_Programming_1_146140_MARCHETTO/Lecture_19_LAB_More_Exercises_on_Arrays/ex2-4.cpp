using namespace std;
#include <iostream>
#include <string>

int main(){
    string I1,I2;
    cout << "Please input two strings: " << endl;
    cin >> I1 >> I2;

    int len1 = 0; while(I1[len1]){len1++;}
    int len2 = 0; while(I2[len2]){len2++;}

    int len = ((len1>len2)?len1:len2) + 1;
    
    int A[len] = {0}; for(int i=0; i<len1; i++){A[i]=I1[len1-i-1]-int('0');}
    int B[len] = {0}; for(int i=0; i<len2; i++){B[i]=I2[len2-i-1]-int('0');}

    int add, r=0;
    int C[len] = {0};
    for(int i=0; i<(len-1); i++){
        add = A[i]+B[i]+r;
        C[i] = add % 10;
        r = (add > 9);
    }

    if(r){C[len-1]=1; len++;}

    cout << "Sum: ";
    for(int i=0; i<len-1; i++){cout << C[len-i-2];}
    cout << endl;

    return 0;
}