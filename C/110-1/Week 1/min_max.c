#include <stdio.h>

int main(void) {
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Min: %d\n", num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3));
    printf("Max: %d\n", num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3));
}