using namespace std;
#include <iostream>

int main(){
    char ci;
    cout << "Please input a character: ";
    cin >> ci;

    cout << "plus 10: " << char(ci+10) << endl;
    cout << "minus 10: " << char(ci-10) << endl;

    return 0;
}