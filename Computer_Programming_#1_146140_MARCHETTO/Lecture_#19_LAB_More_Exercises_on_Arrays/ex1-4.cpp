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

    if(M==N){
        int i=0;
        while(A[i]==B[i] && i<M){i++;}

        if(i==M){cout << "A = B" << endl;}
        else{
            if(A[i]>B[i]){cout << "A is larger" << endl;}
            else{cout << "B is larger" << endl;}
        }
    }
    else{
        if(M>N){cout << "A is larger" << endl;}
        else{cout << "B is larger" << endl;}
    }

    return 0;
}