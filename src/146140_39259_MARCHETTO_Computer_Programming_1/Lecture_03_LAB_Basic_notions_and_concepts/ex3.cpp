using namespace std;
#include <iostream>
#include <cstring>

int main(){
    string up;
    cout << "Please input chars in uppercase: ";
    cin >> up;

    char c = up[0];
    int len = 0;
    while(c){
        len++;
        c = up[len];
    }

    cout << "lowercase: ";

    string low[len];
    for(int i=0; i < len;i++){cout << char(up[i] - ('A'-'a'));}

    cout << endl;

    return 0;
}