using namespace std;
#include "BST.h"

class Stack{
    private:
        struct node{
            int value;
            node* next;
        }*S;
    public:
        Stack();
        void stack_push(const int);
        int* stack_pop();
};

void check_BST_identical_i(Stack*&,BST*&,BST*&);

bool check_BST_identical(BST*&,BST*&);

int main(){
    int choice;
    string eg1,eg2;
    while(true){
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " 0 - quit" << endl;
        cout << " 1 - example #1" << endl;
        cout << " 2 - example #2" << endl;
        cout << " 3 - example #3" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> choice;

        switch(choice){
            case 0: return 0;
            case 1: eg1 = "ex5-eg1-1.txt"; eg2 = "ex5-eg1-2.txt"; break;
            case 2: eg1 = "ex5-eg2-1.txt"; eg2 = "ex5-eg2-2.txt"; break;
            case 3: eg1 = "ex5-eg3-1.txt"; eg2 = "ex5-eg3-2.txt"; break;

            default: cout << "Invalid input!" << endl; return 0;
        }

        BST *t1=NULL, *t2=NULL;

        upload_BT(t1,eg1);
        upload_BT(t2,eg2);

        cout << endl; visualize_tree(t1);
        cout << endl; visualize_tree(t2);

        cout << endl << (check_BST_identical(t1,t2)? "True": "False") << endl << endl;

        delete t1,t2;
    }
    return 0;
}

Stack::Stack(){S = NULL;}

void Stack::stack_push(const int v){
    if(S){
        node* p = new node();
        p->value = v;
        p->next = S;
        S = p;
    }
    else{
        S = new node();
        S->value = v;
        S->next = NULL;
    }
}

int* Stack::stack_pop(){
    if(S){
        node* p = S;
        S = p->next;

        return &p->value;
    }
    else{return NULL;}
}

void check_BST_identical_i(Stack* &S, BST* &t1, BST* &t2){
    if(t1 && t2){
        S->stack_push(t1->value);
        S->stack_push(t2->value);
        check_BST_identical_i(S,t1->left,t2->left);
        check_BST_identical_i(S,t1->right,t2->right);
    }
    else if(t1 && !t2){
        S->stack_push(t1->value);
        check_BST_identical_i(S,t1->left,t2);
        check_BST_identical_i(S,t1->right,t2);
    }
    else if(!t1 && t2){
        S->stack_push(t2->value);
        check_BST_identical_i(S,t1,t2->left);
        check_BST_identical_i(S,t1,t2->right);
    }
}

bool check_BST_identical(BST* &t1, BST* &t2){
    Stack *S = new Stack();
    check_BST_identical_i(S,t1,t2);

    int *p1, *p2;
    while(true){
        p1 = S->stack_pop();
        p2 = S->stack_pop();

        if(p1 && p2){
            if(*p1 != *p2){return false;}
        }
        else if(p1 || p2){
            return false;
        }
        else{
            return true;
        }

        delete p1,p2;
    }
}