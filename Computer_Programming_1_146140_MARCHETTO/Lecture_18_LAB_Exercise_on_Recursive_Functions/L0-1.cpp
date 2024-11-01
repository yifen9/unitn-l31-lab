using namespace std;
#include <iostream>

int recursive(int);

int main(){
    int F;
    cout << "Please input an interger (>= 1): ";
    cin >> F;

    cout << "Factorial: " << recursive(F) << endl;

    return 0;
}

int recursive(int F){
    if(F == 1){
        return 1;
    }
    else{
        return (recursive(F-1)*F);
    }
}