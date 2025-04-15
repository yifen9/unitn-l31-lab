using namespace std;
#include <iostream>
#include <cstring>

class Person{
    private:
        char *name, *surname;
        int YoB;

        void p_set_array_of_chars(char*&,string);
    public:
        Person();
        ~Person();
        char* person_get_name();
        char* person_get_surname();
        int person_get_YoB();
        void person_set_name(string);
        void person_set_surname(string);
        void person_set_YoB(const int);
        void person_print();
};

int main(){
    Person* P = new Person();

    P->person_set_name("NRed");
    P->person_set_surname("SRed");
    P->person_set_YoB(2002);

    P->person_print();

    cout << endl;

    P->person_set_YoB(2003);

    P->person_print();

    return 0;
}

void Person::p_set_array_of_chars(char* &a1, string a2){
    int l = 0;
    while(a2[l] != '\0'){l++;}

    delete[] a1;
    a1 = new char[l];

    for(int i=0; i<l; i++){a1[i] = a2[i];}
}

Person::Person(){
    name = NULL;
    surname = NULL;
    YoB = 0;
}

Person::~Person(){delete[] name, surname;}

char* Person::person_get_name(){
    return name;
}

char* Person::person_get_surname(){
    return surname;
}

int Person::person_get_YoB(){
    return YoB;
}

void Person::person_set_name(string name){
    p_set_array_of_chars(this->name,name);
}

void Person::person_set_surname(string surname){
    p_set_array_of_chars(this->surname,surname);
}

void Person::person_set_YoB(const int YoB){this->YoB = YoB;}

void Person::person_print(){
    cout << "- name:          " << name << endl;
    cout << "- surname:       " << surname << endl;
    cout << "- year of birth: " << YoB << endl;
}