#ifndef EX_H
#define EX_H
#include <iostream>
#include <cstring>
#include <fstream>

struct node{
    int value = 0;
    node *next = NULL;
};

void line();
int length(node*);
node *tail(node*);
void print_all_nodes(node*);
bool read_from_file(node*&,string);

#endif