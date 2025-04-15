using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
    int res=1;
    for(int i=1; i<argc; i++){res*=stoi(argv[i]);}
    cout << "Product: " << res << endl;

    return 0;
}