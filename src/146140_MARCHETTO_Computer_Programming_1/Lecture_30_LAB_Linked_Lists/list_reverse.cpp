#include <iostream> 

using namespace std;
 
struct node{
    int num; 
    node *next; 
};

node *head=NULL; 

void insert_Node(int n){
    struct node *new_node=new node; 
    new_node->num=n; 
    new_node->next=head;
    head=new_node;
}

void reverse() {
    node* current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev; 
}

void display_all_nodes() {
    struct node *temp = head; 
    while(temp != NULL) { 
        cout << temp->num << " "; 
        temp = temp->next; 
    }
    cout << endl; 
}

int main(){
    insert_Node(1); 
    insert_Node(3); 
    insert_Node(5);
    insert_Node(7); 
    insert_Node(9); 
    insert_Node(11); 

    cout << "Original Linked list:\n";
    display_all_nodes();

    cout << "\nReverse Linked list:\n";
    reverse();
    display_all_nodes(); 

    return 0; 
}
