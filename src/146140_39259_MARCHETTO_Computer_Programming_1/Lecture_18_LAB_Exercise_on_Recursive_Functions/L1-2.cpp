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

    cout << "Sum of a vector: " << recursive(&V[0],N) << endl;

    return 0;
}

int recursive(int *V, int N){
    if(N == 1){
        return *V;
    }
    else{
        return (*V + recursive(V+1,N-1));
    }
}