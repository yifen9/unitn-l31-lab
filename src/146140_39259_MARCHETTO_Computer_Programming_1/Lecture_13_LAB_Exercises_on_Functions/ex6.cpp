using namespace std;
#include <iostream>
#include <algorithm>

int main(){
    srand(time(NULL));
    int r11=rand()%6+1,r12=rand()%6+1,r21=rand()%6+1,r22=rand()%6+1;
    cout << (((max(r11,r12)>max(r21,r22))?1:0)?"Highest: Attacker wins!":"Highest: Defender wins!") << endl;
    cout << (((min(r11,r12)>min(r21,r22))?1:0)?"Lowest:  Attacker wins!":"Lowest:  Defender wins!") << endl;

    return 0;
}