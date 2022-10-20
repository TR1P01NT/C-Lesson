#include <stdio.h>

int evenodd(int x);

int main(void) {
    int count = 0, input, yn;

    scanf("%d", &input);

    while (input != -1) {
        yn = evenodd(input);
        if (yn == 1) {
            ++count;
        }
        scanf("%d", &input);
    }

    printf("%d\n", count);
}

int evenodd(int x) {
    if (x % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}