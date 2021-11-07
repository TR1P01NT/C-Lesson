#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0) {
        if ((a + b) > c && abs(a - b) || (a + c) > b && abs(c - a) || (b + c) > c && abs(b - c)) {
                printf("True\n");
            }
        }
        else {
            printf("False\n");
        }
    }