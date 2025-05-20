using namespace std;
#include <iostream>
#include <string>

int i=0;
int A[100] = {0};

void push(int);

void pop();

int main(){
    string a;
    int n;
    while(true){
        cout << "Please input operations (push/pop/-1 to exit): " << endl;
        cin >> a;

        if(a=="-1"){break;}

        if(a=="push"){
            cout << "Please input ints (-1 to exit): " << endl;
            while(true){
                cin >> n;
                if(n==-1){break;}
                push(n);
            }
        }
        else if(a=="pop"){pop();}
    }

    return 0;
}

void push(int n){
    A[i] = n;
    i++;
}

void pop(){
    i--;
    cout << A[i] << endl;
}