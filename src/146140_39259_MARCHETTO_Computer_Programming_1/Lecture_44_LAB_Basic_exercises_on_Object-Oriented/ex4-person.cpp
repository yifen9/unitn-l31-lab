using namespace std;
#include "ex4-person.hpp"

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