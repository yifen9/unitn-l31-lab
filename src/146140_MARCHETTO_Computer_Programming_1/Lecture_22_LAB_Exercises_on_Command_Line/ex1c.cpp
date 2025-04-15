using namespace std;
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    if(string(argv[1])=="--max"){
        int m=stoi(argv[2]);
        for(int i=3; i<argc; i++){m=(m>stoi(argv[i]))?m:stoi(argv[i]);}
        cout << "Max: " << m << endl;
    }
    else if(string(argv[1])=="--sum"){
        int res=0;
        for(int i=1; i<argc; i++){res+=stoi(argv[i]);}
        cout << "Sum: " << res << endl;
    }
    else if(string(argv[1])=="--Product"){
        int res=1;
        for(int i=1; i<argc; i++){res+=stoi(argv[i]);}
        cout << "Product: " << res << endl;
    }
    else if(string(argv[1])=="--Average"){
        int res=0;
        for(int i=1; i<argc; i++){res+=stoi(argv[i]);}
        cout << "Average: " << res/argc << endl;
    }

    return 0;
}