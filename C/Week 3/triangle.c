#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0) {
        if ((a + b) > c || (a + c) > b || (b + c) > c) {
            if ((a + b) > abs(a - b) || (a + c) > abs(c - a) || (b + c) > abs(b - c)) {
                printf("True\n");
            }
        }
        else {
            printf("False\n");
        }

        scanf("%d%d%d", &a, &b, &c);
    }
}