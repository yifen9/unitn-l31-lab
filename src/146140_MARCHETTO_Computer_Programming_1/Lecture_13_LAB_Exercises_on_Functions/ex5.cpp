using namespace std;
#include <iostream>

int main(){
    srand(time(NULL));
    int r = rand()%6+1;
    cout << ((r>rand()%6+12)?"Player 1 wins!":"Player 2 wins!") << endl;

    return 0;
}