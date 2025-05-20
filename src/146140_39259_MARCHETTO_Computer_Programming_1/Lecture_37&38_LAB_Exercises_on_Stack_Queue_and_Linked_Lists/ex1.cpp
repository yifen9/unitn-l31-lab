using namespace std;
#include "stack.h"
#include <string>
#include <fstream>

void line();

int str_to_int(string);

int main(){
    string fName = "ex1-input.txt";

    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return 0;}

    line();
    cout << "Read from file: " << endl;

    Stack *S = new Stack();
    string fWord;
    while(!fIn.eof()){
        fIn >> fWord;
        cout << " - " << fWord << endl;
        S->Stack_push(str_to_int(fWord));
    }

    cout << endl << "Revert raws: " << endl;
    
    int len = S->Stack_length();
    for(int i=0; i<len; i++){cout << " - " << S->Stack_pop() << endl;}
    
    cout << endl << "Done!" << endl;
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