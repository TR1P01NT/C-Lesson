#include <stdio.h>
#include <string.h>

int main(void) {
    int row, col;
    int current_x, current_y, current_face;
    int new_x, new_y, new_face;
    char directions[100] = {0};

    while(scanf("%d %d", &row, &col) != EOF) {
        scanf("%d %d %d", &current_x, &current_y, &current_face);
        int board[55][55] = {0};
        scanf("%s", directions);

        for (int i = 0; i < strlen(directions); i++) {
            if (directions[i] == 'F') {
                
            }
        }
    }
}