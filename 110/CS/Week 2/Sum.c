#include <stdio.h>

int getSum(int a, int b);

int main(void) {
    int int1, int2, sum;

    printf("Input A: ");
    scanf("%d", &int1);
    printf("Input B: ");
    scanf("%d", &int2);

    if (int1 == 0) {
        printf("%d\n", int2);
    }

    else if (int2 == 0) {
        printf("%d\n", int1);
    }

    else {
        sum = getSum(int1, int2);

        printf("%d\n", sum);
    }
}

int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
}