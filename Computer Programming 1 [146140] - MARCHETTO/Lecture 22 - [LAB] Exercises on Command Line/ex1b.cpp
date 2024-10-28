using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
    int m=stoi(argv[2]);
    for(int i=3; i<argc; i++){m=(m>stoi(argv[i]))?m:stoi(argv[i]);}
    cout << "Max: " << m << endl;

    return 0;
}