using namespace std;
#include <iostream>

int main(){
    int r = rand()%10+1;
    int i;

    while(1){
        cout << "Please guess the number (1-10): ";
        cin >> i;

        if(i==r){cout << "Guessd" << endl;break;}
        else if (i<r){cout << "Small" << endl;}
        else {cout << "Big" << endl;}
    }

    return 0;
}