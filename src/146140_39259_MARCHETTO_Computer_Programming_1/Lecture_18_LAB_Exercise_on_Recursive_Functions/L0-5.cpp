using namespace std;
#include <iostream>

int recursive(int,int);

int main(){
    int x,y;
    cout << "Please input two integers (x,y >= 0): " << endl;
    cin >> x >> y;

    cout << "Sum: " << recursive(x,y) << endl;

    return 0;
}

int recursive(int x,int y){
    if(y == 0){
        return x;
    }
    else{
        return recursive(x+1,y-1);
    }
}