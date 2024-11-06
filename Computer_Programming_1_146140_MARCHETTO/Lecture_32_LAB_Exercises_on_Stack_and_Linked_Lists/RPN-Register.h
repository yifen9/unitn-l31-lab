#ifndef RPN_REGISTER_H
#define RPN_REGISTER_H
#include "RPN.h"
#include <cstring>

void line();
node tail(node*);

void stack_print(node*);

void reg_store(node*&,node*&);
void reg_recall(node*&,node*&);

#endif