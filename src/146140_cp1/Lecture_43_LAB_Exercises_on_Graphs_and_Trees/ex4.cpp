using namespace std;
#include "BST.h"

bool check_BST_r(BST*&);

int main(){
    int choice;
    string eg;
    while(true){
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " 0 - quit" << endl;
        cout << " 1 - example #1" << endl;
        cout << " 2 - example #2" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> choice;

        switch(choice){
            case 0: return 0;
            case 1: eg = "ex4-eg1.txt"; break;
            case 2: eg = "ex4-eg2.txt"; break;

            default: cout << "Invalid input!" << endl; return 0;
        }

        BST* tree = NULL;

        upload_BT(tree,eg);

        cout << endl;
        visualize_tree(tree);

        cout << endl << (check_BST_r(tree)? "Yes": "No") << endl << endl;

        delete tree;
    }
    return 0;
}

bool check_BST_r(BST* &tree){
    if(tree){
        BST *tL=tree->left, *tR=tree->right;
        if((tL && (tL->value > tree->value))
        || (tR && (tR->value < tree->value))){
            return false;
        }
        else{
            return (check_BST_r(tL) && check_BST_r(tR));
        }
    }
    else{return true;}
}