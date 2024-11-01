using namespace std;
#include <iostream>

void computeNum(int&,int[]);

int main(){
    int dice[10] = {0};
    srand(time(NULL));
    for(int i=0; i<10; i++){dice[i] = rand() % 6 + 1;}

    int guess;
    cout << "Please guess how many 1 are there (0-10):";
    cin >> guess;

    int num = 0;
    computeNum(num,dice);

    if(guess==num){cout << "Congrats!" << endl;}
    else{cout << "No, the correct answer is: " << num << endl;}

    return 0;
}

void computeNum(int& num, int dice[]){
    for(int i=0; i<10 ; i++){
        if(dice[i]==1){num++;}
    }
}
