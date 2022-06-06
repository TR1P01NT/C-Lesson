#include <stdio.h>
#include <math.h>

int main(void) {
    long long int total = 0;
    int n = 0;

    scanf("%d", &n);

    while((n != 0)) {
        for (int i = 1; i <= n; i++) {
            total += pow(i, i);
        }
        printf("%lld\n", total % 10);

        total = 0;

        scanf("%d", &n);
    }
}