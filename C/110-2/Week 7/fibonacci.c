#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

long long sequence[10001];

void fib(int n, long long n1, long long n2);

int main(void) {
    int test = 0;
    long long int n, i, j;

    scanf("%d", &test);

    sequence[0] = 1;
    sequence[1] = 1;

    for (int i = 2; i <= 50; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }

    while(test--) {
        scanf("%lld %lld %lld", &n, &i, &j);

        if(n >= 48) {
            n = 48 - (n % 2);
        }
        fib(n, i, j);
        puts("");
    }
}

void fib(int n, long long n1, long long n2) {
    if (n1 > n2) {
        return;
    }
    if (n == 0) {
        putchar('0');
    }
    else if (n == 1) {
        putchar('1');
    }
    else {
        if(n1 < sequence[n - 2]) {
            fib(n - 2, n1, MIN(n2, sequence[n - 2] - 1));
            fib(n - 1, 0, n2 - sequence[n - 2]);
        } else {
            fib(n - 1, n1 - sequence[n - 2], n2 - sequence[n - 2]);
        }
    }
}