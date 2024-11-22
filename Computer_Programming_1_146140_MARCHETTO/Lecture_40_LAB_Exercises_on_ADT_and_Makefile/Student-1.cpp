using namespace std;
#include <iostream>
#include <string>

struct Student{
    string name;
    string surname;
    int id;
    float w_average;
};

void print_student(const Student &S){
    cout << "- name:         " << S.name << endl;
    cout << "- surname:      " << S.surname << endl;
    cout << "- id:           " << S.name << endl;
    cout << "- weighted GPA: " << S.w_average << endl;
}

Student create_student(char name[], char surname[], int id, float w_average){
    Student S;

    S.name = name;
    S.surname = surname;
    S.id = id;
    S.w_average = w_average;

    return S;
}

char* str_to_char(const string s){
    int len=0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return res;
}

int main(){
    string name;
    string surname;
    int id;
    float w_average;

    cout << "Create a student: " << endl;
    cout << "- name:         "; cin >> name;
    cout << "- surname:      "; cin >> surname;
    cout << "- id:           "; cin >> id;
    cout << "- weighted GPA: "; cin >> w_average;
    Student S = create_student(str_to_char(name),str_to_char(surname),id,w_average);

    cout << "Print: " << endl;
    print_student(S);

    return 0;
}