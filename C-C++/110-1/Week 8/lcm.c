#include <stdio.h>

int lcm(int a, int b);

int main(void) {
    int num1, num2, max;

    scanf("%d %d", &num1, &num2);

    while (num1 != -1 && num2 != -1) {
        printf("%d\n", lcm(num1, num2));

        scanf("%d %d", &num1, &num2);
    }

    return 0;
}

int lcm(int a, int b) {
    int max;
    
    max = (a > b) ? a : b;

    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }

        max++;
    }
}