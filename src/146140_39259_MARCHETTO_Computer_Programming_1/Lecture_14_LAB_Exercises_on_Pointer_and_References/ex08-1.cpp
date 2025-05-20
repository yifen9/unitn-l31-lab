using namespace std;
#include <iostream>

void sort(int&,int&,int&);

int main(){
    int n1,n2,n3;
    cout << "Please input three positive integers:" << endl;
    cout << " n1: "; cin >> n1;
    cout << " n2: "; cin >> n2;
    cout << " n3: "; cin >> n3;

    sort(n1,n2,n3);

    cout << "Result:" << endl 
        << " n1: " << n1 << endl 
        << " n2: " << n2 << endl 
        << " n3: " << n3 << endl;

    return 0;
}

void sort(int& n1,int& n2, int& n3){
    if(n1>n2){
        if(n2>n3){swap(n1,n3);}
        else{
            if(n1>n3){
                swap(n1,n2);
                swap(n2,n3);
            }
            else{swap(n1,n2);}
        }
    }
    else{
        if(n2>n3){
            if(n1>n3){
                swap(n1,n3);
                swap(n2,n3);}
            else{swap(n2,n3);}
        }
        else{}
    }
}
