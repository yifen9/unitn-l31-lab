using namespace std;
#include "stack.h"

void push(node* &stack, int num){
    node *p = new node();
    p->value = num;
    p->next = stack;
    stack = p;
}

int pop(node* &stack){
    int p = stack->value;
    stack = stack->next;
    return p;
}