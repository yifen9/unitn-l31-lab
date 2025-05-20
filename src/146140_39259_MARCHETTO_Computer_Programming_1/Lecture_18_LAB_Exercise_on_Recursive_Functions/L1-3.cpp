using namespace std;
#include <iostream>

int recursive(int*,int*,int);

int main(){
    int N;
    cout << "Please input an integer: ";
    cin >> N;

    cout << "V - Please input " << N << " integers: " << endl;
    int V[N] = {0};
    for (int i = 0; i < N; i++){cin >> V[i];}

    cout << "W - Please input " << N << " integers: " << endl;
    int W[N] = {0};
    for (int i = 0; i < N; i++){cin >> W[i];}

    cout << "Product of a vector: " << recursive(&V[0],&W[0],N) << endl;

    return 0;
}

int recursive(int *V, int *W, int N){
    if(N == 1){
        return ((*V)*(*W));
    }
    else{
        return (((*V)*(*W)) + recursive(V+1,W+1,N-1));
    }
}