using namespace std;
#include <iostream>
#include <string>

class Borrower{
    private:
        int ID;
        string name;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
    public:
        Borrower(const int ID, const string name){
            this->ID = ID;
            this->name = name;
        }
        int get_ID(){
            return this->ID;
        }
        string get_name(){
            return this->name;
        }
        void print(const int a){
            if(!a){cout << "Borrower: " << endl << endl;}
            p_space_in(a-1); cout << "- ID:   " << this->ID << endl;
            p_space_in(a-1); cout << "- name: " << this->name << endl;
        }
};

class Borrowing{
    private:
        int ID;

        struct{
            int year, month, day;
            void in(const int a){
                year = a/1'00'00;
                month = (a%1'00'00)/1'00;
                day = a%1'00;
            }
            int out(){return (1'00'00*year + 1'00*month + day);}
        }date;

        Borrower* borrower;
        Borrowing* next;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
    public:
        Borrowing(const int ID, const int date, Borrower* borrower){
            this->ID = ID;
            this->date.in(date);

            this->borrower = borrower;
            this->next = NULL;
        }
        void set_next(Borrowing* next){this->next = next;}
        int get_ID(){
            return this->ID;
        }
        Borrower* get_borrower(){
            return this->borrower;
        }
        Borrowing* get_next(){
            return this->next;
        }
        void print(const int a){
            if(!a){cout << "Borrowing: " << endl << endl;}
            p_space_in(a-1); cout << "- ID:   " << this->ID << endl;
            p_space_in(a-1); cout << "- name: " << this->borrower->get_name() << endl;
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
        int ID, count;
        string author, title;

        Borrowing* borrowing;

        void p_space_in(const int a){for(int i=0; i<a; i++){cout << "  ";}}
    public:
        Book(const int ID, const string author, const string title){
            this->ID = ID;
            this->author = author;
            this->title = title;
            
            this->borrowing = NULL;
        }
        void add_borrowing(const int date, Borrower* borrower){
            Borrowing* A = new Borrowing(count,date,borrower);
            cout << 1 << endl;
            if(borrowing == NULL){cout << 2 << endl;borrowing = A;}
            else{
                cout << 3 << endl;
                Borrowing* p = borrowing;
                while(p->get_next() != NULL){p = p->get_next();}
                p->set_next(A);
            }
            count++;
        }
        int get_ID(){
            return this->ID;
        }
        Borrowing* get_borrowing(){
            return this->borrowing;
        }
        void print(const int a){
            if(!a){cout << "Book: " << endl << endl;}
            p_space_in(a-1); cout << "- ID:     " << this->ID << endl;
            p_space_in(a-1); cout << "- author: " << this->author << endl;
            p_space_in(a-1); cout << "- title:  " << this->title << endl;
        }
        void print_list(const int a){
            print(a);
            if(borrowing){
                p_space_in(a-1); cout << "- Borrowing List: " << endl;
                for(Borrowing*p=borrowing; p!=NULL; p=p->get_next()){p->print(a+1);}
                if(!a){cout << endl << "Total: " << count << endl;}
            }
        }
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
                p->value.print(1);
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
            cout << borrower << endl;
            cout << book << endl;
            if(borrower && book){
                book->add_borrowing(date,borrower);
                return true;
            }
            else{return false;}
        }
        void Lib_print_borrowing(){
            cout << "Book List: " << endl << endl;
            int i=0;
            for(node<Book>*p=list_book; p!=NULL; p=p->next){
                cout << "Index: " << i << endl;
                p->value.print_list(1);
                i++;
            }
            cout << endl << "Total: " << i << endl;
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

    A->Lib_delete_borrower(0);

    A->Lib_add_borrowing(0,0,20051101);
    A->Lib_add_borrowing(1,0,20051102);
    A->Lib_add_borrowing(2,0,20051103);

    line();A->Lib_print_borrowing();

    return 0;
}