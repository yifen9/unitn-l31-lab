using namespace std;
#include <iostream>
#include <cmath>

int main(){
    float a,b;
    cout << "Please input a and b: " << endl;
    cin >> a >> b;

    cout << "1) max: " << max(a,b) 
        << " & min: " << min(a,b) << endl;

    if(a>=b){cout << "2) max: " << a 
        << " & min: " << b << endl;}
    else{cout << "2) max: " << b 
        << " & min: " << a << endl;}

    cout << "3) max: " << float((a>=b)?a:b) 
        << " & min: " << float((a>=b)?b:a) << endl;

    return 0;
}