using namespace std;
#include <iostream>

bool checkLowercase(char);

int main(){
    char i;
    cout << "Please input a lowercase character: ";
    cin >> i;

    if (checkLowercase(i)){cout << "uppercase: " << char(i+('A'-'a')) << endl;}
    else {cout << "No lowercase detacted" << endl;}

    return 0;
}

bool checkLowercase(char i){return (i<='z' && i>='a');}