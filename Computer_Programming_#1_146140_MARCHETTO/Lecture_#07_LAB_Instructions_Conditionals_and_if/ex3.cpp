using namespace std;
#include <iostream>

int main(){
    char c;
    cout << "Please input e(English) or j(Japanese): ";
    cin >> c;

    switch(c){
        case 'e': cout << "Have a nice day" << endl; break;
        case 'j': cout << "Yoi 1-nichi o" << endl; break;
    }

    return 0;
}