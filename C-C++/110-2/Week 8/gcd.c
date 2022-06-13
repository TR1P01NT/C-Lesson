#include <stdio.h>

//gcd

int gcd(int x, int y) {
    if (y != 0) {
        return gcd(y, x % y);
    }
    else {
        return x;
    }
}

int main(void) {
    int n, i, j;
    int G = 0;

    scanf("%d", &n);

    while (1) {
        if (n == 0) {
            break;
        }

        for (i = 1; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                G += gcd(i, j);
            }
        }

        printf("%d\n", G);
        G = 0;

        scanf("%d", &n);
    }
}