#include <stdio.h>

int gcd(int x, int y);

int main(void) {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    while ((num1 != -1) && (num2 != -1)) {
        printf("%d\n", gcd(num1, num2));
        scanf("%d %d", &num1, &num2);
    }
}

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    else if (x == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}