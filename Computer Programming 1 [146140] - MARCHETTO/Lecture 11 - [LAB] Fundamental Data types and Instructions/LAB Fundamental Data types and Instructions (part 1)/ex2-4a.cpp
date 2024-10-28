using namespace std;
#include <iostream>

int main(){
    char ci;
    cout << "Please input a character: ";
    cin >> ci;

    cout << "uppercase: " << char(ci + ('A'-'a')) << endl;

    return 0;
}