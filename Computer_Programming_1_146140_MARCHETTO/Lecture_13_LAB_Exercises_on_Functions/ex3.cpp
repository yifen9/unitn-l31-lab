using namespace std;
#include <iostream>

int len(int);

int revert(int,int);

int main(){
    int num;
    cout << "Please input a number: ";
    cin >> num;

    cout << "Revert: " << revert(len(num),num) << endl;

    return 0;
}

int len(int num){
    if(num == 0){return 1;}

    int i=1,len=0;
    while(true){
        if(num < i){return len;}
        else {
            i*=10;
            len++;}
    }
}

int revert(int len,int num){
    int d1=1,d2=1;
    for(int i=1; i<len; i++){d1*=10;}

    int res=0;
    for(int i=0; i<len; i++){
        res += ((num%(d1*10)/d1)*d2);
        d1 /= 10;
        d2 *= 10;
    }

    return res;
}