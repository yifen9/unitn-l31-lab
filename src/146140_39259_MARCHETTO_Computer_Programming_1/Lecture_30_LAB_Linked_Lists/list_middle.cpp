#include <iostream> 

using namespace std; 

struct Node {
    int num; 
    Node *next; 
}; 

int sz = 0; 

void insert(Node** head, int num) {
    Node* new_Node = new Node();
    new_Node->num = num; 
    new_Node->next = *head; 
    *head = new_Node;
    sz++; 
}

int get_Middle(Node *head) {
    if (!head) return -1;
    int c = 0; 
    Node *middle = head; 
    while (head) {
        if (c % 2 != 0) middle = middle->next; 
        c++; 
        head = head->next; 
    }
    return middle->num; 
}

void display_all_nodes(Node* node) { 
    while (node != NULL) {
        cout << node->num << " "; 
        node = node->next; 
    } 
}

int main() {
    Node* head = NULL; 

    insert(&head, 1); 
    insert(&head, 3); 
    insert(&head, 5); 
    insert(&head, 7); 

    cout << "Original list:\n"; 
    display_all_nodes(head); 

    cout << "\nMiddle element of the said list:";
    cout << "\n" << get_Middle(head) << "\n"; 

    cout << "\nOriginal list:\n";
    insert(&head, 9); 
    display_all_nodes(head); 

    cout << "\nMiddle element of the said list:";
    cout << "\n" << get_Middle(head);

    cout << endl;
    return 0;
}
