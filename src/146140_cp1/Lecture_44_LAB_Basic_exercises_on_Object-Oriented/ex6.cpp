using namespace std;
#include <iostream>

class String{
    private:
        int length;
        char* array;

        int p_length_compute(char*);
    public:
        String();
        ~String();
        int string_get_length();
        char* string_get_array();
        void string_set(char*);
        void string_length_compute();
        char string_array_position(const int);
        void string_print();
};

int main(){
    char C1[] = "stringValue";
    String* S = new String[2];

    S[0].string_set(C1);
    S[1].string_set(C1);

    cout << "S1: "; S[0].string_print(); cout << endl;
    cout << "S2: "; S[1].string_print(); cout << endl;

    cout << endl;

    srand(time(NULL));

    char C2[] = "newValueNewValue";
    S[rand() % 2].string_set(C2);

    cout << "S1: "; S[0].string_print(); cout << endl;
    cout << "S2: "; S[1].string_print(); cout << endl;

    return 0;
}

int String::p_length_compute(char* A){
    int l = 0;
    while(A[l] != '\0'){l++;}

    return l;
}

String::String(){
    length = 0;
    array = NULL;
}

String::~String(){delete[] array;}

int String::string_get_length(){
    return length;
}

char* String::string_get_array(){
    return array;
}

void String::string_set(char* A){
    int l = p_length_compute(A);

    if(array){delete[] array;}
    array = new char[l];

    for(int i=0; i<l; i++){array[i] = A[i];}
}

void String::string_length_compute(){length = p_length_compute(array);}

char String::string_array_position(const int i){return array[i];}

void String::string_print(){cout << array;}