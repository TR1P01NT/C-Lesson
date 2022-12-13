#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int fib[40] = {0, 1};

    int N = 0;

    for (int i = 2; i < 40; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    scanf("%d", &N);

    while (N--) {
        int num = 0;
        bool flag = false;

        scanf("%d", &num);
        printf("%d = ", num);

        for (int i = 39; i >= 2; i--) {
            if (num >= fib[i]) {
                num -= fib[i];
                printf("1");
                flag = true;
            }
            else if (flag) {
                printf("0");
            }
        }

        printf(" (fib)\n");
    }
}