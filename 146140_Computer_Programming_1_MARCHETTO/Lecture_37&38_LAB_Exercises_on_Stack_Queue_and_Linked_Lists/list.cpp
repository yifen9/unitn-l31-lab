using namespace std;
#include "list.h"

int List::p_List_length(node *p){
    int N = 0;

    while(p->next!=NULL){p=p->next;N++;}

    return N;
}

void List::p_List_insert_last(node *p, int num){
    while(p->next!=NULL){p=p->next;}

    p->value = num;
    p->next = new node();
}

void List::p_List_swap(node *p1, node *p2){
    node *t = new node();

    t->value = p2->value;
    p2->value = p1->value;
    p1->value = t->value;

    delete t;
}

List::List(){L = new node();}

int List::List_length(){return p_List_length(L);}

void List::List_insert_last(int num){p_List_insert_last(L,num);}

void List::List_insert_last_r(int num){re_List_insert_last_r(L,num);}

void List::re_List_insert_last_r(node *p, int num){
    if(p->next==NULL){
        p->value = num;
        p->next = new node();
    }
    else{re_List_insert_last_r(p->next,num);}
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

void List::List_order(){
    node *p1,*p2;

    bool judge = true;
    while(judge){
        judge = false;

        p1 = L;
        p2 = p1->next;
        while(p2->next!=NULL){
            if(p1->value > p2->value){
                judge = true;
                p_List_swap(p1,p2);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}

void List::List_order_r(){re_List_order_r(L);}

void List::re_List_order_r(node *&p){
    if(p_List_length(p)>1){
        node *p1 = new node();
        node *p2 = new node();

        node *v = p;
        p = p->next;
        while(p->next!=NULL){
            if(v->value > p->value){
                p_List_insert_last(p1,p->value);
            }
            else{
                p_List_insert_last(p2,p->value);
            }
            p = p->next;
        }

        re_List_order_r(p1);
        re_List_order_r(p2);

        p_List_insert_last(p1,v->value);

        node *t;

        while(v!=NULL){
            t = v;
            v = v->next;
            delete t;
        }

        t = p1;
        while(t->next->next!=NULL){t=t->next;}
        delete t->next;
        t->next = p2;

        p = p1;
    }
}