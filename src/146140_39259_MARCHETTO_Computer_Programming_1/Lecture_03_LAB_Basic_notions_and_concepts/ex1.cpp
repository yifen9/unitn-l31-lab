using namespace std;
#include <iostream>

int main(){
    float r, pi = 3.14;
    cout << "Please input radius: ";
    cin >> r;

    float C = 2*pi*r;
    float A = pi*r*r;

    cout << "Circumference = " << C << endl;
    cout << "Area = " << A << endl;

    return 0;
}