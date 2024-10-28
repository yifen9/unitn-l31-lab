using namespace std;
#include <iostream>

int recursive(int);

int main(){
    int N;
    cout << "Please input an interger (>= 0): ";
    cin >> N;

    cout << "Sum: " << recursive(N) << endl;

    return 0;
}

int recursive(int N){
    if (N == 0) {return 0;}
    else {return (recursive(N-1)+N);}
}