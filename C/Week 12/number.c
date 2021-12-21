#include <stdio.h>

int exchange(int *a, int *b);

int main(void) {
    int num1, num2;

    while((scanf("%d %d", &num1, &num2)) != EOF) {
        exchange(&num1, &num2);
        printf("%d %d\n", num1, num2);
    }
}

int exchange(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}