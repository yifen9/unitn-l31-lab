using namespace std;
#include <iostream>

int main(){
    int N;
    cout << "Please input an integer: ";
    cin >> N;

    cout << "Please input " << N << " integers: " << endl;
    int A[N+1] = {0};
    for(int i=0; i<N; i++){cin >> A[i];}

    int M,Q;
    cout << "Please input two integers (index and value): " << endl;
    cin >> M >> Q;

    for(int i=N; i>(N-M); i--){A[i] = A[i-1];}
    A[M] = Q;

    cout << "After insertion: " << endl;
    for(int i=0; i<(N+1); i++){cout << A[i] << endl;}
    
    return 0;
}