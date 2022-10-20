#include <stdio.h>

int main(void) {
    int h1, h2, m1, m2;
    int total;

    while ((scanf("%d %d %d %d", &h1, &m1, &h2, &m2)) && ((h1 + m1 + h2 + m2) != 0)) {
        total = ((h2 * 60) + m2) - ((h1 * 60) + m1);

        if (total < 0) {
            total += (24 * 60);
        }

        printf("%d\n", total);
    }
}