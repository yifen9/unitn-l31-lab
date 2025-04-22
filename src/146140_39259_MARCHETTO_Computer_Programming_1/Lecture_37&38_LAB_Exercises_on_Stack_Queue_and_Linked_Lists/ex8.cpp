using namespace std;
#include <iostream>

struct node{
    int value = 0;
    node *next = NULL;
};

void line();

node *Josephus_ini(int);

bool Josephus_kill(node*&);

int main(){
    int N;
    line();
    cout << "Please input an integer: " << endl << endl << " - input: ";
    cin >> N;
    cout << endl;

    node *L = Josephus_ini(N);
    
    node *p;
    do{
        p = L;

        cout << " - (" << p->value << ")";
        p = p->next;
        for(int i=0; i<(N-1); i++){
            cout << " -> " << p->value;
            p = p->next;
        }
        cout << endl;

        N--;
    }
    while(Josephus_kill(L));

    cout << endl << "person " << L->value << " wins!" << endl;
    line();

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

node *Josephus_ini(int N){
    node *L=new node(), *p=L;
    for(int i=0; i<(N-1); i++){
        p->value = i+1;
        p->next = new node();
        p = p->next;
    }
    p->value = N;
    p->next = L;

    return L;
}

bool Josephus_kill(node *&L){
    node *p1=L, *p2=p1->next, *p3=p2->next;

    if(p1==p2){return false;}
    else{
        delete p2;
        p1->next = p3;

        L = p3;

        return true;
    }
}