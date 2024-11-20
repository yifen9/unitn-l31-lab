using namespace std;
#include <iostream>

struct node{
    int data;
    node* prev;
    node* next;
};

int** f1(){
    srand(time(NULL));

    const int X = 1+rand()%(0b1111);

    int** res = new int*[2];
    res[0] = new int;
    res[0][0] = X;
    res[1] = new int[X];

    for(int i=0; i<X; i++){res[1][i] = rand()%(1+0b11111111);}

    return res;
}

node* f2(const int X, const int* A){
    node* B = new node();
    node *p1=B, *p2=p1;
    for(int i=0; i<X; i++){
        p1->data = A[i];
        p2 = new node();
        p1->next = p2;
        p2->prev = p1;
        p1 = p1->next;
    }
    p1->next = NULL;
    delete p2;

    return B;
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

}

int main(){
    int** t = f1();

    const int X = t[0][0];
    cout << "X: " << X << endl;

    const int* A = t[1];
    cout << "Array:";
    for(int i=0; i<X; i++){cout << " " << A[i];}
    cout << endl;

    node* B = f2(X,A);
    f3(B);

    return 0;
}