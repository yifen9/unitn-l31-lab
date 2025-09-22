using namespace std;
#include <iostream>

bool islower(char);

void toupper(char&);

int main(){
    char c;
    cout << "Please input a character with lowercase: ";
    cin >> c;

    if(islower(c)){
        toupper(c);
        cout << "Uppercase: " << c << endl;
    }
    else {cout << "None" << endl;}

    return 0;
}

bool islower(char c){return ((c <= 'z' && c >= 'a')? true: false);}

void toupper(char& c){c += ('A'-'a');}
