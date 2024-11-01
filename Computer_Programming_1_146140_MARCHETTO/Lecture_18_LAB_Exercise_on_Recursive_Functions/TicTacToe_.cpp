using namespace std;
#include <iostream>

const int BOARD_SIZE = 3;

void print_board(int[][BOARD_SIZE]);

bool move(int,int,int[][BOARD_SIZE]);

void has_won(int[][BOARD_SIZE],int);

void free_cells(int[BOARD_SIZE*BOARD_SIZE][2],int&,int[][BOARD_SIZE]);

void computer_move(int,int,int[BOARD_SIZE*BOARD_SIZE][2]);

void user_move(int);

int main(){
    return 0;
}

void print_board(const int board[][BOARD_SIZE]){}

bool move(int move[], int color, int board[][BOARD_SIZE]){return true;}

void had_won(int board[][BOARD_SIZE], int color){}

void free_cells(int cells[BOARD_SIZE*BOARD_SIZE][2], int &found, const int board[][BOARD_SIZE]){}

void computer_move(int cell[2], const int free_cells_size, const int free_cells[BOARD_SIZE*BOARD_SIZE][2]){}

void user_move(int cell[2]){}