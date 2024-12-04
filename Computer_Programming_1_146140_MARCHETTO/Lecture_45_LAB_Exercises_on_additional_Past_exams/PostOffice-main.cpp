using namespace std;
#include "queue_c_list.h"

int main(){
    char choice;
    Queue* Q = new Queue();
    while(true){
        cout << "Please choose:" << endl;
        cout << "- q: quit" << endl;
        cout << "- a: add person" << endl;
        cout << "- d: dispose of person" << endl;
        cout << "- p: print current situation" << endl;
        cout << "Please input your choice: ";
        cin >> choice;

        switch(choice){
            case 'q': return 0;
            case 'a':{
                char* input;
                cout << endl << "- name: ";
                cin >> input;
                Q->queue_push(input);
                cout << endl;

                break;
            }
            case 'd':
                cout << endl << "- " << Q->queue_pop() << endl << endl;
                
                break;
            case 'p':
                cout << endl;
                Q->queue_print();
                cout << endl;

                break;
            default: cout << "Invalid input!" << endl;
        }
    }
    return 0;
}