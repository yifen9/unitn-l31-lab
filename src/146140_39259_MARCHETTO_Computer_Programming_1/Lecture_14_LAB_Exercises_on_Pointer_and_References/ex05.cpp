using namespace std;
#include <iostream>

int division(int,int,int&);

int main(){
    int a,b,rest;
    cout << "Please input two integers:" << endl;
    cout << " A: "; cin >> a;
    cout << " B: "; cin >> b;

    int quotient = division(a,b,rest);

    cout << "Result:" << endl 
        << " Quotient: " << quotient << endl 
        << " Rest: " << rest << endl;

    return 0;
}

int division(int a, int b, int& rest){
    int quotient = 0;
    while(a>=b){
        a -= b;
        quotient++;
    }

    rest = a;
    
    return quotient;
}
