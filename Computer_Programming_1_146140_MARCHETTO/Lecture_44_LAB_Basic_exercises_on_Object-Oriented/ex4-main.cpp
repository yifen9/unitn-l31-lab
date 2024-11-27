using namespace std;
#include "ex4-person.h"

Person create_person(string, string, const int);

Person* create_array_of_person(const int);

bool store_person_in_array(Person*&, Person, const int);

float average_cal(Person*&, const int);

void average(Person*&, const int);

void greaterThan(Person*&, const int);

int main(){
    int n;
    cout << "Please input the length n: ";
    cin >> n;

    Person* PA = create_array_of_person(n);

    store_person_in_array(PA,create_person("p1 name","p1 surname",2001),n);
    store_person_in_array(PA,create_person("p2 name","p2 surname",2002),n);
    store_person_in_array(PA,create_person("p3 name","p3 surname",2003),n);
    store_person_in_array(PA,create_person("p4 name","p4 surname",2004),n);
    store_person_in_array(PA,create_person("p5 name","p5 surname",2005),n);

    cout << "average: ";
    average(PA,n);
    cout << endl;

    cout << "greater Than: ";
    greaterThan(PA,n);
    cout << endl;

    return 0;
}

Person create_person(string name, string surname, const int YoB){
    Person P;

    P.person_set_name(name);
    P.person_set_surname(surname);
    P.person_set_YoB(YoB);

    return P;
}

Person* create_array_of_person(const int n){
    if(n > 0){
        return new Person[n];
    }
    else{
        return NULL;
    }
}

bool store_person_in_array(Person* &A, Person O, const int n){
    if(A){
        Person* p = A;
        for(int i=0; p->person_get_name(); p++){
            i++;
            if(i >= n){return false;}
        }

        p->person_set_name(O.person_get_name());
        p->person_set_surname(O.person_get_surname());
        p->person_set_YoB(O.person_get_YoB());

        return true;
    }
    else{return false;}
}

float average_cal(Person* &A, const int n){
    int l = 0;
    float a = 0;
    for(Person*p=A; (p->person_get_name() && l<n); p++){
        a += p->person_get_YoB();
        l++;
    }
    a /= l;

    return a;
}

void average(Person* &A, const int n){if(A){cout << average_cal(A,n);}}

void greaterThan(Person* &A, const int n){
    if(A){
        float a = average_cal(A,n);

        int c = 0;
        Person* p = A;
        for(int i=0; (p[i].person_get_name() && i<n); i++){c += (p[i].person_get_YoB() > a);}

        cout << c;
    }
}