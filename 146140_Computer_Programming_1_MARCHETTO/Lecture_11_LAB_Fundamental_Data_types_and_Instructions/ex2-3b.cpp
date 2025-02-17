using namespace std;
#include <iostream>

int main(){
    char ci;
    cout << "Please input a character: ";
    cin >> ci;

    int v;
    cout << "Please input a variant: ";
    cin >> v;

    cout << "plus: " << char(ci+v) << endl;
    cout << "minus: " << char(ci-v) << endl;

    return 0;
}