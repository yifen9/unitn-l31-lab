using namespace std;
#include "ex1V-stack.h"

Stack::Stack(){S = NULL;}

Stack::~Stack(){
    node* p;
    while(S){
        p = S;
        S = S->next;
        delete p;
    }
}

void Stack::stack_push(const int v){
    if(S){
        node* p = new node();
        p->value = v;
        p->next = S;
        S = p;
    }
    else{
        S = new node();
        S->value = v;
        S->next = NULL;
    }
}

int Stack::stack_pop(){
    if(S){
        node* p = S;
        int v = p->value;
        S = p->next;
        delete p;

        return v;
    }
    else{return 0;}
}

bool Stack::stack_isEmpty(){return (!bool(S));}