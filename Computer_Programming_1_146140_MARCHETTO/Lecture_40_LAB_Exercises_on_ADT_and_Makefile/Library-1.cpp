using namespace std;
#include <iostream>
#include <string>

class Borrower{
    private:
        int ID;
        string name;
    public:
        Borrower(const int ID, const string name){
            this->ID = ID;
            this->name = name;
        }
        int get_ID(){return this->ID;}
        void print(){
            cout << "  - ID: " << this->ID << endl;
            cout << "  - name: " << this->name << endl;
        }
};

class Borrowing{
    private:
        int ID;
        struct{
            int year;
            int month;
            int day;
        }date;

        Borrower* borrower;
        Borrowing* borrowing;
    public:
        Borrowing(const int ID, const int date, Borrower* borrower){
            this->ID = ID;

            this->date.year = date/1'00'00;
            this->date.month = (date%1'00'00)/1'00;
            this->date.day = date%1'00;

            this->borrower = borrower;
            this->borrowing = NULL;
        }
        int get_ID(){return this->ID;}
        void set_borrowing(Borrowing* borrowing){this->borrowing = borrowing;}
};

class Book{
    private:
        int ID, count;
        string author;
        string title;

        Borrowing* borrowing;
    public:
        Book(const int ID, const string author, const string title){
            this->count = 0;
            this->ID = ID;
            this->author = author;
            this->title = title;
            this->borrowing = NULL;
        }
        int get_ID(){return this->ID;}
        void print(){
            cout << "- ID: " << this->ID << endl;
            cout << "- author: " << this->author << endl;
            cout << "- title: " << this->title << endl;
        }
        void set_borrowing(Borrowing* borrowing){this->borrowing = borrowing;}
};

class Library{
    private:
        int count_borrower=0, count_book=0;

        template<typename T> struct node{
            T value;
            node* next;

            node<T>(T a): value(a){}
        };
        node<Borrower>* list_borrower = NULL;
        node<Book>* list_book = NULL;

        template<typename T> void p_add_node(node<T>* &list, const T A){
            if(list == NULL){list = new node<T>(A);}
            else{
                node<T>* p = list;
                while(p->next != NULL){p = p->next;}

                p->next = new node<T>(A);
            }
        }
        template<typename T> bool p_delete_node(node<T>* &list, const int ID){
            if(list == NULL){return false;}
            else{
                node<T>* t = new node<T>(list->value);
                t->next = list;

                node<T>* p = t;
                while(p->next->value.get_ID() != ID){
                    p = p->next;
                    if(p->next->next == NULL){return false;}
                }

                p->next = p->next->next;
                list = t->next;

                delete t, p->next;

                return true;
            }
        }
        template<typename T> void p_print_nodes(node<T>* list){
            cout << "List: " << endl << endl;
            int i=0;
            for(node<T>*p=list; p!=NULL; p=p->next){
                cout << "Index: " << i << endl;
                p->value.print();
                i++;
            }
            cout << endl << "Total: " << i << endl;
        }
        template<typename T> node<T>* p_search_node(node<T>* list, const int ID){
            node<T>* p = list;
            while(p->value.get_ID() != ID){
                p = p->next;
                if(p->next == NULL){return NULL;}
            }
            return p;
        }
    public:
        Library(){}
        void Lib_add_borrower(const string name){
            Borrower A(count_borrower,name);
            p_add_node<Borrower>(list_borrower,A);
            count_borrower++;
        }
        void Lib_add_book(const string author, const string title){
            Book A(count_book,author,title);
            p_add_node<Book>(list_book,A);
            count_book++;
        }
        bool Lib_delete_borrower(const int ID){
            return p_delete_node<Borrower>(list_borrower,ID);
        }
        bool Lib_delete_book(const int ID){
            return p_delete_node<Book>(list_book,ID);
        }
        void Lib_print_borrowers(){
            cout << "Borrower ";
            p_print_nodes<Borrower>(list_borrower);
        }
        void Lib_print_books(){
            cout << "Book ";
            p_print_nodes<Book>(list_book);
        }
        bool Lib_add_borrowing(const int ID_borrower, const int ID_book, const int date){
            Borrower* borrower = &(p_search_node<Borrower>(list_borrower,ID_borrower)->value);
            Book* book = &(p_search_node<Book>(list_book,ID_book)->value);

            if(borrower==NULL || book==NULL){return false;}
            else{
                return true;
            }
        }
};

void line(){cout << "--------------------------------" << endl;}

int main(){
    Library* A = new Library();

    A->Lib_add_borrower("Lee");
    A->Lib_add_borrower("Vlad");
    A->Lib_add_borrower("Yifeng");

    A->Lib_add_book("Anto","Conquer the Earth");
    A->Lib_add_book("Li Yifeng","Conquer the GLA");

    line();A->Lib_print_borrowers();
    line();A->Lib_print_books();

    A->Lib_delete_borrower(0);
    A->Lib_delete_book(0);

    line();A->Lib_print_borrowers();
    line();A->Lib_print_books();

    return 0;
}