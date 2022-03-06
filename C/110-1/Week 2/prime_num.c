#include <stdio.h>

int main() {
    int prime, i;

    scanf("%d", &prime);

    for (i = 2; i <= prime/2; i++) {
        if (prime % i == 0) {
            printf("False\n");
            return 0;
        }
    }

    printf("True\n");
    return 0;
}