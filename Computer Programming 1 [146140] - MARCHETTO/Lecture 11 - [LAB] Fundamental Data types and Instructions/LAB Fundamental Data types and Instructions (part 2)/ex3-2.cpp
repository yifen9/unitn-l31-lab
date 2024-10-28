using namespace std;
#include <iostream>
#include <cmath>

int main(){
    float i;
    cout << "Please input a value: ";
    cin >> i;

    cout << "1: " << abs(i) << endl;
    
    if (i>=0) {cout << "2: " << i << endl;}
    else {cout << "2: " << -i << endl;}

    cout << "3: " << float((i>=0)?i:-i) << endl;

    return 0;
}