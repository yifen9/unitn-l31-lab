using namespace std;
#include <iostream>

void excess(int&,int&);

int division(int,int,int&);

int main(){
    int sec,min,hour;
    cout << "Please input three integers:" << endl;
    cout << " sec: "; cin >> sec;
    cout << " min: "; cin >> min;
    cout << " hour: "; cin >> hour;

    excess(sec,min);
    excess(min,hour);

    cout << "Result:" << endl 
        << " sec: " << sec << endl 
        << " min: " << min << endl 
        << " hour: " << hour << endl;

    return 0;
}

void excess(int& a,int& b){
    int rest;
    b += division(a,60,rest);
    a = rest;
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
