#include <stdio.h>

void separate (int x, int y);

int main(void) {
    int i, j;

    scanf("%d %d", &i, &j);

    while (i != -1 && j != -1) {
        separate(i, j);
        scanf("%d %d", &i, &j);
    }
}

void separate (int x, int y) {
    int a, num = 3;

    for (a = 1; a <= y; a++) {
        printf("%d ", num);
        num += x;
    }

    printf("\n");
}