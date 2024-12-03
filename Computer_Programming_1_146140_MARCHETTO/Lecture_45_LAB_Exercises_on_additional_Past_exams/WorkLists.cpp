using namespace std;
#include <iostream>

class WAS{
    private:
        struct Node{
            int value;
            Node* next;
        }*list_employee, *list_stamp_enter, *list_stamp_exit;

        void p_list_delete(Node* list){
            Node* p;
            while(list){
                p = list;
                list = list->next;
                delete p;
            }
        }
        void p_list_add(Node* list, const int num){
            if(list){
                Node* p = list;
                while(p->next){p = p->next;}
                p->next = new Node();
                p->next->value = num;
                p->next->next = NULL;
            }
            else{
                list = new Node();
                list->value = num;
                list->next = NULL;
            }
        }
    public:
        WAS(){
            list_employee = NULL;
            list_stamp_enter = NULL;
            list_stamp_exit = NULL;
        }
        ~WAS(){
            p_list_delete(list_employee);
            p_list_delete(list_stamp_enter);
            p_list_delete(list_stamp_exit);
        }
        void WAS_list_add_employee(const int ID){
            p_list_add(list_employee,ID);
        }
        void WAS_list_add_stamp_enter(const int ID){
            p_list_add(list_stamp_enter,ID);
        }
        void WAS_list_add_stamp_exit(const int ID){
            p_list_add(list_stamp_exit,ID);
        }
        void WAS_list_get_warning();
};

int main(){
    return 0;
}