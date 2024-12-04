using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

int** f1(string fName){
    char c;
    fstream fIn;

    int l1 = 0;
    fIn.open(fName, ios::in);
    while(!fIn.eof()){
        c = fIn.get();
        if((c == '\n') || (fIn.eof())){l1++;}
    }

    int l2[l1];
    fIn.clear();
    fIn.seekg(0);
    for(int i=0,j=0; !fIn.eof();){
        c = fIn.get();
        if((c == '\n') || (fIn.eof())){
            l2[i] = 1 + j;
            i++;
            j = 0;
        }
        else if(c == ' '){j++;}
    }

    int** A = new int*[1+l1];
    A[0] = new int;
    A[0][0] = l1;
    for(int i=0; i<l1; i++){
        A[1+i] = new int[1+l2[i]];
        A[1+i][0] = l2[i];
    }
    fIn.clear();
    fIn.seekg(0);
    for(int i=0,j=0,k=0; !fIn.eof();){
        c = fIn.get();
        if((c == '\n') || (fIn.eof())){
            A[1+i][1+j] = k;
            i++;
            j = 0;
            k = 0;
        }
        else if(c == ' '){
            A[1+i][1+j] = k;
            j++;
            k = 0;
        }
        else{k++;}
    }

    return A;
}

int** f2(string fName){
    int** A = new int*[2];
    string wIn;
    fstream fIn;

    int l1 = 0;
    fIn.open(fName, ios::in);
    for(;!fIn.eof(); l1++){fIn >> wIn;}

    A[0] = new int[1+l1];
    A[0][0] = l1;
    fIn.clear();
    fIn.seekg(0);
    for(int i=0,l; !fIn.eof(); i++){
        fIn >> wIn;

        l = 0;
        while((wIn[l] != '\0') && (wIn[l] != '\n')){l++;}
        char *C = new char[l];
        for(int i=0; i<l; i++){C[i] = wIn[i];}

        if(l){A[0][1+i] = stoi(C);}
    }

    int min=A[0][1], max=A[0][1];
    for(int i=1; i<l1; i++){
        min = (A[0][1+i] < min)? A[0][1+i]: min;
        max = (A[0][1+i] > max)? A[0][1+i]: max;
    }

    int r=1+max-min, B[r] = {0};
    for(int i=0; i<l1; i++){B[A[0][1+i]-min]++;}

    int l2 = 0;
    for(int i=0; i<r; i++){l2 += bool(B[i]);}

    A[1] = new int[1+l2];
    A[1][0] = l2;
    for(int i=0,j=0; i<l1; i++){
        if(B[A[0][1+i]-min]){
            A[1][1+j] = A[0][1+i];
            B[A[0][1+i]-min] = 0;
            j++;
        }
    }

    return A;
}

int main(){
    int** A1 = f1("File1-eg.txt");
    int** A2 = f2("File2-eg.txt");

    cout << "Function one:" << endl << "- Y: " << A1[0][0] << endl;
    for(int i=0; i<A1[0][0]; i++){
        cout << "- X: " << A1[1+i][0] << " and numbers: ";
        for(int j=0; j<(A1[1+i][0] - 1); j++){
            cout << A1[1+i][1+j] << ',';
        }
        cout << A1[1+i][A1[1+i][0]] << endl;
    }

    cout << endl << "Function two:" << endl << "- Input array: ";
    for(int i=1; i<A2[0][0]; i++){cout << A2[0][i] << ',';}
    cout << A2[0][A2[0][0]] << endl << "- Unique elements of the said array: ";
    for(int i=1; i<A2[1][0]; i++){cout << A2[1][i] << ',';}
    cout << A2[1][A2[1][0]] << endl;

    return 0;
}