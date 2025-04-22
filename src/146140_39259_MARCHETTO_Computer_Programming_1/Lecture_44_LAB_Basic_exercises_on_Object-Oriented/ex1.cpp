using namespace std;
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

int main(){
    Stack* S = new Stack();

    S->stack_push(1);
    S->stack_push(2);
    S->stack_push(3);

    S->stack_pop();

    while(!S->stack_isEmpty()){cout << S->stack_pop() << endl;}

    return 0;
}

Stack::Stack(){S = NULL;}

Stack::~Stack(){
    node* p;
    while(S){
        p = S;
        S = S->next;
        delete p;
    }
}

void Stack::stack_push(const int v){
    if(S){
        node* p = new node();
        p->value = v;
        p->next = S;
        S = p;
    }
    else{
        S = new node();
        S->value = v;
        S->next = NULL;
    }
}

int Stack::stack_pop(){
    if(S){
        node* p = S;
        int v = p->value;
        S = p->next;
        delete p;

        return v;
    }
    else{return 0;}
}

bool Stack::stack_isEmpty(){return (!bool(S));}