using namespace std;
#include <iostream>

int* f_initialize(const int);

void f_print(const int, const int*);

int* f_merge(const int, const int*, const int*);

void f_sort(const int, int*&);

int f_min(const int, int*);

int f_max(const int, int*);

float f_mean(const int, int*);

float f_median(const int, int*);

int main(){
    srand(time(NULL));

    const int L = 1+rand()%(0b1111);
    cout << "Length: " << L << endl;

    int *A = f_initialize(L);
    int *B = f_initialize(L);
    cout << "A:"; f_print(L,A); cout << endl;
    cout << "B:"; f_print(L,B); cout << endl;

    int *C = f_merge(L,A,B);
    f_sort(2*L,C);
    cout << "C:"; f_print(2*L,C); cout << endl;

    cout << "Min: " << f_min(2*L,C) << endl;
    cout << "Max: " << f_max(2*L,C) << endl;
    cout << "Mean: " << f_mean(2*L,C) << endl;
    cout << "Median: " << f_median(2*L,C) << endl;

    return 0;
}

int* f_initialize(const int L){
    int *A = new int[L];
    for(int i=0; i<L; i++){A[i] = rand()%(1+0b11111111);}

    return A;
}

void f_print(const int L, const int* A){
    for(int i=0; i<L; i++){cout << " " << A[i];}
}

int* f_merge(const int L, const int* A, const int* B){
    int *C = new int[L];
    for(int i=0; i<L; i++){C[i] = A[i];}
    for(int i=0; i<L; i++){C[L+i] = B[i];}

    return C;
}

void f_sort(const int L, int* &A){
    bool judge = true;
    int t;
    while(judge){
        judge = false;
        for(int i=1; i<L; i++){
            if(A[i-1] > A[i]){
                judge = true;
                t = A[i-1];
                A[i-1] = A[i];
                A[i] = t;
            }
        }
    }
}

int f_min(const int L, int* A){
    int res = A[0];
    for(int i=1; i<L; i++){res = (res<A[i])?res:A[i];}

    return res;
}

int f_max(const int L, int* A){
    int res = A[0];
    for(int i=1; i<L; i++){res = (res>A[i])?res:A[i];}

    return res;
}

float f_mean(const int L, int* A){
    int res = 0;
    for(int i=0; i<L; i++){res += A[i];}

    return float(res)/L;
}

float f_median(const int L, int* A){return float(A[L/2-1]+A[L/2])/2;}