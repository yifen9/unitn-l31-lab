using namespace std;
#include <iostream>

const int BOARD_W = 8;
const int BOARD_H = 12;

void line();

void print_board(const int[BOARD_H][BOARD_W]);

void put_result(int[BOARD_H][BOARD_W],int);

int main(){
    srand(time(NULL));

    int c, C[4]={0}, board[BOARD_H][BOARD_W]={0};
    bool judge;

    int i=0;
    while(i<4){
        c = rand()%6+1;
        judge = true;
        for(int j=0; j<4; j++){if(C[j]==c){judge=false;}}
        if(judge){C[i]=c;i++;}
    }

    int turn=0;
    char G[5];
    while(true){
        do{
            judge = false;
            print_board(board);
            cout << " Guess(A-F)(Q to retype): " << endl << endl;
            for(int i=0; i<4; i++){
                cout << "   - " << i+1 << ": ";
                cin >> G[i];
                if(G[i]=='Q'){
                    judge=true;
                    break;
                }
            }
            cout << endl;
            G[4] = '\0';
        }
        while(judge);

        for(int i=0; i<4; i++){
            board[turn][i] = int(G[i]-'A'+1);

            if(board[turn][i] == C[i]){
                put_result(board,('X'-'A')+1);
            }
            else{
                for(int j=0; j<4; j++){
                    if(board[turn][i] == C[j]){put_result(board,('O'-'A')+1);}
                }
            }
        }

        judge=true;
        for(int i=4; i<8; i++){
            if(board[turn][i]!=('X'-'A'+1)){
                judge=false;
                break;
            }
        }
        if(judge){
            print_board(board);
            line();cout << " Player wins!" << endl;line();
            return 0;
        }

        turn++;

        if(turn>11){
            print_board(board);
            line();cout << " Player loses!" << endl;line();
            return 0;
        }
    }
    
    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void print_board(const int board[BOARD_H][BOARD_W]){
    line();
    cout << " Board: " << endl << endl;

    cout << "   - X: color & position" << endl;
    cout << "   - O: color & wrong position" << endl << endl;

    cout << "       G U E S S          R E S U L T" << endl;
    for(int i=0; i<BOARD_H; i++){
        cout << "   ";
        for(int j=0; j<(BOARD_W/2); j++){cout << "+---";}
        cout << "+   ";
        for(int j=0; j<(BOARD_W/2); j++){cout << "+---";}
        cout << "+" << endl << "  ";
        for(int j=0; j<(BOARD_W/2); j++){
            cout << " | ";
            if(board[i][j]){cout << char('A' + board[i][j]-1);}
            else{cout << " ";}
        }
        cout << " |  ";
        for(int j=(BOARD_W/2); j<BOARD_W; j++){
            cout << " | ";
            if(board[i][j]){cout << char('A' + board[i][j]-1);}
            else{cout << " ";}
        }
        cout << " | " << i+1 << endl;
    }
    cout << "   ";
    for(int j=0; j<(BOARD_W/2); j++){cout << "+---";}
    cout << "+   ";
    for(int j=0; j<(BOARD_W/2); j++){cout << "+---";}
    cout << "+" << endl << "   ";
    for(int i=0; i<(BOARD_W/2); i++){cout << "  " << i+1 << " ";}
    cout << "    ";
    for(int i=0; i<(BOARD_W/2); i++){cout << "  " << i+1 << " ";}
    cout << endl;

    cout << endl;
}

void put_result(int board[BOARD_H][BOARD_W], int value){
    int i=0;
    while(board[i][0] && i<BOARD_H){i++;}
    i--;
    
    int r;
    do{r = rand()%4+4;}
    while(board[i][r]);
    board[i][r] = value;
}