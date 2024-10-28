using namespace std;
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    if(string(argv[1])=="max"){
        int m=stoi(argv[2]);
        for(int i=3; i<argc; i++){m=(m>stoi(argv[i]))?m:stoi(argv[i]);}
        cout << "Max: " << m << endl;
    }

    return 0;
}