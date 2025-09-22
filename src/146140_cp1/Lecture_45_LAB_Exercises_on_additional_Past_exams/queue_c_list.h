#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstring>

class Queue{
    private:
        struct Node{
            char* name;
            Node* next;
        }* Q;

        int p_get_length(char*);
    public:
        Queue();
        ~Queue();
        void queue_push(char*);
        char* queue_pop();
        void queue_print();
};

#endif