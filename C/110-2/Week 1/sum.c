#include <stdio.h>

int main(void) {
    int input = 0, temp = 0, sum = 0;

    while ((scanf("%d", &input) != 0)) {
        if (input == 0) {
            break;
        }

        while (input != 0) {
            temp += input % 10;
            input /= 10;

            if ((input == 0) && temp >= 10) {
                input = temp;
                temp = 0;
            }
        }

        printf("%d\n", temp);

        temp = 0;
    }
}