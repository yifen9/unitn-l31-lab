using namespace std;
#include "stack.hpp"

Stack::Stack(){}

void Stack::Stack_push(int num){
    node *p = new node();
    p->value = num;
    p->next = S;
    S = p;
}

int Stack::Stack_pop(){
    if(S==NULL){
        return 0;
    }
    else{
        int p = S->value;
        S = S->next;
        return p;
    }
}

int Stack::Stack_length(){
    node *p = S;
    int N = 0;

    while(p!=NULL){p=p->next;N++;}

    return N;
}