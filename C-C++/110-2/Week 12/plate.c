#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//license plate

int main(void) {
    int cases;
    char c;
    int letter, number, value;
    char line[10];

    scanf("%d", &cases);

    for (int x = 0; x < cases; x++) {
        letter = 0;
        number = 0;
        value = 0;

        scanf("%s", line);

        letter = ((line[0] - 'A') * 26 * 26) + ((line[1] - 'A') * 26) + (line[2] - 'A');

        number = ((line[4] - '0') * 1000) + ((line[5] - '0') * 100) + ((line[6] - '0') * 10) + (line[7] - '0');

        value = abs(letter - number);

        if (value <= 100) {
            printf("nice\n");
        }
        else {
            printf("not nice\n");
        }
    }
}