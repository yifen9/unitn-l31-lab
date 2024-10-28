using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
    int num;
    cout << "Please input a number:";
    cin >> num;

    int A[100] = {0};
    int re=num, i=0;
    while(re>1){
        num = re;
        re /= 10;
        A[i] = num/re;
        i++;
    }
    
    for(int j=0; j<i; j++){cout << A[j] << endl;}

    return 0;
}