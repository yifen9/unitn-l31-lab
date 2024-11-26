using namespace std;
#include "BST.h"

bool check_BST_r(BST*&);

int main(){
    BST* tree = NULL;
    upload_BST(tree,"tree.txt");

    visualize_tree(tree);

    cout << endl << (check_BST_r(tree)? "Yes": "No") << endl;

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