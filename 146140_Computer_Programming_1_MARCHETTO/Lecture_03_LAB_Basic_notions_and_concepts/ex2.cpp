using namespace std;
#include <iostream>

int main(){
    float F;
    cout << "Please input the temperature in Fahrenheit: ";
    cin >> F;

    cout << "temperature in Celsius degrees: " << (F-32)/1.8 << endl;

    return 0;
}