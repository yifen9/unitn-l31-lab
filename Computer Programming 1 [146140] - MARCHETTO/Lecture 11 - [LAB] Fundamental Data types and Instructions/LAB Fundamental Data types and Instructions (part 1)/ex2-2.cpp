using namespace std;
#include <iostream>
#include <cmath>

int main(){
    float a,b,c;
    cout << "Please input a, b and c: " << endl;
    cin >> a >> b >> c;
    
    float delta = b*b - 4*a*c;
    cout << "delta = " << delta << endl;

    if (delta > 0){
        cout << "x1 = " << float((-b + sqrt(delta)) / (2*a)) << endl;
        cout << "x1 = " << float((-b - sqrt(delta)) / (2*a)) << endl;
    }
    else if (delta > 0){
        cout << "no solutions" << endl;
    }
    else{
        cout << "x = " << float((-b) / 2*a) << endl;
    }

    return 0;
}