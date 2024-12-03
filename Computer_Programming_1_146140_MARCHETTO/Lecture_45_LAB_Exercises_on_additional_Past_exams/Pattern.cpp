using namespace std;
#include <iostream>

int* array_generate(const int MAXLEN, const int MAXNUM){
    int* res = new int[MAXLEN];
    for(int i=0; i<MAXLEN; i++){res[i] = rand() % (1 + MAXNUM);}

    return res;
}

void array_print(int* array, const int MAXLEN){
    cout << '[';
    for(int i=0; i<(MAXLEN-1); i++){cout << array[i] << ", ";}
    cout << array[MAXLEN-1] << ']';
}

bool array_sub_check(int* array, int* subarray, const int len_array, const int len_subarray){
    for(int i=0,j=0; i<len_array; i++){
        if(array[i] == subarray[j]){
            j++;
            if(!(len_subarray - j)){return true;}
        }
        else{j = 0;}
    }
    return false;
}

int main(){
    srand(time(NULL));

    const int MAXLEN_pettern = 3;
    const int MAXLEN_text = 6;
    const int MAXNUM = 0b1;

    int* pattern = array_generate(MAXLEN_pettern,MAXNUM);
    int* text = array_generate(MAXLEN_text,MAXNUM);

    array_print(pattern,MAXLEN_pettern);
    cout << " -> ";
    array_print(text,MAXLEN_text);
    cout << ' ' << (array_sub_check(text,pattern,MAXLEN_text,MAXLEN_pettern)? "YES": "NO") << endl;

    return 0;
}