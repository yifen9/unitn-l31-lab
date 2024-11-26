using namespace std;
#include "BST.h"

bool check_BST_identical_r(BST*&,BST*&);

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

        upload_BST(t1,eg1);
        upload_BST(t2,eg2);

        cout << endl; visualize_tree(t1);
        cout << endl; visualize_tree(t2);

        cout << endl << (check_BST_identical_r(t1,t2)? "True": "False") << endl << endl;

        delete t1,t2;
    }
    return 0;
}

bool check_BST_identical_r(BST* &t1, BST* &t2){
    if((t1 && !t2) || (!t1 && t2)){return false;}
    else{
        if(t1 && t2){
            if(t1->value == t2->value){
                return (check_BST_identical_r(t1->left,t2->left)
                     && check_BST_identical_r(t1->right,t2->right));
            }
            else{return false;}
        }
        else{return true;}
    }
}