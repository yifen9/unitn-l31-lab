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
        cout << "x2 = " << float((-b - sqrt(delta)) / (2*a)) << endl;
    }
    else if (delta < 0){
        cout << "x1 = " << -b/2a << " + " << (sqrt(delta) / (2*a)) << "i" << endl;
        cout << "x2 = " << -b/2a << " - " << (sqrt(delta) / (2*a)) << "i" << endl;
    }
    else{
        cout << "x = " << float((-b) / 2*a) << endl;
    }

    return 0;
}