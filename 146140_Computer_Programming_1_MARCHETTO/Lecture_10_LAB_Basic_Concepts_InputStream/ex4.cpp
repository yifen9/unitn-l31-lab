using namespace std;
#include <iostream>

int main(){
    int h,m,s;
    cout << "Please input hour, minute and second: " << endl;
    cin >> h >> m >> s;

    cout << "Current time: " << h*3600 + m*60 + s << endl;

    return 0;
}