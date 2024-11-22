using namespace std;
#include <iostream>
#include <string>

class Borrower{
    private:
        string name;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
    public:
        Borrower(const string name){this->name = name;}
        void print(const int a){
            if(!a){cout << "Borrower: " << endl;}
            p_space_in(a-1); cout << "- name: " << this->name << endl;
        }
};

class Borrowing{
    private:
        struct{
            int ID;
            Borrower* value;
        }borrower;
        struct{
            int year, month, day;
            void in(const int a){
                year = a/1'00'00;
                month = (a%1'00'00)/1'00;
                day = a%1'00;
            }
            int out(){return (1'00'00*year + 1'00*month + day);}
        }date;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
    public:
        Borrowing(const int ID, Borrower* borrower, const int date){
            this->borrower.ID = ID;
            this->borrower.value = borrower;
            this->date.in(date);
        }
        int get_ID(){return borrower.ID;}
        int get_date(){return date.out();}
        void print(const int a){
            if(!a){cout << "Borrowing: " << endl;}
            p_space_in(a-1); cout << "- Borrower: " << endl;
            p_space_in(a); cout << "- ID: " << this->borrower.ID << endl;
            this->borrower.value->print(a+1);
            p_space_in(a-1); cout << "- date: ";
            if(a){cout << this->date.out() << endl;}
            else{
                cout << endl;
                p_space_in(a); cout << "- year:  " << this->date.year << endl;
                p_space_in(a); cout << "- month: " << this->date.month << endl;
                p_space_in(a); cout << "- day:   " << this->date.day << endl;
            }
        }
};

class Book{
    private:
        int count;
        string author, title;

        struct node{
            int ID;
            Borrowing* value;
            node* next;
        };
        node* list;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
        void p_print(const int a){
            if(!a){cout << "Book: " << endl;}
            p_space_in(a-1); cout << "- author: " << this->author << endl;
            p_space_in(a-1); cout << "- title:  " << this->title << endl;
        }
    public:
        Book(const string author, const string title){
            this->author = author;
            this->title = title;
            
            list = NULL;
        }
        void add_borrowing(const int ID, Borrower* borrower, const int date){
            Borrowing* borrowing = new Borrowing(ID,borrower,date);
            if(list == NULL){
                list = new node();
                list->ID = count;
                list->value = borrowing;
            }
            else{
                node* p = list;
                while(p->next != NULL){p = p->next;}

                p->next = new node();
                p->next->ID = count;
                p->next->value = borrowing;
            }
            count++;
        }
        void print(const int a){
            p_print(a);
            if(list){
                p_space_in(a-1); cout << "- Borrowing List: " << endl;
                for(node*p=list; p!=NULL; p=p->next){
                    p_space_in(a); cout << "- ID: " << p->ID << endl;
                    p->value->print(a+2);
                }
                if(!a){cout << "- Total: " << count << endl;}
            }
        }
        bool print_list(const int a, const int ID, int &i){
            bool judge = false;
            for(node*p=list; p!=NULL; p=p->next){
                if(p->value->get_ID() == ID){
                    p_space_in(a-1); cout << "- ID: " << i << endl;
                    p_print(a+1);
                    p_space_in(a); cout << "- date:  " << p->value->get_date() << endl;

                    judge = true;
                    i++;
                }
            }
            return judge;
        }
};

class Library{
    private:
        int count_borrower=0, count_book=0;

        template<typename T> struct node{
            int ID;
            T value;
            node* next;

            node<T>(const T a): value(a){}
        };
        node<Borrower>* list_borrower = NULL;
        node<Book>* list_book = NULL;

        template<typename T> void p_add_node(node<T>* &list, const int ID, const T A){
            if(list == NULL){
                list = new node<T>(A);
                list->ID = ID;
            }
            else{
                node<T>* p = list;
                while(p->next != NULL){p = p->next;}

                p->next = new node<T>(A);
                p->next->ID = ID;
            }
        }
        template<typename T> bool p_delete_node(node<T>* &list, const int ID){
            if(list == NULL){return false;}
            else{
                node<T>* t = new node<T>(list->value);
                t->next = list;

                node<T>* p = t;
                while(p->next->ID != ID){
                    if(p->next->next == NULL){return false;}
                    else{p = p->next;}
                }

                p->next = p->next->next;
                list = t->next;

                delete t, p->next;

                return true;
            }
        }
        template<typename T> void p_print_nodes(node<T>* list){
            cout << "List: " << endl;
            int i=0;
            for(node<T>*p=list; p!=NULL; p=p->next){
                cout << "- ID: " << p->ID << endl;
                p->value.print(2);
                i++;
            }
            cout << "- Total: " << i << endl;
        }
        template<typename T> node<T>* p_search_node(node<T>* list, const int ID){
            node<T>* p = list;
            while(p->ID != ID){
                if(p->next == NULL){return NULL;}
                else{p = p->next;}
            }
            return p;
        }
    public:
        Library(){}
        void Lib_add_borrower(const string name){
            Borrower A(name);
            p_add_node<Borrower>(list_borrower,count_borrower,A);
            count_borrower++;
        }
        void Lib_add_book(const string author, const string title){
            Book A(author,title);
            p_add_node<Book>(list_book,count_book,A);
            count_book++;
        }
        bool Lib_add_borrowing(const int ID_borrower, const int ID_book, const int date){
            node<Borrower>* borrower = p_search_node<Borrower>(list_borrower,ID_borrower);
            node<Book>* book = p_search_node<Book>(list_book,ID_book);
            if(borrower && book){
                book->value.add_borrowing(ID_borrower,&(borrower->value),date);
                return true;
            }
            else{return false;}
        }
        bool Lib_delete_book(const int ID){return p_delete_node<Book>(list_book,ID);}
        void Lib_print_borrowers(){
            cout << "Borrower ";
            p_print_nodes<Borrower>(list_borrower);
        }
        void Lib_print_books(){
            cout << "Book ";
            p_print_nodes<Book>(list_book);
        }
        void Lib_print_borrowings(const int ID){
            cout << "Borrowing List: " << endl;
            int i=0;
            for(node<Book>*p=list_book; p!=NULL; p=p->next){
                if(p->value.print_list(1,ID,i)){cout << "  - book ID: " << p->ID << endl;}
            }
            cout << "- Total: " << i << endl;
        }
};

int main(){
    Library* A = new Library();

    A->Lib_add_borrower("Li");
    A->Lib_add_borrower("Anto");
    A->Lib_add_borrower("Yifeng");

    A->Lib_add_book("Lee","Battle of Calculus");
    A->Lib_add_book("Anto Lee","Conquer the GLA");
    A->Lib_add_book("Li Yifeng","Computer Programming Enjoyer");

    A->Lib_add_borrowing(2,2,19890604);
    A->Lib_add_borrowing(2,0,29520000);
    A->Lib_add_borrowing(0,2,12345678);
    A->Lib_add_borrowing(0,0,89642952);
    A->Lib_add_borrowing(0,1,20051109);
    A->Lib_add_borrowing(1,1,01010101);

    A->Lib_print_borrowers(); cout << endl;
    A->Lib_print_books(); cout << endl;

    A->Lib_print_borrowings(0); cout << endl;
    A->Lib_print_borrowings(1); cout << endl;
    A->Lib_print_borrowings(2); cout << endl;

    return 0;
}