using namespace std;
#include <iostream>

void swapNum(double*,double*);

int main(){
    double a,b;
    cout << "Please input two number:" << endl;
    cout << " A: "; cin >> a;
    cout << " B: "; cin >> b;

    swapNum(&a,&b);

    cout << "After swap:" << endl 
        << " A: " << a << endl 
        << " B: " << b << endl;

    return 0;
}

void swapNum(double* a, double* b){swap(*a,*b);}
