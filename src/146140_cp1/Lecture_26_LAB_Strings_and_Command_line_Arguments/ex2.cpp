using namespace std;
#include <iostream>
#include <cstring>

int factorio(int);

void pmt(char*,char*,int,int);

int main(){
    char S[100], P[100];
    cout << "Please input a string (max length 100): " << endl;
    cin.getline(S,100);

    int len = strlen(S);
    int fac = factorio(len);

    cout << "n=" << len << " -> nr.Permutations: " << len << "!=" << fac << endl;

    pmt(&P[0],&S[0],0,len);

    return 0;
}

int factorio(int N){
    if (N == 0) {return 1;}
    else {return (factorio(N-1) * N);}
}

void pmt(char *S1, char *S2, int len1, int len2){
    if(len2 == 1){cout << " " << S1 << S2 << endl;}
    else{
        char P1[len1];
        strncpy(P1,S1,len1);

        char P2[len2-1];
        for(int i=0; i<len2; i++){
            P1[len1] = S2[i];
            P1[len1+1] = '\0';

            for(int j=0; j<i; j++){P2[j] = S2[j];}
            for(int j=i; j<len2; j++){P2[i+j] = S2[i+j+1];}

            pmt(&P1[0],&P2[0],len1+1,len2-1);
        }
    }
}