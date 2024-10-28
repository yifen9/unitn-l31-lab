using namespace std;
#include <iostream>

int main(){
    float P,I;
    cout << "Please input the price: ";
    cin >> P;
    cout << "Please input the vat: ";
    cin >> I;

    float CP = P + (P*I)/100;

    cout.precision(5);
    cout << "customer price: " << CP << endl;

    return 0;
}