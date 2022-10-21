#include <stdio.h>
#include <stdbool.h>

bool isSafe(int column, int row);
bool safeToPlace(int col, int row);
bool solveBoard(int row, int n);
bool solveBoardQueen(int row, int n);
void printResult();

int chessboard[10][10];
int board_column = 0;
int board_row = 0;
int present_queen = 0;
int placed_queen = 0;
int placements[10][2];

int main(void) {
    scanf("%d %d %d", &board_column, &board_row, &present_queen);

    for (int i = 0; i < board_row; i++) {
        for (int j = 0; j < board_column; j++) {
            chessboard[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            placements[i][j] = 0;
        }
    }

    if (present_queen != 0) {
        int x = 0;
        int y = 0;

        for (int i = 0; i < present_queen; i++) {
            scanf("%d %d", &x, &y);
            chessboard[y][x] = 1;
        }
    }

    int answer = 0;
    if (present_queen == 0) {
        answer = solveBoard(0, 0);
    } else {
        answer = solveBoardQueen(0, 0);
    }

    if (answer) {
        printResult();
    }
}

bool isSafe(int column, int row) {
    int i = 0;
    int j = 0;

    // Check up
    for (i = row - 1; i >= 0; i--) {
        if (chessboard[i][column] == 1) {
            return false;
        }
    }

    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    for (i = row, j = column; i >= 0 && j < board_column; i--, j++) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    return true;  
}

bool safeToPlace(int col, int row) {
    //self
    if (chessboard[row][col] == 1) {
        return false;
    }
    // right
    for (int i = col; i < board_column; i++) {
        if (chessboard[row][i] == 1) {
            return false;
        }
    }

    // down
    for (int i = row; i < board_row; i++) {
        if (chessboard[i][col] == 1) {
            return false;
        }
    }

    // left
    for (int i = col; i >= 0; i--) {
        if (chessboard[row][i] == 1) {
            return false;
        }
    }

    // up
    for (int i = row; i >= 0; i--) {
        if (chessboard[i][col] == 1) {
            return false;
        }
    }

    // left up
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    // right down
    for (int i = row, j = col; i < board_row && j < board_column; i++, j++) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    // left down
    for (int i = row, j = col; j >= 0 && i < board_row; i++, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    // right up
    for (int i = row, j = col; i >= 0 && j < board_column; i--, j++) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveBoard(int row, int n) {
    if (board_column < board_row) {
        if (row == board_column) {
            return true;
        }
    }
    else {
        if (row == board_row) {
            return true;
        }
    }

    for (int i = 0; i < board_column; i++) {
        if (isSafe(i, row)) {
            chessboard[row][i] = 1;
            placements[placed_queen][0] = row;
            placements[placed_queen][1] = i;
            placed_queen++;
            if (solveBoard(row + 1, n)) {
                return true;
            }
            chessboard[row][i] = 0;
            placed_queen--;
            placements[placed_queen][0] = 0;
            placements[placed_queen][1] = 0;
        }
    }

    return false;
}

bool solveBoardQueen(int row, int n) {
    if (board_column < board_row) {
        if (placed_queen == (board_column - present_queen)) {
            return true;
        }
    }
    else {
        if (placed_queen == (board_row - present_queen)) {
            return true;
        }
    }

    if (board_column < board_row) {
        if (row == (board_column - present_queen)) {
            return true;
        }
    }
    else {
        if (row == (board_row - present_queen)) {
            return true;
        }
    }

    int placed = 0;

    for (int i = 0; i < board_column; i++) {
        bool safe = safeToPlace(i, row);
        if (safe) {
            chessboard[row][i] = 1;
            placements[placed_queen][0] = row;
            placements[placed_queen][1] = i;
            placed_queen++;
            placed++;
            if (solveBoardQueen(row + 1, n)) {
                return true;
            }
            chessboard[row][i] = 0;
            placed_queen--;
            placements[placed_queen][0] = 0;
            placements[placed_queen][1] = 0;
            placed--;
        }
        else if ((i == board_column - 1) && (!safe) && (placed == 0)) {
            if (placed_queen != ((board_column < board_row) ? board_column : board_row) - present_queen) {
                if (solveBoardQueen(row + 1, n)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void printResult() {
    printf("%d\n", placed_queen);

    for (int i = 0; i < placed_queen; i++) {
        printf("%d %d\n", placements[i][1], placements[i][0]);
    }
    
    // print chessboard
    for (int i = 0; i < board_row; i++) {
        for (int j = 0; j < board_column; j++) {
            printf("%d ", chessboard[i][j]);
        }
        printf("\n");
    }
}