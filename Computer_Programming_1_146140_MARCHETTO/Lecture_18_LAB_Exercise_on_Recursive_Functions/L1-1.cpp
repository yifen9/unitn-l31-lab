using namespace std;
#include <iostream>

int recursive(int*,int);

int main(){
    int N;
    cout << "Please input an integer: ";
    cin >> N;

    cout << "Please input " << N << " integers: " << endl;
    int V[N] = {0};
    for (int i = 0; i < N; i++){cin >> V[i];}

    cout << "Vector in reverse order: " << endl;

    recursive(&V[0],N);

    return 0;
}

int recursive(int *V, int N){
    if(N == 0){
        return *(V-1);
    }
    else{
        cout << recursive(V+1, N-1) << endl;
        return *(V-1);
    }
}