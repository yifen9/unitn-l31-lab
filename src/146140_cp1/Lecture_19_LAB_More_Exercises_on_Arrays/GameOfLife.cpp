using namespace std;
#include <iostream>

int main(){
    char input;

    int s1=20, s2=40, c, p1, p2, g=1;

    int m[s1][s2], n[s1][s2];

    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){m[i][j] = 0;}
    }

    m[10][20] = 1;
    m[9][20] = 1;
    m[11][20] = 1;
    m[10][19] = 1;
    m[11][21] = 1;

    while(true){
        for(int i=0; i<s2+2; i++){cout << "+";} cout << endl;
        for(int i=0; i<s1; i++){
            cout << "+";
            for(int j=0; j<s2; j++){cout << ((m[i][j])?'X':' ');}
            cout << "+" << endl;
        }
        for(int i=0; i<s2+2; i++){cout << "+";} cout << endl;

        for(int i=0; i<s1; i++){
            for(int j=0; j<s2; j++){n[i][j] = 0;}
        }
        
        for(int i=0; i<s1; i++){
            for(int j=0; j<s2; j++){
                c = 0;
                for(int k=-1; k<2; k++){
                    for(int l=-1; l<2; l++){
                        p1 = i+k; p2 = j+l;
                        if(m[p1][p2] && p1>-1 && p1<s1 && p2>-1 && p2<s2){c++;}
                    }
                }
                    
                if (m[i][j]){
                    if(c<5 && c>2){n[i][j] = 1;}
                }
                else if(c==3){n[i][j] = 1;}
            }
        }

        for(int i=0; i<s1; i++){
            for(int j=0; j<s2; j++){m[i][j] = n[i][j];}
        }

        cout << "Generation: " << g << endl;
        g++;

        cout << "Continue? (0 to exit): ";
        cin >> input;

        if(input == '0'){return 0;}
    }

    return 0;
}
