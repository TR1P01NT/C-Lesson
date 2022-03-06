#include <stdio.h>

void star (int x, int y);

int main(void) {
    int side1, side2;

    scanf("%d %d", &side1, &side2);

    while (side1 != -1 && side2 != -1) {
        star(side1, side2);
        scanf("%d %d", &side1, &side2);
    }
}

void star(int x, int y) {
    int i, j;

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("*");
        }
        printf("\n");
    }
}
