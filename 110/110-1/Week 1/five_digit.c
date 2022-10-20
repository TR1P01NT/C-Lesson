#include <stdio.h>

int main(void) {
    int num, num1, num2, num3, num4, num5;

    scanf("%d", &num);

    num5 = num % 10;
    num /= 10;
    num4 = num % 10;
    num /= 10;
    num3 = num % 10;
    num /= 10;
    num2 = num % 10;
    num /= 10;
    num1 = num % 10;

    printf("%d   %d   %d   %d   %d", num1, num2, num3, num4, num5);
}