using namespace std;
#include <iostream>

int* rM(int*,int,int);

int rA(int*,int);

int main(){
    int M,N;
    cout << "Please input two integers: " << endl;
    cin >> M >> N;

    cout << "Please input " << (M*N) << " integers: " << endl;
    int V[M][N] = {0};
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){cin >> V[i][j];}}

    cout << "Matrix: " << endl;
    rM(&V[M-1][N-1],M,N);

    return 0;
}

int* rM(int *V, int M, int N){
    if (M == 0) {return (V+N);}
    else {
        rA(rM(V-N, M-1, N),N);
        cout << endl;
        return (V+N);
    }
}

int rA(int *V, int N){
    if (N == 0) {return *(V+1);}
    else {
        cout << rA(V-1, N-1) << " ";
        return *(V+1);
    }
}