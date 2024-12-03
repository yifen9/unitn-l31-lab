using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

struct Node{
    int data;
    Node* next;
};

int str_to_int(const string);

void node_add(Node*&, const int);

Node* list_read_from_file(string);

int random(const int);

Node* list_generate(const int, const int);

void list_print(Node*);

Node* list_copy(Node*);

void list_interleave_r(Node*,Node*);

Node* list_interleave(Node*,Node*);

void list_main(Node*,Node*);

int main(){
    srand(time(NULL));

    const int l=random(0b111), MAXNUM=0b1111;

    int choice;
    cout << "Please choose:" << endl;
    cout << endl;
    cout << " 0 - quit" << endl;
    cout << " 1 - example #1" << endl;
    cout << " 2 - example #2" << endl;
    cout << " 3 - generate randomly" << endl;
    cout << endl;
    cout << "Please input your choice: ";
    cin >> choice;

    switch(choice){
        case 0: return 0;
        case 1:
            cout << endl;
            list_main(
                list_read_from_file("Interleave-eg1-1.txt"),
                list_read_from_file("Interleave-eg1-2.txt")
            );
            break;
        case 2:
            cout << endl;
            list_main(
                list_read_from_file("Interleave-eg2-1.txt"),
                list_read_from_file("Interleave-eg2-2.txt")
            );
            break;
        case 3:
            cout << endl;
            list_main(
                list_generate(l,MAXNUM),
                list_generate(l,MAXNUM)
            );
            break;
        default: cout << "Invalid input!" << endl; return 0;
    }
    return 0;
}

int str_to_int(const string s){
    int len = 0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return stoi(res);
}

void node_add(Node* &list, const int num){
    if(list){
        Node* p = list;
        while(p->next){p = p->next;}
        p->next = new Node();
        p->next->data = num;
        p->next->next = NULL;
    }
    else{
        list = new Node();
        list->data = num;
        list->next = NULL;
    }
}

Node* list_read_from_file(string fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    Node* res = NULL;
    while(!fIn.eof()){
        fIn >> wIn;
        node_add(res,str_to_int(wIn));
    }
    return res;
}

int random(const int MAX){
    return (rand() % (1 + MAX));
}

Node* list_generate(const int l, const int MAXNUM){
    Node* res = NULL;

    for(int i=0; i<l; i++){node_add(res,random(MAXNUM));}

    return res;
}

void list_print(Node* list){
    if(list){
        for(Node*p=list; p; p=p->next){cout << p->data << ' ';}
    }
}

Node* list_copy(Node* list){
    Node* res = NULL;
    if(list){
        for(Node*p=list; p; p=p->next){node_add(res,p->data);}
    }
    return res;
}

void list_interleave_r(Node* l1, Node* l2){
    if(l1->next){
        list_interleave_r(l2,l1->next);
    }
    l1->next = l2;
}

Node* list_interleave(Node* l1, Node* l2){
    if(l1 && l2){
        Node *l1c=list_copy(l1), *l2c=list_copy(l2);

        list_interleave_r(l1c,l2c);

        return l1c;
    }
    else{return NULL;}
}

void list_main(Node* l1, Node* l2){
    cout << "Original Lists:" << endl << "- List1: ";
    list_print(l1);
    cout << endl << "- List2: ";
    list_print(l2);
    cout << endl << "After interleaving:" << endl << "- Interleaved ListA: ";
    list_print(list_interleave(l1,l2));
    cout << endl << "- Interleaved ListB: ";
    if(l1){list_print(list_interleave(l2,l1->next));}
    cout << endl;
}