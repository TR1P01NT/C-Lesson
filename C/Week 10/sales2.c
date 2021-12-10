#include <stdio.h>

int main(void) {
    int gross, person[9] = {0}, commision, i;

    scanf("%d", &gross);

    while(gross != -1) {
        commision = (200 + (gross * 0.09)) / 100;
        if (commision >= 10) {
            person[8]++;
        }
        else {
            ++person[commision - 2];
        }
        scanf("%d", &gross);
    }

    for (i = 0; i < 9; i++) {
        printf("%d\n", person[i]);
    }
}