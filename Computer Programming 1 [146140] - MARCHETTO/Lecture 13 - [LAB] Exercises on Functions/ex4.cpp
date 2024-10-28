using namespace std;
#include <iostream>
#include <cstdlib>

int main(){
    int dice[10] = {0},num = 0;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        dice[i] = rand() % 6 + 1;
        if(dice[i]==1){num++;}
    }

    int guess;
    cout << "Please guess how many 1 are there (0-10):";
    cin >> guess;

    if(guess==num){cout << "Congrats!" << endl;}
    else{cout << "No, the correct answer is: " << num << endl;}

    return 0;
}