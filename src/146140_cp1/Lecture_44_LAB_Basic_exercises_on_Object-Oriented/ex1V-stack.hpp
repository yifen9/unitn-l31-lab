#ifndef EX1V_STACK_H
#define EX1V_STACK_H
#include <iostream>

class Stack{
    private:
        struct node{
            int value;
            node* next;
        }*S;
    public:
        Stack();
        ~Stack();
        void stack_push(const int);
        int stack_pop();
        bool stack_isEmpty();
};

#endif