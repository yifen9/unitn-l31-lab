#ifndef RPN_H
#define RPN_H
#include <iostream>

struct node{
    int value = 0;
    node *next = NULL;
};

void push(node*&,int);
int pop(node*&);

void stack_add(node*&);
void stack_sub(node*&);
void stack_mul(node*&);
void stack_div(node*&);

#endif