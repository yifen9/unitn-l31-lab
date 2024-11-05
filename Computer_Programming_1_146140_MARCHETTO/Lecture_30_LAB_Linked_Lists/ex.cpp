using namespace std;
#include "ex.h"

void line(){cout << "--------------------------------" << endl;}

node tail(node *A){
    node *p = A;
    int N = 0;
    
    while(p->next!=NULL){p=p->next;N++;}

    node res;
    res.value = N;
    res.next = p;

    return res;
}

void print_all_nodes(node *A){
    int N = tail(A).value;
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

bool read_from_file(node *A,string fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << endl << "Missing file name!" << endl; return false;}
    else{
        cout << "Read from File: " << endl;

        node t = tail(A);

        int N = t.value;
        node *p = t.next;

        while(!fIn.eof()){
            p->next = new node();
            p = p->next;

            fIn >> p->value;

            cout << endl;
            cout << " - index: " << N << endl;
            cout << "   - value: " << p->value << endl;

            N++;
        }

        fIn.close();

        cout << endl << "Successfully read!" << endl; return true;
    }
}