using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class List{
    private:
        struct Node{
            int value;
            Node* next;
        }* L;
    public:
        List();
        void list_add(const int);
        int list_get_length();
        int* list_get();
        int list_get_count(const int);
        void list_print();
};

class WAMS{
    private:
        List *list_employee, *list_stamp_enter, *list_stamp_exit;
    public:
        WAMS(List*,List*,List*);
        List* WAMS_get_warninglist();
};

int str_to_int(const string);

List* read_from_file(string);

int main(){
    List *L1 = read_from_file("WorkLists-eg1.txt"),
         *L2 = read_from_file("WorkLists-eg2.txt"),
         *L3 = read_from_file("WorkLists-eg3.txt");
    WAMS* W = new WAMS(L1,L2,L3);

    cout << "List of employees:    "; L1->list_print(); cout << endl;
    cout << "List of enter stamps: "; L2->list_print(); cout << endl;
    cout << "List of exit stamps:  "; L3->list_print(); cout << endl;

    List* WL = W->WAMS_get_warninglist();
    
    cout << "Warning list:         "; WL->list_print(); cout << endl;

    return 0;
}

List::List(){L = NULL;}

void List::list_add(const int value){
    if(L){
        Node* p = L;
        while(p->next){p = p->next;}
        p->next = new Node();
        p->next->value = value;
        p->next->next = NULL;
    }
    else{
        L = new Node();
        L->value = value;
        L->next = NULL;
    }
}

int List::list_get_length(){
    int l = 0;
    for(Node* p=L; p; p=p->next){l++;}

    return l;
}

int* List::list_get(){
    const int l = list_get_length();
    int* A = new int[l];
    Node* p = L;
    for(int i=0; i<l; i++){
        A[i] = p->value;
        p = p->next;
    }
    return A;
}

int List::list_get_count(const int value){
    if(L){
        int c = 0;
        for(Node*p=L; p; p=p->next){c += (p->value == value);}

        return c;
    }
    else{return 0;}
}

void List::list_print(){
    if(L){
        for(Node*p=L; p; p=p->next){cout << p->value << ' ';}
    }
}

WAMS::WAMS(List* list_employee, List* list_stamp_enter, List* list_stamp_exit){
    this->list_employee = list_employee;
    this->list_stamp_enter = list_stamp_enter;
    this->list_stamp_exit = list_stamp_exit;
}

List* WAMS::WAMS_get_warninglist(){
    int l = list_employee->list_get_length(), *A = list_employee->list_get();
    List *W = new List();
    for(int i=0; i<l; i++){
        if(list_stamp_enter->list_get_count(A[i])
            - list_stamp_exit->list_get_count(A[i])){W->list_add(A[i]);}
    }
    return W;
}

int str_to_int(const string s){
    int len = 0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return stoi(res);
}

List* read_from_file(string fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    List* res = new List();
    while(!fIn.eof()){
        fIn >> wIn;
        res->list_add(str_to_int(wIn));
    }
    return res;
}