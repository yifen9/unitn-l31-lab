#ifndef STACK_H
#define STACK_H
#include <iostream>

struct node{
    int value = 0;
    node *next = NULL;
};

void push(node*&,int);

int pop(node*&);

#endif