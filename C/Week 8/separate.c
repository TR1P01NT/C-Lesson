#include <stdio.h>

int main(void) {
    int i, input, count, num[5];

    scanf("%d", &input);

    while (input != -1) {
        count = 0;
        for (i = 0;;i++) {
            num[i] = input % 10;
            ++count;
            input /= 10;

            if (input == 0) {
                break;
            }
        }

        for (; count > 0; count--) {
            printf("%d  ", num[count - 1]);
        }

        printf("\n");

        scanf("%d", &input);
    }

}