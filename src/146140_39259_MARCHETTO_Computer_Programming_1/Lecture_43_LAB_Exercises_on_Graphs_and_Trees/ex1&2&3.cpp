using namespace std;
#include "BST.h"

int main(){
    char choice;
    BST* tree = NULL;
    while(true){
        cout << "Please choose:" << endl;
        cout << "- x: conclude the execution of the program" << endl;
        cout << "- s: search for another number" << endl;
        cout << "- p: print the tree" << endl;
        cout << "- l: load a new tree form a file" << endl;
        cout << "Please input your choice: ";
        cin >> choice;

        switch(choice){
            case 'x': return 0;
            case 's':{
                cout << endl;
                int n;
                cout << "the input number to search: ";
                cin >> n;
                cout << endl;
                search_tree_r(tree,n);
                cout << endl << endl;
                break;
            }
            case 'p':
                cout << endl;
                if(tree){
                    visualize_tree(tree);
                    cout << endl;
                    print_tree_r(tree);
                    cout << endl << endl;
                }
                break;
            case 'l':
                deallocate_tree(tree);
                upload_BST(tree,"tree.txt");
                cout << endl;
                break;
            default: cout << "Invalid input!" << endl;
        }
    }
    return 0;
}