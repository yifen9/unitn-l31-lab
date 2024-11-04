using namespace std;
#include "ex2.h"

bool sublist(node*,node*);

int main(){
    string egList,egSublist;

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

        switch(choice){
            case 0: return 0;
            case 1: egList = "ex2-1-eg1-list.txt"; egSublist = "ex2-1-eg1-sublist.txt"; break;
            case 2: egList = "ex2-1-eg2-list.txt"; egSublist = "ex2-1-eg2-sublist.txt"; break;
            case 3: egList = "ex2-1-eg3-list.txt"; egSublist = "ex2-1-eg3-sublist.txt"; break;

            default: cout << "Invalid input!" << endl; return 0;
        }

        node *nodeList = new node();
        node *nodeSublist = new node();
        cout << "List ";
        if(read_from_file(nodeList,egList)){
            line(); cout << "Sublist ";
            if(read_from_file(nodeSublist,egSublist)){
                if(sublist(nodeList,nodeSublist)){
                    line(); cout << "a sublist" << endl;
                }
                else{
                    line(); cout << "not a sublist" << endl;
                }
            }
        }
        delete nodeList;
        delete nodeSublist;
    }

    return 0;
}

bool sublist(node *nodeList, node *nodeSublist){
    node tailList = tail(nodeList);
    node tailSublist = tail(nodeSublist);

    return true;
}