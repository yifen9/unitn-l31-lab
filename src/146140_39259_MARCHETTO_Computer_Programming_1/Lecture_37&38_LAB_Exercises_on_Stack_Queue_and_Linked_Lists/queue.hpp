#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue{
    private:
        struct node{
            int value = 0;
            node *next = NULL;
        };
        node *Q;
    public:
        Queue();
        void Queue_push(int);
        int Queue_pop();
        int Queue_length();
};

#endif