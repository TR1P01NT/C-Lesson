#include <stdio.h>

int isEven(int x);

int main(void) {
    int a;

    scanf("%d", &a);

    while (a != -1) {
        printf("%d\n", isEven(a));

        scanf("%d", &a);
    }
}

int isEven(int x) {
    int i;

    if (x % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}