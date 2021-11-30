#include <stdio.h>

int isPrime (int x, int y);

int main(void) {
    int input, prime;

    scanf("%d", &input);

    while(input != -1) {
        prime = isPrime(input, 2);
        if (prime == 1) {
            printf("True\n");
        }
        else {
            printf("False\n");
        }
        scanf("%d", &input);
    }
}

int isPrime (int x, int y) {
    if ((x % y == 0) && x == y) {
        return 1;
    }
    else if (x % y == 0) {
        return 0;
    }
    else {
        return isPrime(x, y + 1);
    }
}