using namespace std;
#include "stack.h"
#include <cstring>

struct reg{
    int index;
    int value;

    reg *next = NULL;
};

void line();

node tail(node*);

void stack_print(node*);

void stack_push_new(node*&);

void reg_store(reg*&,node*&);

void reg_recall(reg*&,node*&);

void reg_print(reg*);

int main(){
    node *stack = new node();
    reg *R = new reg();

    string input;
    char choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " n - push new" << endl;
        cout << " p - print the stack" << endl;
        cout << " s - store to register" << endl;
        cout << " r - recall from register" << endl;
        cout << " i - print the register" << endl;
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
                case 'n': stack_push_new(stack); break;
                case 'p': stack_print(stack); break;
                case 's': reg_store(R,stack); break;
                case 'r': reg_recall(R,stack); break;
                case 'i': reg_print(R); break;

                case 'q': return 0;

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
}

void stack_push_new(node* &stack){
    int input;
    cout << "Please input: ";
    cin >> input;
    push(stack,input);
}

void reg_store(reg* &R, node* &stack){
    reg *p = R;
    if(p->next==NULL){
        p->index = pop(stack);
        p->value = pop(stack);
    }
    else{
        while(p->next!=NULL){p=p->next;}

        p->next = new reg();
        p = p->next;

        p->index = pop(stack);
        p->value = pop(stack);
    }
    cout << "Index: " << p->index << endl;
    cout << "Value: " << p->value << endl;
}

void reg_recall(reg* &R, node* &stack){
    int index = pop(stack);

    reg *p = R;
    while(p->index!=index){p=p->next;}

    cout << "Index: " << p->index << endl;
    cout << "Value: " << p->value << endl;
}

void reg_print(reg *R){
    int N = 0; reg *p = R;
    while(p!=NULL){p=p->next;N++;}
    cout << N << " Nodes in Total" << endl;

    p = R;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - index: " << i << endl;
        cout << "   - index: " << p->index << endl;
        cout << "   - value: " << p->value << endl;
        p = p->next;
    }
}
