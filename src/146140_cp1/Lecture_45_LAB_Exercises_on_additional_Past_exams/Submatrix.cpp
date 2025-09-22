using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class List{
    private:
        struct Node{
            int value;
            Node* next;
        }* L;
    public:
        List();
        List(int*, const int);
        ~List();
        void list_add(const int);
        int list_get_length();
        int* list_get();
        int list_get_index(const int);
        int list_get_count(const int);
        void list_print();
};

class Matrix{
    private:
        struct Node{
            List* value;
            Node* next;
        }* M;

        int p_random_int(const int);
        int* p_random_array(const int, const int);
    public:
        Matrix();
        Matrix(int**, const int, const int);
        ~Matrix();
        int matrix_get_width();
        int matrix_get_height();
        int* matrix_get_row(const int);
        int* matrix_get_col(const int);
        int matrix_get_ele(const int, const int);
        void matrix_add_col(int*);
        void matrix_add_row(int*);
        void matrix_fill(const int, const int, const int);
        void matrix_print();
};

int str_to_int(const string);

int** matrix_read_from_file(string, const int, const int);

int* input_read_from_file(string);

Matrix* submatrix(Matrix*,int*);

int main(){
    srand(time(NULL));

    const int H=4, W=4, MAX=9;

    Matrix* M = new Matrix(matrix_read_from_file("Submatrix-eg-1.txt",H,W),H,W);
    //M->matrix_fill(H,W,MAX);

    M->matrix_print();

    cout << endl << "input: ";

    int* I = input_read_from_file("Submatrix-eg-2.txt");

    for(int i=0; i<3; i++){cout << I[i] << ',';}
    cout << I[3] << " => " << endl << endl;

    Matrix* subM = submatrix(M,I);
    
    subM->matrix_print();

    delete M,subM;

    return 0;
}

List::List(){L = NULL;}

List::List(int* A, const int l){
    L = NULL;
    for(int i=0; i<l; i++){list_add(A[i]);}
}

List::~List(){
    for(Node*p; L; delete p){
        p = L;
        L = L->next;
    }
}

void List::list_add(const int value){
    if(L){
        Node* p = L;
        while(p->next){p = p->next;}
        p->next = new Node();
        p->next->value = value;
        p->next->next = NULL;
    }
    else{
        L = new Node();
        L->value = value;
        L->next = NULL;
    }
}

int List::list_get_length(){
    int l = 0;
    for(Node* p=L; p; p=p->next){l++;}

    return l;
}

int* List::list_get(){
    if(L){
        const int l = list_get_length();
        int* A = new int[l];
        Node* p = L;
        for(int i=0; i<l; i++){
            A[i] = p->value;
            p = p->next;
        }
        return A;
    }
    return NULL;            
}

int List::list_get_index(const int index){
    Node* p = L;
    for(int i=0; p; i++){
        if(i == index){return p->value;}
        else{p = p->next;}
    }
    return 0;
}

int List::list_get_count(const int value){
    if(L){
        int c = 0;
        for(Node*p=L; p; p=p->next){c += (p->value == value);}

        return c;
    }
    else{return 0;}
}

void List::list_print(){
    if(L){
        for(Node*p=L; p; p=p->next){cout << p->value << ' ';}
    }
}

int Matrix::p_random_int(const int MAX){return (rand() % (1 + MAX));}

int* Matrix::p_random_array(const int l, const int MAX){
    int* A = new int[l];
    for(int i=0; i<l; i++){A[i] = p_random_int(MAX);}

    return A;
}

Matrix::Matrix(){M = NULL;}

Matrix::Matrix(int** M, const int h, const int w){
    this->M = NULL;
    if(h>0 && w>0){
        for(int i=0; i<w; i++){matrix_add_col(&M[0][i]);}
        for(int i=1; i<h; i++){matrix_add_row(M[i]);}
    }
}

Matrix::~Matrix(){
    Node* p;
    while(M){
        p = M;
        M = M->next;
        delete p->value;
        delete p;
    }
}

int Matrix::matrix_get_width(){
    if(M){
        if(M->value){return M->value->list_get_length();}
    }
    return 0;
}

int Matrix::matrix_get_height(){
    int l = 0;
    for(Node* p=M; p; p=p->next){l++;}

    return l;
}

int* Matrix::matrix_get_row(const int index){
    Node* p = M;
    for(int i=0; p; i++){
        if(i == index){return p->value->list_get();}
        else{p = p->next;}
    }
    return NULL;
}

int* Matrix::matrix_get_col(const int index){
    if(M){
        const int l = matrix_get_height();
        int* A = new int[l];
        Node* p = M;
        for(int i=0; i<l; i++){
            A[i] = p->value->list_get_index(index);
            p = p->next;
        }
        return A;
    }
    else{return NULL;}
}

int Matrix::matrix_get_ele(const int y, const int x){
    if(M){return matrix_get_row(y)[x];}
    else{return 0;}
}

void Matrix::matrix_add_col(int* A){
    if(M){
        int i = 0;
        for(Node*p=M; p; p=p->next){
            p->value->list_add(A[i]);
        }
    }
    else{
        M = new Node();
        M->value = new List(A,1+matrix_get_width());
        M->next = NULL;
    }
}

void Matrix::matrix_add_row(int* A){
    if(M){
        Node* p = M;
        while(p->next){p = p->next;}
        p->next = new Node();
        p->next->value = new List(A,matrix_get_width());
        p->next->next = NULL;
    }
    else{
        M = new Node();
        M->value = new List(A,matrix_get_width());
        M->next = NULL;
    }
}

void Matrix::matrix_fill(const int h, const int w, const int MAX){
    if(h>0 && w>0){
        for(int i=0; i<w; i++){matrix_add_col(p_random_array(1,MAX));}
        for(int i=1; i<h; i++){matrix_add_row(p_random_array(w,MAX));}
    }
}

void Matrix::matrix_print(){
    for(Node*p=M; p; p=p->next){
        p->value->list_print();
        cout << endl;
    }
}

int str_to_int(const string s){
    int len = 0;
    while(s[len] != '\0'){len++;}
    char *res = new char[len];
    for(int i=0; i<len; i++){res[i] = s[i];}

    return stoi(res);
}

int** matrix_read_from_file(string fName, const int h, const int w){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    int** res = new int*[h];
    for(int i=0; i<h; i++){
        res[i] = new int[w];
        for(int j=0; j<w; j++){
            fIn >> wIn;
            res[i][j] = str_to_int(wIn);
        }
    }
    return res;
}

int* input_read_from_file(string fName){
    fstream fIn;
    fIn.open(fName, ios::in);

    string wIn;
    int* res = new int[4];
    for(int i=0; i<4; i++){
        fIn >> wIn;
        res[i] = str_to_int(wIn);
    }
    return res;
}

Matrix* submatrix(Matrix* M, int* I){
    if(I[2]>0 && I[3]>0){
        int mh=M->matrix_get_height(), mw=M->matrix_get_width(),
            h, w,
            py=0, px=0,
            **res;
        res = new int*[I[2]];
        h = I[2];
        for(int i=0; i<I[2]; i++){
            res[i] = new int[I[3]];
            py = I[0] + i;
            if(py>=0 && py<mh){
                w = I[3];
                for(int j=0; j<I[3]; j++){
                    px = I[1] + j;
                    if(px>=0 && px<mw){res[i-(I[2]-h)][j-(I[3]-w)] = M->matrix_get_ele(py,px);}
                    else{w--;}
                }
            }
            else{h--;}
        }
        return (new Matrix(res,h,w));
    }
    else{return NULL;}
}