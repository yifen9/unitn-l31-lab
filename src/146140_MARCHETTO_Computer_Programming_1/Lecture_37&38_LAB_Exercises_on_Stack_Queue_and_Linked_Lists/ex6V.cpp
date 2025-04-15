using namespace std;
#include "list.h"
#include <string>
#include <fstream>

void line();

int str_to_int(string);

void formulae(bool);

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
        case 1: fName = "ex6-eg1.txt"; break;
        case 2: fName = "ex6-eg2.txt"; break;

        default: cout << "Invalid input!" << endl; return 0;
    }

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return 0;}

    cout << "Insert from file: " << endl;

    List *L = new List();
    string fWord;
    while(!fIn.eof()){
        fIn >> fWord;
        cout << " - " << fWord << endl;
        L->List_insert_last(str_to_int(fWord));
    }

    int key;
    cout << endl << "Please input the key: " << endl << endl << " - input: ";
    cin >> key;
    cout << endl;

    formulae(L->List_search_r(key));

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

void formulae(bool judge){
    if(judge){
        cout << "Searched: YES! (recursive)" << endl;
    }
    else{
        cout << "Searched: NO! (recursive)" << endl;
    }
    
    line();
}
