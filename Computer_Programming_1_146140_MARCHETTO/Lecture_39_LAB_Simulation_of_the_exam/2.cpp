using namespace std;
#include <iostream>

struct node{
    int data;
    node* prev;
    node* next;
};

int** f1(){
    const int X = 1+rand()%(0b1111);

    int** res = new int*[2];

    res[0] = new int;
    res[0][0] = X;

    res[1] = new int[X];
    for(int i=0; i<X; i++){res[1][i] = rand()%(1+0b11111111);}

    return res;
}

node* f2(const int X, const int* A){
    if(X > 0){
        node* B = new node();
        node *p1=B, *p2=p1;
        for(int i=0; i<X; i++){
            p1->data = A[i];
            p2 = new node();

            p1->next = p2;
            p2->prev = p1;
            
            p1 = p1->next;
        }
        p1->prev->next = NULL;
        delete p2;

        return B;
    }
    else{return NULL;}
}

void f3(node* A){
    cout << "Doubly Linked List:";
    node* p = A;
    while(p != NULL){
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

void f4(node* &A, const int P, const int num){
    int X;
    node* t = A;
    for(X=0; t!=NULL; t=t->next){X++;}

    if(X == 0){
        A = new node();
        A->data = num;
    }
    else{
        t = A;
        if(P == 0){
            t->prev = new node();
            t->prev->data = num;
            t->prev->next = t;

            A = t->prev;
        }
        else if(P == X){
            while(t->next != NULL){t = t->next;}

            t->next = new node();
            t->next->data = num;
            t->next->prev = t;
        }
        else{
            for(int i=0; i<P; i++){t = t->next;}
            node *p1=t->prev, *p2=t;

            t = new node();
            t->data = num;
            t->prev = p1;
            t->next = p2;

            p1->next = t;
            p2->prev = t;
        }
    }
}

int main(){
    srand(time(NULL));

    int** t = f1();

    const int X = t[0][0];
    cout << "X: " << X << endl;

    const int* A = t[1];
    cout << "Array:";
    for(int i=0; i<X; i++){cout << " " << A[i];}
    cout << endl;

    node* B = f2(X,A);
    f3(B);

    int P;
    cout << "P: ";
    cin >> P;
    f4(B,P,rand()%(1+0b11111111));
    f3(B);

    return 0;
}