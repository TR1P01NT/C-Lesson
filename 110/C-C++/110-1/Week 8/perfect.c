#include <stdio.h>

int isPerfect(int x);

int main(void) {
    int i;

    for (i = 2; i < 1000; i++) {
        isPerfect(i);
    }
}

int isPerfect(int x) {
    int sum = 0, i;

    for (i = 1; i < x; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }
    
    if (sum == x) {
        printf("%d\n", x);
    }

    return 0;
}