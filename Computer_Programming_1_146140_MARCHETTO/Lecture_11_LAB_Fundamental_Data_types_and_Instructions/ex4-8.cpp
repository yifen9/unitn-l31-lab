using namespace std;
#include <iostream>
#include <cmath>

int find(int a){
    for(int j=2;j<a;j++){
        for(int k=2;k<a;k++){
            if(a==j*k){return 0;}
        }
    }
    return 1;
}

int main(){
    int i;
    cout << "Please input a number: ";
    cin >> i;

    bool judge = true;
    for(int j=2;j<=i;j++){
        if(find(j)){
            for(int k=2;k<=i;k++){
                if(find(k)){
                    if(i==j+k){cout << "Input: " << i << " => Output: " << j << " + " << k << endl;judge=false;}
                }
            }
        }
    }

    if(judge){cout << "None sorry" << endl;}

    return 0;
}