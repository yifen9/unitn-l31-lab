#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack{
    private:
        struct node{
            int value = 0;
            node *next = NULL;
        };
        node *S;
    public:
        Stack();
        void Stack_push(int);
        int Stack_pop();
        int Stack_length();
};

#endif