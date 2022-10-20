#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int base, exp, total;
    int count = 0;
    int binary_exp = 0;

    scanf("%d %d", &base, &exp);

    total = 1;

    while (exp > 0) {
        binary_exp = exp % 2;
        if (binary_exp == 0) {
            total *= total;
            ++count;
        }
        else if (binary_exp == 1) {
            total *= (total * base);
            ++count;
        }
        exp /= 2;
    }

    printf("Multiplication count: %d\n", count);
    printf("Answer: %d\n", total);
}