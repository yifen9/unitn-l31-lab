using namespace std;
#include <iostream>

int main(){
    int a,b;
    cout << "Please input a and b: " << endl;
    cin >> a >> b;

    for(int i=a; i<=b; i++){cout << char(i) << ": " << i << endl;}

    return 0;
}