using namespace std;
#include <iostream>
#include <string>
#include <fstream>

struct node{
    int value = 0;
    node *next = NULL;
};

void line();

int str_to_int(string);

void node_insert(node*,int);

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

    cout << "Read from file: " << endl;

    node *L;
    string fWord;
    while(!fIn.eof()){
        fIn >> fWord;
        cout << "  - " << fWord << endl;
        node_insert(L,str_to_int(fWord));
    }
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

void node_insert(node *L, int num){
    node *p = L;

    while(p->next!=NULL){p=p->next;}

    p->value = num;
    p->next = new node();
}