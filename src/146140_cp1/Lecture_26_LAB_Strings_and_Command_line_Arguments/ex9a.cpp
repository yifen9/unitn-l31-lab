using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
    int input;
    cout << "Please input a number:";
    cin >> input;

    int num=input, A[100] = {0};
    int re=num, i=0;
    while(re>10){
        num = re;
        re /= 10;
        A[i] = num%re;
        i++;
    }
    A[i] = re;
    i++;
    
    int product, res=0;
    for(int j=0; j<i; j++){
        product = 1;
        for(int k=0; k<i; k++){product *= A[j];}
        res += product;
    }
    
    if(res==input){cout << "Armostrong number" << endl;}
    else{cout << "not an Armostrong number" << endl;}

    return 0;
}