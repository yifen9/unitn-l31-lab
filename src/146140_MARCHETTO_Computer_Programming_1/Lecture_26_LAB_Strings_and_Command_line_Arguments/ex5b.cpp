using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=5) {cout << "Incorrect input words number!" << endl; return 0;}

    string fName = argv[1];

    fstream fIn;
    fIn.open(fName, ios::in);

    if(!(fIn.is_open())) {cout << "Missing file name!" << endl; return 0;}

    char f[100]; int len;
    while(fIn >> f) {
        len = strlen(f);
        for(int i=0; i<len; i++){
            if(f[i]==*argv[2]){cout << '?';}
            else if(f[i]==*argv[3]){cout << '!';}
            else if(f[i]==*argv[4]){cout << '#';}
            else{cout << f[i];}
        }
        cout << ' ';
    }
    cout << endl;

    fIn.close();

    return 0;
}