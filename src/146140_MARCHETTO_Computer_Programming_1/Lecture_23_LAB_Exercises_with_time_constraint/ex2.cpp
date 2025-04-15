using namespace std;
#include <iostream>

void rM(int*,int,int);

float rAVERAGE(int*,int);

int rMIN(int*,int);

int rMAX(int*,int);

int main(){
    int M=4,N=5;

    cout << "Please input " << (M*N) << " integers: " << endl;
    int V[M][N] = {0};
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){cin >> V[i][j];}}

    cout << endl << "Student: " << endl;
    rM(&V[0][0],M,N);

    int W[N][M] = {0};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){W[i][j]=V[j][i];}}
    
    cout << endl << "Class: " << endl;
    rM(&W[0][0],N,M);

    return 0;
}

void rM(int *V, int M, int N){
    for(int i=0; i<M; i++){
        cout << " " << i << "): " << endl;
        cout << "  Average: " << rAVERAGE(V+i*N,N) << endl;
        cout << "  Min:     " << rMIN(V+i*N,N) << endl;
        cout << "  Max:     " << rMAX(V+i*N,N) << endl;
    }  
}

float rAVERAGE(int *V, int l){
    float res=0;
    for(int i=0; i<l; i++){res += *(V+i);}
    return (res/l);
}

int rMIN(int *V,int l){
    float res=*V;
    for(int i=1; i<l; i++){res = (res<*(V+i))?res:*(V+i);}
    return (res);
}

int rMAX(int *V,int l){
    float res=*V;
    for(int i=1; i<l; i++){res = (res>*(V+i))?res:*(V+i);}
    return (res);
}