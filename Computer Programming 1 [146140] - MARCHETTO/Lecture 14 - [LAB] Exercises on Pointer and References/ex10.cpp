using namespace std;
#include <iostream>

void swapV2(short&,short&);

int main(){
    short a,b;
    cout << "Please input two integers:" << endl;
    cout << " A: "; cin >> a;
    cout << " B: "; cin >> b;

    swapV2(a,b);

    cout << "Result:" << endl 
        << " A: " << a << endl 
        << " B: " << b << endl;
}

void swapV2(short& a,short& b){
    short ra = a%256, rb = b%256;
    a = a-ra+rb;
    b = b-rb+ra;
}