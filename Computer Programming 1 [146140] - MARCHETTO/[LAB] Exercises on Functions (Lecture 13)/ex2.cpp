using namespace std;
#include <iostream>
#include <cctype>

bool checkLowercase1(char);

bool checkLowercase2(char);

int main(){
    char i;
    cout << "Please input a lowercase character: ";
    cin >> i;

    cout << "1: ";
    if (checkLowercase1(i)){
        cout << "uppercase: " << char(i+('A'-'a')) << endl;}
    else {
        cout << "No lowercase detacted" << endl;}

    cout << "2: ";
    if (checkLowercase2(i)){
        cout << "uppercase: " << char(toupper(i)) << endl;}
    else {
        cout << "No lowercase detacted" << endl;}

    return 0;
}

bool checkLowercase1(char i){return (i<='z' && i>='a');}

bool checkLowercase2(char i){return (islower(i));}