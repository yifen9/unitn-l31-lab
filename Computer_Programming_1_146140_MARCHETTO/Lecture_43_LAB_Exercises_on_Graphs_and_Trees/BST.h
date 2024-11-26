#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstring>
#include <fstream>

struct BST{
    int value;
    BST *left, *right;
};

int str_to_int(const string);

void visualize_tree_r(BST*&, const int);

void visualize_tree(BST*&);

void add_node(BST*&, const int&);

void add_BST_r(BST*&, const int&);

void upload_BST(BST*&, const string&);

void print_tree_r(BST*&);

void search_tree_r(BST*&, const int);

void deallocate_tree_r(BST*&);

void deallocate_tree(BST*&);

bool add_BT_r(BST*&, const int&, const int&);

void upload_BT(BST*&, const string&);

#endif