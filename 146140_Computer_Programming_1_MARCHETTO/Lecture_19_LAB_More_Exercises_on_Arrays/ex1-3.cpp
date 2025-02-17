using namespace std;
#include <iostream>
#include <string>

int main(){
    int N=0,len;
    string A,S;

    while(1){
        cout << "Please input a string (input exit to exit): ";
        cin >> S;

        if(S == "exit"){
            cout << "Result: " << A << endl;
            break;
        }
        else{A += S;}
    }

    return 0;
}