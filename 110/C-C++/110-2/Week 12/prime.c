#include <stdio.h>

//cryptography (prime and emirp)

int isPrime(int x, int y);
int renum(int x);

int main(void) {
    int num;
    int flag = 0;
    int numreverse;

    while ((scanf("%d", &num)) != EOF) {
        if (!isPrime(num, 2)) {
            printf("%d is not prime.\n", num);
            continue;
        }
        else {
            numreverse = renum(num);
            if (num == numreverse) {
                printf("%d is prime.\n", num);
                continue;
            }
            
            if (!isPrime(numreverse, 2)) {
                printf("%d is prime.\n", num);
            }
            else {
                printf("%d is emirp.\n", num);
            }
        }
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

int renum(int x) {
    int reverse = 0;
    int temp;

    while (x != 0) {
        temp = x % 10;
        reverse = (reverse * 10) + temp;
        x /= 10;
    }

    return reverse;
}