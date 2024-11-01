using namespace std;
#include <iostream>

int main(){
    int N;
    cout << "Please input N: ";
    cin >> N;

    float result=0;
    for(int i=1; i<=N; i++){
        result += float(1.0/float(i));
    }

    cout << "Result: " << result << endl;

    return 0;
}