using namespace std;
#include "stack.h"
#include "queue.h"
#include <string>

void line();

void palindrome(bool);

int main(){
    string input;
    line();
    cout << "Please input a sequence of characters: " << endl << endl << " - input: ";
    cin >> input;
    cout << endl;

    Stack *S = new Stack();
    Queue *Q = new Queue();

    int len = 0;
    while(input[len]!='\0'){
        S->Stack_push(input[len]);
        Q->Queue_push(input[len]);
        len++;
    }

    int tS,tQ;
    while(true){
        tS = S->Stack_pop();
        tQ = Q->Queue_pop();

        if(tS&&tQ){
            if(tS!=tQ){palindrome(false); return 0;}
        }
        else{palindrome(true); return 0;}
    }

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void palindrome(bool judge){
    if(judge){
        cout << "YES!" << endl;
    }
    else{
        cout << "NO!" << endl;
    }
    
    line();
}