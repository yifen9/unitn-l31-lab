using namespace std;
#include "RPN.h"
#include <cstring>

void line();

node tail(node*);

void stack_print(node*);

void reg_store(node*&,node*&);

void reg_recall(node*&,node*&);

int main(){
    node *stack = new node();
    node *reg = new node();

    string input;
    char choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " n - push new " << endl;
        cout << " s - the first two numbers in the stack are swapped" << endl;
        cout << " e - the two first two numbers in the stack are equal" << endl;
        cout << " q - the calculator quits" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> input;
        line();

        try{
            push(stack,stoi(input));
            cout << "Successfully pushed \"" << stoi(input) << "\" !" << endl;
        }
        catch(invalid_argument){
            choice = input[0];
            switch(choice){

                case 'p': stack_print(stack); break;

                case 'q': cout << "Result: " << pop(stack) << endl; line(); return 0;

                default: cout << "Invalid input!" << endl;
            }
        }
    }

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

node tail(node *A){
    node *p = A;
    int N = 0;
    
    while(p->next!=NULL){p=p->next;N++;}

    node res;
    res.value = N;
    res.next = p;

    return res;
}

void stack_print(node *stack){
    int N = tail(stack).value;
    cout << N << " Nodes in Total" << endl;

    node *p = stack;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - index: " << i << endl;
        cout << "   - value: " << p->value << endl;
        p = p->next;
    }

    cout << endl << "Successfully printed!" << endl;
}

void reg_store(node* &reg, node* &stack){

}

void reg_recall(node* &reg, node* &stack){

}