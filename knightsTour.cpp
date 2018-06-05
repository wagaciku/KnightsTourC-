#include <iostream>
using namespace std;

const int ROW_COUNT = 8;
const int COL_COUNT = 8;
const int POSSIBLE_MOVES = 8;

int ROW[POSSIBLE_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
int COLUMN[POSSIBLE_MOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};

int board[ROW_COUNT][COL_COUNT];

void print_board() {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COL_COUNT; j++) {
            if (board[i][j] < 10)
                cout << '0';
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cin.get(); // pause the screen 
}

find_tour(int move_no, int current_row, int current_col) {
    if (move_no == ROW_COUNT * COL_COUNT) //if we've made the last move
    {
        print_board();
        return true;
    }

    for (int move = 0; move < POSSIBLE_MOVES; move++) {
        int new_row = current_row + ROW[move];
        int new_col = current_col + COLUMN[move];

        if (new_row < 0 || new_row >= ROW_COUNT || new_col < 0 || new_col >= COL_COUNT)
            continue;

        if (board[new_row][new_col] != 0) //check of the box has a value already
            continue;

        board[new_row][new_col] = move_no + 1;
        find_tour(move_no + 1, new_row, new_col);
        board[new_row][new_col] = 0;
    }
}

void solve(int init_row, int init_col) {
    for (int row = 0; row < ROW_COUNT; row++)
        for (int col = 0; col < COL_COUNT; col++)
            board[row][col] = 0;

    board[init_row][init_col] = 1;
    find_tour(1, init_row, init_col);
}

int main(int argc, char* argv[]) {
    solve(7, 8);
}
