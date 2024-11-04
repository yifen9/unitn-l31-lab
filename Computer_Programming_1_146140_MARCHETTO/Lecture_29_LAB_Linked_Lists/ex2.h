#ifndef EX2_H
#define EX2_H
#include <iostream>
#include <cstring>
#include <fstream>

struct node{
    int value = 0;
    node *next = NULL;
};

void line();
node tail(node*);
void print_all_nodes(node*);
bool read_from_file(node*,string);

#endif