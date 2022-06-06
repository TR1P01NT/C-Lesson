#include <stdio.h>

int main(void) {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    while ((num1 != -1) && (num2 != -1)) {
        while (num1 != num2) {
            if (num1 > num2) {
                num1 -= num2;
            }
            else {
                num2 -= num1;
            }
        }

        printf("%d\n", num1);

        scanf("%d %d", &num1, &num2);
    }
}