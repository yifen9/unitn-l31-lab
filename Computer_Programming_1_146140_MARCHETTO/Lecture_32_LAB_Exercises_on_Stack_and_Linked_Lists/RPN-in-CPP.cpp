using namespace std;
#include "RPN-in-CPP.h"

int main(){
    node *stack = new node();

    string input;
    char choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " a number" << endl;
        cout << " an operation (+,-,*,/,^,|(sqrt))" << endl;
        cout << endl;
        cout << " p - the stack is printed" << endl;
        cout << " s - the first two numbers in the stack are swapped" << endl;
        cout << " e - the two first two numbers in the stack are equal" << endl;
        cout << " q - the calculator quits" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> input;
        line();

        try{
            push(stack,stoi(input));
            cout << "Successfully pushed \"" << stoi(input) << "\" !" << endl;
        }
        catch(invalid_argument){
            choice = input[0];
            switch(choice){
                case '+': stack_add(stack); cout << "Successfully \"+\" !" << endl; break;
                case '-': stack_sub(stack); cout << "Successfully \"-\" !" << endl; break;
                case '*': stack_mul(stack); cout << "Successfully \"*\" !" << endl; break;
                case '/': stack_div(stack); cout << "Successfully \"/\" !" << endl; break;

                case '^': stack_pow(stack); cout << "Successfully \"^\" !" << endl; break;
                case '|': stack_sqrt(stack); cout << "Successfully \"square rooted\" !" << endl; break;

                case 'p': stack_print(stack); break;
                case 's': stack_swap(stack); cout << "Successfully swapped!" << endl; break;
                case 'e': stack_equal(stack); cout << "Successfully pushed the equal check!" << endl; break;

                case 'q': cout << "Result: " << pop(stack) << endl; line(); return 0;

                default: cout << "Invalid input!" << endl;
            }
        }
    }
}

void line(){cout << "--------------------------------" << endl;}

node tail(node *A){
    node *p = A;
    int N = 0;
    
    while(p->next!=NULL){p=p->next;N++;}

    node res;
    res.value = N;
    res.next = p;

    return res;
}

void stack_pow(node* &stack){push(stack,pow(pop(stack),pop(stack)));}

void stack_sqrt(node* &stack){push(stack,sqrt(pop(stack)));}

void stack_print(node *stack){
    int N = tail(stack).value;
    cout << N << " Nodes in Total" << endl;

    node *p = stack;
    for(int i=0; i<N; i++){
        cout << endl;
        cout << " - index: " << i << endl;
        cout << "   - value: " << p->value << endl;
        p = p->next;
    }

    cout << endl << "Successfully printed!" << endl;
}

void stack_swap(node* &stack){
    node *t1 = new node(); push(t1,pop(stack));
    node *t2 = new node(); push(t2,pop(stack));

    push(stack,pop(t1));
    push(stack,pop(t2));

    delete t1;
    delete t2;
}

void stack_equal(node* &stack){push(stack,pop(stack)==pop(stack));}