using namespace std;
#include "list.h"
#include <string>
#include <fstream>

void line();

int str_to_int(string);

int main(){
    string fName = "ex7-input.txt";

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return 0;}

    line();
    cout << "Read from file: " << endl;

    List *L = new List();
    string fWord;
    while(!fIn.eof()){
        fIn >> fWord;
        cout << " - " << fWord << endl;
        L->List_insert_last(str_to_int(fWord));
    }

    L->List_order_r();

    cout << endl << "Traverse: " << endl;

    int *T = L->List_traverse();
    for(int i=0; i<T[0]; i++){cout << " - " << T[i+1] << endl;}

    cout << endl << "Successfully ordered!" << endl;
    line();

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

int str_to_int(string fWord){
    int len=0;
    while(fWord[len]!='\0'){len++;}
    
    char fNum[len+1];
    for(int i=0; i<len; i++){fNum[i] = fWord[i];}
    fNum[len] = '\0';

    return stoi(fNum);
}