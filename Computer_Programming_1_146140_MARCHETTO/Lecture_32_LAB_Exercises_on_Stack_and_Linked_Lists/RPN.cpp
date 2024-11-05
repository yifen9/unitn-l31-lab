using namespace std;
#include "RPN.h"

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

void stack_add(node* &stack){push(stack,pop(stack)+pop(stack));}
void stack_sub(node* &stack){push(stack,pop(stack)-pop(stack));}
void stack_mul(node* &stack){push(stack,pop(stack)*pop(stack));}
void stack_div(node* &stack){push(stack,pop(stack)/pop(stack));}