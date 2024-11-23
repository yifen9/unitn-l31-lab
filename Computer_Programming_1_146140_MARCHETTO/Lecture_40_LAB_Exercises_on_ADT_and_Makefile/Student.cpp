using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

struct Student{
    char *name=NULL, *surname=NULL;
    int id = 0;
    float w_average = 0;
};

void print_student(const Student&);

Student create_student(char[],char[],int,float);

bool upload_students(Student*&, const string, const int);

int search_id(Student*,int,int);

int search_name_and_surname(Student*,char*,char*,int);

int student_top_average(Student*,int);

char* str_to_char(const string);

int main(){
    const int N = 100;
    Student* database = new Student[N];

    /*
    int* i = new int();
    while(database[*i].name!=NULL && *i<N){i++;}

    string* name = new string();
    string* surname = new string();
    int* id = new int();
    float* w_average = new float();
    if(*i < N){
        cout << "Create a student: " << endl;
        cout << "- name:         "; cin >> *name;
        cout << "- surname:      "; cin >> *surname;
        cout << "- id:           "; cin >> *id;
        cout << "- weighted GPA: "; cin >> *w_average;
        database[*i] = create_student(str_to_char(*name),str_to_char(*surname),*id,*w_average);
    }
    else{cout << "the maximum size is reached" << endl;}

    delete i, name, surname, id, w_average;
    */

    /*
    int* i = new int();
    *i = search_id(database,42459,N);
    if(*i == -1){cout << "the user does not exist" << endl;}
    else{print_student(database[*i]);}
    delete i;
    */

    /*
    int* i = new int();
    *i = search_name_and_surname(database,str_to_char("Marcus"),str_to_char("Wright"),N);
    if(*i == -1){cout << "the user does not exist" << endl;}
    else{print_student(database[*i]);}
    delete i;
    */

    //cout << student_top_average(database,N);

    //if(!upload_students(database,"Students.txt",N)){cout << "the maximum size is reached" << endl;}

    return 0;
}

void print_student(const Student &S){
    if(S.name != NULL){
        cout << "- name:         " << S.name << endl;
        cout << "- surname:      " << S.surname << endl;
        cout << "- id:           " << S.id << endl;
        cout << "- weighted GPA: " << S.w_average << endl;
    }
}

Student create_student(char name[], char surname[], int id, float w_average){
    Student S;

    S.name = name;
    S.surname = surname;
    S.id = id;
    S.w_average = w_average;

    return S;
}

bool upload_students(Student* &database, const string fName, const int DIM){
    fstream fIn;
    fIn.open(fName, ios::in);
    if(!(fIn.is_open())){cout << "Missing file name!" << endl; return true;}

    char *name, *surname;
    int id;
    float w_average;
    string input;

    int i = 0;
    while(database[i].name != NULL){i++;}

    for(int j=i; (j<DIM && !fIn.eof()); j++){
        fIn >> input; name = str_to_char(input);
        fIn >> input; surname = str_to_char(input);
        fIn >> input; id = stoi(str_to_char(input));
        fIn >> input; w_average = atof(str_to_char(input));

        database[j] = create_student(name,surname,id,w_average);
    }

    return fIn.eof();
}

int search_id(Student* database, int id, int DIM){
    for(int i=0; (i<DIM && database[i].name!=NULL); i++){
        if(database[i].id == id){return i;}
    }
    return -1;
}

int search_name_and_surname(Student* database, char* name, char* surname, int DIM){
    for(int i=0; (i<DIM && database[i].name!=NULL); i++){
        if(!(strcmp(database[i].name,name)
          || strcmp(database[i].surname,surname))){
            return i;
        }
    }
    return -1;
}

int student_top_average(Student* database, int DIM){
    int res = 0;
    float m = database[0].w_average;
    for(int i=1; (i<DIM && database[i].name!=NULL); i++){
        if(database[i].w_average > m){
            m = database[i].w_average;
            res = i;
        }
    }
    return res;
}

char* str_to_char(const string s){
    int len=0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return res;
}