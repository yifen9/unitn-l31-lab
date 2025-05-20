using namespace std;
#include <iostream>
#include <cctype>

int main(){
    char ci;
    cout << "Please input a character: ";
    cin >> ci;

    cout << "uppercase: " << char(toupper(ci)) << endl;

    return 0;
}