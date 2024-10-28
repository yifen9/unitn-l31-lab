using namespace std;
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    if(string(argv[1])=="--max"){
        string u;
        cout << "Please input ints (input -1 to exit): " << endl;
        cin >> u;
        try{if(stoi(u)==-1){return 0;}}
        catch(invalid_argument){cout << "Invalid argument raised for "<< u << endl;}
        int m = stoi(u);
        while(true){
            cin >> u;
            try{if(stoi(u)==-1){break;}}
            catch(invalid_argument){cout << "Invalid argument raised for "<< u << endl;}
            m=(m>stoi(u))?m:stoi(u);
        }
        cout << "Max: " << m << endl;
    }

    return 0;
}