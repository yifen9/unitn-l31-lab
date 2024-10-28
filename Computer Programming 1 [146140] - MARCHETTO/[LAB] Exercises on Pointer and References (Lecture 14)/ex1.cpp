using namespace std;
#include <iostream>
#include <cmath>

float computeSum(int);

float computePi(float);

int main(){
    int N;
    cout << "Please input the precision:";
    cin >> N;

    cout << "Pi = " << computePi(computeSum(N)) << endl;

    return 0;
}

float computeSum(int N){
    float res = 0;
    for(int i=1; i<=N; i++){res += (1.0/float(i*i));}

    return res;
}

float computePi(float sum){return (sqrt(sum*6));}