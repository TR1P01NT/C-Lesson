#include <stdio.h>

int main(void) {
    int a, b;

    while(scanf("%d %d", &a, &b)) {
        int carry = 0;

        if (a == 0 && b == 0) {
            break;
        }

        while(a != 0 || b != 0) {
            int last_a = a % 10;
            int last_b = b % 10;

            if (last_a + last_b >= 10) {
                carry++;
            }

            a /= 10;
            b /= 10;
        }

        if (carry == 0) {
            printf("No carry operation.\n");
        }
        else if (carry == 1) {
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operation.\n", carry);
        }
    }
}