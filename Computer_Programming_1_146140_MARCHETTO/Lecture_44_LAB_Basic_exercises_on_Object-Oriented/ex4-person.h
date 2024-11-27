#ifndef EX4_PERSON_H
#define EX4_PERSON_H
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

#endif