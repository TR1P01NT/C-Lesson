#include <stdio.h>

int main(void) {
    long long num;

    scanf("%lld", &num);

    while (num != 0) {
        if (num % 11 == 0) {
            printf("%lld is a multiple of 11.\n", num);
        }
        else {
            printf("%lld is not a multiple of 11.\n", num);
        }

        scanf("%lld", &num);
    }
}