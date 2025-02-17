using namespace std;
#include <iostream>

const int BOARD_SIZE = 9;

void line();

void print_board(const int[BOARD_SIZE][BOARD_SIZE]);

bool move(int[2],int,int[BOARD_SIZE][BOARD_SIZE]);

bool has_won(int[BOARD_SIZE][BOARD_SIZE],int);

void free_cells(int[BOARD_SIZE*BOARD_SIZE][2],int&,const int[BOARD_SIZE][BOARD_SIZE]);

void computer_move(int[2],const int,const int[BOARD_SIZE*BOARD_SIZE][2]);

void user_move(int[2]);

int main(){
    srand(time(NULL));

    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int fCells[BOARD_SIZE*BOARD_SIZE][2] = {0};
    int found;
    int M[2] = {0};

    while(true){
        /*
        print_board(board);
        free_cells(fCells,found,board);
        if(found){
            do{user_move(M);}
            while(!move(M,2,board));
        }
        else{
            line();cout << " No one wins!" << endl;line();
            break;
        }
        if(has_won(board,2)){cout << "Player wins!" << endl; break;}
        */

        print_board(board);
        free_cells(fCells,found,board);
        if(found){
            computer_move(M,found,fCells);
        }
        else{
            line();cout << " No one wins!" << endl;line();
            break;
        }
        move(M,1,board);
        if(has_won(board,1)){
            print_board(board);
            line();cout << " Computer 1 wins!" << endl;line();
            break;
        }

        print_board(board);
        if(found){
            computer_move(M,found,fCells);
        }
        else{
            line();cout << " No one wins!" << endl;line();
            break;
        }
        move(M,2,board);
        if(has_won(board,2)){
            print_board(board);
            line();cout << " Computer 2 wins!" << endl;line();
            break;
        }
    }

    return 0;
}

void line(){cout << "--------------------------------" << endl;}

void print_board(const int board[BOARD_SIZE][BOARD_SIZE]){
    line();
    cout << " Board: " << endl << endl;

    for(int i=0; i<BOARD_SIZE; i++){
        cout << "   ";
        for(int j=0; j<BOARD_SIZE; j++){cout << "+---";}
        cout << "+" << endl << "  ";
        for(int j=0; j<BOARD_SIZE; j++){
            cout << " | ";
            switch(board[i][j]){
                case 0: cout << ' '; break;
                case 1: cout << 'O'; break;
                case 2: cout << 'X'; break;
            }
        }
        cout << " | " << i << endl;
    }
    cout << "   ";
    for(int j=0; j<BOARD_SIZE; j++){cout << "+---";}
    cout << "+" << endl;
    cout << "   ";
    for(int i=0; i<BOARD_SIZE; i++){cout << "  " << i << " ";}
    cout << endl;

    cout << endl;
}

bool move(int move[2], int color, int board[BOARD_SIZE][BOARD_SIZE]){
    if(board[move[0]][move[1]]){
        return false;
    }
    else{
        board[move[0]][move[1]] = color;
        return true;
    }
}

bool has_won(int board[BOARD_SIZE][BOARD_SIZE], int color){
    bool e1,e2;
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j]==color){
                e1 = i>0 && i<(BOARD_SIZE-1);
                e2 = j>0 && j<(BOARD_SIZE-1);
                if(e1){
                    if(board[i-1][j]==color && board[i+1][j]==color){return true;}
                }
                if(e2){
                    if(board[i][j-1]==color && board[i][j+1]==color){return true;}
                }
                if(e1 && e2){
                    if(board[i-1][j-1]==color && board[i+1][j+1]==color){return true;}
                    if(board[i-1][j+1]==color && board[i+1][j-1]==color){return true;}
                }
            }
        }
    }
    return false;
}

void free_cells(int cells[BOARD_SIZE*BOARD_SIZE][2], int &found, const int board[BOARD_SIZE][BOARD_SIZE]){
    found = 0;
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            cells[i*3+j][0] = 0;
            cells[i*3+j][1] = 0;
            if(!board[i][j]){
                cells[found][0] = i;
                cells[found][1] = j;
                found++;
            }
        }
    }
}

void computer_move(int cell[2], const int free_cells_size, const int free_cells[BOARD_SIZE*BOARD_SIZE][2]){
    int r = rand()%free_cells_size;

    cell[0] = free_cells[r][0];
    cell[1] = free_cells[r][1];

    line();
    cout << " Computer move: " << endl;
    cout << endl;
    cout << "   - row: " << cell[0] << endl;
    cout << "   - col: " << cell[1] << endl;
    cout << endl;
}

void user_move(int cell[2]){
    line();
    cout << " User move: " << endl;
    cout << endl;
    cout << "   - row: "; cin >> cell[0];
    cout << "   - col: "; cin >> cell[1];
    cout << endl;
}