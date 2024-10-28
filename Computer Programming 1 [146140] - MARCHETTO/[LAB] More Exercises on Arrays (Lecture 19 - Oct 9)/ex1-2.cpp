using namespace std;
#include <iostream>

int main(){
    int M,N;
    cout << "Please input two integers: " << endl;
    cin >> M >> N;

    cout << "Please input " << M << " integers: " << endl;
    int A[M] = {0};
    for(int i=0; i<M; i++){cin >> A[i];}

    cout << "Please input " << N << " integers: " << endl;
    int B[N] = {0};
    for(int i=0; i<N; i++){cin >> B[i];}

    int C[M+N] = {0};
    for(int i=0; i<M; i++){C[i] = A[i];}
    for(int i=0; i<N; i++){C[i+M] = B[i];}

    cout << "Concatenation: " << endl;
    for(int i=0; i<(M+N); i++){cout << C[i] << endl;}

    return 0;
}