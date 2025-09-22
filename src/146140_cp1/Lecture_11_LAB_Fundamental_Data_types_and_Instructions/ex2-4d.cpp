using namespace std;
#include <iostream>
#include <cstring>

int main(){
    string up;
    cout << "Please input chars in lowercase: ";
    cin >> up;

    char c = up[0];
    int len = 0;
    while(c){
        len++;
        c = up[len];
    }

    cout << "uppercase: ";

    string low[len];
    for(int i=0; i < len;i++){
        if (((up[i] + ('A'-'a')) < 'Z') && ((up[i] + ('A'-'a')) > 'A')){
            cout << char(up[i] + ('A'-'a'));
        }
    }

    cout << endl;

    return 0;
}