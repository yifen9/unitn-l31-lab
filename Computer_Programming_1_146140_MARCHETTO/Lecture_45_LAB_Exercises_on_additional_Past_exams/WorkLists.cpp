using namespace std;
#include <iostream>

class List{
    private:
        struct Node{
            int value;
            Node* next;
        }* L;
    public:
        List(){L = NULL;}
        ~List(){
            Node* p;
            while(L){
                p = L;
                L = L->next;
                delete p;
            }
        }
        void list_add(const int value){
            if(L){
                Node* p = L;
                while(p->next){p = p->next;}
                p->next = new Node();
                p->next->value = value;
                p->next->next = NULL;
            }
            else{
                L = new Node();
                L->value = value;
                L->next = NULL;
            }
        }
        int list_length(){
            int l = 0;
            for(Node* p=L; p; p=p->next){l++;}

            return l;
        }
        int* list_download(){
            const int l = list_length();
            int* A = new int[l];
            Node* p = L;
            for(int i=0; i<l; i++){
                A[i] = p->value;
                p = p->next;
            }
            return A;
        }
};

class WAS{
    private:
        List *list_employee, *list_stamp_enter, *list_stamp_exit;
    public:
        WAS(){
            list_employee = new List();
            list_stamp_enter = new List();
            list_stamp_exit = new List();
        }
        ~WAS(){delete list_employee, list_stamp_enter, list_stamp_exit;}
        void WAS_list_add_employee(const int ID){
            list_employee->list_add(ID);
        }
        void WAS_list_add_stamp_enter(const int ID){
            list_stamp_enter->list_add(ID);
        }
        void WAS_list_add_stamp_exit(const int ID){
            list_stamp_exit->list_add(ID);
        }
        void WAS_get_warninglist(){
            int *l1=list_stamp_enter->list_download(), *l2=list_stamp_exit->list_download();
            
        }
};

int main(){
    return 0;
}