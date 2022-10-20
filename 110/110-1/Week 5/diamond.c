#include <stdio.h>

int main(void) {
    int line = 0;

    scanf("%d", &line);

    int space = line - 1;

    for (int i = 1; i <= line; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }

        for (int k = 1; k <= (2 * i)- 1; k++) {
            printf("*");
        }

        printf("\n");
        space--;
    }

    space = 1;

    for (int i = 1; i <= line - 1; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }

        for (int k = 1; k <= (2 * (line - i)) - 1; k++) {
            printf("*");
        }

        printf("\n");
        space++;
    }
}