using namespace std;
#include <iostream>

int main(){
    bool a,b;

    cout << "XOR gate: " << endl;
    cout << "A B output" << endl;
    
    a=0; b=0;
    cout << a << " " << b << " " << (!(a&&b) && (a||b)) << endl;
    a=1; b=0;
    cout << a << " " << b << " " << (!(a&&b) && (a||b)) << endl;
    a=0; b=1;
    cout << a << " " << b << " " << (!(a&&b) && (a||b)) << endl;
    a=1; b=1;
    cout << a << " " << b << " " << (!(a&&b) && (a||b)) << endl;

    return 0;
}