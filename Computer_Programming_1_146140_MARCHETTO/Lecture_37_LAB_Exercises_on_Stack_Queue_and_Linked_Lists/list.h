#ifndef LIST_H
#define LIST_H
#include <iostream>

class List{
    private:
        struct node{
            int value = 0;
            node *next = NULL;
        };

        node *L;

        int p_List_length(node*);
        void p_List_insert_last(node*,int);
        void p_List_swap(node*,node*);

        void re_List_insert_last_r(node*,int);
        void re_List_traverse_r(int*,const node*,int);
        bool re_List_search_r(const node*,int);
        void re_List_order_r(node*&);
    public:
        List();

        int List_length();

        void List_insert_last(int);
        void List_insert_last_r(int);

        int *List_traverse();
        int *List_traverse_r();

        bool List_search(int);
        bool List_search_r(int);

        void List_order();
        void List_order_r();
};

#endif