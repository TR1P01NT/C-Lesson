#include <stdio.h>

int main(void) {
    int count, input, max = 0;

    for (count = 1; count < 11; count++) {
        scanf("%d", &input);

        if (input >= max) {
            max = input;
        }
    }

    printf("Max: %d\n", max);
}