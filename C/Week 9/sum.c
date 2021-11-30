#include <stdio.h>

int sum (int x);

int main(void) {
    int input;

    scanf("%d", &input);

    while (input != -1) {
        printf("%d\n", sum(input));
        scanf("%d", &input);
    }
}

int sum(int x) {
    if (x == 0) {
        return 0;
    } 
    else {
        return (x % 10) + sum(x / 10);
    }
}