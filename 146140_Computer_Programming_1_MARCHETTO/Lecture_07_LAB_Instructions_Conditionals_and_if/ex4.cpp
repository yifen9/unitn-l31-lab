using namespace std;
#include <iostream>

int main(){
    int n=0;
    char c;
    cout << "is " << n << "the number you are thinking of? (0-7)(y/n): ";
    cin >> c;

    while(c=='n'){
        n++;
        cout << "is " << n << "the number you are thinking of? (0-7)(y/n): ";
        cin >> c;
    }

    cout << "ez" << endl;

    return 0;
}