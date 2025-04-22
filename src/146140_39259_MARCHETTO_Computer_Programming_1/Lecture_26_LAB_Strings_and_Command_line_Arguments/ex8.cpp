using namespace std;
#include <iostream>

int* rM(int*,int*,int*,int,int,int);

int* rA(int*,int*,int*,int,int,int);

int rSUM(int*,int*,int,int);

int main(){
    int M,N,Q;
    cout << "Please input three integers: " << endl;
    cin >> M >> N >> Q;

    cout << "Please input " << (M*N) << " integers: " << endl;
    int V[M][N] = {0};
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){cin >> V[i][j];}}

    cout << "Please input " << (Q*N) << " integers: " << endl;
    int W[N][Q] = {0};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < Q; j++){cin >> W[i][j];}}

    cout << "Matricial product: " << endl;
    int Y[M][Q] = {0};
    rM(&V[0][0],&W[0][0],&Y[M-1][Q-1],M,N,Q);

    for (int i = 0; i < M; i++){
        for (int j = 0; j < Q; j++){cout << Y[i][j] << " ";}
        cout << endl;
    }

    return 0;
}

int* rM(int *V, int *W, int *Y, int M, int N, int Q){
    if (M == 0) {return (Y+Q);}
    else {
        rA(V,W,rM(V, W, Y-Q, M-1, N, Q),M,N,Q);
        return (Y+Q);
    }
}

int* rA(int *V, int *W, int *Y, int M, int N, int Q){
    if (Q == 0) {return (Y+1);}
    else {
        *rA(V, W, Y-1, M, N, Q-1) = rSUM(V+(M-1)*N, W+(Q-1), N, N);
        return (Y+1);
    }
}

int rSUM(int *V, int *W, int N, int i){
    if (i == 1) {return ((*V)*(*W));}
    else {return (((*V)*(*W)) + rSUM(V+1,W+N,N,i-1));}
}