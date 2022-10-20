#include <stdio.h>

int main(void) {
    int count = 33, i = 0;

    while (count <= 125) {
        printf("%c ", count);
        ++i;

        if (i == 10) {
            i = 0;
            printf(",");
            printf("\n");
        }

        ++count;
    }

    return 0;
}