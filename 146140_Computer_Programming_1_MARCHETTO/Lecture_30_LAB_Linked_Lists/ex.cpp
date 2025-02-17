using namespace std;
#include "ex.h"

void line(){cout << "--------------------------------" << endl;}

int length(node *A){
    node *p = A;
    int N = 0;

    if(p!=NULL){while(p->next!=NULL){p=p->next;N++;}}

    return N;
}

node *tail(node *A){
    node *p = A;
    if(p!=NULL){while(p->next!=NULL){p=p->next;}}

    return p;
}

void print_all_nodes(node *A){
    int N = length(A);
    cout << N << " Nodes in Total" << endl;

    node *p = A;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - index: " << i << endl;
        cout << "   - value: " << p->value << endl;
        p = p->next;
    }

    cout << endl << "Successfully printed!" << endl;
}

bool read_from_file(node *&A,string fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << endl << "Missing file name!" << endl; return false;}
    else{
        cout << "Read from File: " << endl;

        int N = length(A);

        node *p = A;
        if(p!=NULL){while(p->next!=NULL){p=p->next;}}

        while(!fIn.eof()){
            if(p==NULL){p = new node();}
            else{
                p->next = new node();
                p = p->next;
            }

            fIn >> p->value;

            cout << " - index: " << N << endl;
            cout << "   - value: " << p->value << endl;

            N++;
        }

        fIn.close();

        return true;
    }
}