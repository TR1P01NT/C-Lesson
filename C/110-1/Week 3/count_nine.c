#include <stdio.h>

int countnine (int);

int main(void) {
    int num;

    scanf("%d", &num);

    while (num != -1) {
        printf("%d\n", countnine(num));
        
        scanf("%d", &num);
    }
}

int countnine (int num) {
    int count = 0;
    float remainder;

    while (num > 0) {
        remainder = num % 10;
        num /= 10;

        if (remainder == 9 ) {
            ++count;
        }
    }

    return count;
}