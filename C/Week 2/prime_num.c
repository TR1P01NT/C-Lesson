#include <stdio.h>

int main(void) {
    int prime, i, flag = 0;

    scanf("%d", &prime);

    for (i = 2; i <= prime/2; i++) {
        if (prime % i == 0) {
            flag = 1;
        }
    }

    if (flag == 1) {
        printf("False\n");
    }

    else {
        printf("True\n");
    }
}