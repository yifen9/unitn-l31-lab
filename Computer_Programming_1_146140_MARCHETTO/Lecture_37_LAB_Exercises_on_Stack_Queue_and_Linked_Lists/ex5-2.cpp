using namespace std;
#include "list.h"
#include <string>
#include <fstream>

void line();

int str_to_int(string);

int main(){
    string fName;
    int choice;

    line();
    cout << "Please choose:" << endl;
    cout << " 0 - quit" << endl;
    cout << " 1 - example #1" << endl;
    cout << " 2 - example #2" << endl;
    cout << endl;
    cout << "Please input your choice: ";
    cin >> choice;
    line();

    switch(choice){
        case 0: return 0;
        case 1: fName = "ex5-eg1.txt"; break;
        case 2: fName = "ex5-eg2.txt"; break;

        default: cout << "Invalid input!" << endl; return 0;
    }

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return 0;}

    cout << "Insert from file (recursive): " << endl;

    List *L = new List();
    string fWord;
    while(!fIn.eof()){
        fIn >> fWord;
        cout << " - " << fWord << endl;
        L->List_insert_last_r(str_to_int(fWord));
    }

    cout << endl << "Traverse (recursive): " << endl;

    int *T = L->List_traverse_r();
    for(int i=0; i<T[0]; i++){cout << " - " << T[i+1] << endl;}

    cout << endl << "Successfully traversed!" << endl;
    line();
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