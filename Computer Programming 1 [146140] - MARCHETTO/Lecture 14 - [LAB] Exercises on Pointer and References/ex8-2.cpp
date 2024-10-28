using namespace std;
#include <iostream>

void sort(int,int*);

int main(){
    int N;
    cout << "Please input a max integer N: ";
    cin >> N;

    int arr[N]={0};
    cout << "Please input " << N << " integers: " << endl;
    for(int i=0; i<N; i++){
        cout << " " << (i+1) << ": ";
        cin >> arr[i];
    }

    sort(N,&arr[0]);

    cout << "Result: " << endl;
    for(int i=0; i<N; i++){cout << " " << (i+1) << ": " << arr[i] << endl;}

    return 0;
}

void sort(int len,int* arr){
    int size = 4;
    int *i1,*i2;
    bool judge = true;

    while(judge){
        judge = false;
        i1 = arr;
        i2 = arr+1;

        for(int i=1; i<len; i++){
            i1++;
            i2++;

            if(*i1 > *i2){
                 judge = true;
                 swap(*i1,*i2);
            }
        }
    }
}