using namespace std;
#include <iostream>

int main(){
    bool P,Q;

    cout << "Please input the bool value of P and Q: " << endl;
    cin >> P >> Q;

    cout << "P->Q: " << (!P || Q) << endl;
}