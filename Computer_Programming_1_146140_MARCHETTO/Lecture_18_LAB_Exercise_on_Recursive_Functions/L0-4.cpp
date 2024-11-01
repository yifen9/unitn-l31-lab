using namespace std;
#include <iostream>

int recursive(int,int,int);

int main(){
    int a,b;
    cout << "Please input two integers: " << endl;
    cin >> a >> b;

    cout << "Division: " << recursive(a,b,0) << endl;

    return 0;
}

int recursive(int a, int b, int d){
    if (a-b<0) {return d;}
    else {return (recursive(a-b,b,d+1));}
}