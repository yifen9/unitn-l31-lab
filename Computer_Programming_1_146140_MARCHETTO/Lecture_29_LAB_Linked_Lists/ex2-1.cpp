using namespace std;
#include "ex2.h"

bool sublist(node*,node*);

int main(){
    node *A = new node();

    int choice;
    while(true){
        line();
        cout << "Please choose:" << endl;
        cout << endl;
        cout << " 0 - quit" << endl;
        cout << " 1 - example #1" << endl;
        cout << " 2 - example #2" << endl;
        cout << " 3 - example #3" << endl;
        cout << endl;
        cout << "Please input your choice: ";
        cin >> choice;
        line();

        if(choice==0){return 0;}
        else{}
    }

    return 0;
}

bool sublist(node *lA, node *lB){return true;}