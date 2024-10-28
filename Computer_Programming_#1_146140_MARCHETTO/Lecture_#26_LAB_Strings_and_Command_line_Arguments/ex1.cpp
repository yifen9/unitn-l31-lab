using namespace std;
#include <iostream>
#include <cstring>

int main(){
    char S[100];
    cout << "Please input a string (max length 100): " << endl;
    cin.getline(S,100);

    int len=strlen(S), count=1; cout << len << endl;
    for(int i=0; i<len; i++){if(S[i]==' '){count++;}}

    cout << "Words: " << count << endl;

    return 0;
}