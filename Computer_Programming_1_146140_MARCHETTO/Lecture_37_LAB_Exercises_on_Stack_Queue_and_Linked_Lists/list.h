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
        void re_List_insert_last_r(node*,int);
        void re_List_traverse_r(int*,const node*,int);
    public:
        List();

        int List_length();

        void List_insert_last(int);
        void List_insert_last_r(int);

        int List_delete_first();

        int *List_traverse();
        int *List_traverse_r();
};

#endif