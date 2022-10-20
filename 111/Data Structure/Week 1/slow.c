#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int base, exp, total;
    int count = 0;

    scanf("%d %d", &base, &exp);

    total = base;

    for (int i = 1; i < exp; i++) {
        total *= base;
        ++count;
    }

    printf("Multiplication count: %d\n", count);
    printf("Answer: %d\n", total);
}