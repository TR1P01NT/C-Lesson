#include <stdio.h>
#include <math.h>

int calculate(int n) {
    int total = 0, digit;
    while (1) {
        while (n != 0) {
            digit = n % 10;
            total += pow(digit, 2);
            n /= 10;
        }

        if ((n == 0) && (total >= 10)) {
            n = total;
            total = 0;
        }
        else if ((n == 0) && total == 1) {
            return 1;
        }
        else if ((n == 0) && (total >= 2) && (total < 10)) {
            return 0;
        }
    }
}

int main(void) {
    int testcase = 0;
    int num;
    int count = 1;

    scanf("%d", &testcase);

    while (testcase--) {
        scanf("%d", &num);
        int check = calculate(num);

        if (check == 1) {
            printf("Case #%d: %d is a Happy number.\n", count++, num);
        }
        else {
            printf("Case #%d: %d is an Unhappy number.\n", count++, num);
        }
    }
}