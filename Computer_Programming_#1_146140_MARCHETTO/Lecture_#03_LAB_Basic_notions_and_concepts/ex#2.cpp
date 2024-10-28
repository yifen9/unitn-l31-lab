using namespace std;
#include <iostream>

int main(){
    int de, ds;
    cout << "Please input dividend number and divisor number: " << endl;
    cin >> de >> ds;

    cout << "Quotient: " << de/ds << endl;
    cout << "Remainder: " << de%ds << endl;

    return 0;
}