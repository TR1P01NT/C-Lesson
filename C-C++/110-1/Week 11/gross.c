#include <stdio.h>

int main(void) {
    int person, p[1][5] = {12, 16, 10, 14, 15}, item[1][5] = {0, 0, 0, 0, 0};

    scanf("%d", &person);

    int sales[person][5], x = 0, i, j, max, most, product = 0, people = 0;
    int gross[1][person];

    for (i = 0; i < person; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &sales[i][j]);
        }
    }

    for (i = 0; i < person; i++) {
        for (j = 0; j < 5; j++) {
            gross[0][i] += sales[i][j] * p[0][j];
            item[0][j] += sales[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        item[0][i] *= p[0][i];
    }

    for (i = 0; i < person; i++) {
        max = 0;
        if (gross[0][i] > max) {
            max = gross[0][i];
            people = i;
        }
    }

    for (i = 0; i < 5; i++) {
        most = 0;
        if (item[0][i] > most) {
            most = item[0][i];
            product = i;
        }
    }
 
    for (i = 0; i < person; i++) {
        printf("%d: %d\n", i + 1, gross[0][i]);
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", item[0][i]);
    }

    printf("\n%d\n", people + 1);

    switch (product - 1) {
        case 0:
            printf("A\n");
            break;
        case 1:
            printf("B\n");
            break;
        case 2:
            printf("C\n");
            break;
        case 3:
            printf("D\n");
            break;
        case 4:
            printf("E\n");
            break;
    }
}