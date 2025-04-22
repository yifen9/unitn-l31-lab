using namespace std;
#include <iostream>

int main(){
    int bi;
    cout << "Please input a binary number: ";
    cin >> bi;

    int len = 0;
    int judge = 1;
    while(1){
        if(judge <= bi && bi < judge*10){break;}
        judge *= 10;
        len++;
    }

    int de = 0;
    int power = 1, re = 10;
    for(int i=0; i<=len; i++){
        de += (bi-(bi/re)*re)/(re/10)*power;
        power*=2; re*=10;
    }

    cout << "Decimal number: " << de << endl;

    return 0;
}