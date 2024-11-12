using namespace std;
#include "list.h"

List::List(){L = new node();}

int List::List_length(){
    node *p = L;
    int N = 0;

    while(p->next!=NULL){p=p->next;N++;}

    return N;
}

void List::List_insert_last(int num){
    node *p = L;

    while(p->next!=NULL){p=p->next;}

    p->value = num;
    p->next = new node();
}

void List::List_insert_last_r(int num){re_List_insert_last_r(L,num);}

void List::re_List_insert_last_r(node *p, int num){
    if(p->next==NULL){
        p->value = num;
        p->next = new node();
    }
    else{re_List_insert_last_r(p->next,num);}
}

int List::List_delete_first(){
    node *p = L;
    
    L = L->next;

    int t = p->value;
    delete p;

    return t;
}

int *List::List_traverse(){
    int len = List_length();
    int *res = new int[len+1];

    res[0] = len;
    node *p = L;
    for(int i=0; i<len; i++){
        res[i+1] = p->value;
        p = p->next;
    }

    return res;
}

int *List::List_traverse_r(){
    int len = List_length();
    int *res = new int[len+1];

    res[0] = len;
    re_List_traverse_r(res,L,0);

    return res;
}

void List::re_List_traverse_r(int *res, const node *p, int i){
    if(p->next!=NULL){re_List_traverse_r(res,p->next,i+1);}
    res[i+1] = p->value;
}

bool List::List_search(int key){
    bool judge = false;

    node *p = L;
    while(p->next!=NULL){
        if(p->value==key){judge = true; break;}
        else{p = p->next;}
    }

    return judge;
}

bool List::List_search_r(int key){return re_List_search_r(L,key);}

bool List::re_List_search_r(const node *p, int key){
    if(p->next==NULL){return false;}
    else{
        if(p->value==key){
            return true;
        }
        else{
            return re_List_search_r(p->next,key);
        }
    }
}