using namespace std;
#include "queue.hpp"

Queue::Queue(){Q = new node();}

void Queue::Queue_push(int num){
    node *p = Q;

    while(p->next!=NULL){p=p->next;}

    p->value = num;
    p->next = new node();
}

int Queue::Queue_pop(){
    node *p = Q;
    
    Q = Q->next;

    int t = p->value;
    delete p;

    return t;
}

int Queue::Queue_length(){
    node *p = Q;
    int N = 0;

    while(p->next!=NULL){p=p->next;N++;}

    return N;
}