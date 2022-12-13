#include <stdio.h>

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main(void) {
    int N = 0;
    int G = 0;

    while(scanf("%d", &N)) {
        if (N == 0) {
            break;
        }
        else {
            G = 0;

            for (int i = 1; i < N; i++) {
                for (int j = i + 1; j <= N; j++) {
                    G += gcd(i, j);
                }
            }

            printf("%d\n", G);
        }
    }
}
