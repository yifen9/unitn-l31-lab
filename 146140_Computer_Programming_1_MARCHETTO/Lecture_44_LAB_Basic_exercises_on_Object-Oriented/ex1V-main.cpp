using namespace std;
#include "ex1V-stack.h"

int main(){
    Stack* S = new Stack();

    S->stack_push(1);
    S->stack_push(2);
    S->stack_push(3);

    S->stack_pop();

    while(!S->stack_isEmpty()){cout << S->stack_pop() << endl;}

    return 0;
}