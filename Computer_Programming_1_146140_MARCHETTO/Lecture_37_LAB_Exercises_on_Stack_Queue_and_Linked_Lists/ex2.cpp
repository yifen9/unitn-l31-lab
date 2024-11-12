using namespace std;
#include "stack.h"
#include <string>

void line();

void formulae(bool);

int main(){
    string input;
    line();
    cout << " Please input a sequence of characters: " << endl << endl << "  - input: ";
    cin >> input;
    cout << endl;

    Stack *S = new Stack();

    int len = 0;
    while(input[len]!='\0'){
        if(input[len]=='('){S->Stack_push(1);}
        else if(input[len]==')'){
            if(S->Stack_pop()==0){formulae(false);return 0;}
        }
        
        len++;
    }

    formulae(S->Stack_pop()==0);

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void formulae(bool judge){
    if(judge){
        cout << " YES!" << endl;
    }
    else{
        cout << " NO!" << endl;
    }
    
    line();
}