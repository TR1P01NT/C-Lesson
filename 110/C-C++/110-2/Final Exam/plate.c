#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int first, last;
    int number;
    char line[9];
    int testcase;

    scanf("%d", &testcase);

    while (testcase--) {
        scanf("%s", line);

        first = ((line[0] - 'A') * 26 * 26) + ((line[1] - 'A') * 26) + (line[2] - 'A');

        last = ((line[4] - '0') * 1000) + ((line[5] - '0') * 100) + ((line[6] - '0') * 10) + (line[7] - '0');

        number = abs(first - last);

        if (number <= 100) {
            printf("nice\n");
        }
        else {
            printf("not nice\n");
        }
    }
}