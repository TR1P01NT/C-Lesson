#include <stdio.h>

int main(void) {
    int year;

    scanf("%d", &year);

    while (year != -1) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }

        scanf("%d", &year);
    }
}