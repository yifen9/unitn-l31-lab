using namespace std;
#include "BST.h"

int str_to_int(const string s){
    int len=0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return stoi(res);
}

/*
int get_depth_r(BST* &tree, int d){
    if(tree){
        d++;
        bool tL=tree->left, tR=tree->right;
        if(tL || tR){
            int tLd = get_depth_r(tree->left,d);
            int tRd = get_depth_r(tree->right,d);

            return (tLd > tRd)? tLd: tRd;
        }
    }
    return d;
}
*/

void visualize_tree_r(BST* &tree, const int c){
    if(tree){
        visualize_tree_r(tree->right,1+c);
        for(int i=0; i<c; i++){cout << "      ";}
        cout << tree->value << endl;
        visualize_tree_r(tree->left,1+c);
    }
}

void visualize_tree(BST* &tree){visualize_tree_r(tree,0);}

void add_node(BST* &p, const int &v){
    p = new BST();
    p->value = v;
    p->left = NULL;
    p->right = NULL;
}

void add_BST_r(BST* &tree, const int &v){
    if(tree){
        if(v < tree->value){
            add_BST_r(tree->left,v);
        }
        else{
            add_BST_r(tree->right,v);
        }
    }
    else{add_node(tree,v);}
}

void upload_BST(BST* &tree, const string &fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    while(!fIn.eof()){
        fIn >> wIn;
        add_BST_r(tree,str_to_int(wIn));
    }
}

void print_tree_r(BST* &tree){
    if(tree){
        print_tree_r(tree->left);
        cout << ',' << tree->value;
        print_tree_r(tree->right);
    }
}

void search_tree_r(BST* &tree, const int n){
    if(tree){
        if(tree->value != n){
            cout << ',' << tree->value << ',';
            if(tree->value < n){
                cout << "right";
                search_tree_r(tree->right,n);
            }
            else{
                cout << "left";
                search_tree_r(tree->left,n);
            }
        }
    }
}

void deallocate_tree_r(BST* &tree){
    if(tree){
        deallocate_tree_r(tree->left);
        deallocate_tree_r(tree->right);
        delete tree;
    }
}

void deallocate_tree(BST* &tree){tree = NULL;}

void add_BT_r(BST* &tree, const int &v){

}

void upload_BT(BST* &tree, const string &fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    while(!fIn.eof()){
        fIn >> wIn;
        add_BT_r(tree,str_to_int(wIn));
    }
}