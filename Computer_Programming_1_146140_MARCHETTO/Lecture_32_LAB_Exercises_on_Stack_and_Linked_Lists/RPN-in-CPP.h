#ifndef RPN_in_CPP_H
#define RPN_in_CPP_H
#include "RPN.h"
#include <cstring>
#include <cmath>

void line();
node tail(node*);

void stack_add(node*&);
void stack_sub(node*&);
void stack_mul(node*&);
void stack_div(node*&);

void stack_pow(node*&);
void stack_sqrt(node*&);

void stack_print(node*);
void stack_swap(node*&);
void stack_equal(node*&);

#endif