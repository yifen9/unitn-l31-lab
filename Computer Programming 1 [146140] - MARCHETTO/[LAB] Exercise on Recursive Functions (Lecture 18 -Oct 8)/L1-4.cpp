using namespace std;
#include <iostream>

bool recursive(int*,int);

int main(){
    int N;
    cout << "Please input an integer: ";
    cin >> N;

    cout << "Please input " << N << " integers: " << endl;
    int V[N] = {0};
    for (int i = 0; i < N; i++){cin >> V[i];}

    cout << "Is palindrome: " << recursive(&V[0],N) << endl;

    return 0;
}

bool recursive(int *V, int N){
    if (N/2 < 0) {return true;}
    else {
        if (*V == *(V+(N-1))){return recursive(V+1,N-2);}
        else {return false;}
    }
}