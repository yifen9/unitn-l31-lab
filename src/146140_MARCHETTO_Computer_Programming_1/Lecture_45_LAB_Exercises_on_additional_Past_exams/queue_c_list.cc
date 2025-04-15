using namespace std;
#include "queue_c_list.h"

int Queue::p_get_length(char* C){
    int len = 0;
    while(C[len] != '\0'){len++;}

    return len;
}

Queue::Queue(){Q = NULL;}

Queue::~Queue(){
    Node* p;
    while(Q){
        p = Q;
        Q = Q->next;
        delete p;
    }
}

void Queue::queue_push(char* input){
    int len = p_get_length(input);
    char* t = new char[len];
    strcpy(t,input);

    if(Q){
        Node* p = Q;
        while(p->next){p = p->next;}
        p->next = new Node();
        p->next->name = t;
        p->next->next = NULL;
    }
    else{
        Q = new Node();
        Q->name = t;
        Q->next = NULL;
    }
}

char* Queue::queue_pop(){
    if(Q){
        Node* p = Q;
        
        Q = Q->next;

        char* t = p->name;
        delete p;

        return t;
    }
    else{return NULL;}
}

void Queue::queue_print(){
    if(Q){
        for(Node*p=Q; p; p=p->next){cout << "- " << p->name << endl;}
    }
}