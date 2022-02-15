#include <stdio.h>

int compare(int *a, int *b);

int main(void) {
    int num1, num2;

    while((scanf("%d %d", &num1, &num2)) != EOF) {
        compare(&num1, &num2);
        printf("%d %d\n", num1, num2);
    }
}

int compare(int *a, int *b) {
    if (*a > *b) {
        *a *= *a;
        *b *= 2;
    }
    else if (*a < *b) {
        *a *= 2;
        *b *= *b;
    }

    return 0;
}