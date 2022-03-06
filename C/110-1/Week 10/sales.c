#include <stdio.h>

int main(void) {
    int gross, person[9] = {0}, commission, i;

    scanf("%d", &gross);

    while (gross != -1) {
        commission = 200 + (gross * 0.09);

        switch (commission) {
            case 200 ... 299:
                person[0]++;
                break;
            case 300 ... 399:
                person[1]++;
                break;
            case 400 ... 499:
                person[2]++;
                break;
            case 500 ... 599:
                person[3]++;
                break;
            case 600 ... 699:
                person[4]++;
                break;
            case 700 ... 799:
                person[5]++;
                break;
            case 800 ... 899:
                person[6]++;
                break;
            case 900 ... 999:
                person[7]++;
                break;
            default:
                person[8]++;
                break;
        }

        scanf("%d", &gross);
    }

    for (i = 0; i < 9; i++) {
        printf("%d\n", person[i]);
    }
}