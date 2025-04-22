using namespace std;
#include <iostream>

void sort(int&,int&,int&);

int main(){
    srand(time(NULL));
    int r11=rand()%6+1,r12=rand()%6+1,r13=rand()%6+1,r21=rand()%6+1,r22=rand()%6+1,r23=rand()%6+1;

    sort(r11,r12,r13);
    sort(r21,r22,r23);

    cout << (((r11>r21)?1:0)?"Lowest:  Attacker wins!":"Lowest:  Defender wins!") << endl;
    cout << (((r12>r22)?1:0)?"Middle:  Attacker wins!":"Middle:  Defender wins!") << endl;
    cout << (((r13>r23)?1:0)?"Highest: Attacker wins!":"Highest: Defender wins!") << endl;

    return 0;
}

void sort(int& n1,int& n2, int& n3){
    if(n1>n2){
        if(n2>n3){swap(n1,n3);}
        else{
            if(n1>n3){
                swap(n1,n2);
                swap(n2,n3);
            }
            else{swap(n1,n2);}
        }
    }
    else{
        if(n2>n3){
            if(n1>n3){
                swap(n1,n3);
                swap(n2,n3);}
            else{swap(n2,n3);}
        }
        else{}
    }
}
