using namespace std;

#include <iostream> 
#include <time.h>     

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool isPresent(Node* list_pointer, Node* sub_pointer)
{
    Node* curr1 = list_pointer, *curr2 = sub_pointer;


    if (list_pointer == NULL && sub_pointer == NULL)
        return true;

    if ( sub_pointer == NULL || (sub_pointer != NULL && list_pointer == NULL))
        return false;

    while (list_pointer != NULL)
    {
        curr1 = list_pointer;

        while (curr2 != NULL)
        {
            if (curr1 == NULL)
                return false;


            else if (curr2->data == curr1->data)
            {
                curr2 = curr2->next;
                curr1 = curr1->next;
            }

            else
                break;
        }
        if (curr2 == NULL)
            return true;

        curr2 = sub_pointer;

        list_pointer = list_pointer->next;
    }

    return false;
}

void display_all_nodes(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next; 
    } 
}

void createList(Node *head, int MAX, int maxNumNodes_list1){
    int nodeValue= rand() % MAX;  
    int countNodes=0;
    
    Node *list = head;
    Node *tmp=NULL;
    do{
        countNodes++;
        nodeValue= rand() % MAX;  
        tmp = new Node(nodeValue);
        list->next = tmp;
        list=tmp;
    }while(countNodes<maxNumNodes_list1);
}

int main()
{
    srand (time(NULL));
    int MAX=10;
    int maxNumNodes_list1 = rand() % 10;  
    int maxNumNodes_list2 = rand() % 3;  

    // create the first list - random

    int nodeValue= rand() % MAX;
    Node *head_L1 = new Node(nodeValue);
    createList(head_L1, MAX, maxNumNodes_list1);
    display_all_nodes(head_L1);
    cout << "\n"; 

    // create the second list - random

    nodeValue= rand() % MAX;
    Node *head_L2 = new Node(nodeValue);
    createList(head_L2, MAX, maxNumNodes_list2);
    display_all_nodes(head_L2);
    cout << "\n";

    // check the second list

    if (isPresent(head_L1, head_L2))
        cout << "True"<< "\n";
    else
        cout << "False"<< "\n";

    return 0;
}