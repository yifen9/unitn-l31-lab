using namespace std;
#include <iostream>

int maxNum(int[]);

int main(){
    int arr[5]={0},temp,m;
    cout << "Please input 1-5 integers (input 0 to exit):" << endl;
    for(int i=0; i<5; i++){
        cout << " " << (i+1) << ": ";
        cin >> temp;

        if(temp == 0){break;}
        else{arr[i] = temp;}
    }

    cout << "Maxinum: " << maxNum(arr) << endl;

    return 0;
}

int maxNum(int arr[]){
    int m = arr[0];
    for(int i=1; i<5; i++){m = (arr[i]>m?arr[i]:m);}

    return m;
}
