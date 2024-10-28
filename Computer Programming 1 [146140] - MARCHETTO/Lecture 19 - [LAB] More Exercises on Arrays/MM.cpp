using namespace std;
#include <iostream>

int main(){
    srand(time(NULL));

    int C[4] = {7}, O[4] = {5}, c;
    bool judge;

    int i=0;
    while(i<4){
        c = rand()%7;
        judge = true;
        for(int j=0; j<4; j++){if(C[j]==c){judge=false;}}
        if (judge){C[i]=c;i++;}
    }

    i=0;
    while(i<4){
        c = rand()%5;
        judge = true;
        for(int j=0; j<4; j++){if(O[j]==c){judge=false;}}
        if (judge){O[i]=c;i++;}
    }

    
    
    return 0;
}