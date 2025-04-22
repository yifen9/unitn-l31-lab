using namespace std;
#include <iostream>

int main(){
    int a,b;
    cout << "Please input two variables: " << endl;
    cin >> a >> b;

    int t = a; a = b; b = t;

    cout << "Exchanges: " << a << " " << b << endl;

    return 0;
}