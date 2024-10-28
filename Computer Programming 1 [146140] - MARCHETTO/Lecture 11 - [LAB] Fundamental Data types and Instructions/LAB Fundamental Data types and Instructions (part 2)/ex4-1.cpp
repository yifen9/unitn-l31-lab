using namespace std;
#include <iostream>

int main(){
    int n;
    cout << "Please input n: ";
    cin >> n;

    float F0=0,F1=1;
    
    if(n<=1){
        if(n==0){cout << "Fn = " << F0 << endl;}
        else{cout << "Fn = " << F1 << endl;}
    }
    else{
        for(int i=1; i<=(n/2); i++){
            F0 += F1;
            F1 += F0;
        }
        if(n%2==1){cout << "Fn = " << float(F0+F1) << endl;}
        else{cout << "Fn = " << F1 << endl;}
    }

    return 0;
}