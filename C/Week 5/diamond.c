#include <stdio.h>

int main() {
    int i, j;
    double rows;

    scanf("%lf", &rows);

    while(rows != -1) {
        double num = (rows / 2) + 0.5;
        int x = rows / 2;
        for (i = 1; i <= num; i++) {
            for (j = 1; j <= num - i; j++) {
                printf(" ");
            }

            for (j = 1; j <= (2 * i) - 1; j++) {
                printf("*");
            }
            printf("\n");
        }

        for (i = 1; i <= x; i++) {
            for (j = 1; j <= i; j++) {
                printf(" ");
            }

            for (j = 1; j <= 2 * (num - i) - 1; j++) {
                printf("*");
            }
            printf("\n");
        }

        scanf("%lf", &rows);
    }
}