using namespace std;
#include <iostream>

int main(){
    int t;
    cout << "Please input current time: ";
    cin >> t;

    int s = t%60, m = t%3600/60, h = t/3600;

    cout << "Hour: " << h << endl;
    cout << "Minute: " << m << endl;
    cout << "Second: " << s << endl;

    return 0;
}